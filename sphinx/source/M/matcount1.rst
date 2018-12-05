..  _matcount1:

MATCOUNT1
=========

+----------+------------------------------------------------------------------+
| Syntax   | MATCOUNT1 (array, value)  or                                     |
|          |                                                                  |
|          | MATCOUNT1 (array1, array2)                                       |
+----------+------------------------------------------------------------------+
| Location | Math Package                                                     |
+----------+------------------------------------------------------------------+

The function MATCOUNT1 is just a variation of MATCOUNT which performs
comparisons not as exact as MATCOUNT. Numbers must only be almost equal,
the absolute difference must be smaller than the absolute of the second
number divided by 1E7: ABS (a-b) < ABS (b / 1E7). This is the case if
a==b. MATCOUNT1 is therefore the same as MATCOUNT if integers are being
dealt with. Comparison of strings is not case-sensitive, again this is
analogous to the == operator: "QDOS"=="Qdos" is true while "QDOS"="Qdos" is not.

**CROSS-REFERENCE**

:ref:`matcount`,
:ref:`matequ`.

--------------


