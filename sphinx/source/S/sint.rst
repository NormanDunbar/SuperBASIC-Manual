..  _sint:

SINT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  SINT (x) where x=0..65535                                        |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The range of SuperBASIC integers is -32768 to 32767 - these are called
signed integers because they can be negative. This compares to unsigned
integers which have a different range, from 0 to 65535. The function
SINT converts unsigned integers to signed integers, which is not a very
difficult task apart from the need to check the valid range::

    signed% = unsigned - 2^16

or::

    signed% = SINT(unsigned)

**CROSS-REFERENCE**

:ref:`uint` converts in the other direction.

--------------


