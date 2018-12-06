..  _and:

AND
===

+----------+-------------------------------------------------------------------+
| Syntax   |  condition1 AND condition2                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This combination operator combines two condition tests together and will
have the value 1 if both condition1 and condition2 are true or 0 if
either condition1 or condition2 are false.

A value is said to be false if it is equal to zero, anything else will
cause that value to be true.

Please note the difference between this and the bitwise and operator:
x&&y, which compares x and y bit by bit.

**Examples**

PRINT 1 AND 0 Returns 0

PRINT 12 AND 10 Returns 1

(compare PRINT 12&&10 which returns 8).

::

    10 FOR x=1 TO 5
    20   FOR y=1 TO 5
    30     IF x=3 AND y>3 THEN PRINT x;' => ';y,
    40   END FOR y
    50 END FOR x

produces the following output:

3=>4 3=>5

**CROSS-REFERENCE**

:ref:`or`, :ref:`not` and
:ref:`xor` are the other combination operators.

