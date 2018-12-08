..  _move-position:

MOVE\_POSITION
==============

+----------+-------------------------------------------------------------------+
| Syntax   | MOVE\_POSITION #channel, relative\_position                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This is a similar  procedure to :ref:`abs-position`, but the file pointer is set to a position relative to the current one.  The direction given can be positive to move forward in the file, or negative to move backwards. The channel must of course be opened to a file on a directory  device.  If the position given would take you back to before the start of the file, the position is left at the start, position 0.  If the move would take you past the end of file, the file is left at end of file.

After a MOVE\_POSITION command, the next access to the given channel, whether read or write, will take place from the new position.


**EXAMPLE**

::

    MOVE_POSITION #3, 0

moves the current file pointer on channel 3 to the start of the file.

::

    MOVE_POSITION #3, 6e6

moves the current file pointer on channel 3 to the end of the file.


**CROSS-REFERENCE**

:ref:`abs-position`.

