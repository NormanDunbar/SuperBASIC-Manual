..  _sqrt:

SQRT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  SQRT (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the square root of the given parameter. The
opposite of this function is x^2. The given parameter can be zero or any
positive value.

**Example**

::

    PRINT SQRT(32768*2) will return 256.

**NOTE 1**

The version of SQRT implemented on Minerva v1.90 (or later) is the
fastest version of this command which we have seen anywhere!

**NOTE 2**

On Minerva pre v1.96::

    SQRT(4^x*(12^31))

was returning the negative square root. It now returns the positive square root.

**CROSS-REFERENCE**

:ref:`abs` will return the absolute value of the given
parameter.

--------------


