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


