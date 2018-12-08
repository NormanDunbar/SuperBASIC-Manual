..  _scroll:

SCROLL
======

+----------+-------------------------------------------------------------------+
| Syntax   |  SCROLL [#ch,] distance [,area]                                   |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to move the contents of a given window (default
#1) up or down by a specified number of pixels (distance).

A positive
value for distance will move the contents of the window downwards,
whereas a negative distance will move them upwards.

As the contents are
moved, if they move outside of the limits of the window, they will be
lost. The space left by the movement of the window's contents, will be
filled with the current PAPER colour.

If you use the third parameter
(area), you can specify that only part of the window is to be moved, by
using the following values:

- 0 This is the default - move whole window.
- 1 Move the area above the text cursor line.
- 2 Move the area below the text cursor line.

If you wish to move other areas of a window, the
easiest method is to open another window over that part of the window
which you want to move, and then use SCROLL and/or PAN on that new
window (see example below).

**Example**

A short demonstration routine of SCROLL and PAN::

    100 MODE 4
    110 WINDOW 440,200,32,16: PAPER 2: CLS
    120 INK 7: CSIZE 3,1
    130 AT 0,6: PRINT 'QL KEYWORD MANUAL'
    140 OPEN #3,scr_448x200a32x16: PAPER#3,2
    150 AT 5,6: PRINT 'QL KEYWORD MANUAL'
    160 FOR i=1 TO 37
    170   WINDOW #3,40,200,432,16
    180   SCROLL #3,20
    190   PAUSE 5
    200   WINDOW #3,440,20,32,16
    210   PAN #3,40
    220   PAUSE 5
    230   WINDOW #3,40,200,32,16
    240   SCROLL #3,-20
    250   PAUSE 5
    260   WINDOW #3,440,20,32,196
    270   PAN #3,-40
    280   PAUSE 5
    290 END FOR i
    300 CSIZE 0,0

**NOTE**

QL ROMs (other than v6.41 of THOR XVI, SMS and v1.63/v1.64 of Minerva)
allow SCROLL to be used to access various direct TRAP #3 calls to the
operating system (as with PAN and CLS).

The first parameter to be
supplied represents the D1 parameter in machine code, whereas the second
parameter represents D0. In any case, both parameters must be integers
(ie. in the range -32768..32767).

Normally to find out number to give
D0, take the routine's D0 value and subtract 24 (eg. IOG.DOT=48,
48-24=24). However, if the routine's value is 24 or less, subtract 24
and then add this negative value to 128.

Some useful routines which can
be accessed are:

- SCROLL #3,0,121 moves the cursor to column 0 in #3 (IOW.SCOL, D0=$11)
- SCROLL 0,24 has the same effect as CLS 16, ie. it calls (IOG.DOT - D0=$30), which effectively carries out the command POINT 0,0.
- SCROLL x,17 sets the ink colour to x  (IOW.SINK,D0=$29)
- SCROLL #3,n%,42 sets the file pointer in #3 to n% (IOF.POSA,D0=$42)
- SCROLL #3,n%,43 should move the file pointer in #3 on n%  places (IOF.POSR,D0=$43)

Unfortunately, not all values for both
parameters will work on all ROMs and this is a hit and miss way of
programming the QL. Luckily, the wealth of Toolkits available should
mean that there is a legal means of accessing these routines, using
Toolkit keywords, including MTRAP and QTRAP.

**CROSS-REFERENCE**

:ref:`pan` allows you to move the contents of a window
sideways. :ref:`window` allows you to specify the
area of the screen which a window covers.
:ref:`io-trap` allows you to access machine code
routines directly. See also :ref:`qtrap`,
:ref:`btrap` and :ref:`mtrap`.

