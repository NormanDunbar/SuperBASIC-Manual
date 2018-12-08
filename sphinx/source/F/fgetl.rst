..  _fgetl:

FGETL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETL [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads four bytes, being the internal representation of
a longword, from a specified channel (default #1) and returns the
longword's value.

**Example**

It is preferable to store a large integer in internal format because
this is faster than text representation and needs less memory, even if
the number could be stored in internal float format::

    100 large_int = 1.19344E7
    110 :
    120 REMark save value
    130 OPEN_NEW#3,ram1_test
    140 PRINT#3,MKL$(large_int)
    150 CLOSE#3: CLEAR
    160 :
    170 REMark read value
    180 OPEN_IN#3,ram1_test
    190 large_int = FGETL(#3)
    200 CLOSE#3: PRINT large_int

**CROSS-REFERENCE**

:ref:`lget`, :ref:`mkl-dlr`.
:ref:`fputl` allows you to write numbers in internal
format to channels. :ref:`cvl` converts strings
containing the internal format to long integers.

