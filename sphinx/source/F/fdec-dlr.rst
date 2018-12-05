..  _fdec-dlr:

FDEC$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FDEC$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function is similar to CDEC$ except for two major differences.
FDEC$ does not assume that value is an integer, and therefore uses the
whole of value, although if the given ndp (number of decimal places) is less than
the number of decimal places in
value, value will be rounded up or down accordingly.

FDEC$ does not
insert commas in the characters to the left of the decimal point.

**Examples**

::

    PRINT FDEC$(100.235,6,2)

will print '100.24'

::

    PRINT FDEC$(100,6,2)

will print '100.00'

**CROSS-REFERENCE**

Please see :ref:`cdec-dlr`.

--------------


