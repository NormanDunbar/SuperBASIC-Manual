..  _concat:

CONCAT
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CONCAT file1,file2 TO file3                                      |
+----------+-------------------------------------------------------------------+
| Location |  CONCAT                                                           |
+----------+-------------------------------------------------------------------+

This command merges the first two files together to form a new file with
the third specified filename, so that file2 is appended to file1. The
length of file3 is exactly the sum of the lengths of the merged files.

**Example**

Most SuperBASIC programmers use their own standard set of

procedures and functions. If two of them need to be added

to a program, CONCAT helps a lot: CONCAT flp1\_PROG\_bas,flp1\_SUB\_1 TO
ram1\_PROG\_tmp DELETE flp1\_PROG\_bas CONCAT
ram1\_PROG\_tmp,flp1\_SUB\_2 TO flp1\_PROG\_bas DELETE ram1\_PROG\_tmp

You must ensure that line numbers do not conflict.

**NOTE**

Each filename must include the device.

**CROSS-REFERENCE**

:ref:`copy`, :ref:`rename`,
:ref:`delete`.

See :ref:`fwrite` for the more flexible APPEND
procedure.

