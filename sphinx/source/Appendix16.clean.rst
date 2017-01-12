..  _a16-ql--display:

A16 The QL Display
==================

The way in which the QL display is made up is fairly complex, and alters
in different MODEs and on different resolutions. The extended display
under SMSQ/E has also completely re-written the way in which the screen
is addressed, causing some incompatability problems.

The QL screen is in fact an area of the QL's memory which can be altered
using PEEK and POKE (or similar commands) as well as the more usual
display commands such as INK, PRINT, RECOL and INPUT. However, direct
access to the screen should be avoided wherever possible, except via the
machine code IOW.XTOP TRAP #3 routine (D0=$09).

In order to retain compatability with older software, the Aurora
motherboard, Q40/Q60 and QPC2 v3.00+ emulators all copy data stored at
the standard QL screen address across to the correct display area.
However, this in itself can lead to problems unless the computer is set
up to start in 512x256 mode, since the software does not copy changes on
the main screen (for example made with PRINT back to the original QL
display area).

A16.1 The Screen Address
------------------------

On a standard QL the screen is 32768 bytes long and stored in memory
starting with the address 131072 ($20000 in Hexadecimal).

In dual screen mode, another QL screen is also stored in memory,
normally at the address $28000 (in Hexadecimal) onwards.

However, in higher resolutions, this screen address has to move in order
to make room for a larger screen size.

It is therefore imperative that programs and toolkit commands do not
make assumptions about where the QL screen is stored - use SCR\_BASE,
SCREEN or similar functions to find the start address.

As the size of the screen alters, so does the amount of memory which the
screen takes up - to find the number of bytes used to store a screen,
use the formula:

screen\_size = SCR\_LLEN \* SCR\_YLIM

A16.2 The Screen Size
---------------------

On a standard QL, the display normally supports 256x256 pixels in MODE 8
and 512x256 pixels in MODE 4.

However, if the QL implementation you are using allows you to alter the
size of the QL's display (which can be anything up to 1600x1600 pixels),
you can either configure the operating system to start up in a higher
resolution or use a command such as SCR\_SIZE.

Due to the differences in the possible displays, you should use the
functions SCR\_XLIM and SCR\_YLIM to find out the maximum size of the
screen which can be addressed by your program.

Another factor to be taken into account is the number of pixels which
are used to contain the values of one pixel line of the display. On a
standard QL this is 128 bytes and many programs assumed that this would
never change. However, higher resolutions and extended colour drivers
demand more storage space, so you should use SCR\_LLEN to find out this
number.

A16.3 On-Screen Colours
-----------------------

The QL screen is actually an area of memory which is specifically set
aside to hold these details (the display memory). One of the QL's chips
looks at this memory 50 times per second (60 times per second in the sK)
and uses the values stored there to calculate the colour of the pixels
which you see on the screen of your Monitor or TV. Emulators copy this
screen to the area of memory used by the display card on the native
machine.

The display memory starts at SCR\_BASE which represents the top left
hand corner of your Monitor's screen and the size of the memory in bytes
is calculated by the formula:

SCR\_YLIM \* SCR\_LLEN

As you will see from the information set out below, you can easily
presume that if you know the number of pixels that a display size can
show, you should be able to calculate SCR\_LLEN (and vice-versa) and in
fact some software does just this. However, this is not always so - some
QL implementations use a fixed number of bytes to contain the displayed
pixels (no matter what the screen resolution) and so you should use both
SCR\_LLEN and SCR\_XLIM. See the examples below as to how programs
should be written to take account of both of these factors.

The way in which the display memory is organised depends upon the screen
mode being used, with more complex organisation methods for screen modes
which display more colours.

Under SMSQ/E v2.98+. you are able to use either the Standard QL Colour
Drivers, or the Enhanced Colour Drivers. If the latter is used, you need
to specify for each program which colour scheme is to be used with the
following commands:

+------------------+------------------------------------------------------------------------------------+
| COLOUR\_QL       | use standard QL MODE 4 / MODE 8 colour definitions (this is the default scheme).   |
+------------------+------------------------------------------------------------------------------------+
| COLOUR\_PAL      | use 8 bit (256 colour) palette definition.                                         |
+------------------+------------------------------------------------------------------------------------+
| COLOUR\_24       | use the 24 bit true colour definition.                                             |
+------------------+------------------------------------------------------------------------------------+
| COLOUR\_NATIVE   | use the native colour definition (dependent on the hardware itself).               |
+------------------+------------------------------------------------------------------------------------+

You can also specify that a different colour palette is to be used to
represent each of the INK colours, using the commands:

+---------------+----------------------------------------------------------------+
| PALETTE\_QL   | Specify different palette for standard MODE 4/MODE 8 colours   |
+---------------+----------------------------------------------------------------+
| PALETTE\_8    | Specify different palette for 8 bit colours                    |
+---------------+----------------------------------------------------------------+

The MODE will always remain the same once a program is using the
Enhanced Colour Drivers and the colour parameters expected by commands
such as INK, PAPER, STRIP, BORDER and BLOCK will depend upon the
following tables.

To use these tables, look up the hardware the program is to be used on
and then find the colour you need (this will need to be specified as a
PAL value, Native Colour Value or 24 Bit Colour Value depending on which
COLOUR\_xx command has been used) - see COLOUR\_PAL for an example of
how to make a program adopt to the different hardware.

| 

Standard QL Colour Drivers
^^^^^^^^^^^^^^^^^^^^^^^^^^

MODE 4
""""""

This is one of the standard display modes supported on the QL and
compatibles, with a lot of non-leisure software expecting this MODE -
this is because it provides a minimum display area of 512 x 256 pixels.

On a standard QL colour scheme, every two bytes (a word) represent eight
pixels on the Monitor's screen calculated by looking at the status of
each of the corresponding eight binary bits in each byte. The first bit
of the first byte is combined with the first bit of the second byte to
represent the colour of the first pixel. The second bit of the first
byte is combined with the second bit of the second byte to represent the
colour of the second pixel.

For example, if the first two bytes stored at SCR\_BASE are represented
in binary as:

::

            0 1 1 0 0 1 1 0   0 0 1 1 0 0 1 0
            } |_______________}_|
            }     2nd pixel   }
            }_________________}
                  1st pixel

The two bits are then placed side by side to create the colour
combination, meaning that the first pixel is represented as 00 and the
second pixel is represented as 10.

This provides us with the following colours:

+------+---------+
| Bits | Colour  |
+======+=========+
| 00   | BLACK   |
+------+---------+
| 01   | RED     |
+------+---------+
| 10   | GREEN   |
+------+---------+
| 11   | WHITE   |
+------+---------+

Therefore in the above example, the first eight pixels of the display
become:

00 10 11 01 00 10 11 00

which equates to the following colours:

BLACK, GREEN, WHITE, RED, BLACK, GREEN, WHITE, BLACK

**Example**

The following program will fill the screen with black and white vertical
stripes:

::

            100 MODE 4
            110 FOR x=0 TO SCR_YLIM-1
            120   FOR y=0 TO (SCR_XLIM-1)/4 STEP 2
            130     POKE SCR_BASE+ (x*SCR_LLEN) + y,    BIN ('01010101')
            135     POKE SCR_BASE+ (x*SCR_LLEN) + y+1,  BIN ('01010101')
            140   END FOR y
            150 END FOR x

MODE 8
""""""

This was one of the standard display modes but is only fully supported
on a limited number of QL implementations. A lot of leisure software
expects this MODE - this is because it provides more colours and the
possibility of flashing pixels on screen. However, if this mode is not
available, fear not, since the programs will still run quite happily in
other screen modes, although the screen may be a little different.

This mode provides a standard display area of 256 x 256 pixels.

On a standard QL colour scheme, every two bytes (a word) represent four
pixels on the Monitor's screen calculated by looking at the status of
each set of two corresponding binary bits in each byte. The first two
bits of the first byte are combined with the first two bits of the
second byte to represent the colour of the first pixel. The second two
bits of the first byte are combined with the second two bits of the
second byte to represent the colour of the second pixel.

For example, if the first two bytes stored at SCR\_BASE are represented
in binary as:

::

            0 1 1 0 0 1 1 0   0 0 1 1 0 0 1 0
            } } |__|__________}_}_|_|
            } }    2nd pixel  } }
            } }_______________} }
                   1st pixel

The four bits are then placed side by side to define the pixel. The
second bit specifies whether Flash is to be set (bit=1) - if flash is
enabled by setting this bit, then this will affect all other pixels on
that same line until another flash bit is set (disabling the Flash
function).

The other three bits are combined to create the colour, meaning that the
first pixel is represented as 0100 and the second pixel is represented
as 1011.

This provides us with the following colours (excluding the flash bit
which is represented here by an x):

+--------+-----------+
| Bits   | Colour    |
+========+===========+
| 0x00   | BLACK     |
+--------+-----------+
| 0x01   | BLUE      |
+--------+-----------+
| 0x10   | RED       |
+--------+-----------+
| 0x11   | MAGENTA   |
+--------+-----------+
| 1x00   | GREEN     |
+--------+-----------+
| 0x01   | CYAN      |
+--------+-----------+
| 0x10   | YELLOW    |
+--------+-----------+
| 0x11   | WHITE     |
+--------+-----------+

Therefore in the above example, the first four pixels of the display
become:

+---------+--------+-------------------------------------------+
| PIXEL   | BITS   | EFFECT                                    |
+=========+========+===========================================+
| 0       | 0100   | BLACK (Turn Flash On at this Pixel)       |
+---------+--------+-------------------------------------------+
| 1       | 1011   | WHITE (Flashing)                          |
+---------+--------+-------------------------------------------+
| 2       | 0100   | BLACK (Turn Flash Off after this Pixel)   |
+---------+--------+-------------------------------------------+
| 3       | 1010   | YELLOW                                    |
+---------+--------+-------------------------------------------+

**Example**

The following program will fill the screen with magenta and cyan
flashing vertical stripes:

::

            100 MODE 8
            110 FOR x=0 TO SCR_YLIM-1
            120   FOR y=0 TO (SCR_XLIM-1)/4 STEP 2
            130     POKE SCR_BASE+ (x*SCR_LLEN) + y,    BIN ('01100110')
            135     POKE SCR_BASE+ (x*SCR_LLEN) + y+1,  BIN ('11011101')
            140   END FOR y
            150 END FOR x

Note that only one in two cyan pixels flash, this is because the effect
of each pass of the y loop is to set the following pixels:

+---------+--------+-------------------------------------------+
| PIXEL   | BITS   | EFFECT                                    |
+=========+========+===========================================+
| 0       | 0111   | MAGENTA (Turn Flash On at this Pixel)     |
+---------+--------+-------------------------------------------+
| 1       | 1001   | CYAN (Flashing)                           |
+---------+--------+-------------------------------------------+
| 2       | 0111   | BLACK (Turn Flash Off after this Pixel)   |
+---------+--------+-------------------------------------------+
| 3       | 1001   | CYAN (Not Flashing)                       |
+---------+--------+-------------------------------------------+

**SMSQ/E NOTES**

Under the Enhanced Colour Drivers, available under SMSQ/E v2.98+,
COLOUR\_QL can be used to make a program resemble the original MODE 4 or
MODE 8, generating the same colours.

However, as explained in the description of the INK command, all 8
colours available to MODE 8 are actually available whether a program is
attempting to run in MODE 4 or MODE 8. As a result, programs written for
the original standard QL MODE 4 may show slight colour corruption.

It is possible to alter the set of 8 colours available if a different
palette is specified with PALETTE\_QL.

SMSQ/E can be forced to overcome any incompatability problems by
configuring it to load the Standard QL Colour Drivers; using
DISP\_COLOUR; or using PALETTE\_QL.

Aurora Enhanced Colour Drivers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

At present, a version of SMSQ/E which provides the Enhanced Colour
Drivers for Aurora has not been released. The way in which these colour
schemes are therefore used is subject to possible change.

Although this can be used for testing software, unfortunately, if an
Enhanced Colour Mode is enabled on Aurora, the display is corrupted by
pixels being split across the screen, effectively causing the screen to
be repeated horizontally. Programs such as the Photon JPEG viewer
overcome this by clearing the screen and only altering the display
memory directly (not attempting to use any standard commands/ machine
code operating system calls). See the examples below as to how this may
be achieved.

The display mode may be changed directly by altering the value stored at
address $18043 in memory (this is write only and cannot be read). The
write-only Master Control Register at $18063 remains as on the standard
QL for compatability. Attempting to read the byte stored at $18043 will
actually return the value of the Monitor Preset Register - see below.

The Master Control Register ($18063)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A write-only register where the following bits can be used:

+---------+-----+-------------------------------------------------------------------------------------------------------------------+
| Bit 0   | \-  | Blank Screen if set.                                                                                              |
+---------+-----+-------------------------------------------------------------------------------------------------------------------+
| Bit 3   | \-  | Use MODE 4 if clear, MODE 8 if set.                                                                               |
+---------+-----+-------------------------------------------------------------------------------------------------------------------+
| Bit 7   | \-  | Display SCR0 if clear, SCR1 if set. Keep this bit clear if using non-standard QL display modes and resolutions.   |
+---------+-----+-------------------------------------------------------------------------------------------------------------------+

All other bits should be left clear.

As can be seen, Minerva's extended MODE calls alter this register and
should be used where available.

The Enhanced Mode Control Register ($18043)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A write-only register where the following bits can be used:

Bits 0 & 1 - Control display resolution as per following table:

+---------+---------+-------------------------+
| Bit 1   | Bit 0   | Horizontal resolution   |
+=========+=========+=========================+
| 0       | 0       | 512 pixels              |
+---------+---------+-------------------------+
| 0       | 1       | 640 pixels              |
+---------+---------+-------------------------+
| 1       | 0       | 768 pixels              |
+---------+---------+-------------------------+
| 1       | 1       | 1024 pixels             |
+---------+---------+-------------------------+

Bits 3 & 4 - Control colour mode as per following table:

+---------+---------+--------------------------+
| Bit 4   | Bit 3   | Mode                     |
+=========+=========+==========================+
| 0       | 0       | 4 Colour Mode (MODE 4)   |
+---------+---------+--------------------------+
| 0       | 1       | 8 Colour Mode (MODE 8)   |
+---------+---------+--------------------------+
| 1       | 0       | 16 Colour Mode           |
+---------+---------+--------------------------+
| 1       | 1       | 256 Colour Mode          |
+---------+---------+--------------------------+

Bit 7 - Control aspect ratio (which controls how the vertical resolution
is calculated by reference to the horizontal resolution) as per
following table:

+---------+-----------------------------------------------------------------+
| Bit 7   | Aspect Ratio                                                    |
+=========+=================================================================+
| 0       | 2:1 (QL Style pixels); vertical res. = horizontal res. \* 1/2   |
+---------+-----------------------------------------------------------------+
| 1       | 4:3 (Square pixels); vertical res. = horizontal res. \* 3/4     |
+---------+-----------------------------------------------------------------+

All other bits should be left clear.

**IMPORTANT**

The actual resolution displayed will depend on the monitor preset, which
can be read from the Monitor Preset Register (see below) and the mode
selected (for reasons of limited high-resolution screen memory).

The resolution selected in the Enhanced Mode Control Register ($18043)
in principle does NOT depend on the mode, except in MODE 8, where the
resolution selected refers to MODE 4, but the number of pixels in one
line is halved, as per the standard QL MODE 8 (this is to maintain
compatibility), and by limit of the high-resolution screen memory.

Because the high-resolution screen memory is fixed at 240K, the
resolutions in modes with more colours will be limited. In particular:

+--------------------+------------------------------------------------------------------------------------------------------------+
| MODE 4:            | No limits (high-resolution screen memory is larger than maximum resolution of 1024 x 768 pixels).          |
+--------------------+------------------------------------------------------------------------------------------------------------+
| 16 Colour Mode:    | Maximum vertical resolution is limited to 480 lines.                                                       |
+--------------------+------------------------------------------------------------------------------------------------------------+
| 256 Colour Mode:   | Horizontal resolution is limited to 512 pixels, and maximum vertical resolution is limited to 480 lines.   |
+--------------------+------------------------------------------------------------------------------------------------------------+

Additional limits may apply depending on the monitor preset values.

The limiting logic is simple - if the resolution chosen is higher than a
limit, the limit is used instead. Limits apply independently for x and y
directions. The maximum x and y coordinates have to be adjusted
according to these limits for every given resolution and monitor preset
setting.

The Monitor Preset Register ($18043)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is a read-only register where the following bits can be used:

