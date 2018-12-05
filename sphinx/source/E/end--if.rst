..  _end--if:

END IF
======

+----------+-------------------------------------------------------------------+
| Syntax   |  END IF                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the IF..END IF SuperBASIC structure, and has no meaning
on its own.

When the interpreter finds an IF condition statement it then evaluates
the condition and carries out certain commands depending on whether the condition was
true or false.

Having carried out those commands, the interpreter then looks for a
related END IF command, and will pass control onto the statement following END IF.

This does however mean, that except under SMS, unless an in-line IF structure is
being used, if this command is missing, the interpreter will carry on searching
through the program and may just stop without an error if END IF  does not appear
anywhere in the program.

**NOTE 1**

END IF need not appear in an in-line IF statement.

**NOTE 2**

All ROMs (except for Minerva v1.93+ or SMS) can get mixed up with
multiple in-line IF..END IF structures - see IF.

**SMS NOTE**

Checks are made on a program before it is run, and so if an END IF
statement appears without a corresponding IF command, the error
'Misplaced END IF' is reported.

**CROSS-REFERENCE**

Please see :ref:`if`. Other SuperBASIC structures are:
:ref:`define--procedure`,
:ref:`define--function`,
:ref:`select--on`, :ref:`repeat`,
:ref:`for`, and WHEN XXX.

--------------


