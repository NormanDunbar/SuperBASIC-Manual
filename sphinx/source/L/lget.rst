..  _lget:

LGET
====

+----------+----------------------------------------------------------------------------+
| Syntax   | LGET [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
|          |                                                                            |
|          | LGET [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+----------------------------------------------------------------------------+
| Location | SMSQ/E                                                                     |
+----------+----------------------------------------------------------------------------+

This command is very similar to BGET, although this fetches a longword
(4 bytes) at a time (in the range 0..2\ :sup:`32`\ -1) from the given channel
(default #3).

**NOTE**

LGET is affected by TRA.

**CROSS-REFERENCE**

See :ref:`bget`. :ref:`lput` is
complementary function. :ref:`wget` allows you to
fetch word values.

