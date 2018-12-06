..  _ink:

INK
===

+----------+------------------------------------------------------------------+
| Syntax   | INK [#ch,] colour  or                                            |
|          |                                                                  |
|          | INK [#ch,] colour1,colour2 [,pattern]                            |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

This command sets the ink colour used inside the given window ch
(default #1). Since the advent of the Extended Colour Drivers under
SMSQ/E v2.98+ the scope of colours accepted by this command has been
much enhanced and depends upon the colour mode selected for the current
program. As a result, the ink colour can be either a solid colour if the
first syntax is used (in which case colour can be any integer in the
range 0..16777215) or a composite colour made up of the three parameters
supplied in the second syntax (colour1 and colour2 must both be in the range dictated by the current MODE).

Luckily, SMSQ/E allows you to include binary and hexadecimal numbers
directly in programs (eg INK $f800) which may make the non-standard QL
colours easier to use. The way in which colours are handled depends upon
the operating system. On most systems, only the Standard QL Colour
Drivers are supported. However, SMSQ/E v2.98+ can be used to access
further Extended Colour Drivers by configuring SMSQ/E to start with them
loaded, or using the start-up screen on QPC.

STANDARD COLOUR DRIVERS
-----------------------

**MODE 4 and MODE 8**

This applies to standard QL operating systems, or can be set under
SMSQ/E v2.98+ with the command DISP\_COLOUR 0,800,600 or by altering the
configuration of the operating system. There are eight solid colours
which have the following values (although only four of these colours are
available in MODE 4):

+-------+---------------+---------------------------+
| Value | MODE 8 colour | MODE 4 colour             |
+=======+===============+===========================+
| 0     | black         | black                     |
+-------+---------------+---------------------------+
| 1     | blue          | black (should be avoided) |
+-------+---------------+---------------------------+
| 2     | red           | red                       |
+-------+---------------+---------------------------+
| 3     | magenta       | red (should be avoided)   |
+-------+---------------+---------------------------+
| 4     | green         | green                     |
+-------+---------------+---------------------------+
| 5     | cyan          | green (should be avoided) |
+-------+---------------+---------------------------+
| 6     | yellow        | white (should be avoided) |
+-------+---------------+---------------------------+
| 7     | white         | white                     |
+-------+---------------+---------------------------+

The values in MODE 4 which are marked
"should be avoided" can be used on standard QLs, but lead to
compatibility problems when run under the Enhanced Colour Drivers (see
below). Other integer values in the range 8 to 255 are allowed, but
these are generally 'composite' colours and repeats of other values.

EXTENDED COLOUR DRIVERS
-----------------------

The following is a description of the various colour modes available
under the Extended Colour Drivers provided by SMSQ/E v2.98+. These are
available once SMSQ/E is configured to use the Extended Colour Drivers.
DISP\_COLOUR can be used to switch between the standard and extended
colour drivers.

**QL Colour Mode**

This is selected with the command COLOUR\_QL and is the default when a
program is executed. For the purposes of INK, PAPER, STRIP
etc commands, it provides the same colours as under the Standard QL
Colour Mode (provided the standard colour=0 to colour=7
is used), except that MODE 4 programs can actually access all 8 colours
not just the standard 4. However, the actual colours which represent
each of the different values can be amended by changing the palette (see
PALETTE\_QL). This can be used, for example, to rectify programs which
display the wrong colours because they presume INK 3 would always be the
same as INK 2.

**8 Bit Colour Mode**

This is supported on the Aurora motherboard (not yet implemented) and
QPC, QXL and the Q40/Q60. It is selected with COLOUR\_PAL and allows
colour to be in the range 0...255. This is the PAL value and is hardware
independent - refer to Appendix 16 for a full list of the colours
available.

The colours which represent each of the 256 values allowed
can be amended by changing the palette (see PALETTE\_8). For this mode,
the INK parameter should be the PAL value listed in the table. If a
stipple is required, the two composite PAL colours will need to be
specified explicitly - see below.

**Native Colour Mode (8 or 16 bit colour)**

This should be supported on all implementations of SMSQ/E v2.98+ and is
selected with COLOUR\_NATIVE. The range supported by colour and the
effects all depend upon the display hardware currently in use. As a
result, under Aurora, it is similar to COLOUR\_PAL in that it only
supports 8 bit colours, but the colour is specified by the Native Colour
Value instead of the PAL value. On the QPC, QXL and Q40/Q60, it supports
65536 colours as standard. The value required for INK, PAPER, STRIP etc.
depends upon the hardware in use - look at the tables in Appendix 16 for
the appropriate hardware and then the Native Colour Value to use. It may
be easier to use hexadecimal or binary to specify the colour, for
example INK $F81F for magenta on QPC/QXL.

**24 Bit Colour Mode**

This is only supported on QPC (dependent on hardware). It is selected
with COLOUR\_24 and allows colour to be in the range 0..16777215. Due
the values possible in 24 bit colour mode, it is essential that
hexadecimal is used to describe colours. Colours are defined as a 3 byte
value representing a value for red, green and blue respectively. For
example, yellow would be INK $FFFF00.

**COMPOSITE COLOURS**

These are colours made up of either two or three values, for example::

    INK 2,7
    INK 1,7,2
    INK $F800,$FDBF,1

Depending upon the combinations, they may not be displayed correctly on
a television.


::

    INK colour1,colour2

This creates a composite colour made up of the two given colours in a checkerboard pattern (stipple 3).

::

    INK colour1,colour2,stipple

This creates a composite colour which is a mixture of the two given colours, and displayed in the given stipple pattern.

The values for stipple are:

+-------+--------------------+
| Value | Pattern            |
+=======+====================+
| 0     | Dots               |
+-------+--------------------+
| 1     | Horizontal stripes |
+-------+--------------------+
| 2     | Vertical stripes   |
+-------+--------------------+
| 3     | Checkerboard       |
+-------+--------------------+

If you wish to calculate the equivalent single parameter for Standard QL Colour Mode, you will need
to set various bits of colour by referring to the following table (note
that this cannot be used under the Extended Colour Drivers except under
COLOUR\_QL):

.. Original HTML, commented out here. Just for reference to get the table right. NDunbar.
.. <br><h3>BIT7  6    5  4  3    2  1  0
.. <br>STIPPLE                               COLOUR
.. <br></h3>Dots0  0|  0  0  0  |  0  0  0Black
.. <br>Vertical lines0  1|  0  0  1  |  0  0  1Blue
.. <br>Horizontal lines1  0|  0  1  0  |  0  1  0Red
.. <br>Checkerboard1  1|  0  1  1  |  0  1  1Magenta
.. <br>                |  1  0  0  |  1  0  0Green
.. <br>                |  1  0  1  |  1  0  1Cyan
.. <br>                |  1  1  0  |  1  1  0Yellow
.. <br>                |  1  1  1  |  1  1  1White

+-------------------+---------+----------+----------+----------+
| Stipple           | BITS 76 | BITS 543 | BITS 210 | Colour   |
+===================+=========+==========+==========+==========+
| Dots              |    00   |     000  | 000      | Black    |
+-------------------+---------+----------+----------+----------+
| Vertical Lines    |    01   |     001  | 001      | Blue     |
+-------------------+---------+----------+----------+----------+
| Horizontal lines  |    10   |     010  | 010      | Red      |
+-------------------+---------+----------+----------+----------+
| Checkerboard      |    11   |     011  | 011      | Magenta  |
|                   +---------+----------+----------+----------+
|                   |    11   |     100  | 100      | Green    |
|                   +---------+----------+----------+----------+
|                   |    11   |     101  | 101      | Cyan     |
|                   +---------+----------+----------+----------+
|                   |    11   |     110  | 110      | Yellow   |
|                   +---------+----------+----------+----------+
|                   |    11   |     111  | 111      | White    |
+-------------------+---------+----------+----------+----------+

**NOTE**

Turbo and Supercharge cannot compile the THOR's floating point colours
as they expect all parameters to be integers. Use IO\_TRAP instead, for
example::

    a=IO_TRAP(#ch,39,colour): REMark Sets the PAPER colour.
    a=IO_TRAP(#ch,40,colour): REMark  Sets the STRIP colour.
    a=IO_TRAP(#ch,41,colour): REMark  Sets the INK colour.

Unlike the PAPER command, if you use IO\_TRAP here, you will also need to set the STRIP colour
explicitly.

**THOR XVI NOTE**

The THOR XVI allows a total of 16 colours in MODE 12 in the range 0 to
7.5 (stipple will actually fall in the range 0...1023). If you add .5 to
the normal colour, this switches on the THOR's intensity bit, meaning
that for example, the resultant colour for INK 1.5 is somewhere between
black and blue (ie. a very dark blue). You can also add .25 to each
colour, which will result in a stipple mixture of colours (details
unknown at present).

**CROSS-REFERENCE**

:ref:`paper` and :ref:`strip`
also set colours within windows. :ref:`rmode` can be
used to read the current colour mode.
:ref:`colour-ql`,
:ref:`colour-pal`,
:ref:`colour-native` and
:ref:`colour-24` will also affect the colours
produced. :ref:`palette-ql` and
:ref:`palette-8` can be used to change the
palette of colours available.
DISP\_COLOUR can be used to switch from
Extended Colour Drivers to Standard Colour Drivers. Also refer to
:ref:`inverse`. Please also look at the QL Display
appendix (Appendix 16 - :ref:`a16-ql--display`).

