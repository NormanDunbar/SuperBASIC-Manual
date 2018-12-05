..  _sinh:

SINH
====

+----------+-------------------------------------------------------------------+
| Syntax   |  SINH (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Hyper, Hyperbola                                                 |
+----------+-------------------------------------------------------------------+

This function returns the hyperbolic sine (sinus hyperbolicus). The
function is equivalent to: ( EXP(x) - EXP(-x) ) / 2
where the angle x (in fact a ratio) is a small floating point value.

**Example**

Draw a hyperbola and its asymptotes::

    100 SCALE 10, -7, -5: PAPER 0: CLS: INK 3
    110 LINE -4, -4 TO 4, 4, -4, 4 TO 4, -4: INK 7
    120 FOR t = -2 TO 2 STEP 2E-2
    130 x = COSH(t): y = SINH(t)
    140 POINT x, y, -x, y
    150 END FOR t

**CROSS-REFERENCE**

:ref:`cosh`, :ref:`tanh`,
:ref:`arsinh`

--------------


