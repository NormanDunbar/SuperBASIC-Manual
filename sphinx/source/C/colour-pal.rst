..  _colour-pal:

COLOUR\_PAL
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_PAL [#ch]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_PAL is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the Q40/Q60, QXL, QPC and Aurora.

This command requires the Extended Colour Drivers to have been loaded
when SMSQ/E started (set by configuration or chosen from the start-up
menu on QPC). It will not have any effect upon programs already loaded
into the system.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

COLOUR\_PAL selects the PAL colour mode, allowing 256 colours to be
used. After using this command, the effect of the colour parameters
supplied to commands such as INK will depend upon the table which
appears in Appendix 16 - use the PAL colour value given for each colour
(this is hardware independent).

As a result, code such as that given in the example below is required to
check on the colour scheme currently in use and adapt the program
accordingly.

**Example**

::

    100 REMark Make sure the program is in the right mode for Standard QL/Extended Colours
    110 col_sys%=0:h$=VER$
    120 IF RMODE=8:MODE 4
    130 IF RMODE=16:col_sys%=1:REMark Aurora - Extended Colour Drivers
    140 IF RMODE=32:col_sys%=3:REMark QXL/QPC - Extended Colour Drivers
    150 IF RMODE=33:col_sys%=2:REMark Q40 - Extended Colour Drivers
    160 :
    170 REMark Select Appropriate colour scheme
    180 IF h$='HBA':IF col_sys%<>0:COLOUR_PAL
    190 SELect ON col_sys%
    200   =0:BLACK=0:WHITE=7:RED=2:GREEN=4:       REMark Four colours available
    210   =REMAINDER :BLACK=0:WHITE=1:RED=2:GREEN=3:REMark 256 colours available
    220 END SELect
    230 PAPER BLACK:INK GREEN

**NOTE 1**

The 256 colours produced under COLOUR\_PAL on non-Aurora machines may be
changed to allow any 24-bit colour using the command PALETTE\_8. This
will not work on Aurora, which has display hardware limited to 256
colours.

**NOTE 2**

MODE commands have no effect under the Extended Colour Drivers. RMODE
will always report 16 on Aurora, 32 on QXL/QPC and 33 on the Q40/Q60 if
the Extended Colour Drivers are in use.

**CROSS-REFERENCE**

Refer to Appendix 16 and :ref:`ink` for more details.

:ref:`colour-ql`,
:ref:`colour-native` and
:ref:`colour-24` are all similar.

:ref:`palette-ql` and
:ref:`palette-8` affect colour palettes.

:ref:`bgcolour-ql` and
:ref:`bgcolour-24` can be used to alter the
desktop colour of the main screen.

DISP\_COLOUR can be used to switch
between Extended Colour Drivers and the Standard Colour Drivers.

--------------


