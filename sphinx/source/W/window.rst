..  _window:

WINDOW
======

+----------+----------------------------------------------------------------------+
| Syntax   | WINDOW [#ch,] x, y, posx, posy  or                                   |
+----------+----------------------------------------------------------------------+
| Syntax   | WINDOW [#ch,] x, y, posx, posy [\\border] (Minerva v1.79+, THOR XVI) |
+----------+----------------------------------------------------------------------+
| Location | QL ROM, Minerva, THOR XVI                                            |
+----------+----------------------------------------------------------------------+

This command redefines the given screen window (default #1) by
specifying the new size and position of the window. The values must all
be calculated in the pixel co-ordinate system, which means that x and
posx can be in the range 0...XLIM (in both MODE 4 and MODE 8), provided
that x+posx<=XLIM and y and posy can be in the range 0..YLIM, provided
that y+posy<=YLIM.

On a standard QL resolution screen (ie. 512x256
pixels), due to the shape of the screen, a window which measures 100x100
pixels will not appear square. You will need to use a size of 137x100
pixels instead! The Minerva and THOR XVI variants allow you to specify a
border to be drawn around the window at the same time, by the addition
of up to a further four parameters in the form: [\\border\_size [,colour
[,colour2 [,stipple ]]]] This therefore allows you to combine the WINDOW
and BORDER commands. For example::

    WINDOW 448,200,32,16\2,2

is the same as::

    WINDOW 448,200,32,16:cBORDER 2,2.

**Example**

::

    WINDOW 448,200,32,16

is similar to::

    OPEN #1,CON

**NOTE 1**

Although the '\\' separator is not checked for on the Minerva and THOR
XVI implementations, it is recommended to ensure that this is present to
ensure future compatibility. Older ROM versions did not check the number
of parameters, which could result in some software causing problems
unless the separator is actually checked for.

**NOTE 2**

You cannot have a gap of one pixel between windows, even in MODE 4 -
this is to ensure compatibility between MODE 4 and MODE 8. Any odd
parameters will be rounded down.

**MINERVA NOTE**

In a MultiBasic, both channel #0 and #1 are inextricably linked.
Unfortunately, this means that in certain cases both channel #0 and
channel #1 must have the same size and position: any attempt to re-size
#0 will re-size #1 and vice versa. See the MultiBasic appendix for
further details.

**CROSS-REFERENCE**

:ref:`open` allows you to open a window ready for
use. :ref:`border` allows you to set an implicit
border.

--------------


