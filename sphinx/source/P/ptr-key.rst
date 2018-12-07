..  _ptr-key:

PTR\_KEY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_KEY cursor, edge                                            |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE (DIY Toolkit - Vol I)                                     |
+----------+-------------------------------------------------------------------+

Normally DIY Toolkit's mouse driver will enable you to control the
mouse pointer on screen. This mouse pointer is however, not the one used
by the Pointer Environment (therefore the mouse cannot be used to
control programs written specifically for the Pointer Environment except
in cursor emulation mode) and you need a separate program to run in the
background which will display a symbol to show the position of the mouse
on screen.

Th PTR\_KEY command allows you to specify whether the
serial mouse driver should emulate the cursor keys (instead of the
pointer), which allows it to operate software such as word processors.

To emulate the cursor keys, cursor should be 1 - to emulate the pointer
again, set cursor to 0.

The DIY Toolkit mouse driver is actually better
than the SERMouse driver in this respect in that the mouse does not
automatically switch back into Pointer Mode when you leave the program
(see SERMCUR). Then again, you cannot switch between the two modes using
the mouse buttons, or control Pointer Environment programs...

The second parameter expected by this command is used to specify what should happen
to the cursor (or pointer) at the edge of the screen - if edge=1, moving
the cursor or pointer over the edge of the screen will make it re-emerge
on the opposite edge (a wrapping effect). edge=0 disables this.

**CROSS-REFERENCE**

See :ref:`ptr-inc` also. Also see
:ref:`ptr-on` and
:ref:`sermptr`