+--------------------+--------------------+--------------------+--------------------+
| Bit 0              |                    | \-                 | Interlace Enable   |
|                    |                    |                    | Bit (IE)           |
+--------------------+--------------------+--------------------+--------------------+
| Bit 2 (MT1) Bit 4  | } }                | \-                 | General Type of    |
| (MT0)              |                    |                    | Monitor Selected   |
+--------------------+--------------------+--------------------+--------------------+

The maximum vertical resolutions is calculated as per the following
table (where NI means Not Interlaced and I means Interlaced):

+-------+-------+------+--------------------+-------------------------+
| MT1   | MT0   | IE   | Monitor type       | Max. vert. resolution   |
+=======+=======+======+====================+=========================+
| 0     | 0     | 0    | QL standard        | NI 288 lines            |
+-------+-------+------+--------------------+-------------------------+
| 0     | 0     | 1    | QL standard        | I 576 lines             |
+-------+-------+------+--------------------+-------------------------+
| 0     | 1     | 0    | VGA                | I 576 lines             |
+-------+-------+------+--------------------+-------------------------+
| 0     | 1     | 1    | VGA                | I 768 lines             |
+-------+-------+------+--------------------+-------------------------+
| 1     | 0     | 0    | SVGA               | NI 576 lines            |
+-------+-------+------+--------------------+-------------------------+
| 1     | 0     | 1    | SVGA               | I 768 lines             |
+-------+-------+------+--------------------+-------------------------+
| 1     | 1     | 0    | Multisynch         | I 768 lines             |
+-------+-------+------+--------------------+-------------------------+
| 1     | 1     | 1    | Multisynch diag.   | 960 lines\*             |
+-------+-------+------+--------------------+-------------------------+

\* This is a special diagnostic mode which displays a 1024x960
interlaced picture on a multisynch monitor when 1024x768 is selected,
hence displaying the contents of the whole high-res screen area. Whether
the software will support this is optional - this combination of MT and
IE bits is not used in normal operation.

16 Colour Mode
^^^^^^^^^^^^^^

It is planned that under the Enhanced Colour Drivers available in SMSQ/E
v2.98+, this mode will be available as MODE 8 and support up to 1024x480
resolution. It is not yet implemented and may be forced using the
command:

+-----------------------------------+-----+----------------------------+
| POKE $18043,144 (144=%10010000)   | \-  | 512 pixels x 480 pixels    |
+-----------------------------------+-----+----------------------------+
| POKE $18043,146 (146=%10010010)   | \-  | 768 pixels x 480 pixels    |
+-----------------------------------+-----+----------------------------+
| POKE $18043,147 (147=%10010011)   | \-  | 1024 pixels x 480 pixels   |
+-----------------------------------+-----+----------------------------+

(See above for details)

A different set of colours can be used by specifying a different palette
with PALETTE\_QL.

Actually writing to the screen directly causes some problems, since
SCR\_LLEN returns 256 bytes, although in actual fact, the screen is 512
bytes wide in this mode.

Under the Enhanced Colour Drivers, this mode uses a byte to store the
colours of 2 pixels. Here, the four adjacent bits represent the same
pixel.

The four bits are stored in the format **IRGB**, where:

- I is intensity

- G is Green

- R is Red

- B is Blue

It is uncertain how this will be implemented - However, the following
table details the Native Values to be used when POKEing directly to the
screen (in machine code for example) and the probable corresponding INK
parameter to use to achieve that colour (**NOTE** this is not the same as
the original QL colour scheme). Conversion of the values to binary gives
a clue as to how this colour scheme works:

+--------+--------------+----------+----------+-------------+
|                       |             IRGB                  |
+--------+--------------+----------+----------+-------------+
|Ink     | Colour       | Value    |  Value   | Value       |
|Value   | Name         | Decimal  |  Hex     | Binary      |
+========+==============+==========+==========+=============+
| 0      | Black        | 0        | $00      | 0000        |
+--------+--------------+----------+----------+-------------+
| 1      | White        | 15       | $0F      | 1111        |
+--------+--------------+----------+----------+-------------+
| 2      | Red          | 12       | $0C      | 1100        |
+--------+--------------+----------+----------+-------------+
| 3      | Green        | 10       | $0A      | 1010        |
+--------+--------------+----------+----------+-------------+
| 4      | Blue         | 9        | $09      | 1001        |
+--------+--------------+----------+----------+-------------+
| 5      | Magenta      | 13       | $0D      | 1101        |
+--------+--------------+----------+----------+-------------+
| 6      | Yellow       | 14       | $0E      | 1110        |
+--------+--------------+----------+----------+-------------+
| 7      | Cyan         | 11       | $0B      | 1011        |
+--------+--------------+----------+----------+-------------+
|10      | Dark Grey    | 8        | $08      | 1000        |
+--------+--------------+----------+----------+-------------+
|11      | Grey         | 7        | $07      | 0111        |
+--------+--------------+----------+----------+-------------+
|14      | Dark Red     | 4        | $04      | 0100        |
+--------+--------------+----------+----------+-------------+
|17      | Green        | 2        | $02      | 0010        |
+--------+--------------+----------+----------+-------------+
|19      | Blue         | 1        | $01      | 0001        |
+--------+--------------+----------+----------+-------------+
|??      | Dark Magenta | 5        | $05      | 0101        |
+--------+--------------+----------+----------+-------------+
|??      | Dark Yellow  | 6        | $06      | 0110        |
+--------+--------------+----------+----------+-------------+
|??      | Dark Cyan    | 3        | $03      | 0011        |
+--------+--------------+----------+----------+-------------+


**Example**

The following program for SMSQ/E will show the MODE 8 (16 colours)
available on Aurora. Note the need to explicitly wipe the screen - this
is because MODE would normally do this for you.

