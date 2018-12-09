..  _few:

FEW
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FEW(filen *[,{filex | #chx}]* [;cmd$])                           |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

Executes and waits for completion of the job filen, then returns the error code
from that job. FEW is a function version of EW and shares its argument list.


**Examples**

    retcode = FEW ("win1_XChange_xchange")

Will start Psion XChange in win1_xchange, wait until that job has ended and will
then return the error code of that job.



**CROSS-REFERENCE**

See :ref:`ew`
:ref:`exec\_w`.
:ref:`jobs`.

--------------

..  _ex\_m:

EX\_M
====

+----------+----------------------------------------------------------------------------------+
| Syntax   |  EX\_M file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*` [;cmd$] |
+----------+----------------------------------------------------------------------------------+
| Location |  SMSQ/E                                                                          |
+----------+----------------------------------------------------------------------------------+

Variant of the EX command that executes the given file. Differently to EX, which
starts the new job as owned by the system, EX\_M starts the job as a job owned
by its parent job. This means that the newly started job will be killed whenever
its owner job is killed. Obviously this command will only differ from EX when
used from a daughter BASIC or a compiled job.

**Examples**

    EX\_M win1_qmac

Will execute Qmac as a job owned by the current S*BASIC interpreter. When the
current interpreter ceases to exist, the new Qmac job will also be killed.

**NOTE**

An exhaustive explanation of the possible options can be found with the
description of EX. EX\_M takes the exact same arguments.

**CROSS-REFERENCE**

See :ref:`ex`

..  _ex\_m:

FEX\_M
====

+----------+-----------------------------------------------------------------------------------+
| Syntax   |  FEX\_M file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*` [;cmd$] |
+----------+-----------------------------------------------------------------------------------+
| Location |  SMSQ/E                                                                           |
+----------+-----------------------------------------------------------------------------------+

Variant of the FEX function that executes the given file and returns the new
job ID. Differently to FEX, which starts the new job as owned by the system,
FEX\_M starts the job as a job owned by its parent job. This means that the
newly started job will be killed whenever its owner job is killed.

**Examples**

    jobid = FEX\_M(win1_qmac)

Will execute Qmac as a job owned by the current S*BASIC interpreter. When the
current interpreter ceases to exist, the new Qmac job will also be killed.

**NOTE**

An exhaustive explanation of the possible options can be found with the
description of EX. FEX\_M takes the exact same arguments.

**CROSS-REFERENCE**

See :ref:`ex`

..  _alpha\_blend:

ALPHA\_BLEND
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  ALPHA\_BLEND [#channel,] transparency                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.26                                                  |
+----------+-------------------------------------------------------------------+

Alpha Blending is the process of combing a translucent foreground colour, with
a background colour, thereby producing a new blended colour. The degree of the
foreground colour's translucency may range from completely transparent to
completely opaque. It takes two parameters, a channel and an alpha weight
from 0 to 255 with 0 being transparent and 255 being opaque.

So, after executing for example ALPHA_BLEND #1,128 all future graphics commands
on channel 1 including BLOCK, CIRCLE, LINE and PRINT will draw their contents
half-transparent over the existing background until alpha blending is disabled
again (by setting the weight to the default of 255: ALPHA_BLEND #1,255).

**Examples**

    100 PAPER 0 : CLS
    110 ALPHA_BLEND 128                                 half-transparent
    120 FILL 1 : INK 2 : CIRCLE 40,50,20                overlapping circles
    130 FILL 1 : INK 4 : CIRCLE 65,50,20
    140 FILL 1 : INK 1 : CIRCLE 50,75,20
    150 CSIZE 2,0 : AT 10,4
    160 PRINT “Alpha blending!”                         superimpose some text
    170 ALPHA_BLEND 255                                 back to normal



..  _wm\_ink:

WM\_INK
======

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_INK [#channel,] palette\_index                               |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.00                                                  |
+----------+-------------------------------------------------------------------+

Newer Window Managers maintain a table of colour settings for programs to use
as “standard colours”. This is called the *System Palette*, also known as a
‘colour theme’. Four system palette tables, or themes, are supplied with the
operating system.

The list is sorted by *usage* rather than *colour* and includes colour values
to be used for display items such as window background, border, loose items and
so on. The items are referenced by a 4-digit hex number (16-bit value) as per
the list below, or the decimal number equivalent. These numbers should not be
used in standard INK, PAPER and BORDER statements – they are not colour values,
merely an index to an entry in a list of colour values. They should be used with
the WM_x equivalent commands, which will look up the colour values to be
used for the item numbers in the list.

WM\INK sets the ink colour for the channel indicated to the colour for the
specified item number from the system palette.

+---------+-------------------------------------------------+
| Number  | Meaning                                         |
+---------+-------------------------------------------------+
| $0200   | Window border                                   |
+---------+-------------------------------------------------+
| $0201   | Window background                               |
+---------+-------------------------------------------------+
| $0202   | Window foreground                               |
+---------+-------------------------------------------------+
| $0203   | Window middleground                             |
+---------+-------------------------------------------------+
| $0204   | Title background                                |
+---------+-------------------------------------------------+
| $0205   | Title text background                           |
+---------+-------------------------------------------------+
| $0206   | Title foreground                                |
+---------+-------------------------------------------------+
| $0207   | Loose item highlight                            |
+---------+-------------------------------------------------+
| $0208   | Loose item available background                 |
+---------+-------------------------------------------------+
| $0209   | Loose item available foreground                 |
+---------+-------------------------------------------------+
| $020a   | Loose item selected background                  |
+---------+-------------------------------------------------+
| $020b   | Loose item selected foreground                  |
+---------+-------------------------------------------------+
| $020c   | Loose item unavailable background               |
+---------+-------------------------------------------------+
| $020d   | Loose item unavailable foreground               |
+---------+-------------------------------------------------+
| $020e   | Information window border                       |
+---------+-------------------------------------------------+
| $020f   | Information window background                   |
+---------+-------------------------------------------------+
| $0210   | Information window foreground                   |
+---------+-------------------------------------------------+
| $0211   | Information window middleground                 |
+---------+-------------------------------------------------+
| $0212   | Subsidiary information window border            |
+---------+-------------------------------------------------+
| $0213   | Subsidiary information window background        |
+---------+-------------------------------------------------+
| $0214   | Subsidiary information window foreground        |
+---------+-------------------------------------------------+
| $0215   | Subsidiary information window middleground      |
+---------+-------------------------------------------------+
| $0216   | Application window border                       |
+---------+-------------------------------------------------+
| $0217   | Application window background                   |
+---------+-------------------------------------------------+
| $0218   | Application window foreground                   |
+---------+-------------------------------------------------+
| $0219   | Application window middleground                 |
+---------+-------------------------------------------------+
| $021a   | Application window item highlight               |
+---------+-------------------------------------------------+
| $021b   | Application window item available background    |
+---------+-------------------------------------------------+
| $021c   | Application window item available foreground    |
+---------+-------------------------------------------------+
| $021d   | Application window item selected background     |
+---------+-------------------------------------------------+
| $021e   | Application window item selected foreground     |
+---------+-------------------------------------------------+
| $021f   | Application window item unavailable background  |
+---------+-------------------------------------------------+
| $0220   | Application window item unavailable foreground  |
+---------+-------------------------------------------------+
| $0221   | Pan/scroll bar                                  |
+---------+-------------------------------------------------+
| $0222   | Pan/scroll bar section                          |
+---------+-------------------------------------------------+
| $0223   | Pan/scroll bar arrow                            |
+---------+-------------------------------------------------+
| $0224   | Button highlight                                |
+---------+-------------------------------------------------+
| $0225   | Button border                                   |
+---------+-------------------------------------------------+
| $0226   | Button background                               |
+---------+-------------------------------------------------+
| $0227   | Button foreground                               |
+---------+-------------------------------------------------+
| $0228   | Hint border                                     |
+---------+-------------------------------------------------+
| $0229   | Hint background                                 |
+---------+-------------------------------------------------+
| $022a   | Hint foreground                                 |
+---------+-------------------------------------------------+
| $022b   | Hint middleground                               |
+---------+-------------------------------------------------+
| $022c   | Error message background                        |
+---------+-------------------------------------------------+
| $022d   | Error message foreground                        |
+---------+-------------------------------------------------+
| $022e   | Error message middleground                      |
+---------+-------------------------------------------------+
| $022f   | Shaded area                                     |
+---------+-------------------------------------------------+
| $0230   | Dark 3D border shade                            |
+---------+-------------------------------------------------+
| $0231   | Light 3D border shade                           |
+---------+-------------------------------------------------+
| $0232   | Vertical area fill                              |
+---------+-------------------------------------------------+
| $0233   | Subtitle background                             |
+---------+-------------------------------------------------+
| $0234   | Subtitle text background                        |
+---------+-------------------------------------------------+
| $0235   | Subtitle foreground                             |
+---------+-------------------------------------------------+
| $0236   | Menu index background                           |
+---------+-------------------------------------------------+
| $0237   | Menu index foreground                           |
+---------+-------------------------------------------------+
| $0238   | Separator lines etc.                            |
+---------+-------------------------------------------------+

**Example**

    WM_INK #1,$206

Sets the foreground colour in #1 to the title window foreground.

**CROSS-REFERENCE**

See :ref:`wm\_paper
:ref:`wm\_strip`
:ref:`wm\_border`
:ref:`wm\_block`

..  _wm\_paper:

WM\_PAPER
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_PAPER [#channel,] palette\_index                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.00                                                  |
+----------+-------------------------------------------------------------------+

Newer Window Managers maintain a table of colour settings for programs to use
as “standard colours”. This is called the *System Palette*, also known as a
‘colour theme’. Four system palette tables, or themes, are supplied with the
operating system.

The list is sorted by *usage* rather than *colour* and includes colour values
to be used for display items such as window background, border, loose items and
so on. The items are referenced by a 4-digit hex number (16-bit value) as per
the list under the entry for :ref:`wm\_ink`, or the decimal number equivalent.
These numbers should not be used in standard INK, PAPER and BORDER statements –
they are not colour values, merely an index to an entry in a list of colour
values. They should be used with the WM_x equivalent commands, which will look
up the colour values to be used for the item numbers in the list.

WM\_PAPER sets the paper colour for the channel indicated to the colour for the
specified item number from the system palette.

**Example**

    WM_PAPER #1,$204

Sets the paper colour in #1 to the title window background colour from the
current system palette.

**CROSS-REFERENCE**

See :ref:`wm\_ink
:ref:`wm\_strip`
:ref:`wm\_border`
:ref:`wm\_block`

..  _wm\_strip:

WM\_STRIP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_STRIP [#channel,] palette\_index                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.00                                                  |
+----------+-------------------------------------------------------------------+

Newer Window Managers maintain a table of colour settings for programs to use
as “standard colours”. This is called the *System Palette*, also known as a
‘colour theme’. Four system palette tables, or themes, are supplied with the
operating system.

The list is sorted by *usage* rather than *colour* and includes colour values
to be used for display items such as window background, border, loose items and
so on. The items are referenced by a 4-digit hex number (16-bit value) as per
the list under the entry for :ref:`wm\_ink`, or the decimal number equivalent.
These numbers should not be used in standard INK, PAPER and BORDER statements –
they are not colour values, merely an index to an entry in a list of colour
values. They should be used with the WM_x equivalent commands, which will look
up the colour values to be used for the item numbers in the list.

WM\_STRIP sets the strip colour for the channel indicated to the colour for the
specified item number from the system palette.

**Example**

    WM_STRIP #1,$204

Sets the strip colour in #1 to the title window background colour from the
current system palette.

**CROSS-REFERENCE**

See :ref:`wm\_ink
:ref:`wm\_paper`
:ref:`wm\_border`
:ref:`wm\_block`

..  _wm\_border:

WM\_BORDER
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_BORDER [#channel,] palette\_index                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.00                                                  |
+----------+-------------------------------------------------------------------+

Newer Window Managers maintain a table of colour settings for programs to use
as “standard colours”. This is called the *System Palette*, also known as a
‘colour theme’. Four system palette tables, or themes, are supplied with the
operating system.

The list is sorted by *usage* rather than *colour* and includes colour values
to be used for display items such as window background, border, loose items and
so on. The items are referenced by a 4-digit hex number (16-bit value) as per
the list under the entry for :ref:`wm\_ink`, or the decimal number equivalent.
These numbers should not be used in standard INK, PAPER and BORDER statements –
they are not colour values, merely an index to an entry in a list of colour
values. They should be used with the WM_x equivalent commands, which will look
up the colour values to be used for the item numbers in the list.

WM\_BORDER sets the border colour for the channel indicated to the colour for the
specified item number from the system palette.

**Example**

    WM_BORDER #1,$20e

Sets the border colour in #1 to the information window border colour from the
current system palette.

**CROSS-REFERENCE**

See :ref:`wm\_ink
:ref:`wm\_paper`
:ref:`wm\_strip`
:ref:`wm\_block`


..  _wm\_block:

WM\_block
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_BLOCK [#channel,] width, height, x, y, palette\_index        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.00                                                  |
+----------+-------------------------------------------------------------------+

Newer Window Managers maintain a table of colour settings for programs to use
as “standard colours”. This is called the *System Palette*, also known as a
‘colour theme’. Four system palette tables, or themes, are supplied with the
operating system.

The list is sorted by *usage* rather than *colour* and includes colour values
to be used for display items such as window background, border, loose items and
so on. The items are referenced by a 4-digit hex number (16-bit value) as per
the list under the entry for :ref:`wm\_ink`, or the decimal number equivalent.
These numbers should not be used in standard INK, PAPER and BORDER statements –
they are not colour values, merely an index to an entry in a list of colour
values. They should be used with the WM_x equivalent commands, which will look
up the colour values to be used for the item numbers in the list.

WM\_BLOCK draws a block in the channel indicated using the colour for the
specified item number from the system palette.

**Example**

    WM_BLOCK #1,100, 40, 0, 0, $201

Draws a block 100 pixels wide and 40 pixels high to #1 in the current system
palette's window background colour.

**CROSS-REFERENCE**

See :ref:`wm\_ink
:ref:`wm\_paper`
:ref:`wm\_border`
:ref:`wm\_strip`



..  _wm\_movemode:

WM\_movemode
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_MOVEMODE mode                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.01                                                  |
+----------+-------------------------------------------------------------------+

Sets the mode in which windows are moved.

Modern window managers allow moving a window about the screen in various ways:

0 - the "classic" way - the pointer changes to the "move window" sprite which
is moved about the screen.

1 - "Outline": click on the move icon with the MOUSE - keep holding the button
down -, an outline of the window will appear which you can move around and
position where you want it. Release the mouse button and the window positions
itself correctly.

2 - "Full window". This is the same as 1 above, but instead of an outline, the
entire window contents will be desplayed during the movement. For Q40/Q60 users,
switching on the Cache is advisable...

3 - "Full window with transparency" (implemented in SMSQ/E v. 3.16). This is the
same as 2 above, but the window to be moved is made "transparent" : one can
"see through" it.  This is done via "alpha blending". Alpha blending requires
a lot of computing power. So, even if your machine can theoretically handle this
type of move, in practice it might not be feasible. For Q40/Q60 users, switching
on the Cache is advisable.

**Example**

    WM_MOVEMODE 0

Sets the window move mode to "classic", i.e. moving with the move icon.

**NOTE 1**
In any but move mode 0 windows cannot be moved by the keyboard and strictly
require a mouse. When moving windows with the keyboard, the move falls back
to the "classic" icon move for this operation.

**NOTE 2**
"Move with transparency" (mode 3) is only implemented for display modes where
alpha blending actually makes sense, i.e. modes 16, 32 and 33. In other display
modes, such as the QL screen modes, or Atari mono modes, this will be redirected
to move mode 2.

**NOTE 3**
The move modes are configured on a system-wide basis - you cannot have one job
moving in mode 0 and the other in mode 1.

**NOTE 4**
The window move mode can be configured in the operating system config blocks.


..  _pe\_bgon:

PE\_BGON
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PE\_BGON                                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.12                                                  |
+----------+-------------------------------------------------------------------+

Classic versions of the Pointer Environment suspend any jobs that are "buried"
in the window stack and try to output onto their window. Some system extensions
like PIE, PICE and PEX implemented work-arounds for this, allowing jobs to
continue running in the background even with output to the screen.

Starting from version 3.12, SMSQ/E supports background window I/O and update
natively. This feature is enabled and disabled by the commands PE\_BGON and
PE\_BGOFF.

**Example**

    PE\_BGON

Enables background window I/O

**CROSS-REFERENCE**

See :ref:`peon`
:ref:`pie\_on`
:ref:`pxon`
:ref:`pe\_bgoff`


..  _pe\_bgon:

PE\_BGOFF
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PE\_BGOFF                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.12                                                  |
+----------+-------------------------------------------------------------------+

Classic versions of the Pointer Environment suspend any jobs that are "buried"
in the window stack and try to output onto their window. Some system extensions
like PIE, PICE and PEX implemented work-arounds for this, allowing jobs to
continue running in the background even with output to the screen.

Starting from version 3.12, SMSQ/E supports background window I/O and update
natively. This feature is enabled and disabled by the commands PE\_BGON and
PE\_BGOFF.

**Example**

    PE\_BGOFF

Disables background window I/O

**CROSS-REFERENCE**

See :ref:`peoff`
:ref:`pie\_on`
:ref:`pxoff`
:ref:`pe\_bgon`

