..  _reload:

RELOAD
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELOAD program\_name                                             |
+----------+-------------------------------------------------------------------+
| Location |  MutiBASIC (DIY Toolkit - Vol M)                                  |
+----------+-------------------------------------------------------------------+

This command is the opposite to UNLOAD in that it fetches the program
which is stored in memory and loads it into the current SuperBASIC
interpreter. If the screen mode has been stored with UNLOAD (or RESAVE),
then when the program is loaded, RELOAD checks if the current display
mode is the correct one and if not will alter it (although see below).

**NOTE 1**

See the various notes and warnings given for UNLOAD.

**NOTE 2**

Any commands which appear after RELOAD will be ignored.

**NOTE 3**

If you RELOAD a program which has a stored screen in a different mode to
the current display mode, then the system can become confused if the
Pointer Environment or Speedscreen is loaded. Therefore you should
always ensure that the correct MODE is set before you RELOAD a program.

**NOTE 4**

If the specified file is not a file you stored with UNLOAD or does not
exist, an error will be generated. You may also get the error 'Channel
not Open' if the program uses a channel which was OPEN when the program
was UNLOADed but is no longer OPEN.

**CROSS-REFERENCE**

:ref:`scr-save` allows you to dictate whether
the screen display and mode should be stored together with the program.
:ref:`remove` allows you to remove a program stored
in memory with this command. See also :ref:`resave`
and :ref:`qload`.

--------------


