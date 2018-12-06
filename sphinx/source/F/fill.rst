..  _fill:

FILL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FILL [#channel,] boolean                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command switches Fill mode on and off. If the Fill mode is on
(after FILL 1), all points in the given window channel (default #1) that
have the same vertical co-ordinate are connected by a line in the
current ink colour so that only non re-entrant figures can be filled
correctly. This means that figures must only contain two points on each
horizontal row of pixels. The fill mode is de-activated by FILL 0.

**Example 1**

::

    FILL 1: POINT 20,20,40,20: FILL 0

draws a horizontal line from 20,20 to 40,20.

**Example 2**

::

    100 DEFine PROCedure SQUARE (x,y,size,angle)
    110   LOCal n: POINT x,y
    120   TURNTO angle: PENDOWN: FILL 1
    130   FOR n=1 TO 4: MOVE size: TURN 270
    140   PENUP: FILL 0
    150 END DEFine SQUARE

**NOTE 1**

FILL only affects those graphic commands which use relative
co-ordinates, ie. which are influenced by SCALE. Commands which operate
in absolute window or screen co-ordinates will not invoke filling.

**NOTE 2**

On non-Minerva ROMs, 1K of memory may be lost if you do not issue a FILL
0 before closing a window. This is however fixed by v1.38 (or later) of
the Pointer Interface (although earlier versions will re-introduce it to
Minerva!).

**NOTE 3**

When drawing several shapes, all of which are to be filled, ensure that
you issue a FILL 0 between each shape, otherwise they will be joined
together if any points appear on the same horizontal line!

**NOTE 4**

FILL works by setting aside a buffer of approximately 1K. Whenever a
point is then plotted in the given window, FILL looks at the buffer to
see if anything appears to the left of that point on the same horizontal
line (in which case, it fills the line between the two points),
otherwise, FILL will just note the co-ordinate of the point in its
buffer.

FILL then checks if anything appears to the right of the given
point, and if so, will fill the line between the two points. Again, the
co-ordinate of the point will be stored if nothing appears to the right
of it.

This should explain quite a few of FILL's quirks. Whenever a new
FILL command is used on that window, the old buffer is lost, meaning
that FILL will forget about any points previously plotted.

Unfortunately, the interaction of this buffer causes a lot of problems
(and prevents re-entrant shapes), especially in view of the fact that
only FILL or CLOSE will clear the buffer. The buffer is not cleared once
a shape has been completely filled (eg. with CIRCLE), nor even when the
screen is cleared with CLS. Try this for example::

    100 INK 7:FILL 1
    110 CIRCLE 50,50,20
    130 CLS
    135 INK 2
    140 CIRCLE 70,60,20

**NOTE 5**

If OVER -1 is switched on, the same line of an image may be FILLed
twice causing that line to be left empty, unless you start drawing the
image from either the top or the bottom. You may also encounter problems
if you try to draw a line which has already been completed by FILL - for
example try::

    100 OVER -1: FILL 1
    110 LINE 50,50 TO 60,60 TO 70,50 TO 50,50

The FILL command will complete the triangle as soon as the line
between the points (60,60) and (70,50) has been drawn, therefore this
should be re-written::

    100 OVER -1:FILL 1
    110 LINE 50,50 TO 60,60 TO 70,50

On Minerva v1.97 and SMSQ/E, matters are further complicated - the
first example draws a complete triangle, whereas the second one doesn't!

**NOTE 6**

If OVER -1 is switched on, a shape which is drawn as FILLed will not
be wiped out by re-drawing the same shape again, unless you do a FILL 1
before re-drawing the shape. For example, try this::

    100 OVER -1:FILL 1:CIRCLE 50,50,20
    110 PAUSE: CIRCLE 50,50,20

The answer is to insert a line::

    105 FILL 1

**NOTE 7**

On Minvera pre v1.86 FILL 0 when fill was not actually switched on would
stop SuperBASIC!!

**CROSS-REFERENCE**

The paint colour of :ref:`fill` is specified by
:ref:`ink`.

