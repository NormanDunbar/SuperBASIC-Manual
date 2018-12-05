..  _repeat:

REPeat
======

+----------+------------------------------------------------------------------+
| Syntax   | REPeat identifier  or                                            |
|          |                                                                  |
|          | REPeat [identifier](SMS only)                                    |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

The SuperBASIC REPeat loop is extremely flexible and provides an
alternative to the classic FOR loop.

It sets up a perpetual loop which
can only be ended (correctly) by means of the EXIT
command. The syntax of this SuperBASIC structure can take two forms:

REPeat identifier :statement :sup:`\*`\ [:statement]\ :sup:`\*`

or:

REPeat identifier :sup:`\*`\ [statements]\ :sup:`\*` ... [EXIT identifier] [NEXT identifier] ... END REPeat identifier

The first of these variants is known as an in-line REPeat loop. Provided that there is at least one statement following REPeat,
this line will be repeated forever (unless there is an EXIT statement -
see below). There is no need for a related END REPeat statement and therefore the shortest (practicable) in-line
REPeat loop possible is::

    REPeat loop: IF INKEY$=' ' THEN EXIT loop

If an in-line loop is terminated with EXIT, control will be passed to
the statement following the corresponding END REPeat
statement (if one exists), or the next program line. This allows the
following::

    REPeat loop: IF INKEY$=' ':EXIT loop: END REPeat loop: PRINT 'Phew!'

EXIT is used (in both REPeat loops and FOR loops) to terminate the
loop, and the next statement which will be processed is the first
statement after the corresponding END REPeat (if one exists).

NEXT forces the program to make another pass of the loop, returning program
control to the statement following REPeat.

**Example**

A short FuNction which waits for a key to be pressed which can be <ESC>
or any key listed in a string passed as the parameter, and returns the
CODE of the key pressed::

    100 DEFine FuNction Getkey(key$)
    105   LOCal loop,k$
    110   REPeat loop
    120     k$=INKEY$:IF k$='':NEXT loop
    130     IF k$ INSTR key$&CHR$(27):RETurn CODE(k$)
    140   END REPeat loop
    150 END DEFine

**NOTE 1**

The loop identifier must be a floating-point, except under Minerva or
SMS. However, if the loop identifier is also used as a variable in the
program, its value will not be altered by the REPeat / END REPeat / EXIT
/ NEXT statements. It can therefore still be used as a variable within
the loop without any problems.

**NOTE 2**

It is actually possible to force a NEXT loop from outside of the loop,
for example in a program such as::

    100 REPeat Getkey
    110   AT 0,0:PRINT 'Looping'
    120   a$=INKEY$:IF a$='':NEXT Getkey
    130   PRINT a$
    140   IF a$=='x':EXIT Getkey
    150 END REPeat Getkey
    155 :
    160 PRINT 'You have decided to leave the loop'
    170 PRINT 'Press a key to return to it'
    180 PAUSE
    190 CLS
    195 :
    200 NEXT Getkey


This is however very bad programming style and should be avoided. It
makes it very difficult to follow programs and no SuperBASIC compilers
would be able to make sense of it. The above program should be
re-written::

    100 REPeat Getkey
    110   AT 0,0:PRINT 'Looping'
    120   a$=INKEY$:IF a$='':NEXT Getkey
    130   PRINT a$
    140   IF a$=='x'
    150     PRINT 'You are now still in the loop'
    160     PRINT 'Press a key to restart it'
    170     PAUSE
    180     CLS
    190   END IF
    200 END REPeat Getkey


**MINERVA NOTES**

This allows string REPeat loops and integer REPeat loops, although the
use of the former is dubious. You can of course still use the
identifiers within the loop as variables. Integer REPeat loops do not
seem to be any quicker than floating point loops.

If you do use a string identifier, Minerva restricts such strings to a maximum of four
characters. If the string identifier is defined as a variable
beforehand, it will be truncated if necessary - for example, try::


    a$='Hello World': REPeat a$: PRINT a$ and a$='': REPeat a$: a$ = a$ & 'x': PRINT a$

String and integer REPeat loops will not safely work on other ROMs
(except under SMS), even if they will let you type them in!

**SMS NOTES**

Like Minerva, SMS allows string REPeat loops and integer REPeat
loops. However, SMS does not restrict the length of a string loop
identifier (except to the normal string length limit of 32767
characters). SMS also allows you to omit the loop identifier, in which
case the relative EXIT, NEXT and END REPeat statements must also omit
the loop identifier. This flexibility brings this command more in line
with other implementations of BASIC. Error trapping of incorrectly
structured REPeat loops is also improved - please refer to NEXT and END
REPeat.

**CROSS-REFERENCE**

:ref:`for`...\ :ref:`end--for`
is the other loop type.

--------------


