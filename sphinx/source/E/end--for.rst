..  _end--for:

END FOR
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  END FOR loop                                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the FOR..END FOR SuperBASIC structure with the same
loop name, and has no real meaning on its own. When the interpreter meets this
statement, it then looks at the stack to see if a related FOR command has already
been parsed.

If not, then the error 'Not Found' will be reported, however, if such a FOR loop
has been parsed, the interpreter will fetch the end parameter and if the loop is
not yet at this value, then step is added to loop and control returned to the
statement following FOR.

If however loop is already at the end value, control
passes to the statement following END FOR.

The second variant is only available
under SMS, where the interpreter presumes that if no loop name is specified, the
programmer means the interpreter to return control to the most recent FOR
statement (if the loop is not at its final value).

When an EXIT loop is found,
the interpreter will search for the relative END FOR loop, and if found, will
resume program flow at the next statement.

Under SMS, neither EXIT nor END FOR
need have a loop identifier, and therefore EXIT will simply cause the program
to jump to the statement after the next END FOR command (if no loop is
specified).

This does however mean, that except under SMS, unless an in-line
FOR structure is being used, if this command is missing, the interpreter will
carry on searching through the program and may just stop without an error if
END FOR loop does not appear anywhere in the program.

**NOTE**

END FOR need not appear in an in-line FOR statement.

**SMS NOTE**

SMS will report 'unable to find an open loop' if the interpreter comes
across an END FOR command (without a loop variable name) without a
corresponding open FOR loop. If the interpreter comes across an END FOR
command (with a loop variable name) without a corresponding open FOR
loop the error 'undefined loop control variable' is reported.

**CROSS-REFERENCE**

Please see :ref:`for`. Compare
:ref:`next` and :ref:`exit`. Other
SuperBASIC structures are: :ref:`define--procedure`, :ref:`define--function`,
:ref:`select--on`, :ref:`if`, :ref:`repeat`, and WHEN XXX.

