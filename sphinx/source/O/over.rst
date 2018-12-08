..  _over:

OVER
====

+----------+-------------------------------------------------------------------+
| Syntax   |  OVER [#channel,] switch                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to set the way in which anything is written to
a specified window (default #1), whether by PRINT, LINE, BLOCK, or any
other command which prints something on a window. If the supplied
channel is not a window, then error -15 (bad parameter) will be
generated, as will any value of switch outside of the range -1..1. When
the QL is first initiated (or following a MODE  command), OVER is set to 0 (see
below). This can be altered by giving a different value for switch which
will have the following effect:

..  tabularcolumns::    |l|p{.8\textwidth}|

+--------+---------------------------------------------------------------------------+
| Switch | Effect                                                                    |
+--------+---------------------------------------------------------------------------+
| -1     | Everything is PRINTed on a transparent strip. However, each pixel         |
|        | which is drawn on that window in the current INK (or with BLOCK) is       |
|        | actually xored with the colour of the existing background.                |
+--------+---------------------------------------------------------------------------+
| 0      | This is the                                                               |
|        | standard mode, where characters are PRINTed in the current INK and STRIP  |
|        | and any pixels plotted on screen are also in the current INK.             |
+--------+---------------------------------------------------------------------------+
| 1      | This PRINTs characters on a transparent STRIP but pixels are drawn in the |
|        | current INK colour.  BLOCK is unaffected.                                 |
+--------+---------------------------------------------------------------------------+

When OVER -1 is used, it may be useful to calculate how
different colours will appear on screen. This can be achieved by XORing
the two colours in binary, with col1 ^^ col2, for example, a line drawn
in blue on a white background with OVER -1
will actually appear on screen to be INK 1^^7=6 (Yellow). A result of
OVER -1 is that if something is drawn twice in the same place in the
same colour, the object is effectively removed from the screen, leaving
the screen unaltered. This can be seen in the example program given for
IF.

**Example**

A simple demonstration which shows the effects of OVER on CIRCLE, PRINT
and BLOCK. See how easy/difficult it is to calculate how the end display
will look::

    100 MODE 8:WINDOW 448,200,32,16:PAPER 0:CLS
    110 INK 2:SCALE 100,0,0
    120 FILL 1:CIRCLE 50,50,35
    125 PAUSE
    130 INK 7:OVER -1:FILL 1:CIRCLE 50,50,35
    135 PAUSE 140 FILL 0:OVER 0
    150 PAPER 4:INK 7:PRINT"This is a simple circle"
    155 PAUSE
    160 OVER 1:PRINT"This is another line of text"
    165 PAUSE
    170 OVER -1:PRINT\"This is yet another line"
    175 PAUSE
    180 BLOCK 448,200,0,0,2

**NOTE 1**

OVER 0 is set after a MODE command.

**NOTE 2**

The following appears to be a bug in Minerva (pre v1.96) and most other
implementations:

On Minerva pre v1.96, OVER#0 and OVER#1 are equivalent
to OVER#1,0 and OVER#1,1 respectively, OVER#2 gives bad parameter, as
does OVER#-1. OVER is equivalent to OVER #1,0!!

On all later versions of
Minerva and SMS, the behaviour is more logical:

The channel number
defaults to #1 and the switch  to 0, so OVER#0 is OVER#0,0, OVER#1
is OVER#1,0 (not OVER#1,1), OVER#2 is OVER#2,0 and OVER#-1 naturally
produces a 'channel not open' error.

**NOTE 3**

OVER -1 causes various problems with the FILL command - see FILL.

**CROSS-REFERENCE**

Please look at :ref:`ink` and
:ref:`print`.
