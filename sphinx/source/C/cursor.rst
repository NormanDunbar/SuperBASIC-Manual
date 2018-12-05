..  _cursor:

CURSOR
======

+----------+-------------------------------------------------------------------+
| Syntax   | CURSOR [#channel,] [grx, gry,] x,y or                             |
|          |                                                                   |
|          | CURSOR [#channel,] flag (Btool only)                              |
+----------+-------------------------------------------------------------------+
| Location | QL ROM, Btool                                                     |
+----------+-------------------------------------------------------------------+


The CURSOR command allows you to set the text cursor to a specific
position in the given window (default #1). Any text which is then
printed will appear with the given position at its top left corner.

The values x and y specify the position in pixel co-ordinates relative
to the origin of the specified window (eg. if the window #1 was defined
as scr\_448x200a32x16, the command CURSOR 224,100 will set the text
position to the exact centre of the window).

However, for the more adventurous, CURSOR can take an additional two
parameters which allow you to mix text and graphics on a given window
more easily. This sets the text cursor to the graphics co-ordinate
(grx,gry) and then uses the x and y parameters to specify a relative
pixel offset from this graphics co-ordinate (a positive value of x moves
the text cursor to the right, a negative value to the left; whereas a
positive value of y moves the text cursor down, a negative value up).

The second variant only works with the Btool Toolkit. This allows you to
enable or disable the cursor in the specified window (default #1), by
specifying a flag of 1 to enable the cursor or 0 to disable the cursor.

**Example**

This program shows all the 45 degree angles in a circle:

::

    100 MODE 4:WINDOW 448,200,32,16
    110 PAPER 0:INK 7:CLS
    120 SCALE 200,-150,-100
    130 FOR i=0 TO 315 STEP 45
    140   INK 7:LINE 0,0 TO SIN(RAD(i))*50,COS(RAD(i))*50
    150   xoff=0:yoff=0
    160   SELect ON i
    170     =0:xoff=-4:yoff=-9
    180     =45:yoff=-9
    190     =90:yoff=-4
    200     =180:xoff=-10
    210     =225:xoff=-20
    220     =270:xoff=-20:yoff=-4
    230     =315:xoff=-20:yoff=-9
    240   END SELect
    250   INK 4:CURSOR SIN(RAD(i))*50,COS(RAD(i))*50,xoff,yoff
    260   PRINT i
    270 END FOR i

**NOTE 1**

On pre MG ROMs, the CURSOR command only allows a maximum of four
parameters, which means that you can only use grx, gry, x and y on the
default channel. You can however use commands such as CURSOR #3,200,40,3
- although this is not supported on Minerva (pre v1.98) and SMSQ/E and
should be avoided! If you specify a fifth parameter, a 'Bad Parameter'
error will be reported. The Btool variant fixes this as does SMS, MG
ROMs and Minerva. Compiling with Q-Liberator does not prevent this
error.

**NOTE 2**

The graphics positioning did not work on ST/QL Emulators with Drivers
prior to Level D-15 (or E-15).

**NOTE 3**

Compilers will not accept the second syntax.

**NOTE 4**

As from SMS v2.74 CURSOR limits grx to even positions to make in
compatible with MODE 8 and MODE 4 automatically.

**CROSS-REFERENCE**

Please refer to :ref:`print`,
:ref:`left` and :ref:`at`.

:ref:`cursen` is a more compatible means of
enabling a cursor.

--------------


