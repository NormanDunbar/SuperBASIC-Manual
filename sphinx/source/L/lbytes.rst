..  _lbytes:

LBYTES
======

+----------+------------------------------------------------------------------+
| Syntax   | LBYTES device\_filename, start  or                               |
|          |                                                                  |
|          | LBYTES [device\_]filename, start(Toolkit II only)  or            |
|          |                                                                  |
|          | LBYTES #channel, start(SMS only)                                 |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command loads a chunk of machine code (or data) stored on the
given device under the specified filename and will report the error 'Not
Found' (-7) if either the device or filename does not exist. If Toolkit
II is present, this command supports the default data device (see
DATAD$). If found, the chunk of machine code is loaded into the QL,
starting at the specified start address. The code is loaded in one huge
block, which means that loading is very quick. However, there is also no
check on the type of file being loaded and therefore you should make
sure that you know what you are doing. Under SMS the third variant
allows you to load the data from the specified channel which must be
open to a file. This allows for more efficient programs, so that you can
perform various tests on the file beforehand (such as test its length
and file type), whilst only opening a channel to the file once.

**Examples**

One of the main uses of this command is to load in machine code Toolkits
and extensions. It is important to note that if this command is used to
do this, on pre JS ROMs, the commands in the machine code Toolkit cannot
be used in the same program which links them in. A typical boot program
would therefore be::

    100 a=RESPR (1024) : LBYTES flp1_Toolkit_ext,a : CALL a
    110 LRUN flp1_Main_bas

Another use of LBYTES may be to load a screen which has been designed
in a drawing program. A normal QL screen is a maximum of 32768 bytes
long, however quite often screens can be much larger, so it is important
to ensure that you check the length of the file before loading in what
may be a screen file. To load a screen under SMS, use::

    10 OPEN_IN #3,flp1_Loading_scr
    20 scr_length=FLEN (#3)
    30 scr_size=SCR_YLIM * SCR_LLEN
    40 IF scr_size < scr_length
    42 PRINT #0,'Screen resolution is too small for the saved file.':STOP
    45 END IF
    50 IF scr_size>scr_length:PRINT #0,'Screen resolution is too big for the saved file.':STOP
    60 LBYTES #3,SCR_BASE
    70 CLOSE #3

**WARNING**

There is no check on the value of start, so ensure that you only try to
LBYTES machine code into RAM which has been set aside with ALCHP or
RESPR. Also ensure that the file is not too long to fit in the area of
RAM allocated.

**CROSS-REFERENCE**

Normally code loaded with :ref:`lbytes` has been
saved using :ref:`sexec` or
:ref:`sbytes`. :ref:`flen`
allows you to find out the length of a file,
:ref:`ftyp` its file type.

