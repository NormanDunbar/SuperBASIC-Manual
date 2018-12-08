..  _ptr-on:

PTR\_ON
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_ON                                                          |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

This command enables the mouse driver after it has been loaded or after
it has been disabled with PTR\_OFF. All of the mouse settings are reset
to the defaults (set when the files were originally assembled) and the
pointer is positioned in the top left corner of the screen (position
0,0).

**CROSS-REFERENCE**

You can re-position the mouse with
:ref:`ptr-pos`. See
:ref:`sermon` and
:ref:`ptr-off`.
:ref:`ptr-inc`,
:ref:`ptr-key` and
:ref:`ptr-max` are also needed to set various
parameters on start-up.
