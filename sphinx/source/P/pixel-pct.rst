..  _pixel-pct:

PIXEL%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PIXEL% ( [#ch,] x1,y1 )                                          |
+----------+-------------------------------------------------------------------+
| Location |  PIXEL (DIY Toolkit - Vol G)                                      |
+----------+-------------------------------------------------------------------+

This function can be used to read the colour of a point in absolute
co-ordinates on the screen with reference to the specified window
channel (if any - default #1).

This function will work in MODE 4, 8 and
12 (on the THOR XVI, if you have v0.9+). The main limitation on this
function is that the point must appear within the specified window, so
x1 and y1 cannot exceed the width or height of the specified window (in
pixels), or be less than zero.

**NOTE**

Although PIXEL% will work wherever the screen base is located, prior to
v1.0, it assumed that a line of pixels takes 128 bytes - early versions
will not therefore work on higher resolutions.

**CROSS-REFERENCE**

:ref:`plot` and :ref:`draw` allow
you to draw points and lines on the screen. :ref:`ink`
gives details about the various colour values which may be returned
(this will be in the range 0...16).

--------------


