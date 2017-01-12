
==========
Keywords Q
==========

TODO
====




..  _qaconvert:

QACONVERT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  QACONVERT filename                                               |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command takes a file which is stored on a QL Format disk and
converts it into Atari Format. It will then convert special characters
in that file to Atari compatible characters as well as converting any
occurence of a Line Feed character CHR$(10) to a Carriage Return
character CHR$(13) followed by a Line Feed character CHR$(10).

**CROSS-REFERENCE**

Compare :ref:`aqconvert` and
:ref:`qiconvert`. See also
:ref:`acopy` and :ref:`qcopy`.

--------------


..  _qcopy:

QCOPY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QCOPY filename1,filename2                                        |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command is similar to COPY except that it copies a file from an
Atari Format disk to a QL Format disk. No conversion takes place.

**NOTE**

You will need to pass the Atari filename in quote marks if it includes a
three letter extension preceded by a dot eg::

    QCOPY "flp1_PROGRAM.BAS", flp2_PROGRAM.BAS

**CROSS-REFERENCE**

:ref:`acopy` copies a file from a QL disk to an
Atari disk. Level-3 device drivers allow you to read and write to Atari
and IBM format disks anyway. See :ref:`aformat` and
:ref:`aqconvert`.

--------------


..  _qcount-pct:

