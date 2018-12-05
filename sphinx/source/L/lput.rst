..  _lput:

LPUT
====

+----------+----------------------------------------------------------------------------+
| Syntax   | LPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
|          |                                                                            |
|          | LPUT [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+----------------------------------------------------------------------------+
| Location | SMSQ/E                                                                     |
+----------+----------------------------------------------------------------------------+

This command is the complement to LGET, in that it places the longword
value for each item into the specified channel (default #3) at the
current file position (or the specified position if the first variant is
used).

**NOTE**

LPUT is affected by TRA.

**CROSS-REFERENCE**

See :ref:`bput` and :ref:`lget`.
:ref:`wput` and :ref:`put` are also
similar.

--------------


