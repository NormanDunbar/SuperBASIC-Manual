
==========
Keywords C
==========

TODO
====

- This file references SNOOZE, GLOBAL, EXTERNAL, LINK_LOAD_A, WINCTRL, SET_CHANNEL, DISP_COLOUR. They don't exist.


..  _cache-on:

CACHE\_ON
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CACHE\_ON                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Super Gold Card                                             |
+----------+-------------------------------------------------------------------+

This command enables any internal caches which may be available on your
operating system. This is in fact the default.

Caches are a means of storing computer instructions in fast memory and
cutting down on the time taken by a computer to execute those
instructions.

Normally a computer chip works is fed a program in a series of numbers
representing commands, a format which is known as machine code. This
machine code operates at a very low level - the SuperBASIC command PRINT
a$ would need several hundred machine code commands to have any effect
on screen). The later Motorola chips (not 68000 or 68008) used by QLs
and Amigas (and also the newer chips on PCs and ATARIs) all have
on-board caches which can hold a certain number of these machine code
instructions. If, while the program is running, it accesses those
instructions again within a short time (ie. before the cache becomes
full), then the chip can execute that series of commands again very
quickly.

Although caches can therefore speed up many programs, some computer
programs were written in the days before caches were available for the
QL and compatibles, and therefore will not work if the cache is switched
on. This is particularly true of some of the commands used by the Turbo
compiler which contain self-modifying code, thus meaning that storage of
a chunk of instructions is self-defeating.

**CROSS-REFERENCE**

:ref:`cache-off` allows you to disable the
caches.

--------------


..  _cache-off:

CACHE\_OFF
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CACHE\_OFF                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Super Gold Card                                             |
+----------+-------------------------------------------------------------------+

This command disables the internal caches used to speed up the operating
system. This can help some of the older software to work on newer
systems.

In particular, this command is needed if Flexynet is to work (see
NETSEND).

**CROSS-REFERENCE**

See :ref:`cache-on`.

--------------


..  _call:

CALL
====

+----------+-----------------------------------------------------------------------------------+
| Syntax   |  CALL address [,d1[,d2[,d3[,d4[,d5[,d6[,d7 [,a0[,a1[,a2[,a3[,a4[,a5 ]]]]]]]]]]]]] |
+----------+-----------------------------------------------------------------------------------+
| Location |  QL ROM                                                                           |
+----------+-----------------------------------------------------------------------------------+

This command allows you to call a machine code routine loaded at the
memory location address from SuperBASIC. At the same time, you can set
the initial 68008 registers by supplying more than one parameter. Each
additional parameter should be an integer value and is placed into the
appropriate machine code register.

You cannot return values to SuperBASIC using this command, although you
can return errors by setting D0 from the machine code on return.

If the machine code register D0 contains a number other than an error
code (or 0) on return, the program will stop with the error 'At line '.

Various useful routines can be CALLed on a Minerva ROM - these are
discussed on the next few pages.

**NOTE 1**

This command could crash the computer if used from within a program
longer than 32K on pre JS ROMs. This is fixed by Toolkit II, the THOR
XVI and Minerva.

**NOTE 2**

It can be dangerous to CALL addresses in memory unless you know that you
have loaded a specified machine code routine into that location.

    MINERVA NOTES:

**MINERVA NOTES**

Minerva adds various routines which can be CALLed from within a
SuperBASIC program to perform various tasks quickly and efficiently. The
routines are as follows:

**(1) Reset machine**

CALL 390,param

This routine resets the QL and allows you to set various parameters
according to the value of param, which allows you, for example, to cut
the amount of memory available to the machine. >/p>

To calculate the value of param, look at the following table and decide
what effects you want the reset to have.

Next, look up the value of that effect and add it to param.

**EffectValue to add**

-  Skip memory test = 1
-  Skip ROM scanning (ignore extras) = 2
-  Alter maximum memory = 4
-  Default to TV mode = 8
-  Ignore F1..F4 (no wait) = 16
-  Leave n\*256 bytes between screen and System Variables = n\*256
-  Set ramtop to nKB = (n+128)\*1024

**Examples**

(a) reset machine and force dual screen TV mode (no memory test):

CALL 390,8+16+128+1

(b) reset machine to 640K:

CALL 390,(640+128)\*1024+4

**MINERVA WARNINGS**

CALL 390 can crash the machine - always set the new ramtop to a multiple
of 64K and do not try to allocate more memory than is in the system.

If you leave space between the screen and System Variables, this will
reduce the amount of memory available accordingly!!

If your system uses a keyboard linked to SuperHermes, do not use CALL to
reset the system unless you include a line such as PAUSE 40 prior to the
CALL command to clear all pending input, otherwise SuperHermes becomes
confused!

**(2) Move memory quickly:**


CALL PEEK\_W(344)+16384,length,2,3,4,5,6,7,dest,source

This command allows you to move length bytes from the source address to
the destination address (dest) extremely quickly.

Either source or dest may be odd addresses, and the code will even cope
with overlapping areas.

    Minerva Example:

**Minerva Example**

To copy the whole of the main screen to a screen storage area pointed to
by the variable scr\_store

::

    10 scr_size=SCR_LLEN*SCR_YLIM
    20 scr_store=ALCHP(scr_size)
    30 CALL PEEK_W(344)+16384,scr_size,2,3,4,5,6,7,scr_store,SCR_BASE

**(3) Clear memory quickly**

CALL PEEK\_W(360)+16384,length,2,3,4,5,6,7,address

This command allows you to clear length bytes from the given start
address onwards extremely quickly. It could for example, be used to
clear storage buffers.

Please note that address may be odd.

**CROSS-REFERENCE**

:ref:`lbytes`, :ref:`sbytes`
can be used to load and save areas of memory (and machine code
routines).

:ref:`alchp` and :ref:`respr`
can be used to set aside areas of memory for user routines.

:ref:`bmove` and similar commands allow you to move
areas of memory on other ROM implementations.

--------------


..  _caps:

CAPS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CAPS                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools                                                       |
+----------+-------------------------------------------------------------------+

After the command CAPS has been issued, any input from the keyboard via
INPUT, INKEY$ etc. is translated into capital letters. CAPS simulates
the use of the capslock key.

**Example**

To ask the user for any keyboard input, for example a

password where this should be entered in capital letters:

::

    100 CAPS
    110 INPUT "Please enter password:"!pass$
    120 NOCAPS

**NOTE**

Some old replacement keyboards use dirty tricks to engage capslock. If
you are fed up with the original QL keyboard then ensure you get the
latest release of a modern keyboard interface and an IBM-style keyboard.
If you do not do this, then you may have to change to capslock mode with
CAPS...

**CROSS-REFERENCE**

:ref:`nocaps` is self-explanatory.

--------------


..  _catnap:

CATNAP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CATNAP                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

The Turbo compiler allows PROCedure and FuNction definitions within a
compiled program to be defined as GLOBAL and then called by other tasks.
This is similar to making a modular machine code program which is then
linked together when the assembly language modules are assembled. Under
Turbo, the various program modules can be compiled separately, but then
loaded together with LINK\_LOAD\_A and similar commands.

The CATNAP command will force a compiled program to wait at this
statement indefinitely. The compiled program is only allowed to carry on
execution from the next statement if another module calls one of the
GLOBAL definitions contained in the current program and the GLOBAL
PROCedure or FuNction has completed.

If CATNAP is used within a SuperBASIC program, then the program is
simply suspended until the Break key is pressed.

**CROSS-REFERENCE**

:ref:`snooze` is similar. See also
:ref:`global`,
:ref:`external` and
:ref:`link-load-a`.

--------------


..  _cbase:

