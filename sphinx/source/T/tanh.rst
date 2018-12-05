..  _tanh:

TANH
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TANH (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Hyper, Hyperbola                                                 |
+----------+-------------------------------------------------------------------+

This function is analogous to the tangent (TAN) - the hyperbolic
tangent (TANH) is the hyperbolic sine divided by the hyperbolic cosine::

    TANH(x) = SINH(x) / COSH(x)

resulting in the following formula (if SINH and COSH are replaced by
their definitions)::

    TANH(x) = (EXP(x) - EXP(-x)) / (EXP(x) + EXP(-x))

**CROSS-REFERENCE**

:ref:`artanh` is the inverse function of
:ref:`tanh`, :ref:`coth` a
complementary function to :ref:`tanh`.

--------------


