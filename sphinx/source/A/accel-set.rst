..  _accel-set:

ACCEL\_SET
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  ACCEL\_SET type,option                                           |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

Before the ST/QL Emulator can use an accelerator board plugged into the
Atari ST, it is necessary to use the command ACCEL\_SET to tell the
Emulator about the board and to activate the board.

There are currently five accelerator boards which are recognised by the
Emulator. Use the following values for type to tell the Emulator which
one is attached:

-  H - HyperCache (ProVME)
-  A - AdSpeed (ICD)
-  M - MegaSTE (ATARI)
-  P - HyperCache 030 (ProVME), 68030 Board
-  T - TT (ATARI)

If you have a 68030 board attached, the ST/QL Emulator can only use
external caches with this board.

The option parameter currently only has any effect when HyperCache is
attached. This can have the value 6 or 7 (default is 6). This is used to
specify which bit of the Atari's sound chip is used to switch
HyperCache. If you have the HyperCache 030 attached, you can pass the
parameter 0 (default) to enable external caches only, 1 to enable the
internal caches only or 2 to enable both external and internal caches.

**NOTE**

Unfortunately, due to the higher speed of the Atari ST with an
accelerator board enabled, you may encounter problems with the parallel
printer board - use the command PAR\_PULSE.

**CROSS-REFERENCE**

See also :ref:`accel-on`,
:ref:`accel-off` and
:ref:`accel-state`.

--------------


