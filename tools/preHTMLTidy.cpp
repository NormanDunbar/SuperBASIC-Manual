#include <iostream>
#include <iomanip>
#include <string>
#include <list>

//
// Some tags in the original HTML are of the form:
//
//  <br href="..."
//
// Which is wrong. These should be:
//
//  <a href="..."
//
// These should be fixed before we get to HTMLTidy.sh.
//
// Once the above is fixed, we check for "Location:" and if found
// scan for the next closing </span> and make sure we have a blank line after it.
//

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

    
int main (int argc, char *argv[])
{
    // Read stdin until EOF
	while (1) {
        getline(cin, a_line);

        // Check for end of input.
        if (cin.eof()) {
                return 0;
        }

        // Check for '<br href='
        size_t pos = a_line.find("<br href=", 0, 9);

        if (pos != string::npos) {
            // We have it. Fix it.
            a_line = a_line.substr(0, pos) + "<a href=" + a_line.substr(pos + 9, string::npos);
        }

        // We have fixed the faulty <a> tags, check for Location:
        pos = a_line.find("Location:", 0, 9);

        // Did we find it?
        if (pos != string::npos) {
            // See if </span> is on the same line.
            pos = a_line.find("</span>", pos + 9, 7);
            if (pos == string::npos) {
                // Try upper case, just in case.
                pos = a_line.find("</SPAN>", pos + 9, 7);
            }

            // Found? Write the current line up to the end of </span>
            // then write a blank, followed by the rest of the line after the </span>
            if (pos != string::npos) {
                cout << a_line.substr(0, pos + 7) << endl << endl; 

                // Check we don't fall off the end.
                if (pos + 7 <= a_line.size()) {
                    cout << a_line.substr(pos + 7, string::npos) << endl;
                }

                // Read and process the next line.
                continue;
            }

            // Not found. Write out the whole line, then read and check again.
            while (1) {
                cout << a_line << endl;

                getline(cin, a_line);

                // Check for end of input.
                if (cin.eof()) {
                        return 0;
                }
    
                pos = a_line.find("</span>", 0, 7);
                if (pos == string::npos) {
                    pos = a_line.find("</SPAN>", 0, 7);
                }

                if (pos == string::npos) {
                    // Write out and loop.
                    continue;
                }

                // We finally have it!
                // Write out with a blank after the </span>.
                cout << a_line.substr(0, pos + 7) << endl << endl;

                // Reset a_line ready for the break & write.
                a_line = a_line.substr(pos + 7, string::npos);
                break;
            }
            
        }

        // Finally write everything out.
        cout << a_line << endl;
	}
}


