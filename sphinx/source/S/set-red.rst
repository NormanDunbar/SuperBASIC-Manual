..  _set-red:

SET\_RED
========

+----------+-------------------------------------------------------------------+
| Syntax   |  SET\_RED #channel, operation                                     |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This command is similar to SET\_GREEN - the only difference is that
instead of affecting green bits, it alters the red bits. The effect that
this command has on the specified window depends upon the value of
operation:

+-----------+---------------------------------------------------------------------------+
| Operation | Effect                                                                    |
+===========+===========================================================================+
| 0         | Clear all Red bits (remove any Red from the screen).                      |
+-----------+---------------------------------------------------------------------------+
| 1         | Set all Red bits.                                                         |
+-----------+---------------------------------------------------------------------------+
| -1        | If the Green bit for a pixel is set, Set the Red bit, otherwise clear it. |
+-----------+---------------------------------------------------------------------------+

**CROSS-REFERENCE**

See :ref:`set-green` !

--------------


