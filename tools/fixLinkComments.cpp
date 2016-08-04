#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

//
// Delete the temprary comments we added in fixLinks as they break the build!
// They are identified as lines beginning with ".. `" or ".. >`". There may be a blank
// line after, if so, it is also deleted.
//

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::fill;

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

        // Check for link comments.
        if ((a_line.substr(0, 4) == ".. `") || (a_line.substr(0, 5) == ".. >`")) {
            // delete it.
            getline(cin, a_line);
            // Is this blank?
            if (a_line.empty()) {
                // Delete it too.
                continue;
            }
            // Otherwise, drop through.
        }

        // No link comments, write out the buffer.
        cout << a_line << endl;
    }
}

