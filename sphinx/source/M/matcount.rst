..  _matcount:

MATCOUNT
========

+----------+------------------------------------------------------------------+
| Syntax   | MATCOUNT (array, value)  or                                      |
|          |                                                                  |
|          | MATCOUNT (array1, array2)                                        |
+----------+------------------------------------------------------------------+
| Location | Math Package                                                     |
+----------+------------------------------------------------------------------+

MATCOUNT is a function which counts how often a certain value appears
in the given array where array and value can be of any type (even
strings) as long as they are of the same type. The second syntax allows
you to pass two arrays array1 and array2 of the same type and
dimensions, MATCOUNT will then compare these two arrays and return the
number of different elements.

**Example**

The following programs compares two random integer arrays and will
always print something around 33%::

    100 DIM x%(1000), y%(1000)
    110 MATRND x%,2: MATRND y%,2
    120 PRINT MATCOUNT(x%,y%)/10;"%"

**CROSS-REFERENCE**

:ref:`matcount` comparisons are exact in that two
numbers a and b are only regarded as equal if a=b in SuperBASIC terms.
The same is true for strings, it means that their comparison is
case-sensitive. :ref:`matcount1` differs from
:ref:`matcount` (see below) only in the fact that
comparisons are based on the SuperBASIC operator == instead of =.

--------------


