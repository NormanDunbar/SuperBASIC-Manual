
==========
Keywords R
==========

TODO
====

- :ref:`rom` has a ROM\_TEST reference, but is not found in this file.
- :ref:`rmar` has an ESC reference, but is not found.
- :resfast` has a reference to FASTFREE which is not found.


..  _rad:

RAD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RAD (angle)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function is used to convert an angle in degrees into an angle in
radians (which is the system used by QDOS to represent angles in
commands such as SIN, COS, TAN, etc.). Although this will work for any
value of angle, due to the very nature of angles, angle should be in the
range 0..360, which will return a value in the range 0..2Pi.

**Example**

A small program to draw a circle split into 30 degree segments:: 

    100 MODE 4:WINDOW 448,200,32,16:SCALE 100,0,0 
    110 STRIP 2:INK 7 
    120 x1=75:y1=50:x2=x1:y2=y1+25 
    130 CIRCLE x1,y1,25 
    140 FOR x=0 TO 360/30-1 
    150   x2=x1+SIN(RAD(30)*x)*25:y2=y1+COS(RAD(30)*x)*25 
    160   LINE x1,y1 TO x2,y2 
    170 END FOR x

**CROSS-REFERENCE**

See :ref:`deg`, :ref:`sin`,
:ref:`cos`. Also please refer to the Mathematics
section of the Appendix.

--------------


..  _rae:

RAE
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RAE (i,n)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function RAE returns the value of: i/(((1+i)\ :sup:`1/n`\ ) -1)
\*n )
where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`vfr`, :ref:`var`,
:ref:`tca`, :ref:`tnc`,
:ref:`tee`, :ref:`rafe`

--------------


..  _rafe:

RAFE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  RAFE (i,n)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function RAFE returns the value of (((1+i)\ :sup:`(1/n-1)` \* n )/i
where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`vfr`, :ref:`var`,
:ref:`tca`, :ref:`tnc`,
:ref:`tee`, :ref:`rae`

--------------


..  _ramtop:

RAMTOP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RAMTOP                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

The function returns the active memory in KBytes, whether this is free
memory or not. On the original QL without any expansion this function
will return 128, whereas on a QL expanded to 640K, 640 is returned.

**CROSS-REFERENCE**

The value of :ref:`ramtop` can be lowered with
:ref:`reset` to emulate a machine which has less
available memory.

:ref:`print`\ (PHYSTOP/1024)-128
gives the value of the additional memory.

:ref:`free-mem` and :ref:`free` return the actually available
memory.

--------------


..  _ram-use:

RAM\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  RAM\_USE [device]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Trump Card, Gold Card, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

This command is the same as FLP\_USE except that it alters the name of
the device used to access the ramdisks.

**NOTE**

device must only be three letters long.

**CROSS-REFERENCE**

See :ref:`flp-use`.

--------------


..  _rand:

RAND
====

+----------+-------------------------------------------------------------------+
| Syntax   || RAND (devicename)  or                                            |
|          || RAND (device$)                                                   |
+----------+-------------------------------------------------------------------+
| Location || TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Every physical directory device (eg. floppies and microdrives, but not
RAM disks), contain a random number in their FAT (which is a place on
the medium which contains internal data, the number of free/bad/empty
sectors etc). The function RAND returns this number which can be used by
QDOS to check if a medium has been changed.

**NOTE**

QDOS increases access speed by temporarily storing data in so-called
slave blocks. On QDOS and compatible machines this may lead to the
phenomen that RAND only returns the correct value the first time that it
is used, and then returns the same value for any other medium. This can
be avoided by using the command DEL\_DEFB, or better CLRMDV before each
RAND.

**CROSS-REFERENCE**

:ref:`fop-dir` opens a directory.
:ref:`flp-sec` allows you to alter the amount of
checking carried out by a disk interface to see if a disk has been
swapped.

--------------


..  _randomise:

RANDOMISE
=========

+----------+-------------------------------------------------------------------+
| Syntax   || RANDOMISE [(start)] or                                           |
|          || RANDOMISE \\ (Minerva v1.82+ only)                               |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

SuperBASIC uses a standard method to generate pseudo random numbers.

Each time that the function RND is called, a start value specified by
the command RANDOMISE is multiplied by a large number and another number
is added, the solution is modulated and the final number is nearly
unpredictable. 

This method means that after a RANDOMISE command with
parameter, RND will always generate the same numbers. If you pick
another number as the parameter (or do not specify a parameter at all),
this will let RND produce other numbers. If no parameter is specified,
RANDOMISE calculates a random number by combining some internal system
data such as the time, date, pointers etc.

**Example**

::

    100 RANDOMISE 38 
    110 FOR n=1 TO 10: PRINT RND(10)

The program will always write the same ten random numbers on the
screen.

**MINERVA NOTE**

The main problem with using RANDOMISE is that even without a parameter,
the same pattern of 'random' numbers is generated if the interval
between when the computer is switched on and when the line containing
RANDOMISE is reached tends to be the same every time that a program is
run. Although v2.53+ of SMS makes RANDOMISE without a parameter more
random, the only other fix is on v1.82+ of Minerva which allows you to
use:: 

    RANDOMISE \
    
instead of the normal RANDOMISE which should alleviate this problem
somewhat.

**CROSS-REFERENCE**

:ref:`rnd` is the function that returns a random
number. :ref:`randomise` influences
:ref:`matrnd` in the same way.

--------------


..  _read:

READ
====

+----------+-------------------------------------------------------------------+
| Syntax   |  READ var\ :sup:`1` :sup:`\*`\ [var\ :sup:`i`]\ :sup:`\*`         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command forces the interpreter to look at the current data
pointer, that is to say the next program line which begins with the
marker DATA. 

When a program is *first* RUN, the data pointer is set to the
start of the program, and hence READ will attempt to assign the first
value following the first occurrence of DATA to the specified variable.
Having assigned this value, the data pointer is updated to the next
value in the same DATA statement, or the next program line if there are
no more values following the DATA statement. 

If no more DATA is
contained within the program and you try to READ a value, the error 'End
of File' is reported. SMS's improved interpreter reports 'End of DATA'.

**Example**

A simple program to convert the three letter code returned by DAY$ into
the full name of the day:: 

    100 DATA 'Monday','Tuesday','Wednesday','Thursday' 
    110 DATA 'Friday','Saturday','Sunday' 
    120 RESTORE 
    130 dday$=DAY$ 
    135 day=(dday$ INSTR ' MonTueWedThuFriSatSun')/3 
    140 FOR find_day=1 TO day 
    150   IF EOF:EXIT find_day 
    160   READ dday$ 
    170 END FOR find_day 
    180 PRINT dday$

**NOTE 1**

The data pointer is not reset to the start of the program following
every RUN. You need a RESTORE command to do this - try running the above
program without line 120.

**NOTE 2**

If you try to READ a value into a slice of an undimensioned string, the
value will not be stored and SuperBASIC may stop without a message, eg::

    100 DATA 'Bess ' 
    110 a$='Hello World' 
    120 READ a$(7 TO) 
    130 PRINT a$

Try by way of comparison, adding the line::

    10 DIM a$(12)

Both of these work under SMS.

**NOTE 3**

The interpreter does not really check the parameters listed after READ,
and unacceptable parameters, for example::

    READ 1
    
won't report an error and the program continues as if it had read a
variable. SMS's improved Interpreter reports 'Unacceptable Parameters
for READ' when the program is RUN.

**MINERVA NOTE**

As from v1.96, READ has been improved so that it will accept an array
parameter and then read a value for each element of the array in turn,
without having to put READ into a loop.

**Example**

::

    100 DIM x(5) 
    110 READ x 
    120 :
    1000 DATA 1,2,3,4,5,6


This will read x(0), x(1), x(2), x(3), x(4) and x(5)

All other implementations insist upon you using something akin to:: 

    100 DIM x(5) 
    110 FOR i=0 TO 5:READ x(i) 
    120 :
    1000 DATA 1,2,3,4,5,6

**CROSS-REFERENCE**

:ref:`restore` allows you to alter the program
line pointed at by the data pointer. :ref:`data` sets
out lines to be :ref:`read`.
:ref:`eof` allows you to test for the end of all
program data.

--------------



..  _read-header:

READ\_HEADER
============

+----------+-------------------------------------------------------------------+
| Syntax   | error = READ\_HEADER(#channel, buffer)                            |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The file that is opened on the given channel has its header data read into memory starting at the given address (buffer). The buffer address must have been reserved using :ref:`reserve-heap`, or some similar command.  

The buffer must be at least 64 bytes long or unpredictable results will occur. The function will read the header but any memory beyond the end of the buffer will be overwritten if the buffer is too short. After a successful call to this function, the contents of the buffer will be as follows :

+---------------+-----------------+------------------------------------------+
| Address       | Value           | Size                                     |
+===============+=================+==========================================+
| Buffer + 0    | File length     | 4 bytes long (see :ref:`file-length`)    |
+---------------+-----------------+------------------------------------------+
| Buffer + 4    | File access     | 1 byte long - currently zero             |
+---------------+-----------------+------------------------------------------+
| Buffer + 5    | File type       | 1 byte long  (see :ref:`file-type`)      |
+---------------+-----------------+------------------------------------------+
| Buffer + 6    | File dataspace  | 4 bytes long (see :ref:`file-dataspace`) |
+---------------+-----------------+------------------------------------------+
| Buffer + 10   | Unused          | 4 bytes long                             |
+---------------+-----------------+------------------------------------------+
| Buffer + 14   | Name length     | 2 bytes long, size of filename           |
+---------------+-----------------+------------------------------------------+
| Buffer + 16   | Filename        | 36 bytes long                            |
+---------------+-----------------+------------------------------------------+

Directory devices also have the following additional data :

+---------------+-----------------+------------------------------------------+
| Address       | Value           | Size                                     |
+===============+=================+==========================================+
| Buffer + 52   | Update date     | 4 bytes long (see :ref:`file-update`)    |
+---------------+-----------------+------------------------------------------+
| Buffer + 56   | Reference date  | 4 bytes long - see below                 |
+---------------+-----------------+------------------------------------------+
| Buffer + 60   | Backup date     | 4 bytes long (see :ref:`file-backup`)    |
+---------------+-----------------+------------------------------------------+

Miracle Systems hard disc's users and level 2 users will find the files version number stored as the the 2 bytes starting at buffer + 56, the remaining 2 bytes of the reference date seem to be hex 094A or decimal 2378 which has no apparent meaning, this of course may change at some point!

This function returns an error code if something went wrong while attempting to read the file header or zero if everything  went ok.  It can be used as a more efficient method of finding out the details for a particular file rather than calling all the various FILE_XXX functions. Each of these call the READ\_HEADER routine.

To extract data, use :ref:`peek` for byte values, :ref:`peek-w` for the filename length and version number (if level 2 drivers are present, see LEVEL2), or :ref:`peek-l` to extract 4 byte data items.

The filename can be extracted from the buffer by something like::

    f$ = PEEK_STRING(buffer + 16, PEEK_W(buffer + 14)).

**EXAMPLE**
The following example allows you to change the current dataspace requirements for an :ref:`exec`\ utable file::

    6445 DEFine PROCedure ALTER_DATASPACE
    6450   LOCal base, loop, f$, ft, nv
    6455   base = RESERVE_HEAP (64)
    6460   IF base < 0 THEN 
    6465     PRINT "ERROR: " & base & ", reserving heap space."
    6470     RETurn 
    6475   END IF 
    6480   REPeat loop
    6485     INPUT'Enter filename:';f$
    6490     IF f$ = '' THEN EXIT loop
    6495     ft = FILE_TYPE(f$)
    6500     IF ft < 0 THEN 
    6465       PRINT "ERROR: " & ft & ", reading file type for " & f$ & "."
    6510     END IF 
    6515     IF ft <> 1 THEN 
    6520       PRINT f$ & 'is not an executable file!'
    6525       NEXT loop
    6530     END IF 
    6535     PRINT 'Current dataspace is:'; FILE_DATASPACE(f$)
    6540     INPUT 'Enter new value:'; nv
    6545     OPEN #3,f$ : fer = READ_HEADER (#3,base)
    6550     IF fer < 0 : CLOSE #3 : PRINT "READ_HEADER error: " & fer : NEXT loop
    6555     POKE_L base + 6,nv
    6560     fer = SET_HEADER(#3,base)
    6565     IF fer < 0 : PRINT "SET_HEADER error: " & fer
    6570     CLOSE #3
    6575   END REPeat loop
    6580   RELEASE_HEAP base
    6585 END DEFine ALTER_DATASPACE


**CROSS-REFERENCE**

:ref:`set-header`, :ref:`file-length`,
:ref:`file-type`, :ref:`file-dataspace`,
:ref:`file-update`, :ref:`file-backup`.


-------


..  _rechp:

RECHP
=====

+----------+----------------------------------------------------------------------------------+
| Syntax   || RECHP address  or                                                               |
|          || RECHP address\ :sup:`1` :sup:`\*`\ [,address\ :sup:`i`]\ :sup:`\*` (BTool only) |
+----------+----------------------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI, BTool                                                     |
+----------+----------------------------------------------------------------------------------+

The common heap is an area in memory where all programs may store data,
this space being only limited by the memory available. A BASIC program
can reserve space in the common heap with the function ALCHP. 

The command RECHP allows you to recover this memory. The parameter of RECHP
must be the address which was returned by ALCHP. The Btool variant of
this command allows you to recover several addresses at once.

**Example**

Loading a title screen:: 

    100 Title$="FLP1_TITLE_SCR" 
    110 IF FREE_MEM < 38*1024 THEN 
    120   LBYTES Title$,SCREEN 
    130 ELSE 
    140   TitleAdr=ALCHP(32768) 
    150   LBYTES Title$,TitleAdr 
    160   SCRBASE TitleAdr: REFRESH 
    170   RECHP TitleAdr 
    180 END IF

**NOTE**

RECHP reports error -15 if the address was not reserved with ALCHP or if
the memory has already been given back to QDOS.

**CROSS-REFERENCE**

:ref:`clchp` clears all memory reserved by
:ref:`alchp`, :ref:`clear`
deletes the values of all variables. See also
:ref:`discard`, :ref:`ttrel`
and :ref:`release`.

--------------


..  _recol:

RECOL
=====

+----------+---------------------------------------------------------------------------+
| Syntax   || RECOL [#ch,] black,blue,red,magenta,green,cyan,yellow,white (MODE 8)  or |
|          || RECOL [#ch,] black,1,red,3,green,5,white,white (MODE 4)                  |
+----------+---------------------------------------------------------------------------+
| Location || QL ROM                                                                   |
+----------+---------------------------------------------------------------------------+

This command recolours all individual pixels in the specified window
(default #1). 

At least eight parameters must be specified, representing
each of the colours available in MODE 8. 

Each parameter must then have a
value in the range 0..8 representing how that colour pixel is to be
recoloured. 

The rather odd syntax for use in MODE 4 is due to a slight
apparent bug in the RECOL command which means that on some
implementations the parameter which would normally represent the colour
to replace yellow on screen has to be used to specify the colour to
replace white.

**Example**

A simple demonstration program which recolours a circle randomnly:: 

    100 WINDOW 448,200,32,16 
    110 PAPER 0:CLS:INK 7 
    120 SCALE 100,0,0 
    130 REPeat loop 
    140   CIRCLE 75,50,20 
    150   new_col=RND(1 TO 6) 
    160   RECOL 0,1,2,3,4,5,6,new_col 
    170 END REPeat loop  

Note how this only works in MODE 8 (except on SMS): to get it to work 
in MODE 4, you would need to alter line 160 to::

    160 RECOL 0,1,2,3,4,5,new_col,new_col

**NOTE 1**

Do not forget that the value of each parameter is taken to be the new
colour, therefore if RECOL is to have no effect at all, you will need to
use::

    RECOL 0,1,2,3,4,5,6,7
    
and not::

    RECOL 0,0,0,0,0,0,0,0
    
as you might at first think (the latter turns the whole window to
black!).

**NOTE 2**

This command did not work on ST/QL Emulators prior to Level D-05
drivers.

**CROSS-REFERENCE**

:ref:`ink`, :ref:`fill` See also
:ref:`w-swop`,
:ref:`set-red` and
:ref:`set-green`.

--------------


..  _refresh:

REFRESH
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  REFRESH                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

This command forces the whole screen pointed to by SCRBASE to be copied
onto the visible part of memory.

**NOTE**

REFRESH assumes 512x256 pixel resolution, the screen base is always
assumed at $20000.

**CROSS-REFERENCE**

See also :ref:`scrbase`,
:ref:`sclr`, :ref:`plot` and
:ref:`draw`. See also
:ref:`w-show`.

--------------


..  _release:

RELEASE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELEASE address                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command allows you to return a section of memory reserved by GRAB
to QDOS.

**NOTE**

LOAD, CLEAR, NEW and similar commands do not free GRABbed memory (unlike
memory reserved with ALCHP).

**WARNING**

Never free memory where extensions, device drivers or other code have
been loaded and started (for example with CALL) because the operating
system will continue to update these routines regularly and find code
which may have been overwritten by other programs, internal data etc.
Crash!

**CROSS-REFERENCE**

:ref:`rechp` and :ref:`clchp`
clear memory allocated with :ref:`alchp`.
:ref:`discard` releases memory allocated with
:ref:`reserve`. See also the other version of
:ref:`release`.

--------------


RELEASE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELEASE nr                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, QSound                                                    |
+----------+-------------------------------------------------------------------+

RELEASE activates the enhanced sound capabilities of the ST/QL (or the
QSound interface which has now been out of production for some years). A
sequence which has been previously stored with PLAY under the number nr
is 'executed' by RELEASE.

**CROSS-REFERENCE**

:ref:`play`, :ref:`snd-ext`
Beware the other version of :ref:`release`.

--------------


..  _release-heap:

RELEASE\_HEAP
=============

+----------+-------------------------------------------------------------------+
| Syntax   | RELEASE\_HEAP address                                             |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The address given is assumed to be the address of a chunk of common heap as allocated earlier in the program by :ref:`reserve-heap`. In order to avoid crashing the QL when an invalid address is given, RELEASE\_HEAP checks first that there is a flag at address-4 and if so, clears the flag and returns the memory back to the  system.  If the flag is not there, or if the area has already been released, then a bad parameter error will occur.

It is more efficient to RELEASE\_HEAP in the opposite order to that in which it was reserved and will help to avoid heap fragmentation.


**CROSS-REFERENCE**

See :ref:`reserve-heap`\ , below, for an example of use.


-------


..  _release-task:

RELEASE\_TASK
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  RELEASE\_TASK jobnr, jobtag                                      |
+----------+-------------------------------------------------------------------+
| Location |  TASKCMDS (DIY Toolkit Vol J)                                     |
+----------+-------------------------------------------------------------------+

See REL\_JOB and RELJOB below. Refer to NXJOB for information about the
job identification.

--------------


..  _reljob:

RELJOB
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELJOB jobId                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

Same as REL\_JOB apart from the fact that this expects the JobID of the
Job rather than its name or a simple job number.

--------------


..  _reload:

RELOAD
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELOAD program\_name                                             |
+----------+-------------------------------------------------------------------+
| Location |  MutiBASIC (DIY Toolkit - Vol M)                                  |
+----------+-------------------------------------------------------------------+

This command is the opposite to UNLOAD in that it fetches the program
which is stored in memory and loads it into the current SuperBASIC
interpreter. If the screen mode has been stored with UNLOAD (or RESAVE),
then when the program is loaded, RELOAD checks if the current display
mode is the correct one and if not will alter it (although see below).

**NOTE 1**

See the various notes and warnings given for UNLOAD.

**NOTE 2**

Any commands which appear after RELOAD will be ignored.

**NOTE 3**

If you RELOAD a program which has a stored screen in a different mode to
the current display mode, then the system can become confused if the
Pointer Environment or Speedscreen is loaded. Therefore you should
always ensure that the correct MODE is set before you RELOAD a program.

**NOTE 4**

If the specified file is not a file you stored with UNLOAD or does not
exist, an error will be generated. You may also get the error 'Channel
not Open' if the program uses a channel which was OPEN when the program
was UNLOADed but is no longer OPEN.

**CROSS-REFERENCE**

:ref:`scr-save` allows you to dictate whether
the screen display and mode should be stored together with the program.
:ref:`remove` allows you to remove a program stored
in memory with this command. See also :ref:`resave`
and :ref:`qload`.

--------------


..  _rel-job:

REL\_JOB
========

+----------+-------------------------------------------------------------------+
| Syntax   |  REL\_JOB jobname  or REL\_JOB jobnr                              |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command releases a suspended job, so that it becomes active again.

**NOTE 1**

Releasing a job which is waiting for screen input/output will normally
kill it, because it should be activated by <CTRL><C>.

**NOTE 2**

Before v1.11 of this Toolkit, jobnr could not be a variable (see JBASE).

**CROSS-REFERENCE**

Jobs can be suspended by :ref:`sjob` and removed with
:ref:`rjob`, :ref:`kjob`,
:ref:`kill`, etc. :ref:`jobs`
lists the current jobs. See :ref:`reljob`.

--------------


..  _remainder:

REMAINDER
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  REMAINDER                                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This keyword can only be used within a SELect ON structure. It is used
to represent all possible untested values of the SELect ON variable.

**CROSS-REFERENCE**

Please see :ref:`select--on`.

--------------


..  _remark:

REMark
======

+----------+-------------------------------------------------------------------+
| Syntax   |  REMark text                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command has no purpose when a program is RUNing. It is however
used to place comments in the program which can be useful when you later
come to edit a SuperBASIC program. Anything which appears after REMark
on the same line, will be ignored by the interpreter, thus allowing you
to make any sort of comment you like.

**Example**

    100 REMark Line 110 could be altered to: 
    101 REMark 110 INPUT 'Yourname';a$:IF password$<>a$:STOP 
    110 Name$='Author'

**CROSS-REFERENCE**

Another means of splitting a SuperBASIC program into sections is to
include program lines which only contain a colon (:), for example::

    100 PRINT "End of Program":STOP
    110 : 
    200 DATA 'Some data to read'

--------------


..  _remove:

REMOVE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  REMOVE program\_name                                             |
+----------+-------------------------------------------------------------------+
| Location |  MultiBASIC (DIY Toolkit - Vol M)                                 |
+----------+-------------------------------------------------------------------+

This command allows you to remove a task (or program stored in memory
with UNLOAD or RESAVE) by reference to its name. It is therefore very
similar to RJOB, REL\_JOB and REMOVE\_TASK (amongst others).

--------------


..  _remove-task:

REMOVE\_TASK
============

+----------+-------------------------------------------------------------------+
| Syntax   |  REMOVE\_TASK jobnr, jobtag                                       |
+----------+-------------------------------------------------------------------+
| Location |  TASKCMDS (DIY Toolkit - Vol J)                                   |
+----------+-------------------------------------------------------------------+

Please see RJOB, because REMOVE\_TASK a,b works like RJOB a,b,0.

--------------


..  _rename:

RENAME
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RENAME [device\_]oldname TO [device\_]newname                    |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI, Toolkit II                                             |
+----------+-------------------------------------------------------------------+

This command allows you to alter the name of a file which has already been created 
on the given device. 

You must first of all specify the name
of the file to be renamed (if no device is specified, the default data
directory will be used). You will then need to specify the new name for
that file (again, if no device is specified, the default data device
will be used). Assuming that both filenames are valid, an attempt will
be made to alter the filename as requested. If however newname
already exists an error will be generated.

**Example**

::

    RENAME flp1_boot TO flp1_oldboot

**NOTE 1**

If you try to RENAME a file across to another drive, (eg::

    RENAME flp1_boot, flp2_oldboot

the error 'bad name' will be reported.

**NOTE 2**

Although you can RENAME each file within a sub-directory so that they no
longer appear in that sub-directory, any attempt to RENAME the
sub-directory itself (even if there are no files in it) will cause the
error 'Read Only'. 

For example, assuming that a directory of disk flp1\_
returns the following:: 

    boot QUILL->
    
You could for example, use::

    RENAME flp1_QUILL_boot TO flp1_ARCHIVE_boot

if you wished, but any attempt to use:: 

    RENAME flp1_QUILL TO flp1_ARCHIVE

will cause an error except on SMSQ/E (although an error is still
generated on RAM disks).

**NOTE 3**

Unless you have Minerva v1.77 (or later) fitted, RENAME will alter the
date of a microdrive file when used to rename a file on microdrive.

**NOTE 4**

In versions of Toolkit II before v2.10, RENAME could leave the file open
(and therefore inaccessible) if only one name was provided.

**NOTE 5**

If you try to use RENAME to change a filename to uppercase (or
lowercase) the error 'Already Exists' will be reported.

**CROSS-REFERENCE**

See also :ref:`wren` which allows you to rename
several files at once. :ref:`ttrename` is
similar.

--------------


..  _renum:

RENUM
=====

+----------+-------------------------------------------------------------------+
| Syntax   || RENUM [start\_line [TO end\_line];][new\_line][,step] or         |
|          || RENUM [start\_line] TO [end\_line][;new\_line][,step]            |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

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


..  _repeat:

REPeat
======

+----------+-------------------------------------------------------------------+
| Syntax   || REPeat identifier  or                                            |
|          || REPeat [identifier](SMS only)                                    |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The SuperBASIC REPeat loop is extremely flexible and provides an
alternative to the classic FOR loop. 

It sets up a perpetual loop which
can only be ended (correctly) by means of the EXIT
command. The syntax of this SuperBASIC structure can take two forms:

REPeat identifier :statement :sup:`\*`\ [:statement]\ :sup:`\*` 

or: 

REPeat identifier :sup:`\*`\ [statements]\ :sup:`\*` ... [EXIT identifier] [NEXT identifier] ... END REPeat identifier

The first of these variants is known as an in-line REPeat loop. Provided that there is at least one statement following REPeat, 
this line will be repeated forever (unless there is an EXIT statement -
see below). There is no need for a related END REPeat statement and therefore the shortest (practicable) in-line
REPeat loop possible is::

    REPeat loop: IF INKEY$=' ' THEN EXIT loop
 
If an in-line loop is terminated with EXIT, control will be passed to
the statement following the corresponding END REPeat
statement (if one exists), or the next program line. This allows the
following:: 

    REPeat loop: IF INKEY$=' ':EXIT loop: END REPeat loop: PRINT 'Phew!'

EXIT is used (in both REPeat loops and FOR loops) to terminate the
loop, and the next statement which will be processed is the first
statement after the corresponding END REPeat (if one exists). 

NEXT forces the program to make another pass of the loop, returning program
control to the statement following REPeat.

**Example**

A short FuNction which waits for a key to be pressed which can be <ESC>
or any key listed in a string passed as the parameter, and returns the
CODE of the key pressed::

    100 DEFine FuNction Getkey(key$) 
    105   LOCal loop,k$ 
    110   REPeat loop 
    120     k$=INKEY$:IF k$='':NEXT loop 
    130     IF k$ INSTR key$&CHR$(27):RETurn CODE(k$) 
    140   END REPeat loop 
    150 END DEFine

**NOTE 1**

The loop identifier must be a floating-point, except under Minerva or
SMS. However, if the loop identifier is also used as a variable in the
program, its value will not be altered by the REPeat / END REPeat / EXIT
/ NEXT statements. It can therefore still be used as a variable within
the loop without any problems.

**NOTE 2**

It is actually possible to force a NEXT loop from outside of the loop,
for example in a program such as:: 

    100 REPeat Getkey 
    110   AT 0,0:PRINT 'Looping' 
    120   a$=INKEY$:IF a$='':NEXT Getkey 
    130   PRINT a$ 
    140   IF a$=='x':EXIT Getkey 
    150 END REPeat Getkey 
    155 :
    160 PRINT 'You have decided to leave the loop' 
    170 PRINT 'Press a key to return to it' 
    180 PAUSE 
    190 CLS 
    195 :
    200 NEXT Getkey


This is however very bad programming style and should be avoided. It
makes it very difficult to follow programs and no SuperBASIC compilers
would be able to make sense of it. The above program should be
re-written::

    100 REPeat Getkey 
    110   AT 0,0:PRINT 'Looping' 
    120   a$=INKEY$:IF a$='':NEXT Getkey 
    130   PRINT a$ 
    140   IF a$=='x' 
    150     PRINT 'You are now still in the loop' 
    160     PRINT 'Press a key to restart it' 
    170     PAUSE 
    180     CLS 
    190   END IF 
    200 END REPeat Getkey


**MINERVA NOTES**

This allows string REPeat loops and integer REPeat loops, although the
use of the former is dubious. You can of course still use the
identifiers within the loop as variables. Integer REPeat loops do not
seem to be any quicker than floating point loops. 

If you do use a string identifier, Minerva restricts such strings to a maximum of four
characters. If the string identifier is defined as a variable
beforehand, it will be truncated if necessary - for example, try::


    a$='Hello World': REPeat a$: PRINT a$ and a$='': REPeat a$: a$ = a$ & 'x': PRINT a$

String and integer REPeat loops will not safely work on other ROMs
(except under SMS), even if they will let you type them in!

**SMS NOTES**

Like Minerva, SMS allows string REPeat loops and integer REPeat
loops. However, SMS does not restrict the length of a string loop
identifier (except to the normal string length limit of 32767
characters). SMS also allows you to omit the loop identifier, in which
case the relative EXIT, NEXT and END REPeat statements must also omit
the loop identifier. This flexibility brings this command more in line
with other implementations of BASIC. Error trapping of incorrectly
structured REPeat loops is also improved - please refer to NEXT and END
REPeat.

**CROSS-REFERENCE**

:ref:`for`...\ :ref:`end--for`
is the other loop type.

--------------


..  _replace:

REPLACE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  REPLACE oldvar, newvar                                           |
+----------+-------------------------------------------------------------------+
| Location |  REPLACE (DIY Toolkit - Vol R)                                    |
+----------+-------------------------------------------------------------------+

The REPLACE command is intended for use from the interpreter's command
line and for program development only. 

The idea of REPLACE is to rename
SuperBASIC variables contained in the program which is currently loaded
into the interpreter. The first and second parameter can be any
variables, they must not be given as strings ie. inside quotes (this
leads to error -15: bad parameter). 

REPLACE will replace oldvar by
newvar for the whole program (in fact for the whole interpreter).

Acceptable types of parameters are variables and also REPeat loop names
but not PROCedure or FuNction names. 

You can even use this to change
unquoted device names if you wish, such as::

    LBYTES flp1_data_cde

You could use::
 
    REPLACE flp1_data_cde, flp2_data_cde
    
REPLACE is extremely fast, without any noticeable reduction in speed
for large programs due to the fact that the interpreter stores the
program lines in tokenised format, this means that a line is not stored
as text but as a set of numbers (tokens) which represent the elements of
the line. So REPLACE merely has to modify the name table and change the
name which is identified with a certain token.

**Example**

Enter the following lines::

    10 x = 1 
    20 PRINT SQRT(x)

Now type::

    REPLACE x, Whatever

and then LIST or ED, the program now reads::
 
    10 Whatever = 1 
    20 PRINT SQRT(Whatever)

and is functionally identical to the original.

**NOTE 1**

Never use REPLACE as part of a program.

**NOTE 2**

REPLACE will work on a program loaded into a MultiBASIC.

**WARNING 1**

There is one possibility that you can harm your program: if you replace
a variable by another variable which is already used in this program
then the program will usually behave very differently after the
REPLACEment.

**WARNING 2**

According to the Minerva Technical Manual REPLACE is "not particularly
safe". At least if you are using the original version as published in QL
World then you need to turn off Minerva's integer tokenisation (POKE
\\\\212,128). Later versions (v0.3+) do however cope with integer
tokenisation. Despite the warning, we have yet to find any other
problems with REPLACE.

**CROSS-REFERENCE**

:ref:`new-name` is very similar to
:ref:`replace` but the parameters are passed as
strings. This has the advantage that
:ref:`new-name` can take variable parameters,
:ref:`replace` would replace the variable for the
variable name. Compare :ref:`alias`.

--------------


..  _reply:

REPLY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  REPLY [([#wind,] keys$)]                                         |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function REPLY reads a character from the keyboard (with the text
cursor in a window enabled). 

If keys$ was specified, then REPLY will
only stop if the pressed key was listed in keys$, this is case-sensitive
so <a> and <SHIFT><A> are different. 

The return of REPLY is the position of
the pressed key in keys$. REPLY behaves very differently if there is no
keys$ supplied. The return will be the code of the pressed key, just
like CODE(INKEY$(-1)) except that combinations of <ALT> and any other
key are recognised - if <ALT> was held and any other key pressed, REPLY
returns 256 minus the code of that key.

**Example**

Another version of the game also shown at ASK:: 

    100 CLS: x1 = 0: x2 = 100 
    110 PRINT "I am going to find out a number" 
    120 PRINT "from"!x1!"to"!x2!"which only you know." 
    130 PRINT "Press <S> if the proposed number is too small," 
    140 PRINT "<L> if it's too large or <Y> if it's the result." 
    150 REPeat find_out 
    160   x=(x1+x2) DIV 2 
    170   PRINT x;"? "; 
    180   answer = REPLY("sSlLyY") 
    190   SELect ON answer 
    200     =1,2: x1 = x + 1: PRINT "too small" 
    210     =3,4: x2 = x - 1: PRINT "too large" 
    220     =5,6: EXIT find_out 
    230   END SELect 
    240 END REPeat find_out 
    250 PRINT "ok"\"I am the best."

**CROSS-REFERENCE**


:ref:`ask`, :ref:`inkey-dlr`
See :ref:`code` also.

--------------


..  _report:

REPORT
======

+----------+-------------------------------------------------------------------------------+
| Syntax   || REPORT [#channel] or                                                         |
|          || REPORT [#channel,][error\_number](Toolkit II, THOR XVI, TinyToolkit, BTool)  |
+----------+-------------------------------------------------------------------------------+
| Location || QL ROM (post JM), Toolkit II, TinyToolkit, THOR XVI and BTool                |
+----------+-------------------------------------------------------------------------------+

This command will print an error message to the given channel (default
#0, the command line). The type of error is identified by the error
number. If an error number is not supplied, then the last error to have
occurred is displayed. The error message depends on the machine where
the program is running, see ERNUM for conventions. Positive error
numbers have no effect.

**WARNING**

Toolkit II's REPORT allows any value for the error\_number, whereas
TinyToolkit and BTool limit them to -1 to -21 and report undefined error
for values lower than -21. Except under SMS, with Toolkit II, negative
errors smaller than -27 may lead to undefined actions ie. printing a
continuous stream of characters to the report channel - this may never
stop.

**NOTE 1**

TRA can be used to redefine the error messages.

**NOTE 2**

For the original REPORT (QL ROM), only the first version of the command
can be used. Further, if the supplied channel is not yet open, no error
is reported and REPORT simply returns to BASIC as if it had carried out
its job successfully. Also, on Minerva, SMS and ST/QL Emulators with
E-Init software v1.27+, REPORT will show the line and statement number
where the error occurred (rather than merely the line number) in the
form: At line <line number>;<statement number><error message>

**CROSS-REFERENCE**

See :ref:`ernum` about error messages in general and
:ref:`tk2-ext`
/:ref:`tiny-ext` about updating Toolkits. Refer
to the Appendix for the different message texts in various languages.

--------------


..  _resave:

RESAVE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESAVE program\_name                                             |
+----------+-------------------------------------------------------------------+
| Location |  MutiBASIC (DIY Toolkit - Vol M)                                  |
+----------+-------------------------------------------------------------------+

This command is the same as UNLOAD except that if the specified
program\_name has already been stored in memory, it is overwritten.

**CROSS-REFERENCE**

See :ref:`unload`!

--------------


..  _reserve:

RESERVE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESERVE (bytes, JobID)                                           |
+----------+-------------------------------------------------------------------+
| Location |  Timing Toolkit (DIY Toolkit Vol H)                               |
+----------+-------------------------------------------------------------------+

This function grabs an area of memory in the Common Heap similar to
ALCHP. However, the area is not released after a new SuperBASIC program
is loaded. Standard error returns are returned as values by the function
and the program can therefore include error trapping. -3 (Out of Memory)
or -2 (Invalid Job ID) are the most common errors. You can also specify
a task which will own the memory, and that memory will be removed when
that task is removed. This task will normally be 0 (SuperBASIC) or -1
(the current job).

**CROSS-REFERENCE**

See :ref:`discard` and
:ref:`linkup`. Also see
:ref:`alchp`, :ref:`respr` and
:ref:`grab`.

--------------



..  _reserve-heap:

RESERVE\_HEAP
=============

+----------+-------------------------------------------------------------------+
| Syntax   | buffer = RESERVE\_HEAP(length)                                    |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function obtains a chunk of memory for your program to use, the starting address is returned as the result of the call.  Note that the function will ask for 4 bytes more than you require, these are used to store a flag so that calls to :ref:`read-header` do not crash the system by attempting to deallocate invalid areas of memory. If you call this function, the returned address is the first byte that your program can use.  

**EXAMPLE**

The following example shows how this function can be used to reserve a buffer for :ref:`read-header`, described elsewhere.

::

    1000 buffer = RESERVE_HEAP(64)
    1010 IF buffer < 0
    1020    PRINT 'ERROR allocating buffer, ' & buffer
    1030    STOP
    1040 END IF
    1050 error = READ_HEADER(#3, buffer)

    .....do something with buffer contents here

    2040 REMark Finished with buffer
    2050 RELEASE_HEAP buffer


**CROSS-REFERENCE**

:ref:`release-heap`, :ref:`alchp`, 
:ref:`rechp`, :ref:`allocation`.


-------



..  _reset:

RESET
=====

+----------+-------------------------------------------------------------------+
| Syntax   || RESET [new\_ramtop](Not SMSQ/E) or                               |
|          || RESET(SMSQ/E only)                                               |
+----------+-------------------------------------------------------------------+
| Location || TinyToolkit, Beuletools, BTool, SMSQ/E, RES                      |
+----------+-------------------------------------------------------------------+

This command performs a system reset. Except under SMSQ/E, this can be
used to simulate a system with less memory or to get old games and
problem software running, you can reduce the available memory (via
new\_ramtop) to anything between 128K (TinyToolkit: 64K) and RAMTOP in
64K steps (RES and BTool set a maximum of 640K).

**NOTE**

Do not include this command in a program without asking the user to
confirm that it is OK since the computer may be writing some essential
data to disk at the time (or still have some in memory).

**CROSS-REFERENCE**

On Gold Cards use :ref:`res-128` and
:ref:`res-size` for a faster reset. Minerva
allows you to use :ref:`call`  390,x to reset
the system.

--------------


..  _resfast:

RESFAST
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESFAST (bytes)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT for QVME (v2.31+)                                    |
+----------+-------------------------------------------------------------------+

This function allows you to grab a specified number of bytes
in Atari TT FastRAM and is therefore akin to RESPR and ALCHP. However,
note that you can only use LBYTES to load data to this area or SBYTES /
SEXEC to save data if you are loading a file from or saving a file to a
RAM disk. You cannot use floppy disks or hard disks with this area of
memory.

**CROSS-REFERENCE**

See :ref:`fast-free` and :ref:`respr`.

--------------


..  _respr:

RESPR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  RESPR (bytes)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function sets aside a chunk of resident procedure space for use by
a program and returns the address of the start of that memory. Resident
procedure space is merely an area of RAM which can be used safely by the
user without fear of the system crashing if values are written to it.

When used, the RESPR function will search for an area in RAM which is
currently unused and which is at least 'bytes' long. If there is
insufficient space in RAM, then an 'Out of Memory' error is reported.

Memory set aside using RESPR cannot later be released and used for other
purposes (unless you have a Minerva ROM), and thus this command is used
mainly for linking in Toolkits and other system extensions in a boot
program.

**Example**

A simple boot program might look like this::

    100 x=RESPR(10*1024): LBYTES flp1_Toolkit,x: CALL x 
    120 EXEC flp1_Program_obj

**NOTE 1**

If a task is running in memory (eg. with EXEC), when RESPR is used, the
resident procedure space cannot be accessed and the error 'Not Complete'
is reported. However, some Toolkits, SMS and Minerva rewrite the RESPR
command so that it will access the common heap if the resident procedure
space cannot be accessed.

**NOTE 2**

Normally, the function RESPR(0) will return the address of ramtop, this
can actually be used to find out the size of memory attached to the QL::


    PRINT RESPR(0)/1024-128. 
    
However, this will not work on versions of the command which work when tasks are running in memory.

**NOTE 3**

On Minerva pre v1.96, adding machine code functions and procedures from
within a SuperBASIC PROCedure or FuNction definition could cause
problems after a CLEAR command.

**WARNING**

Several programs may try to use the same area of resident procedure
space if absolute addresses are used.

**CROSS-REFERENCE**

Please also see :ref:`alchp` which allocates memory
from the common heap, which can be accessed when tasks are running in
memory. Also see :ref:`reserve` and
:ref:`grab` which are similar to
:ref:`alchp`. It is also worth looking at
:ref:`resfast`.

--------------


..  _restore:

RESTORE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESTORE [line\_no]                                               |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

In any program which uses DATA statements, it is necessary to tell the
interpreter where the data begins within the program, so that it knows
where to look when it encounters a READ command. RESTORE allows you to
set the data pointer to a specific line number within a SuperBASIC
program. 

If line\_no is not specified, then the data pointer is moved to
the start of a program allowing all DATA within a program to be READ.
line\_no can be either a simple reference to a line number anywhere in a
SuperBASIC program, or an expression which will be calculated by the
interpreter when it reaches the RESTORE command.

**NOTE 1**

The Turbo and Supercharge compilers cannot compile computed RESTOREs.

**NOTE 2**

The data pointer is not reset when a program is RUN and it is therefore
necessary to use an implicit RESTORE or CLEAR if you wish to read the
same set of DATA each time that a program is RUN.

**NOTE 3**

On some implementations RESTORE with an invalid parameter will do a
RESTORE 0. This is fixed on Minerva v1.96+ and SMS which report the
error.

**CROSS-REFERENCE**

See :ref:`data` and :ref:`read`.
Please also refer to :ref:`renum`.

--------------


..  _res-size:

RES\_SIZE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  RES\_SIZE ram\_top                                               |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card                                                        |
+----------+-------------------------------------------------------------------+

To get the few old programs which still do not work with the Gold
Card's 1920K RAM running and to simulate a system with less RAM for
debugging, RES\_SIZE resets the system and adjusts the RAMTOP to the
desired value. 

If you use RES\_SIZE 128, high density and extra density
disks cannot be accessed until the next reset. Secondly, the realtime
clock runs by default in protected mode. Thirdly, the ramdisks cannot be
accessed by the system. This should simulate the unexpanded, original
QL. Normal disk drives (DD) can still be accessed, although this can be
temperamental.

**Examples**

::

    RES_SIZE 640 
    RES_SIZE 128 
    RES_SIZE 1024

**NOTE**

You may find that some programs will still not work following RES\_SIZE,
especially if they use a line such as:: 

    x=RESPR(0): start=RESPR(x-131072)
    
This appears to happen because RESPR(0) returns the address of RAMTOP
which is still over 2MB even though only 128K is available. Minerva
users should use::

    CALL 390,x 
    
instead.

**WARNING**

At least up to Gold Card's firmware v2.28, RES\_SIZE does not check the
range of the supplied parameter. If values lower than 56 or higher than
1920 are used, this can lead to crashes of a particularly serious
character. Either the QL hangs during or after the resets, or there will
not be enough free memory to enter any commands. 

There is even a danger
that a fatal crash will occur which can destroy data on hard disks,
disks or microdrive cartridges, or the realtime clock can be affected or
even combinations of these different crashes can occur. As hard disk
drives cannot be removed or protected from any malfunction of the
operating system or programs, they are in extreme danger. 

It is also not
advisable to use values other than multiples of 64 because software
tends to expect a ramtop which is a multiple of 64 and memory is wasted.

**CROSS-REFERENCE**

:ref:`res-128` is identical to :ref:`res-size` 128. See also
:ref:`reset`. See :ref:`ramtop`
and :ref:`free-mem` about available and free
memory. :ref:`flp-ext` improves the reliability
of the floppy disk drives and allows RAM disks to be used.

--------------


..  _res-128:

RES\_128
========

+----------+-------------------------------------------------------------------+
| Syntax   |  RES\_128                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card, Trump Card                                            |
+----------+-------------------------------------------------------------------+

This command does the same as RES\_SIZE 128.

**CROSS-REFERENCE**

:ref:`flp-ext` can be used to re-enable some
functions such as ramdisks.

--------------


..  _retry:

RETRY
=====

+----------+-------------------------------------------------------------------+
| Syntax   || RETRY  or                                                        |
|          || RETRY [line\_no](Toolkit II and Minerva)                         |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

The command RETRY performs the same operation as CONTINUE
except that interpreting re-starts with the statement at which the
error occurred (CONTINUE re-starts the program from the next statement).

If you have Toolkit II or Minerva installed, you will be able to use the
second variant of this command which allows you to re-start processing
at a specified line number to help with error trapping. If the parameter
is specified, this is exactly the same as the second variant of
CONTINUE.

**Example**

Take the following short program:: 

    100 REPeat loop 
    110 INPUT 'Enter a number: ';a 
    120 PRINT 'The number you entered is: ';a 
    130 END REPeat loop

Now, when prompted to enter a number, enter a letter, which results in
the error 'Error in Expression'. If you were to enter the command RETRY,
the program would re-start at line 110, asking you to enter a number.
However, if you entered the command CONTINUE, the program would re-start
at line 120, displaying the message:: 

    The number you entered is: *

**CROSS-REFERENCE**

Please refer to :ref:`continue`!

--------------


..  _return:

RETurn
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RETurn [expression]                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command has two actual uses. The main use of RETurn is to force an
early return from a PROCedure or FuNction definition block. A FuNction
must always return a value and therefore a SuperBASIC DEFine FuNction
block must always contain a RETurn
statement to return this value. 

The second use of RETurn is to mark the
end of a sub-routine which has been called with GO SUB. This is
implemented in SuperBASIC to make the transition from other
implementations of BASIC easier.

**Examples**

A PROCedure to report an error more safely than REPORT:: 

    100 DEFine PROCedure REPORT_ERROR(errnumber) 
    110 IF errnumber>=0 OR errnumber<-21
    120   PRINT #0,'No error' 
    130   RETurn 
    140 END IF 
    150 REPORT errnumber 
    160 END DEFine

A FuNction which returns 1 (true) if a given number is even:: 

    100 DEFine FuNction CK_EVEN (x) 
    110   IF x/2=INT(x/2):RETurn 1 
    120   RETurn 0 
    130 END DEFine

**CROSS-REFERENCE**

See :ref:`define--procedure` and :ref:`define--function`\ . Please also refer to :ref:`go--sub`\ .

--------------


..  _rev-dlr:

REV$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  REV$ (string$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  REV                                                              |
+----------+-------------------------------------------------------------------+

This function returns the supplied string in reverse order.

**Example**

::

    PRINT REV$("Hello World")

shows dlroW olleH

**CROSS-REFERENCE**

:ref:`len` finds the length of a
string. :ref:`trim-dlr` cuts
off excess spaces from a string.

--------------


..  _rjob:

RJOB
====

+----------+-------------------------------------------------------------------+
| Syntax   || RJOB jobname [,error] or                                         |
|          || RJOB jobnr,tag,error  or                                         |
|          || RJOB job\_id,error  or                                           |
|          || RJOB [job\_id,error] (BTool only)                                |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI, BTool                                      |
+----------+-------------------------------------------------------------------+

This command removes a job from memory - all of its channels are
automatically closed and any memory used by the job is freed. The error
code is returned to the owner job of the removed job. The BTool variant
of RJOB allows you to enter the command without any parameters which
will kill every job except SuperBASIC (Job 0), see KJOBS and KILL.

**NOTE**

If the first syntax does not work, you are using an old Toolkit version.

**CROSS-REFERENCE**

:ref:`kjob` works similarly to
:ref:`rjob`. :ref:`kill`,
:ref:`remove` and :ref:`kjobs`
remove all jobs. Have a look at :ref:`jobs`,
:ref:`spjob`, :ref:`ajob`,
:ref:`sjob` etc.

--------------


..  _rmar:

RMAR
====

+----------+-------------------------------------------------------------------+
| Syntax   |  RMAR(n) with n=0..255                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to set the right margin
to n characters (from the left side) on EPSON compatible printers. If
the right margin is smaller than the left margin, the printer will
ignore this setting and print to the greatest possible right margin::

    PRINT #ch,RMAR
    
is the same as::

    PRINT #ch,CHR$(27) & 'Q' & CHR$(n)

.. COMMENT. What is the following meant to be showing? It doesn't seem to
   make any sense or be related to the above. I've left it commented out for now.
   
   
.. ::
..    
    |- LMAR -|
    |------------ RMAR ----------|
    +---------------------------------+
    |                    |
    |     .....................     |
    |   .....................     |
    |    .....................     |

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`alt`,
:ref:`esc`, :ref:`ff`,
:ref:`lmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _rmode:

