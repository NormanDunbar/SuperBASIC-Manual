..  _acot:

ACOT
====

+----------+------------------------------------------------------------------+
| Syntax   | ACOT (x) or                                                      |
|          |                                                                  |
|          | ACOT (y,x) (Minerva v1.90+ only)                                 |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

The function ACOT, is the arc-cotangent function, that is to say the
inverse of the cotangent function (COT in SuperBASIC): COT(ACOT(x))=x
for all values of x, but due to the periodic nature of COT,
ACOT(COT(x))=x is only true for where: 0<x<PI.

Note that if a negative value of x is provided, the angle returned will
be the obtuse angle (ie. greater than 90 degrees).

**MINERVA NOTE**

ACOT can accept two parameters. If you specify two parameters then
ACOT(y,x) will give the angle from the origin to the point (x,y). This
is actually the same as ACOT(x/y) although it does also cater for when
y=0 which would otherwise give an overflow error.

**CROSS-REFERENCE**

:ref:`cot`, :ref:`atan`,
:ref:`tan`.

Please see the Mathematics section in the Appendix.

See also :ref:`arcoth`.

--------------