QCOUNT%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QCOUNT% (#pipe\_ch)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This function is designed to make the use of pipes easier. Provided
that the specified channel is linked to a pipe (normally the input end
of the pipe), this function will return the number of characters which
are waiting to be read from the pipe.

**NOTE**

The value returned will be the exact number of characters placed into
the pipe, which will therefore include the line feed characters and
other control characters. Take the example of::

    10 OPEN #3,pipe_1048 
    20 PRINT #3,'HELLO' 
    30 PRINT QCOUNT%(#3)

The value of 6 is returned, this is because the PRINT
statement has added a line feed to the end of the word 'HELLO', so that
this can be read by an INPUT command.

**CROSS-REFERENCE**

Refer to :ref:`qlink` and also the Device Drivers
Appendix. See also :ref:`qsize-pct` and
:ref:`qspace-pct`.

--------------


..  _qdos-dlr:

QDOS$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QDOS$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn, TinyToolkit, BTool                                           |
+----------+-------------------------------------------------------------------+

This function returns a string containing the version code of the
operating system on which SuperBASIC is running. For example ::

    PRINT QDOS$
    
- Version 1.03 was the first main version of QDOS (an upgrade is essential if you have an earlier version!) 
- Version 1x13 is for all MGx ROMs, eg. 1G13 for the MGG. 
- 1.63 was the first version of Minerva. 
- 1.76 was the first version of Minerva with reliable MultiBASICs.
- 1.98 was the latest and best version of Minerva 
- 2.xx SMS version.
- 3.xx is the version number of the Amiga QL Emulator. 
- 4.xx is the first version of ARGOS on a THOR 1 computer. #
- 5.xx is the version of ARGOS on a THOR 20 computer. 
- 6.xx is the version of ARGOS on a THOR XVI computer. 
- 6.41 is the final version of the THOR ARGOS ROM.

**NOTE 1**

VER$ is normally used to identify the version of the SuperBASIC
interpreter and QDOS$ to identify the version of QDOS (the operating
system). However, as SuperBASIC is an integral part of the operating
system on most QDOS computers, there should really only be a need to use
one of these functions and not both.

**NOTE 2**

The '.' in QDOS$ is changed on MG and SMS v2.50+ (on Gold Cards and
Super Gold Cards only) to reflect the country code of the language
version currently loaded.

**CROSS-REFERENCE**

:ref:`ver-dlr` contains another code identifying the
operating system. :ref:`ver-dlr`\ (1) is identical to
:ref:`qdos-dlr` for Minerva ROMs and SMS. You should
also look at :ref:`machine` and
:ref:`processor`.
:ref:`lang-use` allows you to change the
operating system language.

--------------


..  _qflim:

QFLIM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QFLIM ([#channel,] n) n=0..3                                     |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

With the Pointer Interface present, each job has a maximum outline
window size in which it can open its windows to avoid storing more
information than necessary when switching between jobs and saving the
window contents. The function QFLIM returns the following information
about this maximum outline size, in the (window independent) absolute
co-ordinate system for the different n:

+---+------------------------------------------------------+
| N | Information Returned                                 |
+===+======================================================+
| 0 | Width in pixels (eg. 512 on a standard QL display).  | 
+---+------------------------------------------------------+
| 1 | Height in pixels (eg. 256 on a standard QL display). |
+---+------------------------------------------------------+
| 2 | Leftmost horizontal position.                        |
+---+------------------------------------------------------+
| 3 | Uppermost vertical position.                         |
+---+------------------------------------------------------+

QFLIM needs an open window to get the
information from (default #1). The return values refer to the current
job. If any other values of n are used, a bad parameter error will be
generated.

**Example**

If there are no windows other than #0, #1 and #2, and their positions
are set up as follows:: 

    100 WINDOW #0,100,100,50,50 
    110 WINDOW #1,20,20,0,0 
    120 WINDOW #2,200,50,40,40 
    130 FOR c=0 TO 2: PAPER #c,3: BORDER #c,1,4: CLS #c

The Pointer Interface will reduce the outline size of the screen
available to SuperBASIC, which can be checked with the next program or
by swapping to other jobs which fill the whole screen. 

::

    100 ch=2 
    110 xmin = QFLIM(#ch, 2): xmax = xmin + QFLIM(#ch,0) 
    120 ymin = QFLIM(#ch, 3): ymax = ymin + QFLIM(#ch,1) 
    130 PRINT "x = "; xmin; ".."; xmax 
    140 PRINT "y = "; ymin; ".."; ymax 
    150 percent% = 100 * QFLIM(#ch, 0) * QFLIM(#ch, 1) / (512 * 256) 
    160 PRINT "fills"! percent%; "% of the screen" 


Type WTV or WMON to restore standard window sizes. Note that this
example expects the display to be 512x256 pixels.

**NOTE 1**

The Pointer Interface makes a distinction between the primary window
(generally the first window to be used for input/output operations) and
secondary windows. Although using QFLIM on a secondary window will
return the maximum outlines for the current job's windows, using QFLIM
on the primary window (eg. #0 in SuperBASIC) will return the physical
screen size, ie. the parameters of the largest possible window:: 

    WINDOW QFLIM(#0, 0), QFLIM(#0, 1), QFLIM(#0, 2), QFLIM(#0, 3)

This can therefore be used to check whether or not the extra high
resolution modes provided by some Emulators and the AURORA is available::

    exten4 = 0
    IF QFLIM(#0,1) > 256: exten4 = 1

**NOTE 2**

QFLIM returns useless numbers greater than 10000 if the Pointer
Interface is not present.

**CROSS-REFERENCE**

:ref:`wman-dlr`, :ref:`winf-dlr` allow
you to find out various information about the Pointer Environment.
:ref:`xlim`, :ref:`scr-xlim`,
:ref:`ylim` and
:ref:`scr-ylim` are similar to
:ref:`qflim`. See also
:ref:`outln`.

--------------


..  _qiconvert:

QICONVERT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  QICONVERT filename                                               |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command takes a file which is stored on a QL Format disk and
converts it into IBM Format. It will then convert special characters in
that file to IBM compatible characters as well as converting any
occurence of a Line Feed character CHR$(10) to a Carriage Return
character CHR$(13) followed by a Line Feed character CHR$(10).

**CROSS-REFERENCE**

Compare :ref:`iqconvert` and
:ref:`aqconvert`. See also
:ref:`acopy` and :ref:`qcopy`.
See :ref:`iformat`.

--------------


..  _qlink:

QLINK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QLINK #output TO #input                                          |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This command is the same as TCONNECT.

**CROSS-REFERENCE**

The following functions are also useful when accessing pipes:
:ref:`eofw`, :ref:`pend`,
:ref:`qsize-pct`, :ref:`qcount-pct`
and :ref:`qspace-pct`.

--------------


..  _qload:

QLOAD
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QLOAD [device\_]filename                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is very similar to LOAD as implemented on the SMS. The
only difference are that it insists that the program must have been
saved with the \_sav suffix (eg. flp1\_TEST\_sav). QLOAD will then
proceed to load the BASIC program whether it was saved with the normal
SAVE or SAVE\_O commands, or with the QSAVE or QSAVE\_O commands.

**NOTE 1**

If a program has been saved using QSAVE on a Minerva machine with
Integer Tokenisation enabled, then QLOAD will not be able to understand
it properly and you will notice that numbers and keywords have been
replaced by various symbols.

**NOTE 2**

Any commands which appear after a QLOAD command will be ignored.

**CROSS-REFERENCE**

Also see :ref:`load`,
:ref:`qlrun`, :ref:`qmerge` and
:ref:`qsave` Compare
:ref:`unload`.

--------------


..  _qlrun:

QLRUN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QLRUN [device\_]filename                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is exactly the same as QLOAD except that the program is
automatically RUN as soon as it has been loaded into memory.

**CROSS-REFERENCE**

See :ref:`qload` and
:ref:`qmrun`.

--------------


..  _ql-pex:

QL\_PEX
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QL\_PEX                                                          |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This function returns the offset of the keyword linkage block of the
keywords added by the PEX toolkit. This offset is needed for
Qliberator's $$asmb directorive.

**CROSS-REFERENCE**

See :ref:`pex-save`\ .

--------------


..  _qmerge:

QMERGE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QMERGE [device\_]filename                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command bears the same relationship to MERGE as QLOAD does to LOAD.

**CROSS-REFERENCE**

Refer to :ref:`qload` and
:ref:`merge`. See also
:ref:`qmrun`

--------------


..  _qmrun:

QMRUN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QMRUN [device\_]filename                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is exactly the same as QMERGE except that it ensures that
the program is RUN as soon as it has been merged into memory. If the
command is issued from the command line as a direct command, then the
merged program is RUN from line 1. If, however, QMRUN appears in the
program itself, the program continues from the statement following QMRUN
(making it the same as QMERGE).

**CROSS-REFERENCE**

See :ref:`qmerge` and
:ref:`mrun`.

--------------


..  _qpc-cmdline-dlr:

QPC\_CMDLINE$
=============

+----------+-------------------------------------------------------------------+
| Syntax   | cmd$ = QPC\_CMDLINE$                                              |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This returns the argument that was supplied to QPC after the "-cmdline" command line argument. This can be used to do different actions depending on the way QPC was started.

--------------


..  _qpc-exec:

QPC\_EXEC
=========

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_EXEC command$[, parameter$]                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This command can be used to call an external DOS or Windows program. The name of the executable file is given in the first parameter. Optionally, you can also supply a second parameter, which is then passed to the executed program as its command line arguments.

Furthermore, you can supply a data file as the first parameter. In this case, the associated application for this file type is executed.

**Example** 

::

    QPC_EXEC 'notepad','c:\text.txt' 
    
Starts notepad and loads the c:\\text file.

::

    QPC_EXEC 'c:\text.txt' 
    
Starts the default viewer for .txt files.

--------------


..  _qpc-exit:

QPC\_EXIT
=========

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_EXIT                                                         |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This simply quits QPC.

--------------


..  _qpc-hostos:

QPC\_HOSTOS
===========

+----------+-------------------------------------------------------------------+
| Syntax   | os% = QPC\_HOSTOS                                                 |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This function returns the host operating system under which QPC was started. 

Possible return codes are:

- 0 = DOS (QPC1) 
- 1 = Win9x/ME (QPC2) 
- 2 = WinNT/2000/XP (QPC2)

--------------


..  _qpc-maximize:

QPC\_MAXIMIZE
=============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_MAXIMIZE                                                     |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Maximises the QPC window. (Yes, the spelling of the command name is American!)

--------------


..  _qpc-minimize:

QPC\_MINIMIZE
=============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_MINIMIZE                                                     |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Minimizes the QPC window. (Yes, the spelling of the command name is American!)

--------------


..  _qpc-mspeed:

QPC\_MSPEED
===========

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_MSPEED x\_accel, y\_accel                                    |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This command has no effect on QPC2.

--------------


..  _qpc-netname-dlr:

QPC\_NETNAME$
=============

+----------+-------------------------------------------------------------------+
| Syntax   | name$ = QPC\_NETNAME$                                             |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This function returns the current network name of your PC (the one you supplied upon installation of Windows). The result can be used to distinguish between different PCs (**Example** in a BOOT program).

--------------


..  _qpc-qlscremu:

QPC\_QLSCREMU
=============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_QLSCREMU value                                               |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Enables or disables the original QL screen emulation. When emulating the original screen, all memory write accesses to the area $20000-$207FFF are intercepted and translated into writes to the first 512x256 pixels of the big screen area. If the screen is in high colour mode, additional colour conversion is done.

Possible values are:

- -1: automatic mode 
- 0: disabled (default) 
- 4: force to 4-colour mode 
- 8: force to 8-colour mode

When in QL colour mode, the emulation just transfers the written bytes to the larger screen memory, i.e. when the big mode is in 4-colour mode, the original screen area is also treated as 4-colour mode. In high colour mode however, the colour conversion can do both modes. In this case, you can pre-select the emulated mode (parameter = 4 or 8) or let the last issued :ref:`mode` call decide (automatic mode). Please note that that automatic mode does not work on a per-job basis, so any job that issues a :ref:`mode` command changes the behaviour globally.

Please also note that this transition is one-way only, i.e. bytes written legally to the first 512x256 pixels are not transferred back to the original QL screen (in the case of a high colour screens this would hardly be possible anyway). Unfortunately, this also means that not all old programs will run perfectly with this type of emulation. If you experience problems, start the misbehaving application in 512x256 mode.

--------------


..  _qpc-restore:

QPC\_RESTORE
============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_RESTORE                                                      |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Restores the QPC window. This will return the window size from minimised or maximised to what it was before.

--------------


..  _qpc-syncscrap:

QPC\_SYNCSCRAP
==============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_SYNCSCRAP                                                    |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

In order to rapidly exchange text passages between Windows and SMSQ/E the Syncscrap functionality has been introduced. The equivalent of the Windows clipboard is the scrap extension of the menu extensions.

After loading the menu extensions you can call this command, which creates a job that periodically checks for changes in either the scrap or the Windows clipboard, and synchronizes their contents if necessary. Please note that only text data is supported. The character conversion between the QL character set and the Windows ANSI set is done automatically. The line terminators (LF or LF+CR) are converted too.

--------------


..  _qpc-ver-dlr:

QPC\_VER$
=========

+----------+-------------------------------------------------------------------+
| Syntax   | v$ = QPC\_VER$                                                    |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This returns the current QPC version.

**Example** 

::

    PRINT QPC_VER$ 
    
Will print 4.00 or higher.

--------------


..  _qpc-windowsize:

QPC\_WINDOWSIZE
===============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_WINDOWSIZE x, y                                              |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This sets the size of the client area (the part that displays SMSQ/E) of the QPC window. It does NOT alter the resolution SMSQ/E runs with, so the pixels are effectively zoomed. It is equivalent to the "window size" option in the main configuration window. If QPC is currently in full screen mode it will switch to windowed mode. Window size cannot be set smaller than the SMSQ/E resolution or bigger than the desktop resolution.

**Example** 

::

    DISP_SIZE 512,256
    QPC_WINDOWSIZE 1024,512
    
Does a 200% zoom of the QPC window.

--------------


..  _qpc-windowtitle:

QPC\_WINDOWTITLE
================

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_WINDOWTITLE title$                                           |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Sets the string that can be seen when QPC runs in windowed mode. This can be used to easily distin-guish between several QPC instances.

**Example** 

::

    QPC_WINDOWTITLE "Accounting" 

Sets the title to "Accounting", without the quotes though!

--------------


..  _qptr:

QPTR
====

+----------+-------------------------------------------------------------------+
| Syntax   | PE_Found = QPTR(#channel)                                         |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns 1 if the Pointer Environment is loaded or 0 if not. The channel must be a SCR\_ or CON\_ channel, if not, the result will be 0. If a silly value is given then a QDOS error code will be returned instead.


**EXAMPLE**

::

    PRINT QPTR(#0)
    
will print 1 of the PE is loaded or zero otherwise.


-------


..  _qram-dlr:

QRAM$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QRAM$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This function returns a string containing the version number of the
Pointer Environment, or an empty string if this is not present.

**CROSS-REFERENCE**

:ref:`pinf-dlr` is exactly the same as
:ref:`qram-dlr`. :ref:`wman-dlr` and
:ref:`winf-dlr` contain the version number of the
Window Manager.

--------------


..  _qsave:

QSAVE
=====

+----------+-------------------------------------------------------------------+
| Syntax   || QSAVE [device\_]filename  or                                     |
|          || QSAVE                                                            |
+----------+-------------------------------------------------------------------+
| Location || SMS                                                              |
+----------+-------------------------------------------------------------------+

For several years now, the best utility for saving SuperBASIC programs
in a form which can be loaded very quickly into memory has been QLOAD
from Liberation Software. 

This utility stores SuperBASIC programs on
disk in a special format which although seems meaningless if you VIEW
the file, allows the program to be loaded at around 3x the speed of the
normal LOAD command, which can be very useful for large programs. 

Unlike other similar utilities, programs which have been saved using this
utility can be loaded into any other ROM version without any trouble,
using the QLOAD command. It is nice to see that this utility has been
implemented as part of SMS. 

The QSAVE command allows you to save the
whole of SuperBASIC program currently in memory under the specified
filename to the specified device. If the filename does not end in the
suffix \_SAV, then this will be added automatically. 

If no device is
specified (or it does not exist), then Toolkit II's default data device
will be used. You will also be prompted to confirm whether an existing
file should be overwritten if necessary. 

The second variant of the
command will allow you to QSAVE
the program in memory under the same filename as when LOAD or QLOAD was
last used (with the \_SAV suffix appended if necessary). 

If the original
filename used when the program was LOADed ended in \_BAS, then QSAVE
will alter this to be the \_SAV suffix. 

This variant will also take the
version number of the file when it was LOADed (or QLOADed) and then
increase this by one.

**NOTE 1**

To ensure that QSAVEd programs can be used on all implementations of the
QL, ensure that if used from Minerva, Integer Tokenisation is switched
off - you will need to follow the following procedure:

#. POKE \\\\212,128
#. LOAD the ASCII version of the program (or type NEW) 
#. Alter the program as necessary ... 
#. QSAVE the fast loading version of the program.

**NOTE 2**

QSAVE without a filename suffers the same problems as SAVE.

**CROSS-REFERENCE**

See :ref:`save`, :ref:`qlrun` and
:ref:`qmerge`. :ref:`datad-dlr`
allows you to read the current default data device. See also
:ref:`qsave-o`. :ref:`fvers`
allows you to read the current version number of a file.

--------------


..  _qsave-o:

QSAVE\_O
========

+----------+-------------------------------------------------------------------+
| Syntax   || QSAVE\_O [device\_]filename  or                                  |
|          || QSAVE\_O                                                         |
+----------+-------------------------------------------------------------------+
| Location || SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is the same as QSAVE except that it will automatically
overwrite an existing file with the same filename.

**NOTE**

On Minerva machines you need to be careful about Integer Tokenisation -
see QSAVE.

**CROSS-REFERENCE**

See :ref:`qsave`.

--------------


..  _qsize-pct:

QSIZE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QSIZE% (#pipe\_ch)                                               |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This function is designed to read the amount of characters which a pipe
linked to the specified channel can hold at any one time.

**Example**

::

    10 OPEN #4,pipe_200 
    20 QLINK #4 TO #3 
    25 PRINT #4,'QL DATA' 
    30 PRINT QSIZE% (#3), QCOUNT%(#3) 
    40 CLOSE #3: CLOSE #4 

This short program will print 203 and 8 on screen. 

This will also work with named pipes on SMS:: 

    10 OPEN_NEW #4,pipe_test_200 
    20 OPEN_IN #3,pipe_test 
    25 PRINT #4,'QL DATA' 
    30 PRINT QSIZE% (#3), QCOUNT%(#3) 
    40 CLOSE #3:CLOSE #4

Note however, that if you re-run the program the figure returned by
QCOUNT% continues increasing - this is because a named pipe does not
disappear just because both ends of the pipe have been closed. You would
need to add the line:: 

    50 DELETE pipe_test

to overcome this. Alternatively, try:: 

    DIR pipe: WDEL pipe

**NOTE**

A pipe can normally hold a few extra characters that the size originally
given to the pipe (in the example 203 is returned on most
implementations rather than 200 as might be expected). This does not
cause a problem.

**CROSS-REFERENCE**

Refer to :ref:`qlink` and also the Device Drivers
Appendix. See also :ref:`qcount-pct` and
:ref:`qspace-pct`.

--------------


..  _qspace-pct:

QSPACE%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QSPACE% (#pipe\_ch)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This function returns the amount of empty space in a pipe connected to
the specified channel. 

::

    PRINT QSPACE(#3)
    
is therefore the same as::

    PRINT QSIZE%(#3) - QCOUNT%(#3)

**CROSS-REFERENCE**

Refer to :ref:`qcount-pct` and
:ref:`qsize-pct`.

--------------


..  _qtrap:

QTRAP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QTRAP #ch,key [,d1 [,d2 [,d3 [,a1 [,a2 ]]]]]                     |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This command is similar to IO\_TRAP in that it allows you to access the
machine code TRAP #3 system calls directly. 

You will need to pass at
least two parameters, the number of the channel to be affected and the
operation key to be carried out (this is equivalent to the value in D0
when TRAP #3 is performed). 

The other parameters allow you to pass the
various register values which may be required by the system calls. The
timeout parameter (D3) defaults to -1 (infinite timeout). 

This can be
used effectively to set the INK and PAPER colours for THOR XVI's MODE 12
and still allow the program to be compiled. For example::

    QTRAP #2,HEX('27'),4
    
will set the PAPER colour in the window #2 to Green (although the STRIP
colour will remain unaffected).

**WARNING**

Several TRAP #3 calls can crash the computer - make certain that you
know what you are doing!

**CROSS-REFERENCE**

See :ref:`io-trap`,
:ref:`ttet3`, :ref:`mtrap` and
:ref:`btrap`. Any return parameters can be read with
:ref:`datareg` and
:ref:`addreg`. :ref:`cls`,
:ref:`pan` and :ref:`scroll` can
also be used to call TRAP #3. Refer to the QDOS/SMS Reference Manual
(Section 15) for details of the various system TRAP #3 calls.

--------------


..  _quatari:

QuATARI
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QuATARI                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools, FN                                                   |
+----------+-------------------------------------------------------------------+

This is a logical function which returns either 1 (true) or 0 (false)
depending on whether or not the command was executed on an Atari
QL-Emulator. Unfortunately, there are some additional keywords only
available on the Emulator, so a portable program which uses these has to
check which system it is running on first.

**NOTE**

This function does not always work!

**CROSS-REFERENCE**

Also see :ref:`qdos-dlr`,
:ref:`atari`, :ref:`ver-dlr`,
:ref:`qram-dlr`, :ref:`wman-dlr`,
:ref:`p-env`. :ref:`machine`
is much more reliable.

--------------


..  _queue-pct:

QUEUE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QUEUE% (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  QBASE (DIY Toolkit Vol Q)                                        |
+----------+-------------------------------------------------------------------+

QUEUE% is a function but does exactly the same as FORCE\_TYPE and
TYPE\_IN. 

The return value is zero if all bytes have been successfully
typed in, negative if the keyboard queue is full and positive if another
problem occured. 

The absolute value of the return always indicates how
many characters QUEUE% failed to send.

--------------


..  _quit:

QUIT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  QUIT                                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is used to force remove a Multiple SBASIC Interpreter or a
compiled Job (in the latter case it is the same as STOP).

**NOTE**

If this command is used from SuperBASIC Job 0, it will return an
'Incomplete' error.

**CROSS-REFERENCE**

See :ref:`mb` and :ref:`sbasic`.
:ref:`close` #0 has the same effect from within
a Multiple SBASIC or MultiBASIC Interpreter

