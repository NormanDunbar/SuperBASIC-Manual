..  _pan:

PAN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  PAN [#ch,] distance [,area]                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is very similar to SCROLL except that this enables you to
move a window left and right as opposed to up and down. In its most
simple form, PAN allows you to move the specified window (default #1) a
given number of pixels sideways. If a positive value for the distance is
given, the window will move to the right, whereas a negative distance
will move the window to the left. Again, as with SCROLL, the gap left
behind from the move will be coloured in the current PAPER
colour, and any contents of the window moved off the screen will be
lost. The additional parameter allowed by PAN lets you specify an area
of the given window to be moved. This can have one of the following
values:

..  tabularcolumns::    |l|p{0.85\textwidth}|

+------+---------------------------------------------------------------+
| Area | Effect                                                        |
+======+===============================================================+
| 0    | This moves the whole window (this is the default).            |
+------+---------------------------------------------------------------+
| 3    | This moves the whole of the text cursor line.                 |
+------+---------------------------------------------------------------+
| 4    | This moves everything on the text cursor line to the right of |
|      | the cursor (including the character under the cursor).        |
+------+---------------------------------------------------------------+

**Example**

A short procedure to scroll a given text message across the screen::

    100 DEFine PROCedure SCROLL_TEXT(line$)
    110   LOCal l$,loop
    120   l$=line$
    130   OPEN #3,scr_448x10a32x246
    140   PAPER#3,2:INK#3,0:CSIZE#3,1,0:CLS#3
    150   AT #3,0,0:PRINT#3,'INCOMING MESSAGE:'
    160   INK#3,7
    170   REPeat loop
    180     IF LEN(l$)=0:EXIT loop
    190     AT #3,0,55:PRINT#3,l$(1)
    200     BEEP 100,10
    210     IF LEN(l$)<=1:EXIT loop
    220     l$=l$(2 TO)
    230     AT #3,0,18:PAN #3,-8,4
    240     PAUSE 30
    250   END REPeat loop
    260 END DEFine

**NOTE 1**

In low-resolution mode (8 or 12), the distance will always be rounded
down to an even number of pixels.

**NOTE 2**

As with SCROLL, odd values for area and distance allow you to access
machine code routines (unless you have a THOR XVI, SMS, or Minerva ROM
(v1.63 or v1.64). To access these machine code routines:

- Take the TRAP #3 value for D0 and deduct 27.
- If the figure is less than 27, then take the negative result and add to 128.

For example, PAN 0,115 turns on cursor in #1 (TRAP #3,D0=$E).

This is in fact more useful than SCROLL or
CLS as area can be used to pass a parameter to D1, thus allowing you for
example, to access IOF.POSR - use PAN #3,n%,40 - to move the file
pointer.

**NOTE 3**

On pre MG ROMs, this command may fail if the window is smaller than the
cursor.

**NOTE 4**

On SMSQ/E pre v2.88, PAN in MODE 8 could ruin the screen display if an
odd parameter was specified, since SMSQ/E tried to move the screen by an
odd number of pixels (not supported in MODE 8). Although annoying, this
only had small effects.

**CROSS-REFERENCE**

Also please see :ref:`scroll` and
:ref:`paper`. THORs allow you to use
:ref:`io-trap` to access additional system calls.
Most system calls can be accessed using Toolkit II in any event.
Otherwise, see :ref:`btrap`,
:ref:`qtrap`, :ref:`ttet3` and
:ref:`mtrap`. The QDOS/SMS Reference Manual Section
15 contains full details of the TRAP #3 calls.

