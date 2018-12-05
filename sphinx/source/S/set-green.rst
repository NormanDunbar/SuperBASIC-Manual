..  _set-green:

SET\_GREEN
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  SET\_GREEN #channel, operation                                   |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This command allows you to change the colours used within a specified
window channel very quickly. In order to use this, you really need a
good understanding of the way in which the QL display works - see the QL
Display Appendix for some details. The effect that this command has on
the specified window depends upon the value of operation:


+-----------+---------------------------------------------------------------------------+
| Operation | Effect                                                                    |
+===========+===========================================================================+
| 0         | Clear all Green bits (remove any Green from the screen).                  |
+-----------+---------------------------------------------------------------------------+
| 1         | Set all Green bits.                                                       |
+-----------+---------------------------------------------------------------------------+
| -1        | If the Red bit for a pixel is set, Set the Green bit, otherwise clear it. |
+-----------+---------------------------------------------------------------------------+

**NOTE 1**

This command will only work on screen resolutions of 512x256 pixels.

**NOTE 2**

This command should not really be used in MODE 8.

**CROSS-REFERENCE**

:ref:`set-red` is similar. See
:ref:`recol`. :ref:`w-swap`
can also be used to recolour a window. Refer to the QL Display Appendix.

--------------


