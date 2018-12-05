..  _matadd:

MATADD
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATADD sum,matrix1,matrix2                                       |
+----------+-------------------------------------------------------------------+
| Location |  Math package                                                     |
+----------+-------------------------------------------------------------------+

The command MATADD adds the two matrices contained in the arrays
matrix1 and matrix2, setting the result in the array sum. The
parameters, matrix1, matrix2 and sum, must all be arrays of the same
dimensions, the same size and the same type. They can be of any number
type, viz. floating point or integer (% suffix), but not string and (we
must stress this point) floating point and integer arguments must not be
mixed. If these conditions are not satisfied, then MATADD will break
with a 'bad parameter' error (-15). Provided that the parameters follow
this rule, the command MATADD sets all of the elements of the sum array
to the sum of the respective elements of the two other arrays, matrix1
and matrix2.

**Example**

::

    100 DIM a%(10,10,80), b%(10,10,80), c%(10,10,80)
    110 MATRND a%,-5 TO 5: MATSEQ b%
    120 MATADD c%,a%,b%

**CROSS-REFERENCE**

If you run this short example program (8000 internal loops!), you will
notice the extraordinary speed of :ref:`matadd`
which is representative of the other MAT...
functions; :ref:`matsub` is almost equivalent to
:ref:`matadd`.

--------------


