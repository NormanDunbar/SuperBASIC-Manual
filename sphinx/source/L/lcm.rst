..  _lcm:

LCM
===

+----------+----------------------------------------------------------------------------------------------------------+
| Syntax   |  LCM (x\ :sup:`1`\ , x\ :sup:`2`\ , :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`) where x\ :sup:`i`\ =0..INTMAX  |
+----------+----------------------------------------------------------------------------------------------------------+
| Location |  Math Package                                                                                            |
+----------+----------------------------------------------------------------------------------------------------------+

LCM is a function which takes two or more numeric parameters and finds
their least common multiple, ie. the smallest number which can be
divided by all of the parameters without a remainder. The parameters
should be positive integers.

**Example**

::

    PRINT LCM (2,3,4)

returns 12 and indeed 12/2=6, 12/3=4 and 12/4=3.

**NOTE**

If you are not looking for the least common multiple but any common
multiple then simply multiply all the numbers, eg. 2\*3\*4=24.

**CROSS-REFERENCE**

:ref:`gcd`

--------------


