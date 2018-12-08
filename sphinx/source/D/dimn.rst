..  _dimn:

DIMN
====

+----------+---------------------------------------------------------------------------------+
| Syntax   | DIMN (array [,dimension] )  or                                                  |
|          |                                                                                 |
|          | DIMN (array (dimension\ :sup:`1` :sup:`*`\ [,dimension\ :sup:`i`]\ :sup:`*`\ )) |
+----------+---------------------------------------------------------------------------------+
| Location | QL ROM                                                                          |
+----------+---------------------------------------------------------------------------------+

This function allows you to investigate the size of the given index of
a specified array.

The first syntax is the most common: it will return
the specified dimension (index) used in the original DIM statement when
the array was defined. If the index did not exist, then a result of zero
is returned.

If dimension is not specified, then the size of the first
index is returned.

The second syntax is somewhat obscure and has no
practical advantages. This second syntax will not allow you to access
the size of the first index. It works by reference to the array itself,
for example::

    PRINT DIMN(a$(1))

will return the size of the second index, and::

    PRINT DIMN(a$(1,1))

will return the size of the third index and so forth. Once the number
of dimensions used within the DIMN statement has reached the number used
by the array, then the value 1 will be returned. If any more are
specified, then the error 'Out of Range' will result.


**Examples**

Take an array created with the statement::

    DIM a$(10,12)

The following results will be returned::

    PRINT DIMN(a$)

Will return 10.

::

    PRINT DIMN(a$,1)

Will return 10.

::

    PRINT DIMN(a$,2)

Will return 12.

::

    PRINT DIMN(a$,3)

Will return 0.

::

    PRINT DIMN(a$(1))

Will return 12.

::

    PRINT DIMN(a$(1,1))

Will return 1.

::

    PRINT DIMN(a$(1,1,1))

Will cause an 'Out of Range' error.


**CROSS-REFERENCE**

:ref:`len` will return the actual length of characters
held within a string. :ref:`dim` initialises an array.

