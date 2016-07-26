# Use `pandoc` to convert Rich's HTML files to Restructured Text (rst).
# Required for Sphinx-doc usage.
#	
# Norman Dunbar.
# 24 July 2016

HTML="${1}"
RST="${HTML%%html}rst"

echo "Converting '${HTML}' to '${RST}'"

# Pre conversion cleaning first...
sed --file rstSed.file --in-place "${HTML}" 
CHECK=${?}

if [ "${CHECK}" != "0" ]
then
    echo "Sed failed, error ${CHECK}, Cannot continue."
    exit $?
fi
# Convert to RST...
pandoc -f html -t rst -o "${RST}" "${HTML}"
CHECK=${?}

if [ "${CHECK}" != "0" ]
then
    echo "Pandoc failed, error ${CHECK}, Cannot continue."
    exit $?
fi
# All done. Sort of. Need to go manual now.
echo "Done."

