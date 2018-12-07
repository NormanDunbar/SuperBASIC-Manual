..  _sin:

SIN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  SIN (angle)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the sine of the given angle (in radians ranging
from -PI/2 to PI/2). In a right-angled triangle, the sine is the ratio
of the length of the side opposite to the angle, to the length of the
hypotenuse. A negative angle indicates that the hypotenuse appears below
the base line.

**Example**

A procedure to draw a sector of a circle with the centre at x,y and
radius r.

- A is the angle between the first straight side of the sector and a vertical line on the screen,
- B is the angle between the two straight sides.
- Both angles have to be given in radians, b should be between 0 and 2\*PI.
- Ch specifies the window to be used and cannot be omitted.

::

    100 DEFine PROCedure SECTOR (ch, x, y, r, a, b)
    110   LOCal x1, x2, y1, y2
    120   x1 = x + r * SIN(a): x2 = x + r *SIN(a + b)
    130   y1 = y + r * COS(a): y2 = y + r *COS(a + b)
    140   LINE# ch, x1, y1 TO x, y TO x2, y2
    150   ARC# ch, x2, y2 TO x1, y1 ,b
    160 END DEFine SECTOR

    SECTOR #1, 50, 50, 10, PI/4, PI/2

**NOTE 1**

SIN (PI)==0 (approximately zero) on all ROMs. This should in fact equal zero - only the
Lightning maths package and SMS get this right.

**NOTE 2**

On Minerva v1.96+ SIN with very large values for radian return 0. On
other implementations it returns an overflow error. You should therefore
check the range of the angle parameter.

**CROSS-REFERENCE**

See :ref:`cos`, :ref:`tan`,
:ref:`rad`, :ref:`asin`,
:ref:`acos`, :ref:`atan`,
:ref:`deg`. See also :ref:`sinh`.
Please also refer to the Mathematics section of the Appendix.

