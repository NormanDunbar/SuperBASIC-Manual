..  _turnto:

TURNTO
======

+----------+-------------------------------------------------------------------+
| Syntax   |  TURNTO [#ch,] angle                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command, in contrast to TURN forces the turtle in the specified
window (default #1) to face in the direction specified by angle. If
angle=0, the turtle will face the right hand edge of the window, whereas
an angle of 90 will force the turtle to point towards the top of the
window. A negative value of angle will cause the turtle to turn
clockwise, so that angle=-90 is the same as angle=270.

**CROSS-REFERENCE**

Please refer to :ref:`move` and
:ref:`turn`.

--------------


