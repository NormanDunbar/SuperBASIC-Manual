..  _pround:

PROUND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PROUND (p, x)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  TRIPRODRO                                                        |
+----------+-------------------------------------------------------------------+

PROUND is a function which rounds the given floating pointer number x
to the precision of 10\ :sup:`p`. It looks at the next digit to decide
whether to round upwards or downwards and ignores any others.

**Example**

Print ten random number with three digits after the decimal point::

    100 RANDOMISE
    110 FOR i = 1 TO 10
    120 PRINT PROUND(-3, 10*RND)
    130 END FOR i

**CROSS-REFERENCE**

:ref:`dround`\ .

--------------


