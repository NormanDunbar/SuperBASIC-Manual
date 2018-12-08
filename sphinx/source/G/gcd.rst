..  _gcd:

GCD
===

+----------+---------------------------------------------------------------------------------------------------------+
| Syntax   |  GCD (x\ :sup:`1`\ , x\ :sup:`2` :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`\ ) Where x\ :sup:`i`\ =0..INTMAX  |
+----------+---------------------------------------------------------------------------------------------------------+
| Location |  Math Package                                                                                           |
+----------+---------------------------------------------------------------------------------------------------------+

The function GCD takes two or more positive integers and finds their
greatest common denominator, ie. the largest number by which all of the
given parameters can be divided without remainder. There is always such
a number because 1 (the smallest common denominator) divides every
number without remainder. GCD converts all passed values into integers
by removing any decimal places (as with :ref:`int`) before looking for the
denominator.

**CROSS-REFERENCE**

:ref:`lcm`

