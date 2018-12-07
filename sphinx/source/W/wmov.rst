..  _wmov:

WMOV
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WMOV [#] channel [!]                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX (v20+)                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to interactively alter the size and position of the specified Window
channel by using the following keys:

- <cursor keys>  Move the Origin.
- <SHIFT><cursors>  Alter the size of the Window. (See below)
- <ESC>  Leave the procedure - do not alter Window size and position.
- <ENTER>  Accept the new size and position.

Note that <ALT> plus the <cursor keys> or <SHIFT><cursors> allows you to move more quickly.

You can use this
command to re-size a specified BASIC window (use # before channel) or a
window used by another Job. If you wish to do the latter, then you will
need to omit the # and channel must be the QDOS Channel number (see
CHANNELS). PEX22 onwards ensured that when you use this command to alter
the size and position of the primary window of a job (set with OUTL),
the sizes and relative origins of all secondary windows are preserved.
PEX22 onwards also allows you to place an exclamation mark (!) after the
channel number, in which case the window sizes cannot be altered - only
their position.

**WARNING**

Do not press <CTRL><C> or change Jobs whilst using this command - it can
crash the system!!

**CROSS-REFERENCE**

Also see :ref:`wtv`, :ref:`wmon`,
:ref:`pick-pct`, and :ref:`outl`.

