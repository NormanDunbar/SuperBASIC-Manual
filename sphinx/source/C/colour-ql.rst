..  _colour-ql:

COLOUR\_QL
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_QL [#ch]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_QL is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the Q40/Q60, QXL, QPC and Aurora.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

This command is similar to COLOUR\_PAL, but selects an 8 colour mode,
with colours from 0...7 as per the original QL MODE 8 (although all 8
colours remain available for programs which presume MODE 4).

This can cause some slight incompatibility problems, due to programs
which presume that under MODE 4, INK 3 would produce Red (for example) -
under COLOUR\_QL it will now produce Magenta.

**NOTE 1**

The eight colours produced under COLOUR\_QL may be changed to allow any
colour supported by the hardware using the command PALETTE\_QL.

**NOTE 2**

MODE commands have no effect under the Extended Colour Drivers.

**CROSS-REFERENCE**

Refer to :ref:`colour-pal` for more details.

:ref:`palette-ql` includes a way of overcoming
the incompatibility problems with old :ref:`mode`\ .. 4  programs.

