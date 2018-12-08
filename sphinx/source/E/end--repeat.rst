..  _end--repeat:

END REPeat
==========

+----------+------------------------------------------------------------------+
| Syntax   | END REPeat identifier  or                                        |
|          |                                                                  |
|          | END REPeat [identifier]SMS only                                  |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

This command marks the end of the REPeat...END REPeat SuperBASIC structure with
the same identifier, and has no meaning on its own.

When the interpreter meets this
statement, it then looks at the stack to see if a related REPeat command has already
been parsed. If not, then the error 'Not Found' will be reported, however, if such
a REPeat identifier has been parsed, the interpreter will force the program to loop
around and return control to the statement following REPeat.

Under SMS there is no
need to specify the identifier on the END REPeat statement, in which case, the
interpreter will presume that this is the end of the last REPeat loop to have been
encountered.

When an EXIT identifier is found, the interpreter will search for the
relative END REPeat identifier (or under SMS the next END REPeat  command), and if
found, will resume program flow at the next statement.

This does however mean, that
except under SMS, unless an in-line REPeat structure is being used, if this command
is missing, the interpreter will carry on searching through the program and may just
stop without an error if END REPeat identifier (or END REPeat under SMS) does not
appear anywhere in the program.

**NOTE**

END REPeat need not appear in an in-line REPeat statement.

**SMS NOTE**

SMS will report 'unable to find an open loop' if the interpreter comes
across an END REPeat command (without a loop identifier) without a
corresponding open REPeat loop. If the interpreter comes across an END
REPeat command (with a loop identifier) without a corresponding open
REPeat loop the error 'undefined loop control variable' is reported.

**CROSS-REFERENCE**

Please see :ref:`repeat`.

:ref:`next` loop\_variable is practically the same
although see :ref:`exit`. Other SuperBASIC structures
are: :ref:`define--procedure`,
:ref:`define--function`,
:ref:`select--on`,\ :ref:`if`,
:ref:`for`, and WHEN XXX.

