..  _under:

UNDER
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  UNDER [#ch,] switch                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command switches underlining in the specified window (default #1)
either on or off. Underlining is enabled if switch=1
or disabled if switch=0. Other values of switch will return a 'bad
parameter' error.

If underlining is enabled, whenever anything is
PRINTed, a line will be drawn in the current INK colour in the bottom
but one row of the character.

If FLASH is enabled, although the
character will continue to flash, the underline itself will not. MODE
will disable underlining.

**Example 1**

::

    UNDER 1: PRINT 'Title:'!: UNDER 0: PRINT !'QL SuperBASIC'

**Example 2**

If you don't like the line which is drawn by underline than you can use
OVER to draw your own line with a different colour. Note however that
this line ought to be drawn before the underlined text since the line
should not overlap letters like g, p, q and j.

::

    100 DEFine PROCedure PRNT_UNDL (ch, x, y, text$, col1, col2)
    110   AT#ch,x,y: INK#ch,col2: OVER#ch,0
    120   PRINT#ch,FILL$("_",LEN(text$))
    130   AT#ch,x,y: INK#ch,col1: OVER#ch,1
    140   PRINT#ch,text$
    150   OVER#ch,0
    160 END DEFine PRNT_UNDL

::

    PAPER 3: CLS
    PRNT_UNDL #1,3,3,"Looking good.",7,0

**NOTE**

MODE will reset the current underline mode in all windows.

**CROSS-REFERENCE**

:ref:`ink` sets the current ink colour for the
specified channel, :ref:`print` prints out
characters.

