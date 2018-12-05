..  _asin:

ASIN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ASIN (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function calculates the arc-sine (in radians) which is the opposite
of the sine function, ie:

x = SIN ( ASIN ( x )) = ASIN ( SIN ( x ))

The only valid values of x are in the range -1...1. This means that the
range of angles supported by this command are -PI/2...PI/2. A negative
angle means that the hypotenuse appears below the base line of the
triangle (you must therefore always bear the orientation of the screen
in mind when using this command).

**Example**

Given that there are two points on the screen at (10,20) and (100,75),
find the angle of the line between those two points (from the
horizontal):

::

    100 PRINT CALC_ANGLE(10,20 TO 100,75)
    110 STOP
    120 :
    200 DEFine FuNction CALC_ANGLE(x1,y1,x2,y2)
    210  LOCal Distan, Radian_angle
    220  Distan = SQRT((x2-x1)^2 + (y2-y1)^2)
    230  Radian_angle = ASIN((y2-y1) / Distan)
    240  RETurn DEG(Radian_angle)
    250 END DEFine

**MINERVA NOTE**

On a Minerva you can replace line 220 with: 220 Distan =
ABS(x2-x1,y2-y1)

**CROSS-REFERENCE**

:ref:`acos`, :ref:`atan`,
:ref:`acot` are other arc functions,
:ref:`sin`, :ref:`cos`,
:ref:`tan` and :ref:`cot`\ their
relatives.

Please also see the Mathematics section of the Appendix.

Compare :ref:`arsinh`.

--------------


