..  _screen-mode:

SCREEN\_MODE
============

+----------+-------------------------------------------------------------------+
| Syntax   | current_mode = SCREEN\_MODE                                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function can help in your programs where you need to be in a specific mode.  If you call this function you can find out if a mode change needs to be made or not.  As the :ref:`mode` call changes the mode for every program running in the QL, use this function before setting the appropriate mode.

The value returned can be 4 or 8 for normal QLs, 2 for Atari ST/QL Extended mode 4 or any other value deemed appropriate by the hardware being used. Never assume that your programs will only be run on a QL!

**EXAMPLE**

::

    1000 REMark Requires MODE 4 for best results so ...
    1010 IF SCREEN_MODE <> 4
    1020    MODE 4
    1030 END IF
    1040 :
    1050 REMark Rest of program ....

**CROSS-REFERENCE**

:ref:`mode`.


