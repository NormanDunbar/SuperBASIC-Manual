..  _matread:

MATREAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATREAD array                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATREAD initialises the array (of any type) by reading each
element from DATA lines. Since MATREAD does the same as the following
routine::

    FOR i1=0 TO DIMN(array,1)
      FOR i2=0 TO DIMN(array,2)
        ...
        READ array(i1, i2)
        ...
      END FOR i2
    END FOR i1

all of the normal errors of READ may occur.

**Example**

The following example is identical to MATSEQ a%

::

    100 DIM a%(3,2)
    110 MATREAD a%
    120 :
    130 DATA 1, 2, 3, 4
    140 DATA 5, 6, 7, 8
    150 DATA 9,10,11,12

is identical to MATSEQ a%.

**CROSS-REFERENCE**

:ref:`matinput`

