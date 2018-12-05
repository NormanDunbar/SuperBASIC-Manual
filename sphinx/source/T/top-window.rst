..  _top-window:

TOP\_WINDOW
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  TOP\_WINDOW [#ch]                                                |
+----------+-------------------------------------------------------------------+
| Location |  all THORs                                                        |
+----------+-------------------------------------------------------------------+

This command is similar to the PICK command provided by Qjump's QPTR
package on the QL. This command brings the specified window (default #1)
to the top of the display pile. Under the THOR's windowing system (when
this is enabled), as with the Pointer Environment, a program cannot
access a window which is partly or fully hidden from view. This command
allows the program to force the given window to the top of the pile,
thus allowing it to be seen on screen and therefore open to access. If
possible, the keyboard queue is also connected to the window, so it is
as if the Job has been 'picked' using the keys CTRL C.

**CROSS-REFERENCE**

:ref:`window` allows you to re-position a window.
:ref:`pie-on` allows programs to continue even
though their windows are buried under the Pointer Interface.
:ref:`pick-pct` is similar. :ref:`poke` SYS\_VARS+133 allows you to
enable / disable the THOR's windowing system.

--------------


