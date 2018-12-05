..  _datad-dlr:

DATAD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DATAD$                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function always contains the current default data device, which is
an unofficial QDOS standard and supported by all Toolkit II extensions,
original SuperBASIC commands and most good software.

The default device
means that if no other device is stated, if appropriate, this device
will be used. The default data device will also be consulted if a device
name is supplied but the given file cannot be found on that device. For
example, assuming that DATAD$='flp2\_', if you enter VIEW
ram1\_example\_txt and the file example\_txt is not present on ram1\_,
the command will then try flp2\_ram1\_example\_txt.

This idea can be
extended to use prefixes as sub-directories. Sub-directories are
separated by underscores, DATAD$ always ends with an underscore.


**Example**

TK2DIR reads all files from the current default data device via a pipe,
strips off any network sub-directory prefix and then writes the
remainder of the filenames into the string array passed by parameter.

::

    100 DEFine PROCedure TK2DIR (Verz$)
    110   LOCal e,n,sd$,sd,us
    120   sd$=DATAD$: us="_" INSTR sd$
    130   IF us=3 AND LEN(sd$)>3 and sd$(1)="n" THEN
    140     IF sd$(2) INSTR "12345678":sd$=sd$(4 TO):us="_" INSTR sd$
    160   END IF
    170   OPEN#4,pipe_10000: STAT#4: WDIR#4
    180   e=FILE_OPEN(#3,pipe_,CHANID(#4)): CLOSE#4
    200   INPUT#3,Verz$(0)
    210   FOR n=1 TO DIMN(Verz$)
    220     IF EOF(#3) THEN EXIT n
    230     INPUT#3,Verz$(n)
    240     Verz$(n)=Verz$(n)(us+1 TO)
    250   END FOR n
    260   CLOSE#3
    270 END DEFine TK2DIR

    DIM file$(20,30)
    TK2DIR file$
    CLS: PRINT file$

Here only the first 20 files will be read into file$. NB. This would
require substantial amendment to make it search sub-directories also.


**CROSS-REFERENCE**

:ref:`data-use` defines the default device;
:ref:`dup`, :ref:`ddown` and
:ref:`dnext` allow you to move around the
sub-directory tree. :ref:`progd-dlr` returns the
default program device. :ref:`dlist` prints all
default devices.

--------------


