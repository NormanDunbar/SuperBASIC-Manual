..  _a2-smsqe:

A2 SMSQ/E
=========

(Versions 2.78 - 2.95 tested.)

A2.1 Introduction
-----------------

SMSQ/E is a brand new operating system written by Tony Tebby which has
been designed for the QL and emulators. It is currently available for
standard QLs, AURORA, QPC (a PC emulator), ST/QL emulators, QXL and
QXL2, the Q40 qnd Q60 computers and also the ATARI ST, STE and TT range
of computers.

You must take care not to confuse this operating system with some of the
earlier forms which have been released, namely SMS2 (a plug in add-on
for Ataris) and SMSQ (supplied with the QXL and QXL2 boards) - see the
Emulators Appendix for further details.

SMSQ/E is a complete re-write of the original operating system avoiding
any copyright problems. However, to run on the original QL, SMSQ/E still
requires that a QL operating system (eg. JM or JS) is installed on the
chips inside the QL plus a disk drive and a Gold Card (at the minimum).
This is because SMSQ/E is disk based, rather than being supplied on ROM
chips - you therefore need a means of starting up the QL and loading
SMSQ/E from disk. This does not apply to the QXL, QPC and Atari versions
which have to load their operating systems from disk anyway.

If you are using SMSQ/E on the Gold Card or Super Gold Card, you should
normally use the LRESPR command to start up the copy of SMSQ/E - if this
is used in a boot program, if SMSQ/E is already loaded when the LRESPR
command to load SMSQ/E is read, then it is ignored. If you use RESPR and
LBYTES, then the boot would get into a loop - continually loading the
operating system (unless you check VER$='HBA', although this will not
work on QXL as SMSQ also reports VER$='HBA').

SMSQ/E also incorporates all of the features of the following (which are
available as add on packages to the original QL operating system):

-  Toolkit 2
-  Pointer Interface
-  Qjump's Window Manager
-  Hotkey System II
-  DEV device driver
-  QLOAD / QSAVE from Liberation Software
-  OUTLN command.

As an added bonus, Gold Card and Super Gold Card users (including AURORA
users) also get the Serial Mouse Driver from Albin Hessler Software
which can be loaded into SMSQ/E and allows you to use a mouse plugged
into the serial port.

QXL, QPC, Q40/Q60 and Atari users are able to use the mice supplied for
their computers (provided that you load in a driver for that computer,
eg. the DOS Mouse Driver for IBM Compatible PCs).

SMSQ/E also offers other in-built features:

-  Named pipes and a history device
-  Improved serial and parallel device drivers
-  Level-3 device drivers which allow you to access disks from IBM
   compatible PCs and Ataris.
-  Hi-resolution displays and enhanced colours - refer to Appendix 16

