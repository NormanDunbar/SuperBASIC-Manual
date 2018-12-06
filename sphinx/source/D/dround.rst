..  _dround:

DROUND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DROUND (d, x)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  TRIPRODRO                                                        |
+----------+-------------------------------------------------------------------+

The function DROUND will return the floating point number x
rounded to d decimal digits, counted from the left of the number.
DROUND rounds the last digit up or down depending on the next digit
(ignoring any others).


**Example**

::

    DROUND(3, 1234.56) = 1230
    DROUND(4, 1234.56) = 1235


**CROSS-REFERENCE**

:ref:`pround` rounds to a given precision.

