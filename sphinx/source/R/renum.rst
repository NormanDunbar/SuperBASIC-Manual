..  _renum:

RENUM
=====

+----------+------------------------------------------------------------------+
| Syntax   | RENUM [start\_line [TO end\_line];][new\_line][,step] or         |
|          |                                                                  |
|          | RENUM [start\_line] TO [end\_line][;new\_line][,step]            |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

When developing a SuperBASIC program, you will find that you sometimes
run out of space in which to insert a new line, because of the line
numbers which you have used. Line numbers can be any integer in the
range 1...32767 and it is therefore unlikely that you will not be able
to make room to fit any more lines into the program. To make more room,
you will need to RENUMber the program. You can either elect to use RENUM
in its simplest form, or a more complex form.

The simplest form of RENUM is the command::

    RENUM

This will renumber the whole of the SuperBASIC program in memory, so
that the first line number becomes line 100 and every subsequent
SuperBASIC line number will be in an increment of 10.

You can however
also use RENUM to renumber a specified range of lines in a program, by
using some of the optional parameters. These parameters have the
following effects:

- Start\_line specifies the first line to be RENUMbered (default 1).
- End\_line specifies the last line in the range to be RENUMbered (default 32767).
- New\_line the line number which the start\_line will be RENUMbered to (default 100).
- Step specifies the gap between each new line number (default 10).

RENUM will also alter line
numbers referred to in the standard QL ROM commands::

    GO SUB
    GO TO
    RESTORE

provided of course that the line number referred to is within the
range of lines being renumbered!.

If the line number originally
referred to does not exist, then RENUM will point it to the next program
line following that line number.

It is also possible that a reference to
a line number is actually calculated when the interpreter reaches that
line. In such instances, the line number reference can only be
renumbered if it is the first thing in the expression. For example, take
the following program::

    100 locat = 0
    110 REPeat loop
    120   RESTORE locat + 1000
    125   IF EOF: EXIT loop
    130   READ description$
    140   PRINT description$
    150   locat = locat + 1
    155   PAUSE
    160 END REPeat loop
    888 :
    1000 DATA 'Location One'
    1001 DATA 'Location Two'
    1002 DATA 'Location Three'

RENUM would renumber all of the line numbers beginning with line 100 in
steps of 10, however, the program would no longer work as the RESTORE
command in line 120 would then point to a non-existant line 1000. To
solve this, before using RENUM, alter line 120 to::

    120 RESTORE 1000 + locat

Having carried out the renumbering task, if the lines currently shown
in the list window are affected, they will be relisted in #2 (except
under SMS).

**Examples**

::

    RENUM 100

or::

    RENUM 1 TO

These are both the same as RENUM.


::

    RENUM 100 TO 1000;10,5

This will renumber all lines in the range 100 to 1000, with the new
lines beginning from line 10 in steps of 5.

::

    RENUM 1000;2000

This will renumber all lines from line 1000 onwards, with the new line
numbers beginning with line 2000, and increasing in steps of 10.

::

    RENUM 1000,20

This will renumber all lines from 1000 onwards, with the new line
numbers beginning with line 100 and increasing in steps of 20.

**NOTE 1**

On pre Minerva v1.77 ROMs, RENUM will not generally work correctly on
the line number reference in a RESTORE where this appears on the same
line as a DATA statement.

**NOTE 2**

On non Minerva ROMs, the current DATA pointer and ERLIN line numbers
tend to get lost in the process! Although SMS updates the DATA pointer,
it still has some problems. For example, try the following program::

    1 RENUM TO 170;1,1
    2 RESTORE
    3 READ x:PRINT x
    4 RENUM
    5 READ x:PRINT x
    6 RESTORE 6: DATA 10,12: RESTORE 6
    7 READ x: PRINT x
    8 STOP
    180 PRINT 'Why have I reached here?'

If you alter line 1 to read::

    1 RENUM 1,1

then the program just stops without an error at line 4. Minerva still
has problems with the above.

Try entering the command::

    RENUM 1 TO 7;1,1

An out of range error is reported even though there is no problem with
this range. Minerva does this correctly. We believe other ROMs will show
different symptoms (see the WARNING below).

**NOTE 3**

On Minerva ROMs (pre v1.97), if integer tokenisation is enabled, RENUM
cannot renumber line numbers less than 128.

**NOTE 4**

You cannot use RENUM to renumber lines out of sequence. For example,
given the following lines::

    100 REPeat loop
    110 IF INKEY$=CHR$(27):EXIT loop
    120 END REPeat loop

Any attempt to::

    RENUM 110 TO 110;200

would report an 'Out of Range' error, as you would be trying to renumber line 110 out of order!

**NOTE 5**

If you try to renumber a line outside of the range of line numbers (see
above), or there is not enough space between line numbers outside the
given range to fit the newly renumbered program lines into, this will
cause an 'Out of Range' error. For example, taking the routine listed at
note 4::

    RENUM 32760

or::

    RENUM 100 TO 110;119,1

would both report such an error.

**NOTE 6**

The Turbo and Supercharge compilers from Digital Precision cannot
compile a program with calculated RESTOREs, GO SUBs or GO TOs.

**NOTE 7**

Unfortunately, RENUM will not handle line number references in commands
other than GO TO, GO SUB or RESTORE, which can leave lines such as::

    SAVE flp1_Prog_ext,1000 TO 2000

high and dry!

**WARNING**

It is generally inadvisable to use RENUM within a program as the
interpreter tends to lose its place (see Note 2 above).

**CROSS-REFERENCE**

:ref:`dline` allows you to delete lines from a
program. :ref:`ed` allows you to edit a program in
memory. Also see :ref:`auto`.

--------------


