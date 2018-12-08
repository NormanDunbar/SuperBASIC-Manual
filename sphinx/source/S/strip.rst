..  _strip:

STRIP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  STRIP [#ch,] colour                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

Whenever a character is printed to the QL screen, it is made up of two
components - the character itself which appears in the current INK
colour, and the rectangular block on which the character has been
formed. The latter is known as the 'strip' of the character and the size
of this strip depends on the current character size and spacing (see
CSIZE).

Normally, when you set the PAPER colour of a window, the
character STRIP is set to the same colour. However, you may wish to
print characters on a different background colour in order to make them
stand out. STRIP allows you to alter the colour of the character
background in the specified window (default #1) to a given colour (or
composite colour). However, if you want to print characters in a window
without using this character background (ie. forming a transparent
strip), you will need to use the commands OVER 0 or OVER -1 (see OVER
for more details).

**Example**

A simple routine for printing out a Title on screen::

    10 WINDOW 512, 256, 0, 0: PAPER 4
    20 MODE 4: CLS
    30 TITLE #1,'This is a Title', 120, 95
    40 :
    100 DEFine PROCedure TITLE(ch,text$,x,y)
    110   CSIZE 2,1: OVER 0
    120   CURSOR #ch,x-2,y+1
    130   STRIP #ch,0: PRINT #ch,FILL$(' ',LEN(text$))
    140   CURSOR #ch,x,y
    150   STRIP #ch,2: INK #ch,7
    160   PRINT #ch,text$
    170   CURSOR #ch,x-2,y+1
    180   OVER 1: INK#ch,0
    190   PRINT #ch,text$
    200 END DEFine

**NOTE**

The STRIP colour is automatically reset to the same as the PAPER colour
following a PAPER command.

**CROSS-REFERENCE**

:ref:`paper` also sets the
:ref:`strip` colour. Compare
:ref:`io-trap`. :ref:`csize`
and :ref:`char-inc` allow you to alter the
spacing between characters. :ref:`ink` contains
details of standard and composite colours. See also
:ref:`inverse` which can also prove useful.