::

            100 MODE 4
            110 POKE $18043,144 : REMark force switch to MODE 8:COLOUR_PAL (512 resolution)
            120 scr_offset=SCR_BASE(#1)
            130 scr_len=512:REMark SCR_LLEN reports the wrong value in this mode
            140 :
            150 REMark Blank out screen
            160 col=0
            170 FOR i%=0 TO 479
            180   FOR j%=0 TO 508 STEP 4
            190     POKE_L scr_offset+i%*scr_len+j%,col
            200   END FOR j%
            210 END FOR i%
            220 :
            230 REMark Draw Colours
            240 yoff=20
            250 FOR i=0 TO 1
            260   xoff=0
            270   FOR j=0 TO 15
            280     col=j+j*2^4:REMark Set two pixels at a time.
            290     scr_offset=yoff*scr_len+xoff+SCR_BASE(#1)
            300     FOR a=0 TO 10
            310       FOR b=0 TO 10
            320           POKE scr_offset+a*scr_len+b,col
            330       END FOR b
            340     END FOR a
            350     xoff=xoff+12
            360   END FOR j
            370 yoff=yoff+12
            380 END FOR i

256 Colour Mode
^^^^^^^^^^^^^^^

It is planned that under the Enhanced Colour Drivers available in SMSQ/E
v2.98+, this mode will be available as MODE 16. There is a fixed
resolution available of 512x480 pixels. It is not yet implemented and
may be forced using the command:

POKE $18043,154 (See above for details)

Here, every byte represents one pixel on the Monitor's screen,
calculated by looking at the status of each of the binary bits in each
byte.

Actually writing to the screen directly causes some problems, since
SCR\_LLEN returns 256 bytes, although in actual fact, the screen is 512
bytes wide in this mode.

The bits are combined to represent the amount of GREEN, RED and BLUE to
be used for each pixel, in the format **GRBGRBGX**, where:

- G is Green

- R is Red

- B is Blue

- X is Red/Blue

The colours are hard to describe due to the range and therefore require
experimentation to obtain the correct colours. However, the following
table details the PAL colour which should be used as the INK parameter (

**NOTE**

this does not correspond with the original QL colour scheme!) and the
corresponding Native Values to be used when POKEing directly to the
screen (in machine code for example). It is not possible to list all 256
colours, therefore we have tried to list the most widely used ones (INK
0 to INK 63) grouped into the different colours. Conversion of the
values to binary gives a clue as to how this colour scheme works:

+-------------+-----------------+--------------+--------------+--------------+
|                               |         GRBGRBGX                           |
+-------------+-----------------+--------------+--------------+--------------+
| PAL Colour  | Colour          | Native Value | Native Value | Native Value |
| Value       | Name            | (Decimal)    | (Hex)        | (Binary)     |
+=============+=================+==============+==============+==============+
| 0           | Black           |   0          | $00          | 00000000     |
+-------------+-----------------+--------------+--------------+--------------+
| 1           | White           | 255          | $FF          | 11111111     |
+-------------+-----------------+--------------+--------------+--------------+
| 8           | Dark Slate      |   3          | $03          | 00000011     |
+-------------+-----------------+--------------+--------------+--------------+
| 9           | Slate Grey      |  28          | $1C          | 00011100     |
+-------------+-----------------+--------------+--------------+--------------+
| 10          | Dark Grey       |  31          | $1F          | 00011111     |
+-------------+-----------------+--------------+--------------+--------------+
| 11          | Grey            | 224          | $E0          | 11100000     |
+-------------+-----------------+--------------+--------------+--------------+
| 12          | Light Grey      | 227          | $E3          | 11100011     |
+-------------+-----------------+--------------+--------------+--------------+
| 13          | Ash Grey        | 252          | $FC          | 11111100     |
+-------------+-----------------+--------------+--------------+--------------+
| 58          | Cerise          |  68          | $44          | 01000100     |
+-------------+-----------------+--------------+--------------+--------------+
| 14          | Dark Red        |  64          | $40          | 01000000     |
+-------------+-----------------+--------------+--------------+--------------+
| 2           | Red             |  73          | $49          | 01001001     |
+-------------+-----------------+--------------+--------------+--------------+
| 63          | Deep Purple     |  40          | $28          | 00101000     |
+-------------+-----------------+--------------+--------------+--------------+
| 51          | Plum            |  15          | $0F          | 00001111     |
+-------------+-----------------+--------------+--------------+--------------+
| 20          | Purple          |  96          | $60          | 01100000     |
+-------------+-----------------+--------------+--------------+--------------+
| 26          | Mauve           | 100          | $64          | 01100100     |
+-------------+-----------------+--------------+--------------+--------------+
| 57          | Faded Purple    | 112          | $70          | 01110000     |
+-------------+-----------------+--------------+--------------+--------------+
| 52          | Dusky Pink      | 113          | $71          | 01110001     |
+-------------+-----------------+--------------+--------------+--------------+
| 5           | Magenta         | 109          | $6D          | 01101101     |
+-------------+-----------------+--------------+--------------+--------------+
| 21          | Shocking Pink   | 105          | $69          | 01101001     |
+-------------+-----------------+--------------+--------------+--------------+
| 45          | Dull Pink       | 115          | $73          | 01110011     |
+-------------+-----------------+--------------+--------------+--------------+
| 31          | Rose Pink       | 239          | $EF          | 11101111     |
+-------------+-----------------+--------------+--------------+--------------+
| 39          | Pastel Rose     | 253          | $FD          | 11111101     |
+-------------+-----------------+--------------+--------------+--------------+
| 27          | Peach           | 235          | $EB          | 11101011     |
+-------------+-----------------+--------------+--------------+--------------+
| 50          | Midnight Blue   |   7          | $07          | 00000111     |
+-------------+-----------------+--------------+--------------+--------------+
| 19          | Dark Blue       |  32          | $20          | 00100000     |
+-------------+-----------------+--------------+--------------+--------------+
| 4           | Blue            |  36          | $24          | 00100100     |
+-------------+-----------------+--------------+--------------+--------------+
| 62          | Ultramarine     |  48          | $30          | 00110000     |
+-------------+-----------------+--------------+--------------+--------------+
| 49          | Dusky Blue      |  23          | $17          | 00010111     |
+-------------+-----------------+--------------+--------------+--------------+
| 44          | Steel Blue      |  59          | $3B          | 00111011     |
+-------------+-----------------+--------------+--------------+--------------+
| 18          | Sea Blue        | 160          | $A0          | 10100000     |
+-------------+-----------------+--------------+--------------+--------------+
| 25          | Bright Blue     | 164          | $A4          | 10100100     |
+-------------+-----------------+--------------+--------------+--------------+
| 56          | Dull Blue       | 168          | $A8          | 10101000     |
+-------------+-----------------+--------------+--------------+--------------+
| 43          | Dull Cyan       | 171          | $AB          | 10101011     |
+-------------+-----------------+--------------+--------------+--------------+
| 7           | Cyan            | 182          | $B6          | 10110110     |
+-------------+-----------------+--------------+--------------+--------------+
| 29          | Light Blue      | 247          | $F7          | 11110111     |
+-------------+-----------------+--------------+--------------+--------------+
| 30          | Sky Blue        | 231          | $E7          | 11100111     |
+-------------+-----------------+--------------+--------------+--------------+
| 48          | Dusky Green     |  19          | $13          | 00010011     |
+-------------+-----------------+--------------+--------------+--------------+
| 60          | Grass Green     | 136          | $88          | 10001000     |
+-------------+-----------------+--------------+--------------+--------------+
| 17          | Dark Green      | 128          | $80          | 10000000     |
+-------------+-----------------+--------------+--------------+--------------+
| 54          | Avocado         | 198          | $C6          | 11000110     |
+-------------+-----------------+--------------+--------------+--------------+
| 61          | Sea Green       | 132          | $84          | 10000100     |
+-------------+-----------------+--------------+--------------+--------------+
| 42          | Dull Green      | 143          | $8F          | 10001111     |
+-------------+-----------------+--------------+--------------+--------------+
| 3           | Green           | 146          | $92          | 10010010     |
+-------------+-----------------+--------------+--------------+--------------+
| 23          | Lime Green      | 210          | $D2          | 11010010     |
+-------------+-----------------+--------------+--------------+--------------+
| 24          | Apple Green     | 178          | $B2          | 10110010     |
+-------------+-----------------+--------------+--------------+--------------+
| 55          | Dull Turquoise  | 170          | $AA          | 10101010     |
+-------------+-----------------+--------------+--------------+--------------+
| 41          | Light Khaki     | 199          | $C7          | 11000111     |
+-------------+-----------------+--------------+--------------+--------------+
| 15          | Light Green     | 243          | $F3          | 11110011     |
+-------------+-----------------+--------------+--------------+--------------+
| 36          | Pastel Green    | 254          | $FE          | 11111110     |
+-------------+-----------------+--------------+--------------+--------------+
| 46          | Brown           |  11          | $0B          | 00001011     |
+-------------+-----------------+--------------+--------------+--------------+
| 59          | Tan             |  80          | $50          | 01010000     |
+-------------+-----------------+--------------+--------------+--------------+
| 6           | Yellow          | 219          | $DB          | 11011011     |
+-------------+-----------------+--------------+--------------+--------------+
| 22          | Orange          | 201          | $C9          | 11001001     |
+-------------+-----------------+--------------+--------------+--------------+
| 16          | Mustard         | 192          | $C0          | 11000000     |
+-------------+-----------------+--------------+--------------+--------------+
| 47          | Khaki           |  27          | $1B          | 00011011     |
+-------------+-----------------+--------------+--------------+--------------+
| 53          | Buff            | 197          | $C5          | 11000101     |
+-------------+-----------------+--------------+--------------+--------------+
| 40          | Brick           |  87          | $57          | 01010111     |
+-------------+-----------------+--------------+--------------+--------------+
| 33          | Beige           | 249          | $F9          | 11111001     |
+-------------+-----------------+--------------+--------------+--------------+
| 28          | Light Yellow    | 251          | $FB          | 11111011     |
+-------------+-----------------+--------------+--------------+--------------+


It is unknown how PAL colours 32, 34, 35, 37 and 38 will be mapped as
these relate to the same values as PAL colours 31, 33, 36, 13 and 13
respectively.

The remainder of the colours are mapped as **grbgrbgx** (we would welcome
names for each of these colours):


+-------------+--------------------------------------------+
|             |         GRBGRBGX                           |
+-------------+--------------+--------------+--------------+
| PAL Colour  | Native Value | Native Value | Native Value |
| Value       | (Decimal)    | (Hex)        | (Binary)     |
+=============+==============+==============+==============+
|  64         |   4          |  $04         |  00000100    |
+-------------+--------------+--------------+--------------+
|  65         |   1          |  $01         |  00000001    |
+-------------+--------------+--------------+--------------+
|  66         |    5         |  $05         |  00000101    |
+-------------+--------------+--------------+--------------+
|  67         |   33         |  $21         |  00100001    |
+-------------+--------------+--------------+--------------+
|  68         |   37         |  $25         |  00100101    |
+-------------+--------------+--------------+--------------+
|  69         |    8         |  $08         |  00001000    |
+-------------+--------------+--------------+--------------+
|  70         |   12         |  $0C         |  00001100    |
+-------------+--------------+--------------+--------------+
|  71         |   44         |  $2C         |  00101100    |
+-------------+--------------+--------------+--------------+
|  72         |    9         |  $09         |  00001001    |
+-------------+--------------+--------------+--------------+
|  73         |   13         |  $0D         |  00001101    |
+-------------+--------------+--------------+--------------+
|  74         |   41         |  $29         |  00101001    |
+-------------+--------------+--------------+--------------+
|  75         |   45         |  $2D         |  00101101    |
+-------------+--------------+--------------+--------------+
|  76         |   65         |  $41         |  01000001    |
+-------------+--------------+--------------+--------------+
|  77         |   69         |  $45         |  01000101    |
+-------------+--------------+--------------+--------------+
|  78         |   97         |  $61         |  01100001    |
+-------------+--------------+--------------+--------------+
|  79         |  101         |  $65         |  01100101    |
+-------------+--------------+--------------+--------------+
|  80         |   72         |  $48         |  01001000    |
+-------------+--------------+--------------+--------------+
|  81         |   76         |  $4C         |  01001100    |
+-------------+--------------+--------------+--------------+
|  82         |  104         |  $68         |  01101000    |
+-------------+--------------+--------------+--------------+
|  83         |  108         |  $6C         |  01101100    |
+-------------+--------------+--------------+--------------+
|  84         |   77         |  $4D         |  01001101    |
+-------------+--------------+--------------+--------------+
|  85         |    2         |  $02         |  00000010    |
+-------------+--------------+--------------+--------------+
|  86         |    6         |  $06         |  00000110    |
+-------------+--------------+--------------+--------------+
|  87         |   34         |  $22         |  00100010    |
+-------------+--------------+--------------+--------------+
|  88         |   38         |  $26         |  00100110    |
+-------------+--------------+--------------+--------------+
|  89         |   35         |  $23         |  00100011    |
+-------------+--------------+--------------+--------------+
|  90         |   39         |  $27         |  00100111    |
+-------------+--------------+--------------+--------------+
|  91         |   10         |  $0A         |  00001010    |
+-------------+--------------+--------------+--------------+
|  92         |   14         |  $0E         |  00001110    |
+-------------+--------------+--------------+--------------+
|  93         |   42         |  $2A         |  00101010    |
+-------------+--------------+--------------+--------------+
|  94         |   46         |  $2E         |  00101110    |
+-------------+--------------+--------------+--------------+
|  95         |   43         |  $2B         |  00101011    |
+-------------+--------------+--------------+--------------+
|  96         |   47         |  $2F         |  00101111    |
+-------------+--------------+--------------+--------------+
|  97         |   66         |  $42         |  01000010    |
+-------------+--------------+--------------+--------------+
|  98         |   70         |  $46         |  01000110    |
+-------------+--------------+--------------+--------------+
|  99         |   98         |  $62         |  01100010    |
+-------------+--------------+--------------+--------------+
| 100         |  102         |  $66         |  01100110    |
+-------------+--------------+--------------+--------------+
| 101         |   67         |  $43         |  01000011    |
+-------------+--------------+--------------+--------------+
| 102         |   71         |  $47         |  01000111    |
+-------------+--------------+--------------+--------------+
| 103         |   99         |  $63         |  01100011    |
+-------------+--------------+--------------+--------------+
| 104         |  103         |  $67         |  01100111    |
+-------------+--------------+--------------+--------------+
| 105         |   74         |  $4A         |  01001010    |
+-------------+--------------+--------------+--------------+
| 106         |   78         |  $4E         |  01001110    |
+-------------+--------------+--------------+--------------+
| 107         |  106         |  $6A         |  01101010    |
+-------------+--------------+--------------+--------------+
| 108         |  110         |  $6E         |  01101110    |
+-------------+--------------+--------------+--------------+
| 109         |   75         |  $4B         |  01001011    |
+-------------+--------------+--------------+--------------+
| 110         |   79         |  $4F         |  01001111    |
+-------------+--------------+--------------+--------------+
| 111         |  107         |  $6B         |  01101011    |
+-------------+--------------+--------------+--------------+
| 112         |   95         |  $5F         |  01011111    |
+-------------+--------------+--------------+--------------+
| 113         |   16         |  $10         |  00010000    |
+-------------+--------------+--------------+--------------+
| 114         |   20         |  $14         |  00010100    |
+-------------+--------------+--------------+--------------+
| 115         |   52         |  $34         |  00110100    |
+-------------+--------------+--------------+--------------+
| 116         |   17         |  $11         |  00010001    |
+-------------+--------------+--------------+--------------+
| 117         |   21         |  $15         |  00010101    |
+-------------+--------------+--------------+--------------+
| 118         |   49         |  $31         |  00110001    |
+-------------+--------------+--------------+--------------+
| 119         |   53         |  $35         |  00110101    |
+-------------+--------------+--------------+--------------+
| 120         |   24         |  $18         |  00011000    |
+-------------+--------------+--------------+--------------+
| 121         |   56         |  $38         |  00111000    |
+-------------+--------------+--------------+--------------+
| 122         |   60         |  $3C         |  00111100    |
+-------------+--------------+--------------+--------------+
| 123         |   25         |  $19         |  00011001    |
+-------------+--------------+--------------+--------------+
| 124         |   29         |  $1D         |  00011101    |
+-------------+--------------+--------------+--------------+
| 125         |   57         |  $39         |  00111001    |
+-------------+--------------+--------------+--------------+
| 126         |   61         |  $3D         |  00111101    |
+-------------+--------------+--------------+--------------+
| 127         |   84         |  $54         |  01010100    |
+-------------+--------------+--------------+--------------+
| 128         |  116         |  $74         |  01110100    |
+-------------+--------------+--------------+--------------+
| 129         |   81         |  $51         |  01010001    |
+-------------+--------------+--------------+--------------+
| 130         |   85         |  $55         |  01010101    |
+-------------+--------------+--------------+--------------+
| 131         |  117         |  $75         |  01110101    |
+-------------+--------------+--------------+--------------+
| 132         |   88         |  $58         |  01011000    |
+-------------+--------------+--------------+--------------+
| 133         |   92         |  $5C         |  01011100    |
+-------------+--------------+--------------+--------------+
| 134         |  120         |  $78         |  01111000    |
+-------------+--------------+--------------+--------------+
| 135         |  124         |  $7C         |  01111100    |
+-------------+--------------+--------------+--------------+
| 136         |   89         |  $59         |  01011001    |
+-------------+--------------+--------------+--------------+
| 137         |   93         |  $5D         |  01011101    |
+-------------+--------------+--------------+--------------+
| 138         |  121         |  $79         |  01111001    |
+-------------+--------------+--------------+--------------+
| 139         |  125         |  $7D         |  01111101    |
+-------------+--------------+--------------+--------------+
| 140         |   18         |  $12         |  00010010    |
+-------------+--------------+--------------+--------------+
| 141         |   22         |  $16         |  00010110    |
+-------------+--------------+--------------+--------------+
| 142         |   50         |  $32         |  00110010    |
+-------------+--------------+--------------+--------------+
| 143         |   54         |  $36         |  00110110    |
+-------------+--------------+--------------+--------------+
| 144         |   51         |  $33         |  00110011    |
+-------------+--------------+--------------+--------------+
| 145         |   55         |  $37         |  00110111    |
+-------------+--------------+--------------+--------------+
| 146         |   26         |  $1A         |  00011010    |
+-------------+--------------+--------------+--------------+
| 147         |   30         |  $1E         |  00011110    |
+-------------+--------------+--------------+--------------+
| 148         |   58         |  $3A         |  00111010    |
+-------------+--------------+--------------+--------------+
| 149         |   62         |  $3E         |  00111110    |
+-------------+--------------+--------------+--------------+
| 150         |   63         |  $3F         |  00111111    |
+-------------+--------------+--------------+--------------+
| 151         |   82         |  $52         |  01010010    |
+-------------+--------------+--------------+--------------+
| 152         |   86         |  $56         |  01010110    |
+-------------+--------------+--------------+--------------+
| 153         |  114         |  $72         |  01110010    |
+-------------+--------------+--------------+--------------+
| 154         |  118         |  $76         |  01110110    |
+-------------+--------------+--------------+--------------+
| 155         |   83         |  $53         |  01010011    |
+-------------+--------------+--------------+--------------+
| 156         |  119         |  $77         |  01110111    |
+-------------+--------------+--------------+--------------+
| 157         |   90         |  $5A         |  01011010    |
+-------------+--------------+--------------+--------------+
| 158         |   94         |  $5E         |  01011110    |
+-------------+--------------+--------------+--------------+
| 159         |  122         |  $7A         |  01111010    |
+-------------+--------------+--------------+--------------+
| 160         |  126         |  $7E         |  01111110    |
+-------------+--------------+--------------+--------------+
| 161         |   91         |  $5B         |  01011011    |
+-------------+--------------+--------------+--------------+
| 162         |   95         |  $5F         |  01011111    |
+-------------+--------------+--------------+--------------+
| 163         |  123         |  $7B         |  01111011    |
+-------------+--------------+--------------+--------------+
| 164         |  127         |  $7F         |  01111111    |
+-------------+--------------+--------------+--------------+
| 165         |  129         |  $81         |  10000001    |
+-------------+--------------+--------------+--------------+
| 166         |  133         |  $85         |  10000101    |
+-------------+--------------+--------------+--------------+
| 167         |  161         |  $A1         |  10100001    |
+-------------+--------------+--------------+--------------+
| 168         |  165         |  $A5         |  10100101    |
+-------------+--------------+--------------+--------------+
| 169         |  140         |  $8C         |  10001100    |
+-------------+--------------+--------------+--------------+
| 170         |  172         |  $AC         |  10101100    |
+-------------+--------------+--------------+--------------+
| 171         |  137         |  $89         |  10001001    |
+-------------+--------------+--------------+--------------+
| 172         |  141         |  $8D         |  10001101    |
+-------------+--------------+--------------+--------------+
| 173         |  169         |  $A9         |  10101001    |
+-------------+--------------+--------------+--------------+
| 174         |  173         |  $AD         |  10101101    |
+-------------+--------------+--------------+--------------+
| 175         |  196         |  $C4         |  11000100    |
+-------------+--------------+--------------+--------------+
| 176         |  228         |  $E4         |  11100100    |
+-------------+--------------+--------------+--------------+
| 177         |  193         |  $C1         |  11000001    |
+-------------+--------------+--------------+--------------+
| 178         |  225         |  $E1         |  11100001    |
+-------------+--------------+--------------+--------------+
| 179         |  229         |  $E5         |  11100101    |
+-------------+--------------+--------------+--------------+
| 180         |  200         |  $C8         |  11001000    |
+-------------+--------------+--------------+--------------+
| 181         |  204         |  $CC         |  11001100    |
+-------------+--------------+--------------+--------------+
| 182         |  232         |  $E8         |  11101000    |
+-------------+--------------+--------------+--------------+
| 183         |  236         |  $EC         |  11101100    |
+-------------+--------------+--------------+--------------+
| 184         |  205         |  $CD         |  11001101    |
+-------------+--------------+--------------+--------------+
| 185         |  233         |  $E9         |  11101001    |
+-------------+--------------+--------------+--------------+
| 186         |  237         |  $ED         |  11101101    |
+-------------+--------------+--------------+--------------+
| 187         |  130         |  $82         |  10000010    |
+-------------+--------------+--------------+--------------+
| 188         |  134         |  $86         |  10000110    |
+-------------+--------------+--------------+--------------+
| 189         |  162         |  $A2         |  10100010    |
+-------------+--------------+--------------+--------------+
| 190         |  166         |  $A6         |  10100110    |
+-------------+--------------+--------------+--------------+
| 191         |  131         |  $83         |  10000011    |
+-------------+--------------+--------------+--------------+
| 192         |  135         |  $87         |  10000111    |
+-------------+--------------+--------------+--------------+
| 193         |  163         |  $A3         |  10100011    |
+-------------+--------------+--------------+--------------+
| 194         |  167         |  $A7         |  10100111    |
+-------------+--------------+--------------+--------------+
| 195         |  138         |  $8A         |  10001010    |
+-------------+--------------+--------------+--------------+
| 196         |  142         |  $8E         |  10001110    |
+-------------+--------------+--------------+--------------+
| 197         |  174         |  $AE         |  10101110    |
+-------------+--------------+--------------+--------------+
| 198         |  139         |  $8B         |  10001011    |
+-------------+--------------+--------------+--------------+
| 199         |  175         |  $AF         |  10101111    |
+-------------+--------------+--------------+--------------+
| 200         |  194         |  $C2         |  11000010    |
+-------------+--------------+--------------+--------------+
| 201         |  226         |  $E2         |  11100010    |
+-------------+--------------+--------------+--------------+
| 202         |  230         |  $E6         |  11100110    |
+-------------+--------------+--------------+--------------+
| 203         |  195         |  $C3         |  11000011    |
+-------------+--------------+--------------+--------------+
| 204         |  202         |  $CA         |  11001010    |
+-------------+--------------+--------------+--------------+
| 205         |  206         |  $CE         |  11001110    |
+-------------+--------------+--------------+--------------+
| 206         |  234         |  $EA         |  11101010    |
+-------------+--------------+--------------+--------------+
| 207         |  238         |  $EE         |  11101110    |
+-------------+--------------+--------------+--------------+
| 208         |  203         |  $CB         |  11001011    |
+-------------+--------------+--------------+--------------+
| 209         |  207         |  $CF         |  11001111    |
+-------------+--------------+--------------+--------------+
| 210         |  144         |  $90         |  10010000    |
+-------------+--------------+--------------+--------------+
| 211         |  148         |  $94         |  10010100    |
+-------------+--------------+--------------+--------------+
| 212         |  176         |  $B0         |  10110000    |
+-------------+--------------+--------------+--------------+
| 213         |  180         |  $B4         |  10110100    |
+-------------+--------------+--------------+--------------+
| 214         |  145         |  $91         |  10010001    |
+-------------+--------------+--------------+--------------+
| 215         |  149         |  $95         |  10010101    |
+-------------+--------------+--------------+--------------+
| 216         |  177         |  $B1         |  10110001    |
+-------------+--------------+--------------+--------------+
| 217         |  181         |  $B5         |  10110101    |
+-------------+--------------+--------------+--------------+
| 218         |  152         |  $98         |  10011000    |
+-------------+--------------+--------------+--------------+
| 219         |  156         |  $9C         |  10011100    |
+-------------+--------------+--------------+--------------+
| 220         |  184         |  $B8         |  10111000    |
+-------------+--------------+--------------+--------------+
| 221         |  188         |  $BC         |  10111100    |
+-------------+--------------+--------------+--------------+
| 222         |  153         |  $99         |  10011001    |
+-------------+--------------+--------------+--------------+
| 223         |  157         |  $9D         |  10011101    |
+-------------+--------------+--------------+--------------+
| 224         |  185         |  $B9         |  10111001    |
+-------------+--------------+--------------+--------------+
| 225         |  189         |  $BD         |  10111101    |
+-------------+--------------+--------------+--------------+
| 226         |  208         |  $D0         |  11010000    |
+-------------+--------------+--------------+--------------+
| 227         |  212         |  $D4         |  11010100    |
+-------------+--------------+--------------+--------------+
| 228         |  240         |  $F0         |  11110000    |
+-------------+--------------+--------------+--------------+
| 229         |  244         |  $F4         |  11110100    |
+-------------+--------------+--------------+--------------+
| 230         |  209         |  $D1         |  11010001    |
+-------------+--------------+--------------+--------------+
| 231         |  213         |  $D5         |  11010101    |
+-------------+--------------+--------------+--------------+
| 232         |  241         |  $F1         |  11110001    |
+-------------+--------------+--------------+--------------+
| 233         |  245         |  $F5         |  11110101    |
+-------------+--------------+--------------+--------------+
| 234         |  220         |  $DC         |  11011100    |
+-------------+--------------+--------------+--------------+
| 235         |  248         |  $F8         |  11111000    |
+-------------+--------------+--------------+--------------+
| 236         |  221         |  $DD         |  11011101    |
+-------------+--------------+--------------+--------------+
| 237         |  150         |  $96         |  10010110    |
+-------------+--------------+--------------+--------------+
| 238         |  151         |  $97         |  10010111    |
+-------------+--------------+--------------+--------------+
| 239         |  179         |  $B3         |  10110011    |
+-------------+--------------+--------------+--------------+
| 240         |  154         |  $9A         |  10011010    |
+-------------+--------------+--------------+--------------+
| 241         |  158         |  $9E         |  10011110    |
+-------------+--------------+--------------+--------------+
| 242         |  186         |  $BA         |  10111010    |
+-------------+--------------+--------------+--------------+
| 243         |  190         |  $BE         |  10111110    |
+-------------+--------------+--------------+--------------+
| 244         |  155         |  $9B         |  10011011    |
+-------------+--------------+--------------+--------------+
| 245         |  159         |  $9F         |  10011111    |
+-------------+--------------+--------------+--------------+
| 246         |  187         |  $BB         |  10111011    |
+-------------+--------------+--------------+--------------+
| 247         |  191         |  $BF         |  10111111    |
+-------------+--------------+--------------+--------------+
| 248         |  214         |  $D6         |  11010110    |
+-------------+--------------+--------------+--------------+
| 249         |  242         |  $F2         |  11110010    |
+-------------+--------------+--------------+--------------+
| 250         |  246         |  $F6         |  11110110    |
+-------------+--------------+--------------+--------------+
| 251         |  211         |  $D3         |  11010011    |
+-------------+--------------+--------------+--------------+
| 252         |  215         |  $D7         |  11010111    |
+-------------+--------------+--------------+--------------+
| 253         |  222         |  $DE         |  11011110    |
+-------------+--------------+--------------+--------------+
| 254         |  250         |  $FA         |  11111010    |
+-------------+--------------+--------------+--------------+
| 255         |  223         |  $DF         |  11011111    |
+-------------+--------------+--------------+--------------+

**Example**

The following program for SMSQ/E will show the full range of colours
available on Aurora. Note the need to explicitly wipe the screen - this
is because MODE would normally do this for you.

::

            100 MODE 4
            110 POKE $18043,156 : REMark force switch to MODE 256:COLOUR_PAL
            120 :
            130 scr_offset=SCR_BASE(#1)
            140 scr_len=512:REMark SCR_LLEN returns the wrong figure in this mode
            150 :
            160 REMark Blank out screen
            170 col=0
            180 FOR i%=0 TO 479
            190   FOR j%=0 TO 508 STEP 4
            200     POKE_L scr_offset+i%*scr_len+j%,col
            210   END FOR j%
            220 END FOR i%
            230 :
            240 REMark Draw Colours
            250 yoff=20
            260 FOR i=0 TO 15
            270   xoff=0
            280   FOR j=0 TO 15
            290     col=i*16+j
            300     scr_offset=yoff*scr_len+xoff+SCR_BASE(#1)
            310     FOR a=0 TO 10
            320       FOR b=0 TO 10
            330         POKE scr_offset+a*scr_len+b,col
            340       END FOR b
            350     END FOR a
            360     xoff=xoff+12
            370   END FOR j
            380 yoff=yoff+12
            390 END FOR i

QPC/QXL Enhanced Colour Drivers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

SMSQ/E v2.98+ provides various colour modes for QPC2 and the QXL card.
You can configure SMSQ/E to start with either the Standard QL Colour
Drivers or the Enhanced Colour Drivers. If the Enhanced Colour Drivers
are loaded, RMODE will return 32.

The Enhanced Colour Drivers support a QL 8 colour mode (selected with
COLOUR\_QL), a PAL Colour Mode providing 256 colours (selected with
COLOUR\_PAL), a Native Colour Mode providing 65536 colours (select with
COLOUR\_NATIVE) and a 24 bit colour mode providing over 16 million
colours (select with COLOUR\_24).

QL Colour Mode (COLOUR\_QL)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is similar to MODE 4 under the Standard QL Colour Drivers and is
provided for compatability. However all 8 standard MODE 8 colours are
actually available. See INK for a list of the standard MODE 8 colours.

PAL Colour Mode (COLOUR\_PAL)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This allows programs to use 256 colours - it is the simplest mode to
use, since a standard PAL Colour Value is used by any standard colour
commands, such as INK, to describe all 256 colours on all
implementations (including Aurora).

The table on the following pages describes all 256 colours with the PAL
Colour Value and their Native Colour Value in decimal, hexadecimal and
binary (see below).

You can use PALETTE\_8 to change the 256 colours available.

Native Colour Mode (COLOUR\_NATIVE)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

As with the Q40/Q60, this allows programs to use 65536 colours. However,
the Native Colour Values required for INK, STRIP, PAPER etc. depend upon
the hardware (ie. they are different to Q40/Q60 values). The colour is
described by the actual value which would be POKEd into the video
memory, hence two bytes (a word) represent the colour of one pixel on
the Monitor's screen. It is therefore easier to use Hexadecimal values
to represent each colour.

The bits in the word represent the amount of GREEN, RED and BLUE to be
used for each pixel, in the format **RRRRRGGG GGGBBBBB**, where:

- G is Green (6 bits)

- R is Red (5 bits)

- B is Blue (5 bits)

The table on the following pages describes the first 256 colours with
the PAL Colour Value and their Native Colour Value in decimal,
hexadecimal and binary (see below).

**NOTE:** 
When the values are entered direct into memory with a POKE
command or machine code routine, due to the organisation of memory on a
PC, it is necessary to enter the low byte before the high byte. As a
result, the value for red, in binary 11111000 00000000 (INK $F800) is
entered as POKE address,$00F8.

24 Bit Colour Mode (COLOUR\_24)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is supported only on PCs with 24 bit graphics cards. However, it is
essential to understand this mode as commands such as PALETTE\_8 and
PALETTE\_QL expect colours to be described in this format. The details
appear later in this Appendix.

**Colour Table**

Due to the range of colours available, it is hard to describe each
colour; therefore it will require experimentation to obtain the correct
colours. The following table details the PAL Colour Value and Native
Colour Value for each colour which need to be used for INK and similar
commands.

**NOTE**
This does not correspond with the orignal QL colour scheme!. 

We have tried to list the most widely used ones (INK 0 to INK 63 under
COLOUR\_PAL) grouped into the different colours followed by the values
for the remainder of the first 256 colours. Conversion of the values to
binary gives a clue as to how this colour scheme works:

+-------------+-----------------+--------------+-------------------+
|                               |         RRRRRGGG GGGBBBBB        |
+-------------+-----------------+--------------+-------------------+
| PAL Colour  | Colour          | Native Value | Native Value      |
| Value       | Name            | (Hex)        | (Binary)          |
+=============+=================+==============+===================+
|   0         | Black           | $0000        | 00000000 00000000 |
+-------------+-----------------+--------------+-------------------+
|   1         | White           | $FFFF        | 11111111 11111111 |
+-------------+-----------------+--------------+-------------------+
|   8         | Dark Slate      | $2124        | 00100001 00100100 |
+-------------+-----------------+--------------+-------------------+
|   9         | Slate Grey      | $4A49        | 01001010 01001001 |
+-------------+-----------------+--------------+-------------------+
|  10         | Dark Grey       | $6B6D        | 01101011 01101101 |
+-------------+-----------------+--------------+-------------------+
|  11         | Grey            | $9492        | 10010100 10010010 |
+-------------+-----------------+--------------+-------------------+
|  12         | Light Grey      | $B5B6        | 10110101 10110110 |
+-------------+-----------------+--------------+-------------------+
|  13         | Ash Grey        | $DEDB        | 11011110 11011011 |
+-------------+-----------------+--------------+-------------------+
|  58         | Cerise          | $9009        | 10010000 00001001 |
+-------------+-----------------+--------------+-------------------+
|  14         | Dark Red        | $9000        | 10010000 00000000 |
+-------------+-----------------+--------------+-------------------+
|   2         | Red             | $F800        | 11111000 00000000 |
+-------------+-----------------+--------------+-------------------+
|  63         | Deep Purple     | $4812        | 01001000 00010010 |
+-------------+-----------------+--------------+-------------------+
|  51         | Plum            | $692D        | 01101001 00101101 |
+-------------+-----------------+--------------+-------------------+
|  20         | Purple          | $9012        | 10010000 00010010 |
+-------------+-----------------+--------------+-------------------+
|  26         | Mauve           | $901F        | 10010000 00011111 |
+-------------+-----------------+--------------+-------------------+
|  57         | Faded Purple    | $9256        | 10010010 01010110 |
+-------------+-----------------+--------------+-------------------+
|  52         | Dusky Pink      | $B252        | 10110010 01010010 |
+-------------+-----------------+--------------+-------------------+
|   5         | Magenta         | $F81F        | 11111000 00011111 |
+-------------+-----------------+--------------+-------------------+
|  21         | Shocking Pink   | $F812        | 11111000 00010010 |
+-------------+-----------------+--------------+-------------------+
|  45         | Dull Pink       | $B376        | 10110011 01110110 |
+-------------+-----------------+--------------+-------------------+
|  32         | Pink            | $FDBB        | 11111101 10111011 |
+-------------+-----------------+--------------+-------------------+
|  31         | Rose Pink       | $FDBF        | 11111101 10111111 |
+-------------+-----------------+--------------+-------------------+
|  34         | Pastel Pink     | $FEDB        | 11111110 11011011 |
+-------------+-----------------+--------------+-------------------+
|  39         | Pastel Rose     | $FEDF        | 11111110 11011111 |
+-------------+-----------------+--------------+-------------------+
|  27         | Peach           | $FDB6        | 11111101 10110110 |
+-------------+-----------------+--------------+-------------------+
|  50         | Midnight Blue   | $212D        | 00100001 00101101 |
+-------------+-----------------+--------------+-------------------+
|  19         | Dark Blue       | $0012        | 00000000 00010010 |
+-------------+-----------------+--------------+-------------------+
|   4         | Blue            | $001F        | 00000000 00011111 |
+-------------+-----------------+--------------+-------------------+
|  62         | Ultramarine     | $0252        | 00000010 01010010 |
+-------------+-----------------+--------------+-------------------+
|  49         | Dusky Blue      | $236D        | 00100011 01101101 |
+-------------+-----------------+--------------+-------------------+
|  44         | Steel Blue      | $6B76        | 01101011 01110110 |
+-------------+-----------------+--------------+-------------------+
|  18         | Sea Blue        | $0492        | 00000100 10010010 |
+-------------+-----------------+--------------+-------------------+
|  25         | Bright Blue     | $049F        | 00000100 10011111 |
+-------------+-----------------+--------------+-------------------+
|  56         | Dull Blue       | $4C96        | 01001100 10010110 |
+-------------+-----------------+--------------+-------------------+
|  43         | Dull Cyan       | $6DB6        | 01101101 10110110 |
+-------------+-----------------+--------------+-------------------+
|   7         | Cyan            | $07FF        | 00000111 11111111 |
+-------------+-----------------+--------------+-------------------+
|  29         | Light Blue      | $B7FF        | 10110111 11111111 |
+-------------+-----------------+--------------+-------------------+
|  30         | Sky Blue        | $B5BF        | 10110101 10111111 |
+-------------+-----------------+--------------+-------------------+
|  38         | Pastel Blue     | $DEDF        | 11011110 11011111 |
+-------------+-----------------+--------------+-------------------+
|  37         | Pastel Cyan     | $DFFF        | 11011111 11111111 |
+-------------+-----------------+--------------+-------------------+
|  48         | Dusky Green     | $2364        | 00100011 01100100 |
+-------------+-----------------+--------------+-------------------+
|  60         | Grass Green     | $4C80        | 01001100 10000000 |
+-------------+-----------------+--------------+-------------------+
|  17         | Dark Green      | $0480        | 00000100 10000000 |
+-------------+-----------------+--------------+-------------------+
|  54         | Avocado         | $95A9        | 10010101 10101001 |
+-------------+-----------------+--------------+-------------------+
|  61         | Sea Green       | $0489        | 00000100 10001001 |
+-------------+-----------------+--------------+-------------------+
|  42         | Dull Green      | $6DAD        | 01101101 10101101 |
+-------------+-----------------+--------------+-------------------+
|   3         | Green           | $07E0        | 00000111 11100000 |
+-------------+-----------------+--------------+-------------------+
|  23         | Lime Green      | $97E0        | 10010111 11100000 |
+-------------+-----------------+--------------+-------------------+
|  24         | Apple Green     | $07F2        | 00000111 11110010 |
+-------------+-----------------+--------------+-------------------+
|  55         | Dull Turquoise  | $4DB2        | 01001101 10110010 |
+-------------+-----------------+--------------+-------------------+
|  41         | Light Khaki     | $B5AD        | 10110101 10101101 |
+-------------+-----------------+--------------+-------------------+
|  15         | Light Green     | $B7F6        | 10110111 11110110 |
+-------------+-----------------+--------------+-------------------+
|  36         | Pastel Green    | $DFFB        | 11011111 11111011 |
+-------------+-----------------+--------------+-------------------+
|  46         | Brown           | $6924        | 01101001 00100100 |
+-------------+-----------------+--------------+-------------------+
|  59         | Tan             | $9240        | 10010010 01000000 |
+-------------+-----------------+--------------+-------------------+
|   6         | Yellow          | $FFE0        | 11111111 11100000 |
+-------------+-----------------+--------------+-------------------+
|  22         | Orange          | $FC80        | 11111100 10000000 |
+-------------+-----------------+--------------+-------------------+
|  16         | Mustard         | $9480        | 10010100 10000000 |
+-------------+-----------------+--------------+-------------------+
|  47         | Khaki           | $6B64        | 01101011 01100100 |
+-------------+-----------------+--------------+-------------------+
|  53         | Buff            | $B489        | 10110100 10001001 |
+-------------+-----------------+--------------+-------------------+
|  40         | Brick           | $B36D        | 10110011 01101101 |
+-------------+-----------------+--------------+-------------------+
|  33         | Beige           | $FED6        | 11111110 11010110 |
+-------------+-----------------+--------------+-------------------+
|  28         | Light Yellow    | $FFF6        | 11111111 11110110 |
+-------------+-----------------+--------------+-------------------+
|  35         | Pastel Yellow   | $FFFB        | 11111111 11111011 |
+-------------+-----------------+--------------+-------------------+
              

The remainder of the first 256 colours are mapped as follows (we would
welcome names for each of these colours):

+-------------+--------------+-------------------+
|             |         RRRRRGGG GGGBBBBB        |
+-------------+--------------+-------------------+
| PAL Colour  | Native Value | Native Value      |
| Value       | (Hex)        | (Binary)          |
+=============+==============+===================+
|  64         | $0009        | 00000000 00001001 |
+-------------+--------------+-------------------+
|  65         | $2004        | 00100000 00000100 |
+-------------+--------------+-------------------+
|  66         | $200D        | 00100000 00001101 |
+-------------+--------------+-------------------+
|  67         | $2016        | 00100000 00010110 |
+-------------+--------------+-------------------+
|  68         | $201F        | 00100000 00011111 |
+-------------+--------------+-------------------+
|  69         | $4800        | 01001000 00000000 |
+-------------+--------------+-------------------+
|  70         | $4809        | 01001000 00001001 |
+-------------+--------------+-------------------+
|  71         | $481B        | 01001000 00011011 |
+-------------+--------------+-------------------+
|  72         | $6804        | 01101000 00000100 |
+-------------+--------------+-------------------+
|  73         | $680D        | 01101000 00001101 |
+-------------+--------------+-------------------+
|  74         | $6816        | 01101000 00010110 |
+-------------+--------------+-------------------+
|  75         | $681F        | 01101000 00011111 |
+-------------+--------------+-------------------+
|  76         | $B004        | 10110000 00000100 |
+-------------+--------------+-------------------+
|  77         | $B00D        | 10110000 00001101 |
+-------------+--------------+-------------------+
|  78         | $B016        | 10110000 00010110 |
+-------------+--------------+-------------------+
|  79         | $B01F        | 10110000 00011111 |
+-------------+--------------+-------------------+
|  80         | $D800        | 11011000 00000000 |
+-------------+--------------+-------------------+
|  81         | $D809        | 11011000 00001001 |
+-------------+--------------+-------------------+
|  82         | $D812        | 11011000 00010010 |
+-------------+--------------+-------------------+
|  83         | $D81B        | 11011000 00011011 |
+-------------+--------------+-------------------+
|  84         | $F80D        | 11111000 00001101 |
+-------------+--------------+-------------------+
|  85         | $0120        | 00000001 00100000 |
+-------------+--------------+-------------------+
|  86         | $0129        | 00000001 00101001 |
+-------------+--------------+-------------------+
|  87         | $0132        | 00000001 00110010 |
+-------------+--------------+-------------------+
|  88         | $013B        | 00000001 00111011 |
+-------------+--------------+-------------------+
|  89         | $2136        | 00100001 00110110 |
+-------------+--------------+-------------------+
|  90         | $213F        | 00100001 00111111 |
+-------------+--------------+-------------------+
|  91         | $4920        | 01001001 00100000 |
+-------------+--------------+-------------------+
|  92         | $4929        | 01001001 00101001 |
+-------------+--------------+-------------------+
|  93         | $4932        | 01001001 00110010 |
+-------------+--------------+-------------------+
|  94         | $493B        | 01001001 00111011 |
+-------------+--------------+-------------------+
|  95         | $6936        | 01101001 00110110 |
+-------------+--------------+-------------------+
|  96         | $693F        | 01101001 00111111 |
+-------------+--------------+-------------------+
|  97         | $9120        | 10010001 00100000 |
+-------------+--------------+-------------------+
|  98         | $9129        | 10010001 00101001 |
+-------------+--------------+-------------------+
|  99         | $9132        | 10010001 00110010 |
+-------------+--------------+-------------------+
| 100         | $913B        | 10010001 00111011 |
+-------------+--------------+-------------------+
| 101         | $B124        | 10110001 00100100 |
+-------------+--------------+-------------------+
| 102         | $B12D        | 10110001 00101101 |
+-------------+--------------+-------------------+
| 103         | $B136        | 10110001 00110110 |
+-------------+--------------+-------------------+
| 104         | $B13F        | 10110001 00111111 |
+-------------+--------------+-------------------+
| 105         | $D920        | 11011001 00100000 |
+-------------+--------------+-------------------+
| 106         | $D929        | 11011001 00101001 |
+-------------+--------------+-------------------+
| 107         | $D932        | 11011001 00110010 |
+-------------+--------------+-------------------+
| 108         | $D93B        | 11011001 00111011 |
+-------------+--------------+-------------------+
| 109         | $F924        | 11111001 00100100 |
+-------------+--------------+-------------------+
| 110         | $F92D        | 11111001 00101101 |
+-------------+--------------+-------------------+
| 111         | $F936        | 11111001 00110110 |
+-------------+--------------+-------------------+
| 112         | $F93F        | 11111001 00111111 |
+-------------+--------------+-------------------+
| 113         | $0240        | 00000010 01000000 |
+-------------+--------------+-------------------+
| 114         | $0249        | 00000010 01001001 |
+-------------+--------------+-------------------+
| 115         | $025B        | 00000010 01011011 |
+-------------+--------------+-------------------+
| 116         | $2244        | 00100010 01000100 |
+-------------+--------------+-------------------+
| 117         | $224D        | 00100010 01001101 |
+-------------+--------------+-------------------+
| 118         | $2256        | 00100010 01010110 |
+-------------+--------------+-------------------+
| 119         | $225F        | 00100010 01011111 |
+-------------+--------------+-------------------+
| 120         | $4A40        | 01001010 01000000 |
+-------------+--------------+-------------------+
| 121         | $4A52        | 01001010 01010010 |
+-------------+--------------+-------------------+
| 122         | $4A5B        | 01001010 01011011 |
+-------------+--------------+-------------------+
| 123         | $6A44        | 01101010 01000100 |
+-------------+--------------+-------------------+
| 124         | $6A4D        | 01101010 01001101 |
+-------------+--------------+-------------------+
| 125         | $6456        | 01100100 01010110 |
+-------------+--------------+-------------------+
| 126         | $6A5F        | 01101010 01011111 |
+-------------+--------------+-------------------+
| 127         | $9249        | 10010010 01001001 |
+-------------+--------------+-------------------+
| 128         | $925B        | 10010010 01011011 |
+-------------+--------------+-------------------+
| 129         | $B244        | 10110010 01000100 |
+-------------+--------------+-------------------+
| 130         | $B24D        | 10110010 01001101 |
+-------------+--------------+-------------------+
| 131         | $B25F        | 10110010 01011111 |
+-------------+--------------+-------------------+
| 132         | $DA40        | 11011010 01000000 |
+-------------+--------------+-------------------+
| 133         | $DA49        | 11011010 01001001 |
+-------------+--------------+-------------------+
| 134         | $DA52        | 11011010 01010010 |
+-------------+--------------+-------------------+
| 135         | $DA5B        | 11011010 01011011 |
+-------------+--------------+-------------------+
| 136         | $FA44        | 11111010 01000100 |
+-------------+--------------+-------------------+
| 137         | $FA4D        | 11111010 01001101 |
+-------------+--------------+-------------------+
| 138         | $FA56        | 11111010 01010110 |
+-------------+--------------+-------------------+
| 139         | $FA5F        | 11111010 01011111 |
+-------------+--------------+-------------------+
| 140         | $0360        | 00000011 01100000 |
+-------------+--------------+-------------------+
| 141         | $0369        | 00000011 01101001 |
+-------------+--------------+-------------------+
| 142         | $0372        | 00000011 01110010 |
+-------------+--------------+-------------------+
| 143         | $037B        | 00000011 01111011 |
+-------------+--------------+-------------------+
| 144         | $2376        | 00100011 01110110 |
+-------------+--------------+-------------------+
| 145         | $237F        | 00100011 01111111 |
+-------------+--------------+-------------------+
| 146         | $4B60        | 01001011 01100000 |
+-------------+--------------+-------------------+
| 147         | $4B69        | 01001011 01101001 |
+-------------+--------------+-------------------+
| 148         | $4B72        | 01001011 01110010 |
+-------------+--------------+-------------------+
| 149         | $4B7B        | 01001011 01111011 |
+-------------+--------------+-------------------+
| 150         | $6B7F        | 01101011 01111111 |
+-------------+--------------+-------------------+
| 151         | $9360        | 10010011 01100000 |
+-------------+--------------+-------------------+
| 152         | $9369        | 10010011 01101001 |
+-------------+--------------+-------------------+
| 153         | $9372        | 10010011 01110010 |
+-------------+--------------+-------------------+
| 154         | $937B        | 10010011 01111011 |
+-------------+--------------+-------------------+
| 155         | $B364        | 10110011 01100100 |
+-------------+--------------+-------------------+
| 156         | $B37F        | 10110011 01111111 |
+-------------+--------------+-------------------+
| 157         | $DB60        | 11011011 01100000 |
+-------------+--------------+-------------------+
| 158         | $DB69        | 11011011 01101001 |
+-------------+--------------+-------------------+
| 159         | $DB72        | 11011011 01110010 |
+-------------+--------------+-------------------+
| 160         | $DB7B        | 11011011 01111011 |
+-------------+--------------+-------------------+
| 161         | $FB64        | 11111011 01100100 |
+-------------+--------------+-------------------+
| 162         | $FB6D        | 11111011 01101101 |
+-------------+--------------+-------------------+
| 163         | $FB76        | 11111011 01110110 |
+-------------+--------------+-------------------+
| 164         | $FB7F        | 11111011 01111111 |
+-------------+--------------+-------------------+
| 165         | $2484        | 00100100 10000100 |
+-------------+--------------+-------------------+
| 166         | $248D        | 00100100 10001101 |
+-------------+--------------+-------------------+
| 167         | $2496        | 00100100 10010110 |
+-------------+--------------+-------------------+
| 168         | $249F        | 00100100 10011111 |
+-------------+--------------+-------------------+
| 169         | $4C89        | 01001100 10001001 |
+-------------+--------------+-------------------+
| 170         | $4C9B        | 01001100 10011011 |
+-------------+--------------+-------------------+
| 171         | $6C84        | 01101100 10000100 |
+-------------+--------------+-------------------+
| 172         | $6C8D        | 01101100 10001101 |
+-------------+--------------+-------------------+
| 173         | $6C96        | 01101100 10010110 |
+-------------+--------------+-------------------+
| 174         | $6C9F        | 01101100 10011111 |
+-------------+--------------+-------------------+
| 175         | $9489        | 10010100 10001001 |
+-------------+--------------+-------------------+
| 176         | $948B        | 10010100 10001011 |
+-------------+--------------+-------------------+
| 177         | $B484        | 10110100 10000100 |
+-------------+--------------+-------------------+
| 178         | $B496        | 10110100 10010110 |
+-------------+--------------+-------------------+
| 179         | $B49F        | 10110100 10011111 |
+-------------+--------------+-------------------+
| 180         | $DC80        | 11011100 10000000 |
+-------------+--------------+-------------------+
| 181         | $DC89        | 11011100 10001001 |
+-------------+--------------+-------------------+
| 182         | $DC92        | 11011100 10010010 |
+-------------+--------------+-------------------+
| 183         | $DC9B        | 11011100 10011011 |
+-------------+--------------+-------------------+
| 184         | $FC8D        | 11111100 10001101 |
+-------------+--------------+-------------------+
| 185         | $FC96        | 11111100 10010110 |
+-------------+--------------+-------------------+
| 186         | $FC9F        | 11111100 10011111 |
+-------------+--------------+-------------------+
| 187         | $05A0        | 00000101 10100000 |
+-------------+--------------+-------------------+
| 188         | $05A9        | 00000101 10101001 |
+-------------+--------------+-------------------+
| 189         | $05B2        | 00000101 10110010 |
+-------------+--------------+-------------------+
| 190         | $05BB        | 00000101 10111011 |
+-------------+--------------+-------------------+
| 191         | $25A4        | 00100101 10100100 |
+-------------+--------------+-------------------+
| 192         | $25AD        | 00100101 10101101 |
+-------------+--------------+-------------------+
| 193         | $25B6        | 00100101 10110110 |
+-------------+--------------+-------------------+
| 194         | $25BF        | 00100101 10111111 |
+-------------+--------------+-------------------+
| 195         | $4DA0        | 01001101 10100000 |
+-------------+--------------+-------------------+
| 196         | $4DA9        | 01001101 10101001 |
+-------------+--------------+-------------------+
| 197         | $4DBB        | 01001101 10111011 |
+-------------+--------------+-------------------+
| 198         | $6DA4        | 01101101 10100100 |
+-------------+--------------+-------------------+
| 199         | $6DBF        | 01101101 10111111 |
+-------------+--------------+-------------------+
| 200         | $95A0        | 10010101 10100000 |
+-------------+--------------+-------------------+
| 201         | $95B2        | 10010101 10110010 |
+-------------+--------------+-------------------+
| 202         | $95BB        | 10010101 10111011 |
+-------------+--------------+-------------------+
| 203         | $B5A4        | 10110101 10100100 |
+-------------+--------------+-------------------+
| 204         | $DDA0        | 11011101 10100000 |
+-------------+--------------+-------------------+
| 205         | $DDA9        | 11011101 10101001 |
+-------------+--------------+-------------------+
| 206         | $DDB2        | 11011101 10110010 |
+-------------+--------------+-------------------+
| 207         | $DDBB        | 11011101 10111011 |
+-------------+--------------+-------------------+
| 208         | $FDA4        | 11111101 10100100 |
+-------------+--------------+-------------------+
| 209         | $FDAD        | 11111101 10101101 |
+-------------+--------------+-------------------+
| 210         | $06C0        | 00000110 11000000 |
+-------------+--------------+-------------------+
| 211         | $06C9        | 00000110 11001001 |
+-------------+--------------+-------------------+
| 212         | $06D2        | 00000110 11010010 |
+-------------+--------------+-------------------+
| 213         | $06DB        | 00000110 11011011 |
+-------------+--------------+-------------------+
| 214         | $26C4        | 00100110 11000100 |
+-------------+--------------+-------------------+
| 215         | $26CD        | 00100110 11001101 |
+-------------+--------------+-------------------+
| 216         | $26D6        | 00100110 11010110 |
+-------------+--------------+-------------------+
| 217         | $26DF        | 00100110 11011111 |
+-------------+--------------+-------------------+
| 218         | $4EC0        | 01001110 11000000 |
+-------------+--------------+-------------------+
| 219         | $4EC9        | 01001110 11001001 |
+-------------+--------------+-------------------+
| 220         | $4ED2        | 01001110 11010010 |
+-------------+--------------+-------------------+
| 221         | $4EDB        | 01001110 11011011 |
+-------------+--------------+-------------------+
| 222         | $6EC4        | 01101110 11000100 |
+-------------+--------------+-------------------+
| 223         | $6ECD        | 01101110 11001101 |
+-------------+--------------+-------------------+
| 224         | $6ED6        | 01101110 11010110 |
+-------------+--------------+-------------------+
| 225         | $6EDF        | 01101110 11011111 |
+-------------+--------------+-------------------+
| 226         | $96C0        | 10010110 11000000 |
+-------------+--------------+-------------------+
| 227         | $96C9        | 10010110 11001001 |
+-------------+--------------+-------------------+
| 228         | $96D2        | 10010110 11010010 |
+-------------+--------------+-------------------+
| 229         | $96DB        | 10010110 11011011 |
+-------------+--------------+-------------------+
| 230         | $B6C4        | 10110110 11000100 |
+-------------+--------------+-------------------+
| 231         | $B6CD        | 10110110 11001101 |
+-------------+--------------+-------------------+
| 232         | $B6D6        | 10110110 11010110 |
+-------------+--------------+-------------------+
| 233         | $B6DF        | 10110110 11011111 |
+-------------+--------------+-------------------+
| 234         | $DEC9        | 11011110 11001001 |
+-------------+--------------+-------------------+
| 235         | $DED2        | 11011110 11010010 |
+-------------+--------------+-------------------+
| 236         | $FECD        | 11111110 11001101 |
+-------------+--------------+-------------------+
| 237         | $07E9        | 00000111 11101001 |
+-------------+--------------+-------------------+
| 238         | $27ED        | 00100111 11101101 |
+-------------+--------------+-------------------+
| 239         | $27F6        | 00100111 11110110 |
+-------------+--------------+-------------------+
| 240         | $4FE0        | 01001111 11100000 |
+-------------+--------------+-------------------+
| 241         | $4FE9        | 01001111 11101001 |
+-------------+--------------+-------------------+
| 242         | $4FF2        | 01001111 11110010 |
+-------------+--------------+-------------------+
| 243         | $4FFB        | 01001111 11111011 |
+-------------+--------------+-------------------+
| 244         | $6FE4        | 01101111 11100100 |
+-------------+--------------+-------------------+
| 245         | $6FED        | 01101111 11101101 |
+-------------+--------------+-------------------+
| 246         | $6FF6        | 01101111 11110110 |
+-------------+--------------+-------------------+
| 247         | $6FFF        | 01101111 11111111 |
+-------------+--------------+-------------------+
| 248         | $97E9        | 10010111 11101001 |
+-------------+--------------+-------------------+
| 249         | $97F2        | 10010111 11110010 |
+-------------+--------------+-------------------+
| 250         | $97FB        | 10010111 11111011 |
+-------------+--------------+-------------------+
| 251         | $B7E4        | 10110111 11100100 |
+-------------+--------------+-------------------+
| 252         | $B7ED        | 10110111 11101101 |
+-------------+--------------+-------------------+
| 253         | $DFE9        | 11011111 11101001 |
+-------------+--------------+-------------------+
| 254         | $DFF2        | 11011111 11110010 |
+-------------+--------------+-------------------+
| 255         | $FFED        | 11111111 11101101 |
+-------------+--------------+-------------------+

Q40/Q60 Enhanced Colour Drivers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

SMSQ/E v2.98+ provides various colour modes for the Q40 and Q60
computers. You can configure SMSQ/E to start with either the Standard QL
Colour Drivers or the Enhanced Colour Drivers. If the Enhanced Colour
Drivers are loaded, RMODE will return 33.

The Enhanced Colour Drivers support a QL 8 colour mode (selected with
COLOUR\_QL), a PAL Colour Mode providing 256 colours (selected with
COLOUR\_PAL) and a Native Colour Mode providing 65536 colours (select
with COLOUR\_NATIVE). As with the other implementations, 24 bit colours
are used by commands such as PALETTE\_8, although there is no 24 bit
colour mode due to the limitations of the hardware.

QL Colour Mode (COLOUR\_QL)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is similar to MODE 4 under the Standard QL Colour Drivers and is
provided for compatability. However all 8 standard MODE 8 colours are
actually available. See INK for a list of the standard MODE 8 colours.

PAL Colour Mode (COLOUR\_PAL)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This allows programs to use 256 colours - it is the simplest mode to
use, since a standard PAL Colour Value is used by any standard colour
commands, such as INK, to describe all 256 colours on all
implementations (including Aurora).

The table on the following pages describes all 256 colours with the PAL
Colour Value and their Native Colour Value in decimal, hexadecimal and
binary (see below).

You can use PALETTE\_8 to change the 256 colours available.

Native Colour Mode (COLOUR\_NATIVE)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

As with QXL and QPC2, this allows programs to use 65536 colours.
However, the Native Colour Values required for INK, STRIP, PAPER etc.
depend upon the hardware (ie. they are different to the QPC2/QXL
values). The colour is described by the actual value which would be
POKEd into the video memory, hence two bytes (a word) represent the
colour of one pixel on the Monitor's screen. It is therefore easier to
use Hexadecimal values to represent each colour.

The bits in the word represent the amount of GREEN, RED and BLUE to be
used for each pixel, in the format **GGGGGRRR RRBBBBBW**, where:

- G is Green (5 bits)

- R Red (5 bits)

- B Blue (5 bits)

- W White

The table on the following pages describes the first 256 colours with
the PAL Colour Value and their Native Colour Value in decimal,
hexadecimal and binary (see below).

**Colour Table**

Due to the range of colours available, it is hard to describe each
colour; therefore it will require experimentation to obtain the correct
colours. The following table details the PAL Colour Value and Native
Colour Value for each colour which need to be used for INK and similar
commands (**NOTE** this does not correspond with the orignal QL colour
scheme!). We have tried to list the most widely used ones (INK 0 to INK
63 under COLOUR\_PAL) grouped into the different colours followed by the
values for the remainder of the first 256 colours. Conversion of the
values to binary gives a clue as to how this colour scheme works:

+-------------+----------------+--------------+-------------------+
|             |         GGGGGRRR RRBBBBBW                         |
+-------------+----------------+--------------+-------------------+
| PAL Colour  | Colour         | Native Value | Native Value      |
| Value       | Name           | Hex          | Binary            |
+=============+================+==============+===================+
|  0          | Black          | $0000        | 00000000 00000000 |
+-------------+----------------+--------------+-------------------+
|  1          | White          | $FFFF        | 11111111 11111111 |
+-------------+----------------+--------------+-------------------+
|  8          | Dark Slate     | $2108        | 00100001 00001000 |
+-------------+----------------+--------------+-------------------+
|  9          | Slate Grey     | $4A53        | 01001010 01010011 |
+-------------+----------------+--------------+-------------------+
| 10          | Dark Grey      | $6B5B        | 01101011 01011011 |
+-------------+----------------+--------------+-------------------+
| 11          | Grey           | $94A4        | 10010100 10100100 |
+-------------+----------------+--------------+-------------------+
| 12          | Light Grey     | $B5AC        | 10110101 10101100 |
+-------------+----------------+--------------+-------------------+
| 13          | Ash Grey       | $DEF7        | 11011110 11110111 |
+-------------+----------------+--------------+-------------------+
| 58          | Cerise         | $0492        | 00000100 10010010 |
+-------------+----------------+--------------+-------------------+
| 14          | Dark Red       | $0480        | 00000100 10000000 |
+-------------+----------------+--------------+-------------------+
|  2          | Red            | $07C0        | 00000111 11000000 |
+-------------+----------------+--------------+-------------------+
| 63          | Deep Purple    | $0264        | 00000010 01100100 |
+-------------+----------------+--------------+-------------------+
| 51          | Plum           | $235B        | 00100011 01011011 |
+-------------+----------------+--------------+-------------------+
| 20          | Purple         | $04A4        | 00000100 10100100 |
+-------------+----------------+--------------+-------------------+
| 26          | Mauve          | $04BE        | 00000100 10111110 |
+-------------+----------------+--------------+-------------------+
| 57          | Faded Purple   | $4CAC        | 01001100 10101100 |
+-------------+----------------+--------------+-------------------+
| 52          | Dusky Pink     | $4DA4        | 01001101 10100100 |
+-------------+----------------+--------------+-------------------+
|  5          | Magenta        | $07FF        | 00000111 11111111 |
+-------------+----------------+--------------+-------------------+
| 21          | Shocking Pink  | $07E4        | 00000111 11100100 |
+-------------+----------------+--------------+-------------------+
| 45          | Dull Pink      | $6DAC        | 01101101 10101100 |
+-------------+----------------+--------------+-------------------+
| 32          | Pink           | $B7F7        | 10110111 11110111 |
+-------------+----------------+--------------+-------------------+
| 31          | Rose Pink      | $B7FF        | 10110111 11111111 | 
+-------------+----------------+--------------+-------------------+
| 34          | Pastel Pink    | $DFF7        | 11011111 11110111 | 
+-------------+----------------+--------------+-------------------+
| 39          | Pastel Rose    | $DFFF        | 11011111 11111111 | 
+-------------+----------------+--------------+-------------------+
| 27          | Peach          | $B7EC        | 10110111 11101100 | 
+-------------+----------------+--------------+-------------------+
| 50          | Midnight Blue  | $211A        | 00100001 00011010 | 
+-------------+----------------+--------------+-------------------+
| 19          | Dark Blue      | $0024        | 00000000 00100100 | 
+-------------+----------------+--------------+-------------------+
|  4          | Blue           | $003E        | 00000000 00111110 | 
+-------------+----------------+--------------+-------------------+
| 62          | Ultramarine    | $4824        | 01001000 00100100 | 
+-------------+----------------+--------------+-------------------+
| 49          | Dusky Blue     | $691B        | 01101001 00011011 | 
+-------------+----------------+--------------+-------------------+
| 44          | Steel Blue     | $6B6D        | 01101011 01101101 | 
+-------------+----------------+--------------+-------------------+
| 18          | Sea Blue       | $9024        | 10010000 00100100 | 
+-------------+----------------+--------------+-------------------+
| 25          | Bright Blue    | $903E        | 10010000 00111110 | 
+-------------+----------------+--------------+-------------------+
| 56          | Dull Blue      | $926C        | 10010010 01101100 | 
+-------------+----------------+--------------+-------------------+
| 43          | Dull Cyan      | $B36C        | 10110011 01101100 | 
+-------------+----------------+--------------+-------------------+
|  7          | Cyan           | $F83F        | 11111000 00111111 | 
+-------------+----------------+--------------+-------------------+
| 29          | Light Blue     | $FDBF        | 11111101 10111111 | 
+-------------+----------------+--------------+-------------------+
| 30          | Sky Blue       | $B5BE        | 10110101 10111110 | 
+-------------+----------------+--------------+-------------------+
| 38          | Pastel Blue    | $DEFF        | 11011110 11111111 | 
+-------------+----------------+--------------+-------------------+
| 37          | Pastel Cyan    | $FEFF        | 11111110 11111111 | 
+-------------+----------------+--------------+-------------------+
| 48          | Dusky Green    | $6908        | 01101001 00001000 | 
+-------------+----------------+--------------+-------------------+
| 60          | Grass Green    | $9240        | 10010010 01000000 | 
+-------------+----------------+--------------+-------------------+
| 17          | Dark Green     | $9000        | 10010000 00000000 | 
+-------------+----------------+--------------+-------------------+
| 54          | Avocado        | $B492        | 10110100 10010010 | 
+-------------+----------------+--------------+-------------------+
| 61          | Sea Green      | $9012        | 10010000 00010010 | 
+-------------+----------------+--------------+-------------------+
| 42          | Dull Green     | $B35B        | 10110011 01011011 | 
+-------------+----------------+--------------+-------------------+
|  3          | Green          | $F800        | 11111000 00000000 | 
+-------------+----------------+--------------+-------------------+
| 23          | Lime Green     | $FC80        | 11111100 10000000 | 
+-------------+----------------+--------------+-------------------+
| 24          | Apple Green    | $F824        | 11111000 00100100 | 
+-------------+----------------+--------------+-------------------+
| 55          | Dull Turquoise | $B264        | 10110010 01100100 | 
+-------------+----------------+--------------+-------------------+
| 41          | Light Khaki    | $B59A        | 10110101 10011010 | 
+-------------+----------------+--------------+-------------------+
| 15          | Light Green    | $FDAC        | 11111101 10101100 | 
+-------------+----------------+--------------+-------------------+
| 36          | Pastel Green   | $FEF7        | 11111110 11110111 | 
+-------------+----------------+--------------+-------------------+
| 46          | Brown          | $2348        | 00100011 01001000 | 
+-------------+----------------+--------------+-------------------+
| 59          | Tan            | $4C80        | 01001100 10000000 | 
+-------------+----------------+--------------+-------------------+
|  6          | Yellow         | $FFC1        | 11111111 11000001 | 
+-------------+----------------+--------------+-------------------+
| 22          | Orange         | $97C0        | 10010111 11000000 | 
+-------------+----------------+--------------+-------------------+
| 16          | Mustard        | $9480        | 10010100 10000000 | 
+-------------+----------------+--------------+-------------------+
| 47          | Khaki          | $6B49        | 01101011 01001001 | 
+-------------+----------------+--------------+-------------------+
| 53          | Buff           | $9592        | 10010101 10010010 | 
+-------------+----------------+--------------+-------------------+
| 40          | Brick          | $6D9B        | 01101101 10011011 | 
+-------------+----------------+--------------+-------------------+
| 33          | Beige          | $DFED        | 11011111 11101101 | 
+-------------+----------------+--------------+-------------------+
| 28          | Light Yellow   | $FFED        | 11111111 11101101 | 
+-------------+----------------+--------------+-------------------+
| 35          | Pastel Yellow  | $FFF7        | 11111111 11110111 | 
+-------------+----------------+--------------+-------------------+

The remainder of the first 256 colours are mapped as follows (we would
welcome names for each of these colours):

+-------------+--------------+-------------------+
|             |         GGGGGRRR RRBBBBBW        |
+-------------+--------------+-------------------+
| PAL Colour  | Native Value | Native Value      |
| Value       | Hex          | Binary            |
+=============+==============+===================+
| 64          | $0012        | 00000000 00010010 | 
+-------------+--------------+-------------------+
| 65          | $0108        | 00000001 00001000 | 
+-------------+--------------+-------------------+
| 66          | $011A        | 00000001 00011010 | 
+-------------+--------------+-------------------+
| 67          | $012C        | 00000001 00101100 | 
+-------------+--------------+-------------------+
| 68          | $013E        | 00000001 00111110 | 
+-------------+--------------+-------------------+
| 69          | $0240        | 00000010 01000000 | 
+-------------+--------------+-------------------+
| 70          | $0253        | 00000010 01010011 | 
+-------------+--------------+-------------------+
| 71          | $0277        | 00000010 01110111 | 
+-------------+--------------+-------------------+
| 72          | $0348        | 00000011 01001000 | 
+-------------+--------------+-------------------+
| 73          | $035B        | 00000011 01011011 | 
+-------------+--------------+-------------------+
| 74          | $036C        | 00000011 01101100 | 
+-------------+--------------+-------------------+
| 75          | $037F        | 00000011 01111111 | 
+-------------+--------------+-------------------+
| 76          | $0588        | 00000101 10001000 | 
+-------------+--------------+-------------------+
| 77          | $059A        | 00000101 10011010 | 
+-------------+--------------+-------------------+
| 78          | $05AC        | 00000101 10101100 | 
+-------------+--------------+-------------------+
| 79          | $05BE        | 00000101 10111110 | 
+-------------+--------------+-------------------+
| 80          | $06C0        | 00000110 11000000 | 
+-------------+--------------+-------------------+
| 81          | $06D3        | 00000110 11010011 | 
+-------------+--------------+-------------------+
| 82          | $06E4        | 00000110 11100100 | 
+-------------+--------------+-------------------+
| 83          | $06F7        | 00000110 11110111 | 
+-------------+--------------+-------------------+
| 84          | $07DB        | 00000111 11011011 | 
+-------------+--------------+-------------------+
| 85          | $2000        | 00100000 00000000 | 
+-------------+--------------+-------------------+
| 86          | $2012        | 00100000 00010010 | 
+-------------+--------------+-------------------+
| 87          | $2024        | 00100000 00100100 | 
+-------------+--------------+-------------------+
| 88          | $2036        | 00100000 00110110 | 
+-------------+--------------+-------------------+
| 89          | $212C        | 00100001 00101100 | 
+-------------+--------------+-------------------+
| 90          | $213E        | 00100001 00111110 | 
+-------------+--------------+-------------------+
| 91          | $2240        | 00100010 01000000 | 
+-------------+--------------+-------------------+
| 92          | $2253        | 00100010 01010011 | 
+-------------+--------------+-------------------+
| 93          | $2264        | 00100010 01100100 | 
+-------------+--------------+-------------------+
| 94          | $2277        | 00100010 01110111 | 
+-------------+--------------+-------------------+
| 95          | $236C        | 00100011 01101100 | 
+-------------+--------------+-------------------+
| 96          | $237F        | 00100011 01111111 | 
+-------------+--------------+-------------------+
| 97          | $2480        | 00100100 10000000 | 
+-------------+--------------+-------------------+
| 98          | $2492        | 00100100 10010010 | 
+-------------+--------------+-------------------+
| 99          | $24A4        | 00100100 10100100 | 
+-------------+--------------+-------------------+
| 100         | $24B6        | 00100100 10110110 | 
+-------------+--------------+-------------------+
| 101         | $2588        | 00100101 10001000 | 
+-------------+--------------+-------------------+
| 102         | $259A        | 00100101 10011010 | 
+-------------+--------------+-------------------+
| 103         | $25AC        | 00100101 10101100 | 
+-------------+--------------+-------------------+
| 104         | $25BE        | 00100101 10111110 | 
+-------------+--------------+-------------------+
| 105         | $26C0        | 00100110 11000000 | 
+-------------+--------------+-------------------+
| 106         | $26D3        | 00100110 11010011 | 
+-------------+--------------+-------------------+
| 107         | $26E4        | 00100110 11100100 | 
+-------------+--------------+-------------------+
| 108         | $26F7        | 00100110 11110111 | 
+-------------+--------------+-------------------+
| 109         | $27C8        | 00100111 11001000 | 
+-------------+--------------+-------------------+
| 110         | $27DB        | 00100111 11011011 | 
+-------------+--------------+-------------------+
| 111         | $27EC        | 00100111 11101100 | 
+-------------+--------------+-------------------+
| 112         | $27FF        | 00100111 11111111 | 
+-------------+--------------+-------------------+
| 113         | $4800        | 01001000 00000000 | 
+-------------+--------------+-------------------+
| 114         | $4813        | 01001000 00010011 | 
+-------------+--------------+-------------------+
| 115         | $4837        | 01001000 00110111 | 
+-------------+--------------+-------------------+
| 116         | $4908        | 01001001 00001000 | 
+-------------+--------------+-------------------+
| 117         | $491B        | 01001001 00011011 | 
+-------------+--------------+-------------------+
| 118         | $492C        | 01001001 00101100 | 
+-------------+--------------+-------------------+
| 119         | $493F        | 01001001 00111111 | 
+-------------+--------------+-------------------+
| 120         | $4A41        | 01001010 01000001 | 
+-------------+--------------+-------------------+
| 121         | $4A65        | 01001010 01100101 | 
+-------------+--------------+-------------------+
| 122         | $4A77        | 01001010 01110111 | 
+-------------+--------------+-------------------+
| 123         | $4B49        | 01001011 01001001 | 
+-------------+--------------+-------------------+
| 124         | $4B5B        | 01001011 01011011 | 
+-------------+--------------+-------------------+
| 125         | $8B2C        | 10001011 00101100 | 
+-------------+--------------+-------------------+
| 126         | $4B7F        | 01001011 01111111 | 
+-------------+--------------+-------------------+
| 127         | $4C93        | 01001100 10010011 | 
+-------------+--------------+-------------------+
| 128         | $4CB7        | 01001100 10110111 | 
+-------------+--------------+-------------------+
| 129         | $4D88        | 01001101 10001000 | 
+-------------+--------------+-------------------+
| 130         | $4D9B        | 01001101 10011011 | 
+-------------+--------------+-------------------+
| 131         | $4DBF        | 01001101 10111111 | 
+-------------+--------------+-------------------+
| 132         | $4EC1        | 01001110 11000001 | 
+-------------+--------------+-------------------+
| 133         | $4ED3        | 01001110 11010011 | 
+-------------+--------------+-------------------+
| 134         | $4EE5        | 01001110 11100101 | 
+-------------+--------------+-------------------+
| 135         | $4EF7        | 01001110 11110111 | 
+-------------+--------------+-------------------+
| 136         | $4FC9        | 01001111 11001001 | 
+-------------+--------------+-------------------+
| 137         | $4FDB        | 01001111 11011011 | 
+-------------+--------------+-------------------+
| 138         | $4FED        | 01001111 11101101 | 
+-------------+--------------+-------------------+
| 139         | $4FFF        | 01001111 11111111 | 
+-------------+--------------+-------------------+
| 140         | $6800        | 01101000 00000000 | 
+-------------+--------------+-------------------+
| 141         | $6813        | 01101000 00010011 | 
+-------------+--------------+-------------------+
| 142         | $6824        | 01101000 00100100 | 
+-------------+--------------+-------------------+
| 143         | $6837        | 01101000 00110111 | 
+-------------+--------------+-------------------+
| 144         | $692C        | 01101001 00101100 | 
+-------------+--------------+-------------------+
| 145         | $693F        | 01101001 00111111 | 
+-------------+--------------+-------------------+
| 146         | $6A41        | 01101010 01000001 | 
+-------------+--------------+-------------------+
| 147         | $6A53        | 01101010 01010011 | 
+-------------+--------------+-------------------+
| 148         | $6A65        | 01101010 01100101 | 
+-------------+--------------+-------------------+
| 149         | $6A77        | 01101010 01110111 | 
+-------------+--------------+-------------------+
| 150         | $6B7F        | 01101011 01111111 | 
+-------------+--------------+-------------------+
| 151         | $6C80        | 01101100 10000000 | 
+-------------+--------------+-------------------+
| 152         | $6C93        | 01101100 10010011 | 
+-------------+--------------+-------------------+
| 153         | $6CA4        | 01101100 10100100 | 
+-------------+--------------+-------------------+
| 154         | $6CB7        | 01101100 10110111 | 
+-------------+--------------+-------------------+
| 155         | $6D88        | 01101101 10001000 | 
+-------------+--------------+-------------------+
| 156         | $6DBF        | 01101101 10111111 | 
+-------------+--------------+-------------------+
| 157         | $6EC1        | 01101110 11000001 | 
+-------------+--------------+-------------------+
| 158         | $6ED3        | 01101110 11010011 | 
+-------------+--------------+-------------------+
| 159         | $6EE5        | 01101110 11100101 | 
+-------------+--------------+-------------------+
| 160         | $6EF7        | 01101110 11110111 | 
+-------------+--------------+-------------------+
| 161         | $6FC9        | 01101111 11001001 | 
+-------------+--------------+-------------------+
| 162         | $6FDB        | 01101111 11011011 | 
+-------------+--------------+-------------------+
| 163         | $6FED        | 01101111 11101101 | 
+-------------+--------------+-------------------+
| 164         | $6FFF        | 01101111 11111111 | 
+-------------+--------------+-------------------+
| 165         | $9108        | 10010001 00001000 | 
+-------------+--------------+-------------------+
| 166         | $911A        | 10010001 00011010 | 
+-------------+--------------+-------------------+
| 167         | $912C        | 10010001 00101100 | 
+-------------+--------------+-------------------+
| 168         | $913E        | 10010001 00111110 | 
+-------------+--------------+-------------------+
| 169         | $9253        | 10010010 01010011 | 
+-------------+--------------+-------------------+
| 170         | $9277        | 10010010 01110111 | 
+-------------+--------------+-------------------+
| 171         | $9348        | 10010011 01001000 | 
+-------------+--------------+-------------------+
| 172         | $935B        | 10010011 01011011 | 
+-------------+--------------+-------------------+
| 173         | $936C        | 10010011 01101100 | 
+-------------+--------------+-------------------+
| 174         | $937F        | 10010011 01111111 | 
+-------------+--------------+-------------------+
| 175         | $9492        | 10010100 10010010 | 
+-------------+--------------+-------------------+
| 176         | $9496        | 10010100 10010110 | 
+-------------+--------------+-------------------+
| 177         | $9588        | 10010101 10001000 | 
+-------------+--------------+-------------------+
| 178         | $95AC        | 10010101 10101100 | 
+-------------+--------------+-------------------+
| 179         | $95BE        | 10010101 10111110 | 
+-------------+--------------+-------------------+
| 180         | $96C0        | 10010110 11000000 | 
+-------------+--------------+-------------------+
| 181         | $96D3        | 10010110 11010011 | 
+-------------+--------------+-------------------+
| 182         | $96E4        | 10010110 11100100 | 
+-------------+--------------+-------------------+
| 183         | $96F7        | 10010110 11110111 | 
+-------------+--------------+-------------------+
| 184         | $97DB        | 10010111 11011011 | 
+-------------+--------------+-------------------+
| 185         | $97EC        | 10010111 11101100 | 
+-------------+--------------+-------------------+
| 186         | $97FF        | 10010111 11111111 | 
+-------------+--------------+-------------------+
| 187         | $B000        | 10110000 00000000 | 
+-------------+--------------+-------------------+
| 188         | $B012        | 10110000 00010010 | 
+-------------+--------------+-------------------+
| 189         | $B024        | 10110000 00100100 | 
+-------------+--------------+-------------------+
| 190         | $B036        | 10110000 00110110 | 
+-------------+--------------+-------------------+
| 191         | $B108        | 10110001 00001000 | 
+-------------+--------------+-------------------+
| 192         | $B11A        | 10110001 00011010 | 
+-------------+--------------+-------------------+
| 193         | $B12C        | 10110001 00101100 | 
+-------------+--------------+-------------------+
| 194         | $B13E        | 10110001 00111110 | 
+-------------+--------------+-------------------+
| 195         | $B240        | 10110010 01000000 | 
+-------------+--------------+-------------------+
| 196         | $B253        | 10110010 01010011 | 
+-------------+--------------+-------------------+
| 197         | $B277        | 10110010 01110111 | 
+-------------+--------------+-------------------+
| 198         | $B348        | 10110011 01001000 | 
+-------------+--------------+-------------------+
| 199         | $B37F        | 10110011 01111111 | 
+-------------+--------------+-------------------+
| 200         | $B480        | 10110100 10000000 | 
+-------------+--------------+-------------------+
| 201         | $B4A4        | 10110100 10100100 | 
+-------------+--------------+-------------------+
| 202         | $B4B6        | 10110100 10110110 | 
+-------------+--------------+-------------------+
| 203         | $B588        | 10110101 10001000 | 
+-------------+--------------+-------------------+
| 204         | $B6C0        | 10110110 11000000 | 
+-------------+--------------+-------------------+
| 205         | $B6D3        | 10110110 11010011 | 
+-------------+--------------+-------------------+
| 206         | $B6E4        | 10110110 11100100 | 
+-------------+--------------+-------------------+
| 207         | $B6F7        | 10110110 11110111 | 
+-------------+--------------+-------------------+
| 208         | $B7C8        | 10110111 11001000 | 
+-------------+--------------+-------------------+
| 209         | $B7DB        | 10110111 11011011 | 
+-------------+--------------+-------------------+
| 210         | $D800        | 11011000 00000000 | 
+-------------+--------------+-------------------+
| 211         | $D813        | 11011000 00010011 | 
+-------------+--------------+-------------------+
| 212         | $D824        | 11011000 00100100 | 
+-------------+--------------+-------------------+
| 213         | $D837        | 11011000 00110111 | 
+-------------+--------------+-------------------+
| 214         | $D908        | 11011001 00001000 | 
+-------------+--------------+-------------------+
| 215         | $D91B        | 11011001 00011011 | 
+-------------+--------------+-------------------+
| 216         | $D92C        | 11011001 00101100 | 
+-------------+--------------+-------------------+
| 217         | $D93F        | 11011001 00111111 | 
+-------------+--------------+-------------------+
| 218         | $DA41        | 11011010 01000001 | 
+-------------+--------------+-------------------+
| 219         | $DA53        | 11011010 01010011 | 
+-------------+--------------+-------------------+
| 220         | $DA65        | 11011010 01100101 | 
+-------------+--------------+-------------------+
| 221         | $DA77        | 11011010 01110111 | 
+-------------+--------------+-------------------+
| 222         | $DB49        | 11011011 01001001 | 
+-------------+--------------+-------------------+
| 223         | $DB5B        | 11011011 01011011 | 
+-------------+--------------+-------------------+
| 224         | $DB6D        | 11011011 01101101 | 
+-------------+--------------+-------------------+
| 225         | $DB7F        | 11011011 01111111 | 
+-------------+--------------+-------------------+
| 226         | $DC80        | 11011100 10000000 | 
+-------------+--------------+-------------------+
| 227         | $DC93        | 11011100 10010011 | 
+-------------+--------------+-------------------+
| 228         | $DCA4        | 11011100 10100100 | 
+-------------+--------------+-------------------+
| 229         | $DCB7        | 11011100 10110111 | 
+-------------+--------------+-------------------+
| 230         | $DD88        | 11011101 10001000 | 
+-------------+--------------+-------------------+
| 231         | $DD9B        | 11011101 10011011 | 
+-------------+--------------+-------------------+
| 232         | $DDAC        | 11011101 10101100 | 
+-------------+--------------+-------------------+
| 233         | $DDBF        | 11011101 10111111 | 
+-------------+--------------+-------------------+
| 234         | $DED3        | 11011110 11010011 | 
+-------------+--------------+-------------------+
| 235         | $DEE5        | 11011110 11100101 | 
+-------------+--------------+-------------------+
| 236         | $DFDB        | 11011111 11011011 | 
+-------------+--------------+-------------------+
| 237         | $F813        | 11111000 00010011 | 
+-------------+--------------+-------------------+
| 238         | $F91B        | 11111001 00011011 | 
+-------------+--------------+-------------------+
| 239         | $F92C        | 11111001 00101100 | 
+-------------+--------------+-------------------+
| 240         | $FA41        | 11111010 01000001 | 
+-------------+--------------+-------------------+
| 241         | $FA53        | 11111010 01010011 | 
+-------------+--------------+-------------------+
| 242         | $FA65        | 11111010 01100101 | 
+-------------+--------------+-------------------+
| 243         | $FA77        | 11111010 01110111 | 
+-------------+--------------+-------------------+
| 244         | $FB49        | 11111011 01001001 | 
+-------------+--------------+-------------------+
| 245         | $FB5B        | 11111011 01011011 | 
+-------------+--------------+-------------------+
| 246         | $FB6D        | 11111011 01101101 | 
+-------------+--------------+-------------------+
| 247         | $FB7F        | 11111011 01111111 | 
+-------------+--------------+-------------------+
| 248         | $FC93        | 11111100 10010011 | 
+-------------+--------------+-------------------+
| 249         | $FCA4        | 11111100 10100100 | 
+-------------+--------------+-------------------+
| 250         | $FCB7        | 11111100 10110111 | 
+-------------+--------------+-------------------+
| 251         | $FD88        | 11111101 10001000 | 
+-------------+--------------+-------------------+
| 252         | $FD9B        | 11111101 10011011 | 
+-------------+--------------+-------------------+
| 253         | $FED3        | 11111110 11010011 | 
+-------------+--------------+-------------------+
| 254         | $FEE5        | 11111110 11100101 | 
+-------------+--------------+-------------------+
| 255         | $FFDB        | 11111111 11011011 | 
+-------------+--------------+-------------------+


24 Bit Enhanced Colour Drivers
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Although only available as a Colour Mode on QPC2 and the QXL, this true
colour (24 bit) mode is used by commands such as PALETTE\_QL and
PALETTE\_8 to describe approx 16 million colours in detail.

Here, every four bytes (a longword) represent one pixel on the Monitor's
screen.

The bits are combined to represent the amount of GREEN, RED and BLUE to
be used for each pixel, in the following format **rrrrrrrr gggggggg bbbbbbbb xxxxxxxx**, where:

- G is Green (8 bits)

- R is Red (8 bits)

- B is Blue (8 bits)

- X is Unused

In the table below, the colours represented by each of the first 256 PAL
colours (0 to 255) closely resembles those generated under the 256
Colour Mode on the Aurora, however, due to the way in which colour is
stored, it is necessary to look up the comparative Hexadecimal value for
each colour which would need to be POKEd into memory.

You cannot use the PAL colour number as a parameter for INK (and other
commands) due to the fact that this is limited to 256 - use the
hexadecimal 24 bit value instead.

Again, the colours are hard to describe due to the range and therefore
require experimentation to obtain the correct colours. However, the
following table details the corresponding INK parameter to use to
achieve that colour (*NOTE* this does not correspond with the orignal QL
colour scheme!). It is not possible to list all of the 16 million
colours, therefore we have tried to list the most widely used ones (INK
0 to INK 63) grouped into the different colours and the values for the
rest of the colours in the range INK 64 to INK 255.

+--------------------------+--------------------------+--------------------------+
| PAL                      |                          | 24 bit                   |
| Colour                   | Colour                   | Value                    |
| Value                    | Name                     | (Hex)                    |
+==========================+==========================+==========================+
| 0                        | Black                    | $000000                  |
+--------------------------+--------------------------+--------------------------+
| 1                        | White                    | $FFFFFF                  |
+--------------------------+--------------------------+--------------------------+
| 8                        | Dark Slate               | $242424                  |
+--------------------------+--------------------------+--------------------------+
| 9                        | Slate Grey               | $494949                  |
+--------------------------+--------------------------+--------------------------+
| 10                       | Dark Grey                | $6D6D6D                  |
+--------------------------+--------------------------+--------------------------+
| 11                       | Grey                     | $929292                  |
+--------------------------+--------------------------+--------------------------+
| 12                       | Light Grey               | $B6B6B6                  |
+--------------------------+--------------------------+--------------------------+
| 13                       | Ash Grey                 | $DBDBDB                  |
+--------------------------+--------------------------+--------------------------+
| 58                       | Cerise                   | $920049                  |
+--------------------------+--------------------------+--------------------------+
| 14                       | Dark Red                 | $920000                  |
+--------------------------+--------------------------+--------------------------+
| 2                        | Red                      | $FF0000                  |
+--------------------------+--------------------------+--------------------------+
| 63                       | Deep Purple              | $490092                  |
+--------------------------+--------------------------+--------------------------+
| 51                       | Plum                     | $6D246D                  |
+--------------------------+--------------------------+--------------------------+
| 20                       | Purple                   | $920092                  |
+--------------------------+--------------------------+--------------------------+
| 26                       | Mauve                    | $9200FF                  |
+--------------------------+--------------------------+--------------------------+
| 57                       | Faded Purple             | $9249B6                  |
+--------------------------+--------------------------+--------------------------+
| 52                       | Dusky Pink               | $B64992                  |
+--------------------------+--------------------------+--------------------------+
| 5                        | Magenta                  | $FF00FF                  |
+--------------------------+--------------------------+--------------------------+
| 21                       | Shocking Pink            | $FF0092                  |
+--------------------------+--------------------------+--------------------------+
| 45                       | Dull Pink                | $B66DB6                  |
+--------------------------+--------------------------+--------------------------+
| 32                       | Pink                     | $FFB6DB                  |
+--------------------------+--------------------------+--------------------------+
| 31                       | Rose Pink                | $FFB6FF                  |
+--------------------------+--------------------------+--------------------------+
| 34                       | Pastel Pink              | $FFDBDB                  |
+--------------------------+--------------------------+--------------------------+
| 39                       | Pastel Rose              | $FFDBFF                  |
+--------------------------+--------------------------+--------------------------+
| 27                       | Peach                    | $FFB6B6                  |
+--------------------------+--------------------------+--------------------------+
| 50                       | Midnight Blue            | $24246D                  |
+--------------------------+--------------------------+--------------------------+
| 19                       | Dark Blue                | $000092                  |
+--------------------------+--------------------------+--------------------------+
| 4                        | Blue                     | $0000FF                  |
+--------------------------+--------------------------+--------------------------+
| 62                       | Ultramarine              | $004992                  |
+--------------------------+--------------------------+--------------------------+
| 49                       | Dusky Blue               | $246D6D                  |
+--------------------------+--------------------------+--------------------------+
| 44                       | Steel Blue               | $6D6DB6                  |
+--------------------------+--------------------------+--------------------------+
| 18                       | Sea Blue                 | $009292                  |
+--------------------------+--------------------------+--------------------------+
| 25                       | Bright Blue              | $0092FF                  |
+--------------------------+--------------------------+--------------------------+
| 56                       | Dull Blue                | $4992B6                  |
+--------------------------+--------------------------+--------------------------+
| 43                       | Dull Cyan                | $6DB6B6                  |
+--------------------------+--------------------------+--------------------------+
| 7                        | Cyan                     | $00FFFF                  |
+--------------------------+--------------------------+--------------------------+
| 29                       | Light Blue               | $B6FFFF                  |
+--------------------------+--------------------------+--------------------------+
| 30                       | Sky Blue                 | $B6B6FF                  |
+--------------------------+--------------------------+--------------------------+
| 38                       | Pastel Blue              | $DBDBFF                  |
+--------------------------+--------------------------+--------------------------+
| 37                       | Pastel Cyan              | $DBFFFF                  |
+--------------------------+--------------------------+--------------------------+
| 48                       | Dusky Green              | $246D24                  |
+--------------------------+--------------------------+--------------------------+
| 60                       | Grass Green              | $499200                  |
+--------------------------+--------------------------+--------------------------+
| 17                       | Dark Green               | $009200                  |
+--------------------------+--------------------------+--------------------------+
| 54                       | Avocado                  | $92B649                  |
+--------------------------+--------------------------+--------------------------+
| 61                       | Sea Green                | $009249                  |
+--------------------------+--------------------------+--------------------------+
| 42                       | Dull Green               | $6DB66D                  |
+--------------------------+--------------------------+--------------------------+
| 3                        | Green                    | $00FF00                  |
+--------------------------+--------------------------+--------------------------+
| 23                       | Lime Green               | $92FF00                  |
+--------------------------+--------------------------+--------------------------+
| 24                       | Apple Green              | $00FF92                  |
+--------------------------+--------------------------+--------------------------+
| 55                       | Dull Turquoise           | $49B692                  |
+--------------------------+--------------------------+--------------------------+
| 41                       | Light Khaki              | $B6B66D                  |
+--------------------------+--------------------------+--------------------------+
| 15                       | Light Green              | $B6FFB6                  |
+--------------------------+--------------------------+--------------------------+
| 36                       | Pastel Green             | $DBFFDB                  |
+--------------------------+--------------------------+--------------------------+
| 46                       | Brown                    | $6D2424                  |
+--------------------------+--------------------------+--------------------------+
| 59                       | Tan                      | $924900                  |
+--------------------------+--------------------------+--------------------------+
| 6                        | Yellow                   | $FFFF00                  |
+--------------------------+--------------------------+--------------------------+
| 22                       | Orange                   | $FF9200                  |
+--------------------------+--------------------------+--------------------------+
| 16                       | Mustard                  | $929200                  |
+--------------------------+--------------------------+--------------------------+
| 47                       | Khaki                    | $6D6D24                  |
+--------------------------+--------------------------+--------------------------+
| 53                       | Buff                     | $B69249                  |
+--------------------------+--------------------------+--------------------------+
| 40                       | Brick                    | $B66D6D                  |
+--------------------------+--------------------------+--------------------------+
| 33                       | Beige                    | $FFDBB6                  |
+--------------------------+--------------------------+--------------------------+
| 28                       | Light Yellow             | $FFFFB6                  |
+--------------------------+--------------------------+--------------------------+
| 35                       | Pastel Yellow            | $FFFFDB                  |
+--------------------------+--------------------------+--------------------------+

The remainder of the first 256 colours are mapped as follows (we would
welcome names for each of these colours):

+----------+--------------------------+
| PAL      | 24 bit                   |
| Colour   | Value                    |
| Value    | (Hex)                    |
+==========+==========================+
| 64       | $000049                  |
+----------+--------------------------+
| 65       | $240024                  |
+----------+--------------------------+
| 66       | $24006D                  |
+----------+--------------------------+
| 67       | $2400B6                  |
+----------+--------------------------+
| 68       | $2400FF                  |
+----------+--------------------------+
| 69       | $490000                  |
+----------+--------------------------+
| 70       | $490049                  |
+----------+--------------------------+
| 71       | $4900DB                  |
+----------+--------------------------+
| 72       | $6D0024                  |
+----------+--------------------------+
| 73       | $6D006D                  |
+----------+--------------------------+
| 74       | $6D00B6                  |
+----------+--------------------------+
| 75       | $6D00FF                  |
+----------+--------------------------+
| 76       | $B60024                  |
+----------+--------------------------+
| 77       | $B6006D                  |
+----------+--------------------------+
| 78       | $B600B6                  |
+----------+--------------------------+
| 79       | $B600FF                  |
+----------+--------------------------+
| 80       | $DB0000                  |
+----------+--------------------------+
| 81       | $DB0049                  |
+----------+--------------------------+
| 82       | $DB0092                  |
+----------+--------------------------+
| 83       | $DB00DB                  |
+----------+--------------------------+
| 84       | $FF006D                  |
+----------+--------------------------+
| 85       | $002400                  |
+----------+--------------------------+
| 86       | $002449                  |
+----------+--------------------------+
| 87       | $002492                  |
+----------+--------------------------+
| 88       | $0024DB                  |
+----------+--------------------------+
| 89       | $2424B6                  |
+----------+--------------------------+
| 90       | $2424FF                  |
+----------+--------------------------+
| 91       | $492400                  |
+----------+--------------------------+
| 92       | $492449                  |
+----------+--------------------------+
| 93       | $492492                  |
+----------+--------------------------+
| 94       | $4924DB                  |
+----------+--------------------------+
| 95       | $6D24B6                  |
+----------+--------------------------+
| 96       | $6D24FF                  |
+----------+--------------------------+
| 97       | $922400                  |
+----------+--------------------------+
| 98       | $922449                  |
+----------+--------------------------+
| 99       | $922492                  |
+----------+--------------------------+
| 100      | $9224DB                  |
+----------+--------------------------+
| 101      | $B62424                  |
+----------+--------------------------+
| 102      | $B6246D                  |
+----------+--------------------------+
| 103      | $B624B6                  |
+----------+--------------------------+
| 104      | $B624FF                  |
+----------+--------------------------+
| 105      | $DB2400                  |
+----------+--------------------------+
| 106      | $DB2449                  |
+----------+--------------------------+
| 107      | $DB2492                  |
+----------+--------------------------+
| 108      | $DB246D                  |
+----------+--------------------------+
| 109      | $FF2424                  |
+----------+--------------------------+
| 110      | $FF246D                  |
+----------+--------------------------+
| 111      | $FF24B6                  |
+----------+--------------------------+
| 112      | $FF24FF                  |
+----------+--------------------------+
| 113      | $004900                  |
+----------+--------------------------+
| 114      | $004949                  |
+----------+--------------------------+
| 115      | $0049DB                  |
+----------+--------------------------+
| 116      | $244924                  |
+----------+--------------------------+
| 117      | $24496D                  |
+----------+--------------------------+
| 118      | $2449B6                  |
+----------+--------------------------+
| 119      | $2449FF                  |
+----------+--------------------------+
| 120      | $494900                  |
+----------+--------------------------+
| 121      | $494992                  |
+----------+--------------------------+
| 122      | $4949DB                  |
+----------+--------------------------+
| 123      | $6D4924                  |
+----------+--------------------------+
| 124      | $6D496D                  |
+----------+--------------------------+
| 125      | $6D49B6                  |
+----------+--------------------------+
| 126      | $6D49FF                  |
+----------+--------------------------+
| 127      | $924949                  |
+----------+--------------------------+
| 128      | $9249DB                  |
+----------+--------------------------+
| 129      | $B64924                  |
+----------+--------------------------+
| 130      | $B6496D                  |
+----------+--------------------------+
| 131      | $B649FF                  |
+----------+--------------------------+
| 132      | $DB4900                  |
+----------+--------------------------+
| 133      | $DB4949                  |
+----------+--------------------------+
| 134      | $DB4992                  |
+----------+--------------------------+
| 135      | $DB49DB                  |
+----------+--------------------------+
| 136      | $FF4924                  |
+----------+--------------------------+
| 137      | $FF496D                  |
+----------+--------------------------+
| 138      | $FF49B6                  |
+----------+--------------------------+
| 139      | $FF49FF                  |
+----------+--------------------------+
| 140      | $006D00                  |
+----------+--------------------------+
| 141      | $006D49                  |
+----------+--------------------------+
| 142      | $006D92                  |
+----------+--------------------------+
| 143      | $006DDB                  |
+----------+--------------------------+
| 144      | $246DB6                  |
+----------+--------------------------+
| 145      | $246DFF                  |
+----------+--------------------------+
| 146      | $496D00                  |
+----------+--------------------------+
| 147      | $496D49                  |
+----------+--------------------------+
| 148      | $496D92                  |
+----------+--------------------------+
| 149      | $496DDB                  |
+----------+--------------------------+
| 150      | $6D6DFF                  |
+----------+--------------------------+
| 151      | $926D00                  |
+----------+--------------------------+
| 152      | $926D49                  |
+----------+--------------------------+
| 153      | $926D92                  |
+----------+--------------------------+
| 154      | $926DDB                  |
+----------+--------------------------+
| 155      | $B66D24                  |
+----------+--------------------------+
| 156      | $B66DFF                  |
+----------+--------------------------+
| 157      | $DB6D00                  |
+----------+--------------------------+
| 158      | $DB6D49                  |
+----------+--------------------------+
| 159      | $DB6D92                  |
+----------+--------------------------+
| 160      | $DB6DDB                  |
+----------+--------------------------+
| 161      | $FF6D24                  |
+----------+--------------------------+
| 162      | $FF6D6D                  |
+----------+--------------------------+
| 163      | $FF6DB6                  |
+----------+--------------------------+
| 164      | $FF6DFF                  |
+----------+--------------------------+
| 165      | $249224                  |
+----------+--------------------------+
| 166      | $24926D                  |
+----------+--------------------------+
| 167      | $2492B6                  |
+----------+--------------------------+
| 168      | $2492FF                  |
+----------+--------------------------+
| 169      | $499249                  |
+----------+--------------------------+
| 170      | $4992DB                  |
+----------+--------------------------+
| 171      | $6D9224                  |
+----------+--------------------------+
| 172      | $6D926D                  |
+----------+--------------------------+
| 173      | $6D92B6                  |
+----------+--------------------------+
| 174      | $6D92FF                  |
+----------+--------------------------+
| 175      | $929249                  |
+----------+--------------------------+
| 176      | $9292DB                  |
+----------+--------------------------+
| 177      | $B69224                  |
+----------+--------------------------+
| 178      | $B692B6                  |
+----------+--------------------------+
| 179      | $B692FF                  |
+----------+--------------------------+
| 180      | $DB9200                  |
+----------+--------------------------+
| 181      | $DB9249                  |
+----------+--------------------------+
| 182      | $DB9292                  |
+----------+--------------------------+
| 183      | $DB92DB                  |
+----------+--------------------------+
| 184      | $FF926D                  |
+----------+--------------------------+
| 185      | $FF92B6                  |
+----------+--------------------------+
| 186      | $FF92FF                  |
+----------+--------------------------+
| 187      | $00B600                  |
+----------+--------------------------+
| 188      | $00B649                  |
+----------+--------------------------+
| 189      | $00B692                  |
+----------+--------------------------+
| 190      | $00B6DB                  |
+----------+--------------------------+
| 191      | $24B624                  |
+----------+--------------------------+
| 192      | $24B66D                  |
+----------+--------------------------+
| 193      | $24B6B6                  |
+----------+--------------------------+
| 194      | $24B6FF                  |
+----------+--------------------------+
| 195      | $49B600                  |
+----------+--------------------------+
| 196      | $49B649                  |
+----------+--------------------------+
| 197      | $49B6DB                  |
+----------+--------------------------+
| 198      | $6DB624                  |
+----------+--------------------------+
| 199      | $6DB6FF                  |
+----------+--------------------------+
| 200      | $92B600                  |
+----------+--------------------------+
| 201      | $92B692                  |
+----------+--------------------------+
| 202      | $92B6DB                  |
+----------+--------------------------+
| 203      | $B6B624                  |
+----------+--------------------------+
| 204      | $DBB600                  |
+----------+--------------------------+
| 205      | $DBB649                  |
+----------+--------------------------+
| 206      | $DBB692                  |
+----------+--------------------------+
| 207      | $DBB6DB                  |
+----------+--------------------------+
| 208      | $FFB624                  |
+----------+--------------------------+
| 209      | $FFB66D                  |
+----------+--------------------------+
| 210      | $00DB00                  |
+----------+--------------------------+
| 211      | $00DB49                  |
+----------+--------------------------+
| 212      | $00DB92                  |
+----------+--------------------------+
| 213      | $00DBDB                  |
+----------+--------------------------+
| 214      | $24DB24                  |
+----------+--------------------------+
| 215      | $24DB6D                  |
+----------+--------------------------+
| 216      | $24DBB6                  |
+----------+--------------------------+
| 217      | $24DBFF                  |
+----------+--------------------------+
| 218      | $49DB00                  |
+----------+--------------------------+
| 219      | $49DB49                  |
+----------+--------------------------+
| 220      | $49DB92                  |
+----------+--------------------------+
| 221      | $49DBDB                  |
+----------+--------------------------+
| 222      | $6DDB24                  |
+----------+--------------------------+
| 223      | $6DDB6D                  |
+----------+--------------------------+
| 224      | $6DDBB6                  |
+----------+--------------------------+
| 225      | $6DDBFF                  |
+----------+--------------------------+
| 226      | $92DB00                  |
+----------+--------------------------+
| 227      | $92DB49                  |
+----------+--------------------------+
| 228      | $92DB92                  |
+----------+--------------------------+
| 229      | $92DBDB                  |
+----------+--------------------------+
| 230      | $B6DB24                  |
+----------+--------------------------+
| 231      | $B6DB6D                  |
+----------+--------------------------+
| 232      | $B6DBN6                  |
+----------+--------------------------+
| 233      | $B6DBFF                  |
+----------+--------------------------+
| 234      | $DBDB49                  |
+----------+--------------------------+
| 235      | $DBDB92                  |
+----------+--------------------------+
| 236      | $FFDB6D                  |
+----------+--------------------------+
| 237      | $00FF49                  |
+----------+--------------------------+
| 238      | $24FF6D                  |
+----------+--------------------------+
| 239      | $24FFB6                  |
+----------+--------------------------+
| 240      | $49FF00                  |
+----------+--------------------------+
| 241      | $49FF49                  |
+----------+--------------------------+
| 242      | $49FF92                  |
+----------+--------------------------+
| 243      | $49FFDB                  |
+----------+--------------------------+
| 244      | $6DFF24                  |
+----------+--------------------------+
| 245      | $6DFF6D                  |
+----------+--------------------------+
| 246      | $6DFFB6                  |
+----------+--------------------------+
| 247      | $6DFFFF                  |
+----------+--------------------------+
| 248      | $92FF49                  |
+----------+--------------------------+
| 249      | $92FF92                  |
+----------+--------------------------+
| 250      | $92FFDB                  |
+----------+--------------------------+
| 251      | $B6FF24                  |
+----------+--------------------------+
| 252      | $B6FF6D                  |
+----------+--------------------------+
| 253      | $DBFF49                  |
+----------+--------------------------+
| 254      | $DBFF92                  |
+----------+--------------------------+
| 255      | $FFFF6D                  |
+----------+--------------------------+

MISCELLANEOUS COLOUR MODES
^^^^^^^^^^^^^^^^^^^^^^^^^^

MODE 2 (Monochrome Drivers)
"""""""""""""""""""""""""""

Each byte represents eight pixels on the Monitor's screen calculated by
looking at the status of each of the eight binary bits which make up a
byte - if a bit is 1 (ON) then the corresponding pixel will be white,
otherwise it will be black.

For example, if PEEK (SCR\_BASE) returns the value 85, in binary this is
represented by:

0 1 0 1 0 1 0 1

Therefore the top left of the Monitor screen will be showing eight
alternating pixels of black and white.

**Example**

The following program will fill the screen with black and white vertical
stripes:

::

            100 MODE 2
            110 FOR x=0 TO SCR_YLIM-1
            120   FOR y=0 TO (SCR_XLIM-1)/4
            130     POKE SCR_BASE+ (x*SCR_LLEN) + y,85
            140   END FOR y
            150 END FOR x

**SMSQ/E NOTE**

Under SMSQ/E v2.98+, Enhanced Colour Drivers, this becomes MODE 0.

MODE 12 (16 Colour Mode)
""""""""""""""""""""""""

This is supported only by the THOR XVI and is similar to Aurora's 16
Colour Mode under the Enhanced Colour Drivers in that it replaces the
Flash bit of MODE 8 by an Intensity bit which allows you to display 16
colours on screen at a time at a resolution of 256 x 256 pixels.

(We have no details of how this was implemented).

A16.4 USING HIGH RESOLUTION DISPLAYS
------------------------------------

There is not much adaptation required in order to use QL screen
resolutions in excess of 512x256 pixels - all of the normal commands
work as you would expect. OUTLN includes an example of how to allow
programs to re-size themselves up to the maximum resolution. However,
there are some rules which you need to observe..

First of all, refer to Appendix 6.7 (Using High Resolution Screens)
about some compatability issues.

If a user chooses to run a program on a high resolution screen, they
will find that the program will only occupy a small area of the screen.
Even if the program allows you to resize it to take advantage of the
larger screen, this may not be very satisfactory. Although graphics
commands which work by reference to the graphics co-ordinates system
(such as LINE) will take advantage of the larger windows provided by the
program, thus giving the effect of enlarging any on-screen graphics,
other commands which work by reference to the pixel co-ordinates system
(such as BLOCK) will rely on the program to resize them specifically for
the new screen. You may therefore find that the display of some programs
is corrupted, unless the programmer has taken sufficient care.

One of the main problems is that text can still only be PRINTed on
screen in the standard QL sizes, and therefore, any text PRINTed in
CSIZE 0,0 will be very hard to read on a 800x600 screen (let alone a
1600x1200 screen), even with a 17" Monitor. Programs will therefore need
to take this into account, possibly using the resize procedure to alter
the character sizes used for text, or using the ProWeSS system from
PROGS, which uses scaleable fonts for output.

Refer to the SCALE command for a means of working out a relationship
between graphics co-ordinates and pixel co- ordinates.
