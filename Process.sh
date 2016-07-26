# Process a "dirty" html file to clean first, then
# convert it to RST.
# Afterwards, copy the files to an appropriate place.
#
# Norman Dunbar
# 26th July 2016
#
# Expects to find HTMLTidy.sh and HTML2rst.sh in the current directory.
#

# Clean up the HTML and create a file called x.clean.html from x.html.
HTML="${1}"
CLEAN="${HTML%%html}clean.html"
RST="${CLEAN%%html}rst"
ERRORS="${HTML%%html}errors.txt"

./HTMLTidy.sh ${HTML} && ./HTML2rst.sh ${CLEAN}

mv ${HTML} html/
mv ${CLEAN} clean/
mv ${ERRORS} errors/
mv ${RST} sphinx/source/

