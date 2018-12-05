..  _move:

MOVE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MOVE [#ch,] distance                                             |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The QL supports a simplified means of drawing pictures known as turtle
graphics. This was based upon an early educational tool, whereby simple
commands could be entered into a computer to drive a small robot turtle
which moved around the floor and held a pen. This pen could either be up
in which case the turtle would just move around, or down in which case a
line would be left by the turtle on the floor as it moved.

When a window
is first opened, an invisible turtle appears at the graphics origin
(altered with SCALE) facing to the right, with its pen in the up
position.

The command MOVE forces the turtle in the specified window
(default #1) to move in the current direction by the specified distance.

The actual distance moved on screen depends on the current SCALE
applicable to that window. If distance is negative, the turtle will move
backwards. MOVE always works from the current graphics cursor position,
and after using this command, the current graphics cursor is placed at
the turtle's position on screen. MOVE is affected by the current INK
colour, FILL and also OVER, just like any other graphics command.

**Example**

A simple procedure to draw a shape of a set number of equal length
sides::

    100 DEFine PROCedure POLYGON (chan, sides, side_length)
    110   TURNTO #chan,0: PENDOWN #chan
    120   FOR k = 1 TO sides
    130     MOVE #chan, side_length
    140     TURN #chan, 360 / sides
    150   END FOR k
    155   PENUP #chan
    160 END DEFine

Try for example, POLYGON #2,5,10.

**NOTE**

The THOR XVI v6.40 tended to crash when using turtle graphics,
especially if a channel number was specified.

**CROSS-REFERENCE**

:ref:`pendown` forces the pen into the down
position, leaving a trail on screen. :ref:`penup`
allows the turtle to move without leaving a trail.
:ref:`turn` and :ref:`turnto`
allow you to alter the direction of the turtle.

--------------