SMSQ/E also includes the SBAS/QD F10 Thing, which allows you to
automatically run SuperBASIC programs which are being edited under the
QD Editor by pressing F10 (this initiates a Multiple SBASIC which then
LRUN's the program). The FileInfo II Thing is also included which allows
SuperBASIC programs with filenames ending in \_BAS or \_SAV to be
Executed directly from the Qpac II Files Menu.

Unfortunately, due to the new coding, there are bound to be one or two
slightly grey areas where compatibility must meet with compromise.

From the SuperBASIC point of view, there are no real problems with using
programs written for earlier operating systems (possibly excluding FB
Roms which insisted on using AT y,x instead of AT x,y), and SMSQ/E
merely enhances this superb programming language to provide the
SuperBASIC programmer with the most flexible and quickest
implementations of BASIC ever devised (it is nearly as quick as
SuperBASIC compiled with Qliberator).

Some of the enhancements made by SMSQ/E are not available on other
operating systems and it is likely that in the future SMSQ/E is the only
operating system which will continue to be upgraded. With free upgrades
at present there is no reason why you should be using anything but the
latest version!

The idea of this section is therefore just to point out some of the
possible pitfalls with which programmers will be faced when writing
SuperBASIC which is specifically designed to run on SMSQ/E and possibly
also on earlier operating systems.

**WARNING:**

Some versions of SMSQ/E appear to have been released in a hurry and are
unreliable - most notably, v2.93 and v2.95 which should be avoided.

A2.2 The EOF Function
---------------------

On early versions of SMSQ/E (pre v2.55) EOF was implemented differently
to the original SuperBASIC version, in that it would wait until either
data or an end of file code was received from the associated channel.
The original would return 1 if no data was waiting in the queue. This
version of EOF has now been renamed EOFW.

A2.3 Empty Brackets
-------------------

| An empty bracket is always regarded as a syntax error by original QL
  ROMs whereas SMSQ/E (in common with Minerva) tolerates them, for
  example to indicate that a function is called with a parameter, eg.
  DATE(). If a program should be portable than you have to avoid this
  style because all other implementations (other than Minerva) mark such
  lines with a MISTake:

::

    100 MISTake PRINT DATE()

Since DATE() and VER$() are effectively the same as DATE and VER$, it is
recommended to use the latter syntax.

A2.4 Multiple Sbasics
---------------------

SMSQ/E (in common with Minerva) allows you to have several BASIC
interpreters which can all multitask. Essentially, you retain the
original SuperBASIC interpreter together with several copies of that
interpreter, each of which is known as a SBASIC.

A SBASIC will in fact operate in the same way as SuperBASIC, and you can
link different toolkits with each copy of the interpreter, knowing that
they will not be available to the other existing interpreters.

The only problem is that many toolkits have been written with only the
original SuperBASIC interpreter in mind, and some commands are therefore
unable to access the SBASIC's variables. Fortunately, the majority of
commands and functions do in fact still work with SBASICs, unless used
from within a compiled program.

See Appendix 1 for more details of Multiple BASICs.

A2.5 Improved Interpreter
-------------------------

Unlike the original SuperBASIC, SMSQ/E will look at a program to ensure
that all of the structures are validly constructed before it allows you
to SAVE or RUN the program. Although this can pick up common programming
mistakes (such as forgetting to add END FOR or END DEFine), this can
mean that some SuperBASIC programs will now refuse to RUN, reporting an
Incomplete Definition. This is especially problematic as SMSQ/E (prior
to v2.89) will not allow a single-line PROCedure or FuNction to exist
without END DEFine appearing on the line.

Further checks are carried out before a program is RUN or SAVEd and a
wide range of error messages have been added to the Interpreter, which
may be reported. These error messages are listed in the Errors Appendix.

A2.6 Numbers in Programs
------------------------

SMSQ/E has extended SuperBASIC by allowing programs to contain both
hexadecimal and binary numbers explicitly in the code, such as a=%10 (or
a=$02) is the same as a=2. These constructs will result in a MIStake
being shown on other implementations (refer to the Mathematics
Appendix).

Programs which use this feature can only be compiled using Turbo v4.3 or
later.

A2.7 Inbuilt Pointer Environment
---------------------------------

SMSQ/E incorporates the Pointer Environment (the files ptr\_gen, wman
and Hot\_rext form part of the operating system and therefore cannot be
loaded separately). This means that some programs which could not be run
under the Pointer Environment previously, cannot be run under SMSQ/E. As
far as we are aware, there are very few programs which cause a problem.

A2.8 Undefined Variables
------------------------

SMSQ/E differs from all other implementations of SuperBASIC in that it
gives values to variables which have not yet been defined. Whereas on
other implementations, if you do not have a program in memory (eg. after
NEW), and enter the following line:

PRINT a,a$ : PRINT a/10 you would see the display:

\* \*

on screen, and then the error 'At 0,2 : Error in Expression' would be
shown.

Under SMSQ/E, you would see the display:

0

0

as an undefined numeric variable is given the value 0 and an undefined
string is given the value of an empty string (the second 0 is the result
of a/10 where a=0). No error would be reported.

A2.9 Extended Display
---------------------

There are very few programs which will not work under SMSQ/E, these are
mainly programs (or toolkits) which make assumptions about:

A2.9.1 Extra Colours
^^^^^^^^^^^^^^^^^^^^

SMSQ/E v2.98 implements a different display driver for many systems,
including 65536 colours on the QXL, QPC and Q40 - see Appendix 16.
Because the format of the display is different to the original QL, this
may cause incompatability problems with many of the drawing commands
covered in this book which assume the original QL screen format. This
can however be overcome by only using these commands or programs which
cause problems in the original display configuration of 512x256 pixels,
with MODE 4 or MODE 8 colours. Use RMODE to check which colour system is
currently in use.

People have also noticed that various programs appear in various
multiple colours (not intended by the original author). This tends to be
due to the fact that the authors have assumed that non-standard colours
will be converted by MODE 4 (for example INK 3 under MODE 4 produces
red) or into stipples.

A2.9.2 Hi-resolution Displays
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Unless you are using an original QL motherboard, SMSQ/E supports higher
resolution displays, up to 1600x1200 pixels. This may cause further
problems for software and commands which assume the original resolution
of 512x256 pixels.

A2.10 Problems
--------------

There are very few programs which will not work under SMSQ/E, these are
mainly programs (or toolkits) which make assumptions about:

- The location of the screen or system variables

- The size of the QL's screen

- The fact that you cannot overwrite the QL's ROM (and therefore there
  is no need to ensure that POKE commands are not trying to overwrite
  part of the ROM

- The location of various parts of the operating system (including
  machine code routines)

Most of these programs will also have difficulty running on anything
other than a standard QL (even Gold Cards mean that programs will face
problems if they try to overwrite the QL's ROM).

A2.10.1 Lightning/Speedscreen
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

These two programs cannot be used with SMSQ/E. However, SMSQ/E's screen
driver is just as quick.

A2.10.2 Toolkit III and System Toolkit
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Neither of these toolkits will work with SMSQ/E, but then they do not
really add very much to the system!

A2.10.3 Serial to Parallel Converters
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

SMSQ/E has speeded up the serial ports somewhat (making them meet the
design specifications) and unfortunately this means that some serial to
parallel converters work too slowly and some characters are lost. Try
SER\_PAUSE or a newer converter (or if your computer has a built-in
parallel interface, use that!).

A2.10.4 Aurora
^^^^^^^^^^^^^^

Aurora users will really need to use at least v2a.85 of SMSQ/E.

A2.10.5 Disk Access
^^^^^^^^^^^^^^^^^^^

There appears to be problems accessing DD disks (double density) under
SMSQ/E after v2.91, in that later versions often report file errors or
fail to format these disks. This is a major problem which will hopefully
be resolved in later versions.

See also FLP\_DENSITY.



