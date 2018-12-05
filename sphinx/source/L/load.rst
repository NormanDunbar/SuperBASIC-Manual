..  _load:

LOAD
====

+----------+------------------------------------------------------------------+
| Syntax   | LOAD device\_filename  or                                        |
|          |                                                                  |
|          | LOAD [device\_]filename (Toolkit II)                             |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command looks for a SuperBASIC program held on the given device
under the specified filename (a program file), reporting the error 'not
found' if either the device or the filename does not exist. If found, it
then clears any current SuperBASIC program out of memory, closes all
channels with a channel number greater than #2, turns off any WHEN
processing, and performs a CLS on #0, #1 and #2. Each line of the
program file is loaded into memory and then parsed as if it had been
entered into the command line by the user. If any lines cannot be parsed
(ie. they would normally generate a 'bad line' error), then the word
MISTake is inserted into the line after the line number and the loading
process continues.

Under SMS when the program has been loaded, if there
have been any errors in the program, the error 'MISTake in Program' is
reported, or any other Interpreter error, with the line number listed.

Program files are stored on directory devices by the computer as pure
ASCII files, allowing them to be imported into text editors for ease of
editing (or even to be created in separate editing programs), copied
direct to a printer (using the COPY\_N command), and VIEWed on screen.

However, this means that the program has to be parsed each time that it
is loaded, making the loading process quite slow. This can however be
circumvented by using a fast loading utility - we highly recommend QLOAD
from Liberation Software for this purpose.

If the program file contains
some lines in it which do not have line numbers, then these are
automatically executed as if they had been typed direct into the
keyboard. For example, one method of software protection would be to
turn off the Break key on loading and then RUN the program. This can be
achieved by entering the following as direct commands, with the desired
program in memory::

    OPEN_NEW #3,flp1_file
    LIST #3 PRINT #3,'BREAK_OFF':RUN'
    CLOSE #3

This actually opens a new file, and inserts as direct commands
BREAK\_OFF and RUN after the body of the program (LIST in this instance
is similar to SAVE except that it allows you to add further text to the
end of the program file).

These two commands will be interpreted
immediately that flp1\_file has been loaded, thus preventing anyone from
looking at the listing (the break key is disabled and the program
immediately RUN).

Unfortunately though, this does not really work very
well, as you cannot stop the user from VIEWing the file on screen!!

If you have Toolkit II present, then if a device is not specified, or LOAD
cannot find the specified file on the given device, then Toolkit II will
add the default data device to the filename. If the file still cannot be
found, then the default program device is used instead.

**Example 1**

To load a file Test1\_bas on mdv1\_ (the default data device is flp1\_
and the default program device is flp2\_)::

    LOAD mdv1_Test1_bas

If Toolkit II is present and Test1\_bas is not on mdv1\_ (or there is
not a microdrive cartridge in mdv1\_), the default data device is added,
equivalent to::

    LOAD flp1_mdv1_Test1_bas

If the file is still not found, the default program device is used,
which is equivalent to::

    LOAD flp2_mdv1_Test1_bas

**Example 2**

Some examples showing the capabilities of LOAD::

    LOAD 'n' & station & '_flp1_'&file$

Loads the given file from flp1\_ on the given network station.

::

    LOAD ser1c

Loads a file from the device attached to ser1.

::

    LOAD neti_3

Loads a file which will be SAVEd over the network by station 3.

**NOTE 1**

LOAD can leave error trapping enabled on JS and MG ROMs - see WHEN ERRor
for details.

**NOTE 2**

Minerva users will notice that in current versions, LOAD
clears both screens even if #0, #1 and #2 are all on the same screen.

**NOTE 3**

LOAD allows programs which have been created on Minerva using integer
tokenisation to be loaded into any other ROM without any problems - any
numbers in the program file are automatically converted to floating
point tokens (or long/short integers if integer tokenisation is
enabled), thus preventing any problems.

**NOTE 4**

LOAD cannot be used from within a PROCedure or FuNction unless you have
a JS ROM, MGx ROM, SMS or Minerva v1.83+. On other implementations, this
causes the error 'Not Implemented'.

**NOTE 5**

Except under SMS, line numbers can be added to a numberless program file
using AUTO - please refer to AUTO.

**NOTE 6**

On Minerva v1.86, LOAD could become confused when used inside a program.

**NOTE 7**

Since Toolkit II v2.22 (and on Minerva), LOAD will refuse to try and
load a file unless its file type is 0 (see FTYP).

**NOTE 8**

Any commands which appear on the same line as LOAD (after the LOAD
command) will be ignored.

**SMS NOTES**

LOAD has been re-written so that it will also load files saved with the
QLOAD utility from Liberation Software (which is now part of SMS). If
the specified filename does not end in \_SAV or \_BAS, then if the
specified filename does not exist, before trying the default data device
and the default program device (see above), LOAD will first of all try
the filename with \_BAS appended and if still not found, will try the
filename with \_SAV appended.

So if the default data device is flp1\_
and the default program device is flp2\_, LOAD ram1\_TEST will look for
the following files:

- ram1\_TEST
- ram1\_TEST\_bas
- ram1\_TEST\_sav
- flp1\_ram1\_TEST
- flp1\_ram1\_TEST\_bas
- flp1\_ram1\_TEST\_sav
- flp2\_ram1\_TEST
- flp2\_ram1\_TEST\_bas
- flp2\_ram1\_TEST\_sav

Only if none of these filenames exist will it report a 'Not Found'
error.

**CROSS-REFERENCE**

:ref:`save` saves the current SuperBASIC program in
memory. :ref:`lrun` automatically runs the program
after loading. :ref:`merge` and
:ref:`mrun` are similar commands. Also see
:ref:`qload` and :ref:`reload`.
:ref:`exec` allows you to load a multitasking program
(normally a machine code program or a compiled program).
:ref:`lbytes` allows you to load a section of
memory.

--------------


