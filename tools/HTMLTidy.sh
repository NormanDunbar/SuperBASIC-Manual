# Use `html-tidy` to clean up Rich's HTML files.
# Norman Dunbar.
# 22 July 2016

DIR=`dirname "${0}"`
HTML="${1}"
TMP=${HTML}.tmp
CLEAN="${HTML%%html}clean.html"
ERRS="${HTML%%html}errors.txt"
CHECK=0

# Clean up first...
# PreClean...
preHTMLTidy < ${HTML} > ${TMP}

echo "Cleaning '${HTML}' as '${CLEAN}', with errors in '${ERRS}'"
tidy -indent -wrap 1000 -upper -ashtml -utf8 -file "${ERRS}" -output "${CLEAN}" "${TMP}"
CHECK=${?}

# 1 = Warnings
# 2 = Errors

if [ "${CHECK}" != "0" ]
then
    echo "HTML Tidy failed, error ${CHECK}."
    echo "(1 = Warnings, 2 = Errors)"
    if [ "${CHECK}" = "2" ]
    then
        echo "The following errors need fixing:"
        grep "Error:" ${ERRS}
        exit ${CHECK}
    else
        echo "Check the following warnings in 'errors/${ERRS}' before continuing."
        grep "Warning:" ${ERRS}
    fi
fi


# Post cleaning cleaning next...
sed --file "${DIR}"/sed.file --in-place "${CLEAN}" 
CHECK=${?}

if [ "${CHECK}" != "0" ]
then
    echo "Sed failed, error ${CHECK}, Cannot continue."
    exit $?
fi

# Finished with ${TMP}
#rm ${TMP} 2>/dev/null

# All done. Sort of. Need to go manual now.
echo "Done."
exit ${CHECK}
