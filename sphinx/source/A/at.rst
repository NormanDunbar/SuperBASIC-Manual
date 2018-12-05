..  _at:

AT
==

+----------+------------------------------------------------------------------+
| Syntax   | AT [#ch,] row, column  or                                        |
|          |                                                                  |
|          | AT [#ch,] column,row (pre AH ROMs only)                          |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

This command sets the current print position in the given window
(default #1) to the given row and column number. The top left hand
corner of any window is always the position (0,0), however, the maximum
values of the row and column numbers depends on both the size of the
window and the current character size. Anything outside of this will
give the error 'Out of Range' (-4).

Unlike the PRINT parameter TO, this command does not print any spaces on
screen, thus allowing you to place text precisely on screen without
deleting any other parts of the screen.

Unfortunately for users who learnt to program on early versions of
Sinclair BASIC (on the ZX81 or Spectrum), this command is implemented
differently.

Some implementations of BASIC allow you to set the print position from
within the PRINT command, for example:

PRINT AT 3,5;'Hello'

On the QL, you would need the line:

AT 3,5: PRINT 'Hello'

**Example**

A program which uses the AT command to create an interesting effect on
screen. This will not work on pre JS ROMs as it relies upon the WHEN
ERRor command:

::

    1000 WHEN ERRor
    1010   IF ERR_OR THEN dir1=-dir1: y=y-2: RETRY 1070
    1020 END WHEN
    1025 :
    1030 MODE 4:WINDOW 448,200,32,16:CSIZE 0,0
    1040 x=0: dir1=1
    1050 FOR y=0 TO 63
    1060   AT x,y:PRINT 'Sinclair QL'
    1070   x=x+dir1
    1080 END FOR y

**NOTE**

On early QL ROMs (pre AH), the parameters were mixed up meaning that the
syntax was AT column,row. This can of course create many problems in
uncompiled SuperBASIC, however, there should not be many of these
machines left.

If you do have one of these early machines, it is recommended that you
do update the ROM.

**CROSS-REFERENCE**

:ref:`csize` sets the current character size for the
given window

:ref:`window` alters the physical size of a given
window.

:ref:`cursor` allows you to set the print position
more exactly.

:ref:`print` actually prints things on screen at the
current print position.

:ref:`ver-dlr` allows you to check the ROM version.

Also see :ref:`left`.

--------------


