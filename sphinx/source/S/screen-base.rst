..  _screen-base:

SCREEN\_BASE
============

+----------+-------------------------------------------------------------------+
| Syntax   | screen = SCREEN\_BASE(#channel)                                   |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function is handy for Minerva  users, who have 2 screens to play with. The function returns the address of the start of the screen  memory for the appropriate channel.

If the returned address is negative, consider it to be a QDOS error code. (-6 means channel not open & -15 means not a SCR\_ or CON\_ channel.)

SCREEN\_BASE  allows you to write  programs  that need not make guesses about the whereabouts of the screen memory, or assume that if :ref:`ver-dlr` gives a certain result, that a Minerva ROM is being used, this may not always be the case. Regardless of the ROM in use, this function will always return the screen address for the given channel.

**EXAMPLE**

::

    PRINT HEX$(SCREEN_BASE(#0), 24)


-------



