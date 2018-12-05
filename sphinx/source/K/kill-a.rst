..  _kill-a:

KILL\_A
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  KILL\_A                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command forces everything which can be accessed from SuperBASIC to
be cleared, killed or removed: Jobs, file definition blocks (except if
Qjump's Hotkey System is present), variables, the DATA pointer, the
common heap and all channels are closed. On an Atari QL-Emulator and
under SMS, the buffer for the serial and parallel port is also cleared.

**WARNING**

Be very careful! All data will be lost. Avoid this command if you can:
it is more like a safe emergency break.

**CROSS-REFERENCE**

:ref:`kill`, :ref:`killn`,
:ref:`kjobs`,
:ref:`del-defb`,
:ref:`clchp`.

--------------