RMODE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  RMODE [(screen)]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

The function RMODE returns the current screen mode (of the screen
belonging to the job which executes RMODE if the Window Manager is
present). 

If Minerva or Amiga QDOS v3.23 is present and is in dual
screen mode, then PRINT RMODE(1) will show the current screen mode for
the Other Screen (see MODE). If Minerva and Amiga QDOS is not present,
(or dual screen mode is not active), then RMODE(1) will return -19 (for
'Not Implemented'). Both RMODE and RMODE(0) return the mode of the
Default Screen on all ROMs:

+-------+----------------+---------+
| RMODE | Min Resolution | Colours |
+=======+================+=========+
| 2     | 640 x 400      |  2      |
+-------+----------------+---------+
| 4     | 512 x 256      |  4      |
+-------+----------------+---------+
| 8     | 256 x 256      |  8      |
+-------+----------------+---------+
| 12    | 256 x 256      | 16      |
+-------+----------------+---------+

**Example**

If a program is written to operate in one of these modes, it has to
change to that mode at the very beginning. A simple MODE 4 will do, if
high resolution is needed. But the MODE is executed even if the screen
was already in the correct mode. It looks better if MODE is only done if
the mode really has to be changed. CHANGE\_MODE should be used instead
of MODE:: 

    100 DEFine PROCedure CHANGE_MODE (mode%) 
    110   IF RMODE(0)<> mode% 
    120     MODE mode% 
    130   END IF 
    140 END DEFine CHANGE_MODE

