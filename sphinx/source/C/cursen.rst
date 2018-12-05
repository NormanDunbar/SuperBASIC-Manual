..  _cursen:

CURSEN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CURSEN [#ch]                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, QSOUND                                     |
+----------+-------------------------------------------------------------------+

If a program is to multitask without the assistance of the Pointer
Interface, it is necessary to give that program an active cursor so that
the user can switch to the program using the key <CTRL><C>, which alters
the active keyboard queue.

Unless a program has an active cursor, it cannot accept input from the
keyboard by the use of commands such as PAUSE, INKEY$ and INPUT.

The command CURSEN enables the cursor in the given channel, which must
be either a scr or con channel. If no channel is specified, the default
is #1.

Once the cursor is enabled, a red block will appear at the current text
cursor position in the given channel. This block will begin to flash
when the cursor is 'active' (ie. expecting input).

**MINERVA NOTE**

Minerva's System Xtensions allow you to alter the attributes of the text
cursor, by using the command POKE !124!51,x where x is in the format of:
RRRRSCCC, where the top 4 bits of x (RRRR) determine the cursor flash
rate, the bottom three bits (CCC) determine the colour of the cursor and
the fourth bit (S) determines whether the cursor appears as a solid
block or an underline.

You can actually get an invisible cursor by using the command POKE
!124!51,0. Unfortunately though, this sets the cursor attributes for all
cursors which are enabled, rather than just for the current Job.

**CROSS-REFERENCE**

:ref:`keyrow` reads keys without an active cursor.
See :ref:`curdis` also.

--------------


