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

Compare `AQCONVERT <KeywordsA.clean.html#aqconvert>`__ and
`QICONVERT <KeywordsQ.clean.html#qiconvert>`__. See also
`ACOPY <KeywordsA.clean.html#acopy>`__ and `QCOPY <KeywordsQ.clean.html#qcopy>`__.

--------------

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
three letter extension preceded by a dot eg: QCOPY "flp1\_PROGRAM.BAS",
flp2\_PROGRAM.BAS

**CROSS-REFERENCE**

`ACOPY <KeywordsA.clean.html#acopy>`__ copies a file from a QL disk to an
Atari disk. Level-3 device drivers allow you to read and write to Atari
and IBM format disks anyway. See `AFORMAT and
AQCONVERT <KeywordsA.clean.html#aformat20and20aqconvert>`__.

--------------

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
other control characters. Take the example of: 10 OPEN #3,pipe\_1048 20
PRINT #3,'HELLO' 30 PRINT QCOUNT%(#3)
 The value of 6 is returned, this is because the PRINT
 statement has added a line feed to the end of the word 'HELLO', so that
this can be read by an INPUT command.

**CROSS-REFERENCE**

Refer to `QLINK <KeywordsQ.clean.html#qlink>`__ and also the Device Drivers
Appendix. See also `QSIZE% <KeywordsQ.clean.html#qsize>`__ and
`QSPACE% <KeywordsQ.clean.html#qspace>`__.

--------------

QDOS$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QDOS$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn, TinyToolkit, BTool                                           |
+----------+-------------------------------------------------------------------+

 This function returns a string containing the version code of the
operating system on which SuperBASIC is running. Example values:

QDOS$
~~~~~

Operating System
~~~~~~~~~~~~~~~~

1.03the first main version of QDOS (an upgrade is essential if you have
an earlier version!) 1x13all MGx ROMs, eg. 1G13 for the MGG 1.63the
first version of Minerva 1.76the first version of Minerva with reliable
MultiBASICs 1.98the latest and best version of Minerva 2.xxSMS version
3.xxthe version number of the Amiga QL Emulator 4.xxthe first version of
ARGOS on a THOR 1 computer 5.xxthe version of ARGOS on a THOR 20
computer 6.xxthe version of ARGOS on a THOR XVI computer 6.41the final
version of the THOR ARGOS ROM

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

`VER$ <KeywordsV.clean.html#ver>`__ contains another code identifying the
operating system. `VER$(1) <KeywordsV.clean.html#ver(1)>`__ is identical to
`QDOS$ <KeywordsQ.clean.html#qdos>`__ for Minerva ROMs and SMS. You should
also look at `MACHINE <KeywordsM.clean.html#machine>`__ and
`PROCESSOR <KeywordsP.clean.html#processor>`__.
`LANG\_USE <KeywordsL.clean.html#lang-use>`__ allows you to change the
operating system language.

--------------

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

ninformation
~~~~~~~~~~~~

