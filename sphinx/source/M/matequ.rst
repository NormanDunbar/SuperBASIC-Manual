..  _matequ:

MATEQU
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATEQU array1, {array2 \| value}                                 |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATEQU sets up array1 in two different ways depending on
the type of the second parameter: (1) If another array array2 of the
same dimensions is supplied then each element of array1 is set to the
corresponding element of array2; or (2) If the second parameter is not
an array but a constant, variable or expression then each element of
array1 is set to the given value. Array1, array2 and value can be of any
type: integer, floating point or string. array1 and array2 must however
be of the same type and have the same number of dimensions.

**Examples**

::

    DIM a$(4,8), a%(2,2,2,2,2), a(0), b$(4,8)
    MATEQU a$,"Hi there"
    MATEQU a%,6
    MATEQU a%,-PI
    test$=9.5: MATEQU a%,test$
    MATEQU a,9.5
    MATEQU a$,b$

**NOTE**

Supercharge and Turbo users... sorry!

**CROSS-REFERENCE**

:ref:`matrnd`, :ref:`matidn`

