..  _log10:

LOG10
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LOG10 (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function LOG10 calculates the logarithm to the base 10 of the given
number. For the non-mathematicians out there: x=10\ :sup:`LOG10(x)`.

**Examples**

::

    100 INPUT "Integer Number:"!x
    110 PRINT "This number has"!INT(1+LOG10(ABS(x)))!"digits."

The trivial function LOGN finds the logarithm of x to any base b which
makes sense::

    10 DEFine FuNction LOGN (x,b)
    20   RETurn LN(x)/LN(b)
    30 END DEFine LOGN

**CROSS-REFERENCE**

:ref:`ln`, :ref:`log2`.

