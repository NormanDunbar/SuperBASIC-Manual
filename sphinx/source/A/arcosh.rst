..  _arcosh:

ARCOSH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ARCOSH (x)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

This function returns the arc hyperbolic cosine of the specified value,
that is to say it will return the value which must be passed to the
hyperbolic cosine to return the given result, so::

    COSH ( ARCOSH ( x )) = x

The ARCOSH function can be expressed as a combination of SuperBASIC
keywords: it's the same as::

    LN(x + SQRT(x*x-1)).

**CROSS-REFERENCE**

See :ref:`acos`, :ref:`asin`,
:ref:`acot`, :ref:`atan`,
:ref:`cosh`, :ref:`arcoth`,
:ref:`arsinh` and
:ref:`artanh`.

--------------


