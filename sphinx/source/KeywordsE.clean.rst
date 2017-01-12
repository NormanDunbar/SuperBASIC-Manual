
==========
Keywords E
==========

TODO
====

- There is a reference to the ESC command, probably in Beuletools, but it's not in the file.
- :ref:`eq-dlr` references NE$ but that's not found.
- :ref:`eprom-load` links to ROM\_TEST, but this is not found.
- :ref:`enl` and :ref:`el` link to ESC, which is not found.
- SET\_ENV is references from here, but is not known.




..  _easter:

EASTER
======

+----------+-------------------------------------------------------------------+
| Syntax   |  EASTER (year%) where year% >= 1583                               |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function calculates the date of Easter Sunday for any given year after 1583 
(when the Gregorian calender was introduced by Pope Gregory XIII to replace the 
Julian calender of Julius Caeser which had been in use since 46 BC). EASTER 
returns the date as a floating point number, where the day is the integer part 
of the number and the month is given by the digits following the floating 
point, eg. PRINT EASTER(1993)  shows 11.4 (April, 11th) 

**Example**

Easter Sunday is used as a basis to fix other clerical days, so if two
years have Easter Sunday on the same day, the other holy dates are
identical, too::

    100 INPUT "Year=";year 
    110 east1=EASTER(year) 
    120 FOR y=year+1 TO 32767 
    130   east2=EASTER(y) 
    140   IF east1=east2 THEN 
    150     PRINT "Next Easter Sunday on"!east1;". is in"!y;"." 
    160     EXIT y 
    170   END IF 
    180 END FOR y

**NOTE**

EASTER does not return the correct value on SMSQ/E for some reason.

**CROSS-REFERENCE**

:ref:`gregor`

--------------


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
between occurences of an object which has been searched for in the
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

--------------


..  _edit:

