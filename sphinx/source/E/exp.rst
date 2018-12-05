..  _exp:

EXP
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EXP (var)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the value of the mathematical base e to the power of the
given parameter (in other words, this is equivalent to the mathematical
expression e\ :sup:`var`). This is the opposite to the function LN, ie.
var=LN(EXP(var)).

QDOS supports var in the range -512...511. The approximate value of e can be
found by::

    PRINT EXP(1)

::

    PRINT EXP(0)

returns the value 1 - as any good mathematician knows, anything to the power
of 0 returns the value 1.

**CROSS-REFERENCE**

:ref:`ln` returns the natural logarithm of the given
value.

--------------


