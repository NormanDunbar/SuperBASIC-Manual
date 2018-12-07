..  _uput:

UPUT
====

+----------+----------------------------------------------------------------------------+
| Syntax   | UPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
|          |                                                                            |
|          | UPUT [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+----------------------------------------------------------------------------+
| Location | SMSQ/E v2.55+                                                              |
+----------+----------------------------------------------------------------------------+

This command is the same as BPUT, except that any bytes sent by it to
the specified channel (default #3) are not affected by the TRA command.
This command is therefore useful for sending printer control codes.

**CROSS-REFERENCE**

See :ref:`bput`, :ref:`wput` and
:ref:`lput`.

