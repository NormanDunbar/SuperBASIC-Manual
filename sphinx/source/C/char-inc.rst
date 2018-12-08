..  _char-inc:

CHAR\_INC
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHAR\_INC [#channel,] x\_step,y\_step                            |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command sets the horizontal (x\_step) and vertical (y\_step)
distance between characters printed on a window (default #1). The
standard values are the width and height of a character and are
automatically set by CSIZE.

CSIZE#2,0,0 performs an internal CHAR\_INC#2,6,10.

Characters are generally based on a grid which measures 8x10 pixels,
although the leftmost column was not available for fonts on pre-JS ROMs.
Also, if you own a JSU ROM (an American QL), this grid size is reduced
to 8x8, although programs would appear to run okay on the JSU ROM
without modification (see MODE for further details).

**Example**

Would you like to print more characters to the screen than normal? You
can either do this by defining smaller fonts or by writing characters on
the screen closer together:

::

    100 WINDOW 512,40,0,0:CLS
    110 CSIZE 0,0: CHAR_INC 5,8:OVER 1
    120 PRINT FILL$('.',102)

Window #1 now offers 5 rows and 102 columns instead of 4 rows and 85
columns, but text can only be read in overwrite mode (OVER 1). CHAR\_INC
6,8 is the highest possible value which will allow text to be read
without the need for OVER 1.

**WARNING**

Unless you have Minerva or Lightning installed (with \_lngASLNG
enabled), if you specify a character height less than the standard 10
pixels (for CSIZE x,0) for example, the strip printed will remain at ten
pixels, and although the screen driver might detect that it is not
necessary to scroll a window to fit the text on, it does not take
account of the height of the strip, which could therefore fall out of
the window (or into the system variables if your window is near the
bottom of the screen).

**CROSS-REFERENCE**

:ref:`csize`, :ref:`over`.

See also :ref:`ttinc`.

