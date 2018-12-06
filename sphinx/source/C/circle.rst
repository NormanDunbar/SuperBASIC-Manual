..  _circle:

CIRCLE
======

+----------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | CIRCLE [#ch,] x,y,radius [,ratio,ecc] :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`\ ,radius\ :sup:`i` [,ratio\ :sup:`i`\ ,ecc\ :sup:`i`]]\ :sup:`\*` |
+----------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                         |
+----------+------------------------------------------------------------------------------------------------------------------------------------------------+

This command allows you to draw a circle of the given radius with its
centre point at the point (x,y).

The positioning and size of the circle will actually depend upon the
scale and shape of the specified window (default #1).

The co-ordinates are calculated by reference to the graphics origin, and
the graphics pointer will be set to the centre point of the last circle
to be drawn on completion of the command.

If any parts of the circle lie outside of the specified window, they
will not be drawn (there will not be an Overflow Error).

If the parameters ratio and ecc are specified, this command has exactly
the same effect as ELLIPSE.

This command will actually allow you to draw multiple circles by
including more sets of parameters. Each additional set must be preceded
by a semicolon (unless the preceding circle uses five parameters). This
means that these commands are all the same:

::

    CIRCLE 100,100,20,1,0,50,50,20
    CIRCLE 100,100,20;50,50,20
    CIRCLE 100,100,20:CIRCLE 50,50,20

Although the FILL command will allow you to draw filled circles on
screen (in the current ink colour), you will need to include a FILL 1
statement prior to each circle if they are to appear independently on
screen (this cannot be achieved when using this command to draw multiple
circles!). If this rule is not followed, then any points which lie on
the same horizontal line (even though they may be in different circles)
will be joined.

**Example**

Try the following for an interesting effect:

::

    100 WINDOW 448,200,32,16: MODE 8
    110 PAPER 0: CLS
    120 SCALE 200,-100,-100
    130 INK 4:CIRCLE -50,-50,5
    140 FOR i=1 TO 350
    150   INK RND(7): FILL 1
    160   CIRCLE_R 5-(i MOD 10),15-(i MOD 30),20
    170 END FOR i

**CROSS-REFERENCE**

Please refer to :ref:`ellipse` for further
information on the ratio and ecc details.

