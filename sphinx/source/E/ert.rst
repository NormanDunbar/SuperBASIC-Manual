..  _ert:

ERT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ERT function                                                     |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

Normally, whenever you use a function (or anything else which may return an error
code), you will need to assign the result of the function (or whatever else) to a
variable and then test that variable in order to see whether or not an error has
been generated.

If an error has been generated, you will then need to report the
error (if you do not intend to take any action to try and rectify the situation),
something which can take a lot of program space, if you intend to write a program
which does not require the command REPort to be present.

The command ERT was
introduced in the Hotkey System II to enable you to write programs which test the
result for an error code and report the error all in one step.

**Example 1**

A simple program which provides its own error trapping::

    100 PAPER 0:INK 7
    110 REPeat loop
    120 CLS
    130 AT 0,0:PRINT 'Enter an integer (0 to 300): ';
    140 xerr=GET_INT
    150 IF xerr<0:PRINT 'Error - try again':ELSE x=xerr:EXIT loop
    160 PAUSE
    170 END REPeat loop
    180 PRINT 'The integer was : ';x
    185 :
    190 DEFine FuNction GET_INT
    200   valid$='0123456789'
    210   INPUT a$:IF a$='':RETurn -1
    220   FOR i=1 TO LEN(a$):IF a$(i) INSTR valid$=0:RETurn -17
    230   IF a$>300:RETurn -4
    240   RETurn a$
    250 END DEFine


**Example 2**

A similar program which is designed to stop on an error::

    100 PAPER 0:INK 7
    110 CLS
    120 AT 0,0:PRINT 'Enter an integer (0 to 300): ';
    130 xerr=GET_INT
    140 IF xerr<0:REPORT xerr:STOP:ELSE x=xerr
    150 PRINT 'The integer was : ';x
    155 :
    160 DEFine FuNction GET_INT
    170   valid$='0123456789'
    180   INPUT a$:IF a$='':RETurn -1
    190   FOR i=1 TO LEN(a$):IF a$(i) INSTR valid$=0:RETurn -17
    200   IF a$>300:RETurn -4
    210   RETurn a$
    220 END DEFine

**Example 3**


The same program as in the second example, but using ERT::

    100 PAPER 0:INK 7
    110 CLS
    120 AT 0,0:PRINT 'Enter an integer (0 to 300): ';
    130 ERT GET_INT
    140 PRINT 'The integer was : ';x
    150 DEFine FuNction GET_INT
    160   valid$='0123456789'
    170   INPUT a$:IF a$='':RETurn -1
    180   FOR i=1 TO LEN(a$):IF a$(i) INSTR valid$=0:RETurn -17
    190   IF a$>300:RETurn -4
    200   x=a$
    210   RETurn x
    220 END DEFine

**NOTE**

When you are using ERT, always beware of what you are testing for an
error, for example, if you had altered line 130 in the second example
to::

    130 ERT x=GET_INT

you would not actually be testing to see whether the function GET\_INT
returned an error, but whether the line x=GET\_INT produced an error - x
itself would not be altered, hence the need to assign the result to x
inside the function.

**CROSS-REFERENCE**

:ref:`report` will report an error without stopping
the program.

