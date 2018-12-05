..  _matseq:

MATSEQ
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATSEQ array                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATSEQ initialises the array (which must be a numeric
array) with a constantly increasing set of integer numbers: 1 2 3 4 5
6...

There is not really much use for MATSEQ except for demonstration.

Array can be either a floating point or integer variable. No strings are allowed.

**CROSS-REFERENCE**

:ref:`matidn` is a useful means of initialising an
array, :ref:`matequ` can be used to set all
elements of an array to a certain value. It is worth noting that any
square matrix created with :ref:`matseq` cannot be
inverted with :ref:`matinv` because the determinant
:ref:`det` of that matrix is always zero::

    100 n=30: DIM m(n,n), minv(n,n)
    110 MATSEQ m
    120 MATINV minv,m

This always fails at line 120 because :ref:`det`\ (m) = 0.

--------------


