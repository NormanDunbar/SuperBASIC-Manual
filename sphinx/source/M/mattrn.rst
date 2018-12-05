..  _mattrn:

MATTRN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATTRN array1, array2                                            |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATTRN takes numeric arrays of two dimensions or string
arrays of three dimensions and reads each row of array2, placing it in
the corresponding column of array1.

It is obligatory that both arrays
have the same type and are exactly DIMed to the needs of MATTRN.

The
first dimension of array1 must be equal to the second of array2 and the
first dimension of array2 must be equal to the second of array1.

For
strings, additionally, the third dimensions of both arrays have to be
equal::

    DIM array1(x,y), array2(y,x)
    DIM array1%(x,y), array2%(y,x)
    DIM array1$(x,y,z), array2$(y,x,z)

So array1 and array2 can only be of identical dimensions for square
matrices. In all other cases the contents of array1 are not modified.

**Example**

::

    100 DIM A%(2,3), B%(3,2)
    110 MATRND B%,9: PRINT B%!\
    120 MATTRN A%,B%: PRINT A%!\
    130 MATTRN B%,A%: PRINT B%!\

--------------


