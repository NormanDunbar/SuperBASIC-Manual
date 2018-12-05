..  _minimum-pct:

MINIMUM%
========

+----------+------------------------------------------------------------------+
| Syntax   | MINIMUM% [ ( array% ) ] or                                       |
|          |                                                                  |
|          | MINIMUM% ( :sup:`\*`\ [ value ]\ :sup:`\*` )                     |
+----------+------------------------------------------------------------------+
| Location | Minmax (DIY Toolkit - Vol Z)                                     |
+----------+------------------------------------------------------------------+

This function is exactly the same as MINIMUM except that it only
accepts integer parameters and is therefore able to work much more
quickly. As with MINIMUM, you can use this function to find the smallest
value in an array, provided that the first variant is used, and the
array is a single dimensional integer array. If no parameter is
supplied, then the smallest possible integer number supported by the QL
is returned - this is equivalent to -32768.

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmin`, :ref:`minimum`
and :ref:`min` are similar. Refer also to
:ref:`maximum-pct`.

--------------


