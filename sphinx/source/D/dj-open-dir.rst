..  _dj-open-dir:

DJ\_OPEN\_DIR
=============

+----------+-------------------------------------------------------------------+
| Syntax   | channel = DJ\_OPEN\_DIR('filename')                               |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

All of these DJ\_OPEN functions return the SuperBasic channel number if the channel was opened without any problems, or, a negative error code otherwise. You can use this to check whether the open was successful or not.

The filename must be supplied as a variable name, file$ for example, or in quotes, 'flp1_fred_dat'.

They all work in a similar manner to the normmal SuperBasic OPEN procedures, but, DJ\_OPEN\_DIR offers a new function not normally found on a standard QL.

**DJToolkit Author's Note**

I am grateful to Simon N. Goodwin for his timely article in *QL WORLD volume 2, issue 8* (marked Vol 2, issue 7!!!). I had been toying with these routines for a while and was aware of the undocumented QDOS routines to extend the SuperBasic channel table. I was, however, not able to get my routines to work properly. Simon's article was a great help and these functions are based on that article. Thanks Simon.

**EXAMPLE**

The OPEN routines work as follows::

    1000 REMark open our file for input
    1010 :
    1020 chan = DJ_OPEN_IN('filename')
    1030 IF chan < 0
    1040    PRINT 'OOPS, failed to open "filename", error ' & chan
    1050    STOP
    1060 END IF
    1070 :
    1080 REM process data in file here ....

DJ\_OPEN\_DIR is a new function to those in the normal QL range, and it works as follows::

    1000 REMark read a directory
    1010 :
    1020 INPUT 'Which device ';dev$
    1030 chan = DJ_OPEN_DIR(dev$)
    1040 IF chan < 0
    1050    PRINT 'Cannot open ' & dev$ & ', error ' & chan
    1060    STOP
    1070 END IF
    1080 :
    1090 CLS
    1100 REPeat dir_loop
    1110   IF EOF(#chan) THEN EXIT dir_loop
    1120   a$ = FETCH_BYTES(#chan, 64)
    1130   size = CODE(a$(16)):       REMark Size of file name
    1140   PRINT a$(17 TO 16 + size): REMark file name
    1150 END REPeat dir_loop
    1160 :
    1170 CLOSE #chan
    1180 STOP

In this example, no checks are done to ensure that the device actually exists, etc. You could use :ref:`dev-name` to check if it is a legal device. The data being read from a device directory file must always be read in 64 byte chunks as per this example.

Each chunk is a single directory entry which holds a copy of the file header for the appropriate file. Note, that the first 4 bytes of a file header hold the actual length of the file but when read from the directory as above, the value if 64 bytes too high as it includes the length of the file header as part of the length of a file.

The above routine will also print blank lines if a file has been deleted from the directory at some point. Deleted files have a name length of zero.

Note that if you type in a filename instead of a device name, the function will cope. For example, you type in 'flp1\_fred' instead of 'flp1\_'. You will get a list of the files on 'flp1\_' if 'fred' is a file, or even, if 'fred' is not on 'flp1\_'. If, however, you have the LEVEL 2 drivers (see :ref:`level2` below), and 'fred' is a sub-directory then you will get a listing of the sub-directory as requested.

**CROSS-REFERENCE**

:ref:`dj-open`, :ref:`dj-open-in`, :ref:`dj-open-new`, and :ref:`dj-open-over`.

