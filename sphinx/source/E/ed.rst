..  _ed:

ED
==

+----------+-------------------------------------------------------------------+
| Syntax   |  ED [#ch,] [start\_line]                                          |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command invokes Toolkit II's full-screen editor. This provides powerful
facilities for editing a SuperBASIC program loaded in memory and forms a useful
alternative to the QL's standard EDIT and AUTO commands.

ED will list the current SuperBASIC program from its first line (or from the
specified start\_line) onwards in the given channel (default #2). If the specified
channel (#ch) is not a console con\_ channel, then an error -15 (Bad Parameter)
will be reported. If any lines are too long to fit in the specified window, they
are wrapped round onto the next line, with this 'continuation line' indented in
order to differentiate from other program lines. It does however make sense to
use the widest possible window to avoid wrapping of lines.

Once a window-full of the listing is shown, ED will activate the cursor in the
window and you can then move up or down through the listing by using the up and
down cursor keys. The left and right cursor keys will move across the listing
lines (and even 'blank' space where the actual program lines do not appear).

Any attempt to alter a line (eg. to delete a character) will activate that line,
in which case it will be shown in inverse colours. Any attempt to move the cursor
off that line (or pressing <ENTER>) will tell ED to accept the alterations and
de-activate that line.

If the line is not acceptable to the SuperBASIC parser, then a 'Bad Line' error
will be generated in #0 and the line re-activated.

If you press the Break key or <ESC> whilst a line is active, it will be
de-activated and returned to its original state. If no line is active, <ENTER>
will insert a new line number half-way (if possible) between the number of the
line on which the cursor is situated and the next line number. If there is no
room for an additional line between the two program lines, <ENTER> will be
ignored.

If on the other hand, there is a gap of 20 or more (or there are no further
program lines), the new line number will be the current line number plus 10.

Another way of creating new lines is to amend the line number of the current
line. If you do this, a new line with the amended line number will be inserted
(overwriting any existing line) and the current line will remain the same (the
cursor remains on the same line). This enables you to copy lines from one
part of a program to another.

By way of further assistance to the SuperBASIC programmer, ED can work in two
modes - Overwrite Mode and Insert Mode. The latter is the default, in which
case any characters typed will activate the current line and insert them at
the current cursor position.

In Overwrite Mode, any characters typed will activate the current line and
replace the characters under the cursor.

A line can be deleted either by using <CTRL><ALT><←> (except on SMS where you
must use <CTRL><←>) or by deleting all of the visible characters in a line. If
you delete everything but the line number, then the line pointed to by that
line number will be deleted.

There are several other keys available which make editing a SuperBASIC program
much easier than under EDIT. The keys available from within the standard ED
are listed on the next page.

**NOTE 1**

Avoid ED #0 if possible.

**NOTE 2**

ED is likely to cause various problems if used from within a SuperBASIC
program.

**NOTE 3**

Any attempt to create SuperBASIC lines which are longer than 32766
characters may crash SuperBASIC.

**NOTE 4**

If a program contains a line 32767, this may upset ED when you are
editing the end of the program.

**NOTE 5**

ED is not very helpful when there is no program actually in memory, as
it starts off with a blank screen and you have to type the whole line,
including line number (even if you passed a line number with the
command).

**NOTE 6**

As from SMS v2.58 you can use ED ERLIN to edit the line which has caused
an error. We are not certain if this works on other implementations.

**NOTE 7**

Any attempt to ED a line number greater than 32757 can cause problems
(on some versions ED creates negative line numbers, on others you cannot
see the line being edited). SMSQ/E v2.85 (at least) does not have these
problems, but see Note 4 above.

**ED Special Key Presses**

The keys available in ED are:

+----------------+--------------------------------------------------------------------------------+
| Key Press      | Action                                                                         |
+================+================================================================================+
| <ENTER>        | Create new line, unless line is active, in which case this tells ED to accept  |
|                | alterations to the line and de-activate it.                                    |
+----------------+--------------------------------------------------------------------------------+
| <ESC>          | Leave ED - control returns to #0 unless line is active, in which case this     |
|                | de-activates line without altering it.                                         |
+----------------+--------------------------------------------------------------------------------+
| <CTRL><SPACE>  | See <ESC>.                                                                     |
+----------------+--------------------------------------------------------------------------------+
| <TAB>          | Move to the right by multiples of eight.                                       |
+----------------+--------------------------------------------------------------------------------+
| <SHIFT><TAB>   | Move to the left by multiples of eight.                                        |
+----------------+--------------------------------------------------------------------------------+
| ↑              | Move up one line.                                                              |
+----------------+--------------------------------------------------------------------------------+
| <ALT> ↑        | Scroll up a line (cursor remains still, text moves down).                      |
+----------------+--------------------------------------------------------------------------------+
| <SHIFT> ↑      | Scroll up one page (cursor remains still).                                     |
+----------------+--------------------------------------------------------------------------------+
| ↓              | Move down one line.                                                            |
+----------------+--------------------------------------------------------------------------------+
| <ALT> ↓        | Scroll down a line (cursor remains still, text moves up).                      |
+----------------+--------------------------------------------------------------------------------+
| <SHIFT> ↓      | Scroll down one page (cursor remains still).                                   |
+----------------+--------------------------------------------------------------------------------+
| →              | Move right one character.                                                      |
+----------------+--------------------------------------------------------------------------------+
| <CTRL> →       | Delete character under cursor (line becomes active).                           |
+----------------+--------------------------------------------------------------------------------+
| ←              | Move left one character.                                                       |
+----------------+--------------------------------------------------------------------------------+
| <CTRL> ←       | Delete character to left of cursor (line becomes active).                      |
+----------------+--------------------------------------------------------------------------------+
| <CTRL><ALT> ←  | Delete line under cursor (not under SMS).                                      |
+----------------+--------------------------------------------------------------------------------+
| <SHIFT><F4>    | Switch between overwrite and insert mode.                                      |
+----------------+--------------------------------------------------------------------------------+


SMS adds the following additional keys:

+------------------+--------------------------------------------------------------------------------+
| Key Press        | Action                                                                         |
+==================+================================================================================+
| <SHIFT> ←        | Move left one word.                                                            |
+------------------+--------------------------------------------------------------------------------+
| <ALT> ←          | Move to start of line.                                                         |
+------------------+--------------------------------------------------------------------------------+
| <CTRL><SHIFT> ←  | Delete word to left of cursor (line becomes active).                           |
+------------------+--------------------------------------------------------------------------------+
| <CTRL><ALT> ←    | Delete from cursor to start of line (line becomes active).                     |
+------------------+--------------------------------------------------------------------------------+
| <SHIFT> →        | Move right one word.                                                           |
+------------------+--------------------------------------------------------------------------------+
| <ALT> →          | Move to end of line.                                                           |
+------------------+--------------------------------------------------------------------------------+
| <CTRL><SHIFT> →  | Delete word under cursor (line becomes active).                                |
+------------------+--------------------------------------------------------------------------------+
| <CTRL><ALT> →    | Delete from cursor to end of line (line becomes active).                       |
+------------------+--------------------------------------------------------------------------------+
| <CTRL> ←         | Delete whole line under cursor.                                                |
+------------------+--------------------------------------------------------------------------------+
| <SHIFT><F5>      | Stuff the currently activated line into the Hotkey buffer so that this can be  |
|                  | later recalled with <ALT><SPACE>. **Note** this will only work if the Hotkey   |
|                  | system is active (see HOT\_GO). For this you need v2.58+.                      |
+------------------+--------------------------------------------------------------------------------+

**SMS NOTES**

Oddly, the SuperBasic interpreter allows you to enter a line which is
beyond the permitted range of line numbers, for example, enter as a
direct command::

    40000 PRINT 'This should not be accepted'

No error is reported, and the line is executed as if it had been
entered without a line number!

SMS also suffers with problems if you
edit a long line at the bottom of a window, so that as you type in more
text for the line, the program line extends below the bottom of the
window. 'Invalid Syntax' is printed over and over in #0, crashing the
computer. This was improved in v2.71 but still has not been totally
fixed.

The keying <CTRL> → clashes with the key used by early versions
of the program MasterBasic (by Ergon Software) which is used to move
between occurrences of an object which has been searched for in the
program. This has been resolved in v1.46+ of the program.

If you try to
use ED on #2 and this is not open, then SMS will use #0 (if this is not
open, it will open a default window #0). This is useful for SBASICs
which may be started with only one channel open (an input channel).

Another useful feature implemented on SMS is that as from v2.69, if you
enter the command ED without any parameters, this has one of two
effects. If you have not previously used ED, this edits the start of the
program (as on all other versions). However, if you have previously used
ED, the line which is shown at the top of #2 is the line which was at
the top of the window when you left ED previously - this can therefore
be useful when testing a section of the program.

**CROSS-REFERENCE**

Please also refer to :ref:`auto` and
:ref:`edit` which are replaced by this command.

