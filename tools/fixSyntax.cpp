#include <iostream>
#include <iomanip>
#include <string>

//
// Some code to wrap the "Syntax:" and "Location:" lines from Rich's
// SuperBASIC manual, in a ReStructuredText grid table. Something like:
//
// +----------+------------------------------+
// | Synatx   | CLOSE #channel  or           |
// |          | CLOSE                        |
// +----------+------------------------------+
// | Location | QL ROM                       |
// |          | Minerva                      |
// +----------+------------------------------+
//
// Syntax should be split at " or " so that each option is on a
// separate line. Likewise, Location.
//
// Of course, sometimes Location: and Syntax: happen to be on the
// same line, which is, to be blunt, a bit of a bugger!
//
// So far I've seen the following:
//
// 1. Syntax: blah Location: Blah<eol>
//
// 2. Syntax: blah<eol>
//    Location: Blah<eol>
//
// 3. Syntax: blah<eol>
//    blah blah blah Location: Blah<eol>
//
// 4. Syntax: blah<eol>
//    blah blah blah<eol>
//    blah blah blah<eol>
//    blah blah blah Location: Blah<eol>
//
// In any of the above, Location's line may or may not be followed by a blank.


using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

void doSyntax(const size_t pos);
void doLocation(const size_t pos);
void doBoth(const size_t posSyntax, const size_t posLocation);

string a_line;          // Storage for each line, without a line feed.
string buffer;          // Storage for entire Syntax: + Location: section, with linefeeds.
    
string tableSeparator = 
    "+----------+-------------------------------------------------------------------+";
    
int main (int argc, char *argv[])
{
    // Read stdin until EOF
    while (1) {
        getline(cin, a_line);

        // Check for end of input.
        if (cin.eof()) {
            return 0;
        }
        
        // Check for "Syntax:" and "Location:"
        size_t posSyntax = a_line.find("Syntax:", 0, 7);
        size_t posLocation = a_line.find("Location:", 0, 9);

        // Did we find Syntax?
        if (posSyntax == string::npos) {
            // Not found, write the line to output and continue reading.
            // We should trim leading spaces though.
            cout << a_line << endl;
            continue;
        }
        
        // We must have found Syntax:, read until we find Location: too.
        buffer = "";
        while (posLocation == string::npos) {
            buffer += a_line += " ";
            getline(cin, a_line);
            
            // Should never happen ..... (FLW!)
            if (cin.eof()) {
                break;
            }
            
            posLocation = a_line.find("Location:", 0, 9);
        }
        
        // Add the last line to the buffer.
        buffer += a_line;
        
        // posSyntax is fine.
        // PosLocation is relevant to the final line only. 
        // We need to find it in relation to buffer.
        posLocation = buffer.find("Location:", posSyntax + 7, 9);
        
        // Write out the syntax/location table.
        // We assume the whole lot fits in 80 characters.
        cout << tableSeparator << endl;
        string temp = buffer.substr(posSyntax + 7, posLocation - posSyntax - 7);
        cout << "| Syntax   | " << temp;
        cout << setw(80 - 13 - temp.size()) << "|" << endl;
        cout << tableSeparator << endl;
        temp = buffer.substr(posLocation + 9, string::npos);
        cout << "| Location | " << temp;
        cout << setw(80 - 13 - temp.size()) << "|" << endl;
        cout << tableSeparator << endl << endl;
        
        
        
    }
}



