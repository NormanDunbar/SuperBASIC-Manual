..  _if:

IF
==

+----------+-------------------------------------------------------------------+
| Syntax   |  IF condition .....                                               |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is used to mark the start of yet another powerful
SuperBASIC structure which allows a program to perform various functions
dependent upon the status of a condition. The condition will always be
interpreted as having either the value 1 (true) or 0 (false), using
boolean logic if necessary. Such conditions may be simple, such as x=2
or complex, as in x=3 AND (y=1 OR y=2).

There are actually two forms of
the SuperBASIC structure:

IF condition {THEN \| :} statement :sup:`\*`\ [:statement]\ :sup:`\*` [:ELSE statement :sup:`\*`\ [:statement]\ :sup:`\*`]

or

IF condition [{THEN \| :}] :sup:`\*`\ [:statement]\ :sup:`\*` ... [ELSE] :sup:`\*`\ [:statement]\ :sup:`\*` ... END IF

The first syntax represents in-line code, and the keyword THEN can
either appear or be replaced by a colon (:). If the condition is true,
the statements following THEN (or :) are executed, until the end of the line is
reached. There is actually no need for a colon after THEN, for example
the following are all the same::

    IF x=1 : PRINT 'x is 1'
    IF x=1 THEN PRINT 'x is 1'
    IF x=1 THEN:PRINT 'x is 1'

If during processing of the statements following THEN, a corresponding
ELSE keyword is found, the interpreter will search the line for the
corresponding END IF, in which case control will jump to the statement
following the END IF. If however, the line does not contain a
corresponding END IF, as with all other types on in-line code, control
will jump to the next program line.

On the other hand, if the condition
is false, the interpreter will search the line for the corresponding
ELSE, which, if found, will force control to jump to the first statement
following ELSE. Control then just continues along the program line and
to the next program line. Note that a colon must appear before the word
ELSE, and although not strictly necessary after the word ELSE, it is
advisable to place a colon after the ELSE keyword (see the Note below).

If ELSE does not appear, control is passed to the statement following
the corresponding END IF, or if not present, the next program line.

The second syntax represents the much more flexible long-form of the IF..END
IF statement. On the first line containing the IF condition, the keyword
THEN may be replaced by a colon, or even omitted altogether. If the
condition is true, control is passed to the next program line. If during
interpretation, an ELSE statement is found, the interpreter searches for
the corresponding END IF and passes control to the statement following
this.

If the condition is false, the interpreter once again searches for
a corresponding ELSE. If this is not present, then control is passed to
the next statement after the corresponding END IF. If on the other hand,
ELSE is present, control passes to the statement following ELSE (which
may be on the same line as the ELSE keyword). There is no need to follow
ELSE by a colon in this long form.

**Example 1**

A short program to move a cross around the screen, using the keys
<N>orth, <S>outh, <E>ast and <W>est, press <ESC> to leave program::

    100 WINDOW 448,200,32,16:PAPER 0:CLS
    110 x=224:y=100:OVER 0:INK 7
    120 CURSOR x,y:PRINT 'X':OVER -1
    130 REPeat loop
    140 dir$=INKEY$(-1)
    150 old_x=x:old_y=y
    160 IF dir$ INSTR 'nesw'
    170 IF dir$=='n':IF y>0:y=y-1
    180 IF dir$=='s' AND y<200-10:y=y+1
    190 IF dir$=='e':IF x<448-6:x=x+1
    200 IF dir$=='w' AND x>0:x=x-1
    210 ELSE IF dir$=CHR$(27):EXIT loop:ELSE NEXT loop
    220 END IF
    230 CURSOR old_x,old_y:PRINT 'X'
    240 CURSOR x,y:PRINT 'X'
    250 END REPeat loop
    260 OVER 0

