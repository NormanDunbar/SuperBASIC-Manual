..  _ttpokem:

TTPOKEM
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTPOKEM adr2 { , \| ! \| TO } adr1, bytes                        |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

The command TTPOKEM moves any amount of bytes in memory from address
adr1 to adr2. The choice of the separator only makes a difference if the
source memory area overlaps with the destination. The separator has the
following effects:

- Comma (,) : the move is non-destructive, meaning that the memory area from adr1 has been copied to adr2 so that it is identical to the area which was previously located at adr1 (the area at adr1 has changed of course if the areas overlap).
- ! or TO : The move is destructive and the overlapping parts of or both blocks will be messed up, that is because the first few bytes stored at adr1 will be stored at adr2 onwards, thus overwriting the last few bytes of adr1 which should have been copied.

**CROSS-REFERENCE**

:ref:`bmove`, :ref:`copy-b`,
:ref:`copy-l`, :ref:`copy-w`

