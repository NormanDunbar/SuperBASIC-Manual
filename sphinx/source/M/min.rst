..  _min:

MIN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  MIN (x\ :sup:`1` :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`\ )         |
+----------+-------------------------------------------------------------------+
| Location |  Math Package, MINMAX2                                            |
+----------+-------------------------------------------------------------------+

This function must be given at least one number as a parameter - it
will then return the lowest value out of the given list of parameters.

**Example**

::

    100 INPUT "a ="!a
    110 INPUT "b ="!b
    120 FOR x=MIN(a,b) TO MAX(a,b): PRINT x

**CROSS-REFERENCE**

:ref:`max` is :ref:`min`'s
counterpart. Compare :ref:`minimum` and
:ref:`matmin`.

--------------


