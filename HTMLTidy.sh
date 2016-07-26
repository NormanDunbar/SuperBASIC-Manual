# Use `html-tidy` to clean up Rich's HTML files.
# Norman Dunbar.
# 22 July 2016

HTML="${1}"
CLEAN="${HTML%%html}clean.html"
ERRS="${HTML%%html}errors.txt"
CHECK=0

# Clean up first...
echo "Cleaning '${HTML}' as '${CLEAN}', with errors in '${ERRS}'"
tidy -indent -wrap 1000 -upper -ashtml -utf8 -file "${ERRS}" -output "${CLEAN}" "${HTML}"
CHECK=${?}

# 1 = Warnings
# 2 = Errors

if [ "${CHECK}" != "0" ]
then
    echo "HTML Tidy failed, error ${CHECK}, Cannot continue."
    echo "(1 = Warnings, 2 = Errors)"
    if [ "${CHECK}" = "2" ]
    then
        echo "The following errors need fixing:"
        grep "Error:" ${ERRS}
        exit ${CHECK}
    else
        echo "Check the warnings in '${ERRS}' before continuing."
    fi
fi


# Post cleaning cleaning next...
sed --file sed.file --in-place "${CLEAN}" 
CHECK=${?}

if [ "${CHECK}" != "0" ]
then
    echo "Sed failed, error ${CHECK}, Cannot continue."
    exit $?
fi


# All done. Sort of. Need to go manual now.
echo "Done."

