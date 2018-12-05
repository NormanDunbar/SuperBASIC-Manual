..  _flash:

FLASH
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FLASH [#ch,] switch                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command turns on or off flashing in the specified window channel
(default #1). Switch can only have the values 0 (to enable flashing) and
1 (to turn flashing on).

This command will only have any effect in MODE
8.

If flashing is enabled, then any characters PRINTed to the given
window afterwards will be shown to flash - it is first written out as
normal, but then the parts of the character which would normally be
shown in the current INK colour will alternate with the colour of the
background.

The colour of the background can in fact be different for
each row of pixels - this is calculated by the colour of the left-most
pixel on each row for each character PRINTed.

**Example**

This short listing shows the effect of the FLASH command - note that
the display is not actually changed back to its original form.

::

    100 PAPER 2: INK 1
    120 CSIZE 3,1: MODE 8: CLS
    130 FOR i=0 TO 50: LINE 80+i,80 TO 15+i,10
    140 INK 7: CURSOR 100,120
    150 OVER 1: FLASH 1: PRINT 'This is flashing'
    160 CSIZE 1,0: FLASH 0

**NOTE 1**

This command only affects characters PRINTed to the screen after the
FLASH 1. There is no effect on graphics commands, or BLOCK or LINE.

**NOTE 2**

Spurious results may occur if you write over part of a flashing
character (with OVER -1).

**NOTE 3**

This command does not work on the Amiga-QDOS Emulator or ST/QL
Emulators.

**CROSS-REFERENCE**

Please also refer to :ref:`under`,
:ref:`over` and :ref:`print`.
:ref:`mode` resets the
:ref:`flash` mode to off.

--------------


