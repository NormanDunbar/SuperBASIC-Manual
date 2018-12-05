..  _win-base:

WIN\_BASE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_BASE [(#channel)]                                           |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This function returns the start address of the definition block for the
specified window (default #1). If an error occurs WIN\_BASE returns the
appropriate QDOS error code, eg. -15 if the channel does not apply to a
window or -6 if the channel is not open.

**Example**

Some information about the internal structure of QDOS is necessary to
make use of WIN\_BASE from SuperBASIC. This function returns the PAPER
background colour of a window::

    100 DEFine FuNction GET_PAPER (winchan)
    110   IF WIN_BASE(#winchan)<0 THEN
    120     PRINT#0,"GET_PAPER: ";: REPORT #0, WIN_BASE(#winchan)
    130     PAUSE 800: STOP
    140   END IF
    150   RETurn PEEK(WIN_BASE(#winchan)+68)
    160 END DEFine GET_PAPER

**NOTE**

The Window Manager changes the structure of window definition blocks.

**CROSS-REFERENCE**

:ref:`sys-base`, :ref:`set`

--------------