**CROSS-REFERENCE**

:ref:`mode` sets the mode.
:ref:`qflim` returns the screen resolution.
:ref:`ttmode-pct` is similar.

--------------


..  _rnd:

RND
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RND [([min TO] max)]                                             |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function produces a (pseudo) random number. When used without
parameters it returns a floating point number between 0 and 1, otherwise
an integer number lying between the two parameters (including the
parameters) will be returned.

+-------------------+------------------------------+
| Expression        | Results                      |
+===================+==============================+
| x=RND             | 0 < x < 1                    |
+-------------------+------------------------------+
| x=RND(max)        | 0, 1, 2, 3, ..., max         |
| where max >= 0    |                              |
+-------------------+------------------------------+
| x=RND(min TO max) | min, min+1, ..., max-1, max  |
| where max >= min  |                              |
+-------------------+------------------------------+

**Example**

::

    100 CLS: PRINT "RND Statistics" 
    110 n = 1000: m = 10: DIM h%(m) 
    120 FOR i=1 TO n 
    130   k = RND(1 TO m) 
    140   h%(k) = h%(k )+ 1 
    150   AT 2,5: PRINT i 
    160 END FOR i 
    170 PRINT: avdiff = 0 
    180 FOR k = 1 TO m 
    190   diff = n / m - h%(k) 
    200   PRINT k; TO 6; h%(k); TO 12; INT(diff) 
    210   avdiff = avdiff + ABS(diff / n * m) 
    220 END FOR k 
    230 PRINT\"average difference:" ! INT(100 * avdiff / m);"%"

