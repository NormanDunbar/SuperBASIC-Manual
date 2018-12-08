..  _accel-on:

ACCEL\_ON
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  ACCEL\_ON                                                        |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

The ST/QL Emulator supports several of the accelerator boards which can
be plugged into the Atari ST computer, thus allowing much greater
operational speed. This command both enables the 16MHz mode on the Atari
ST and tells the attached accelerator board to use its memory cache (if
built in).

**NOTE**

This and the other ACCEL\_... commands will be ignored unless you have
previously used ACCEL\_SET to define the type of accelerator board
attached to the Atari ST.

**CROSS-REFERENCE**

:ref:`accel-off` turns off the 16MHz mode (if
possible) and also tells the accelerator board that it should no longer
use its memory cache. Also see
:ref:`accel-set`.

