#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

//
// Fix links in the generated ReStructuredText files.
// The default is `XXX <KeywordsX.html#XXX>`__ and we want `XXX <KeywordsX.clean.html#xxx>`__
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
		// Check for a link. Maybe more than 1...
        // eg "See `XXX <KeywordsX.html#XXX>`__ and `YYY <KeywordsY.html#YYY>`_ for further details.".

        posBackTick = a_line.find("`", 0, 1);
        posKeywords = a_line.find(" <Keywords", 0, 10);
        posHtmlHash = a_line.find("html#", 0, 5);

        if ((posBackTick != string::npos) && (posKeywords != string::npos) && (posHtmlHash != string::npos)) {
            // We have a link. Output current line as a comment.
            // Only for debugging. It interferes if we do it for live.
            // cout << ".. " << a_line << endl << endl;

            // Copy everything up to the backtick to the output buffer. Then
            // add "clean." and then the "html#".
            buffer += a_line.substr(0, posHtmlHash);
            buffer += "clean.";
            buffer += a_line.substr(posHtmlHash, 5);

            // Find the end of the URL.
            posTerminator = a_line.find(">", posHtmlHash + 5, 1);
            if (posTerminator == string::npos) {
                cout << "*** FIXME: Invalid URL, no closing '>'" << endl;
                cout << buffer << endl;
                continue;
            }

            // Lowercase the anchor name. If we don't then links don't work
            // as they only link to the html file, not to the actual anchor.
            // Underscores too get replaced by hyphens.
            for (size_t x = posHtmlHash + 5; x < posTerminator; x++) {
                char c = tolower(a_line.at(x));
                
                // Amend any special chracters we need to fixup.
                if (c == '_') 
					c = '-';
				
				// Delete any specials that are ignored. This might
				// be fun - BASIC_W and BASIC_W% for example. Problem,
				// If BASIC_W gets URL #basic-w, BASIC_W% gets #id2. 
				// Hmmm!	
				if (c == '$' || c == '%')
						continue;
				
				// And add the modified character to the buffer.	
                buffer += c;
            }

            // Strip off what we just converted.
            a_line = a_line.substr(posTerminator, string::npos);
            goto try_again;

        } else {
            // No links found. Append a_line to buffer.
            buffer += a_line;
        }
		
		// Just write everything out if there are no links.
        cout << buffer << endl;
	}
}

