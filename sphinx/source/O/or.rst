..  _or:

OR
==

+----------+-------------------------------------------------------------------+
| Syntax   |  condition1 OR condition2                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This combination operator combines two condition tests together and
will have the value 0 if both condition1 and condition2
are false, or 1 if either condition1 or condition2 are true (or both
are true). Please note the difference between this and the bitwise OR
operator: x\|\|y, which compares x and y bit by bit.

**Example 1**

::

    PRINT 1 OR 0

Returns 1.

::

    PRINT 12 OR 10

Returns 1.

Compare PRINT 12&&10 which returns 14).

**Example 2**

::

    10 FOR x=1 TO 5
    20   FOR y=1 TO 5
    30     IF x=3 OR y>3:PRINT x;'=>';y,
    40   END FOR y
    50 END FOR x

produces the following output::

    1=>4 1=>5 2=>4 2=>5 3=>1 3=>2 3=>3 3=>4 3=>5 4=>4 4=>5 5=>4 5=>5

**CROSS-REFERENCE**

:ref:`and`, :ref:`not` and
:ref:`xor` are the other combination operators.

--------------


