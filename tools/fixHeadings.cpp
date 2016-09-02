#include <iostream>
#include <iomanip>
#include <string>
#include <list>

//
// Some code to fix the various <h1> lines from Rich's
// SuperBASIC manual, into a correct heading format.
// Something like:
//
//      ` <>`__\ BASIC\_B
//      ~~~~~~~~~~~~~~~~~
//
// becomes
//
//      BASIC\_B
//      ========
//
//
// Also, various headings are converted to bold instead. They 
// never needed to be headings originally. This makes the contents
// on the generated HTML, PDF, ePub etc much easier to use.
// And smaller!

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::fill;
using std::list;

// Globals. I know, but it's quicker ok! ;-)
string a_line;

// Things I need to change from headings to bold only.
string lookFor[] = {"NOTE:",  "NOTES:", "NOTE 1:", "NOTE 2:", "NOTE 3:", "NOTE 4:",
                    "NOTE 5:", "NOTE 6:", "NOTE 7:", "NOTE 8:", "NOTE 9:",
                    "CROSS-REFERENCE:", "CROSS -REFERENCE:", "CROSS- REFERENCE:",
                    "WARNING:", "WARNINGS:", "WARNING 1:", "WARNING 2:", "WARNING 3:", "WARNING 4:",
                    "WARNING 5:", "WARNING 6:", "WARNING 7:", "WARNING 8:", "WARNING 9:",
                    "EXAMPLE:", "EXAMPLES:", "EXAMPLE 1:", "EXAMPLE 2:", "EXAMPLE 3:",
                    "EXAMPLE 4:", "EXAMPLE 5:", "EXAMPLE 6:", "EXAMPLE 7:",
                    "EXAMPLE 8:", "EXAMPLE 9:",
                    "Example:", "Examples:", "Example 1:", "Example 2:", "Example 3:",
                    "Example 4:", "Examples 5:", "Example 6:", "Example 7:", "Example 8:",
                    "Example 9:"};

// Map the above into a string list.
list<string> lookForThese(lookFor, lookFor + sizeof(lookFor) / sizeof(string));


bool doStrings();
	
    
int main (int argc, char *argv[])
{
    // Read stdin until EOF
	while (1) {
		getline(cin, a_line);

		// Check for end of input.
		if (cin.eof()) {
			return 0;
		}
		
		// Check for "` <>`__\ ".
		size_t pos = a_line.find("` <>`__\\ ", 0, 9);
		
		if (pos != string::npos) {
            // We have a heading. Fix it and the following line.
            cout << a_line.substr(9, string::npos) << endl;
            char prevFill = cout.fill('=');
            cout << setw(a_line.size() - 9) << "=" << endl;
            cout.fill(prevFill);
            
            // Lose the underline
            getline(cin, a_line);
            continue;
		}
      
        // Anything that's a heading that shouldn't be?
        if (doStrings()) 
            continue;
        
		// Just write everything else out.
		cout << a_line << endl;
	}
}


bool doStrings()
{
    // Print contents of lookForThese list.
    for (list<string>::iterator thisOne = lookForThese.begin(); thisOne != lookForThese.end(); thisOne++) {
    
        string temp = *thisOne;
        size_t tempSize = temp.size();
        size_t pos;

        // Do we have it in the buffer?
        pos = a_line.find(temp.c_str(), 0, tempSize);
        if (pos != string::npos) {

            // Yes we do... lose the colon and make it bold and not a heading.
            // But remember, it might not be at the start of a line!
            // cout << "..    " << a_line << endl << endl;   // Curent line as comment.
            cout << "**" << a_line.substr(0, pos + tempSize - 1) << "**" << endl;
            
            // Lose the following underline.
            getline(cin, a_line);

            // We have processed this line. Read the next line on return.
            return true;
        }
    }

    // Nothing changed, process the line as normal.
    return false;
}