**NOTE**

If a range is specified {eg. RND(x TO y)} the second number must not be
less than the first (ie. y>=x). If only one parameter is specified, this
is taken to be the top of the range, with the bottom of the range being
0. Therefore, if only one parameter is specified, this must not be
negative.

**CROSS-REFERENCE**

The results of :ref:`rnd` can be influenced with
:ref:`randomise`. See also
:ref:`matrnd`.

--------------


..  _rom:

ROM
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ROM (n)                                                          |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function returns the address in memory where additional ROMs can
be placed. The parameter specifies the number of the slot you wish to
look at (it must be in the range 0...16). The possible values are:

+----+--------------------+
| n  | ROM(n)             |
+====+====================+
| 0  | 49152 (EPROM-Port) |
+----+--------------------+
| 1  | 786432             |
+----+--------------------+
| 2  | 802816             |
+----+--------------------+
| 3  | 819200             |
+----+--------------------+
| 4  | 835584             |
+----+--------------------+
| 5  | 851968             |
+----+--------------------+
| 6  | 868352             |
+----+--------------------+
| 7  | 884736             |
+----+--------------------+
| 8  | 901120             |
+----+--------------------+
| 9  | 917504             |
+----+--------------------+
| 10 | 933888             |
+----+--------------------+
| 11 | 950272             |
+----+--------------------+
| 12 | 966656             |
+----+--------------------+
| 13 | 983040             |
+----+--------------------+
| 14 | 999424             |
+----+--------------------+
| 15 | 1015808            |
+----+--------------------+
| 16 | 1032192            |
+----+--------------------+


