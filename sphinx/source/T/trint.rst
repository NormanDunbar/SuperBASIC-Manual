..  _trint:

TRINT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TRINT (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  TRIPRODRO                                                        |
+----------+-------------------------------------------------------------------+

The function TRINT gives the integer part of a floating point number,
it differs from INT for negative numbers only: INT always returns the
next lowest integer, this is the same as the integer part for positive
numbers; however below zero INT
always returns one less than TRINT. For example::

    INT(-PI)

will return -4 and::

    TRINT(-PI)

will return -3.

**CROSS-REFERENCE**

The fact that::

    x = TRINT(x) + FRACT(x)

can be exploited to substitute one of the two functions by the other, for
example::

    100 DEFine FuNction MYTRINT(x)
    110   RETurn x - FRACT(x)
    120 END DEFine MYTRINT

If you want to round numbers, refer to
:ref:`dround` and
:ref:`pround`.

--------------


