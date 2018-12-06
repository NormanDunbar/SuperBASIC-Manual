..  _merge:

MERGE
=====

+----------+------------------------------------------------------------------+
| Syntax   | MERGE device\_filename  or                                       |
|          |                                                                  |
|          | MERGE [device\_]filename (Toolkit II)                            |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command is similar to LOAD *except* that it does not clear the
current program and variables out of memory prior to loading the given
program file. Neither is the screen cleared, which enables loading
pictures to be shown on screen whilst the main program loads.

This means
that any line numbers which appear in the program currently in memory
and which are repeated in the program file will be *overwritten* by the
lines in the program file, whereas any new lines will be inserted into
the program in memory.

Again, any lines without line numbers are
automatically executed as they are loaded into memory. This could
therefore be used within a program to execute a 'command file' stored on
a directory device (however, see below).

**Example**

A short program - when typed in, save this using the command::

    SAVE mdv1_test1_bas

::

    10 REMark Test1
    20 PRINT 'The Sinclair QL'

Now, type NEW and enter the following short program::

    5 REMark Test
    20 PRINT 'An old program line'
    30 PRINT 'SuperComputer'

Now, enter the command::

    MERGE mdv1_test1_bas

followed by::

    LIST

and the following will now form the program in memory::

    5 REMark Test
    10 REMark Test1
    20 PRINT 'The Sinclair QL'
    30 PRINT 'SuperComputer'

**NOTE 1**

Unfortunately, if you MERGE a file of direct commands (ie. a program
file without line numbers), only the first line will be read and the
file will be left open, making it impossible to change the
disk/microdrive cartridge. Some compilers provide commands to ensure
that the file is closed and all of the commands executed.

Minerva and Toolkit II close the file, but still only the first command is executed,
unless the MERGE command is used from within a program (in which case, the whole of the
command file is executed). SMS ensures that MERGE works in both of these circumstances.

**NOTE 2**

When writing command files, ensure that the lines are all checked
thoroughly before saving them without the line numbers, since a 'bad
line' error on such a file may crash the QL. However, if Toolkit II is
present, this makes a safe recovery, reporting 'bad line'.

**NOTE 3**

MERGE can become confused if used from within a PROCedure or FuNction.
Minerva and Toolkit II both report 'Not Implemented'.

**NOTE 4**

On Minerva v1.86, MERGE could become a little confused when used within
a program.

**NOTE 5**

When used within a program MERGE and MRUN are the same.

**NOTE 6**

Since Toolkit II v2.22 (and on the Minerva version), MERGE
has refused to try and load a file which does not have a file type of 0 - see FTYP.

**SMS NOTE**

MERGE follows the same rules for finding a program name as the LOAD
command.

**CROSS-REFERENCE**

:ref:`mrun` is very similar. See
:ref:`load` and :ref:`save`.
:ref:`do` is also very similar to
:ref:`merge`.

