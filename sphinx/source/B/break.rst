..  _break:

BREAK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BREAK switch                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The command BREAK takes the parameter of either ON (=1) or OFF (=0) and
enables or disables the ability to stop a program with the Break key
<CTRL><SPACE> (and <ESC> on Minerva) accordingly.


**Example**

::

    100 WINDOW 136,100,100,40: INK 7
    110 BORDER 1,4,3: PAPER 3,0: CLS
    120 SCALE 100,-50,-50: POINT 0,0
    130 fast=ASK( "Fast (y/n)" ): CLS
    140 BREAK fast
    150 FOR n=0 TO 4000
    160   IF BREAK% THEN AT 0,0: PRINT n
    170   x=RND(-50 TO 50): y=RND(-50 TO 50)
    180   z=SIN(PI*SQRT(x*x+y*y)/10)+1
    190   IF z > 2*RND THEN POINT x,y
    200 END FOR n
    210 BREAK ON


**NOTE 1**

After the Break key has been disabled and re-enabled, if you try to
Break from the interpreter's command window #0 it might be disturbed.
Instead of printing 'not complete' (error -1) in #0 when <CTRL><SPACE>
is pressed, that message may appear in #2 and Break will work only once,
the interpreter will not accept any further Breaks... A single <ENTER>
after you initially press the Break key cures this.


**NOTE 2**

This command does not work under SMS.


**CROSS-REFERENCE**

See also :ref:`break-pct`,
:ref:`freeze` and
:ref:`freeze-pct`.

Do not confuse BTool's command :ref:`break` with
TinyToolkit's function :ref:`break` (although you
can use both in the same program!)

--------------


