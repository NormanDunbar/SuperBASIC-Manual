#include <iostream>
#include <iomanip>
#include <string>
#include <list>

//
// Fix links in the generated ReStructuredText files.
// The default is `XXX <KeywordsX.html#XXX>`__ and we want just `XXX`_.
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
    size_t posBackTick;
    size_t posKeywords;
    size_t posHtmlHash;
    size_t posClosing;
    size_t posTerminator;
    string whiteSpace = " \t\f\v\n\r";
    string buffer;

    // Read stdin until EOF
	while (1) {
		getline(cin, a_line);
        std::cerr << "*** \"" << a_line << "\"" << endl;

		// Check for end of input.
		if (cin.eof()) {
			return 0;
		}

        // Check for comments.
        if (a_line.substr(0, 2) == "..") {
            continue;
        }

        // Clear the output buffer;
        buffer.clear();
		
try_again:
        std::cerr << "Try again..." << endl;
        std::cerr << "A *** \"" << a_line << "\"" << endl;
        std::cerr << "B *** \"" << buffer << "\"" << endl << endl;

		// Check for a link. Maybe more than 1...
        // eg "See `XXX <KeywordsX.html#XXX>`__ and `YYY <KeywordsY.html#YYY>`_ for further details.".
        //     Should become "See `XXX`_ and `YYY`_ for further details.".

        posBackTick = a_line.find("`", 0, 1);
        posKeywords = a_line.find(" <Keywords", 0, 10);
        posHtmlHash = a_line.find("html#", 0, 5);

        if ((posBackTick != string::npos) && (posKeywords != string::npos) && (posHtmlHash != string::npos)) {
            // We have a link. Output current line as a comment.
            cout << ".. " << a_line << endl << endl;

            // Copy everything up to the backtick to the output buffer.
            buffer += a_line.substr(0, posBackTick - 1);

            // Find the closing '>`_' or '>`__', start checking from posHtmlHash.
            // Try double underscore first.
            posClosing = a_line.find(">`__", posHtmlHash, 4);
            if (posClosing == string::npos) {
                // Failed. Try one underscore.
                posClosing = a_line.find(">`_", posHtmlHash, 3);
                if (posClosing == string::npos) {
                    cout << "FIXME - broken link suspected ********************************* " << endl;
                    cout << a_line << endl;
                    continue;
                } else {
                    // Adjust to the end of the search text.
                    posClosing += 3;
                }
            } else {
                // Adjust to the end of the search text.
                posClosing += 4;
            }

            // Work backwards from posKeywords to find the previous non space character.
            // We start as posKeywords as that is the space in front of <Keyword...!
            size_t posTerminator = a_line.find_last_not_of(whiteSpace, posKeywords);
            if (posTerminator == string::npos) {
                    cout << "FIXME - broken link suspected ********************************* " << endl;
                    cout << a_line << endl;
                    continue;
            }

            // We have our termiating position, add the short link to the buffer.
            buffer += a_line.substr(posBackTick, posTerminator - posBackTick + 1) += "`_ ";

            // And strip out the whole URL we found, before searching the line for another.
            a_line = a_line.substr(posClosing, string::npos);
            goto try_again;
        }
		
		// Just write everything out if there are no links.
        if (buffer.empty()) {
            cout << a_line << endl;
        } else {
            cout << buffer << endl;
        }
	}
}

