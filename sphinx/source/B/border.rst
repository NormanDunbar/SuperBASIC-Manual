..  _border:

BORDER
======

+----------+-----------------------------------------------------------------+
| Syntax   | BORDER [#channel,] size [,colour] or                            |
|          |                                                                 |
|          | BORDER [#channel] Location: QL ROM                              |
+----------+-----------------------------------------------------------------+
| Location | QL ROM                                                          |
+----------+-----------------------------------------------------------------+

This command allows you to add a coloured border around the inside of
the edge of the specified window (default #1). If the second syntax is
used, this will turn off the border on the specified window - this is
the same as:

BORDER [#channel,] 0

If a border is present around the window, the physical size of the
window is altered, so that PRINT and LINE commands (for instance) will
not overwrite the border. Please note however, that the window is reset
to its original size prior to a BORDER command and therefore two
successive border commands only have the same effect as the second
BORDER command on its own.

If the specified size is too large to fit in the given window, the error
'Out of Range' will be reported.

As with other graphics commands, colour can actually be up to three
parameters forming a composite colour.

For example: BORDER #2,2,4

has the same effect as BORDER #2,2,4,4,3

or even BORDER #2,2,4,4

If no value is given for colour a transparent border will be added to
the given window. This means that a border will be created, but anything
which already appears in that border will not be affected.

Once the border has been re-drawn the cursor is automatically placed at
the top left hand position (0,0) just inside the border.


**Examples**

To produce a screen with a title, allowing you to scroll

text and do all sorts on the screen without affecting the title:

::

    100 MODE 4
    110 WINDOW 448,200,32,16
    120 PAPER 0: BORDER 0 : CLS
    130 AT 0,30: PRINT "THE TITLE PAGE"
    140 BORDER 9
    150 PAPER 2:CLS

To produce a 'take-off' effect:

::

    100 MODE 8
    110 WINDOW 448,200,32,16
    120 FOR i=1 TO 99
    130   BORDER i,2
    140 END FOR i


**NOTE 1**

If a border appears in a window, there is always a width of at least two
pixels down the sides to ensure that the border will appear in MODE 8.
Take the width value and if it is odd, add one for the width down the
sides of the window.


**NOTE 2**

The second syntax will not work on Minerva (pre v1.79) and the THOR XVI
- you will need to specify a width of zero instead.


**CROSS-REFERENCE**

:ref:`ink` describes composite colours.

Also see :ref:`window`.

--------------


