..  _mouse-stuff:

MOUSE\_STUFF
============

+----------+-------------------------------------------------------------------+
| Syntax   | MOUSE\_STUFF [#ch,] hot$                                          |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This function adjusts the string that is stuffed into the keyboard queue when the middle mouse button is pressed (or both left and right buttons are pressed simultaneously). The string cannot be longer than two characters, but this is enough to trigger any hotkey, which in turn, can do almost anything.

**Example**

::

    MOUSE_STUFF '.'

Generates a dot if middle mouse button is pressed.

::

    MOUSE_STUFF CHR$(255) & '.'

Generates hotkey <Alt><.> which will activate whatever has been defined on that key combination.

