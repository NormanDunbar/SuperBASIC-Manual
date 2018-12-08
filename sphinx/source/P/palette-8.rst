..  _palette-8:

PALETTE\_8
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PALETTE\_8 [#ch,] start, true\_colour1 \*[,true\_colourx]\*      |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

This command is similar to PALETTE\_QL, except that it allows you to
redefine all 256 colours available under COLOUR\_PAL.

As with
PALETTE\_QL, start is the number of the first colour to change, followed
by each of the new colours described in 24 Bit Colour Mode. A valid
window channel must also be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

On hardware
with a true palette map (most PCs), this command will affect all
programs, including information already displayed on screen. However, on
all other hardware, most notably the Q40 and Q60, existing information
will remain unaffected.

**Examples**

::

    PALETTE_8 4, $FFB6DB

makes the computer use PINK, instead of BLUE when
INK 4 (PAL Colour Value) is used within a program.

::

    PALETTE_8 5, $B6FFFF, $929200

will change INK 5 to Light Blue (from Magenta) and INK 6
to Mustard (from Yellow).

**NOTE 1**

This command will not have any effect on Aurora, which only provides 256
colours to choose from. It therefore *may not* be implemented on the
Aurora version of SMSQ/E.

**NOTE 2**

The problem with using 24 bit values is that they have to be trimmed to
fit into the native colour scheme on the computer in use - as a result,
although the same 24 bit colour value is specified, the resultant colour
will be slightly different on QPC and Q40.

**CROSS-REFERENCE**

See :ref:`palette-ql` and
:ref:`colour-pal` for more details.

