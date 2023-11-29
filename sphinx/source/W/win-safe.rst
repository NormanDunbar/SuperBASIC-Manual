..  _win-safe:

WIN\_SAFE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_SAFE card                                                   |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Q68                                                   |
+----------+-------------------------------------------------------------------+

This command checks whether it is safe to remove a card as far as the
WIN driver is concerned. If the card is safe to remove it returns no
error. If the card is not safe to remove it returns the error "is in
use".

**Example**

::

   WIN_SAFE 1 REMark is SD card 1 safe to remove

   

