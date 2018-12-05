..  _qpc-qlscremu:

QPC\_QLSCREMU
=============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_QLSCREMU value                                               |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Enables or disables the original QL screen emulation. When emulating the original screen, all memory write accesses to the area $20000-$207FFF are intercepted and translated into writes to the first 512x256 pixels of the big screen area. If the screen is in high colour mode, additional colour conversion is done.

Possible values are:

- -1: automatic mode
- 0: disabled (default)
- 4: force to 4-colour mode
- 8: force to 8-colour mode

When in QL colour mode, the emulation just transfers the written bytes to the larger screen memory, i.e. when the big mode is in 4-colour mode, the original screen area is also treated as 4-colour mode. In high colour mode however, the colour conversion can do both modes. In this case, you can pre-select the emulated mode (parameter = 4 or 8) or let the last issued :ref:`mode` call decide (automatic mode). Please note that that automatic mode does not work on a per-job basis, so any job that issues a :ref:`mode` command changes the behaviour globally.

Please also note that this transition is one-way only, i.e. bytes written legally to the first 512x256 pixels are not transferred back to the original QL screen (in the case of a high colour screens this would hardly be possible anyway). Unfortunately, this also means that not all old programs will run perfectly with this type of emulation. If you experience problems, start the misbehaving application in 512x256 mode.

--------------


