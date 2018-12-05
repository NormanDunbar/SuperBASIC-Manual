..  _matidn:

MATIDN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATIDN matrix                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This command forces the square numeric array matrix to be initialised
so that the matrix is given the algebraic identity for matrices of that
size. This gives the matrix the following format::

    1 0 0 . . . 0 0 0
    0 1 0 . . . 0 0 0
    0 0 1 . . . 0 0 0
    . . .       . . .
    . . .       . . .
    . . .       . . .
    0 0 0 . . . 1 0 0
    0 0 0 . . . 0 1 0
    0 0 0 . . . 0 0 1


All elements on the
diagonal line from the top left corner to the bottom right corner are
set to 1 and all other elements are set to 0. This forms the identity
matrix, which means that when a matrix of the same size is multiplied by
this, the resultant matrix is the same as the original matrix, ie.
matrix1 \* matrix = matrix1.

**CROSS-REFERENCE**

:ref:`matmult` multiplies matrices.

--------------


