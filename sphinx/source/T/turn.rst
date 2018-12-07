..  _turn:

TURN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TURN [#ch,] degrees                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is part of the QL's turtle graphics set and alters the
current direction of the turtle in the specified window (default #1).
When a window is first opened, the turtle will be facing the right hand
side of the window (this is zero degrees).

TURN will force the turtle to turn anti-clockwise by the specified number of
degrees (note that this does not work in radians!). If a negative number
of degrees is specified, the turtle will be turned in a clockwise
direction.

**CROSS-REFERENCE**

:ref:`turnto` forces the turtle to face in an
absolute direction. Please also see :ref:`move`.

