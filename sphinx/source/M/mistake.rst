..  _mistake:

MISTake
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MISTake                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

MISTake is a keyword which will only rarely ever be found. It cannot be
inserted into a program from the keyboard. Instead, it is generated
internally whenever LOAD, LRUN, MERGE or MRUN
commands are used and a line in the file being loaded cannot be parsed
(ie. if it would generate a 'bad line' error if typed in at the
keyboard).

Rather than reporting an error and stopping the loading
process, the word MISTake is inserted in the offending line after the
line number. If you then try to RUN the offending line, a 'Bad Line'
error will be generated (under SMS the error 'MISTake in program' is
reported.

You can however EDIT the offending line - you must delete the
word MISTake as well as correcting the error before the line will be
accepted by the parser. Once this is done, then the program should run
as normal.

**NOTE**

Unfortunately, QREF (from Liberation Software) cannot find lines
containing MISTake - in order to do this, you need a much more complex
system such as MasterBasic+ (from Ergon Development).

**CROSS-REFERENCE**

Please see :ref:`load` and
:ref:`merge` about loading a SuperBASIC program in
general.

--------------


