#include <iostream>
#include <iomanip>
#include <string>
#include <list>

//
// Some tags in the original HTML are of the form:
//
//  <br href="..."
//
// Whihc is wrongs. These should be:
//
//  <a href="..."
//
// These should be fixed before we get to HTMLTidy.sh.
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

            // Just write everything else out.
            cout << a_line << endl;
	}
}


