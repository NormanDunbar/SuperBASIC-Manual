..  _input:

INPUT
=====

+----------+----------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | INPUT [#chan,] :sup:`\*`\ [ [separator] [prompt\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\*`  or                                  |
|          |                                                                                                                                        |
|          | INPUT :sup:`\*`\ [ [#chan,] [separator] [prompt\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\*`  (THOR XVI and Minerva v1.97+ only)  |
+----------+----------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                 |
+----------+----------------------------------------------------------------------------------------------------------------------------------------+

This command will read a string of bytes from the specified channel
(default #1), which must end in CHR$(10) = <ENTER>. The fetched string
is then placed in the specified variable (var), which may be of any
type. Several sets of bytes may be read at the same time by specifying
more than one variable, for example by::

    INPUT a$,x,b$

Although each set of bytes must again be terminated by CHR$(10).

If the channel is write-only (eg. scr), error -15 (bad parameter) will be
reported.

If the specified channel is a console channel (con), the
cursor will be activated and the user will be able to type in a string
of characters at the current text cursor position. The characters typed
will appear in the current INK colour on the current STRIP colour, and
will also be affected by the settings of CSIZE, UNDER, FLASH and OVER.

If a channel is specified, this must be followed by a comma. It may
however also be followed by one or more separators. Each separator may
be one of the following:

- ! - (Exclamation mark) If a character other than a space appears immediately to the left of
  the current text cursor position, print a space. If prompt$ is specified
  after this, if prompt$ is too long to fit on the line from the current
  text cursor position, it will be placed at the start of the next line.

  If nothing follows this separator, then the text cursor is not moved at
  the end of the command.

- , - (Comma) This forces the text cursor to be placed on the
  next column which is a multiple of 8. Note that anything which appears
  on screen underneath the columns which are stepped over will in fact be
  blanked out in the current STRIP colour. If the next column which is a
  multiple of 8 is at the end of the current line, then the comma will
  move the text cursor to the start of the next line, not overwriting any
  text on screen!

- \\ - (Back slash) This forces the text cursor to be placed at the start of the next
  line. If nothing follows this separator this has no further effect - the
  text cursor is automatically placed at the start of the next line at the
  end of INPUT anyway (see below). This has no effect unless nothing
  follows this separator, in which case the text cursor is left alone at
  the end of the command.

- TO col - This moves the text cursor to the
  specified column (col). If however, the text cursor is already at or
  beyond the specified column, the text cursor is moved one space to the
  right (unless you have a THOR XVI - see TO). This separator must however
  be followed by yet another separator (normally ; (semicolon) so as to avoid
  confusion). If the specified column is further than the far right side
  of the specified channel, then TO merely wraps around the channel,
  continuing to count from the start of the next line. Note that any text
  under the columns which are jumped by TO will be blanked out in the
  current STRIP colour.

At the end of the INPUT command, the text cursor
is placed at the start of the next print line (unless an end separator
of '!', '\\' or ';' is used).

If prompt$ is specified, this will have no
effect unless the specified channel (#chan) is a console channel. If
this is the case, the specified string is written to the console
channel, (as with PRINT), followed by the specified separator. The
cursor on the specified channel is then activated at the current print
position and input awaited as normal if required.

If you are wondering
how to include a variable as part of prompt$, this is achieved by
placing the variable in brackets, for example the following will prompt
for 3 names to be entered::

    100 DIM a$(3,10)
    110 FOR i=1 TO 3
    120   INPUT 'Enter name number' ! (i) ! a$(i) TO 40; '-- Thank you'
    130 END FOR i

Unfortunately, you cannot include the variable which has been entered
in that same INPUT statement as a part of prompt$. If you do so, the
prompt$ will include the variable at the value it contained at the start
of the INPUT statement. For example, the following will not work
correctly, always saying x^2=1 no matter what value you enter::

    x=1: INPUT #2 ; 'Enter Number to Square' ! x \ 'x^2=' ; (x^2)

This could be fixed by using the following::

    x=1: INPUT #2 ; 'Enter Number to Square' ! x: PRINT 'x^2=' ; (x^2)

The keys available for editing the string of characters as you enter it
(via a console window) are shown on the next page. Once the string has
been entered, it is assigned to the specified variable and the
interpreter then looks at the INPUT
command to see if any further prompt$ need to be printed out, or
whether any further variables need to be entered; and if so, will repeat
the above steps.

**KEYS AVAILABLE FOR EDITING**

Once any prompt$ has been printed, whilst the user is inputting a
string, the following keys are available to the user to edit the string
being entered:

- <LEFT> Move cursor left one character (if possible)
- <RIGHT> Move cursor right one character (if possible)
- <ENTER> Accept string input
- <UP> Ditto
- <DOWN> Ditto
- <CTRL><LEFT> Delete character to left of cursor
- <CTRL><RIGHT> Delete character under cursor
- <CTRL><SPACE> Break current command - return control to #0

**Example 1**

::

    INPUT #2, TO 10 ; x$ \ TO 10 ; y$ \ 'Name:' ! : INPUT #2, TO 10 ; a$

**Example 2**

A function which will return a numeric variable safely. This accepts
leading and trailing spaces, and even spaces before the E part of a
number. Unfortunately, there is no way to prevent overflow errors, where
the number is outside the range 10E-616...10E616. However, it will
accept for example: ' +1.32 E-20 '::

    100 REMark Demonstration
    110 AT 10,0:PRINT 'Enter number: ':no=INPUT_no(#1,10,13)
    120 PRINT #0,lives
    125 :
    130 DEFine FuNction  INPUT_no (chan, posx, posy)
    140   LOCal var$,ix,loop,er,E_pos,dota,c
    150   er=0
    160   REPeat loop
    170     IF er<0:BEEP 1000,10:er=0
    180     dota=0
    190     AT#chan,posx,posy:PRINT#chan,FILL$(' ',20)
    200     AT#chan,posx,posy:INPUT#chan,var$
    210     IF var$="":er=-1:NEXT loop
    220     FOR ix=1 TO LEN(var$)
    230       IF var$(ix)<>' ':var$=var$(ix TO):EXIT ix
    240     END FOR ix
    250     FOR ix=LEN(var$) TO 1 STEP -1
    260       IF var$(ix)<>' ':var$=var$(1 TO ix):EXIT ix
    270     END FOR ix
    280     IF var$(1) INSTR '.1234567890-+'=0:er=-1:NEXT loop
    290     IF var$(1)='.':dota=1
    300     E_pos='E' INSTR var$
    310     IF E_pos+1>LEN(var$):er=-1:NEXT loop
    320     IF E_pos=0:E_pos=LEN(var$)+1
    330     FOR ix=2 TO E_pos-1
    340       c=CODE(var$(ix)):IF c=46:dota=dota+1
    350       IF c<>46 AND (c<48 OR c>57) OR dota>1:er=-1:NEXT loop
    360     END FOR ix
    370     IF E_pos>LEN(var$):RETurn var$
    380     FOR ix=E_pos+1 TO LEN(var$)
    390       IF var$(ix)<>' ':E_pos=ix-1:EXIT ix
    400     END FOR ix
    410     IF var$(E_pos+1) INSTR '1234567890-+'=0:er=-1:NEXT loop
    420     IF var$(E_pos+1) INSTR '-+':IF E_pos+2>LEN(var$):er=-1: NEXT loop
    430     FOR ix=E_pos+2 TO LEN(var$)
    440       c=CODE(var$(ix)):IF c<48 OR c>57:er=-17:NEXT loop
    450     END FOR ix
    460     RETurn var$
    470   END REPeat loop
    480 END DEFine

**NOTE 1**

If you try to INPUT a string greater than 32766 characters, this may
crash the system. It is therefore important that when INPUTting from a
file which is longer than 32766 characters, you are certain that it
contains a CHR$(10). If not, then use INKEY$.

**NOTE 2**

If no variable is specified, INPUT will have the same effect as PRINT.
In particular, as from SMS v2.57, INPUT on its own will clear a pending
newline, in the same way as PRINT on its own.

**NOTE 3**

Pre JS ROMs have a small input buffer, meaning that strings over 128
characters long lead to a 'Buffer Full' (-5) error. You can fix this for
QLiberator with a compiler directive.

**NOTE 4**

INPUT a% cannot accept -32768 (except on Minerva v1.76+ and SMS).

**NOTE 5**

If you try to INPUT a value into a slice of an undimensioned string, the
value will not be stored and BASIC may stop without a message. For
example::

    100 a$='Hello World'
    200 INPUT a$(7 TO)
    210 PRINT a$

The above program will not even attempt to allow you to INPUT the
value. The cure on all ROMs is to dimension the string, or to INPUT a
temporary variable::

    100 a$='Hello World'
    110 INPUT g$
    120 a$(7 to)=g$
    130 PRINT a$

**NOTE 6**

If the specified channel is not a console channel, prompt$ and any separators
are completely ignored. If there is no data in the
channel to be read, then the error 'End of File' (-10) is reported.
Under SMS, the prompt$ is still printed out, but any attempt to read a
variable results in 'Invalid parameter'.

**NOTE 7**

Except under Minerva v1.97+, if CURSOR was used to specify the position
of the input line and the position specified could not be set with the
AT comand, the display could become messy if the cursor was moved off
the initial row and then returned to it.

**NOTE 8**

Before SMS v2.59 if the <BREAK> key was pressed during an INPUT command,
the cursor could be left active.

**MINERVA NOTES**

Minerva provides the following additional keys for use in editing the
string:

- <ALT><LEFT> move to start of current text
- <ALT><RIGHT> move to end of current text
- <TAB> move along to x\*8th character from start of line (or end of data if nearer)
- <SHIFT><TAB> moves back in steps of 8 characters (or start of data if nearer)
- <CTRL><ALT><LEFT> delete to start of current (visible) line
- <CTRL><ALT><RIGHT> delete from current character to end of line
- <ESC> same as <CTRL><SPACE> (Break key)
- <SHIFT><ENTER> same as <ENTER>
- <SHIFT><SPACE> same as <SPACE>

Minerva v1.93+ alters keys further, both to make editing text easier and also to
prevent some anomalies in earlier versions:

- <UP> where the input data consists of more than one line, the up key moves up a line, unless
  cursor on first line of data in which case ends input. Any lines which
  have scrolled up out of the window will be re-shown if you press <UP> to
  move onto those lines. On previous ROM versions, if a line had
  disappeared off the screen, you could not access it. The only downside
  to this, is that any prompt which appeared before the text being edited
  cannot be re-shown - the prompt is simply 'blanked out' in the current
  PAPER colour.

- <DOWN> where input data consists of more than one line, the
  down key moves down a line, unless cursor on last line of data in which
  case it ends the input. This will allow you to access data lines which
  have scrolled down out of the window.

- <SHIFT><RIGHT> moves you right to
  the start of the next word (or end of the data). The start of a word is
  taken to be where the character to left of the cursor is space and the
  character under the cursor is something other than space.

- <SHIFT><LEFT> moves you left to the start of the previous word (or start
  of the data).

- <CTRL> + any combination with <LEFT> or <RIGHT> will
  delete the characters moved over. Spaces to the right which are caused
  by deletions are cleared in current PAPER colour - all other versions
  clear in current STRIP colour. Minerva v1.96+ (as with THOR XVI) will
  also allow: DIM x(4):INPUT x

This will patiently ask you to input the five values of x(0) to x(4).
Minerva v1.96+ (as per THOR XVI) also allows you to insert channel
numbers part way through an INPUT statement, although - unlike the THOR
XVI implementation - you still cannot use the variable entered as part
of the output.

**SMS NOTES**

SMS provides the following additional keys for use in editing the
string:

- <ALT><LEFT> move to start of current text

- <ALT><RIGHT> move to end of current text

- <TAB> move along to x\*8th character from start of line

- <SHIFT><TAB> moves back in steps of 8 characters <ALT><LEFT>move to start
  of current text

- <ALT><RIGHT> move to end of current text

- <TAB> move along to x\*8th character from start of line

- <SHIFT><TAB> moves back in steps of 8 characters

- <CTRL><DOWN> Deletes the whole of the input line


- <SHIFT><RIGHT> moves you right to the start of the next word (or end of
  the data). The start of a word is taken to be where the character to
  left of the cursor is space and the character under the cursor is
  something other than space.

- <SHIFT><LEFT> moves you left to the start of
  the previous word (or start of the data).

- <CTRL> + any combination with <LEFT> or <RIGHT> will delete the characters
  moved over.

The following keyings have also been altered:

- <DOWN> Has no effect!
- <UP> Has no effect!

**THOR XVI NOTES**

The THOR XVI (version 6.41) allows you to put channel numbers part way
through a statement, for example::

    INPUT 'Your name' ; #0 , name$ \ #1 ; ' is ' ; (name$)

instead of::

    PRINT 'Your name ' ; : INPUT #0,name$ : PRINT 'is ';name$

The THOR XVI also allows you to INPUT arrays with one statement. For
example::

    DIM x(4): INPUT x

will wait around for five values to be entered. No other implementation
(other than Minerva v1.96+) currently allows this.

**WARNING 1**

There is no facility to check the characters entered using INPUT and if
someone tries to enter a non-numeric character when INPUTting a numeric
variable an error will be caused. The second example provides a means of
ensuring numeric input is entered safely. Also refer to CHECKF and
CHECK%.

**WARNING 2**

You can crash SMS if you try to omit unwanted data by using the same
variable more than once in the INPUT statement. For example, consider
opening a channel to a file which contains a copy of a directory. The
first two lines contained in the file are not needed, being the disk
name and the number of sectors. You therefore may use a line similar to::

    100 OPEN_IN #3,ram1_direc
    110 INPUT #3,dummy$\dummy$

which would simply read these two lines. Unfortunately, on SMSQ/E (pre
v2.88), this appears to corrupt the return stack and may cause problems
when you try to use other variables. Minerva also exhibits some of the
same traits, although it manages to avoid a system crash. Oddly, if you
enter PRINT dummy$ following this command, will print either rubbish (on SMSQ/E pre v2.88)
or the first line of the file (on Minerva), whereas it should in fact
show the second line!! Even more curiously, if you RUN the program a
second time, INPUT works correctly! Later versions of SMSQ/E act in the
same way as Minerva. The original QL ROMs get this one correct.

**CROSS-REFERENCE**

The text cursor is positioned using commands such as
:ref:`at` and :ref:`cursor`. You
may prefer to use :ref:`edline-dlr` which allows you
to provide a default string for alteration, as well as specifying the
maximum number of characters that can be typed in.
:ref:`print` has some similar characteristics.
:ref:`his-set` allows you to set a history for a
console channel.

