..  _copy-o:

COPY\_O
=======

+----------+-------------------------------------------------------------------+
| Syntax   | COPY\_O [file1] [TO file2] or                                     |
|          |                                                                   |
|          | COPY\_O file1 [,file2 [,file3...]] {TO \| !} fileb (THOR XVI)     |
+----------+-------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                              |
+----------+-------------------------------------------------------------------+

The command COPY\_O is identical to Toolkit II's COPY command, but if
the file already exists, it will automatically be over-written without
asking the user for confirmation.

This command is also supported on the THOR XVI, although both the input
and destination channels must be specified in full.

**CROSS-REFERENCE**

:ref:`ftest` and :ref:`etat`
check the status of a file, thus enabling you to check if a file already
exists.

