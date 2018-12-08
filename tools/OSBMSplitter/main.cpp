#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <regex>

//==============================================================================
// OSBMSplitter.
//==============================================================================
// This utility will read in a 'Keywords?.clean.rst' file and for each keyword
// found, will create and write an individual file purely for that one
// keyword.
//
// This is to help make updating simpler, and a small file will be changed
// and not the entire list of keywords.
//
// Output files are created in a folder named for the upper cased first letter
// of the keyword(s) in question. There is A through Z plus underscore. These
// files will be named after the keywords link name rather than the keyword,
// to prevent spurious characters appearing in filename - percents, dollars etc.
//------------------------------------------------------------------------------
// Norman Dunbar.
// 5th December 2018.
//------------------------------------------------------------------------------
// This code is in the public domain - for all the good it will do you! :-)
//==============================================================================


//------------------------------------------------------------------------------
// Try to avoid polluting  the namespace with everything from STD::
//------------------------------------------------------------------------------
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;
using std::regex;
using std::smatch;


//------------------------------------------------------------------------------
// Forward declaration of support functions.
//------------------------------------------------------------------------------
int processFile(const string &inputFile);



//------------------------------------------------------------------------------
// Start here folks...
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    cout << endl
         << "Online SuperBASIC Manual Splitter" << endl
         << "=================================" << endl << endl;

    // Parameters ok?
    if (argc != 2) {
        cerr << "OSBMSplitter: incorrect parameters." << endl
             << "A single 'KeywordsX.clean.rst' filename is required." << endl
             << "and it must exist." << endl << endl;
        return -1;
    }

    // Grab the input file.
    string inputFile(argv[1]);
    cout << "Reading '" << inputFile << "' ..." <<  endl << endl;

    // Process the input file and return the result code.
    return processFile(inputFile);
}

//------------------------------------------------------------------------------
// Process the input file.
//------------------------------------------------------------------------------
int processFile(const string &inputFile) {

    ofstream *ofs;                              // Output file stream.
    string aLine;                               // One line of input.
    string outputFolder;                        // Output folder name.
    string outputFile;                          // Full output file path.
    regex labelRegex("^..  _(.*):$");           // Regex detecting label lines.
    smatch match;                               // Set if we get a regex match.
    int result = 0;                             // Assumes all went well.
    bool dontReadNextLine;                      // Do we need to read the next line?

    ifstream *ifs = new ifstream(inputFile);    // Input file stream.
    if (!ifs->good()) {
        cerr << "OSBMSplitter: Cannot open input file '"
             << inputFile << "'"
             << endl << endl;
        return -1;
    }

    // Extract the output folder from the input filename, which
    // could be local or a full path. Go in reverse then!
    // InputFile = c:\xxxxx\yyyy\zzzzzzzz\KeywordsX.clean.rst
    // We want the 11th character from the end.
    // And we want it in upper case.
    outputFolder = inputFile.substr(inputFile.length() - 11, 1);
    for (auto & c: outputFolder) c = toupper(c);

    // The main loop to read the input file.
    getline(*ifs, aLine);
    while (ifs->good()) {

        // Have we read a label line yet? Keep reading
        // the input file until we hit the first one.
        while (!regex_match(aLine, match, labelRegex)) {
            getline(*ifs, aLine);
        }

        // We have the first match on a label line.
        // Extract the label and open it as an output file.
        //
        // match[1] will convert to a string in an assignment, but not
        // in an assignment expression. Hmmm.
        // outputFile = "c:/Users/hisg494/temp/" + outputFolder + "/" + string(match[1]) + ".rst";
        outputFile = "./" + outputFolder + "/" + string(match[1]) + ".rst";

        ofs = new ofstream(outputFile);
        if (!ofs->good()) {
            cerr << "OSBMSplitter: Cannot open output file '"
                 << outputFile << "'"
                 << endl << endl;
            result = -2;
            break;
        }

        cout << endl << "Writing '" << outputFile << "' ..." << endl;

        // Write the label line to the output file.
        // Then read and write the input file until we hit:
        //      EOF; or
        //      Another label line.
        *ofs << aLine << endl;

        // Make sure we set this flag correctly! If we hit EOF we will
        // read the next line and exit. If we hit a label, we must not
        // read another line until we process the label.
        dontReadNextLine = false;

        while (1) {
            getline(*ifs, aLine);

            // EOF? Error?
            if (!ifs->good()) {
                break;
            }

            // Label line?
            if (regex_match(aLine, match, labelRegex)) {
                dontReadNextLine = true;
                break;
            }

            // Not the end of this keyword, so write it out.
            *ofs << aLine << endl;

        }   // end while (1)

        // Close the current output file.
        cout << "Closing '" << outputFile << "'" << endl;
        ofs->close();

        // If we exited EOF, we will exit the loop pretty soon.
        // However, if we found a label line, we do not need to read
        // the next input line, we already have it in the buffer.
        if (dontReadNextLine) {
            continue;
        }

        // Read next input line. Sets EOF, if necessary.
        getline(*ifs, aLine);
    } // end while (ifs->good()).

    // All done, close input file.
    ifs->close();
    return result;
}
