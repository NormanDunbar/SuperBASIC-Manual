..  _etat:

ETAT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ETAT (file$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  ETAT                                                             |
+----------+-------------------------------------------------------------------+

This function checks to see if the given file (passed as a string) exists and then
checks upon its status (whether it can be opened etc). If necessary a standard
error number is returned, otherwise ETAT will return 0, which means that the file
can be accessed without the danger of an error such as "not found". This can
therefore be used to avoid the need for error trapping.

**Example**

This program copies text files to window #1::

    100 REPeat input_loop
    110 INPUT "File to view:"!file$
    120   AnError=ETAT(file$)
    130   IF NOT AnError: EXIT input_loop
    140   PRINT "Sorry, ";: REPORT#1,AnError
    150 END REPeat input_loop
    160 OPEN_IN#3,file$
    170 REPeat view_file
    180 IF EOF(#3) THEN EXIT view_file
    190 INPUT#3,line$: PRINT line$
    200 END REPeat view_file
    210 CLOSE#3

**CROSS-REFERENCE**

:ref:`ftest` works like
:ref:`etat` but recognises the default device and
directory. :ref:`file-open`,
:ref:`fopen`, :ref:`fop-in`,
:ref:`fop-over` and
:ref:`fop-new` are all functions to open files
without the need for error trapping. :ref:`open`,
:ref:`open-in` and
:ref:`open-new` stop with error messages if an
error occurs. To avoid this, error trapping facilities, such as
:ref:`when--error` have to be used.

