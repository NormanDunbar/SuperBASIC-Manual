..  _next:

NEXT
====

+----------+------------------------------------------------------------------+
| Syntax   | NEXT loop\_variable (inside FOR loops) or                        |
|          |                                                                  |
|          | NEXT loop\_name (inside REPeat loops) or                         |
|          |                                                                  |
|          | NEXT(SMS only)                                                   |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

This command forces the program to make the next pass in a loop
structure - the next command to be processed is the first after the
relevant FOR or REPeat instruction. NEXT can be used in both loop
structures, FOR and REPeat.

**NOTE**

If a FOR loop has already reached its last value, NEXT will have no
effect.

**SMS NOTE**

The loop\_name / loop\_variable do not need to be specified, in which
case NEXT merely makes the program make the next pass of the latest
defined FOR or REPeat loop. If NEXT does not appear within a loop
structure, the error 'unable to find an open loop' will be reported. If
however, NEXT is followed by a loop\_name or loop\_variable and that
does not correspond to a currently open loop, the error 'undefined loop
control variable' will be reported.

**CROSS-REFERENCE**

You must study :ref:`for` or
:ref:`repeat` before using
:ref:`next`. :ref:`exit` leaves a
loop.
