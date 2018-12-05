..  _qsave:

QSAVE
=====

+----------+------------------------------------------------------------------+
| Syntax   | QSAVE [device\_]filename  or                                     |
|          |                                                                  |
|          | QSAVE                                                            |
+----------+------------------------------------------------------------------+
| Location | SMS                                                              |
+----------+------------------------------------------------------------------+

For several years now, the best utility for saving SuperBASIC programs
in a form which can be loaded very quickly into memory has been QLOAD
from Liberation Software.

This utility stores SuperBASIC programs on
disk in a special format which although seems meaningless if you VIEW
the file, allows the program to be loaded at around 3x the speed of the
normal LOAD command, which can be very useful for large programs.

Unlike other similar utilities, programs which have been saved using this
utility can be loaded into any other ROM version without any trouble,
using the QLOAD command. It is nice to see that this utility has been
implemented as part of SMS.

The QSAVE command allows you to save the
whole of SuperBASIC program currently in memory under the specified
filename to the specified device. If the filename does not end in the
suffix \_SAV, then this will be added automatically.

If no device is
specified (or it does not exist), then Toolkit II's default data device
will be used. You will also be prompted to confirm whether an existing
file should be overwritten if necessary.

The second variant of the
command will allow you to QSAVE
the program in memory under the same filename as when LOAD or QLOAD was
last used (with the \_SAV suffix appended if necessary).

If the original
filename used when the program was LOADed ended in \_BAS, then QSAVE
will alter this to be the \_SAV suffix.

This variant will also take the
version number of the file when it was LOADed (or QLOADed) and then
increase this by one.

**NOTE 1**

To ensure that QSAVEd programs can be used on all implementations of the
QL, ensure that if used from Minerva, Integer Tokenisation is switched
off - you will need to follow the following procedure:

#. POKE \\\\212,128
#. LOAD the ASCII version of the program (or type NEW)
#. Alter the program as necessary ...
#. QSAVE the fast loading version of the program.

**NOTE 2**

QSAVE without a filename suffers the same problems as SAVE.

**CROSS-REFERENCE**

See :ref:`save`, :ref:`qlrun` and
:ref:`qmerge`. :ref:`datad-dlr`
allows you to read the current default data device. See also
:ref:`qsave-o`. :ref:`fvers`
allows you to read the current version number of a file.

--------------


