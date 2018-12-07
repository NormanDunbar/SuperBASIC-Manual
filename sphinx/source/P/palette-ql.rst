..  _palette-ql:

PALETTE\_QL
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  PALETTE\_QL [#ch,] start, true\_colour1 \*[,true\_colourx]\*     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

This command allows you to redefine the eight colours used by the
Extended Colour Drivers to display COLOUR\_QL. A valid window channel
must be open, default #1 (or #0 on a SBASIC with only #0 open), although
one may also be supplied as #ch.

Start is the number of the first colour
to change, followed by each of the new colours described in 24 Bit
Colour Mode. On hardware with a true palette map (most PCs), this
command will affect all programs, including information already
displayed on screen. However, on all other hardware, most notably the
Q40 and Q60, existing information will remain unaffected.

**Example 1**

::

    PALETTE_QL 4,$FFB6DB

makes the computer use PINK instead of GREEN when
INK 4 (QL Colour Value) is used within a program.

::

    PALETTE_QL 5,$B6FFFF,$929200

will change INK 5 to Light Blue (from Cyan) and INK 6 to Mustard (from Yellow).

**Example 2**

Many programs written with MODE 4 in mind, presume that INK 3
is the same as INK 2 (for example). However, under COLOUR\_QL, even
MODE 4 programs can access the standard MODE 8 colours, therefore INK 3
becomes MAGENTA. To overcome this problem, use the following routine::


    100 red=255*65536+100:REMark $FF0064 - red and a bit of blue
    110 blue=255*256+155: REMark $00FF9B - green and the rest of blue
    120 white=blue+red:   REMark $FFFFFF
    125 REMark - Now change all 8 colours, starting at INK 0
    130 PALETTE_QL 0,0,0,red,red,blue,blue,white,white

**NOTE**

The problem with using 24 bit values is that they have to be trimmed to
fit into the native colour scheme on the computer in use - as a result,
although the same 24 bit colour value is specified, the resultant colour
will be slightly different on QPC, Q40 and Aurora.

**CROSS-REFERENCE**

:ref:`colour-ql`, :ref:`ink`,
:ref:`palette-8` Also refer to Appendix 16
which lists the first 256 24 Bit Colours.

