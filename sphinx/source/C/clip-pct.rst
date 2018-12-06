..  _clip-pct:

CLIP%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLIP% (#channel)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  CLIP (DIY Toolkit - Vol S)                                       |
+----------+-------------------------------------------------------------------+

This function can be used to read characters from the QL's screen.

In order for the function to work, you will need to OPEN a window over
that part of the QL's screen which you wish to read and ensure that it
is in the correct MODE and has UNDER, CSIZE and CHAR\_INC set to the
same values as were used to create that part of the screen. You will
also need to ensure that the same font is being used by the window which
you have OPENed. The window should be defined so that any text written
to that window would precisely match the text on screen (except for
colour).

Due to the way in which QL's work, this means that CLIP% can be used to
read user-defined characters from the screen, for example, where in
games some of the font has been redefined to represent symbols in the
game.

The function will then try to read a character from the current cursor
position and return its character CODE. It can be used to read any
character in the range 0...255 (except CHR$(10) which does not appear on
screen).

The DIY Toolkit includes an example of a program which uses this
function to create a clip board for reading text from a program running
on the QL. It uses CHAN\_W% and similar functions to read the existing
settings of the window of a target program.

However, this function is really of most use when used within your own
programs, possibly to detect collisions in a game between objects.

**Example**

The following short routine could be used to read the name of a disk in
flp1\_ (provided that the directory was not longer than one page):

::

    10 DIR flp1_
    20 FOR i=0 TO 20
    25 AT #1,1,i
    30 PRINT #2,CLIP$(#1);
    40 END FOR i

**NOTE 1**

Although this works on all QL implementations, the code will not
currently work with resolutions bigger than 512x256 pixels.

**NOTE 2**

If you want to read characters from a window of a program whilst the
THOR XVI's windowing environment, or the Pointer Environment is running,
you will have to switch off the windowing environment before the program
in question is loaded, using POKE SYS\_VARS+133,1 on the THOR or EXEP
flp1\_program,u under the Pointer Environment.

**NOTE 3**

The main problem with these functions is that some programs do not use
standard fonts (or attach fonts to a window using non-standard
techniques). Some additional fonts are supplied with DIY Toolkit which
may help in this respect.

**CROSS-REFERENCE**

See the Fonts Appendix about changing QL fonts.

:ref:`char-use` and
:ref:`s-font` allows you to set the font used by a
window.

See also :ref:`clip-dlr`.

