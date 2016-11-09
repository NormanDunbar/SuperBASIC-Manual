#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>

//
// extractLinks <list_of_files>
//
// This program will read the list of files and for each one found, 
// will extract all the links.
// 
// Links are found as follows, in the source files:
//
//      `Link Text <URL>`__
//

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::regex;
using std::regex_match;


// Globals. Yes, I know...
string this_line;

// Function prototype(s).
void doFile(const char *fname);


int main (int argc, char *argv[])
{
    for (int x = 1; x < argc; x++) {
        doFile(argv[x]);
    }
    return 0;
}


void doFile(const char *fname)
{
    // Open a file, read it, extract the keywords.

    unsigned lineNumber = 0;
    string linkText;  
    regex linkRegex(".*`.*<.*>`__.*");        // This should match a valid link.
    
    ifstream ifs (fname, std::ifstream::in);
    while (ifs.good()) {
        getline(ifs, this_line);
        lineNumber++;

        // There can be more than one link on a line of course!
        while (regex_match(this_line, linkRegex)) {
            
            // Where are we? For debugging.
            //cout << endl << fname << ": " << lineNumber << ":" << endl;
            //cout << this_line << endl;
        
            // Extract the link in this line.
            size_t posLink = this_line.find("`", 0, 1);
            size_t posEndLink = this_line.find("`_", posLink + 1, 2);

            // Write out the link details.
            linkText = this_line.substr(posLink, posEndLink - posLink + 3);
            cout << linkText << " in: " << fname << " at line: " << lineNumber << endl;
            
            // Adjust the line.
            this_line = this_line.substr(posEndLink+3, string::npos);
        }
    }

    ifs.close();
}

