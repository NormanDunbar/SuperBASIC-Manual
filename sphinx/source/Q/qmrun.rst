..  _qmrun:

QMRUN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QMRUN [device\_]filename                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is exactly the same as QMERGE except that it ensures that
the program is RUN as soon as it has been merged into memory. If the
command is issued from the command line as a direct command, then the
merged program is RUN from line 1. If, however, QMRUN appears in the
program itself, the program continues from the statement following QMRUN
(making it the same as QMERGE).

**CROSS-REFERENCE**

See :ref:`qmerge` and
:ref:`mrun`.