EDIT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  EDIT [start\_number] [,step]                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to enter the SuperBASIC line editor in order to alter a SuperBASIC 
program loaded in memory. It will automatically create line numbers in the command line (#0) 
to assist in entering SuperBASIC programs, in much the same way as AUTO. EDIT would normally 
only be entered as a direct command (although you can include it in a program line, the 
line numbers will not be generated until the program has finished its work). 

Once entered, you will be presented with the first line start\_number (default 100) - if 
this line already exists in the program, then the existing line will be presented. 
Otherwise, you will only see the current line number.

Pressing the up and down arrow keys will move you to the previous line or the next line 
(respectively) in the program, although if there is no previous (or next) line, then you 
will exit the EDIT mode. However, if you press the Enter key, if step is specified 
(default 0), this will act in the same way as AUTO. However, if step is not specified, 
you will leave EDIT mode. 

The main advantage of using EDIT over ED is how EDIT handles the screen. If the program 
has not been previously EDITed (or a PROC/FN Cleared message has been displayed) then 
EDIT will show a section of the current program in #2 when you move off the line currently 
being EDITed with the cursor keys or <ENTER>. This section will have the line which was just 
EDITed as the top line and will go on to fill #2 with additional lines of the program. However, 
if the program has already been EDITed and the PROC/FN Cleared message has not been displayed, 
then EDIT will not affect the display on screen (other than showing parts of the program in #0) 
until you EDIT a line which is within the range of lines which were previously being EDITed. 

This range of lines is actually slightly bigger than the lines which would have been displayed 
in #2, going from an invisible top line (the line above the displayed line) to an invisible 
bottom line (the line below the displayed line). Now, this can be quite useful when searching 
a program for some text or deciding where to copy a section of the program to, or even to 
line up characters on screen when the program has been RUN. 

The listing which last appeared on #2 is represented as::

    110 PAPER 0:INK 4:CLS(Invisible Top Line) 
    -------------------------------------------- 
    120 PRINT 'A PROGRAM'(Displayed Lines) 
    130 PRINT 'TO GET YOUR NAME'
    140 INPUT \\'ENTER YOUR NAME';name$
    150 PRINT \\
    160 PRINT 'HELLO'!name$
    -------------------------------------------- 
    170 PRINT \\"I'M YOUR COMPUTER"(Invisible bottom Line )

**NOTE 1**

You cannot set an absolute step value of zero - omit this parameter to
achieve the same result!

**NOTE 2**

On non-Minerva ROMs EDIT uses the same routine as RENUM to check its
parameters, which means that you can specify a start\_line and an
end\_line, although they do nothing. For example::

    EDIT 100 TO 1000;1000,20

would create lines 1000, 1020, 1040, ....

**NOTE 3**

The maximum line number is 32767. Both start\_number and step should be
integers - if they are not, they will be rounded to the nearest integer
(compare INT).

**NOTE 4**

Additional keys are available for editing on Minerva (see INPUT).

**NOTE 5**

EDIT can give problems if it is issued after breaking into a program
which was in the middle of a PROCedure or FuNction at the time. 

On non-Minerva ROMs, this is likely to produce a 'not implemented' error
and the wrong line. Press Break and try again do not try to edit the
line. On Minerva ROMs (pre v1.97) this is compounded by the fact that
Minerva tends to try to run the program again. 

Sometimes you are lucky
and Minerva tries to jump to a non-existent line number before
presenting you with the desired line. Unfortunately, EDIT is never
really safe in this context, and you should either type CLEAR before
EDIT or use ED.

**NOTE 6**

On pre Minerva ROMs SuperBASIC is liable to lock up if you try to EDIT a
line after trying to call a PROCedure/FuNction which was defined at the
end of the program, but had been deleted.

**SMS NOTES**

On SMS the EDIT command is exactly the same as ED.

**CROSS-REFERENCE**

:ref:`auto` is very similar, especially where
:ref:`step` is specified.
:ref:`dline` deletes program lines.
:ref:`input` contains details of the available
keypresses for cursor navigation. :ref:`ed` provides a
different means of editing a SuperBASIC program. 

::

    PRINT PEEK_W(\\HEX('9C')) 

returns the line number of the invisible top line which was
last :ref:`edit`\ ed (except on SMS). 

::

    PRINT PEEK_W(\\HEX('9E')) 

returns the line number of the bottom line in #2
which was last :ref:`edit`\ ed (except on SMS).

--------------


..  _editf:

EDITF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  EDITF ([#ch,] {default \| default$} [,maxlen%])                  |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is similar to EDLINE$. However, EDITF is intended solely for asking 
the user to enter a floating point number. The specified default (which may be 
given as a number or a string) is printed at the current text cursor position 
in #ch  (default #1) and allows you to edit it. The parameter maxlen%  dictates 
the maximum number of characters allowed (this defaults to the amount set when 
the Turbo Toolkit is configured). The edited result is returned when <ENTER> 
is pressed. If the string contains a non-sensical value when <ENTER> is pressed, 
a warning beep is sounded.

**NOTE**

On non-SMS machines, a buffer full errror could be reported if an
attempt was made to enter a string longer than 118 characters, or the
length of the longest SuperBASIC line listed or edited to date,
whichever is longer.

**CROSS-REFERENCE**

See :ref:`edline-dlr`.
:ref:`edit-pct` and :ref:`edit-dlr`
are also useful.

--------------


..  _edit-pct:

EDIT%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  EDIT% ([#ch,] {default \| default$} [,maxlen%])                  |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is the same as EDITF, except that only integer values are acceptable.

**CROSS-REFERENCE**

See :ref:`editf`.

--------------


..  _edit-dlr:

EDIT$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  EDIT$ ([#ch,] default$ [,maxlen%])                               |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is similar to EDLINE$. It operates in the same way as EDITF, 
except that any string of characters can be edited, rather than being 
restricted to a number.

**CROSS-REFERENCE**

See :ref:`editf`.

--------------


..  _edline-dlr:

EDLINE$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  EDLINE$ (#ch, maxlen%, edit$)                                    |
+----------+-------------------------------------------------------------------+
| Location |  EDLINE (DIY Toolkit Vol E)                                       |
+----------+-------------------------------------------------------------------+

The function EDLINE$ prints edit$ at the current text cursor position in #ch 
(there is no default channel) and allows you to edit it. A maximum length of 
maxlen% characters is allowed. The edited result is returned. Unlike INPUT, 
EDLINE$ will not finish with <UP> or <DOWN> but only after <ENTER> and 
<CTRL><SPACE> (also <ESC> on Minerva). Instead <UP> and <DOWN> move the cursor 
to the start and end of the string respectively; apart from that the usual 
keys for editing are used: <CTRL><LEFT> deletes the character to the left 
of the cursor, <CTRL><RIGHT> the character under the cursor.

**Example**

::

    100 CLS 
    110 REPeat ask_name 
    120 PRINT \"Please enter your name: "; 
    130 Name$ = "Billy the Kid" 
    140 Name$ = EDLINE$(#1,40,Name$) 
    150 PRINT "Your name is '";Name$;"' (y/n)? "; 
    160 ok$ = EDLINE$(#1,1,"y") 
    170 IF ok$ INSTR "yY" THEN EXIT ask_name 
    180 PRINT "Try again..." 
    190 END REPeat ask_name 
    200 PRINT "Hello,"!Name$;"!"

**NOTE**

You need a special version of EDLINE$ to work correctly on Minerva and
SMS. This version is included with the DIY Toolkit package.

**CROSS-REFERENCE**

:ref:`edline-dlr` can be used to input numbers but
you have to ensure that the entered text can be successfully coerced to
a number, see :ref:`check-pct` and
:ref:`checkf` for that.
:ref:`edit-dlr` is similar. Other routines for human
input are for example: :ref:`input`,
:ref:`inkey-dlr`, :ref:`ask` and
:ref:`reply`.

--------------


..  _el:

EL
==

+----------+-------------------------------------------------------------------+
| Syntax   |  EL                                                               |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on the NLQ ( near letter 
quality) font on an EPSON compatible printer::

    PRINT EL  

is the same as::

    PRINT CHR$(27)&"x"&CHR$(1).

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`dbl`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`, :ref:`esc`,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _elis:

ELIS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ELIS (keyword$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function will return the machine code start address of the specified resident 
keyword if it is recognised by SuperBASIC. If the keyword is unknown, then the 
function will generate a Not Found error.

**CROSS-REFERENCE**

See :ref:`key-add`,
:ref:`flis` and :ref:`codevec`.
Compare :ref:`find` and
:ref:`lookup-pct`.

--------------


..  _ellipse:

ELLIPSE
=======

+----------+---------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | ELLIPSE [#ch,] x,y,radius,ratio,ecc :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`\ ,radius\ :sup:`i`\ ,ratio\ :sup:`i`\ ,ecc\ :sup:`i`]\ :sup:`\*` |
+----------+---------------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                      |
+----------+---------------------------------------------------------------------------------------------------------------------------------------------+

Both the ELLIPSE and CIRCLE commands perform exactly the same function.
We have however decided to split them, since if users adopt the habit of
using ELLIPSE to draw ellipses and CIRCLE to draw circles, 
this will help users understand SuperBASIC programs
much more easily. 

This command allows you to draw an ellipse in the
current INK colour of the given radius with its centre point at the
point (x,y). 

The ratio affects the difference between the major axis and
the minor axis - the greater the ratio, the greater the difference
between the two. 

The major (y) axis is specified by the parameter
radius, whereas the minor (x) axis is calculated by radius\*ratio which
therefore means that if ratio>1, the major axis will become the (x) axis
(if you see what we mean!). 

Ecc defines the angle at which the ellipse
will be drawn. This is measured in radians and forms the anti-clockwise
angle between a vertical line drawn through the origin of the ellipse
and the major axis. Thus, ecc=PI/4 draws an ellipse at an angle of 45
degrees. 

The actual positioning and size of the ellipse will depend upon
the scale and shape of the specified window (default #1). 

The
co-ordinates are calculated by reference to the graphics origin, and the
graphics pointer will be set to the centre point of the last ellipse to
be drawn on completion of the command. If any parts of the ellipse lie
outside of the specified window, they will not be drawn (there will not
be an error). 

If the parameters ratio and ecc are omitted, this command
has exactly the same effect as CIRCLE. This command will actually allow
you to draw multiple ellipses by including more sets of parameters. Each
additional set must be preceded by a semicolon (unless the preceding
ellipse uses five parameters). This means for example, that these all
perform the same action::

    ELLIPSE 100,100,20,1,2,50,50,20 
    ELLIPSE 100,100,20,1,2; 50,50,20 
    ELLIPSE 100,100,20,1,2: CIRCLE 50,50,20

Although the FILL command will allow you to draw filled ellipses on
screen (in the current ink colour), you will need to include a FILL 1
statement prior to each ellipse if they are to appear independently on
screen (this cannot be achieved when using this command to draw multiple
ellipses). 

If this rule is not followed, then any points which lie on
the same horizontal line (even though they may be in different ellipses)
will be joined.

**Example**

Try the following for an interesting effect::

    100 MODE 8 
    110 WINDOW 448,200,32,16:PAPER 0:CLS 
    120 SCALE 100,0,0 
    130 INK 4:OVER -1 
    140 REPeat loop 
    150   FOR ang=0 TO PI*2-(PI*2/20) STEP PI*2/20 
    160     FILL 1:ELLIPSE 70,50,40,.5,ang 
    170     FILL 1:ELLIPSE 70,50,40,.5,ang 
    180   END FOR ang 
    190 END REPeat loop

**NOTE**

On all ROMs other than Minerva v1.89+, very small ellipses and very
large ones can cause problems. Try::

    ELLIPSE 80,80,80,6,1 

on a non-Minerva machine for a laugh. 

Unfortunately, Lightning SE (v2.11) still contains
this bug and will bring it back!

**CROSS-REFERENCE**

Please refer to :ref:`circle`,
:ref:`ellipse-r`, :ref:`arc`,
:ref:`line` and :ref:`point`.

--------------


..  _ellipse-r:

ELLIPSE\_R
==========

+----------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | ELLIPSE\_R [#ch,] x,y,radius,ratio,ecc :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`\ ,radius\ :sup:`i`\ ,ratio\ :sup:`i`\ ,ecc\ :sup:`i`]\ :sup:`\*` |
+----------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                         |
+----------+------------------------------------------------------------------------------------------------------------------------------------------------+

This command draws an ellipse relative to the current graphics cursor.
See ELLIPSE above!

**CROSS-REFERENCE**

Please refer to :ref:`arc-r` and
:ref:`circle-r`.

--------------


..  _else:

ELSE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ELSE :sup:`\*`\ [:statements]\ :sup:`\*`                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command forms part of the IF...END IF structure and allows you to take alternative 
action if the condition contained in the IF statement proves to be false.

**CROSS-REFERENCE**

See :ref:`if` for more details.

--------------


..  _end:

END
===

+----------+-------------------------------------------------------------------+
| Syntax   |  END ...                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This keyword forms part of the structures: END WHEN, END SELect, END IF, END REPeat, 
END FOR and END DEFine  As such, it cannot be used on its own within a 
program - this will cause a 'bad line' error.

**CROSS-REFERENCE**

Please refer to the individual structure descriptions below for more
details.

--------------


..  _end--define:

END DEFine
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  END DEFine [name]                                                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the DEFine PROCedure and DEFine FuNction SuperBASIC 
structures, and has no meaning on its own. You may if you wish, place the name of 
the PROCedure or FuNction  after END DEFine to help make the SuperBASIC program 
more readable - this will however have no effect on how the command is treated 
by the interpreter, which will still take the next END DEFine as the end of the 
current definition block (even if it is followed by a different name). 

The interpreter will jump out of a definition block whenever it meets a RETurn 
statement. It will also jump out of a DEFine PROCedure definition when it meets 
an END DEFine statement. This does of course mean that END DEFine can be used in 
the middle of a PROCedure to force a return to the calling statement - however, 
this can cause other problems and a RETurn should be used, with END DEFine 
only appearing at the very end of the definition block. 

On the other hand, the interpreter can only jump out of a DEFine FuNction definition 
if it meets a RETurn - if the interpreter comes across an END DEFine in such situations, 
it will report the error 'Error In Expression'. On SMS the error 'RETurn not in 
Procedure or Function' is reported. If the definition block is not actually being used, 
but the interpreter is working its way through the program, when a DEFine PROCedure 
or DEFine FuNction statement is met, the interpreter will search for the next END DEFine, 
and having found one, will resume the program at the next statement. 

This does however mean, that unless an in-line DEFine structure is being used, if 
this command is missing, the interpreter will carry on searching through the program 
and may just stop without an error if END DEFine does not appear anywhere in the 
program after the initial DEFine PROCedure (or DEFine FuNction).

**Example 1**

The above rules mean that the following example will work under
SuperBASIC, but is extremely inefficient and difficult to decode::

    10 FOR i=1 TO 100 
    20   PRINT power(i) 
    30   DEFine FuNction power(x) 
    40     RETurn 2^x 
    50   END DEFine 
    60 END FOR i

**Example 2**

See if you can work out why the following program goes wrong::

    100 FOR i=1 TO 100 
    110   PRINT power(i) 
    120   DEFine FuNction power(x) 
    130     DEFine FuNction base 
    140       RETurn 2 
    150     END DEFine base 
    160     RETurn base^x 
    170   END DEFine power 
    180 END FOR i 

If you are having trouble, try inserting::

    155 PRINT 'Program line 155:';x

**NOTE**

END DEFine need not appear in an in-line definition statement, except
under SMS.

**SMS NOTE**

Checks are made on a program before it is run, and so if an END DEFine
statement is missing, this will be reported as an error ('Incomplete
DEFine clause'). SMS's improved interpreter will report the error
'Misplaced END DEFine' if END DEFine does not mark the end of a DEFine
PROCedure or DEFine FuNction block.

**CROSS-REFERENCE**

Please see :ref:`define--procedure` and
:ref:`define--function`. Other SuperBASIC
structures are :ref:`select--on`,
:ref:`if`, :ref:`repeat`,
WHEN XXX and :ref:`for`.

--------------


..  _end--for:

END FOR
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  END FOR loop                                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the FOR..END FOR SuperBASIC structure with the same 
loop name, and has no real meaning on its own. When the interpreter meets this 
statement, it then looks at the stack to see if a related FOR command has already 
been parsed. 

If not, then the error 'Not Found' will be reported, however, if such a FOR loop 
has been parsed, the interpreter will fetch the end parameter and if the loop is 
not yet at this value, then step is added to loop and control returned to the 
statement following FOR. 

If however loop is already at the end value, control 
passes to the statement following END FOR. 

The second variant is only available 
under SMS, where the interpreter presumes that if no loop name is specified, the 
programmer means the interpreter to return control to the most recent FOR 
statement (if the loop is not at its final value). 

When an EXIT loop is found, 
the interpreter will search for the relative END FOR loop, and if found, will 
resume program flow at the next statement. 

Under SMS, neither EXIT nor END FOR 
need have a loop identifier, and therefore EXIT will simply cause the program 
to jump to the statement after the next END FOR command (if no loop is 
specified). 

This does however mean, that except under SMS, unless an in-line 
FOR structure is being used, if this command is missing, the interpreter will 
carry on searching through the program and may just stop without an error if 
END FOR loop does not appear anywhere in the program.

**NOTE**

END FOR need not appear in an in-line FOR statement.

**SMS NOTE**

SMS will report 'unable to find an open loop' if the interpreter comes
across an END FOR command (without a loop variable name) without a
corresponding open FOR loop. If the interpreter comes across an END FOR
command (with a loop variable name) without a corresponding open FOR
loop the error 'undefined loop control variable' is reported.

**CROSS-REFERENCE**

Please see :ref:`for`. Compare
:ref:`next` and :ref:`exit`. Other
SuperBASIC structures are: :ref:`define--procedure`, :ref:`define--function`,
:ref:`select--on`, :ref:`if`, :ref:`repeat`, and WHEN XXX.

--------------


..  _end--if:

END IF
======

+----------+-------------------------------------------------------------------+
| Syntax   |  END IF                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the IF..END IF SuperBASIC structure, and has no meaning 
on its own. 

When the interpreter finds an IF condition statement it then evaluates 
the condition and carries out certain commands depending on whether the condition was 
true or false. 

Having carried out those commands, the interpreter then looks for a 
related END IF command, and will pass control onto the statement following END IF. 

This does however mean, that except under SMS, unless an in-line IF structure is 
being used, if this command is missing, the interpreter will carry on searching 
through the program and may just stop without an error if END IF  does not appear 
anywhere in the program. 

**NOTE 1**

END IF need not appear in an in-line IF statement.

**NOTE 2**

All ROMs (except for Minerva v1.93+ or SMS) can get mixed up with
multiple in-line IF..END IF structures - see IF.

**SMS NOTE**

Checks are made on a program before it is run, and so if an END IF
statement appears without a corresponding IF command, the error
'Misplaced END IF' is reported.

**CROSS-REFERENCE**

Please see :ref:`if`. Other SuperBASIC structures are:
:ref:`define--procedure`, 
:ref:`define--function`, 
:ref:`select--on`, :ref:`repeat`,
:ref:`for`, and WHEN XXX.

--------------


..  _end--repeat:

END REPeat
==========

+----------+-------------------------------------------------------------------+
| Syntax   || END REPeat identifier  or                                        |
|          || END REPeat [identifier]SMS only                                  |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command marks the end of the REPeat...END REPeat SuperBASIC structure with 
the same identifier, and has no meaning on its own. 

When the interpreter meets this 
statement, it then looks at the stack to see if a related REPeat command has already 
been parsed. If not, then the error 'Not Found' will be reported, however, if such 
a REPeat identifier has been parsed, the interpreter will force the program to loop 
around and return control to the statement following REPeat. 

Under SMS there is no 
need to specify the identifier on the END REPeat statement, in which case, the 
interpreter will presume that this is the end of the last REPeat loop to have been 
encountered. 

When an EXIT identifier is found, the interpreter will search for the 
relative END REPeat identifier (or under SMS the next END REPeat  command), and if 
found, will resume program flow at the next statement. 

This does however mean, that 
except under SMS, unless an in-line REPeat structure is being used, if this command 
is missing, the interpreter will carry on searching through the program and may just 
stop without an error if END REPeat identifier (or END REPeat under SMS) does not 
appear anywhere in the program.

**NOTE**

END REPeat need not appear in an in-line REPeat statement.

**SMS NOTE**

SMS will report 'unable to find an open loop' if the interpreter comes
across an END REPeat command (without a loop identifier) without a
corresponding open REPeat loop. If the interpreter comes across an END
REPeat command (with a loop identifier) without a corresponding open
REPeat loop the error 'undefined loop control variable' is reported.

**CROSS-REFERENCE**

Please see :ref:`repeat`. 

:ref:`next` loop\_variable is practically the same
although see :ref:`exit`. Other SuperBASIC structures
are: :ref:`define--procedure`, 
:ref:`define--function`, 
:ref:`select--on`,\ :ref:`if`,
:ref:`for`, and WHEN XXX.

--------------


..  _end--select:

END SELect
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  END SELect                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This marks the end of the SELect ON...END SELect SuperBASIC structure, and has no 
meaning on its own. When the interpreter has found a match for the value of the 
variable, it performs a series of commands, and then looks for the end of the block 
marked with END SELect. 

This means that except under SMS, unless an in-line SELect 
ON structure is being used, if this command is missing, the interpreter will carry 
on searching through the program and may just stop without an error if END SELect 
does not appear anywhere in the program.

**NOTE 1**

END SELect need not appear in an in-line SELect ON statement.

**NOTE 2**

Under SMS, if END SELect appears in an in-line SELect ON
statement, if any commands appear after END SELect on the same line, an
error will be reported.

**SMS NOTE**

Checks are made on a program before it is run, and so if an END SELect
statement is missing, this will be reported as an error ('Incomplete
SELect clause'). SMS's improved interpreter will report the error
'Misplaced END SELect' if END SELect does not mark the end of a SELect
ON definition block.

**CROSS-REFERENCE**

Please see :ref:`select--on`. Other SuperBASIC
structures are :ref:`define--procedure`,
:ref:`define--function`,
:ref:`if`, :ref:`repeat`,
WHEN XXX and :ref:`for`.

--------------


..  _end--when:

END WHEN
========

+----------+-------------------------------------------------------------------+
| Syntax   |  END WHEN                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM)                                                 |
+----------+-------------------------------------------------------------------+

This marks the end of the SuperBASIC structures: WHEN ERRor and WHEN condition ... 
END WHEN, and has no meaning on its own. When the program is first run, the 
interpreter marks the start of this structure and then (unless it is an in-line 
structure) looks for the end of the block marked with END WHEN. 

This means that if this statement is missing, except under SMS, the interpreter 
will carry on searching through the program and may just stop without an error 
if END WHEN does not appear anywhere in the program.

**NOTE**

END WHEN need not appear in a single line WHEN or WHEN ERRor statement, eg::

    100 WHEN a>4:PRINT 'a>4'.

**SMS NOTES**

Checks are made on a program before it is run, and so if an END WHEN
statement is missing, this will be reported as an error. 

SMS's improved
interpreter will also report the error 'Misplaced END WHEN' if END WHEN
does not mark the end of a WHEN ERROR definition block.

**CROSS-REFERENCE**

Please see :ref:`when--error` and :ref:`when--condition`. Other SuperBASIC
structures are :ref:`define--procedure`,
:ref:`define--function`,
:ref:`if`, :ref:`repeat`,
:ref:`select` and :ref:`for`.

--------------


..  _end-cmd:

END\_CMD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  END\_CMD                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This marks the end of a numberless file of direct commands for use with the MERGE 
command. This command should be entered on its own as the last line of the numberless 
file. It overcomes the problem explained in NOTE 1 of MERGE. 

**CROSS-REFERENCE**

Please see :ref:`merge`. :ref:`do`
is also useful for executing such files.

--------------


..  _end-when:

END\_WHEN
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  END\_WHEN                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This marks the end of the Turbo structure equivalent to the SuperBASIC WHEN ERRor 
structure. END\_WHEN has no meaning on its own and should only be used within 
Turbo compiled programs.

**CROSS-REFERENCE**

Please see :ref:`when--error`

--------------


..  _env-del:

ENV\_DEL
========

+----------+-------------------------------------------------------------------+
| Syntax   |  ENV\_DEL name$                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Environment Variables                                            |
+----------+-------------------------------------------------------------------+

This command is used to remove a specified environment variable. Please note that 
the name of the environment variable is case sensitive. If an empty string is 
passed as the argument, then an error will be reported.

**Example**

A boot program may specify where the files for the main program are
stored and then pass it to subsequently called programs with. Once the
program has finished, the environment variable may be deleted. 

::

    1000 source$='win1_PROGS_utils\_' 
    1010 SETENV "PROGLOC="&source$ 
    1020 EXEC_W source$&'main_exe' 
    1030 ENV_DEL "PROGLOC"

**CROSS-REFERENCE**

Please see :ref:`setenv`

--------------


..  _env-list:

ENV\_LIST
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  ENV\_LIST [#ch]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Environment Variables                                            |
+----------+-------------------------------------------------------------------+

This command lists all currently active environment variables to the specified 
channel (default #1).

**CROSS-REFERENCE**

Please see :ref:`setenv`

--------------


..  _enl:

ENL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ENL                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on double width on an 
EPSON compatible printer::

    PRINT ENL

is the same as::

    PRINT CHR$(27)&"W"&CHR$(1)

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`, :ref:`esc`,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _eof:

EOF
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EOF [(#ch)]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This is a logical function which actually has two uses in SuperBASIC. If no channel 
number is specified, then PRINT EOF  will return 1 unless the current program 
contains some DATA  lines which have not yet been READ. This is therefore useful 
to create programs which can handle any amount of data. However, if a channel 
number is specified, for example PRINT EOF(#1), then zero will be returned unless 
the given channel is linked to a file and the file pointer is at (or beyond) the 
end of that file (ie. whether or not there is data to be read from that channel).

**Example**

Two simple programs to retrieve an address from a given name (the full
name must be given on input). The first of these has the data stored in
the program, whereas the second has it stored on a file called
flp1\_address\_data::

    100 RESTORE 
    110 MODE 4 
    120 OPEN #3,con_448x200a32x16:BORDER#3,1,2:PAPER#3,0:INK#3,7 
    130 INPUT #3,'Input name to look for:'!search$ 
    140 REPeat loop 
    150   IF EOF:PRINT#3\\"No address stored":EXIT loop 
    160   READ name$,address$ 
    170   IF name$==search$:PRINT #3\\name$,address$:EXIT loop 
    180 END REPeat loop
    190 CLOSE #3 
    200 DATA 'Fred Blogs','17 Mulberry Court' 
    210 DATA 'John Peters','182 Johnson Ave.' 
    220 DATA 'Martin Edwards','83 Olive Drive'

::

    100 OPEN_IN #3,flp1_Address_data 
    110 MODE 4 120 OPEN #4,con_448x200a32x16:BORDER#4,1,2:PAPER#4,0:INK#4,7 
    130 INPUT #4,'Input name to look for:'!search$ 
    140 REPeat loop 
    150   IF EOF(#3):PRINT#4\\"No address stored":EXIT loop 
    160   INPUT #3;name$,address$  
    170   IF name$==search$:PRINT #4\\name$,address$:EXIT loop 
    180 END REPeat loop
    190 CLOSE #4:CLOSE #3

**SMS NOTE**

Until v2.55 this command was the same as EOFW, which meant that it would
only return a value if there was data waiting or it had received an end
of file code - this was changed back to the original to maintain
compatability.

**CROSS-REFERENCE**

:ref:`data` specifies a line of data statements.
:ref:`restore` resets the data pointer and
:ref:`read` will actually fetch the data.
:ref:`close` closes a given channel after it has
been used. :ref:`pend` or
:ref:`io-pend-pct` are much better for use on
pipes. See also :ref:`eofw`.

--------------


..  _eofw:

EOFW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  EOFW (#ch)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This function is very similar to EOF in that it returns the value 0 if there is 
data waiting to be read from the specified channel, otherwise it returns 1. The 
difference is that this version of the function will however wait until data is 
received or the end of file code is received, which is especially useful on pipes 
which may not always work with EOF which returns 1 if the channel does not contain 
any data to be read.

**CROSS-REFERENCE**

See :ref:`eof`. :ref:`pend` and
:ref:`io-pend-pct` are very similar.

--------------


..  _eprom-load:

EPROM\_LOAD
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  EPROM\_LOAD device\_file                                         |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v1.21+), SMS                                        |
+----------+-------------------------------------------------------------------+

You cannot plug QL EPROM cartridges into the various other computers which now 
support QL software, which would normally make some software which contains part 
of its code on EPROM, unuseable. In order that you can use such software on other 
computers, you need to create a file on an original QL containing an image of the 
EPROM cartridge plugged into the QL's ROM port. To do this, use the command:: 

    SBYTES flp1_EPROM_image,49152,16384  

It is hoped that software producers who sell software which requires an EPROM 
cartridge will make versions available with ready-made images of the cartridge, 
so that the software can be used by users without access to an original QL. 

Having 
done this, you will need to have the ST/QL Emulator switched on (or SMS loaded on 
the other computer), then insert that disk into the Atari's disk drive, and use 
the command: EPROM\_LOAD flp1\_EPROM\_image  This will then copy the EPROM code 
into the same address on the Emulator or other computer as the EPROM cartridge 
occupies on the QL, thus making it useable.

**NOTE 1**

If you make images of several EPROM cartridges in this way, then
additional ones which are loaded with EPROM\_LOAD will be stored in
arbitrary addresses under SMS or the emulator. Therefore you will need
to ensure that cartridges which insist on being loaded at the address
$C000 (the QL's ROM port address), will need to be loaded first with
EPROM\_LOAD.

**NOTE 2**

On early versions of the Emulator, this was called ROM\_LOAD.

**NOTE 3**

On SMS before v2.52, this could crash the system if used on a Gold Card
or Super Gold Card without the specified file being present.

**CROSS-REFERENCE**

See also :ref:`rom`, :ref:`roms`
and :ref:`rom-test`.

--------------


..  _eps:

EPS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EPS [(x)]                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

Since the precision of the QL is limited, a number may not change if a very small 
value is added. The function EPS(x)  returns the smallest value which can be added 
to x so that the sum of x and EPS(x) will be different from x. This only makes 
sense for floating point numbers. The default parameter is 0. EPS(x) attains its 
smallest value at x=0, so EPS(0) returns the smallest absolute number which can 
be handled by SuperBASIC. EPS(x) is always greater than zero and EPS(x)=EPS(-x).

**Example**

An approximation of PI/4 as proposed by Leibniz::

    100 x = 0: d = 1 
    110 t0 = DATE 
    120 FOR i=1 TO 1E100 
    130   IF ABS(1/d) < EPS(x) THEN EXIT i 
    140   x = x + 1/d 
    150   d = - SGN(d) \* (ABS(d)+2) 
    160 END FOR i 
    170 t = DATE - t0 
    180 PRINT "Iterations ="!i!" Runtime ="!t;"s" 
    190 PRINT "Iterations per Second ="!i/t 
    200 PRINT "PI ="!4\*x!"(";PI;")"

Unfortunately, the algorithm is not efficient enough to compete with
the QL's precision, so that about 2E9 iterations are necessary to get a
suitable result. Since this will take a while (ages!), you can reduce
precision by a factor of one million, by modifying line 130::

    130 IF ABS(1/d) < 1E6 * EPS(x) THEN EXIT i

The program will then finish after 1075 iterations with 4\*x =
3.140662, not bad compared to 3.141593 when taking the drastic reduction
of precision into account.

**NOTE**

EPS does not recognise the higher precision used by Minerva. Minerva's
higher precision may have an effect on fractals and similar esoteric
calculations.

--------------


..  _eq-dlr:

EQ$
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EQ$ (type, string1$, string2$ )                                  |
+----------+-------------------------------------------------------------------+
| Location |  Btool                                                            |
+----------+-------------------------------------------------------------------+

This function expects the same parameters as GT$. It will return a value of 1 if 
the two strings are equal to each other using the same test as GT$.

**CROSS-REFERENCE**

See :ref:`gt-dlr` for more details.
:ref:`ne-dlr` is the same as::

    NOT EQ$ (type, string1$,string2$)
    

--------------


..  _erlin:

ERLIN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ERLIN                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM version)                                         |
+----------+-------------------------------------------------------------------+

This function returns the line where the last error occurred. 
If the error occurred in a line typed into the command window (#0), then zero is 
returned (zero is also returned if there is no error).

**Example**

It takes a lot of time to debug programs, so save typing by including a
variation of the following line in your BOOT program. Then, if an error
occurs and the program stops with an error message, simply press
<ALT><E> to see and edit the line where something went wrong::

    ALTKEY "e","ED ERLIN-20"&CODE(216)&CODE(216),""

or::

    ALTKEY "e","AUTO ERLIN",""

**CROSS-REFERENCE**

:ref:`ernum` returns the error number,
:ref:`report` invokes an error message and :ref:`when--error`
allows error trapping. :ref:`erlin-pct` is exactly the same.

--------------


..  _erlin-pct:

ERLIN%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ERLIN%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is exactly the same as ERLIN, except it will work on all versions 
of the QL ROM.

**CROSS-REFERENCE**

See :ref:`erlin` and
:ref:`ernum-pct`.

--------------


..  _ernum:

ERNUM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ERNUM                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM version)                                         |
+----------+-------------------------------------------------------------------+

This function returns the error number of the last error which occurred. An error 
number is negative and can be returned by any program (SuperBASIC, jobs, M/C 
Toolkits,...). The equivalent error messages are the same on all of the 
implementations of SuperBASIC, although they are also supported in different 
languages (see the Appendix for other languages):

+-------+------------------------+
| Error | English message        |
+=======+========================+
| -1    | Not Complete           |
+-------+------------------------+
| -2    | Invalid Job            |
+-------+------------------------+
| -3    | Out of Memory          |
+-------+------------------------+
| -4    | Out of Range           |
+-------+------------------------+
| -5    | Buffer Full            |
+-------+------------------------+
| -6    | Channel not Open       |
+-------+------------------------+
| -7    | Not Found              |
+-------+------------------------+
| -8    | Already Exists         |
+-------+------------------------+
| -9    | In Use                 |
+-------+------------------------+
| -10   | End of File            |
+-------+------------------------+
| -11   | Drive Full             |
+-------+------------------------+
| -12   | Bad Name               |
+-------+------------------------+
| -13   | Xmit Error             |
+-------+------------------------+
| -14   | Format Failed          |
+-------+------------------------+
| -15   | Bad Parameter          |
+-------+------------------------+
| -16   | Bad or Changed Medium  |
+-------+------------------------+
| -17   | Error in Expression    |
+-------+------------------------+
| -18   | Overflow               |
+-------+------------------------+
| -19   | Not Implemented Yet    |
+-------+------------------------+
| -20   | Read Only              |
+-------+------------------------+
| -21   | Bad Line               |
+-------+------------------------+


**NOTE**

Jobs may return a positive error number. The meaning of such a number
depends on the job. No error message will be reported.

**SMS NOTE**

The error messages have been redefined to try to make them more
intelligent, they are now:

+-------+------------------------+
| Error | English message        |
+=======+========================+
| -1    | Incomplete             |
+-------+------------------------+
| -2    | Invalid Job ID         |
+-------+------------------------+
| -3    | Insufficient memory    |
+-------+------------------------+
| -4    | Value out of range     |
+-------+------------------------+
| -5    | Buffer full            |
+-------+------------------------+
| -6    | Invalid channel ID     |
+-------+------------------------+
| -7    | Not found              |
+-------+------------------------+
| -8    | Already exists         |
+-------+------------------------+
| -9    | Is in use              |
+-------+------------------------+
| -10   | End of file            |
+-------+------------------------+
| -11   | Medium is full         |
+-------+------------------------+
| -12   | Invalid name           |
+-------+------------------------+
| -13   | Transmission error     |
+-------+------------------------+
| -14   | Format failed          |
+-------+------------------------+
| -15   | Invalid parameter      |
+-------+------------------------+
| -16   | Medium check failed    |
+-------+------------------------+
| -17   | Error in expression    |
+-------+------------------------+
| -18   | Arithmetic overflow    |
+-------+------------------------+
| -19   | Not implemented        |
+-------+------------------------+
| -20   | Write protected        |
+-------+------------------------+
| -21   | Invalid syntax         |
+-------+------------------------+
| -22   | Unknown message        |
+-------+------------------------+
| -23   | Access denied          |
+-------+------------------------+


Other errors are reported by the SBASIC
interpreter, but these are not covered by ERNUM.

**CROSS-REFERENCE**

:ref:`erlin` returns the line number where the error
occurred. :ref:`ernum-pct` is the same as this
function. :ref:`report` invokes an error message
and :ref:`when--error` can be used to trap
errors. The :ref:`err-...` functions are
alternatives to :ref:`ernum`.

--------------


..  _ernum-pct:

ERNUM%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ERNUM%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is exactly the same as ERNUM, except it will work on all versions 
of the QL ROM.

**CROSS-REFERENCE**

See :ref:`ernum` and
:ref:`erlin-pct`.

--------------


..  _err-...:

ERR\_...
========

+----------+--------------------------------------------------------------------+
| Syntax   || ERR\_NC, ERR\_NJ, ERR\_OM, ERR\_OR, ERR\_BO, ERR\_NO, ERR\_NF,    | 
|          || ERR\_EX, ERR\_IU, ERR\_EF, ERR\_DF, ERR\_BN, ERR\_TE, ERR\_FF,    | 
|          || ERR\_BP, ERR\_FE, ERR\_XP, ERR\_OV, ERR\_NI, ERR\_RO, ERR\_BL     |
+----------+--------------------------------------------------------------------+
| Location || QL ROM                                                            |
+----------+--------------------------------------------------------------------+

These are logical functions which return either 0 or 1 if the
corresponding error has occurred. Only one of them can have the value 1
at any time.

+----------+-------------------------+
| Function | Error Code              |
+==========+=========================+
| ERR\_NC  | NOT COMPLETE        -1  |
+----------+-------------------------+
| ERR\_NJ  | INVALID JOB         -2  |
+----------+-------------------------+
| ERR\_OM  | OUT OF MEMORY       -3  |
+----------+-------------------------+
| ERR\_OR  | OUT OF RANGE        -4  |
+----------+-------------------------+
| ERR\_BO  | BUFFER OVERFLOW     -5  |
+----------+-------------------------+
| ERR\_NO  | CHANNEL NOT OPEN    -6  |
+----------+-------------------------+
| ERR\_NF  | NOT FOUND           -7  |
+----------+-------------------------+
| ERR\_EX  | ALREADY EXISTS      -8  |
+----------+-------------------------+
| ERR\_IU  | IN USE              -9  |
+----------+-------------------------+
| ERR\_EF  | END OF FILE         -10 |
+----------+-------------------------+
| ERR\_DF  | DRIVE FULL          -11 |
+----------+-------------------------+
| ERR\_BN  | BAD NAME            -12 |
+----------+-------------------------+
| ERR\_TE  | TRANSMISSION ERROR  -13 |
+----------+-------------------------+
| ERR\_FF  | FORMAT FAILED       -14 |
+----------+-------------------------+
| ERR\_BP  | BAD PARAMETER       -15 |
+----------+-------------------------+
| ERR\_FE  | FILE ERROR          -16 |
+----------+-------------------------+
| ERR\_XP  | ERROR IN EXPRESSION -17 |
+----------+-------------------------+
| ERR\_OV  | ARITHMETIC OVERFLOW -18 |
+----------+-------------------------+
| ERR\_NI  | NOT IMPLEMENTED     -19 |
+----------+-------------------------+
| ERR\_RO  | READ ONLY           -20 |
+----------+-------------------------+
| ERR\_BL  | BAD LINE            -21 |
+----------+-------------------------+


**NOTE 1**

These functions are not affected by REPORT.

**NOTE 2**

On Minerva pre v1.98, the ERR\_ functions were returning 1 if any higher
error had occured!!

**WARNING**

The JS ROM version of ERR\_DF had a bug which crashed the system when
used. All later operating systems and Toolkit II, the THOR XVI, the
Amiga-QL Emulator, TinyToolkit, and BTool fix this.

**CROSS-REFERENCE**

See Appendix for other languages.

--------------


..  _error:

ERRor
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ERRor                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM)                                                 |
+----------+-------------------------------------------------------------------+

This keyword forms part of the structure WHEN ERRor. Please refer to WHEN ERRor. 
As such, this keyword cannot be used in a program on its own - this will report 
'bad line'.

**CROSS-REFERENCE**

:ref:`when--error` contains a detailed
description of this structure.

--------------


..  _ert:

ERT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ERT function                                                     |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

Normally, whenever you use a function (or anything else which may return an error 
code), you will need to assign the result of the function (or whatever else) to a 
variable and then test that variable in order to see whether or not an error has 
been generated. 

If an error has been generated, you will then need to report the 
error (if you do not intend to take any action to try and rectify the situation), 
something which can take a lot of program space, if you intend to write a program 
which does not require the command REPort to be present. 

The command ERT was 
introduced in the Hotkey System II to enable you to write programs which test the 
result for an error code and report the error all in one step.

**Example 1**

A simple program which provides its own error trapping::

    100 PAPER 0:INK 7 
    110 REPeat loop 
    120 CLS 
    130 AT 0,0:PRINT 'Enter an integer (0 to 300): '; 
    140 xerr=GET_INT 
    150 IF xerr<0:PRINT 'Error - try again':ELSE x=xerr:EXIT loop 
    160 PAUSE 
    170 END REPeat loop 
    180 PRINT 'The integer was : ';x 
    185 : 
    190 DEFine FuNction GET_INT 
    200   valid$='0123456789' 
    210   INPUT a$:IF a$='':RETurn -1 
    220   FOR i=1 TO LEN(a$):IF a$(i) INSTR valid$=0:RETurn -17 
    230   IF a$>300:RETurn -4 
    240   RETurn a$ 
    250 END DEFine


**Example 2**

A similar program which is designed to stop on an error::

    100 PAPER 0:INK 7 
    110 CLS 
    120 AT 0,0:PRINT 'Enter an integer (0 to 300): '; 
    130 xerr=GET_INT 
    140 IF xerr<0:REPORT xerr:STOP:ELSE x=xerr 
    150 PRINT 'The integer was : ';x 
    155 : 
    160 DEFine FuNction GET_INT 
    170   valid$='0123456789' 
    180   INPUT a$:IF a$='':RETurn -1 
    190   FOR i=1 TO LEN(a$):IF a$(i) INSTR valid$=0:RETurn -17 
    200   IF a$>300:RETurn -4 
    210   RETurn a$ 
    220 END DEFine

**Example 3**


The same program as in the second example, but using ERT::

    100 PAPER 0:INK 7 
    110 CLS 
    120 AT 0,0:PRINT 'Enter an integer (0 to 300): '; 
    130 ERT GET_INT 
    140 PRINT 'The integer was : ';x 
    150 DEFine FuNction GET_INT 
    160   valid$='0123456789' 
    170   INPUT a$:IF a$='':RETurn -1 
    180   FOR i=1 TO LEN(a$):IF a$(i) INSTR valid$=0:RETurn -17 
    190   IF a$>300:RETurn -4 
    200   x=a$ 
    210   RETurn x 
    220 END DEFine

**NOTE**

When you are using ERT, always beware of what you are testing for an
error, for example, if you had altered line 130 in the second example
to::

    130 ERT x=GET_INT

you would not actually be testing to see whether the function GET\_INT
returned an error, but whether the line x=GET\_INT produced an error - x
itself would not be altered, hence the need to assign the result to x
inside the function.

**CROSS-REFERENCE**

:ref:`report` will report an error without stopping
the program.

--------------


..  _et:

ET
==

+----------+-------------------------------------------------------------------+
| Syntax   |  ET file :sup:`\*`\ [,{filex \| #chx}]\ :sup:`\*` [;cmd$]         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

The syntax for ET is the same as for the Toolkit II variant of EX and it also 
operates in a similar manner. However, ET is intended for low level debugging, 
ie. to trace execution of the machine code commands step by step. 

A monitor program such as Qmon is necessary. 

The command ET loads the executable program, installs the job and immediately 
suspends the job by setting its priority to zero. Control is then returned to 
SuperBASIC to allow you to use a monitor program.

**CROSS-REFERENCE**

:ref:`ex`

--------------


..  _etab-dlr:

ETAB$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ETAB$ (string$ [,tabdist]) where tabdist=1..255                  |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

Some editors and word-processors use the character CHR$(9) as a tab mark to save 
the space which would otherwise be needed to store several spaces. The function 
ETAB$ takes a given string, expands all tab marks in it and returns the result. 

If the tabulator distance, tabdist, is not given, a default of eight characters 
is assumed. The length of string$ has to be smaller than 256 characters: 
LEN(string$)<256. 

Tabdist>255 has no effect.

**Example**

The text file test\_txt is shown with all tab marks expanded::

    100 OPEN_IN#3,test_txt 
    110 CLS 
    120 REPeat all_lines 
    130   IF EOF(#3) THEN EXIT all_lines 
    140   INPUT#3,line$ 
    150   IF LEN(line$)>255 THEN line$=line$(1 TO 255) 
    160   PRINT ETAB$(line$,4) 
    170 END REPeat all_lines
    180 CLOSE#3

**NOTE**

A value of tabdist<=0 will not produce usable output.

**WARNING**

Although tab mark distances of 32766 and 32767 are allowed, ETAB$ will
not produce a sensible output. It may even possibly crash the system.

**CROSS-REFERENCE**

:ref:`ctab-dlr` is the complimentary function to
:ref:`etab-dlr`. :ref:`instr` finds
the position of a string in another string. :ref:`len`
returns the length of a string.

--------------


..  _etat:

ETAT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ETAT (file$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  ETAT                                                             |
+----------+-------------------------------------------------------------------+

This function checks to see if the given file (passed as a string) exists and then 
checks upon its status (whether it can be opened etc). If necessary a standard 
error number is returned, otherwise ETAT will return 0, which means that the file 
can be accessed without the danger of an error such as "not found". This can 
therefore be used to avoid the need for error trapping.

**Example**

This program copies text files to window #1::

    100 REPeat input_loop 
    110 INPUT "File to view:"!file$ 
    120   AnError=ETAT(file$) 
    130   IF NOT AnError: EXIT input_loop 
    140   PRINT "Sorry, ";: REPORT#1,AnError 
    150 END REPeat input_loop 
    160 OPEN_IN#3,file$ 
    170 REPeat view_file 
    180 IF EOF(#3) THEN EXIT view_file 
    190 INPUT#3,line$: PRINT line$ 
    200 END REPeat view_file 
    210 CLOSE#3

**CROSS-REFERENCE**

:ref:`ftest` works like
:ref:`etat` but recognises the default device and
directory. :ref:`file-open`,
:ref:`fopen`, :ref:`fop-in`,
:ref:`fop-over` and
:ref:`fop-new` are all functions to open files
without the need for error trapping. :ref:`open`,
:ref:`open-in` and
:ref:`open-new` stop with error messages if an
error occurs. To avoid this, error trapping facilities, such as
:ref:`when--error` have to be used.

--------------


..  _ew:

EW
==

+----------+----------------------------------------------------------------------+
| Syntax   |  EW file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*`|
+----------+----------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                                 |
+----------+----------------------------------------------------------------------+

This command causes the given file (which must be an executable program) to be executed. 

If the drivename is not given, or the file cannot be found on the given device, EW 
will load the first file from the default program directory (see PROGD$), with subsequent 
programs being loaded from the default data directory (see DATAD$). The calling program 
will be stopped whilst the new job is running (ie. the new job cannot multitask with the 
calling program). If you supply any channels (which must already be open in the calling 
program) or filenames as parameters, these form channels which can be accessed by the job. 

If your program has been compiled with QLiberator or is to be run as an SBASIC job under 
SMS then each supplied channel will become #0, #1, #2 .... 

Note that with Turbo compiled programs the channels work backwards and will become #15, #14, 
#13 ... To access these channels from within the job, merely ensure that the job does not 
try to open its own channel with the same number, and then write the program lines as if 
the channels were open. Further, you can pass a command string (cmd$) to the program 
specifying what the executed job should do. It depends on the job what cmd$ should look 
like and also how you will access the given string. The Turbo and QLiberator compilers 
include commands in their Toolkits to read the supplied string; and Minerva MultiBASICs 
and SMS SBASICs include the function CMD$  which allows you to read the supplied string. 

If you have not used one of these compilers to produce the job, then you will need to 
read the string from the stack. Please note that the command string must appear as the 
last parameter for the command. The command string can be explicit strings and names as 
well as expressions. However, variables must be converted into expressions, for example 
by::

    EW 'flp1_xchange';(dataspace)  

On some very early versions of Toolkit II, you needed::

    EW 'flp1_xchange';dataspace&""  

Executable programs often return an error code back to the owner job (the program which 
started it). Especially with 'C' compiled programs, this will be non-zero if there are any 
errors. EW stops the owner job if this happened. There is unfortunately no way to stop 
this from happening unless you use error trapping (eg. WHEN ERRor, or Q\_ERR\_ON 
from QLiberator).

**Example 1**

::

    EW QED;"flp1_readme_txt"

The editor will be started from the default program directory and told
to load the file readme\_txt.

**Example 2**

::

    EW mdv1_QUILL

will start QUILL from microdrive 1.

**NOTE 1**

There are problems with EW and EX in Toolkit II v2.05 (and previous
versions) which make them unreliable and difficult to use with compiled
programs. The main problem lay in what was classed to be the owner of a
secondary Job. From v2.06 onwards, the owner for EX has been Job 0 and
the owner for EW, the current Job.

**NOTE 2**

TinyToolkit and BTool allow you to break out of a program started with
EW at any time by pressing <CTRL><SPACE> - the program can then be
treated as if it was started with EX.

**NOTE 3**

On some versions of the QL ROM (and Toolkit II), unless the Pointer
Environment is loaded, you may need to press <CTRL><C> to get back the
cursor at the end of the task.

**NOTE 4**

You cannot use EW (or similar) to execute a file stored on a PC or TOS
disk (even with Level-3 Device Drivers) - see the Device Drivers
Appendix, in particular the notes on Level-3 Device Drivers for further
details.

**MINERVA NOTES**

As from v1.93+, MultiBASICs can be started up with the command:

    EW pipep :sup:`*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`*` [;cmd$] 

Prior to this version, you needed to load the file Multib\_exe contained on
the disk supplied with Minerva and use the command:

    EW flp1_Multib_exe :sup:`*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`*` [;cmd$] 

How any supplied channels are dealt with is slightly different to all other
implementations. Its effect depends on how many channels are passed: 

- No channels passed - MultiBASIC started with a single small window which is
  the same for #0 and #1.
- One channel passed - This becomes both #0 and #1. 
- Two channels passed - These become #0 and #1 respectively. 
- Three or more channels passed - The first two become #0 and #1 respectively, then any
  additional ones become #3 onwards. 

Minerva MultiBASICs also treat any command string passed to them in a special way: 

- If the last character of the command string is an exclamation mark (!), then the
  MultiBASIC is started up with the original keywords built into the ROM,
  and any which had been linked into SuperBASIC subsequently (for example
  Toolkit II) will not be available to that MultiBASIC. This character is
  then removed from the command string before it can be read by the
  MultiBASIC. 

- If the command string contains the greater than sign
  (>), then anything which appears before that character in the string, is
  opened as an input command channel (thus allowing you to run a
  MultiBASIC program in the background) and then all characters up to and
  including the greater than character are deleted from the command string
  before it can be read by the MultiBASIC.

**Example**

Take a simple BASIC program to convert a given file (say
flp1\_TEST\_TXT) into uppercase::

    110 REPeat loop 
    120   IF EOF(#0) THEN EXIT loop 
    130   INPUT #0,a$ 
    140   IF a$='' THEN NEXT loop 
    150   FOR i=1 TO LEN(a$) 
    160     IF CODE(a$(i))>96 AND CODE(a$(i))<123 THEN 
    170       a$(i)=CHR$(CODE(a$(i))-32) 
    180     END IF 
    190   END FOR i 
    200   PRINT a$ 
    210 END REPeat loop 
    220 IF VER$(-1):CLOSE #0

Save this as flp1\_UC\_bas and then enter the command::

    OPEN #3,con 
    EW pipep,flp1_test_txt,#3;'flp1_UC_bas>'

or, prior to v1.93, use::

    OPEN #3,con 
    EW flp1_Multib_exe,flp1_test_txt,#3;'flp1_UC\_bas>'


The last line checks to make sure this program is not being run from
the original SuperBASIC interpreter (job 0) in which case, it then
closes #0. Unfortunately, on v1.97 (at least), this program fails to
spot the end of the file (try PEND instead of EOF), and therefore
reports an 'End of File' error on completion. Oddly, this error is not
reported if you use EX to run the program.

**SMS NOTE**

SMS allows EW and EX to run basic programs in the background, as an
SBASIC job. For example, using the Minerva example program above, this
could be used with the line::

    EW flp1_UC_bas,flp1_test_txt,#3

This does not report an error on completion. Beware however that prior
to v2.69, this command would not work in Qliberated programs to start an
SBASIC program. Because of this ability, SMS v2.58+ has amended the EW
set of commands so that it searches for a file in much the same way as
LOAD under SMS. 

Taking a default program device to be flp1\_, 

::

    EW ram1_TEST 

will look for the following files:

- ram1_TEST
- ram1_TEST_sav 
- ram1_TEST_bas 
- flp1_ram1_TEST 
- flp1_ram1_TEST_sav
- flp1_ram1_TEST_bas

**CROSS-REFERENCE**

For further information see :ref:`ex`.
:ref:`sbasic` allows you to set up several SBASIC
jobs under SMS. :ref:`mb` allowed you to start up a
MultiBASIC on early versions of Minerva. Please also see the appendix on
Multiple BASICs.

--------------


..  _ex:

EX
==

+----------+-------------------------------------------------------------------------------+
| Syntax   |  EX file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*` [;cmd$] |
+----------+-------------------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                                         |
+----------+-------------------------------------------------------------------------------+

This command forces the given file (which must be an executable program) to be 
executed and control is then generally returned to the calling program to enable 
the new job to multitask alongside the calling program. Similar parameters as 
for EW can be passed to the job. 

Use EW if the program cannot multitask for some reason or if you do not want it to.

**Example 1**

::

    EX QED;"readme_txt"

The QED editor will be started from the default program device and told to
load the file readme\_txt from the editor's default device.

**Example 2**

::

    EX UC_obj,ram1_hope_lis,par

A program called UC\_obj (a program which converts text to all upper
case) will be started up to run alongside all other programs. Two new
channels ('ram1\_hope\_lis' and 'par') are opened for the task to use
for its input and output channels respectively - the task must not open
its own channels but will rely upon the user supplying them as
parameters. 

The BASIC version of such a program is::

    110 REPeat loop 
    120 IF EOF(#0) THEN EXIT loop 
    130 INPUT #0,a$ 
    140 IF a$='' THEN NEXT loop
    150 FOR i=1 TO LEN(a$) 
    160   IF CODE(a$(i))>96 AND CODE(a$(i))<123 THEN
    170     a$(i)=CHR$(CODE(a$(i))-32) 
    180   END IF 
    190 END FOR i 
    200 PRINT#1,a$
    210 END REPeat loop

Turbo users will need to alter #0 and #1 to #15 and #14 respectively.

Minerva and SMS users can use this program without compiling it (see EW
above).

**Using EX to set up filters**

It is actually quite simple to create a multitasking environment on the
QL using the EX command to set up several programs all of which will
process a given file (or data entered into a given channel) in turn. 

The
syntax for this version of the command is: 

    EX jobparams\ :sup:`1`:sup:`\*`\ [TO jobparams\ :sup:`i`]\ :sup:`\*` [TO #chan\ :sup:`0`]

where jobparams represents the same parameters as are available for the
normal EX command, being: 

    file :sup:`\*`\ [,{file\ :sup:`x` \|#ch\ :sup:`x`}]\ :sup:`\*` [;cmd$] 

What this actually does, is to set up
a chain of jobs or channels whereby one extra channel is opened for each
job to form the output channel for the job on the left of the TO and
another channel is opened to form the input channel of the job on the
right of the TO. 

Where a channel number appears at the end of the line
(after a TO), this is taken as being the final output channel and
nothing further can be done to the original input.

**Examples**

How about extending the Upper case conversion 'filter' so that a given
text file is then printed out one line at a time with each line being
printed out as normal, but then printed again, but this time backwards!

First of all, the program to do the printing::

    110 REPeat loop 
    120   IF EOF(#0): EXIT loop: REMark Turbo uses #15, not #0 
    130   INPUT #0,a$:PRINT#1,a$: REMark Turbo uses #14, not #1 
    140   IF CMD$=='y': REMark Turbo users use OPTION_CMD$ 
    150   IF a$='':NEXT loop 
    160   FOR lop=LEN(a$) TO 1 STEP -1 
    170     PRINT#1,a$(lop); 
    180   END FOR lop 
    190   PRINT#1 
    200   END IF
    210 END REPeat loop

Compile this program and save the compiled version as flp1\_Back\_obj.

Now to carry out the desired task::

    OPEN #3,con 
    EX flp1_uc_obj,flp1_test_txt TO flp1_back_obj,#3;'y'

On Minerva v1.93+, you could use::

    OPEN #3,con 
    EX pipep,flp1_test_txt;'flp1_uc_bas>' TO pipep,#3;'flp1_back_bas>y'

Or on SMS:: 

    OPEN #3,con 
    EX flp1_uc_bas,flp1_test_txt TO flp1_back_bas,#3;'y'

How about trying this::

    OPEN #3,con 
    EX flp1_uc_obj,flp1_test_txt TO flp1_back_obj;'y' TO flp1_back_obj,#3;'y'

**NOTE 1**

On pre JS ROMs, you may find that if you EX a new Job whilst there is
already one Job in progress, the ink and paper colours of the first Job
are set to zero. This is a problem unless you have a key to redraw the
screen for the first Job (or the Pointer Interface).

**NOTE 2**

The THOR XVI always ensures that cursor control is passed to the new Job
on start-up rather than returning to the calling Job.

**MINERVA NOTE**

Please refer to notes about EW which explain how to use this command to
control MultiBASICs.

**SMS NOTE**

Please refer to notes about EW and use this command to control multiple
SBASICs.

**CROSS-REFERENCE**

Use :ref:`ftyp` or
:ref:`file-type` to check if a file is
executable. :ref:`fdat` returns the dataspace of an
executable file, :ref:`fxtra` provides other
information. :ref:`et` is very similar to
:ref:`ex`.

--------------


..  _exchg:

EXCHG
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  EXCHG device\_file,old$,new$                                     |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This command creates a Job which opens a channel to the specified file and then 
works through the file, replacing every occurrence of old$ with new$. The 
search for old$ is case independent. Both old$ and new$ must be the same length.

**Example**

::

    EXCHG flp1_Task_obj,'mdv','flp'

will replace all references to mdv1\_ or mdv2\_ to flp1\_ and flp2\_ respectively 
in the file flp1\_task\_obj.

**NOTE**

CHR$(0) cannot be replaced!

**CROSS-REFERENCE**

See also :ref:`convert`.

--------------


..  _exec:

EXEC
====

+----------+----------------------------------------------------------------------------------------------------------+
| Syntax   || EXEC program  or                                                                                        |
|          || EXEC file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`\*` [;cmd$] (Toolkit II, THOR XVI)  or |
|          || EXEC file :sup:`\*`\ [,#ch\ :sup:`x`]\ :sup:`\*` [;cmd$] (Minerva v1.93+)                               |
+----------+----------------------------------------------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                                                                      |
+----------+----------------------------------------------------------------------------------------------------------+

This command loads and starts a machine code or compiled program, but
then returns control to the calling job (ie. the job which issued EXEC)
so that both jobs are multitasking. 

Minerva v1.97+ has now implemented a sub-set of the Toolkit II standard, 
in that you can pass details of existing channels to a job as well as a command string.

**CROSS-REFERENCE**

With Toolkit II installed or on a THOR XVI,
:ref:`exec` is the same as
:ref:`ex`. See also
:ref:`exec-w`, :ref:`ew`,
:ref:`ttex` and :ref:`et`. If you
are using the Hotkey System or SMS then
see :ref:`exep` in this manual.

--------------


..  _exec-w:

EXEC\_W
=======

+----------+-------------------------------------------------------------------------------------------------------------+
| Syntax   || EXEC\_W program  or                                                                                        |
|          || EXEC\_W file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`\*` [;cmd$] (Toolkit II, THOR XVI)  or |
|          || EXEC\_W file :sup:`\*`\ [,#ch\ :sup:`x`]\ :sup:`\*` [;cmd$] (Minerva v1.93+)                               |
+----------+-------------------------------------------------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                                                                         |
+----------+-------------------------------------------------------------------------------------------------------------+

This command is the same as EXEC except that the calling job is
suspended until the program has finished.

**CROSS-REFERENCE**

Toolkit II and a THOR XVI make :ref:`exec-w` the
same as :ref:`ew`. See also
:ref:`exec`, :ref:`ex`,
:ref:`ttex`, :ref:`ttex-w` and :ref:`et`.

--------------


..  _exep:

EXEP
====

+----------+-------------------------------------------------------------------+
| Syntax   || EXEP filename [;cmd$] [,Jobname$] [,options] or                  |
|          || EXEP Thingname$ [;cmd$] [,Jobname$] [,options] (version 2.17+)   |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+
 
The first variant of the EXEP command is similar to the EX
and EW commands provided by Toolkit II. However, not only does EXEP
allow you to pass a command string to the program being called (as with
EX or EW), but you can also supply the Job name which will be shown in a
list of the Jobs currently loaded into memory. 

In order to make various
'problem' programs work correctly under the Pointer Environment, it is
sometimes necessary to pass various parameters (options) to the Hotkey
System when the program is called in order to tell it how to treat the
program. 

The command EXEP allows you to execute a program (in the same
way as with EXEC), but at the same time, pass these parameters to the
Pointer Environment. The parameters (or options) currently supported
are: 

- P [,size]- This tells the Hotkey System that the program is a Psion
  program (eg. Quill) which will try to grab all of the available memory.

  If size is not specifed, then the Hotkey System will ask the user to
  specify the maximum amount of memory (in kilobytes) that the program
  should use before the program actually starts. Otherwise, the program
  will be allowed to use size
  kilobytes of memory (if available). 

  When the Pointer Environment was
  first released, Qjump produced a program (Grabber) which could be used
  to amend the amount of memory addressed by the Psion programs once and
  for all - if this program has been used on your copies of the Psion
  programs, then do not use this option. 

- G [,x,y,a,b] - When a program is
  started, the Pointer Interface will store the area of the screen
  contained under each window as it is opened, restoring any part of the
  screen is no longer covered by an active window. 

  This provides
  non-destructive windows, one of the major assets of the Pointer
  Interface. However, some programs have a habit of opening windows,
  writing to the screen and then closing the window so that the text
  cannot be altered - creating background information. 

  Unfortunately, due
  to the way in which the Pointer Interface works, as soon as this window
  is closed, the background information would be lost. 

  The solution to
  this is to use a guardian window (created using this parameter) which
  specifies the area of the screen which the program is allowed to use and
  which must therefore not be restored until the program has ended (even
  if there are no current windows open on that area). The parameters are
  used to open a guardian window x pixels wide by y pixels high at the
  origin (a,b). 

  Any attempt by a program to open or resize a window so
  that part of it would fall outside this Guardian window will fail. 

  If you do not pass the size of the Guardian window as a parameter (eg. EXEP
  flp1\_Graph\_exe,g), the maximum permissible window size will be assumed
  (eg. 512x256 on a standard QL). 

- F - Some programs which use KEYROW to read
  the keyboard, or access the screen directly, can wreak havoc when
  multitasking alongside other programs. 

  This parameter causes the
  computer to only pass any keypresses read with KEYROW to the program
  started with EXEP. 

- U - With some programs, for example, a clock, it is
  desirable for this to be updated on screen even though it is not the Job
  at the top of the pile (ie. it is overwriting part of the current Job's
  windows). 

  The Pointer Interface will allow you to do this by passing the
  u parameter (for unlock), for example::

    EXEP flp1_Clock,u

The second syntax of EXEP is similar, except that instead of loading a
task stored with the given filename, it searches through the Thing list
for an Executable Thing with the given Thingname and then (if present),
will start that up as a new Job (if it is not present, then EXEP will
look on the default program device for a file called Thingname). 

For example, if you have QPAC2 present, EXEP Files will call up the files
sub-menu (in the latest versions of QPAC2, you could use, for example::

    EXEP files;'\S \D flp1__exe \O v','View _EXE'

to create a View files menu which will list all of the files on flp1\_
which end with \_exe, without any sort order; the job being called 'View
\_EXE' in the Jobs list).

**Example 1**

Consider the following program::

    100 MODE 4 
    110 OPEN #0,CON_10x10a132x66 
    120 OPEN #1,CON_448x200a32x16 
    130 PAPER 0:INK 7:CLS 
    140 BORDER 1,2:AT 10,9:PRINT 'Y AXIS' 
    150 AT 15,35:PRINT 'X AXIS'
    160 OPEN #1,CON_248x100a132x66:BORDER 1,4 
    170 PAUSE

If this program was compiled (without windows being copied across) and
then run, as soon as line 160 was reached, the information around the
sides of the graph would be lost! The reason for the PAUSE in line 170
is that as soon as the compiled program reached the end, it would close
all of its windows, and you would not be able to see anything! The
answer is to use a Guardian window (created using this parameter).
Presuming that the above program has been compiled under the filename
flp1\_Graph\_exe, you could use the line::

    EXEP flp1_Graph_exe,G,448,200,32,16

to define a Guardian window 448x200 pixels with its origin at (32,16).

**Example 2**

Try for example, compiling the following program and starting it
with:: 

    EXEP flp1_Test_exe,u

(presuming that is the filename you allocate to it)::

    100 OPEN #1,con_512x256a0x0 
    110 REPeat Loop 
    120   PRINT KEYROW(0) 
    130 END REPeat Loop

You will find it very difficult to do anything (including removing this
job). The solution is to pass this parameter to the Pointer Interface
which tells it to Freeze the program when it is in buried under another
Job's windows (eg. if you used <CTRL><C> to change to another Job). For
example, use the line::

    EXEP flp1_Test_exe,f 

**Example 3**

The SuperBASIC line:: 

    EXEP flp1_EDT;'flp2_Text',Editor,g

will start up an editor stored under the filename flp1\_EDT, which will
be given the Job name 'Editor' (which will be shown for example in the
JOBS table), provide it with a guardian window of 512x256, and tell it
to load a file called flp2\_Text.

**NOTE 1**

Before v2.21 of the Hotkey System II, you could not pass a command
string to the program being called.

**NOTE 2**

The various parameters can be mixed together, for example::

    EXEP flp1_Graph_exe,F,G,448,200,32,16;'ser1'

**NOTE 3**

Versions earlier than v2.24 will not allow you to alter the Job Name,
which will otherwise be the name given the program when it was created.

**CROSS-REFERENCE**

:ref:`thing` allows you to test whether or not a
given Thing is present. :ref:`ex`,
:ref:`exec`, :ref:`ew` and
:ref:`exec-w` are all similar to the first variant
of :ref:`exep`.
:ref:`get-stuff-dlr` will call up the QPAC2 files
sub-menu and allow you to read the chosen filename.
:ref:`hot-thing` allows you to set up a hotkey
to call an Executable Thing.

--------------


..  _exit:

EXIT
====

+----------+--------------------------------------------------------------------+
| Syntax   || EXIT loop\_variable (FOR loops)  or                               |
|          || EXIT loop\_name (REPeat loops)  or                                |
|          || EXIT(SMS only)                                                    |
+----------+--------------------------------------------------------------------+
| Location || QL ROM                                                            |
+----------+--------------------------------------------------------------------+

Using the first two variants of this command, the specified loop
(either a FOR or a REPeat structure) will be finished and the program
will jump to the first statement after the relative END FOR
loop\_variable or END REPeat loop\_name. 

The third variant only exists
under SMS and will force the interpreter to jump out of the current loop
being executed, whether it is a FOR loop or a REPeat loop - the
interpreter will just search the program for the next END REPeat or END
FOR statement.

**NOTE 1**

If two or more loops are nested together, it is possible to EXIT the
outer loop from within the inner loop::

    REPeat loop1
      ... 
      REPeat loop2
        ... 
        IF condition THEN EXIT loop1 ---+ 
        ...                             | 
      END REPeat loop2                  | 
      ...                               |
    END REPeat loop1                    | 
    ...                    <------------+ 


Such a structure is not regarded as elegant by some people because it is 
not possible to draw a structogram from this.

**NOTE 2**

If a program is badly written, this can lead to confusion - for example,
try::

    100 REPeat loop 
    120   PRINT 'Hello' 
    130   EXIT loop 
    140 END REPeat loop
    150 END REPeat loop

The interpreter fails to notice the misplaced END REPeat at line 150.

The first time that EXIT loop is encountered, the interpreter leaves the
loop at line 140 - however, line 150 forces the interpreter to execute
the loop a second time. This time, EXIT loop forces the interpreter to
jump out the loop at line 150. The same thing happens if you use FOR ...
END FOR instead of REPeat ... END REPeat

This feature allows you to jump back into a loop from anywhere in the
program (although this should be avoided). Compare what happens if NEXT
loop is used instead of END REPeat loop in line 150, EXIT loop will
always exit the loop at line 140. This means that NEXT loop can also be
used to jump back into a loop from anywhere in the program (although
again, this should be avoided). 

Note that in any event, these latter two
features will only work if the named loop has already been RUN (setting
up the loop variables)!!

**CROSS-REFERENCE**

Please see :ref:`for` and
:ref:`repeat` for more details.

--------------


..  _exp:

EXP
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EXP (var)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the value of the mathematical base e to the power of the 
given parameter (in other words, this is equivalent to the mathematical 
expression e\ :sup:`var`). This is the opposite to the function LN, ie. 
var=LN(EXP(var)). 

QDOS supports var in the range -512...511. The approximate value of e can be 
found by::

    PRINT EXP(1)  

::

    PRINT EXP(0)  

returns the value 1 - as any good mathematician knows, anything to the power 
of 0 returns the value 1.

**CROSS-REFERENCE**

:ref:`ln` returns the natural logarithm of the given
value.

--------------


..  _expand:

EXPAND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  EXPAND file$                                                     |
+----------+-------------------------------------------------------------------+
| Location |  COMPICT                                                          |
+----------+-------------------------------------------------------------------+

This command takes a screen file (which must have been created with COMPRESS), 
and re-expands it on the visible screen.

**NOTE 1**

EXPAND needs a working space of 32K. A memory overflow error will be
reported if there is not enough memory available.

**NOTE 2**

EXPAND assumes that the screen starts at $20000 and will therefore not
work on Minerva's second screen or extended resolutions.

**NOTE 3**

EXPAND will not work on QLs with resolutions above 512x256

**WARNING**

If the file was not saved by COMPRESS, it is most likely that the system
will crash. This is certain if the file is longer than 32K.

**CROSS-REFERENCE**

:ref:`compress`,
:ref:`fastexpand`.

--------------


..  _explode:

EXPLODE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  EXPLODE                                                          |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, QSound                                                    |
+----------+-------------------------------------------------------------------+

This command produces the sound of an explosion, very nice.

**CROSS-REFERENCE**

:ref:`snd-ext`, :ref:`bell`,
:ref:`shoot`.

--------------


..  _extras:

EXTRAS
======

+----------+-------------------------------------------------------------------+
| Syntax   || EXTRAS [#channel] or                                             |
|          || EXTRAS \\file (Toolkit II, THOR only)  or                        |
|          || EXTRAS [#channel][,width] (BTool only)                           |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI, QSound, BTool                              |
+----------+-------------------------------------------------------------------+

This command lists all of the machine code Procedures and Functions
(keywords) which are recognised by the SuperBASIC interpreter in the
given channel (default #1), or the given file (if the second variant is
used), which will be automatically opened and even overwritten if it
already exists (after asking the user to confirm that this is okay). 

The file will be closed at the end of the operation. 

The THOR XVI version
will not list those keywords which are resident in ROM (ie. available
when the THOR is first powered up). 

The BTool version lists the keywords
in columns and as such is the same as EXTRAS\_W. The number of columns
is adapted automatically to a window's width; if this is too wide for
your needs then you can specify a width in characters. 

The QSound
variant is intended for output to a non-screen channel (see WIDTH), in
which case an empty line appears between each name. If output is sent to
a window, then the words are all printed on the same line, obscuring
output.

**NOTE 1**

BTool's EXTRAS does not support the SuperBASIC WIDTH command and you
will therefore need to specify an absolute width as the second parameter
to format output.

**NOTE 2**

Versions of Tiny Toolkit pre v1.10 contained a different implementation
of this command, now renamed TXTRAS.

**NOTE 3**

Within an SBASIC (on SMS), EXTRAS only lists those keywords used in that
SBASIC to date - this is because the whole name table is not copied when
an SBASIC is started up, allowing different SBASICs to use the same name
for different things.

**CROSS-REFERENCE**

Use :ref:`sxtras` if you have a lot of extensions
in memory and you are looking for a specific one. See also
:ref:`txtras`, :ref:`vocab` and
:ref:`new-name`.

--------------


..  _extras-w:

EXTRAS\_W
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  EXTRAS\_W [#ch]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This lists all of the current SuperBASIC commands to the given channel (default 
#1). Unlike EXTRAS, the output appears in columns and there is no pause when 
the given window is full.

**CROSS-REFERENCE**

:ref:`extras` is very similar.

