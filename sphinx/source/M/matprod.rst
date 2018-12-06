..  _matprod:

MATPROD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATPROD (array)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function MATPROD returns the product of the array's values, so
array is not allowed to be a string array.

**Example**

Can you see why MATPROD and FACT return the same number for every n?

::

    100 n=8: DIM a%(n)
    110 MATSEQ a%
    120 PRINT MATPROD(a%) ;" = ";
    130 PRINT FACT(n+1)

**NOTE**

MATPROD is not compatible with Turbo and Supercharge.

**CROSS-REFERENCE**

:ref:`matprod` is almost identical to
:ref:`matsum` except that it returns the product
rather than the elements' sum; so have a look at
:ref:`matsum` which is also more useful.

