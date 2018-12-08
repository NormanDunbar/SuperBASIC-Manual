..  _matsub:

MATSUB
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATSUB difference,matrix1,matrix2                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

Provided that the parameters of the command MATSUB fulfil the same
conditions as for MATADD, MATSUB will store the difference between
matrix1 and matrix2 in difference. Difference(...) = matrix1(...) -
matrix2(...). Two or all of the parameters can be identical, so::

    MATSUB a,a,a

and::

    MATSUB a,b,a

etc. are valid.

**CROSS-REFERENCE**

:ref:`matadd`!

