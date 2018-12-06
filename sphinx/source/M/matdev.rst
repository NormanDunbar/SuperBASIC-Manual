..  _matdev:

MATDEV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATDEV array[%]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function takes any numeric array and calculates a number from its
values which gives information about their standard deviation.

**Example**

::

    10 DIM x(10)
    20 PRINT MATDEV (x)

gives 0 because all elements of x are equal and therefore, have no deviation. Add
the line::

    15 MATRND x,10

and the result will be be around 3.2.

**CROSS-REFERENCE**

:ref:`matmean`

