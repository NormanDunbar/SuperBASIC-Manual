..  _rand:

RAND
====

+----------+------------------------------------------------------------------+
| Syntax   | RAND (devicename)  or                                            |
|          |                                                                  |
|          | RAND (device$)                                                   |
+----------+------------------------------------------------------------------+
| Location | TinyToolkit                                                      |
+----------+------------------------------------------------------------------+

Every physical directory device (eg. floppies and microdrives, but not
RAM disks), contain a random number in their FAT (which is a place on
the medium which contains internal data, the number of free/bad/empty
sectors etc). The function RAND returns this number which can be used by
QDOS to check if a medium has been changed.

**NOTE**

QDOS increases access speed by temporarily storing data in so-called
slave blocks. On QDOS and compatible machines this may lead to the
phenomenon that RAND only returns the correct value the first time that it
is used, and then returns the same value for any other medium. This can
be avoided by using the command DEL\_DEFB, or better CLRMDV before each
RAND.

**CROSS-REFERENCE**

:ref:`fop-dir` opens a directory.
:ref:`flp-sec` allows you to alter the amount of
checking carried out by a disk interface to see if a disk has been
swapped.

