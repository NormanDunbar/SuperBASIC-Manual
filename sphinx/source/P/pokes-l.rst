..  _pokes-l:

POKES\_L
========

+----------+------------------------------------------------------------------------------------------------------------------------+
| Syntax   | POKES address, {value\ :sup:`1` \| value\ :sup:`1`\ $} :sup:`\*`\ {,value\ :sup:`i` \| ,value\ :sup:`i`\ $}\ :sup:`\*` |
|          |                                                                                                                        |
|          | and                                                                                                                    |
|          |                                                                                                                        |
|          | POKES\_W address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\                                            |
|          |                                                                                                                        |
|          | and                                                                                                                    |
|          |                                                                                                                        |
|          | POKES\_L address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\                                            |
+----------+------------------------------------------------------------------------------------------------------------------------+
| Location | SMSQ/E and ATARI\_REXT v2.17+                                                                                          |
+----------+------------------------------------------------------------------------------------------------------------------------+

These three commands are only of any use on the Atari series of
computers. They are the same as the simple forms of POKE, POKE\_W and
POKE\_L, except that they operate in Supervisor Mode and can therefore
be used to write data direct into the Atari's IO hardware. On all other
implementations they are the same as POKE, POKE\_W
and POKE\_L.

**CROSS-REFERENCE**

See :ref:`poke` and :ref:`peeks`.
Also see :ref:`prot-mem`.

