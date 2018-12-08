..  _fmake-dir:

FMAKE\_DIR
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FMAKE\_DIR (subdirectory)                                        |
+----------+-------------------------------------------------------------------+
| Location |  Level-2 Device Drivers                                           |
+----------+-------------------------------------------------------------------+

This function will only work if Level-2 or Level-3 device drivers are
available.

FMAKE\_DIR is identical to MAKE\_DIR except that it is a
function and does not stop a program if an error occurs, instead it
returns the code of the error concerned.

The following errors need some explanation:

- Error -9 (in use) : There is already a sub-directory with the same name;
- Error -8 (already exists) : File (not a sub-directory) exists already with that name;
- Error -15 (bad parameter) : Medium does not support sub-directories.

**NOTE 1**

If MAKE\_DIR or FMAKE\_DIR fail on a ramdisk, an old type ramdisk may
have been loaded. There is no other way to activate the integral ramdisk
other than by resetting the whole system.

**NOTE 2**

If error -15 occurs (ie. if you try to created a sub-directory on a
medium where this is not possible), MAKE\_DIR and FMAKE\_DIR will leave
an empty file with the name of the desired sub-directory on the medium.
Remember to remove this.

**CROSS-REFERENCE**

See :ref:`make-dir`.

