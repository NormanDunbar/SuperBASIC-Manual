..  _line:

LINE
====

+----------+----------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   |  LINE [#chan,] [x,y] [TO x\ :sup:`1`,y\ :sup:`1`] :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] [TO x\ :sup:`j`\ ,y\ :sup:`j`] ]\ :sup:`\*` |
+----------+----------------------------------------------------------------------------------------------------------------------------------------+
| Location |  QL ROM                                                                                                                                |
+----------+----------------------------------------------------------------------------------------------------------------------------------------+

This command is part of the QL's graphics repertoire and allows you to
draw a straight line in the specified channel (default #1) in the
current INK colour between any two points. As with all of the other
graphics commands, the exact size and position of the line depends upon
the current SCALE. Unfortunately, there is no way of making the line any
thicker, other than by drawing parallel lines. Although the above syntax
may seem rather complex, this can be explained as follows:

If the separator TO appears between any two sets of co-ordinates, then a line
will be drawn between those two co-ordinates.

If however the two sets of
co-ordinates are the same, nothing will be drawn, eg: LINE 10,10 TO
10,10 has no effect.

If the start co-ordinates are not specified, then the
current graphics cursor is used as the one end of the line, eg: LINE
10,10 TO 15,10 TO 20,20
will draw a line between the points (10,10) and (15,10) and then a line
between (15,10) and (20,20). The graphics cursor is placed at the last
set of co-ordinates.

If the separator TO does not appear, then no line
is drawn and the graphics cursor is moved to the last set of
co-ordinates. For example: LINE 10,10 and LINE 20,20,10,10
have exactly the same effect - they both place the graphics cursor at
the point (10,10).

Any part of the lines which lie outside of the
specified channel will not be drawn, but no error will be reported.

**Example**

A simple demonstration program::

    100 MODE 8 110 WINDOW 448,200,32,16:PAPER 0:CLS
    120 SCALE 100,0,0
    130 OVER -1
    140 REPeat loop
    150   xstep=RND
    160   INK RND(7)
    170   FOR i=1 TO 360 STEP xstep
    180     ix=RAD(i)
    190     LINE 50,50 TO 50+COS(ix)\*50,50+SIN(ix)\*50
    200   END FOR i
    210 END REPeat loop

**NOTE**

On a MG ROM, you may find that the last point is not always plotted.

**CROSS-REFERENCE**

:ref:`line-r` is very similar. See also
:ref:`ellipse`,
:ref:`circle`, :ref:`arc`,
:ref:`point` and :ref:`scale`.

--------------


