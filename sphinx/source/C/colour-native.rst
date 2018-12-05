..  _colour-native:

COLOUR\_NATIVE
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_NATIVE [#ch]                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_NATIVE is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the Q40/Q60, QXL, QPC and Aurora.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

This command is similar to COLOUR\_PAL, but allows you to use 256
colours on Aurora, or 65536 colours on QXL, QPC and the Q40/Q60, by
selecting the native colour mode of the hardware.

Colour parameters supplied to commands such as INK are defined in native
colours and therefore their effect will depend upon the hardware itself
(Appendix 16 contains details of the first 256 colours and their Native
Colour Values in decimal, hexadecimal and binary for use with the INK
command or similar).

**NOTE**

MODE commands have no effect under the Extended Colour Drivers.

**CROSS-REFERENCE**

Refer to :ref:`colour-pal` for more details.

--------------


