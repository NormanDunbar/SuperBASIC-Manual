..  _file-len:

FILE\_LEN
=========

+----------+------------------------------------------------------------------+
| Syntax   | FILE\_LEN (filename) or                                          |
|          |                                                                  |
|          | FILE\_LEN (file$)                                                |
+----------+------------------------------------------------------------------+
| Location | TinyToolkit                                                      |
+----------+------------------------------------------------------------------+

This function returns the length of a file in bytes. It does not
support the default devices or sub-directories.

**Example**

A short program to show simple file statistics (without any support of
wild cards)::

    100 dev$="FLP1_"
    110 OPEN#3,PIPE_10000: OPEN#4,PIPE_200
    120 TCONNECT #3 TO #4
    130 DIR#3,dev$: INPUT#4,h$\h$
    140 :
    150 sum=0: count=0
    160 REPeat add_lengths
    170   IF NOT PEND(#4) THEN EXIT add_lengths
    180   INPUT#4,file$
    185   IF " ->" INSTR file$ THEN NEXT add_lengths
    190   sum=sum+FILE_LEN(dev$ & file$)
    200   count=count+1
    210 END REPeat add_lengths
    220 :
    230 CLS
    240 PRINT "There are"!count!"files in"!dev$;"."
    250 PRINT "They are altogether"!sum!"bytes long,"
    260 PRINT "the average length is"!INT(sum/count+.5)!"bytes."

TinyToolkit's TCONNECT or DIY Toolkit's QLINK is necessary

**NOTE**

It is not recommended to get a file list by writing a directory into a
file or pipe. Problems arise with sub-directories on level-2 drivers: a
sub-directory is marked with an appended " ->" in the directory list
(WDIR, WSTAT, DIR), so opening a file such a "test ->" will fail. Refer
to OPEN\_DIR and FOP\_DIR for a cleaner method.

**CROSS-REFERENCE**

:ref:`flen` has a more flexible syntax.
:ref:`file-type`,
:ref:`file-dat`,
:ref:`file-pos`,
:ref:`fname-dlr`, :ref:`fpos`,
:ref:`ftyp`, :ref:`fupdt` and
:ref:`fxtra` hold other information on a file.

--------------


