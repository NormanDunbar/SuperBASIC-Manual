..  _copy-n:

COPY\_N
=======

+----------+-------------------------------------------------------------------+
| Syntax   | COPY\_N file1 TO file2  or                                        |
|          |                                                                   |
|          | COPY\_N [file1] [TO file2] (Tooolkit II)  or                      |
|          |                                                                   |
|          | COPY\_N file1 [,file2 [,file3...]] {TO \| !} fileb (THOR XVI)     |
+----------+-------------------------------------------------------------------+
| Location | QL ROM, Toolkit II, THOR XVI                                      |
+----------+-------------------------------------------------------------------+


This command is basically the same as COPY, but the file header is
explicitly removed. This is important for example if you wish to copy a
file direct to a printer attached to ser2.

If the file header was also printed, this would include some
non-printable characters {eg. CHR$(0)}, which might be interpreted by
the printer as control characters and therefore produce rubbish as
output.

Toolkit II's COPY examines the type of the destination device before it
proceeds. It will not then copy the file header if this is a serial
device or a parallel port. The standard COPY command contained in the QL
ROM does not make this differentiation and so COPY\_N must be used
instead if the file header is not to be copied.

**CROSS-REFERENCE**

:ref:`copy-h` forces the file header to be copied
to the given destination (whether it is a serial port, a parallel port
or not), and the syntax is identical to :ref:`copy`,
:ref:`copy-n` and
:ref:`copy-o`.

