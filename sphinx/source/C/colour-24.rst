..  _colour-24:

COLOUR\_24
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_24 [#ch]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_24 is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the QXL and QPC, providing a good graphics card is installed.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

This command is similar to COLOUR\_PAL, but allows you to specify
colours directly using the 24 bit colour mode, thus allowing 16777216
(2^24) colours on screen at the same time.

Although the command does work on hardware which does not support a 24
bit graphics mode, the specified colours have to be adapted to fit into
the memory available for each pixel (eg 8 or 16 bits). This can cause
inaccuracies and unpredictable results - COLOUR\_NATIVE is preferable in
such circumstances.

**CROSS-REFERENCE**

Refer to :ref:`colour-pal` and
:ref:`colour-native` for more details.

:ref:`palette-ql`,
:ref:`palette-8` and
:ref:`bgcolour-24` all use the 24 bit table
to describe colours.

--------------


