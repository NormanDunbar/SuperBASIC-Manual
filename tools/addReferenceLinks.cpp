#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>
#include <cctype>

//
// addReferenceLinks <list_of_files>
//
// This program will read the list of files and for each one found, 
// will extract all the existing "wrong format" links as follows:
// 
//      `Link Text <URL>`__
//
// These links need fixing as the current style only works in HTML
// generated output. PDF, for example, reports the links as broken.
//
// The fix is simple (!) - replace the above style links with:
//
//      :ref:`Link Text`
//
// Where a link is to a keywork that ends with a '%' or '$', then
// these characters are not permitted, so we change them to 
// '-pct' or '-dlr' accordingly.
//

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::regex;
using std::regex_match;
using std::smatch;
using std::regex_constants::match_any;
using std::regex_constants::ECMAScript;

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
    regex linkRegex("`.*?<Keywords.*?>`__"); // .*? = Non-greedy = will match all links on a line.
    smatch match;
    
    ifstream ifs (fname, std::ifstream::in);
    while (ifs.good()) {
        getline(ifs, this_line);
        lineNumber++;
        
        // No URLs? No worries!
        if (!regex_search(this_line, match, linkRegex)) {
            cout << this_line << endl;
            continue;
        }
           
        // We have (a) link(s) to a keyword somewhere.
        // There can be more than one link on a line of course!
        while (regex_search(this_line, match, linkRegex)) {
            
            // Where are we? For debugging.
            //cout << endl << fname << ": " << lineNumber << ":" << endl;
            //cout << this_line << endl;
            
            // Show details of a match.
            /*
            cout << endl << "MATCH:" << endl;
            for (unsigned x = 0; x < match.size(); x++) {
                cout << endl << fname << ": " << lineNumber << ":" << endl;
                cout << this_line << endl;
                cout << "match.position: " << match.position(x) << endl;
                cout << "match.length: " << match.length(x) << endl;
                cout << "match.text: '" << match[x] << "'" << endl;
                cout << "match.str: '" << match.str(x) << "'" << endl;
                cout << "match.prefix: '" << match.prefix() << "'" << endl;
                cout << "match.suffix: '" << match.suffix() << "'" << endl;
                
            }
            */
            
            // On match, write the prefix - the stuff before the URL.
            // Then a ref link (':ref:).
            // Then the new URL in backticks.
            // Job done, do any remaining URLs.        
            cout << match.prefix() << ":ref:`";
            
            // Extract the keyword from after the '#'.
            string url = match[0];
            size_t hashPos = url.find("#");
            if (hashPos == string::npos) {
                cerr << "BROKEN URL at line " << lineNumber << ":" <<  match[0] << endl;
                continue;
            }
            
            // Extract the lower cases keyword.
            size_t chevronPos = url.find(">");
            if (hashPos == string::npos) {
                cerr << "BROKEN URL at line " << lineNumber << ":" << match[0] << endl;
                continue;
            }

            string keyWord = url.substr(hashPos + 1, chevronPos - hashPos - 1);
            
            // Percent or Dollar?
            size_t len = keyWord.length() -1;
            if (keyWord.at(len) == '%') {
                keyWord = keyWord.substr(0, len) + "-pct";
            } else 
                if (keyWord.at(len) == '$') {
                keyWord = keyWord.substr(0, len) + "-dlr";
            }
            cout <<keyWord << "`";
            
            // Adjust the line.
            this_line = match.suffix();
        }
        
        // This is the rest of the line after all URLs.
        cout << this_line << endl;
    }

    ifs.close();
}

