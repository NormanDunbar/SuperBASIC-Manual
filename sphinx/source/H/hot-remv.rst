..  _hot-remv:

HOT\_REMV
=========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_REMV (key$)  or                                             |
|          |                                                                  |
|          | HOT\_REMV (Thingname$)                                           |
+----------+------------------------------------------------------------------+
| Location |  HOTKEY II                                                       |
+----------+------------------------------------------------------------------+

The HOT\_REMV function allows you to remove the hotkey definition
associated with the specified key or, if you prefer, the hotkey
associated with the specified Thing. If the hotkey refers to a program
which has been loaded into the common heap (eg. with HOT\_CHP), then
this area of the common heap will also be released.

**NOTE**

Prior to v2.26 of the Hotkey System 2, if key$ was an upper case letter,
then any hotkey associated with the lower case letter would also be
removed.

**CROSS-REFERENCE**

See :ref:`hot-off` for further details.

