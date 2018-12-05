..  _scr-save:

SCR\_SAVE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SCR\_SAVE flag                                                   |
+----------+-------------------------------------------------------------------+
| Location |  MutiBASIC v4.0+ (DIY Toolkit - Vol M)                            |
+----------+-------------------------------------------------------------------+

This command is used to specify whether the current screen display and
mode should be stored along with the program when the UNLOAD or RESAVE
commands are used. The setting depends on the value of flag:

- 0 Do not store the screen display and mode.
- 1 (This is the default). Store the screen display and mode so that it is redisplayed when RELOAD is used.
- -1 This tells RELOAD to ignore the screen details (if any) stored with the program - use SCR\_SAVE 1 if you want to see them.

**NOTE**

Beware that this toolkit only supports 512x256 resolution and expects
the screen base to be at 131072.

**CROSS-REFERENCE**

:ref:`unload` contains more details about this
toolkit.

--------------


