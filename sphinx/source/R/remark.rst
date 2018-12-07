..  _remark:

REMark
======

+----------+-------------------------------------------------------------------+
| Syntax   |  REMark text                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command has no purpose when a program is RUNing. It is however
used to place comments in the program which can be useful when you later
come to edit a SuperBASIC program. Anything which appears after REMark
on the same line, will be ignored by the interpreter, thus allowing you
to make any sort of comment you like.

**Example**

    100 REMark Line 110 could be altered to:
    101 REMark 110 INPUT 'Your name';a$:IF password$<>a$:STOP
    110 Name$='Author'

**CROSS-REFERENCE**

Another means of splitting a SuperBASIC program into sections is to
include program lines which only contain a colon (:), for example::

    100 PRINT "End of Program":STOP
    110 :
    200 DATA 'Some data to read'

