..  _xor:

XOR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  condition1 XOR condition2                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This combination operator combines two condition tests together and
will have the value 0 if both condition1 and condition2
are true or both are false or 1 if either condition1 or condition2
are true (but not both).

Please note the difference between this and the bitwise XOR
operator: x^^y, which compares x and y bit by bit.

**Examples**

::

    PRINT 1 XOR 0: REMark Returns 1.
    PRINT 2 XOR 10 REMark Returns 0.

Compare::

    PRINT 2^^10

which returns 8.

::

    10 FOR x=1 TO 5
    20   FOR y=1 TO 5
    30     IF x=3 XOR y >1 AND y<3:PRINT x;'=>';y,
    40   END FOR y
    50 END FOR x

produces the following output::

    1=>2 2=>2 3=>1 3=>3 3=>4 3=>5 4=>2 5=>2

**CROSS-REFERENCE**

:ref:`and`, :ref:`or` and
:ref:`not` are the other combination operators.

