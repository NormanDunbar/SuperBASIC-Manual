..  _ndim-pct:

NDIM%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  NDIM% (array)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  NDIM                                                             |
+----------+-------------------------------------------------------------------+

This function returns the number of dimensions of a given array. DIMmed
variables of any type (floating point, integer and string) are legal
parameters.

**Example**

::

    DIM test% (10,50,2)
    PRINT NDIM% (test%)

gives the answer 3.

**NOTE**

String arrays often have one more dimension than the number of elements
which they can hold. This extra dimension sets the maximum length of
each element, for example::

    DIM name$(100,20)

sets aside space in the array name$ for 100 strings, each of which can be a maximum of 20
characters long::

    PRINT NDIM%(name$) returns 2.

**CROSS-REFERENCE**

:ref:`dimn` finds the defined size of each dimension
and can be used to replace :ref:`ndim-pct`.
:ref:`dim` declares an array.
:ref:`ndim` is exactly the same as
:ref:`ndim-pct`.
