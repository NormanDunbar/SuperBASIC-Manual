..  _intmax:

INTMAX
======

+----------+-------------------------------------------------------------------+
| Syntax   |  INTMAX                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function INTMAX returns the constant 10737421823 = 2^30-1. Although
SuperBASIC's integers can only handle a maximum of 16 bits (resulting in
a range of 2\ :sup:`16` different values: -32768 to 32767), the QL can
internally, on a machine code level, happily handle larger integers.
Many keywords listed in this book actually make use of this possibility
and that explains their valid parameter range.

**NOTE**

An error in the Maths Package (up to v2.04) means that a line such as
PRINT 2^30-INTMAX will report an out of memory error. This is fixed in
later versions of the package.

**CROSS-REFERENCE**

:ref:`eps`\ (x) = 1  if and only if :ref:`abs`\ (x) = 2 \* INTMAX.

