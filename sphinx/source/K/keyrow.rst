..  _keyrow:

KEYROW
======

+----------+-------------------------------------------------------------------+
| Syntax   |  KEYROW (row)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function is used to read the keyboard. It is not linked with a
channel which means that it can be used by a job to read the keyboard
whether or not that job has an active cursor. This is mainly only of use
for programs which work in the background unless a certain key is
pressed to bring them to life. If you try to use this command in a
program to control the screen, then this will undoubtedly lead to screen
corruption as the active program may itself be accessing the screen.

The main advantage which this function has when compared to INKEY$ is that
it allows programs to recognise when the user is pressing several keys
at once, such as the left and up cursor keys to move diagonally.

The function KEYROW is able to read several keys at once by using a keyboard
matrix, where each row is numbered and each key is assigned to a certain
row. If that key is pressed, then a bit is set in the integer value of
that row to represent which key has been pressed.

For British QLs, the format of the matrix is::

    Row 0| 7 4 F5 F3 F2 5 F1 F4
    Row 1| DOWN SPACE \ RIGHT ESC UP LEFT ENTER
    Row 2| " M £ B C . Z ]
    Row 3| ; G = F S K CAPSLOCK [
    Row 4| J D P A 1 H 3 L
    Row 5| O Y - R TAB I W 9
    Row 6| U T 0 E Q 6 2 8
    Row 7| , N / V X ALT CTRL SHIFT


+-------+----+----+----+----+---+---+---+---+
| Bit   |  7 |  6 |  5 |  4 | 3 | 2 | 1 | 0 |
+-------+----+----+----+----+---+---+---+---+
| Value |128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
+-------+----+----+----+----+---+---+---+---+

Please see the :ref:`a9-character--sets`\ .

The table reflects the physical keyboard layout and so may be different
on other languages.

Unfortunately, only one row at a time can be read with KEYROW and so the keys are arranged
into groups - for example, all of the cursor keys appear on one row, as
do all of the function keys.

When the function is used, the supplied parameter row specifies which row of the matrix is to be looked at. The
value returned will have bits set representing which keys (if any) in
that row were being pressed.

When KEYROW is used, any characters in the
type-ahead buffer are cleared, therefore, if you wish to avoid
accidental input by the user of unwanted keys, you could use::

    dummy = KEYROW(0): Quit$ = INKEY$(-1)

This will clear the type-ahead buffer and then wait for a new key to be
pressed - this is essential where, for example, you are asking for
confirmation that a program should be quit.

**Example 1**

If you were holding the <SHIFT> key down together with the left and up
cursor keys down::

    PRINT KEYROW(7)

would return the value 1 and::

    PRINT KEYROW(1)

would return the value 6.

**Example 2**

The following program moves a cross about the screen, using the cursor
keys - diagonal movement is allowed::

    100 MODE 4
    110 WINDOW 512,256,0,0:PAPER 0:CLS
    120 WINDOW 448,200,32,16
    130 INK 7:OVER -1
    140 SCALE 150,-120,-75
    150 x=0:y=0
    160 LINE x-10,y TO x+10,y,x,y-10 TO x,y+10
    170 REPeat loop
    180   ax=KEYROW(1)
    190   IF NOT ax:NEXT loop
    200   LINE x-10,y TO x+10,y,x,y-10 TO x,y+10
    210   IF ax&&2:x=x-(x>-120)
    220   IF ax&&16:x=x+(x<128)
    230   IF ax&&4:y=y+(y<75)
    240   IF ax&&128:y=y-(y>-75)
    250   IF ax&&8:PRINT 'Program Escaped':OVER 0:STOP
    260   LINE x-10,y TO x+10,y,x,y-10 TO x,y+10
    270 END REPeat loop

**NOTE 1**

Except under SMS, if you are holding three keys down which form three
corners of a rectangle on the keyboard matrix, the KEYROW function will
return the same value as if the key which appears in the fourth corner
of the rectangle was also depressed. The QL Manual suggests this does
not happen where one of the keys is <CTRL>, <ALT> or <SHIFT>, but this
still happens on the QL, even with Hermes.

**NOTE 2**

Some replacement full-sized keyboard interfaces will not recognise where
two letter keys, two function keys or two numerical keys are held down
at the same time.

**NOTE 3**

It is just possible that if KEYROW is being executed whilst a task is
being loaded or unloaded, the system will crash (the command does not
take place in supervisor mode). This has been fixed on THORs v4.16 (or
later) and Minerva.

**NOTE 4**

KEYROW had various problems under SMS before v2.58.

**NOTE 5**

This command is only partly implemented on THORs v4.16 (and later), and
does not work at all on earlier versions: the only multiple keystrokes
recognised are: <SHIFT>, <CTRL>, <ALT> and one other key! The corners of
the numeric pad act as diagonal cursor keys and the <CAPSLOCK> result is
obtained by pressing <5> on the numeric pad. INKEY$ should be used
instead.

**NOTE 6**

It is highly recommended that KEYROW is *not used* at all.

It reads the
physical keyboard directly, so will conflict with other jobs running in
a multitasking environment.

Another problem is the differences between
keyboards, for example, on a German QL the <Z> and <Y> keys are swapped
over compared to a British QL - INKEY$ is much better!

**ST/QL NOTES**

On the ST/QL Emulator, the KEYROW table is much extended, with the
following rows being added, both to take account of the additional keys
available on an ST keyboard and also to take account of the numeric
keypad (hence the repetition of various keys!)::

    Row 8 | F10 F9 F8 F7 F6 BACKSPACE ~
    Row 9 | + - CLR/HOME
    Row 10| DELETE INSERT
    Row 11| <
    Row 12| 8 7 * / ) ( HELP UNDO
    Row 13| 0 3 2 1 6 5 4 9
    Row 14| ENTER .

+-------+----+----+----+----+---+---+---+---+
| Bit   |  7 |  6 |  5 |  4 | 3 | 2 | 1 | 0 |
+-------+----+----+----+----+---+---+---+---+
| Value |128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
+-------+----+----+----+----+---+---+---+---+


The additional keys have the following meanings:

- BACKSPACE Delete one character to left (CTRL left).
- SHIFT BACKSPACE Deletes a word to the left.
- DELETE Delete character under cursor (CTRL right).
- SHIFT DELETE Deletes word under cursor.
- UNDO Undo current operation (CTRL ALT up).
- SHIFT UNDO Mega undo!
- CLR/HOME Freezes screen (CTRL F5)
- INSERT Hard space (SHIFT SPACE)
- CTRL SHIFT ALT UNDO Hard reset.

The keys on the numeric keypad have been redefined as follows:

+------------+--------+
| Keying     | Result |
+============+========+
| SHIFT (    | [      |
+------------+--------+
| SHIFT )    | ]      |
+------------+--------+
| SHIFT /    | \      |
+------------+--------+
| SHIFT ENTER| =      |
+------------+--------+
| CTRL (     | {      |
+------------+--------+
| CTRL )     | }      |
+------------+--------+
| CTRL \\    |  \|    |
+------------+--------+

**CROSS-REFERENCE**

:ref:`inkey-dlr` and :ref:`input`
allow user input from the keyboard whilst retaining compatibility across
the various QDOS implementations. These commands are also job specific,
and hence much better for use in multitasking programs. Some of the
HOT_XXX commands and
:ref:`exep` allow you to pass a U option to the
program to force the computer to freeze all other programs whilst this
one is running - this can be used to ensure that a program which uses
:ref:`keyrow` does not carry on reading the
keyboard whilst you are using another program.

