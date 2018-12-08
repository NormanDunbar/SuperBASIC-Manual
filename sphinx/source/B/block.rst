..  _block:

BLOCK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BLOCK [#channel,] width, height, x, y, colour                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command draws a block of size width x height at position x,y of the
given colour in the specified window (default #1). Both the position and
the block size are given in absolute pixel co-ordinates, with the
maximum ranges specified by the physical size of the window.

This means that for example, in a window which is defined as
448x200a32x16, the maximum block which can be drawn is a block of size
448 x 200 in position (0,0). You can also use OVER to produce other
effects with BLOCK.

As with other graphics commands, the colour can be made up of up to
three parameters, giving the background, contrast and stipple pattern
(composite colours).


**Example**

A program printing out the set of numbers 1 to 100 and then quickly
recolouring the two halves of the window:

::

    100 WINDOW 300,60,102,56
    110 PAPER 0: CLS
    120 FOR i=1 TO 100: PRINT !i!
    130 OVER -1
    140 BLOCK 150,60,0,0,7
    150 BLOCK 150,60,150,0,2
    160 OVER 0


**NOTE 1**

Some ROMs (not SMS) will allow you to specify blocks which lie partly
outside of a window without reporting the error 'Out of Range'. However,
this can also crash some ROMs!


**NOTE 2**

Odd values for width and x are always rounded down to an even number
(eg. 23 pixels wide becomes 22 pixels). This is to ensure compatibility
between MODE 4 and MODE 8. The only problem is that you cannot specify a
block one pixel wide, or even have a gap of one pixel between two
blocks.


**NOTE 3**

Unless you have a Minerva ROM or SMS, you cannot draw a block 512 pixels
wide - you need to use two adjacent blocks instead!


**NOTE 4**

BLOCK provides an extremely quick way of drawing horizontal or vertical
lines on screen.


**MINERVA NOTE**

Early versions of Minerva (pre v1.83) contained code to ensure that the
given block would appear wholly within the specified window. However,
later versions had to be altered to ensure compatibility with certain
programs. These later versions allow width, height, x and y to be within
the range -32768...32767 - only that part of the block (if any) which
appears in the given window will be drawn!

For example:

BLOCK 200,10,-20,255,7 has the same effect as:

BLOCK 180,1,0,255,7


**CROSS-REFERENCE**

:ref:`ink` contains information concerning composite
colours.

