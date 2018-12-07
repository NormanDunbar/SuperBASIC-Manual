..  _recol:

RECOL
=====

+----------+--------------------------------------------------------------------------+
| Syntax   | RECOL [#ch,] black,blue,red,magenta,green,cyan,yellow,white (MODE 8)  or |
|          |                                                                          |
|          | RECOL [#ch,] black,1,red,3,green,5,white,white (MODE 4)                  |
+----------+--------------------------------------------------------------------------+
| Location | QL ROM                                                                   |
+----------+--------------------------------------------------------------------------+

This command recolours all individual pixels in the specified window
(default #1).

At least eight parameters must be specified, representing
each of the colours available in MODE 8.

Each parameter must then have a
value in the range 0..8 representing how that colour pixel is to be
recoloured.

The rather odd syntax for use in MODE 4 is due to a slight
apparent bug in the RECOL command which means that on some
implementations the parameter which would normally represent the colour
to replace yellow on screen has to be used to specify the colour to
replace white.

**Example**

A simple demonstration program which recolours a circle randomnly::

    100 WINDOW 448,200,32,16
    110 PAPER 0:CLS:INK 7
    120 SCALE 100,0,0
    130 REPeat loop
    140   CIRCLE 75,50,20
    150   new_col=RND(1 TO 6)
    160   RECOL 0,1,2,3,4,5,6,new_col
    170 END REPeat loop

Note how this only works in MODE 8 (except on SMS): to get it to work
in MODE 4, you would need to alter line 160 to::

    160 RECOL 0,1,2,3,4,5,new_col,new_col

**NOTE 1**

Do not forget that the value of each parameter is taken to be the new
colour, therefore if RECOL is to have no effect at all, you will need to
use::

    RECOL 0,1,2,3,4,5,6,7

and not::

    RECOL 0,0,0,0,0,0,0,0

as you might at first think (the latter turns the whole window to
black!).

**NOTE 2**

This command did not work on ST/QL Emulators prior to Level D-05
drivers.

**CROSS-REFERENCE**

:ref:`ink`, :ref:`fill` See also
:ref:`w-swop`,
:ref:`set-red` and
:ref:`set-green`.

