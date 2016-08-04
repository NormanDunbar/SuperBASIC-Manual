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

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

void doSyntax(const size_t pos);
void doLocation(const size_t pos);
void doBoth(const size_t posSyntax, const size_t posLocation);

string a_line;
    
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

        // Did we find both of them in one line?
        if ((posSyntax != string::npos) && (posLocation != string::npos)) {
            doBoth(posSyntax, posLocation);

            // We continue because we do Syntax first, then Location
            // And doLocation writes out all the lines it reads.
            continue;
        }

        // Try just the Syntax: line then? If we find a Location line
        // in doSyntax, it gets correctly processed so we need a new line.
        if (posSyntax != string::npos) {
            doSyntax(posSyntax);
            continue;
        }
            
        // Check for "Location:". We need a new line afterwards.
        posLocation = a_line.find("Location:", 0, 9);
        if (posLocation != string::npos) {
            doLocation(posLocation);
            continue;
        }

        // Just write everything else out.
        cout << a_line << endl;
    }
}


void doSyntax(const size_t pos)
{
    // Process the Syntax: part of the fixup.
    // Read lines until we get a blank, (??) or a line
    // with "Location:" in it. Keep everything then
    // slice out each individual option for syntax.
    
    string buffer;
    size_t posLocation;
    
    cout << tableSeparator << endl;
    cout << "| Syntax   | ";        // 13 characters, no linefeed.
    
    // Keep the rest of the Syntax: line.
    buffer = a_line.substr(pos + 7, string::npos);
    
    while (1) {
        // Read a few more lines. We shouldn't hit EOF here! (FLW!)
        getline(cin, a_line);
        posLocation = a_line.find("Location:", 0, 9);
        if ((posLocation != string::npos) || (a_line.size() == 0)) {
            break;
        } else {
            buffer += (" " + a_line);
        }
    }
    
    // We have the full text of the syntax line in our buffer.
    if (buffer.size() < 80-2-13) {
        // Just write the whole line out.
        
        cout << buffer;
        cout << setw(80-13-buffer.size()) << "|" << endl;
    } else {
        // Need to split the buffer at any " or " text. 
        
        while (1) {
            posLocation = buffer.find(" or ", 0, 4);
            if (posLocation != string::npos) {
                // We have a split.
                string temp = buffer.substr(0, posLocation + 3);
                cout << temp;
                cout << setw(80-13-temp.size()) << "|" << endl;
                buffer = buffer.substr(posLocation + 4, string::npos);
                
                // Do we need another line?
                if (buffer.find(" or ", 0, 4) != string::npos) {
                    cout << "|          | ";
                }
            } else {
                // No splitter. Write out the rest of the buffer.
                cout << "|          | " << buffer;
                cout << setw(80-13-buffer.size()) << "|" << endl;
                break;
            }
        }
    }

    cout << tableSeparator << endl;
    
    // Did we find a "Location:" line? If so, it's in a_line
    // so process it because we "continue" on return from here
    // and would lose the newly read line.
    if (posLocation != string::npos) {
        doLocation(posLocation);
    }
    
}


void doLocation(const size_t pos)
{
    // Process the Location: part of the fixup.
    // There should be a tableSeparator just above from Syntax.
    
    string buffer;
    
    cout << "| Location | ";        // 13 characters, no linefeed.
    
    // Keep the rest of the Location: line.     
    buffer = a_line.substr(pos + 9, string::npos);

    while (1) {
        // Read a few more lines. We shouldn't hit EOF here! (FLW!)
        getline(cin, a_line);
        if (a_line.size() == 0) {
            break;
        } else {
            buffer += (" " + a_line);
        }
    }
    
    // We have the full text of the Location line in our buffer.
    if (buffer.size() < 80-2-13) {
        // Just write the whole line out.
        cout << buffer;
        cout << setw(80-13-buffer.size()) << "|" << endl;
    } else {
        // Need to split the buffer at WHAT EXACTLY???. 
        cout << buffer << " |" << endl;
    }

    cout << tableSeparator << endl; 
    
    // And write out the blank line we just read.
    cout << a_line << endl;
}


void doBoth(const size_t posSyntax, const size_t posLocation)
{
    // We have Syntax: and Location: on the same line.
    // Split off the Location: part, keeping "Location:".
    string locBuffer = a_line.substr(posLocation, string::npos);

    // Keep just the Syntax: part.
    a_line = a_line.substr(posSyntax + 7, posLocation - 8);
    
    // Write out the syntax table cell and the syntax details.
    cout << tableSeparator << endl;
    cout << "| Syntax   | " << a_line;
    cout << setw(80-13-a_line.size()) << "|" << endl;
    cout << tableSeparator << endl;

    // Then do the Location details.
    a_line = locBuffer;
    doLocation(0);   
}

