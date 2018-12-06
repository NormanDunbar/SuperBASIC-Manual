..  _a10-character--sets:

A10 Designing New Character Sets (Fonts)
========================================

A font is a character set used by the computer to display characters
(normally letters and numbers) on screen. A wide range of fonts can be
used, which allow you to make letters appear differently on screen for
different programs.

A10.1 Fonts on the QL
---------------------

On the QL, each window can have two fonts attached. There are actually
two default fonts, the first of which defines the characters from 32 to
127 and the second of which defines the characters from 127 to 255.

The reason that CHR$(127) is defined twice is that the definition in the
first font is the definition used for the copyright symbol, whereas the
definition in the second font is that used if a character is undefined,
such as CHR$(2).

Normally this is not noticeable and when you open a new window (scr\_ or
con\_), the standard QL fonts are attached to that channel.

Minerva users can use the commands::

    POKE_L !124!40, font1

and::

    POKE_L !124!44, font2

to alter these default fonts and thereby attach user-defined fonts to
every single window that is opened after this command.

SMSQ/E users can use the command CHAR\_DEF to achieve a similar result.

A10.2 Changing Fonts in Programs
--------------------------------

When a character is PRINTed, the QL looks up the code in the first font
to find the binary definition of the character (see below). If the code
is found in this first font then it is PRINTed, otherwise, the QL looks
for the code in the second font and if found PRINTs this out.

If however the character is still not found, then the first character of
the second font is printed out.

This therefore means that although substitute fonts need not have the
same range as the QL standard fonts, it is important that a font
contains all of the characters which will be used by a program!

On a QL, a font is stored in the following format:

+-----------+-----------------------------------------------------------+
| Offset    | Value                                                     |
+===========+===========================================================+
| $0        | Byte giving code of first character defined in the font   |
+-----------+-----------------------------------------------------------+
| $1        | Byte giving the number of characters defined (minus 1)    |
+-----------+-----------------------------------------------------------+
| $2...$A   | Nine bytes defining the first character                   |
+-----------+-----------------------------------------------------------+
| $B...     | Nine bytes for each subsequent character...               |
+-----------+-----------------------------------------------------------+

Each character contained in the font is designed on a grid 8 pixels wide
by 9 pixels high, and therefore the easiest way of calculating the nine
bytes which make up each character is to design the character on a sheet
of graph paper (if you do not have a font design program) and then each
row must be converted from binary to decimal.

Each square in the grid which contains a 1 will be shown as a pixel in
the current INK colour when PRINTed to the screen. For instance, this is
the binary representation of the character k:

::

      |     BIT  7 6 5 4 3 2 1 0
    --+-------------------------------
      |0         0 1 0 0 0 0 0 0 =  64
      |1         0 1 0 0 0 0 0 0 =  64
      |2         0 1 0 0 0 1 0 0 =  68
    R |3         0 1 0 0 1 0 0 0 =  72
    O |4         0 1 1 1 0 0 0 0 = 112
    W |5         0 1 0 0 1 0 0 0 =  72
      |6         0 1 0 0 0 1 0 0 =  68
      |7         0 0 0 0 0 0 0 0 =   0
      |8         0 0 0 0 0 0 0 0 =   0
    --+-------------------------------

Therefore a small program to set the character 'a' to the same as the
character 'k' in channel #1 would be:

::

    10 a=RESPR(11)
    20 POKE a,97 : REMark 97=CODE('a') - first character in font
    30 POKE a+1,0: REMark Only one character is being redefined
    40 RESTORE
    50 FOR i=0 TO 8:READ bit:POKE a+2+i,bit
    60 DATA 64,64,68,72,112,72,68,0,0
    70 CHAR_USE #1,a,0

Note that unfortunately no other characters will be printed correctly!
This is because, when re-designing a font, it needs to include all of
the characters which may be used in the window to which the font is
attached.

When designing fonts for use on the QL, it is important that certain
rules are followed to ensure that when characters are PRINTed on screen,
they have the desired appearance in all screen modes. The QL converts a
given character into the desired mode by doubling up various rows or
columns (depending on the size set using the CSIZE command). If you
intend to re-design letters, the rightmost two columns (bits 0 and 1)
should always be left empty as these are ignored in current versions of
the QL ROM.

The leftmost column (bit 7) is normally left blank to ensure a gap
between adjacent characters, however, should you want to use this column
also, you must be wary of the fact that pre-JS ROMs cannot display fonts
correctly which use this column (bit 7) and so this should always be
left blank unless you know that your font is going to be used
specifically on later ROMs (see CSIZE).

In fact, if you are clever, you can use this bit 7 to obtain interesting
effects on pre-JS ROMs, whilst still retaining the full 8 pixel wide
characters (the effects vary depending on the ROM version and cannot be
guaranteed!).

You should also be aware of the fact that an extra blank row is
generally left between each line of characters. Toolkit II users can
however prevent this by using CHAR\_INC.
