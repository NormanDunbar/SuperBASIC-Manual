..  _atan:

ATAN
====

+----------+------------------------------------------------------------------+
| Syntax   | ATAN (x)  or                                                     |
|          |                                                                  |
|          | ATAN (x,y) (Minerva and SMS only)                                |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

The function ATAN, is the arc-tangent function, that is to say the
inverse of the tangent function (TAN in SuperBASIC).

TAN ( ATAN ( x )) = x

for all values of x, but due to the fact that TAN works on periods; ATAN
( TAN ( x )) = x

is only true for where: -PI/2 < x < PI/2.

A negative angle indicates that the hypotenuse appears below the base
line of the triangle, and it is therefore important to bear in mind the
orientation of the screen when using this command.

**NOTE 1**

Because trigonometrical functions are calculated using polynomial
approximations, large parameters can produce small errors.

For example, on all implementations:

PRINT TAN (ATAN ( 123456 ))

gives 123461.2 instead of 123456.

The maximum error rises in direct proportion to the parameter for the
above example.

**NOTE 2**

There is a very obscure bug contained in the code for ATAN which means
that the command may crash on non-Minerva ROMs if used in a program
which is longer than 32K.

**MINERVA NOTE**

ATAN can accept two parameters. If you specify two parameters then
ATAN(x,y) will give the angle from the origin to the point (x,y). This
is actually the same as ATAN(y/x), although it does also cater for when
x=0 which would otherwise give an overflow error.

This variant also supports a full circle, for example the following can
be used to calculate the bearing travelled (with 0 degrees being north),
given that you have moved x miles east (or west if x<0) and y miles
north (or south if y<0):

::

    100 DEFine PROCedure BEARING (x,y)
    110 direction=DEG (ATAN (y,x))
    120 IF x>=0: RETurn direction: ELSE RETurn 360+direction
    130 END DEFine

The need for line 120 is because the value returned by ATAN is in the
range -PI ... PI (which converts to -180 ... +180 degrees) - the value
returned needs to be in the range 0 ... 360. Note that x and y are
swapped around in line 110 - this is to circumvent the problem that a
bearing of 0 is north, whereas in the mathematical functions, a zero is
taken to be horizontal.

**SMS NOTE**

The ATAN function has been extended to be the same as on Minerva,
although the range of values it returns have been made into four
quadrant results (as with ATN2 ), so that for ATAN(x,y) if x>0, the
result is now in the range -PI/2...PI/2 instead of the usual 0...PI.

**CROSS-REFERENCE**

:ref:`tan`, :ref:`atn`,
:ref:`atn2` and :ref:`artanh`.
Also please refer to the Mathematics section in the Appendix.

--------------


