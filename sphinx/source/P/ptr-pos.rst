..  _ptr-pos:

PTR\_POS
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_POS x,y                                                     |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

This command can be used to set the initial position of the mouse
pointer on screen - it is normally located at 0,0 (the top left hand
corner of the screen).

You can however use this command to set it to the
specified absolute pixel co- ordinates, which must be within the area
defined with the PTR\_LIMITS command.

**CROSS-REFERENCE**

See :ref:`ptr-limits` and
:ref:`ptr-on`. The pointer position can be read
with :ref:`x-ptr-pct`,
:ref:`y-ptr-pct` and
:ref:`ptr-fn-pct`.
