# Use `pandoc` to convert Rich's HTML files to Restructured Text (rst).
# Required for Sphinx-doc usage.
# Assumes that the tools directory is on PATH.
#	
# Norman Dunbar.
# 24 July 2016

DIR=`dirname "${0}"`
HTML="${1}"
RST="${HTML%%html}rst"
TMP="${RST}".tmp

echo "Converting '${HTML}' to '${RST}'"

# Pre conversion cleaning first...
sed --file "${DIR}"/rstSed.file --in-place "${HTML}" 
CHECK=${?}

if [ "${CHECK}" != "0" ]
then
    echo "Sed failed, error ${CHECK}, Cannot continue."
    exit $?
fi

# Convert to RST...
pandoc -f html -t rst -o "${TMP}" "${HTML}"
CHECK=${?}

if [ "${CHECK}" != "0" ]
then
    echo "Pandoc failed, error ${CHECK}, Cannot continue."
    exit $?
fi

# Sort out the Syntax: and Location: stuff as best we can.
# FixSyntax does both Syntax and Location and gets it nearly
# correct most of the time!
#
# Pipe through fixHeadings too to do the headings. And other
# stuff as well.
#
# Then pipe into fixLinks to convert all URLs from something
# like <KeywordsX.html#XXXX> to <KeywoprdsX.clean.html#xxxx>
# where we add ".clean'" and lowercase the anchor.
#
# Which while they are not perfect, it does save a huge amount
# of typing. These assume that the tools folder is on $PATH.
fixSyntax < "${TMP}" | fixHeadings | fixLinks > "${RST}" && rm "${TMP}"


# All done. Sort of. Need to go manual now.
echo "Done."