CBASE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CBASE [(#ch)](Btool) and CBASE (#ch)(TinyToolkit)                |
+----------+-------------------------------------------------------------------+
| Location |  BTool, TinyToolkit                                               |
+----------+-------------------------------------------------------------------+

The function CBASE finds the start address of the channel definition
block which belongs to #ch. This is an area in memory where QDOS stores
a lot of information about the channel, for example, which kind of
device is connected to the channel.

The Btool variant returns the base of channel #1 if #ch is not
specified.

**CROSS-REFERENCE**

The Pointer Interface modifies the structure of channel definition
blocks for windows.

If you want to access these, preferably use
:ref:`winctrl` instead of
:ref:`cbase`. See also
:ref:`chbase`.

You can also use the `CHAN\_ <KeywordsC.clean.html#chan_>`\ xx functions to
look at the channel definition block.

--------------


..  _cchr-dlr:

CCHR$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CCHR$ (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function CCHR$ takes a word value (max 32767) and returns two
characters represented by that word. This is therefore the same as:

X=PEEK\_W(10000)

PRINT CHR$(X DIV 256);CHR$(X MOD 256)

**CROSS-REFERENCE**


:ref:@\chr-dlr` can be used to print each character separately.

--------------


..  _cdec-dlr:

CDEC$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CDEC$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The function CDEC$ allows you to convert a given value into a string in
a specified format. This function will always take the integer part of
the given value (which must be in the range -2^31...2^31, and will be
rounded to the nearest integer if it is a floating point) and then
assumes that the last ndp digits are to the right of the decimal point.

If there are enough characters to the left of the decimal point, a comma
(',') will be placed between each set of three characters. The length is
the length of the string which is to be returned, which must always be
greater than or equal to the length of the value plus each comma and the
decimal point. If length is not large enough, then the string returned
will be full of asterisks ('\*').

This function is particularly useful for formatting columns of figures,
especially in view of the fact that it sidesteps the QL's habit of
converting large numbers to exponential form. The commas ensure that it
is ideal for use in formatting output of currencies.

**Examples**

PRINT CDEC$(123,4,0)

will print ' 123'

PRINT CDEC$(123,4,1)

will print '12.3'

PRINT CDEC$(1234567,9,2)

will print '12,345.67'

**CROSS-REFERENCE**

:ref:`print-using` is a general means of
formatting output.

:ref:`idec-dlr` and :ref:`fdec-dlr`
are complementary functions.

--------------


..  _cd-alltime:

CD\_ALLTIME
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ALLTIME                                                      |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function returns the actual elapsed time in REDBOOK format from the
start of the CD which is being played at present.

**Example**

A procedure to give the currently elapsed time:

::

    100 DEFine PROCedure SHOW_TIME
    110 elapse%=CD_ALLTIME
    120 PRINT 'TOTAL ELAPSED TIME: ';CD_HOUR (elapse%);' HRS ';CD_MINUTE (elapse%);' MINS ';:
    130 PRINT CD_SECOND (elapse%);' SECS'
    130 END DEFine

**CROSS-REFERENCE**

:ref:`cd-play` plays specified tracks.

:ref:`cd-track` allows you to find out which
track is being played.

:ref:`cd-tracktime` allows you to find out
the total elapsed time on the current track.

:ref:`cd-red2hsg` allows you to convert
REDBOOK format to HSG Format.

:ref:`cd-hour`,
:ref:`cd-minute`,
:ref:`cd-second` allow you to convert REDBOOK
format into a more understandable form.

--------------


..  _cd-close:

CD\_CLOSE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_CLOSE                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command closes the CD drive drawer, loading a CD if you have placed
one in the drawer.

**CROSS-REFERENCE**

:ref:`cd-eject` opens the drawer.

:ref:`cd-play` allows you to play a CD.

See :ref:`cd-init`.

--------------


..  _cd-eject:

CD\_EJECT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_EJECT                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command opens the CD drive drawer and allows you to either place a
new CD in the drive or to remove one.

You need to close the drawer before attempting to play the CD!

**CROSS-REFERENCE**

:ref:`cd-close` closes the CD drive drawer.

:ref:`cd-play` allows you to play an Audio CD.

--------------


..  _cd-firsttrack:

CD\_FIRSTTRACK
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_FIRSTTRACK                                                   |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return the track number of the first track on the CD
currently in the player (this should always be 1).

**CROSS-REFERENCE**

:ref:`cd-lasttrack` allows you to find out
the last track number.

--------------


..  _cd-hour:

CD\_HOUR
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_HOUR (address)                                               |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function takes an address in REDBOOK format and tells you the
number of hours (0..23) contained in that address.

**CROSS-REFERENCE**

:ref:`cd-minute` and
:ref:`cd-second` allow you to find the number
of minutes and seconds in a REDBOOK address respectively.

--------------


..  _cd-hsg2red:

CD\_HSG2RED
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_HSG2RED (address)                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

There are two common formats used to address sectors on a CD directly.
The standard format is REDBOOK format, which uses a time index to
calculate the sector to address.

This time index is in the form $00MMSSFF where MM is the minute, SS the
second and FF the frame.

There are 75 frames in one second.

The other format is HSG FORMAT where the sector is calculated by
reference to the formula:

HSG=(minute\*60+second)\*75+frame

This function takes the address in HSG format and converts this to
REDBOOK format.

**CROSS-REFERENCE**

:ref:`cd-red2hsg` allows you to convert
REDBOOK format addresses to HSG format.

:ref:`cd-hour`,
:ref:`cd-minute` and
:ref:`cd-second` allow you to find out the
hours, minutes and seconds referred to by a REDBOOK address.

--------------


..  _cd-init:

CD\_INIT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_INIT [name$]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

QPC is able to use a CD player linked to a PC in order to play Audio CDs
at present.

You first of all need to initialise the CD drive by using this command.
CD\_INIT causes QPC to seach for a CD-ROM drive and initialise the
driver.

You can either pass the name of the drive as a parameter or, if you do
not use name$, then QPC will use the PC program MSCDEX (if present) to
locate the CD-ROM Drive. MSCDEX can be loaded in the PC file
AUTOEXEC.BAT if you wish, otherwise the CD drive name must appear in the
PC file CONFIG.SYS.

**Example**

CD\_INIT 'mscd001'

**NOTE 1**

This command will only be recognised once.

**NOTE 2**

The CD player commands and functions will not work if you have not
loaded the PC's CD-ROM driver in config.sys, for example with the line:

DEVICE=C:\\CD\\CDROMDRV.SYS /D:MSCD001

**CROSS-REFERENCE**

:ref:`cd-play` allows you to play CD Audio
tracks.

:ref:`cd-eject` ejects a disk from the drive, or
allows you to insert a new disk.

--------------


..  _cd-isclosed:

CD\_ISCLOSED
============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ISCLOSED                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return 1 (True) if the CD drawer is closed, otherwise
it will return 0.

**Example**

::

    100 IF NOT CD_ISPLAYING
    110   IF NOT CD_ISCLOSED : CD_CLOSE
    120   IF CD_ISINSERTED : CD_PLAY
    130 END IF

**CROSS-REFERENCE**

:ref:`cd-close` closes the CD drawer.

--------------


..  _cd-isinserted:

CD\_ISINSERTED
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ISINSERTED                                                   |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return 1 (True) if there is a CD in the CD-ROM drive
and the drawer is closed, otherwise it will return 0.

**CROSS-REFERENCE**

See :ref:`cd-isclosed`.

--------------


..  _cd-ispaused:

CD\_ISPAUSED
============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ISPAUSED                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return 1 (True) if the CD is paused (as opposed to
stopped), otherwise it will return 0.

**CROSS-REFERENCE**

:ref:`cd-stop` can be used to pause the CD.

:ref:`cd-resume` resumes playing a CD.

--------------


..  _cd-isplaying:

CD\_ISPLAYING
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ISPLAYING                                                    |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return 1 (True) if an Audio CD is currently playing,
otherwise it will return 0.

**CROSS-REFERENCE**

:ref:`cd-play` allows you to play an Audio CD.

--------------


..  _cd-lasttrack:

CD\_LASTTRACK
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_LASTTRACK                                                    |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return the track number of the last track on the CD
currently in the player.

**CROSS-REFERENCE**

:ref:`cd-firsttrack` allows you to find out
the first track number.

:ref:`cd-track` tells you the track number
currently playing.

--------------


..  _cd-length:

CD\_LENGTH
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_LENGTH                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return the length of the Audio CD currently in the
player in REDBOOK format.

**CROSS-REFERENCE**

:ref:`cd-lasttrack` allows you to find out
the last track number.

:ref:`cd-hour`,
:ref:`cd-minute`,
:ref:`cd-second` convert REDBOOK format into a
time.

--------------


..  _cd-minute:

CD\_MINUTE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_MINUTE (address)                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function takes an address in REDBOOK format and tells you the
number of minutes (0..59) contained in that address.

**CROSS-REFERENCE**

:ref:`cd-hour` and
:ref:`cd-second` allow you to find the number
of hours and seconds in a REDBOOK address respectively.

--------------


..  _cd-play:

CD\_PLAY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_PLAY [start [,end]]                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command allows you to play the tracks on an audio CD once it has
been initialised. If no parameters are specified, QPC will play the
whole of the CD in the CD-ROM drive.

This command will not slow the operation of SMSQ/E and returns
immediately that the CD starts playing.

The parameters allow you to specify the start and end tracks to be
played. These parameters are given either as track numbers or as sectors
in REDBOOK format (if bit 31 of the parameter is set). A sector on an
Audio CD is 2352 bytes.

To set bit 31, add the value $80000000 or 2^31

**Examples**

CD\_PLAY

plays the whole disk

CD\_PLAY 10

play track 10 to the end of the disk

CD\_PLAY 5,CD\_TRACKSTART(5)+$80000000

play track 5 only.

A program which will play all of the tracks on an Audio CD in a random
order:

::

    100 INPUT 'Has the CD-ROM Drive already been initialised ? [y] ';an$
    110 IF an$=='n': CD_INIT
    120 IF NOT CD_ISINSERTED
    130   IF CD_ISCLOSED : CD_EJECT
    140   INPUT 'Place a CD in the drive and press <ENTER> ';an$
    150   CD_CLOSE
    160   IF NOT CD_ISINSERTED
    170     PRINT 'NO CD LOADED ':PAUSE :STOP
    180   END IF
    190 END IF
    200 tracks=CD_LASTTRACK-CD_FIRSTTRACK
    210 DIM played% (tracks)
    220 FOR i=1 to tracks
    230   REPeat Floop
    240     play=RND(1 TO tracks)
    250     IF played%(play)=0: played%(play)=1: EXIT Floop
    260   END REPeat Floop
    270   CD_PLAY play,play
    280   REPeat Ploop: IF NOT CD_ISPLAYING: EXIT Ploop
    290 END FOR i

**CROSS-REFERENCE**

:ref:`cd-init` allows SMSQ/E to recognise a CD
drive.

:ref:`cd-stop` pauses playing

:ref:`cd-eject` opens the disk drawer to allow
you to insert a new CD.

:ref:`cd-close` closes the disk drawer.

:ref:`cd-isinserted` allows you to check if
a CD is in the drive.

--------------


..  _cd-red2hsg:

CD\_RED2HSG
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_RED2HSG (address)                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function converts a specified address in HSG format into REDBOOK
format.

**CROSS-REFERENCE**

See :ref:`cd-hsg2red` !

--------------


..  _cd-resume:

CD\_RESUME
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_RESUME                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command restarts the CD-ROM drive playing from the last track on
which it was paused.

**NOTE**

If you had not previously paused the CD, then an error is reported.

**CROSS-REFERENCE**

:ref:`cd-stop` allows you to pause a CD which is
currently playing.

:ref:`cd-ispaused` allows you to check if the
CD has been paused.

--------------


..  _cd-second:

CD\_SECOND
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_SECOND (address)                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function takes an address in REDBOOK format and tells you the
number of seconds (0..59) contained in that address.

**CROSS-REFERENCE**

:ref:`cd-hour` and
:ref:`cd-minute` allow you to find the number
of hours and minutes in a REDBOOK address respectively.

--------------


..  _cd-stop:

CD\_STOP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_STOP                                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command has one of two effects.

If an Audio CD is already playing, then the disk is paused.

If you have already paused the Audio CD, then a complete stop is
performed.

**Example**

The following procedure brings the CD to a complete stop -

you cannot resume playing.

::

    1000 DEFine PROCedure STOP_CD
    1010 CD_STOP
    1020 IF CD_ISPAUSED : CD_STOP
    1030 END DEFine

**WARNING**

On some laptop PCs, it has been noted that if you are playing an Audio
CD and close the case without issuing CD\_STOP, when you re-open the
case QPC will have crashed.

**CROSS-REFERENCE**

:ref:`cd-resume` allows you to resume playing
an Audio CD that has been paused.

:ref:`cd-play` allows you to play an Audio CD
that is at a complete stop.

:ref:`cd-eject` opens the drive drawer.

:ref:`cd-close` closes the drive drawer.

--------------


..  _cd-track:

CD\_TRACK
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_TRACK                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function returns the track number of which track on a CD is
actually being played at present.

**CROSS-REFERENCE**

:ref:`cd-play` plays specified tracks.

--------------


..  _cd-tracklength:

CD\_TRACKLENGTH
===============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_TRACKLENGTH (track)                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function returns the length of a specified track in HSG format.

**CROSS-REFERENCE**

:ref:`cd-tracktime` allows you to find out
the elapsed time on a track being played.

:ref:`cd-hsg2red` converts the HSG format to
REDBOOK format.

--------------


..  _cd-trackstart:

CD\_TRACKSTART
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_TRACKSTART (track)                                           |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function returns the start address for a specified track in REDBOOK
format.

**CROSS-REFERENCE**

:ref:`cd-tracklength` allows you to find
out the length of a track.

:ref:`cd-play` allows you to play specified
tracks

:ref:`cd-red2hsg` converts the REDBOOK format
to HSG format.

--------------


..  _cd-tracktime:

CD\_TRACKTIME
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_TRACKTIME                                                    |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function returns the actual elapsed time in REDBOOK format within
the current CD track that is being played at present.

**CROSS-REFERENCE**

:ref:`cd-play` plays specified tracks.

:ref:`cd-track` allows you to find out which
track is being played.

:ref:`cd-alltime` allows you to find out the
total elapsed time on the CD disk as a whole.

--------------


..  _ceil:

CEIL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CEIL (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function CEIL returns the closest integer to x which is greater than
or equal to x (the 'ceiling' of x). Compare INT which returns the next
integer which is less than or equal:

CEIL(12.75)=13 INT(12.75)=12 CEIL(-2.3)=-2 INT(-2.3)=-3

CEIL can handle numbers in the range -32768<x<=32768.

**Example**

A mechanic needs one and a half hours to replace the rusty exhaust of a
car. If his rate of pay is £13 per hour, he will charge
CEIL(13\*1.5)=£20 for the job (excluding parts).

**NOTE**

The simplest way to get a true INTEGER function, where x is rounded up
or down to the nearest integer is with INT(x+.5) which ensures that
INT(12.75)=13 and INT(-2.3)=-2.

**CROSS-REFERENCE**

:ref:`int`

--------------


..  _change:

CHANGE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHANGE old\_drv1$ TO new\_drv2$                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command allows you to rename directory devices. All directory
device names are in the form xxxn\_, where xxx identifies the drive type
(eg. FLP) and n the drive number (1..8).

The most common drive types are:

-  RAM - temporary internal ramdisk
-  FLP - floppy disk drive (sometimes called FDK)
-  MDV - microdrive
-  MOS - permanent external ramdisk
-  WIN - hard disk drive (sometimes HDK)
-  NUL - null device, a dummy device
-  DEV - universal devices (also PTH)

(Please see the Devices Appendix.)

CHANGE replaces the xxx part of a device name by a user defined name.
This new name can already exist but both parameters must consist of
three letters; the use of characters other than letters is possible but
not recommended, eg:

CHANGE "flp" TO "<\*>".

**Example**

CHANGE "ram" TO "mdv" makes the system believe that a ramdisk is a
microdrive.

DIR mdv1\_ will provide a directory of ramdisk 1, but the device ram1\_
(or ram2\_, etc.) is no longer recognised. The microdrives themselves
cannot be accessed any more until you use: CHANGE "mdv" TO "ram" to
restore the normal condition.

**NOTE**

If a device name is in ROM (eg. possibly mdv on QLs without floppy disk
drives), the error -20 (read only) will be reported.

**CROSS-REFERENCE**

:ref:`flp-use` and
:ref:`ram-use` work similarly.

--------------


..  _chanid:

CHANID
======

+----------+-------------------------------------------------------------------+
| Syntax   || CHANID [(#ch)]Btool only or                                      |
|          || CHANID (#ch)TinyToolkit                                          |
+----------+-------------------------------------------------------------------+
| Location || BTool, TinyToolkit                                               |
+----------+-------------------------------------------------------------------+

QDOS uses a different sort of channel number internally to those used by
SuperBASIC. These so-called channel IDs have the advantage that two
channels will never have the same channel ID, even if some channels have
been closed for a long time.

The function CHANID expects an open SuperBASIC channel #ch (a default
channel of #1 is allowed by Btool) and returns its current internal
channel ID.

**Example**

::

    100 OPEN#3,con_2x1
    110 PRINT CHANID(#3)
    120 CLOSE#3: OPEN#3,con_2x1
    130 PRINT CHANID(#3)
    140 CLOSE#3

**CROSS-REFERENCE**

:ref:`chanid` is intended for use with
:ref:`file-open`.

:ref:`channel-id` is the same as the Btool
variant.

See :ref:`set-channel` also.

--------------


..  _channels:

CHANNELS
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHANNELS [#ch]                                                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool, Qsound, TinyToolkit                                       |
+----------+-------------------------------------------------------------------+

The command CHANNELS list all channels which are currently open
(including channels from any other job) to the given channel (default
#1).

Each channel is listed with a channel number which can be used with
CLOSE% and provides details of its size and position. Unfortunately, the
name of the Job which owns the channel is not listed.

**NOTE**

The Tiny Toolkit and Qsound version of this command do not currently
work with the Pointer Environment. The BTool version works to some
extent.

**CROSS-REFERENCE**

:ref:`close-pct`, :ref:`jobs` and
:ref:`chanid`

--------------


..  _channel-id:

CHANNEL\_ID
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHANNEL\_ID [(#ch)]                                              |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is exactly the same as CHANID.

**CROSS-REFERENCE**

See\ :ref:`chanid` and
:ref:`set-channel`.

--------------


..  _chan-b-pct:

CHAN\_B%
========


..  _chan-w-pct:

CHAN\_W%
========


..  _chan-l-pct:

CHAN\_L%
========

+----------+-------------------------------------------------------------------+
| Syntax   || CHAN\_B% (#ch, offset) and                                       |
|          || CHAN\_W% (#ch, offset) and                                       |
|          || CHAN\_L                                                          |
+----------+-------------------------------------------------------------------+
| Location || CHANS (DIY Toolkit - Vol C)                                      |
+----------+-------------------------------------------------------------------+

These three functions can be used to look at values within the channel
definition block relating to the specified channel (#ch). You will need
a good book on the QL's operating system to understand the various
offsets, such as the QDOS/SMS Reference Manual (See section 18.7 to
18.9.3 in that book).

They allow you to read single bytes, words and longwords from the
channel definition block (what is required depends upon the offset).

Extra offsets (negative numbers) are added by the Pointer Environment
which can also be looked at by using these functions.

**Examples**

Instead of using SCR\_BASE, you can use:

PRINT CHAN\_L (#1,50)

to find the base address of the screen.

::

    100 PRINT 'Window #1's size is';
    110 PRINT CHAN_W% (#1,28);'x'; CHAN_W% (#1,30);'a'; CHAN_W% (#1,24);'x'; CHAN_W% (#1,26)

**CROSS-REFERENCE**

:ref:`chbase` can be used to find out similar
information.

--------------


..  _charge:

CHARGE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHARGE [task\_file$]                                             |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command starts up the Turbo Compiler and attempts to compile the
program currently loaded in SuperBASIC Job 0.

It is similar to issuing the commands:

::

    EXEC_W flp1_PARSER_TASK
    EXEC flp1_CODEGEN_TASK

The default device which contains the Turbo compiler (PARSER\_TASK and
CODEGEN\_TASK) can be configured with a special toolkit configuration
program.

If you do not specify a task\_file$, then the one which is configured is
assumed to be the name of the new compiled file to be generated. This
and several other defaults may be altered from the front panel which is
generated by PARSER\_TASK. The default settings on the front panel may
also be configured and set using various directives such as
TURBO\_obfil.

The maximum length of the task\_file$ is 12 characters. If a longer
string is supplied, only the first 12 characters are used.

**Example**

CHARGE 'GENEALOGY'

**NOTE 1**

This command will not work on Minerva and SMS.

**NOTE 2**

The filename for the new task has never really worked correctly when
passed as a parameter, if you specify a device as part of the filename.
The filename becomes corrupted if this is the case.

**NOTE 3**

When you compile a program using TURBO, it is imperative that all of the
machine code procedures and functions which are used by that program are
linked into the machine. If you fail to do this, then an error will be
reported when you try to run your compiled program using EXEC or EXEC\_W
for example.

This is different to QLiberator, which only checks whether each machine
code function or procedure is linked in when (and if) it tries to use
them whilst the compiled program is being run.

**CROSS-REFERENCE**

:ref:`data-area` and various TURBO_xxx
directives exist, starting with :ref:`turbo-diags` to allow you to
specify various compilation options from within your program's source
code.

Please also refer to :ref:`compiled`.

--------------


..  _char-def:

CHAR\_DEF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHAR\_DEF font1,font2                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.57+                                                    |
+----------+-------------------------------------------------------------------+

This command is very similar to the CHAR\_USE command, except that
instead of altering the fonts attached to a specified window, it sets
the default fonts which are used for every new window channel that is
opened after this command (unless they in turn define their own fonts).

The two parameters should point to an address in memory where a font in
the QL font format is stored. If either parameter is 0, then that fount
is reset to the standard system fount. If either parameter is -1, then
CHAR\_DEF will not affect that font.

Minerva users can achieve the same effect with the following:

::

    110 Font0=PEEK_L (!124 !40)
    120 Font1=PEEK_L (!124 !44)
    130 POKE_L !124 !40, NewFont0, NewFont1

Note that you will need to store the addresses of the original QL ROM
fonts (as in lines 110 and 120).

**NOTE 1**

The screen windows which are already open will not be affected.

**NOTE 2**

This command cannot affect a screen window which has been OPENed over
the Network, unless issued on the Slave computer (on whose screen the
window appears), before the window was OPENed over the Network.

**CROSS-REFERENCE**

:ref:`char-use`,
:ref:`char-inc`.

Please also refer to the Fonts Appendix.

--------------


..  _char-inc:

CHAR\_INC
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHAR\_INC [#channel,] x\_step,y\_step                            |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command sets the horizontal (x\_step) and vertical (y\_step)
distance between characters printed on a window (default #1). The
standard values are the width and height of a character and are
automatically set by CSIZE.

CSIZE#2,0,0 performs an internal CHAR\_INC#2,6,10.

Characters are generally based on a grid which measures 8x10 pixels,
although the leftmost column was not available for fonts on pre-JS ROMs.
Also, if you own a JSU ROM (an American QL), this grid size is reduced
to 8x8, although programs would appear to run okay on the JSU ROM
without modification (see MODE for further details).

**Example**

Would you like to print more characters to the screen than normal? You
can either do this by defining smaller fonts or by writing characters on
the screen closer together:

::

    100 WINDOW 512,40,0,0:CLS
    110 CSIZE 0,0: CHAR_INC 5,8:OVER 1
    120 PRINT FILL$('.',102)

Window #1 now offers 5 rows and 102 columns instead of 4 rows and 85
columns, but text can only be read in overwrite mode (OVER 1). CHAR\_INC
6,8 is the highest possible value which will allow text to be read
without the need for OVER 1.

**WARNING**

Unless you have Minerva or Lightning installed (with \_lngASLNG
enabled), if you specify a character height less than the standard 10
pixels (for CSIZE x,0) for example, the strip printed will remain at ten
pixels, and although the screen driver might detect that it is not
necessary to scroll a window to fit the text on, it does not take
account of the height of the strip, which could therefore fall out of
the window (or into the system variables if your window is near the
bottom of the screen).

**CROSS-REFERENCE**

:ref:`csize`, :ref:`over`.

See also :ref:`ttinc`.

--------------


..  _char-use:

CHAR\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHAR\_USE [#ch,] font1,font2                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command allows you to attach substitute fonts in QDOS format to the
specified window channel (default #1).

CHAR\_USE will attach the two fonts at addresses font1 and font2 to the
window in place of the current system fonts.

When a character is printed, if it cannot be found at either font1 or
font2, then the first character of the second font will be used.

To return to the current system fonts on the specified window, use
font1=0 or font2=0 as appropriate.

If you use the value of -1 as one of the parameters, then that font
attached to the specified channel will not be altered by this command.

**Example**

CHAR\_USE #3,font\_address,0

resets the first font in #3 to the font stored at font\_address in
memory.

**NOTE**

This command will have no effect on a window OPENed over the Network.

**CROSS-REFERENCE**

Please refer to the Fonts Appendix concerning QL fonts.

:ref:`char-inc` allows you to alter the spacing
between characters.

:ref:`char-def` allows you to alter the default
system fonts.

:ref:`s-font` performs the same function as
:ref:`char-use`.

--------------


..  _chbase:

CHBASE
======

+----------+-------------------------------------------------------------------+
| Syntax   || CHBASE [(#ch)] or                                                |
|          || CHBASE (chidx%, chtag%)                                          |
+----------+-------------------------------------------------------------------+
| Location || QBASE (DIY Toolkit Vol Q)                                        |
+----------+-------------------------------------------------------------------+

CHBASE is a function which returns the start address of a window
definition block. This block contains a wide range of information about
a window, such as the size and colour settings. Refer to the QDOS
Reference manual Section 18.7 and 18.9.1 (or similar) for further
details.

The window can be either specified by its SuperBASIC channel number, eg:
CHBASE(#2), where the default is #1, or the internal channel ID; which
must be split into index (chidx%) and tag (chtag%) before being passed
to CHBASE.

The latter syntax allows you to access the windows of jobs other than
the current job.

Inside knowledge about the operating system is necessary to access these
tables. Please refer to QDOS system documentation. The structure of the
window definition block is different under Thors, original QLs and the
Pointer Environment.

CHBASE returns small negative integers if an error occurs, representing
the QDOS error code:

-  -1 = Window is currently in use, eg. awaiting input.
-  -6 = No such channel exists.
-  -15 = It's a channel but not a window.

**Example 1**

The current INK colour is found at offset $46, so: INK 7: PRINT PEEK(
CHBASE+ HEX('46') ) will print 7, because of the INK 7 command.

**Example 2**

It is usually not recommended to close and re-open SuperBASIC channel
#0. The following lines check if this has happened, although they will
only work under the SuperBASIC interpreter(!). You will find the
condition in line 100 is always true for Minerva's MultiBASIC
interpreters and SMS's SBASIC interpreters: this does no harm - the
example is more or less just an example of the syntax of CHBASE...

::

    100 IF CHBASE(0,0) <> CHBASE(#0) THEN
    110   UNDER 1: PRINT "Warning": UNDER 0
    120   PRINT "Channel #0 is not in it's original state."
    130 END IF

**CROSS-REFERENCE**

:ref:`cbase`.

See also :ref:`chan-b-pct` and related functions.

--------------



..  _check:

CHECK
=====

+----------+-------------------------------------------------------------------+
| Syntax   | oops = CHECK('name')                                              |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

If name is a currently loaded  machine code procedure or function, then the variable oops will be set to 1 otherwise it will be set to 0.  This is a handy way to check that an extension command has been loaded before calling it.  In a Turbo'd or Supercharged program, the :ref:`exec` will fail and a list of  missing extensions will be displayed, a QLiberated program will only fail if the extension is actually called.

**EXAMPLE**

::

    1000 DEFine FuNction CheckTK2
    1010   REMark Is TK2 present?
    1020   RETurn CHECK('WTV')
    2030 END DEFine


-------


..  _check-pct:

CHECK%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHECK% (integer$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                      |
+----------+-------------------------------------------------------------------+

Coercion is the process of converting a string which holds a number into
the actual number. It is a powerful in-built feature of SuperBASIC. This
allows you to create input routines such as:

::

    100 dage% = RND(10 TO 110)
    110 INPUT "Your age [" & dage% & "]?" ! age$;
    120 IF age$ = "" THEN
    130   age% = dage%: PRINT age%
    140 ELSE
    150   age% = age$: PRINT
    160 END IF

Although SuperBASIC coercion is very powerful, it does have its limits
when non-numeric strings are entered. If age$ was "44", age%=age$ will
assign 44 to age%. Even if the string was not really a number, eg.
"44x5", SuperBASIC will simply ignore everything behind legal characters
(ie. age%=age$ would assign 44 to age% still). However, if age$
contained something like "no thanks" it cannot be coerced and the
program will fail with an 'error in expression' (-17).

The function CHECK% exploits the fact that SuperBASIC is obviously able
to see the difference between a valid number or what comes close to that
and nonsense. CHECK% carries out an explicit coercion for integer
numbers: it will try to make a number from the supplied parameter in the
same way as SuperBASIC would. However, CHECK% will not stop with an
error for unusable strings, instead it returns -32768.

Although "-32768" is converted correctly to -32768, this value must be
reserved because the program cannot know whether the input was illegal
or -32768.

**Example**

Let's rewrite the above example for coercion with CHECK%. We have to
replace the implicit coercion age%=age$ with age%=CHECK%(age$) and put
INPUT into a loop:

::

    100 dage% = RND(10 TO 110)
    110 REPeat asking
    120   INPUT "Your age [" & dage% & "]?" ! age$;
    130   IF age$ = "" THEN
    140     age% = dage%: PRINT age%
    150   ELSE
    160     age% = CHECK%(age$): PRINT
    170     IF age% > -32768 THEN EXIT asking
    180   END IF
    190 END REPeat asking

**CROSS-REFERENCE**

:ref:`checkf` does the same as
:ref:`check-pct` but converts strings containing
floating point numbers.

:ref:`when--error` can trap the coercion
failure.

See the Coercion Appendix also.

--------------


..  _checkf:

CHECKF
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHECKF (float$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                      |
+----------+-------------------------------------------------------------------+

Just like CHECK%, the function CHECKF takes the specified string and
coerces it to a number. This time, however, the number returned will be
a floating point rather than an integer as returned by CHECK%.

CHECKF works just like CHECK% except that a return value of -1E600
signifies unacceptable strings.

**CROSS-REFERENCE**

:ref:`check-pct` and :ref:`ttefp`
are worth a look.

--------------


..  _chk-heap:

CHK\_HEAP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHK\_HEAP                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command is used to check whether the heap has become corrupted - we
have no real details over its working as it is undocumented.

--------------


..  _chr-dlr:

CHR$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CHR$ (code)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the character associated with the given code.

The QL ROM character set is actually only in the range 0...255, although
code can be anything in the range -32768...32767. The least significant
byte of the supplied parameter is used, ie. code && 255.

**Examples**

PRINT CHR$(100) and PRINT CHR$(1636)

both return 'd'.

A short function to convert any lower case letters in a given string to
upper case:

::

    100 DEFine FuNction UP$(a$)
    110 LOCal U$
    115 U$=a$
    117 IF a$='':RETurn ''
    120 FOR i=1 TO LEN(a$)
    130   IF CODE( a$(i) )>96:IF CODE( a$(i) )<123:U$(i)=CHR$( CODE( a$(i) )-32 )
    140 END FOR i
    150 RETurn U$
    160 END DEFine UP$

**NOTE**

The THOR XVI limits code to the range 0...255.

**CROSS-REFERENCE**

See :ref:`code` and also please refer to the
Characters section of the Appendix.

--------------


..  _circle:

CIRCLE
======

+----------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | CIRCLE [#ch,] x,y,radius [,ratio,ecc] :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`\ ,radius\ :sup:`i` [,ratio\ :sup:`i`\ ,ecc\ :sup:`i`]]\ :sup:`\*` |
+----------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                         |
+----------+------------------------------------------------------------------------------------------------------------------------------------------------+

This command allows you to draw a circle of the given radius with its
centre point at the point (x,y).

The positioning and size of the circle will actually depend upon the
scale and shape of the specified window (default #1).

The co-ordinates are calculated by reference to the graphics origin, and
the graphics pointer will be set to the centre point of the last circle
to be drawn on completion of the command.

If any parts of the circle lie outside of the specified window, they
will not be drawn (there will not be an Overflow Error).

If the parameters ratio and ecc are specified, this command has exactly
the same effect as ELLIPSE.

This command will actually allow you to draw multiple circles by
including more sets of parameters. Each additional set must be preceded
by a semicolon (unless the preceding circle uses five parameters). This
means that these commands are all the same:

::

    CIRCLE 100,100,20,1,0,50,50,20
    CIRCLE 100,100,20;50,50,20
    CIRCLE 100,100,20:CIRCLE 50,50,20

Although the FILL command will allow you to draw filled circles on
screen (in the current ink colour), you will need to include a FILL 1
statement prior to each circle if they are to appear independently on
screen (this cannot be achieved when using this command to draw multiple
circles!). If this rule is not followed, then any points which lie on
the same horizontal line (even though they may be in different circles)
will be joined.

**Example**

Try the following for an interesting effect:

::

    100 WINDOW 448,200,32,16: MODE 8
    110 PAPER 0: CLS
    120 SCALE 200,-100,-100
    130 INK 4:CIRCLE -50,-50,5
    140 FOR i=1 TO 350
    150   INK RND(7): FILL 1
    160   CIRCLE_R 5-(i MOD 10),15-(i MOD 30),20
    170 END FOR i

**CROSS-REFERENCE**

Please refer to :ref:`ellipse` for further
information on the ratio and ecc details.

--------------


..  _circle-r:

CIRCLE\_R
=========

+----------+---------------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | CIRCLE\_R [#ch,] x,y,radius [,ratio,ecc] :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`\ ,radius\ :sup:`i` [,ratio\ :sup:`i`\ ,ecc\ :sup:`i`]]\ :sup:`\*` |
+----------+---------------------------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                                            |
+----------+---------------------------------------------------------------------------------------------------------------------------------------------------+

This command draws a circle relative to the current graphics cursor. See
CIRCLE.

**CROSS-REFERENCE**

Please refer to :ref:`arc-r`.
:ref:`ellipse-r` is exactly the same as this
command.

--------------


..  _ckeyoff:

CKEYOFF
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CKEYOFF                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Pointer Interface (v1.23 or later)                               |
+----------+-------------------------------------------------------------------+

Normally, the Pointer Interface will recognise the cursor keys in the
same way as it recognises the mouse, thus allowing you to move the
pointer around the screen using the keyboard.

You may however prefer that the cursor keys had no effect on the pointer
- the solution is simple - just use the command CKEYOFF.

**NOTE**

There were problems with this command prior to v1.56.

**CROSS-REFERENCE**

:ref:`ckeyon` tells the Pointer Interface to
recognise the cursorkeys again.

--------------


..  _ckeyon:

CKEYON
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CKEYON                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Pointer Interface (v1.23 or later)                               |
+----------+-------------------------------------------------------------------+

See :ref:`ckeyoff`.

**NOTE**

There were problems with this command prior to v1.56.

--------------


..  _clchp:

CLCHP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLCHP                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, Btool                                      |
+----------+-------------------------------------------------------------------+

A BASIC program can reserve space in the common heap with ALCHP. The
command CLCHP removes all space which has been grabbed using ALCHP and
returns it to the common heap so that it can be used for other purposes.

**CROSS-REFERENCE**

:ref:`alchp` reserves areas of the common heap, and
:ref:`rechp` releases a specified part of the common
heap.

Compare :ref:`reserve` and the Btool variant of
:ref:`alchp`.

:ref:`new` and :ref:`load` also
release areas of the common heap.

--------------


..  _clear:

CLEAR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLEAR                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command forces all variables to be cleared meaning that the
computer will no longer remember their values.

This does not affect SuperBASIC functions or resident keywords, for
example, PRINT PI will always return 3.141593.

On non-SMS machines, if a variable is PRINTed, which has not yet been
assigned a value, an asterisk appears on screen. If you try to *use* a
variable which has not yet been assigned a value, then an error will
occur (normally error in expression (-17)).

If Toolkit II is present (or you are using Minerva or a THOR XVI), any
valid WHEN structures are also suspended by the CLEAR command.

Adding CLEAR before a program is run ensures that all variables used in
a program will be defined properly. While developing a large program in
BASIC it may sometimes be helpful to set an essential variable directly
in the command line and not as a static statement in the listing.

**Example**

The following lines will produce a different output depending on whether
they have been run before or not:

::

    100 PRINT a
    110 a=5
    120 PRINT a

The first run shows... \* 5 This is because the contents of a were not
defined until line 110 was reached.

The second time, a was still set and so the output is slightly
different... 5 5

**NOTE**

CLEAR may cause some problems on pre Minerva ROMs if it is issued after
having deleted a PROCedure or a FuNction in a SuperBASIC program which
appeared as the last thing in a program. This is fixed by Toolkit II.

**SMS NOTE**

Variables which have not been assigned a value on SMS will return 0
(zero) if a numeric variable or otherwise an empty string - an error
will therefore not occur if you try to use such a variable.

On a machine fitted with SMS the example would therefore have printed 0
5 on the first run, and 5 5 on the second.

**CROSS-REFERENCE**

:ref:`close`,
:ref:`clear-hot`,
:ref:`clchp`, :ref:`clrmdv`,
:ref:`run`.

--------------


..  _clear-hot:

CLEAR\_HOT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CLEAR\_HOT key                                                   |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command deletes a hotkey defined with the HOT command and releases
the memory used to set up the hotkey back to QDOS' memory management.

**NOTE**

CLEAR\_HOT works okay, but in most cases the memory released by this
command is not recognised by the system as being free memory and
therefore cannot be re-used without resetting the system.

**CROSS-REFERENCE**

See :ref:`hot` on how to define a hotkey.

Use :ref:`free`,
:ref:`free-mem` to check the actual available memory.

--------------


..  _clip-pct:

CLIP%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLIP% (#channel)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  CLIP (DIY Toolkit - Vol S)                                       |
+----------+-------------------------------------------------------------------+

This function can be used to read characters from the QL's screen.

In order for the function to work, you will need to OPEN a window over
that part of the QL's screen which you wish to read and ensure that it
is in the correct MODE and has UNDER, CSIZE and CHAR\_INC set to the
same values as were used to create that part of the screen. You will
also need to ensure that the same font is being used by the window which
you have OPENed. The window should be defined so that any text written
to that window would precisely match the text on screen (except for
colour).

Due to the way in which QL's work, this means that CLIP% can be used to
read user-defined characters from the screen, for example, where in
games some of the font has been redefined to represent symbols in the
game.

The function will then try to read a character from the current cursor
position and return its character CODE. It can be used to read any
character in the range 0...255 (except CHR$(10) which does not appear on
screen).

The DIY Toolkit includes an example of a program which uses this
function to create a clip board for reading text from a program running
on the QL. It uses CHAN\_W% and similar functions to read the existing
settings of the window of a target program.

However, this function is really of most use when used within your own
programs, possibly to detect collisions in a game between objects.

**Example**

The following short routine could be used to read the name of a disk in
flp1\_ (provided that the directory was not longer than one page):

::

    10 DIR flp1_
    20 FOR i=0 TO 20
    25 AT #1,1,i
    30 PRINT #2,CLIP$(#1);
    40 END FOR i

**NOTE 1**

Although this works on all QL implementations, the code will not
currently work with resolutions bigger than 512x256 pixels.

**NOTE 2**

If you want to read characters from a window of a program whilst the
THOR XVI's windowing environment, or the Pointer Environment is running,
you will have to switch off the windowing environment before the program
in question is loaded, using POKE SYS\_VARS+133,1 on the THOR or EXEP
flp1\_program,u under the Pointer Environment.

**NOTE 3**

The main problem with these functions is that some programs do not use
standard fonts (or attach fonts to a window using non-standard
techniques). Some additional fonts are supplied with DIY Toolkit which
may help in this respect.

**CROSS-REFERENCE**

See the Fonts Appendix about changing QL fonts.

:ref:`char-use` and
:ref:`s-font` allows you to set the font used by a
window.

See also :ref:`clip-dlr`.

--------------


..  _clip-dlr:

CLIP$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLIP$ (#channel)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  CLIP (DIY Toolkit - Vol S)                                       |
+----------+-------------------------------------------------------------------+

This function is very similar to CLIP% except that it returns the actual
character which appears on screen rather than the character code.

**NOTE**

The same notes apply to this function as to CLIP%.

**CROSS-REFERENCE**

See :ref:`clip-pct`.

--------------


..  _clock:

CLOCK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLOCK [#channel] [,format$]                                      |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The command CLOCK creates a multitasking digital clock job named Clock.
If no channel parameter is stated, CLOCK will open its own window
(con\_60x20a448x206), which is intended for F1-monitor mode (see WMON),
otherwise the given channel will be used.

Format$ is optional and is used to define how the clock will appear on
screen. It can contain any text you desire (except for the characters %
or $), but there are certain special characters (see below) which allow
you to alter the way in which the clock is presented; so CLOCK "TEA AT
4" might remind you when tea time is, but will have no effect on the
display of the clock.

The format is defined by using certain set series of strings. The
following special characters will affect the way in which the clock is
displayed (the default format string is "$d %d $m %h:%m:%s" which is
ideal) :

-  %d Day of month - 2 digits
-  $d Day of week - 3 characters
-  %h Hour (24h) - 2 digits
-  $m Month - 3 characters
-  %m Minute - 2 digits
-  %s Seconds - 2 digits
-  %y Year - 2 digits (last two digits)
-  %c Century - 2 digits (see note 4 below)

A newline can be inserted by either padding out the string with spaces
or by adding CHR$(10) inside the string.

**Example**

CLOCK #2,'Date: %d $m %y' & chr$(10) & 'Time: $d %h:%m'

**NOTE 1**

There is no difference between upper case and lower case letters, so %d
has the same effect as %D. However, do watch the difference between $m
and %m!

**NOTE 2**

Any attempt to open a clock in channel #0 will be ignored and the
default window opened.

**NOTE 3**

Unfortunately for Pointer Environment users, there is no way of
'unlocking' the clock so that it can operate alongside other Jobs. On
the THOR XVI this is alleviated by ensuring that the Job is always owned
by Job 0.

**NOTE 4**

v2.25+ of Toolkit II introduced a further special character for use in
the format string. This is %c, which returns the first two digits of the
year, for example %c%y will print the current year as four digits.

**NOTE 5**

On v6.41 of the THOR XVI, if CLOCK has to open its own window, this
window is in fact owned by SuperBASIC rather than the CLOCK task. This
means that if CLOCK is removed other than by using NO\_CLOCK, (eg. with
RJOB) the channel can be left open.

**CROSS-REFERENCE**

Use :ref:`sdate` or :ref:`adate`
to set the system date and time.

:ref:`date-dlr` and :ref:`date`
return the current time.

:ref:`no-clock` removes the
:ref:`clock` on the THOR.

--------------


..  _close:

CLOSE
=====

+----------+----------------------------------------------------------------------------+
| Syntax   || CLOSE #channel  or                                                        |
|          || CLOSE #channel1 [, #channel2 ...] (Toolkit II, Btool & Minerva v1.81+) or |
|          || CLOSE (Toolkit II, THOR & Minerva v1.81+, BTool)                          |
+----------+----------------------------------------------------------------------------+
| Location || QL ROM, Toolkit II, BTool,. THOR                                          |
+----------+----------------------------------------------------------------------------+

CLOSE is a procedure which closes a specified channel, (or even several
channels if the second or third variant is used). The contents of that
channel will however remain unchanged.

The second variant allows any number of specified channels to be closed
at the same time and the third closes all channels with channel numbers
of #3 or above.

Every CLOSE command will first flush the contents of internal buffers to
ensure that all information has been passed to the channel before it is
closed.

**Examples**

::

    CLOSE#3
    CLOSE#n
    CLOSE #1
    CLOSE#8,#3,#6
    CLOSE

**NOTE 1**

On Minerva pre v1.81 and other ROMs, unless Toolkit II is installed,
CLOSE will report 'channel not open' if the channel is not open. Toolkit
II and later versions of Minerva stop this from happening.

**NOTE 2**

There is a harmless bug in Toolkit II's CLOSE. This will report error
-15 (bad parameter) if channel #32767 was opened and CLOSE issued
without parameters, or even if you use the explicit command CLOSE #32767
(unless you have SMS). Although #32767 will still be closed
successfully, any further attempt to use CLOSE without parameters will
continue to report error -15 until the program is cleared out with NEW,
LOAD or LRUN.

**NOTE 3**

On Minerva, if you have Lightning installed, then unless you CLOSE
channels in the opposite order to that in which they were OPENed, you
may end up with several CLOSEd windows which are still visible on
screen. This will only disappear when another channel with the same
channel number is opened. The Pointer Interface and SMS cure this.

**NOTE 4**

Unless you have a THOR XVI or Minerva (without SMS), do not CLOSE a
network out (eg. NETO\_1) channel unless you have written something to
it. The machine will lock up if you do so be warned! On a THOR, the
system will lock up for 30 seconds and then report an 'Xmit Error'. On
Minerva, you will need to press <CTRL><SPACE>.

**NOTE 5**

QL ROMs (pre MG) had problems in closing ser2 - they tended to close one
serial channel for output and the other for input instead!

    NOTE 6:

**NOTE 6**

If you are writing to a file (especially on a microdrive cartridge),
ensure that the drive has finished turning after issuing the CLOSE
command, before trying to access the file (otherwise you may find that
all of the changes are not present!). The other solution is to FLUSH the
file before CLOSEing it.

**MINERVA NOTE**

CLOSE #1 will also remove a MultiBasic job in certain instances - see
appendix on Multiple Basics.

**WARNING**

Although under the interpreter, channel #0 (the command window) and
channels #1 and #2 can be closed, this will lock up the SuperBASIC
interpreter. It does no harm at all in compiled programs.

Minerva and SMS prevents this from being disastrous, but some programs
may behave a little strangely on the newly opened #0. If you use CLOSE
#0 from within a MultiBASIC or one of SMS's SBASICs, this will remove
the MultiBASIC (or SBASIC) Job.

**CROSS-REFERENCE**

:ref:`open`, :ref:`channels`,
:ref:`close-pct`
:ref:`scr-store` and related commands can be
used to provide the QL with a windowing environment whereby the contents
of the screen are restored when a window is
:ref:`close`\ d.

--------------


..  _close-pct:

CLOSE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CLOSE% n                                                         |
+----------+-------------------------------------------------------------------+
| Location |  BTool, TinyToolkit                                               |
+----------+-------------------------------------------------------------------+

The command CLOSE% allows you to close a channel which is specified
using the channel number listed when you use the CHANNELS command. This
thus allows you to close channels owned by other Jobs.

**WARNING**

If you close the channel of a job, this can lock up that job. Ensure
that you know the consequences of your actions!

**CROSS-REFERENCE**

:ref:`channels`, :ref:`close`

--------------


..  _clrmdv:

CLRMDV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CLRMDV n                                                         |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, Btool                                               |
+----------+-------------------------------------------------------------------+

This command forces the QL to forget that it had already read a
cartridge in the given microdrive mdvn\_. This could be necessary if
cartridges are exchanged between QLs, otherwise one of the QLs may not
find a file written by another QL on a cartridge. Such problems do not
exist with floppies or any other media.

**Example**

CLRMDV 2

**CROSS-REFERENCE**

For :ref:`rand`, :ref:`clrmdv`
is very useful.

See also :ref:`del-defb` which performs a
similar task.

--------------


..  _cls:

CLS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CLS [#chan,] [cls\_type]                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is normally used to clear all or part of the specified
window (default #1) to the current paper colour for that channel (this
is not affected by OVER). CLS does not affect a border attached to a
window.

The cls\_type can be used to specify which area of the window is to be
cleared (the default is 0). This can have the following standard values,
which have different effects depending upon the current position of the
text cursor:

-  0 Clear the whole window
-  1 Clear the window above the cursor line
-  2 Clear the window below the cursor line
-  3 Clear the whole cursor line
-  4 Clear the window from the cursor position to the right-hand end of
   the cursor line

After using this command, the text cursor is placed at the top left-hand
corner of the window (if cls\_type=0) or at the start of the next line
below the cursor position for other values.

Except under SMS and on the THOR XVI, most systems allow you to use
other values for cls\_type to access various TRAP #3 system utilities.
The way in which the appropriate value of cls\_type is calculated is by
taking the value of D0 which would be used in machine code and
subtracting 32 from this. If this gives a negative result, then add this
negative result to 128.

For example, to move the cursor back one space, in machine code you
would use the call IOW.PCOL (D0=19). 19-32=-13, therefore:

CLS #3,128-13 moves the cursor back one space in #3.

You must however be aware of using CLS 98 (IO.FLINE) on pre JS ROMs,
since this tended to leave the cursor switched on!

**NOTE 1**

On pre MG ROMs CLS is likely to fail if the window is smaller than the
cursor.

**NOTE 2**

The THOR XVI only allows cls\_type to be in the range 0..4.

Under SMS, if cls\_type is more than 4, then CLS uses cls\_type MOD 4.

**NOTE 3**

Some of the additional values of cls\_type can actually cause the
computer to crash, whilst others will merely report an error.

**CROSS-REFERENCE**

:ref:`at` and :ref:`print` position
the text cursor.

:ref:`paper` alters the current paper colour.

:ref:`scroll` and :ref:`pan` also
allow you to access various system utilities.

A much safer way to access system utilities is to use
:ref:`io-trap`, :ref:`mtrap`,
:ref:`qtrap` and :ref:`btrap`.

For details of the various TRAP #3 system utilities refer to the
QDOS/SMS Reference Manual (Section 15) or similar.

--------------


..  _cls-a:

CLS\_A
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CLS\_A                                                           |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools                                                       |
+----------+-------------------------------------------------------------------+

This command forces all windows currently OPENed by SuperBASIC or
belonging to the current job to be cleared and given a border (width 1,
colour 255). This works on channels opened on Minerva's dual screens.

**CROSS-REFERENCE**

:ref:`cls` clears a single window without changing
window attributes, the border in this case.

--------------


..  _cmd-dlr:

CMD$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CMD$                                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Minerva                                                     |
+----------+-------------------------------------------------------------------+

This function can be used from within SMS SBASICs, Minerva MultiBASICs
and compiled programs (not SuperBASIC Job 0) to read a string passed to
the program when it was initiated, with the command EX (or similar).

The string appears after the EX command, preceded with a semicolon.

**Example**

Create a program to load in Xchange and set its default drives and
memory, something akin to:

::

    10 xch_data$=DATAD$:xch$=PROGD$
    20 data_space=300
    30 x$=CMD$
    40 IF x$<>''
    45   datpos='\' INSTR x$
    50   IF datpos:data_space=x$(datpos+1 TO)
    55   IF datpos>5:x$=x$(1 TO datpos-1)
    74   dr1=',' INSTR x$
    75   IF dr1<6
    80     IF dr1=0:PROG_USE x$(1 TO):ELSE IF dr1<LEN(x$-4):DATA_USE x$(dr1+1 TO)
    90   ELSE
    100     PROG_USE x$(1 TO dr1-1)
    110     IF dr1<LEN(x$)-4:DATA_USE x$(dr1+1 TO)
    120   END IF
    140 END IF
    150 EX xchange;data_space
    160 DATA_USE xch_data$
    170 PROG_USE xch$

Save this as FLP1\_XCHANGE\_BAS (or similar).

Now, to pass the relevant parameters all you need do under SMS is enter
the line:

EXEC flp1\_XCHANGE\_BAS;'win1\_XCHANGE\_,flp2\_\\200'

Minerva treats the string slightly differently - see EX for an
explanation of the following command which achieves the same:

EXEC pipep;'flp1\_XCHANGE\_BAS>win1\_XCHANGE,flp2\_\\200'

This will execute win1\_XCHANGE\_xchange with the help file to be loaded
from win1\_XCHANGE\_ , the data files being loaded from flp2\_ and a
dataspace of 200K.

**NOTE 1**

In SMS pre v2.60, you could not directly slice CMD$ - copy it to another
string variable first, as in the example.

**NOTE 2**

You cannot use this command in TURBO compiled jobs - use OPTION\_CMD$
instead.

**CROSS-REFERENCE**

See :ref:`exec` and
:ref:`exec-w`.

--------------


..  _code:

CODE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CODE (character$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the internal code used to represent the given
character$ (this will be a value between 0 and 255).

If the supplied parameter is more than one character in length, the code
of the first character will be returned. The result 255 represents the
ALT key, although this will only be produced with the statement PRINT
CODE(INKEY$) if the <ALT> key is being pressed together with a second
key, in which case the code of the second key quickly follows. If
character$ is a nul string, CODE will return 0.

**Example 1**

PRINT CHR$(CODE('Alpha'))

will print 'A'.

**Example 2**

A short program to reveal the code of the current key being pressed
(with special code to trap the instance of the ALT key being pressed):

::

    100 REPeat loop
    110   AT 0,0: a$ = INKEY$(#1, -1)
    120   IF CODE(a$) = 255
    130     PRINT 'ALT+' & CODE(INKEY$) & '  '
    140   ELSE PRINT CODE(a$);'      '
    150   END IF
    160 END REPeat loop

Try replacing lines 110 to 150 with: 110 AT 0,0: PRINT CODE(INKEY$(-1))

**CROSS-REFERENCE**

Please refer to the Characters section of the Appendix for a full list
of the characters and their internal codes.

--------------


..  _codevec:

CODEVEC
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CODEVEC (name$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ALIAS (DIY Toolkit - Vol A)                                      |
+----------+-------------------------------------------------------------------+

This function is very similar to KEY\_ADD in that it returns the address
in memory where the machine code for a machine code Procedure or
Function is stored (useful for debugging programs with Qmon or similar
machine code monitor).

If the Machine Code Procedure or Function with the given name$ does not
exist, then a 'Not Found' error is reported.

**CROSS-REFERENCE**

See :ref:`key-add` and
:ref:`elis`.

--------------


..  _col:

COL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  COL(x, y)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

COL is a function which returns the colour of a given screen pixel
(specified in absolute co-ordinates). The colour is however not coded in
the usual way - the return value of COL is either 0, 1, 2 or 3
(representing the four true colours which can displayed in MODE 4, ie.
black, red, green and white).

**Example**

::

    100 WMON: LIST#2
    110 xmin% = 0: xmax% = 100
    120 ymin% = 0: ymax% = 100
    130 FOR x% = xmin% TO xmax%
    140   FOR y% = ymin% TO ymax%
    150     c% = 2 * COL(x%,y%) + 1
    160     BLOCK 1, 1, x%-xmin%, y%-ymin%, c%
    170   END FOR y%
    180 END FOR x%

Unless you are using Minerva or SMS, replace x% and y% by x and y.

**NOTE**

COL will return meaningless data unless the screen is located at address
131072, is in MODE 4, and uses a 512 x 256 resolution.

**CROSS-REFERENCE**

:ref:`set` draws a screen pixel.

--------------


..  _colour-native:

COLOUR\_NATIVE
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_NATIVE [#ch]                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_NATIVE is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the Q40/Q60, QXL, QPC and Aurora.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

This command is similar to COLOUR\_PAL, but allows you to use 256
colours on Aurora, or 65536 colours on QXL, QPC and the Q40/Q60, by
selecting the native colour mode of the hardware.

Colour parameters supplied to commands such as INK are defined in native
colours and therefore their effect will depend upon the hardware itself
(Appendix 16 contains details of the first 256 colours and their Native
Colour Values in decimal, hexadecimal and binary for use with the INK
command or similar).

**NOTE**

MODE commands have no effect under the Extended Colour Drivers.

**CROSS-REFERENCE**

Refer to :ref:`colour-pal` for more details.

--------------


..  _colour-pal:

COLOUR\_PAL
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_PAL [#ch]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_PAL is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the Q40/Q60, QXL, QPC and Aurora.

This command requires the Extended Colour Drivers to have been loaded
when SMSQ/E started (set by configuration or chosen from the start-up
menu on QPC). It will not have any effect upon programs already loaded
into the system.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

COLOUR\_PAL selects the PAL colour mode, allowing 256 colours to be
used. After using this command, the effect of the colour parameters
supplied to commands such as INK will depend upon the table which
appears in Appendix 16 - use the PAL colour value given for each colour
(this is hardware independent).

As a result, code such as that given in the example below is required to
check on the colour scheme currently in use and adapt the program
accordingly.

**Example**

::

    100 REMark Make sure the program is in the right mode for Standard QL/Extended Colours
    110 col_sys%=0:h$=VER$
    120 IF RMODE=8:MODE 4
    130 IF RMODE=16:col_sys%=1:REMark Aurora - Extended Colour Drivers
    140 IF RMODE=32:col_sys%=3:REMark QXL/QPC - Extended Colour Drivers
    150 IF RMODE=33:col_sys%=2:REMark Q40 - Extended Colour Drivers
    160 :
    170 REMark Select Appropriate colour scheme
    180 IF h$='HBA':IF col_sys%<>0:COLOUR_PAL
    190 SELect ON col_sys%
    200   =0:BLACK=0:WHITE=7:RED=2:GREEN=4:       REMark Four colours available
    210   =REMAINDER :BLACK=0:WHITE=1:RED=2:GREEN=3:REMark 256 colours available
    220 END SELect
    230 PAPER BLACK:INK GREEN

**NOTE 1**

The 256 colours produced under COLOUR\_PAL on non-Aurora machines may be
changed to allow any 24-bit colour using the command PALETTE\_8. This
will not work on Aurora, which has display hardware limited to 256
colours.

**NOTE 2**

MODE commands have no effect under the Extended Colour Drivers. RMODE
will always report 16 on Aurora, 32 on QXL/QPC and 33 on the Q40/Q60 if
the Extended Colour Drivers are in use.

**CROSS-REFERENCE**

Refer to Appendix 16 and :ref:`ink` for more details.

:ref:`colour-ql`,
:ref:`colour-native` and
:ref:`colour-24` are all similar.

:ref:`palette-ql` and
:ref:`palette-8` affect colour palettes.

:ref:`bgcolour-ql` and
:ref:`bgcolour-24` can be used to alter the
desktop colour of the main screen.

:ref:`disp-colour` can be used to switch
between Extended Colour Drivers and the Standard Colour Drivers.

--------------


..  _colour-ql:

COLOUR\_QL
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_QL [#ch]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_QL is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the Q40/Q60, QXL, QPC and Aurora.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

This command is similar to COLOUR\_PAL, but selects an 8 colour mode,
with colours from 0...7 as per the original QL MODE 8 (although all 8
colours remain available for programs which presume MODE 4).

This can cause some slight incompatability problems, due to programs
which presume that under MODE 4, INK 3 would produce Red (for example) -
under COLOUR\_QL it will now produce Magenta.

**NOTE 1**

The eight colours produced under COLOUR\_QL may be changed to allow any
colour supported by the hardware using the command PALETTE\_QL.

**NOTE 2**

MODE commands have no effect under the Extended Colour Drivers.

**CROSS-REFERENCE**

Refer to :ref:`colour-pal` for more details.

:ref:`palette-ql` includes a way of overcoming
the incompatability problems with old :ref:`mode`\ .. 4  programs.

--------------


..  _colour-24:

COLOUR\_24
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  COLOUR\_24 [#ch]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

COLOUR\_24 is a command used to select the colour palette to be used
from within the Extended Colour Drivers provided with SMSQ/E v2.98+ on
the QXL and QPC, providing a good graphics card is installed.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

This command is similar to COLOUR\_PAL, but allows you to specify
colours directly using the 24 bit colour mode, thus allowing 16777216
(2^24) colours on screen at the same time.

Although the command does work on hardware which does not support a 24
bit graphics mode, the specified colours have to be adapted to fit into
the memory available for each pixel (eg 8 or 16 bits). This can cause
inaccuracies and unpredictable results - COLOUR\_NATIVE is preferable in
such circumstances.

**CROSS-REFERENCE**

Refer to :ref:`colour-pal` and
:ref:`colour-native` for more details.

:ref:`palette-ql`,
:ref:`palette-8` and
:ref:`bgcolour-24` all use the 24 bit table
to describe colours.

--------------


..  _command-line:

COMMAND\_LINE
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  COMMAND\_LINE                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is really only of any use with the TYPE\_IN command. It
selects the SuperBASIC command line (#0) so that anything passed with
TYPE\_IN is automatically entered into that channel (as if it were
typed).

Note that COMMAND\_LINE cannot have any effect if SuperBASIC is doing
something or if the job which uses the command was started with EXEC\_W
or similar.

**NOTE 1**

COMMAND\_LINE pre v3c27 does not seem to work correctly on all versions
of the QL ROM.

**NOTE 2**

Two files called TurboFix\_bin and MiniCommdLin\_bin can be used to
allow COMMAND\_LINE to select the command line of a Minerva MultiBASIC -
this relies on the MultiBASIC being the job which uses the COMMAND\_LINE
command. Some early versions of TurboFix\_bin have bugs in it.

A similar version is available called SMSQCommdLin\_BIN which works in
the same way, except for SMS SBASIC interpreters. Some versions of
TurboFix\_BIN also support SBASIC but it is currently recommended that
this file is used instead.

**CROSS-REFERENCE**

See :ref:`type-in` for an example.

--------------


..  _compiled:

COMPILED
========

+----------+-------------------------------------------------------------------+
| Syntax   |  COMPILED                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function simply returns a value of 0 if the current program is
interpreted or 1 if it has been compiled.

**NOTE 1**

Although primarily for use with programs compiled with Turbo, versions
of this function after v3c27 will work even from within a program
compiled under QLiberator.

**NOTE 2**

Prior to v3c27, this function did not always return the correct value on
Minerva and SMS (particularly from within a MultiBASIC or SBASIC
daughter job).

**CROSS-REFERENCE**

See :ref:`job-name` for an example.

--------------


..  _compress:

COMPRESS
========

+----------+-------------------------------------------------------------------+
| Syntax   |  COMPRESS filename                                                |
+----------+-------------------------------------------------------------------+
| Location |  COMPICT                                                          |
+----------+-------------------------------------------------------------------+

This command takes the current screen contents and compresses them,
saving the picture in its compressed form in the stated file - the full
filename (eg. ram1\_test\_scr) has to be used.

This compressed form does not represent that great a saving over the
original 32768 bytes required to hold the details of the screen before
compression - the amount of space required for a compressed screen
depends upon the amount of adjacent pixels on the screen which have the
same colour.

Whilst the screen is compressed, a pattern is drawn over the screen,
which although annoying, is harmless.

**Example**

COMPRESS flp2\_TITLE\_scr

**NOTE 1**

COMPRESS temporarily needs 64K of working space and will report an error
if this is not available. Unfortunately the file stays open if this
happens and cannot be accessed until is is closed with CLOSE% or a
desktop program such as QPAC 2 (channels menu).

**NOTE 2**

COMPRESS does not work in supervisor mode, ie. it multitasks, thus if
you were doing something else whilst the screen was being compressed,
the saved picture may look pretty strange when expanded.

**NOTE 3**

COMPRESS assumes that the screen starts at $20000 and cannot therefore
be used with Minerva's second screen or some emulator display modes.

**NOTE 4**

COMPRESS assumes a screen resolution of 512x256 and cannot work on
higher resolution screens.

**CROSS-REFERENCE**

Screens which have been saved with
:ref:`compress` can be loaded with
:ref:`expand` or re-loaded from memory with
:ref:`fastexpand`.

See also :ref:`scr-store`.

--------------


..  _concat:

CONCAT
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CONCAT file1,file2 TO file3                                      |
+----------+-------------------------------------------------------------------+
| Location |  CONCAT                                                           |
+----------+-------------------------------------------------------------------+

This command merges the first two files together to form a new file with
the third specified filename, so that file2 is appended to file1. The
length of file3 is exactly the sum of the lengths of the merged files.

**Example**

Most SuperBASIC programmers use their own standard set of

procedures and functions. If two of them need to be added

to a program, CONCAT helps a lot: CONCAT flp1\_PROG\_bas,flp1\_SUB\_1 TO
ram1\_PROG\_tmp DELETE flp1\_PROG\_bas CONCAT
ram1\_PROG\_tmp,flp1\_SUB\_2 TO flp1\_PROG\_bas DELETE ram1\_PROG\_tmp

You must ensure that line numbers do not conflict.

**NOTE**

Each filename must include the device.

**CROSS-REFERENCE**

:ref:`copy`, :ref:`rename`,
:ref:`delete`.

See :ref:`fwrite` for the more flexible APPEND
procedure.

--------------


..  _connect:

CONNECT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CONNECT [#]pipe\_in% TO [#]pipe\_out%                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is exactly the same as TCONNECT, except that the two
channels do not have to have a hash sign in front of them.

**CROSS-REFERENCE**

:ref:`tconnect`
and\ :ref:`qlink`

--------------


..  _continue:

CONTINUE
========

+----------+-------------------------------------------------------------------+
| Syntax   || CONTINUE or                                                      |
|          || CONTINUE [line\_no](Toolkit II & Minerva only)                   |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This command allows the user to try and recover from an error (normally
after STOP or pressing the Break key), by telling the interpreter to
carry on running the program from the next statement. This will however
not work if the message 'PROC/FN Cleared'.

If you have Toolkit II, Minerva installed, you will be able to use the
second variant of this command which allows you to re-start processing
at a specified line number to help with error trapping.

**NOTE 1**

CONTINUE cannot carry on processing where the line which was stopped was
a direct command (ie. typed in at #0).

**NOTE 2**

Unless you are using the Toolkit II or Minerva variants of this command,
do not try to use CONTINUE after RENUMbering the program, as the
continuation table is not updated by the RENUM routine and may therefore
try to jump to the old line number.

**NOTE 3**

Beware that RENUM does not renumber line\_no if you have used this
command as part of a program.

**NOTE 4**

CONTINUE can only re-start processing if no new lines have been added;
no new variables have been added to the program; no lines have been
altered; and the PROC/FN Cleared message has not appeared.

**CROSS-REFERENCE**

See :ref:`retry` and also
:ref:`when--error`.

--------------


..  _convcase-dlr:

ConvCASE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  ConvCASE$ (string$ [,lower])                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

ConvCASE$ returns the given string with all upper case letters converted
to lower case if lower=1, or all lower case letters to upper case if
lower=0. Default of lower is 1

**NOTE**

Unlike similar functions ConvCASE$ will recognise all non- ASCII
letters, namely umlauts and accents.

**CROSS-REFERENCE**

:ref:`upper-dlr`, :ref:`lower-dlr`,
:ref:`bit-pct`, :ref:`chr-dlr`,
:ref:`upc-dlr`, :ref:`lwc-dlr`

--------------


..  _convert:

CONVERT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CONVERT src\_file,dst\_file,original$,replacement$               |
+----------+-------------------------------------------------------------------+
| Location |  CONVERT                                                          |
+----------+-------------------------------------------------------------------+

This command is used to copy src\_file to dest\_file and replace all
occurrences of original$ by replacement$.

Both strings must have the same length.

The search is case-independent.

No default devices are supported.

**Example 1**

Take a QUILL-document and export it using the 'Print to file' option
without a printer driver in the main drive.

Next VIEW it or look at it with an editor or by: COPY flp1\_example\_lis
TO scr.

You will see the character CHR$(13) (the carriage return <CR> character)
at the end of each line. This is not needed by QDOS to perform a
carriage return on screen. Remove these excess characters with: CONVERT
flp1\_example\_lis, flp1\_example\_txt, CHR$(13), " ".

<CR> at the end of lines may also appear when downloading messages from
a bulletin board or converting MS/DOS text files to QDOS.

**Example 2**

Badly written or simple programs generally lack the feature to change
device names for file operations. Using commands like FLP\_USE may have
a negative effect on any jobs which are running simultaneously, so it is
better to make the program use flp1\_ instead of mdv2\_.

This can be achieved quite simply with the command: CONVERT prog1\_exe,
prog2\_exe, "mdv2\_", "flp1\_".

**NOTE**

The character CHR$(0) cannot be replaced.

**CROSS-REFERENCE**

:ref:`exchg` is similar to
:ref:`convert`.

--------------


..  _copy:

COPY
====

+----------+--------------------------------------------------------------------+
| Syntax   || COPY file1 TO file2  or                                           |
|          || COPY [file] [TO file2] (Toolkit II)  or                           |
|          || COPY file1 [,file2 [,file3...]] {TO \| !} fileb (THOR XVI)        |
+----------+--------------------------------------------------------------------+
| Location || QL ROM, Toolkit II, THOR XVI                                      |
+----------+--------------------------------------------------------------------+

The command COPY duplicates file1, so that file2 is an exact copy. The
parameters can also be a device (eg. ser1, con, scr, scr\_400x20) or, if
you have Toolkit II installed, a channel (eg. #3) can be used for the
second parameter.

If Toolkit II is present, COPY supports the default devices and
sub-directories. COPY will look for the file to be copied on the default
data device if necessary (see DATAD$).

The rules for determining the destination parameter can be somewhat
complex under Toolkit II:

(1) If no device is given, but a filename is specified, then Toolkit II
looks at the first parameter. The destination device is then assumed to
be the same as the source device (ie. the device name specified as part
of the first parameter, or the default data device - see DATAD$).

Under SMS, it will use the default data device whether or not the first
parameter contains a device.

(2) If the second parameter is omitted, then again Toolkit II looks at
the first parameter. The same filename as for the first parameter will
be used. If a device is given in the first parameter, then this is used
as the destination device (unfortunately meaning that Toolkit II tries
to copy the file onto itself!). On the other hand, if no device was
specified, then the default destination device will be used (see
DESTD$).

Under SMS, if a device is specified in the first parameter, SMSQ/E
(v2.85 at least) tries to copy the file to the default destination
device without a filename! Normally unless the default destination
device is either PAR or SER, this will report an error 'is in use'.

(3) If a second parameter is given which includes a device name, then
this is used!

If the destination is an existing file, unlike the normal ROM COPY
command, Toolkit II will not break COPY with the error -8 (already
exists), but instead it will print: >file<exists, OK to overwrite..Y or
N? in channel #0 and wait for the user to press either <Y> or <N> -
<ESC> and <CTRL><SPACE> mean <N> here.

**Examples**

Assuming that the default data device is flp1\_ and the default
destination device is ram2\_ (using Toolkit II or SMS implementation):

+-------------------------------------+---------------------------------------------------------------------+
| Command                             | Effect                                                              |
+=====================================+=====================================================================+
| COPY mdv1\_quill TO flp1\_quill     | Copies mdv1\_quill to flp1\_quill                                   |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas, ram2\_tmp     | Copies ram1\_prog\_bas to ram2\_tmp                                 |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas, scr\_200x100  | Copies ram1\_prog\_bas to a window                                  |
+-------------------------------------+---------------------------------------------------------------------+
| COPY prog\_bas, ser1                | Copies flp1\_prog\_bas to ser1                                      |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ser2 TO ram1\_prog\_bas        | Copies data from ser2 to a file                                     |
+-------------------------------------+---------------------------------------------------------------------+
| COPY con TO ser                     | Copies everything typed to ser1                                     |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas                | Tries to copy ram1\_prog\_bas to itself unless on SMS               |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas                | Tries to copy ram1\_prog\_bas to ram2\_ and will report an error    |
+-------------------------------------+---------------------------------------------------------------------+
| COPY prog\_bas                      | Copies flp1\_prog\_bas to ram2\_prog\_bas                           |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas TO #2          | Copies ram1\_prog\_bas to a channel                                 |
+-------------------------------------+---------------------------------------------------------------------+

**NOTE 1**

The TO separator can be replaced by a comma ',' (although note the THOR
XVI variant!).

**NOTE 2**

Each file includes a file header of 64 bytes to store supple-mentary
information such as the time of the last update, file type, length and
much more. Without Toolkit II, COPY will always copy the header if a
file is copied. The Toolkit II COPY command does not copy the header to
serial devices (eg. ser) if this is specified as the destination.

**NOTE 3**

COPY without any parameters is allowed with Toolkit II, but it can cause
problems (at least in versions up to v2.28 Toolkit II and v2.85 SMS)

As an exception to rule 2, when first used it would appear to try to
copy the file "" on DATAD$ onto itself. On systems without level-2
drivers, such files can exist, but have no special function, whereas on
level-2 drivers, these files contain the sub-directories. Thus, with the
standard combination of Toolkit II and level-2 drivers installed, a pure
COPY normally breaks with error -9 (in use) (see FMAKE\_DIR for the
reason).

However, due to a bug in current versions of Toolkit II, when first used
it may report error -15 (bad parameter), in which case it will have left
the file flp1\_ open and prevent most of any further access to that
device (unless you can close the channel with CLOSE% or a desktop).

**NOTE 4**

On SMS pre v2.58, if you used COPY and were asked if you wanted to
overwrite the file, and answered N, an error code was returned.

**THOR XVI NOTES**

The THOR XVI (v6.41 and later) supports the third variant of COPY. This
allows you to merge several files:

COPY flp1\_texta,flp1\_textb TO flp2\_Book will create a new file
flp2\_Book made up of the merged files flp1\_texta and flp1\_textb. The
headers will (of course) not be copied.

If you alter the TO delimiter to !, ie: COPY flp1\_texta,flp1\_textb !
flp2\_Book

then it is assumed that fileb already exists and file1, file2 and file3
are all appended to it.

**CROSS-REFERENCE**

:ref:`spl-use` and
:ref:`dest-use` set the destination device.

See :ref:`copy-n` and
:ref:`copy-h` for copying file headers and
:ref:`copy-o` on how to force overwriting.

:ref:`spl` performs a background copy (ie. it
multitasks).

See :ref:`append` which is similar to the THOR
variant.

--------------


..  _copy-b:

COPY\_B
=======

+----------+-------------------------------------------------------------------+
| Syntax   || COPY\_B adr1, adr2, n or                                         |
|          || COPY\_B adr1, n TO adr2                                          |
+----------+-------------------------------------------------------------------+
| Location || BTool                                                            |
+----------+-------------------------------------------------------------------+

The command COPY\_B copies n bytes from the memory address adr1 to adr2
without any restrictions. The programmer has to ensure that there is
sufficient room at the specified destination memory location (which must
be free useable memory).

**Example**

::

    100 RANDOMISE: n=10
    110 a1=ALCHP(6*n): a2=ALCHP(6*n)
    120 FOR i=0 TO 6*(n-1) STEP 6: POKE_F a1+i,RND
    130 COPY_B a1,6*n TO a2
    140 FOR i=0 TO 6*(n-1) STEP 6: PRINT PEEK_F(a2+i)
    150 RECHP a1: RECHP a2

**CROSS-REFERENCE**

:ref:`copy-w`,
:ref:`copy-l`,
:ref:`ttpokem` and
:ref:`xchange`

--------------


..  _copy-h:

COPY\_H
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  COPY\_H [file1] [TO file2]                                       |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

See :ref:`copy-n`.

**CROSS-REFERENCE**

:ref:`fgeth-dlr`

--------------


..  _copy-l:

COPY\_L
=======

+----------+-------------------------------------------------------------------+
| Syntax   ||  COPY\_L adr1, adr2, n or                                        |
|          || COPY\_L adr1, n TO adr2                                          |
+----------+-------------------------------------------------------------------+
| Location ||  BTool                                                           |
+----------+-------------------------------------------------------------------+

The command COPY\_L copies n longwords (each being 4 bytes) from address
adr1 to adr2. The two memory locations can overlap (this is also true
for COPY\_B and COPY\_W).

If you are using Minerva, you will probably find it quicker to use it's
specialised CALL routines.

**Example**

::

    100 a=ALCHP(48*1024)
    110 COPY_L 0,12*1024 TO a

**NOTE**

Both adr1 and adr2 must be even addresses.

**CROSS-REFERENCE**

:ref:`copy-w`,
:ref:`copy-b`, :ref:`odd`.

--------------


..  _copy-n:

COPY\_N
=======

+----------+--------------------------------------------------------------------+
| Syntax   || COPY\_N file1 TO file2  or                                        |
|          || COPY\_N [file1] [TO file2] (Tooolkit II)  or                      |
|          || COPY\_N file1 [,file2 [,file3...]] {TO \| !} fileb (THOR XVI)     |
+----------+--------------------------------------------------------------------+
| Location || QL ROM, Toolkit II, THOR XVI                                      |
+----------+--------------------------------------------------------------------+


This command is basically the same as COPY, but the file header is
explicitly removed. This is important for example if you wish to copy a
file direct to a printer attached to ser2.

If the file header was also printed, this would include some
non-printable characters {eg. CHR$(0)}, which might be interpreted by
the printer as control characters and therefore produce rubbish as
output.

Toolkit II's COPY examines the type of the destination device before it
proceeds. It will not then copy the file header if this is a serial
device or a parallel port. The standard COPY command contained in the QL
ROM does not make this differentiation and so COPY\_N must be used
instead if the file header is not to be copied.

**CROSS-REFERENCE**

:ref:`copy-h` forces the file header to be copied
to the given destination (whether it is a serial port, a parallel port
or not), and the syntax is identical to :ref:`copy`,
:ref:`copy-n` and
:ref:`copy-o`.

--------------


..  _copy-o:

COPY\_O
=======

+----------+--------------------------------------------------------------------+
| Syntax   || COPY\_O [file1] [TO file2] or                                     |
|          || COPY\_O file1 [,file2 [,file3...]] {TO \| !} fileb (THOR XVI)     |
+----------+--------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                              |
+----------+--------------------------------------------------------------------+

The command COPY\_O is identical to Toolkit II's COPY command, but if
the file already exists, it will automatically be over-written without
asking the user for confirmation.

This command is also supported on the THOR XVI, although both the input
and destination channels must be specified in full.

**CROSS-REFERENCE**

:ref:`ftest` and :ref:`etat`
check the status of a file, thus enabling you to check if a file already
exists.

--------------


..  _copy-w:

COPY\_W
=======

+----------+-------------------------------------------------------------------+
| Syntax   || COPY\_W adr1, adr2, n         or                                 |
|          || COPY\_W adr1, n TO adr2                                          |
+----------+-------------------------------------------------------------------+
| Location || BTool                                                            |
+----------+-------------------------------------------------------------------+

The command COPY\_W copies n words (two bytes each) from address adr1 to
adr2.

**NOTE**

Both addresses must be even.

**CROSS-REFERENCE**

:ref:`copy-w` is always faster than
:ref:`copy-b`, but
:ref:`copy-l` is even faster than
:ref:`copy-w`.

See also :ref:`xchange`.

Minerva has its own fast copy routines (see
:ref:`call`).

--------------


..  _cos:

COS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  COS (radians)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function allows you to find the cosine of the specified angle
(given in radians).

In a right angled triangle the cosine is the ratio of the length of the
side adjoining the given angle, to the length of the hypotenuse (or the
sine of the complement of that angle). Thus, sine and cosine can
actually substitute each other:

+------------------------+----------------------+
| Mathematical formula   | In SuperBASIC        |
+========================+======================+
| cos x = sin (π/2-x)    | COS(x)=SIN(PI/2-x)   |
+------------------------+----------------------+
| sin x = cos (π/2-x)    | SIN(x)=COS(PI/2-x)   |
+------------------------+----------------------+

**Example**

An analogue clock:

::

    100 wx = 50: wy = INT(wx / 1.25): px = 50: py = 40
    110 OPEN#3,"scr_" & wx & "x" & wy & "a" & px & "x" & py
    120 PAPER#3,3: CLS#3: BORDER#3,1,0: SCALE#3,100,-45,-50
    130 INK#3,0: FILL#3,1: CIRCLE#3,0,0,40:FILL#3,0: INK#3,4
    135 Hs = PI/6
    140 FOR t = 1 TO 12
    150  LINE#3,40 * SIN(Hs * t), 40 * COS(Hs * t) TO 45 * SIN(Hs * t), 45 * COS(Hs * t)
    160 END FOR t
    170 INK #3, 7
    180 d$ = DATE$: min = d$(16 TO 17)
    190 hour = d$(13 TO 14) MOD 12 + min / 60
    200 LINE#3,0,0 TO 30 * SIN(Hs * hour), 30 * COS(Hs * hour)
    210 LINE#3,0,0 TO 40 * SIN(PI / 30 * min), 40 * COS(PI / 30 * min)
    220 PAUSE 100: CLOSE #3

**NOTE 1**

COS with very large values for the angle produces either very odd
results or an overflow error (except on Minerva v1.96+ where it returns
0). The correct range for radians is -PI...PI, because anything outside
this range is actually merely a repeat of the series. This is because an
angle of PI\*2 radians forms a complete circle, therefore an angle of
PI\*3 is actually the same as an angle of PI (ie. PI\*3-PI\*2). If you
insist on using these silly angles, try SIN (X+PI/2) instead of COS(X).

**NOTE 2**

The THOR XVI (v6.41) fixes a slight inaccuracy in this command to ensure
that COS(PI/2)=0. On other ROMs COS(PI/2)==0.

The Lightning package and SMS also fix this bug.

**CROSS-REFERENCE**

See :ref:`sin`, :ref:`acos`.

Compare :ref:`cosh`.

Please also see the Mathematics section of the Appendix.

--------------


..  _cosh:

COSH
====

+----------+-------------------------------------------------------------------+
| Syntax   |  COSH (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Hyper, Hyperbola                                                 |
+----------+-------------------------------------------------------------------+

This function is defined very similarly to SINH. It can be expressed as:

( EXP(x) + EXP(-x) ) / 2

**Example**

The COSH function can be used to describe a rope, chain or similar
object which has two ends tied at the same height to a ceiling (for
instance). Line 110 draws the ceiling, lines 120 to 160 the chain.

::

    100 a = .8: SCALE 10, -5, 0: CLS
    110 LINE -2,CHAIN(-2) TO 2,CHAIN(2)
    120 FOR x = -2 TO 2 STEP .1
    130   y = CHAIN(x)
    140   IF x > -2 THEN LINE _x, _y TO x, y
    150   _x = x: _y = y
    160 END FOR x
    170 :
    180 DEFine FuNction CHAIN(x)
    190  RETurn a * COSH(x/a)
    200 END DEFine CHAIN

**CROSS-REFERENCE**

See :ref:`sinh` for an example.

:ref:`arcosh` is the inverse function of
:ref:`cosh`.

--------------


..  _cot:

COT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  COT (angle)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the cotangent of a given angle (specified in
radians).

In a right angled triangle the cotangent of an angle is defined as the
ratio of the side adjoining the given angle to the side opposite to the
given angle (forming a right angle with the other line). Due to the
periodic nature of the function, it is best to work with angle in the
range: 0 < angle < PI.

COT(angle) can also be calculated as COS(angle)/SIN(angle).

**Example**

A program to create a graph showing the range of the function COT:

::

    100 MODE 4: OPEN#1,con_448x200a32x16
    110 SCALE 100,-75,-50
    120 INK 4: LINE -75,0 TO 125,0: LINE 0,-50 TO 0,50
    130 CURSOR 0,0,0,0: PRINT '0'
    140 CURSOR 0,0,-100,0: PRINT '-ã'
    150 CURSOR 0,0,100,0: PRINT 'ã'
    160 CURSOR 0,0,-200,0: PRINT '-ã * 2'
    170 CURSOR 0,0,200,0: PRINT '2ã'
    180 CURSOR 0,0,0,-100: PRINT '1'
    190 CURSOR 0,0,0,90: PRINT '-1'
    200 INK 7
    210 FOR ang=-(PI*2)+1E-2 TO PI*2 STEP 1E-2
    220   POINT ang*75/(PI*2),50*COT(ang)
    230 END FOR ang

**NOTE 1**

Although COT(PI) and COT(PI\*x) should be undefined (values of angle
very close to PI tend to infinity), on most QDOS implementations, it
gives a very large positive or negative number.

Currently, only the Lightning maths package and SMS produce an overflow
error (the correct result).

**NOTE 2**

On Minerva v1.96+ very large values of angle will return the value 0. On
other implementations produce an overflow error.

**NOTE 3**

COT(0) on most ROMs gives 1 - this is fixed on Minerva, SMS, Lightning,
QXL, and ST/QL which give an overflow error.

**NOTE 4**

COT(PI/2) should equal zero - on all implementations of this command,
this returns a number near to zero (except under SMS).

**CROSS-REFERENCE**

Please refer to\ :ref:`acot`,
:ref:`atan`, :ref:`tan`.

Compare :ref:`coth`.

Also refer to the Mathematics section of the Appendix.

--------------


..  _coth:

COTH
====

+----------+-------------------------------------------------------------------+
| Syntax   |  COTH (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

This function returns the hyperbolic co-tangent.

This is defined as one divided by the hyperbolic tangent, so COTH(x) =
1/TANH(x).

**CROSS-REFERENCE**

:ref:`arcoth` is the inverse function of
:ref:`coth`.

--------------


..  _csize:

CSIZE
=====

+----------+-------------------------------------------------------------------+
| Syntax   | CSIZE [#channel,] width, height                                   |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+

This command sets the size and spacing of characters in the given
channel (default #1).

Width ranges from 0 to 3 and there are two possible heights, 0 and 1.
Each width and height corresponds to a certain pixel size:

+-------+---------+------+--------+---------+------+
| Width | Spacing | Size | Height | Spacing | Size |
+=======+=========+======+========+=========+======+
|   0   |    6    |   5  |   0    |   10    |   9  |
+-------+---------+------+--------+---------+------+
|   1   |    8    |   5  |   1    |   20    |  18  |
+-------+---------+------+--------+---------+------+
|   2   |   12    |  10  |                         |
+-------+---------+------+                         |
|   3   |   16    |  10  |                         |
+-------+---------+------+--------+---------+------+

In low resolution mode width 0 and 1 have no effect: in that mode, the
smallest character size allowable is 12 pixels wide; CSIZE 2,0.

**NOTE 1**

On pre-JS ROMs, characters which use all eight pixels available for the
definition of characters will not be printed correctly on screen. Even
on JS and MG ROMs, problems exist in some character sizes. Minerva, SMS
and the ST/QL drivers (Level E-23 onwards) prevent any such problems.

**NOTE 2**

The THOR XVI allows you to use any value for the vertical size - odd
values give double height characters and even values give normal height.

**CROSS-REFERENCE**

:ref:`char-inc` allows you to change spacing
independently of character size.

:ref:`mode` will reset the character size to the
default (ie. 2,0 in :ref:`mode` 8 and 0,0 in
:ref:`mode` 4).

The command :ref:`at` is also affected by the current
character spacing.

--------------


..  _ctab-dlr:

CTAB$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CTAB$ (string$ [,tabdist]) tabdist=1..255                        |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

CTAB$ is a function which will look for spaces in the supplied string$
and if there is at least a tabdist number of spaces, they will be
replaced by the TAB character, CHR$(9), so that ETAB$ or editors /
word-processors can re-expand them to the original string.

CTAB$ does not alter the actual string$ but will return it in its
compressed form.

The default value of tabdist is 8, and the length of string$ is limited
to 255 characters (so tabdist>255 does not make much sense).

**WARNING**

tabdist=0 will produce rubbish output and it is also possible that CTAB$
will crash the system. Negative values lead to nonsense results but do
not harm the system.

**CROSS-REFERENCE**

:ref:`etab-dlr` expands the TAB marks.

--------------


..  _cur:

CUR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CUR [#channel,] boolean                                          |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Every Window channel has a cursor which flashes when it is switched on
and appears solid when it is inactive.

The command CUR with boolean=1 activates the cursor of a window, and it
is de-activated with boolean=0. The default channel is #1.

**Example**

Multitasking programs should use INKEY$ to read keystrokes from the
keyboard if no other job is to be similarly affected by the keys
pressed. KEYROW could be used, but this does not care which
job/channel/window was active when a key was pressed (this could be used
to give a background job a command without leaving the current job).

The following function imitates the getchar() function of the C
language, and is used for non-interactive keyboard input. Arcade games
should not engage the cursor!

::

    100 DEFine FuNction GETCHAR% (channel,timeout)
    110  LOCal char$
    120  CUR#channel,1
    130  char$=INKEY$(#channel,timeout)
    140  CUR#channel,0
    150  RETurn CODE(char$)
    160 END DEFine GETCHAR%

**NOTE**

Although the cursor was activated, it will not flash until the channel
is made into the current keyboard input queue (ie. when it can use PEND,
EOF, INKEY$). This may therefore mean that the keys <CTRL><C> will need
to be pressed to make this program the active (current) task.

Non-console windows (scr\_) cannot be used for input operations (ie.
INPUT and INKEY$ cannot be used), nevertheless, the cursor may still be
enabled.

INPUT will activate and de-activate the cursor itself.

**CROSS-REFERENCE**

See :ref:`force-type` concerning current input
queue activation, :ref:`inkey-dlr`,
:ref:`input` and :ref:`keyrow`
for general information.

:ref:`cursen` and
:ref:`curdis` are both combined by the
:ref:`cur` command.
:ref:`cursor-pct`.

--------------


..  _curdis:

CURDIS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CURDIS [#ch]                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, QSOUND                                     |
+----------+-------------------------------------------------------------------+

This command disables the cursor in the given channel. See CURSEN!

The default window for this command is #1.

If a cursor is disabled in a given window (or does not exist), task
switching with <CTRL><C> to the job which owns that window will not work
unless the Pointer Environment is present.

**WARNING**

Do not use CURDIS #0 as this may prevent further input.

**CROSS-REFERENCE**

See :ref:`cursen` for more details.

:ref:`cursor-off` is similar.

--------------


..  _cursen:

CURSEN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CURSEN [#ch]                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, QSOUND                                     |
+----------+-------------------------------------------------------------------+

If a program is to multitask without the assistance of the Pointer
Interface, it is necessary to give that program an active cursor so that
the user can switch to the program using the key <CTRL><C>, which alters
the active keyboard queue.

Unless a program has an active cursor, it cannot accept input from the
keyboard by the use of commands such as PAUSE, INKEY$ and INPUT.

The command CURSEN enables the cursor in the given channel, which must
be either a scr or con channel. If no channel is specified, the default
is #1.

Once the cursor is enabled, a red block will appear at the current text
cursor position in the given channel. This block will begin to flash
when the cursor is 'active' (ie. expecting input).

**MINERVA NOTE**

Minerva's System Xtensions allow you to alter the attributes of the text
cursor, by using the command POKE !124!51,x where x is in the format of:
RRRRSCCC, where the top 4 bits of x (RRRR) determine the cursor flash
rate, the bottom three bits (CCC) determine the colour of the cursor and
the fourth bit (S) determines whether the cursor appears as a solid
block or an underline.

You can actually get an invisible cursor by using the command POKE
!124!51,0. Unfortunately though, this sets the cursor attributes for all
cursors which are enabled, rather than just for the current Job.

**CROSS-REFERENCE**

:ref:`keyrow` reads keys without an active cursor.
See :ref:`curdis` also.

--------------


..  _cursor:

CURSOR
======

+----------+--------------------------------------------------------------------+
| Syntax   || CURSOR [#channel,] [grx, gry,] x,y or                             |
|          || CURSOR [#channel,] flag (Btool only)                              |
+----------+--------------------------------------------------------------------+
| Location || QL ROM, Btool                                                     |
+----------+--------------------------------------------------------------------+


The CURSOR command allows you to set the text cursor to a specific
position in the given window (default #1). Any text which is then
printed will appear with the given position at its top left corner.

The values x and y specify the position in pixel co-ordinates relative
to the origin of the specified window (eg. if the window #1 was defined
as scr\_448x200a32x16, the command CURSOR 224,100 will set the text
position to the exact centre of the window).

However, for the more adventurous, CURSOR can take an additional two
parameters which allow you to mix text and graphics on a given window
more easily. This sets the text cursor to the graphics co-ordinate
(grx,gry) and then uses the x and y parameters to specify a relative
pixel offset from this graphics co-ordinate (a positive value of x moves
the text cursor to the right, a negative value to the left; whereas a
positive value of y moves the text cursor down, a negative value up).

The second variant only works with the Btool Toolkit. This allows you to
enable or disable the cursor in the specified window (default #1), by
specifying a flag of 1 to enable the cursor or 0 to disable the cursor.

**Example**

This program shows all the 45 degree angles in a circle:

::

    100 MODE 4:WINDOW 448,200,32,16
    110 PAPER 0:INK 7:CLS
    120 SCALE 200,-150,-100
    130 FOR i=0 TO 315 STEP 45
    140   INK 7:LINE 0,0 TO SIN(RAD(i))*50,COS(RAD(i))*50
    150   xoff=0:yoff=0
    160   SELect ON i
    170     =0:xoff=-4:yoff=-9
    180     =45:yoff=-9
    190     =90:yoff=-4
    200     =180:xoff=-10
    210     =225:xoff=-20
    220     =270:xoff=-20:yoff=-4
    230     =315:xoff=-20:yoff=-9
    240   END SELect
    250   INK 4:CURSOR SIN(RAD(i))*50,COS(RAD(i))*50,xoff,yoff
    260   PRINT i
    270 END FOR i

**NOTE 1**

On pre MG ROMs, the CURSOR command only allows a maximum of four
parameters, which means that you can only use grx, gry, x and y on the
default channel. You can however use commands such as CURSOR #3,200,40,3
- although this is not supported on Minerva (pre v1.98) and SMSQ/E and
should be avoided! If you specify a fifth parameter, a 'Bad Parameter'
error will be reported. The Btool variant fixes this as does SMS, MG
ROMs and Minerva. Compiling with Q-Liberator does not prevent this
error.

**NOTE 2**

The graphics positioning did not work on ST/QL Emulators with Drivers
prior to Level D-15 (or E-15).

**NOTE 3**

Compilers will not accept the second syntax.

**NOTE 4**

As from SMS v2.74 CURSOR limits grx to even positions to make in
compatible with MODE 8 and MODE 4 automatically.

**CROSS-REFERENCE**

Please refer to :ref:`print`,
:ref:`left` and :ref:`at`.

:ref:`cursen` is a more compatible means of
enabling a cursor.

--------------


..  _cursor-pct:

CURSOR%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CURSOR% [#window]                                                |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns the current status of the text cursor in the
specified window (default #1). Results are:

-  0 for disabled,
-  1 for enabled and visible,
-  -1 for enabled but invisible.

An active cursor flashes, and therefore alternates between visible and
invisible status when enabled. Otherwise, it will appear as a solid
block on screen (unless there is no cursor attached to the specified
channel).

On Minerva it is possible to alter the shape and colour of the cursor.

**CROSS-REFERENCE**

:ref:`cursen`, :ref:`curdis`,
:ref:`cursor` and :ref:`cur`
enable or disable the cursor.

Also refer to :ref:`cursor-off` and
:ref:`cursor-on`.

--------------


..  _cursor-off:

CURSOR\_OFF
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CURSOR\_OFF [#ch]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is exactly the same as CURDIS.

--------------


..  _cursor-on:

CURSOR\_ON
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CURSOR\_ON [#ch [!] ]                                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is very similar to CURSEN, with the default window being
#1.

However, you can add an exclamation mark after the channel number. If
this is omitted, then upon execution of this command the chosen window
is automatically selected as the active window (where key input is
directed). Add the exclamation mark to prevent this.

**CROSS-REFERENCE**

See :ref:`cursor-off`,
:ref:`cursen` and
:ref:`cursor-pct` for more details.

--------------


..  _cvf:

CVF
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CVF (mkf\_$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function takes any six character long string, (the internal format
of a floating point number), and returns the value as a floating point
number.

**WARNING**

CVF locks SuperBASIC if the supplied parameter is six bytes long but not
a valid representation of a floating point number, eg. CVF("BlaBla").

MKF$ always returns a valid parameter for CVF which will not crash it.

**CROSS-REFERENCE**

:ref:`peek-f`, :ref:`mkf-dlr`,
:ref:`cvi-pct`, :ref:`cvl`,
:ref:`cvs-dlr`.

:ref:`fputf` and :ref:`fgetf`
enable you to read and write floating point numbers in internal format
to or from files.

--------------


..  _cvi-pct:

CVI%
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CVI% (mki\_$)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

CVI% is the inverse function of MKI$ and expects a two character long
string, being the internal representation of an integer, and then
converts this into the actual integer number.

**Example**

MKI$( 20812 )="QL"

CVI%("QL")=20812

**CROSS-REFERENCE**

:ref:`mki-dlr`, :ref:`cvl`,
:ref:`cvf`, :ref:`cvs-dlr`.

:ref:`fget-pct` and :ref:`fput-pct`
provide similar facilities for writing and reading integers in their
internal format from files.

--------------


..  _cvs-dlr:

CVS$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CVS$ (mks\_$)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function takes the internal representation of a string and returns
the string concerned.

A string is represented internally as a word containing the length of
the string followed by the string itself.

**Example**

CVS$( CHR$(0) & CHR$(2) & "Test" ) = "Test"(1 TO 2) = "Te"

**CROSS-REFERENCE**

:ref:`mks-dlr`, :ref:`cvi-pct`,
:ref:`cvl`, :ref:`cvf`.
:ref:`fput-dlr` and :ref:`fget-dlr`
enable you to write strings to and read strings from files in their
internal formats.

--------------


..  _cvl:

CVL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CVL (mkl\_$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function converts the internal representation of a long integer
number (a four character long string) to the actual value and returns
that. CVL is the inverse of MKL$.

**Example**

CVL( MKL$( 10010 ) = "10010"

**CROSS-REFERENCE**

:ref:`mkl-dlr`, :ref:`cvi-pct`,
:ref:`cvf`, :ref:`cvs-dlr`.

:ref:`fputl` and :ref:`fgetl`
provide similar facilities to enable you to write and read long integers
from files in their internal format.

