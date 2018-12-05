..  _maximum-pct:

MAXIMUM%
========

+----------+------------------------------------------------------------------+
| Syntax   | MAXIMUM% [ ( array% ) ] or                                       |
|          |                                                                  |
|          | MAXIMUM% ( :sup:`\*`\ [ value ]\ :sup:`\*` )                     |
+----------+------------------------------------------------------------------+
| Location | Minmax (DIY Toolkit - Vol Z)                                     |
+----------+------------------------------------------------------------------+

This function is exactly the same as MAXIMUM except that it only
accepts integer parameters and is therefore able to work much more
quickly. As with MAXIMUM, you can use this function to find the highest
value in an array, provided that the first variant is used, and the
array is a single dimensional integer array. If no parameter is
supplied, then the greatest possible integer number supported by the QL
is returned - this is equivalent to 32767.

**Example**

::

    PRINT MAXIMUM%

Returns 32767

::

    DIM x%(3): x%(0)=10: x%(1)=200: x%(2)=2: x%(3)=50
    PRINT MAXIMUM% (x%)

Returns 200.

::

    PRINT MAXIMUM% (100, ax ,21*10+ac)

Returns the highest value as an integer.

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmax`, :ref:`maximum`
and :ref:`max` are similar. Refer also to
:ref:`minimum-pct`.

--------------


