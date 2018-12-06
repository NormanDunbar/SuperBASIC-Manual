..  _end--select:

END SELect
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  END SELect                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This marks the end of the SELect ON...END SELect SuperBASIC structure, and has no
meaning on its own. When the interpreter has found a match for the value of the
variable, it performs a series of commands, and then looks for the end of the block
marked with END SELect.

This means that except under SMS, unless an in-line SELect
ON structure is being used, if this command is missing, the interpreter will carry
on searching through the program and may just stop without an error if END SELect
does not appear anywhere in the program.

**NOTE 1**

END SELect need not appear in an in-line SELect ON statement.

**NOTE 2**

Under SMS, if END SELect appears in an in-line SELect ON
statement, if any commands appear after END SELect on the same line, an
error will be reported.

**SMS NOTE**

Checks are made on a program before it is run, and so if an END SELect
statement is missing, this will be reported as an error ('Incomplete
SELect clause'). SMS's improved interpreter will report the error
'Misplaced END SELect' if END SELect does not mark the end of a SELect
ON definition block.

**CROSS-REFERENCE**

Please see :ref:`select--on`. Other SuperBASIC
structures are :ref:`define--procedure`,
:ref:`define--function`,
:ref:`if`, :ref:`repeat`,
WHEN XXX and :ref:`for`.

