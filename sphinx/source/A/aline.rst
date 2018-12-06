..  _aline:

ALINE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ALINE x1,y1 TO x2,y2, Colour                                     |
+----------+-------------------------------------------------------------------+
| Location |  Shape Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command quickly draws a line between the specified absolute, window
independent co-ordinates, (x1,y1) and (x2,y2), on the screen. ALINE uses
XOR mode, which means that the line can be removed without destroying
the contents of the screen by drawing exactly the same line again. -
This does however mean that the colour of the line as it appears on
screen may not be the same as the specified parameter (see OVER -1).

**Example**

The procedure HAIRCROSS x,y allows you to move a cross wire around the
screen with the cursor keys, to alter the values of x and y. Press
<SPACE> to make x and y equal the new values, or press <ESC> to keep the
old values.

::

    100 DEFine PROCedure HAIRCROSS (px,py)
    110  LOCal Size,Key,Stepp,old_px,old_py
    120  Size=31 : old_px=px : old_py=py
    140  REPeat Move_it
    150    CROSS px,py
    160    REPeat Wait_for_key
    170      Key=KEYROW(1): Stepp=4*(KEYROW(7))+1
    180      IF Key THEN EXIT Wait_for_key
    190    END REPeat Wait_for_key
    200    CROSS px,py
    210    IF Key&&2 THEN px=px-Stepp
    220    IF Key&&16 THEN px=px+Stepp
    230    IF Key&&4 THEN py=py-Stepp
    240    IF Key&&128 THEN py=py+Stepp
    250    IF px<Size THEN px=Size
    260    IF px>511-Size THEN px=511-Size
    270    IF py<Size THEN py=Size
    280    IF py>255-Size THEN py=Size
    290    SELect ON Key
    300      =64: EXIT Move_it
    310      =8: px=old_px: py=old_py
    320          EXIT Move_it
    330    END SELect
    340  END REPeat Move_it
    350 END DEFine HAIRCROSS
    360 :
    370 DEFine PROCedure CROSS (ax,ay)
    380  ALINE ax-Size,ay-Size TO ax+Size,ay+Size ,7
    390  ALINE ax+Size,ay-Size TO ax-Size,ay+Size ,7
    400 END DEFine CROSS

**NOTE 1**

ALINE assumes that the screen starts at $20000 and will therefore not
work on Minerva's / Amiga QDOS's / QDOS Classic's second screen or on
higher resolution displays.

**NOTE 2**

ALINE also assumes that the screen measures 512x256 pixels and cannot
therefore work on higher resolution screens.

**NOTE 3**

ALINE only works in MODE 4.

**CROSS-REFERENCE**

:ref:`draw` has the same syntax as
:ref:`aline` but does not work in XOR
mode.\ :ref:`draw` is also able to draw lines on
screens stored in memory.

:ref:`line` and :ref:`line-r`
are much more flexible.

