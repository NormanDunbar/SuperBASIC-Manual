..  _atari:

ATARI
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ATARI                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

On the Atari QL-Emulator, this command switches to Atari mode.
Naturally, on other machines, it has no effect. It will also fail if a
QL ROM was found at the start address of the ROM-TOS ($FC0000) - it is
possible to load QDOS to that address.

**NOTE**

The FN Toolkit (pre v1.04) contained a function of the same name which
had a different effect - this has now been renamed QuATARI (see below).

**WARNING**

This command will most probably fail on the latest ST/QL drivers.

**CROSS-REFERENCE**

See :ref:`quatari`.

--------------


