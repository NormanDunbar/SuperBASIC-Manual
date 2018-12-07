..  _ptr-inc:

PTR\_INC
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_INC x\_step, y\_step                                        |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE (DIY Toolkit - Vol I)                                     |
+----------+-------------------------------------------------------------------+

This command is only really of any use when the Cursor Key emulation is
enabled (see PTR\_KEY). It allows you to set the number of mouse pulses
which are taken to correspond to moving the cursor 1 character either in
an x direction or a y direction.

The two values given are normally set
to 12 and 24 respectively for MODE 4 operation, although if this proves
too quick (especially in MODE 8), you could try PTR\_INC 24,24. The
higher the values, the slower the cursor will move as you push the mouse
about the table.

**CROSS-REFERENCE**

See :ref:`ptr-key` and also compare
:ref:`sermspeed`.

