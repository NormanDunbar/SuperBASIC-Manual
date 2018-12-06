..  _ellipse:

ELLIPSE
=======

+----------+---------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | ELLIPSE [#ch,] x,y,radius,ratio,ecc :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`\ ,radius\ :sup:`i`\ ,ratio\ :sup:`i`\ ,ecc\ :sup:`i`]\ :sup:`\*` |
+----------+---------------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                      |
+----------+---------------------------------------------------------------------------------------------------------------------------------------------+

Both the ELLIPSE and CIRCLE commands perform exactly the same function.
We have however decided to split them, since if users adopt the habit of
using ELLIPSE to draw ellipses and CIRCLE to draw circles,
this will help users understand SuperBASIC programs
much more easily.

This command allows you to draw an ellipse in the
current INK colour of the given radius with its centre point at the
point (x,y).

The ratio affects the difference between the major axis and
the minor axis - the greater the ratio, the greater the difference
between the two.

The major (y) axis is specified by the parameter
radius, whereas the minor (x) axis is calculated by radius\*ratio which
therefore means that if ratio>1, the major axis will become the (x) axis
(if you see what we mean!).

Ecc defines the angle at which the ellipse
will be drawn. This is measured in radians and forms the anti-clockwise
angle between a vertical line drawn through the origin of the ellipse
and the major axis. Thus, ecc=PI/4 draws an ellipse at an angle of 45
degrees.

The actual positioning and size of the ellipse will depend upon
the scale and shape of the specified window (default #1).

The
co-ordinates are calculated by reference to the graphics origin, and the
graphics pointer will be set to the centre point of the last ellipse to
be drawn on completion of the command. If any parts of the ellipse lie
outside of the specified window, they will not be drawn (there will not
be an error).

If the parameters ratio and ecc are omitted, this command
has exactly the same effect as CIRCLE. This command will actually allow
you to draw multiple ellipses by including more sets of parameters. Each
additional set must be preceded by a semicolon (unless the preceding
ellipse uses five parameters). This means for example, that these all
perform the same action::

    ELLIPSE 100,100,20,1,2,50,50,20
    ELLIPSE 100,100,20,1,2; 50,50,20
    ELLIPSE 100,100,20,1,2: CIRCLE 50,50,20

Although the FILL command will allow you to draw filled ellipses on
screen (in the current ink colour), you will need to include a FILL 1
statement prior to each ellipse if they are to appear independently on
screen (this cannot be achieved when using this command to draw multiple
ellipses).

If this rule is not followed, then any points which lie on
the same horizontal line (even though they may be in different ellipses)
will be joined.

**Example**

Try the following for an interesting effect::

    100 MODE 8
    110 WINDOW 448,200,32,16:PAPER 0:CLS
    120 SCALE 100,0,0
    130 INK 4:OVER -1
    140 REPeat loop
    150   FOR ang=0 TO PI*2-(PI*2/20) STEP PI*2/20
    160     FILL 1:ELLIPSE 70,50,40,.5,ang
    170     FILL 1:ELLIPSE 70,50,40,.5,ang
    180   END FOR ang
    190 END REPeat loop

**NOTE**

On all ROMs other than Minerva v1.89+, very small ellipses and very
large ones can cause problems. Try::

    ELLIPSE 80,80,80,6,1

on a non-Minerva machine for a laugh.

Unfortunately, Lightning SE (v2.11) still contains
this bug and will bring it back!

**CROSS-REFERENCE**

Please refer to :ref:`circle`,
:ref:`ellipse-r`, :ref:`arc`,
:ref:`line` and :ref:`point`.

