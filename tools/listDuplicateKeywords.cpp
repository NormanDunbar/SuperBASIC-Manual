#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <cctype>

//
// listDuplicateKeyword <keyword file>
//
// This program will read the list of keywords produced by extracteAllKeywords.cmd, 
// and will list all those found to be duplicated. This helps when setting up the
// keyword and reference links.
// 

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;


string this_line;
string last_line = "Dummy Keyword";

void doFile(const char *fname);


int main (int argc, char *argv[])
{
    if (argc != 2) {
        cerr << "No keyword file parameter supplied.";
        return 1;
    }
    
    cout << endl << "The following are duplicated keywords" << endl << endl;
    doFile(argv[1]);
    cout << endl << "Finished." << endl << endl;

    return 0;
}


void doFile(const char *fname)
{
    // Open a file, read it, extract the keywords.
    // Then check if this one is the same as the previous one.

    ifstream ifs (fname, std::ifstream::in);
    while (ifs.good()) {
        getline(ifs, this_line);
        if (this_line == last_line) {
            cout << last_line << endl;
        }
        
        last_line = this_line;
    }

    ifs.close();
}

