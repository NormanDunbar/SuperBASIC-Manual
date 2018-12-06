..  _fvers:

FVERS
=====

+----------+------------------------------------------------------------------+
| Syntax   | FVERS [(#channel)] or                                            |
|          |                                                                  |
|          | FVERS (\\file)                                                   |
+----------+------------------------------------------------------------------+
| Location | Level-2 Device Drivers                                           |
+----------+------------------------------------------------------------------+

This function reads the version number of the given file (or of the
file attached to the specified channel {default #3} if the first variant
is used).

The version numbers can range from 0 to 2\ :sup:`16`-1 (65535)
and generally indicate how often a file has been amended. If a file was
created on a level-1 device driver system, its version number is zero
(0), while newly created files on level-2 device drivers will have the
version number 1 after they have been closed. FVERS supports Toolkit
II's default data device and sub-directories.

If the first variant is
used, the default channel is #3 if none is specified.

Each time that a
file is amended on level-2 and level-3 drivers, the version number is
increased by one. If the version reaches its limit of 65535, it will
start at version 1 again. A file has to be re-opened to change its
version by more than one. After the file has been amended, the version
will only increase after a FLUSH or CLOSE.

Unfortunately current
versions of SAVE and SBYTES do not increase the version number because
they overwrite existing files instead of truncating them.

**Example**

::

    OPEN_OVER#3,test_tmp: REMark create the file
    PRINT#3,"just a line": REMark write a line to the file
    PRINT FVERS(#3): REMark 0, neither flushed nor closed
    CLOSE#3: REMark close file
    PRINT FVERS(\test_tmp): REMark 1
    OPEN#3,test_tmp: REMark re-open file
    PRINT FVERS(#3): REMark 1, nothing changed yet
    PRINT#3,"replace the line": REMark amend file
    PRINT FVERS(#3): REMark still 1 not yet flushed
    FLUSH#3: REMark write slave blocks to file
    PRINT FVERS(#3): REMark now it's 2
    FLUSH#3: REMark flush again
    PRINT FVERS(#3): REMark  2
    PRINT#3,"next line": REMark change file again
    CLOSE#3: REMark close file
    PRINT FVERS(\test_tmp): REMark  still 2

**NOTE**

The file version number is not preserved if the file is overwritten.
However, if you make a copy of a file, this keeps the same version
number as the original, but not on Level-1 drivers.

**SMS NOTE**

If you use the SAVE command without a filename to save a previously
loaded SuperBASIC program, the file version number will be increased by
one.

**CROSS-REFERENCE**

:ref:`set-fvers` allows you to set the version
number.