0width in pixels (eg. 512 on a standard QL display). 1height in pixels
(eg. 256 on a standard QL display). 2leftmost horizontal position
3uppermost vertical position QFLIM needs an open window to get the
information from (default #1). The return values refer to the current
job. If any other values of n are used, a bad parameter error will be
generated.

**Example**

If there are no windows other than #0, #1 and #2, and their positions
are as follows: 100 WINDOW#0,100,100,50,50 110 WINDOW#1,20,20,0,0 120
WINDOW#2,200,50,40,40 130 FOR c=0 TO 2: PAPER#c,3: BORDER#c,1,4: CLS#c
 The Pointer Interface will reduce the outline size of the screen
available to SuperBASIC, which can be checked with the next program or
by swapping to other jobs which fill the whole screen. 100 ch=2 110
xmin=QFLIM(#ch,2): xmax=xmin+ QFLIM(#ch,0) 120 ymin=QFLIM(#ch,3):
ymax=ymin+ QFLIM(#ch,1) 130 PRINT "x = ";xmin;"..";xmax 140 PRINT "y =
";ymin;"..";ymax 150 percent% = 100 \* QFLIM(#ch,0) \* QFLIM(#ch,1) /
(512\*256) 160 PRINT "fills"!percent%;"% of the screen"
 Type WTV or WMON to restore standard window sizes. Note that this
example expects the display to be 512x256 pixels.

**NOTE 1**

The Pointer Interface makes a distinction between the primary window
(generally the first window to be used for input/output operations) and
secondary windows. Although using QFLIM on a secondary window will
return the maximum outlines for the current job's windows, using QFLIM
on the primary window (eg. #0 in SuperBASIC) will return the physical
screen size, ie. the parameters of the largest possible window: WINDOW
QFLIM(#0,0),QFLIM(#0,1),QFLIM(#0,2),QFLIM(#0,3)
 This can therefore be used to check whether or not the extra high
resolution modes provided by some Emulators and the AURORA is available:
exten4=0: IF QFLIM(#0,1)>256:exten4=1

**NOTE 2**

QFLIM returns useless numbers greater than 10000 if the Pointer
Interface is not present.

**CROSS-REFERENCE**

`WMAN$ <KeywordsW.clean.html#wman>`__, `WINF$ <KeywordsW.clean.html#winf>`__ allow
you to find out various information about the Pointer Environment.
`XLIM <KeywordsX.clean.html#xlim>`__, `SCR\_XLIM <KeywordsS.clean.html#scr-xlim>`__,
`YLIM <KeywordsY.clean.html#ylim>`__ and
`SCR\_YLIM <KeywordsS.clean.html#scr-ylim>`__ are similar to
`QFLIM <KeywordsQ.clean.html#qflim>`__. See also
`OUTLN <KeywordsO.clean.html#outln>`__.

--------------

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

Compare `IQCONVERT <KeywordsI.clean.html#iqconvert>`__ and
`AQCONVERT <KeywordsA.clean.html#aqconvert>`__. See also
`ACOPY <KeywordsA.clean.html#acopy>`__ and `QCOPY <KeywordsQ.clean.html#qcopy>`__.
See `IFORMAT <KeywordsI.clean.html#iformat>`__.

--------------

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
`EOFW <KeywordsE.clean.html#eofw>`__, `PEND <KeywordsP.clean.html#pend>`__,
`QSIZE% <KeywordsQ.clean.html#qsize>`__, `QCOUNT% <KeywordsQ.clean.html#qcount>`__
and `QSPACE% <KeywordsQ.clean.html#qspace>`__.

--------------

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

Also see `LOAD <KeywordsL.clean.html#load>`__,
`QLRUN <KeywordsQ.clean.html#qlrun>`__, `QMERGE <KeywordsQ.clean.html#qmerge>`__ and
`QSAVE <KeywordsQ.clean.html#qsave>`__ Compare
`UNLOAD <KeywordsU.clean.html#unload>`__.

--------------

QLRUN
~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  QLRUN [device\_]filename                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

 This command is exactly the same as QLOAD except that the program is
automatically RUN as soon as it has been loaded into memory.

**CROSS-REFERENCE**

See `QLOAD <KeywordsQ.clean.html#qload>`__ and
`QMRUN <KeywordsQ.clean.html#qmrun>`__.

--------------

QL\_PEX
~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  QL\_PEX                                                          |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This function returns the offset of the keyword linkage block of the
keywords added by the PEX toolkit. This offset is needed for
Qliberator's $$asmb directorive.

**CROSS-REFERENCE**

See `PEX\_SAVE. <KeywordsP.clean.html#pex-save.>`__

--------------

QMERGE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QMERGE [device\_]filename                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

 This command bears the same relationship to MERGE as QLOAD
 does to LOAD.

**CROSS-REFERENCE**

Refer to `QLOAD <KeywordsQ.clean.html#qload>`__ and
`MERGE <KeywordsM.clean.html#merge>`__. See also
`QMRUN <KeywordsQ.clean.html#qmrun>`__

--------------

QMRUN
~~~~~

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

See `QMERGE <KeywordsQ.clean.html#qmerge>`__ and
`MRUN <KeywordsM.clean.html#mrun>`__.

--------------

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

`PINF$ <KeywordsP.clean.html#pinf>`__ is exactly the same as
`QRAM$ <KeywordsQ.clean.html#qram>`__. `WMAN$ <KeywordsW.clean.html#wman>`__ and
`WINF$ <KeywordsW.clean.html#winf>`__ contain the version number of the
Window Manager.

--------------

QSAVE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QSAVE [device\_]filename  or QSAVE                               |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

 For several years now, the best utility for saving SuperBASIC programs
in a form which can be loaded very quickly into memory has been QLOAD
from Liberation Software. This utility stores SuperBASIC programs on
disk in a special format which although seems meaningless if you VIEW
the file, allows the program to be loaded at around 3x the speed of the
normal LOAD command, which can be very useful for large programs. Unlike
other similar utilities, programs which have been saved using this
utility can be loaded into any other ROM version without any trouble,
using the QLOAD command. It is nice to see that this utility has been
implemented as part of SMS. The QSAVE command allows you to save the
whole of SuperBASIC program currently in memory under the specified
filename to the specified device. If the filename does not end in the
suffix \_SAV, then this will be added automatically. If no device is
specified (or it does not exist), then Toolkit II's default data device
will be used. You will also be prompted to confirm whether an existing
file should be overwritten if necessary. The second variant of the
command will allow you to QSAVE
 the program in memory under the same filename as when LOAD or QLOAD was
last used (with the \_SAV suffix appended if necessary). If the original
filename used when the program was LOADed ended in \_BAS, then QSAVE
will alter this to be the \_SAV suffix. This variant will also take the
version number of the file when it was LOADed (or QLOADed) and then
increase this by one.

**NOTE 1**

To ensure that QSAVEd programs can be used on all implementations of the
QL, ensure that if used from Minerva, Integer Tokenisation is switched
off - you will need to follow the following procedure: (1) POKE
\\\\212,128
 (2) LOAD ASCII version of the program (or type NEW) (3) Alter program
as necessary (4) QSAVE the fast loading version of the program

**NOTE 2**

QSAVE without a filename suffers the same problems as SAVE.

**CROSS-REFERENCE**

See `SAVE <KeywordsS.clean.html#save>`__, `QLRUN <KeywordsQ.clean.html#qlrun>`__ and
`QMERGE <KeywordsQ.clean.html#qmerge>`__. `DATAD$ <KeywordsD.clean.html#datad>`__
allows you to read the current default data device. See also
`QSAVE\_O <KeywordsQ.clean.html#qsave-o>`__. `FVERS <KeywordsF.clean.html#fvers>`__
allows you to read the current version number of a file.

--------------

QSAVE\_O
~~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  QSAVE\_O [device\_]filename  or QSAVE\_O                         |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

 This command is the same as QSAVE except that it will automatically
overwrite an existing file with the same filename.

**NOTE**

On Minerva machines you need to be careful about Integer Tokenisation -
see QSAVE.

**CROSS-REFERENCE**

See `QSAVE <KeywordsQ.clean.html#qsave>`__.

--------------

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

10 OPEN #4,pipe\_200 20 QLINK #4 TO #3 25 PRINT #4,'QL DATA' 30 PRINT
QSIZE% (#3), QCOUNT%(#3) 40 CLOSE #3:CLOSE #4
 This short program will print the figures 203 and 8 on screen. This
will also work with named pipes on SMS: 10 OPEN\_NEW #4,pipe\_test\_200
20 OPEN\_IN #3,pipe\_test 25 PRINT #4,'QL DATA' 30 PRINT QSIZE% (#3),
QCOUNT%(#3) 40 CLOSE #3:CLOSE #4
 Note however, that if you re-run the program the figure returned by
QCOUNT% continues increasing - this is because a named pipe does not
disappear just because both ends of the pipe have been closed. You would
need to add the line: 50 DELETE pipe\_test
 to overcome this, or try: DIR pipe: WDEL pipe

**NOTE**

A pipe can normally hold a few extra characters that the size originally
given to the pipe (in the example 203 is returned on most
implementations rather than 200 as might be expected). This does not
cause a problem.

**CROSS-REFERENCE**

Refer to `QLINK <KeywordsQ.clean.html#qlink>`__ and also the Device Drivers
Appendix. See also `QCOUNT% <KeywordsQ.clean.html#qcount>`__ and
`QSPACE% <KeywordsQ.clean.html#qspace>`__.

--------------

QSPACE%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QSPACE% (#pipe\_ch)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

 This function returns the amount of empty space in a pipe connected to
the specified channel. PRINT QSPACE(#3)
 is therefore the same as: PRINT QSIZE%(#3)-QCOUNT%(#3)

**CROSS-REFERENCE**

Refer to `QCOUNT% <KeywordsQ.clean.html#qcount>`__ and
`QSIZE% <KeywordsQ.clean.html#qsize>`__.

--------------

QTRAP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QTRAP #ch,key [,d1 [,d2 [,d3 [,a1 [,a2 ]]]]]                     |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS                                                            |
+----------+-------------------------------------------------------------------+

(DIY Toolkit Vol T)
 This command is similar to IO\_TRAP in that it allows you to access the
machine code TRAP #3 system calls directly. You will need to pass at
least two parameters, the number of the channel to be affected and the
operation key to be carried out (this is equivalent to the value in D0
when TRAP #3 is performed). The other parameters allow you to pass the
various register values which may be required by the system calls. The
timeout parameter (D3) defaults to -1 (infinite timeout). This can be
used effectively to set the INK and PAPER colours for THOR XVI's MODE 12
and still allow the program to be compiled. For example: QTRAP
#2,HEX('27'),4
 will set the PAPER colour in the window #2 to Green (although the STRIP
colour will remain unaffected).

**WARNING**

Several TRAP #3 calls can crash the computer - make certain that you
know what you are doing!

**CROSS-REFERENCE**

See `IO\_TRAP <KeywordsI.clean.html#io-trap>`__,
`TTET3 <KeywordsT.clean.html#ttet3>`__, `MTRAP <KeywordsM.clean.html#mtrap>`__ and
`BTRAP <KeywordsB.clean.html#btrap>`__. Any return parameters can be read with
`DATAREG <KeywordsD.clean.html#datareg>`__ and
`ADDREG <KeywordsA.clean.html#addreg>`__. `CLS <KeywordsC.clean.html#cls>`__,
`PAN <KeywordsP.clean.html#pan>`__ and `SCROLL <KeywordsS.clean.html#scroll>`__ can
also be used to call TRAP #3. Refer to the QDOS/SMS Reference Manual
(Section 15) for details of the various system TRAP #3 calls.

--------------

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

Also see `QDOS$ <KeywordsQ.clean.html#qdos>`__,
`ATARI <KeywordsA.clean.html#atari>`__, `VER$ <KeywordsV.clean.html#ver>`__,
`QRAM$ <KeywordsQ.clean.html#qram>`__, `WMAN$ <KeywordsW.clean.html#wman>`__,
`P\_ENV <KeywordsP.clean.html#p-env>`__. `MACHINE <KeywordsM.clean.html#machine>`__
is much more reliable.

--------------

QUEUE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QUEUE% (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  QBASE (DIY Toolkit Vol Q)                                        |
+----------+-------------------------------------------------------------------+

 QUEUE% is a function but does exactly the same as FORCE\_TYPE and
TYPE\_IN. The return value is zero if all bytes have been successfully
typed in, negative if the keyboard queue is full and positive if another
problem occured. The absolute value of the return always indicates how
many characters QUEUE% failed to send.

--------------

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

See `MB <KeywordsM.clean.html#mb>`__ and `SBASIC <KeywordsS.clean.html#sbasic>`__.
`CLOSE #0 <KeywordsC.clean.html#close20#0>`__ has the same effect from within
a Multiple SBASIC or MultiBASIC Interpreter
