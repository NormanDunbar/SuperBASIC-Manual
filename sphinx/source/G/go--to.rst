..  _go--to:

GO TO
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  GO TO line\_number(GOTO is expanded to GO TO)                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The command GO TO behaves in a similar way to GO SUB in that it forces
program flow to jump to a different part of the program. It is not
possible to RETurn to the statement following GO TO, unless you use
another GO TO command. SuperBASIC allows much more elegant and powerful
structures which should be used.

**Example**

An extremely simple password check::

    10 INPUT Password$
    20 IF Password$=='QL lives' THEN GO TO 50
    30 PRINT 'Access DENIED'
    40 GO TO 10
    50 PRINT 'Access Granted'

 This would be much better if re-written::

    10 REPeat Pass_loop
    20   INPUT Password$
    30   IF Password$=='QL lives' THEN EXIT Pass_loop
    40   PRINT 'Access DENIED'
    50 END REPeat Pass_loop
    60 PRINT 'Access Granted'

**CROSS-REFERENCE**

Please read :ref:`go--sub` before you dare to try
:ref:`go--to`!

--------------