**CROSS-REFERENCE**

:ref:`rom-test` checks if a piece of code can be
placed into a ROM. :ref:`eprom-load` allows
you to load an EPROM on an emulator.

--------------


..  _rom-ext:

ROM\_EXT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  ROM\_EXT                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This command activates any EPROMs in a standard QL format which have
been plugged into the ROM port on the Atari ST. The code contained in
the EPROMs is initialised just as it would be on the QL.

**NOTE**

This can only be used on code which is stored on EPROM chips, as a QL
EPROM cartridge cannot be plugged into the Atari ST.

**CROSS-REFERENCE**

See also :ref:`rom-load` and
:ref:`eprom-load` which allows you to
transport code across from QL EPROM cartridges.

--------------


..  _rom-load:

ROM\_LOAD
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  ROM\_LOAD device\_file                                           |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (pre v1.21 only)                                     |
+----------+-------------------------------------------------------------------+

On later versions of the Emulator, this has been renamed EPROM\_LOAD.

--------------


..  _roms:

ROMs
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ROMs [#ch]                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command lists all ROM headers of plugged in ROMs to the given
channel (default #1), provided the ROMs conform to the Sinclair
standard. This will recognise, for example, Trumpcard, Atari QL-Emulator
and anything plugged into the QL's ROMport.

**CROSS-REFERENCE**

:ref:`rom` returns the start address of a ROM slot.

--------------


..  _rtp-...:
..  _rtp-r:

RTP\_R
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RTP\_R (imag, real)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PTRRTP                                                           |
+----------+-------------------------------------------------------------------+

The function RTP\_R takes a given rectangular co-ordinate and returns
the so-called module (ie. the radius in polar co-ordinates). The result
of RTP\_R is always strictly positive and is not affected by the sign of
the imag and real parameters, because of the symmetries of a circle.

**Example 1**

Draw a rectangular pattern in green and the corresponding polar pattern
again displayed as rectangular co-ordinates in white:: 

    100 SCALE 10,-5,-5: PAPER 0: CLS 
    110 FOR x = -3 TO 3 STEP .4 
    120   FOR y = -3 TO 3 STEP 5E-2 
    130     INK 4: POINT x, y 
    140     INK 7: POINT RTP_R(x,y), RTP_T(x,y) 
    150   END FOR y 
    160 END FOR x

**Example 2**

The same as the above example but the polar co-ordinates are treated
even more unusually. If you correct the program and exchange a and b in
line 140 then the two patterns will match exactly - this reveals what
the RTP\_... functions are actually doing:: 

    100 SCALE 10,-5,-5: PAPER 0: CLS 
    110   FOR x = -3 TO 3 STEP .4 
    120   FOR y = -3 TO 3 STEP 2E-2 
    130     INK 4: POINT x, y 
    140     a = RTP_R(x,y): b = RTP_T(x,y) 
    145     INK 7: POINT b * COS(a), b * SIN(a) 
    150   END FOR y 
    160 END FOR x

**CROSS-REFERENCE**

Polar co-ordinates also need an angle, this is calculated with
:ref:`rtp-t`. The
:ref:`ptr-...` pair of functions is complementary to
:ref:`rtp-...`\ .

--------------


..  _rtp-t:

RTP\_T
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RTP\_T (imag, real)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PTRRTP                                                           |
+----------+-------------------------------------------------------------------+

The function RTP\_T takes rectangular co-ordinates and returns the
corresponding argument, (the angle used in polar co-ordinates) in
radians. See RTP\_R for further information.

--------------


..  _run:

RUN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RUN [line]                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

There is one command which can be found in any BASIC language::

    RUN
    
Issuing RUN may actually be a little closer to the truth than you like
to admit, but you should be happy with BASIC. Assembly language is much
more terrifying, and if you have not yet reached that point of knowledge
and understanding which it is most frustrating to reach... However:: 

    RUN line 
    
is identical to:: 

    GOTO line 

and:: 

    RUN 

without a parameter, could be replaced by GOTO 1. 

Unlike some implementations of BASIC, the variables and the DATA pointer are not reset when you enter RUN.

**NOTE**

Jobs cannot be started with RUN but have to loaded and executed with EX,
EXEC\_W,... or a file manager/desktop. RUN will work okay from inside
compiled jobs to enable them to re-start themselves.

**CROSS-REFERENCE**

See :ref:`go--to` or even better, :ref:`repeat` and :ref:`for` loops.

