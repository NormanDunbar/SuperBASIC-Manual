..  _qload:

QLOAD
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QLOAD [device\_]filename                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is very similar to LOAD as implemented on the SMS. The
only difference are that it insists that the program must have been
saved with the \_sav suffix (eg. flp1\_TEST\_sav). QLOAD will then
proceed to load the BASIC program whether it was saved with the normal
SAVE or SAVE\_O commands, or with the QSAVE or QSAVE\_O commands.

**NOTE 1**

If a program has been saved using QSAVE on a Minerva machine with
Integer Tokenisation enabled, then QLOAD will not be able to understand
it properly and you will notice that numbers and keywords have been
replaced by various symbols.

**NOTE 2**

Any commands which appear after a QLOAD command will be ignored.

**CROSS-REFERENCE**

Also see :ref:`load`,
:ref:`qlrun`, :ref:`qmerge` and
:ref:`qsave` Compare
:ref:`unload`.

--------------


