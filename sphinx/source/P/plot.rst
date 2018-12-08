..  _plot:

PLOT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PLOT x,y,colour                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

This command forces a pixel to be set at the absolute screen position
x,y. The origin (0,0) is the upper left corner of the full QL screen,
the opposite corner (diagonally) is (511,255). Two neighbouring points
do not have any space between them.

Co-ordinates greater than 511 (x) or
255 (y) or smaller than 0 are modulated - (x MOD 511) and/or (y MOD 255). The base
address of the screen used by PLOT is defined with SCRBASE. PLOT works
in MODE 4 only.

**Example**

The following procedure plots a point given in polar co-ordinates. A
simple approach to draw a line in a polar system is listed at DRAW. A
sensible range for the radius is 0 <= r <= 127.

::

    100 DEFine PROCedure POLAR_PLOT (r,phi,col)
    110   LOCal x,y
    120   x=1.35*r*SIN(phi+PI/2)+255
    130   y=r*COS(phi+PI/2)+127
    140   PLOT x,y,col
    150 END DEFine POLAR_PLOT


**NOTE 1**

PLOT writes directly into screen memory and will work on 512x256
resolutions only, it assumes by default that the screen starts at $20000
(redefine with SCRBASE) and works in MODE 4 only.

**NOTE 2**

Minerva users can SCRBASE SCREEN(#3) to allow PLOT to draw on the screen
on which channel #3 is located.

**CROSS-REFERENCE**

:ref:`draw` draws a line,
:ref:`sclr` clears the screen, and
:ref:`refresh` makes the screen defined by
:ref:`scrbase` visible. Compare the other
implementation of :ref:`plot`.

--------------


PLOT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PLOT [#ch,] x1,y1                                                |
+----------+-------------------------------------------------------------------+
| Location |  DRAW (DIY Toolkit - Vol G)                                       |
+----------+-------------------------------------------------------------------+

This command plots a point in absolute co-ordinates on the screen with
reference to the specified window channel (if any - default #1). This is
also used to specify the start point of a line to be drawn with the DRAW
command from the same toolkit.

This is quicker than using the SuperBASIC
POINT command and unlike other similar commands, it will support the
current INK  colour and OVER mode.

<CTRL><F5> will pause the point drawing and it
will even work in MODE 4, 8 and 12 (on the THOR XVI, if you have v1.6+).

The main limitation on this command is that the point must appear within
the specified window, so x1 and y1 cannot exceed the width or height of
the specified window (in pixels), or be less than zero.

**NOTE**

Although PLOT will work wherever the screen base is located, it assumes
that a line of pixels takes 128 bytes - it will not therefore work on
higher resolutions.

**CROSS-REFERENCE**

See the other variant of :ref:`plot`. See also
:ref:`draw`. Compare
:ref:`point`.

