..  _scr-refresh:

SCR\_REFRESH
============

+----------+-------------------------------------------------------------------+
| Syntax   |  SCR\_REFRESH address                                             |
+----------+-------------------------------------------------------------------+
| Location |  SuperWindow Toolkit                                              |
+----------+-------------------------------------------------------------------+

This command copies a screen (or a portion of a screen) which has been
saved in memory at the specified address using SCR\_STORE back to the
same position on the visible display screen.

**NOTE**

It is unknown at present whether these commands check for the start
address of the screen and its dimensions and therefore they may not work
on some higher resolutions. Unfortunately, we do not have access to the
toolkit at present.

**CROSS-REFERENCE**

:ref:`scr-store` stores a window or rectangle
taken from the display. See also :ref:`w-show` and
:ref:`refresh`.

--------------


