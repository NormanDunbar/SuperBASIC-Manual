..  _end--define:

END DEFine
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  END DEFine [name]                                                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the DEFine PROCedure and DEFine FuNction SuperBASIC
structures, and has no meaning on its own. You may if you wish, place the name of
the PROCedure or FuNction  after END DEFine to help make the SuperBASIC program
more readable - this will however have no effect on how the command is treated
by the interpreter, which will still take the next END DEFine as the end of the
current definition block (even if it is followed by a different name).

The interpreter will jump out of a definition block whenever it meets a RETurn
statement. It will also jump out of a DEFine PROCedure definition when it meets
an END DEFine statement. This does of course mean that END DEFine can be used in
the middle of a PROCedure to force a return to the calling statement - however,
this can cause other problems and a RETurn should be used, with END DEFine
only appearing at the very end of the definition block.

On the other hand, the interpreter can only jump out of a DEFine FuNction definition
if it meets a RETurn - if the interpreter comes across an END DEFine in such situations,
it will report the error 'Error In Expression'. On SMS the error 'RETurn not in
Procedure or Function' is reported. If the definition block is not actually being used,
but the interpreter is working its way through the program, when a DEFine PROCedure
or DEFine FuNction statement is met, the interpreter will search for the next END DEFine,
and having found one, will resume the program at the next statement.

This does however mean, that unless an in-line DEFine structure is being used, if
this command is missing, the interpreter will carry on searching through the program
and may just stop without an error if END DEFine does not appear anywhere in the
program after the initial DEFine PROCedure (or DEFine FuNction).

**Example 1**

The above rules mean that the following example will work under
SuperBASIC, but is extremely inefficient and difficult to decode::

    10 FOR i=1 TO 100
    20   PRINT power(i)
    30   DEFine FuNction power(x)
    40     RETurn 2^x
    50   END DEFine
    60 END FOR i

**Example 2**

See if you can work out why the following program goes wrong::

    100 FOR i=1 TO 100
    110   PRINT power(i)
    120   DEFine FuNction power(x)
    130     DEFine FuNction base
    140       RETurn 2
    150     END DEFine base
    160     RETurn base^x
    170   END DEFine power
    180 END FOR i

If you are having trouble, try inserting::

    155 PRINT 'Program line 155:';x

**NOTE**

END DEFine need not appear in an in-line definition statement, except
under SMS.

**SMS NOTE**

Checks are made on a program before it is run, and so if an END DEFine
statement is missing, this will be reported as an error ('Incomplete
DEFine clause'). SMS's improved interpreter will report the error
'Misplaced END DEFine' if END DEFine does not mark the end of a DEFine
PROCedure or DEFine FuNction block.

**CROSS-REFERENCE**

Please see :ref:`define--procedure` and
:ref:`define--function`. Other SuperBASIC
structures are :ref:`select--on`,
:ref:`if`, :ref:`repeat`,
WHEN XXX and :ref:`for`.

