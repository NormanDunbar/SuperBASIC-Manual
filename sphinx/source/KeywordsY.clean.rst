
==========
Keywords Y
==========



..  _ylim:

YLIM
====

+----------+-------------------------------------------------------------------+
| Syntax   || YLIM  or                                                         |
|          || YLIM #ch (v2.08+)                                                |
+----------+-------------------------------------------------------------------+
| Location || ATARI\_REXT (v1.29+)                                             |
+----------+-------------------------------------------------------------------+

This function returns the vertical size of the screen in pixels. The
second variant makes this function the same as SCR\_YLIM.

**NOTE**

The Pointer Interface must be present for this function to work.

**CROSS-REFERENCE**

See :ref:`xlim` for details.

--------------


..  _y-ptr-pct:

Y\_PTR%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  Y\_PTR%                                                          |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

This function will return the y co-ordinate of the pointer which is
controlled by the mouse. The value is given in absolute pixel
co-ordinates, with the point 0,0 being the top left hand corner of the
screen.

**CROSS-REFERENCE**

See :ref:`ptr-pos` and
:ref:`ptr-max`.
:ref:`x-ptr-pct` reads the x co-ordinate.