Notice the use of both AND logic operators and second IF
statements (these can be swapped around). Placing the check for the
keys <N>, <E>, <S> and <W> within another IF
statement increases the speed of this routine, as the four statements
in lines 170 to 200 do not need to be processed if another key is
pressed.

**Example 2**

The whole program can be simplified a little by using boolean logic, by
replacing lines 170 to 200 with the following::

    170 IF dir$=='n':y=y-(y>0)
    180 IF dir$=='s':y=y+(y<200-10)
    190 IF dir$=='e':x=x+(x<448-6)
    200 IF dir$=='w':x=x-(x>0)

This is about 2.5% quicker than the first example.

**Example 3**

On a Minerva ROM, the powerful and even quicker SELect ON statement
could be used to make things even easier to understand, by replacing
lines 160 to 220 with::

    160 SELect ON dir$
    170   ='n':y=y-(y>0)
    180   ='s':y=y+(y<200-10)
    190   ='e':x=x+(x<448-6)
    200   ='w':x=x-(x>0)
    210   =CHR$(27):EXIT loop
    215   =REMAINDER :NEXT loop
    220 END SELect

This is about 22.5% quicker than the first example. Don't worry that
the 'X' disappears in a band across the screen as it is being moved - as
soon as you take your finger off the button, you are okay! It is unknown
why this phenomenon occurs..

**NOTE 1**

On ROM versions earlier than Minerva v1.92 (unless you have SMS), when
using multiple in-line IF statements, you need to be very careful over
the use of ELSE and the colon ':'. Although the following two lines have
exactly the same effect::

    IF x=0 : PRINT 'HELLO' : ELSE PRINT 'Bye'
    IF x=0 : PRINT 'HELLO' : ELSE : PRINT 'Bye'

The following gives the interpreter problems::

    10 x=0
    20 PRINT x
    30 IF x=0 : PRINT 'HELLO' : ELSE IF x=2 : PRINT 'GOODBYE' : END IF : x=x+1
    40 x=x+2
    50 PRINT x

This should make x=2 at line 40, but in fact x=3.

This is because the
interpreter does not look for an END IF following the ELSE IF structure.

Compare this with what happens if line 30 is made to read::

    30 IF x=0 : PRINT 'HELLO' : ELSE : IF x=2 : PRINT 'GOODBYE' : END IF : x=x+1

This is actually a bug in the interpreter rather than a feature, as
adding more IF statements into line 30 would appear to rectify it! The
answer therefore is to ensure that a colon appears after every ELSE (or
compile the program).

**NOTE 2**

Another problem also exists with in-line IF...END IF
statements - in the following program, line 100 is called twice when
d=1 and only once if d<>1.

::

    2 IF d=1:PRINT 'd is 1':ELSE :PRINT 'd is not 1':END IF :PRINT 'A simple test':GO SUB 100
    3 STOP
    100 PRINT "Now this is peculiar!!":RETurn

The rule would appear to be that the first GOSUB/PROCedure call after
the END IF contained in an in-line IF...ELSE...END IF structure is
called twice PROVIDED that the fist condition of the IF..ELSE..END IF
statement is true. Both Minerva v1.93+ and SMS cure this. Otherwise, set
the IF..ELSE..END IF statement out over several lines.

**SMS NOTES**

The improved interpreter checks whether IF statements are valid
constructs before RUNning or SAVEing a program and will report one of
the following errors if there is a problem:

**Incomplete IF clause**

Normally appears where END IF has been omitted other than in the in-line
format.

**Misplaced END IF**

There is no matching IF ... clause

**Misplaced ELSE**

This error is normally reported if an ELSE statement has not been placed
inside an IF...END IF construct.

**CROSS-REFERENCE**

:ref:`select--on` provides a much quicker
(although less flexible) means of testing a variable. Other SuperBASIC
structures are :ref:`when--condition`,
:ref:`when--error`,
:ref:`define--procedure`,
:ref:`define--function`,
:ref:`repeat` and :ref:`for`.

