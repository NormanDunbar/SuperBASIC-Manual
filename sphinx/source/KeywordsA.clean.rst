
==========
Keywords A
==========

TODO
====

- :ref:`allocation` refers to taskno% and tasktag% in the syntax, but the text mentions taskid%. 
- There is a reference to the ESC command, in :ref:`alt`, but it's not in the KeywordsE file.


..  _abs:

ABS
===

+----------+-------------------------------------------------------------------------+
| Syntax   || ABS (number) or                                                        |
|          || ABS (number1 :sup:`\*`\ [,number\ :sup:`x`]\ :sup:`\*`) (Minerva only) | 
+----------+-------------------------------------------------------------------------+
| Location || QL ROM                                                                 | 
+----------+-------------------------------------------------------------------------+

This function returns the absolute value of a number - ie. the positive
difference (or distance) between zero and the number. The absolute value
of a positive number (including zero) therefore, is the number itself -
negative numbers are converted to positive. This function will happily
handle 32-bit integer numbers (-INTMAX..INTMAX, roughly -1E9..1E9).

**Example 1**

The SIGN% function returns 1 if the supplied parameter is positive, -1
if negative, or 0 if it is zero, for example,

PRINT SIGN%(-10) will print -1 on screen.

This version rounds values which are very close to zero (use = in line
110 instead of == if you want to avoid this).

Note that line 110 is needed to avoid an error when line 120 tries to
divide by zero.

::

    100 DEFine FuNction SIGN% (number)
    110  IF number==0 THEN RETurn 0
    120  RETurn number/ABS(number)
    130 END DEFine

**Example 2**

Here is a simple implementation of the cosine function. Of course, it
cannot compete with the speed of a machine code function, but it allows
you to specify the precision of the result. You can optimise the
function by exploiting the symmetries of the cosine function.

::

    100 DEFine FuNction MYCOS (x, prec)
    110  LOCal fct, result, xpower, i, lagrange, sqrx
    120  fct = 1: result = 1
    130  xpower = 1: sqrx = x*x
    140  i = 2
    150  REPeat taylor
    160    fct = fct * (i-1) * i
    170    xpower = - xpower * sqrx
    180    result = result + xpower/fct
    190    lagrange = ABS(xpower*x / fct / (i+1))
    200    IF lagrange < prec THEN EXIT taylor
    210    i = i + 2
    220  END REPeat taylor
    230  RETurn result
    240 END DEFine MYCOS

**MINERVA NOTE**

ABS can accept more than one parameter. This version of ABS will square
each parameter, and return the square root of the total of those
squares, eg. ABS(x,y)=SQRT(x2+y2). This is therefore useful to calculate
the distance between two points (using pythagoras' method).

For example, to calculate the distance between the points on screen at
(10,20) and (100,75), simply type in: PRINT ABS(100-10,75-20)

Three parameters can be used to find the distance between two points in
three dimensional space. Any more parameters take you into the realm of
theoretical mathematics (we always thought that time was the fourth
dimension!).

For example, to calculate the length of a diagonal in a standard cube
(length of sides = 1), use: PRINT ABS(1,1,1)

**CROSS-REFERENCE**

See :ref:`sgn` and :ref:`sgn-pct` for
similar machine code versions of our example function SIGN% demonstrated above.

--------------


..  _abs-position:

ABS\_POSITION
=============

+----------+-------------------------------------------------------------------+
| Syntax   | ABS\_POSITION #channel, position                                  |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure will set the file pointer to the position given for the file attached to the given channel number. If you attempt to set the position for a screen or some other non-directory device channel, you will get a bad parameter error, as you will if position is negative.

If the position given is 0, the file will be positioned to the start, if the position is a large  number which is greater than the current file size, the position will be set to the end of file and no error will occur.

After an ABS\_POSITION command, all file accesses will take place at the new position.

**EXAMPLE**

::

    1500 REMark Set position to very end, for appending data
    1510 ABS_POSITION #3, 6e6
    1520 ...

**CROSS-REFERENCE**

:ref:`move-position`.

-------


..  _accel-off:

ACCEL\_OFF
==========

+---------+--------------------------------------------------------------+
| Syntax  | ACCEL\_OFF                                                   |
+---------+--------------------------------------------------------------+
| Location| ST/QL                                                        |
+---------+--------------------------------------------------------------+

See ACCEL\_ON below!

--------------


..  _accel-on:

ACCEL\_ON
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  ACCEL\_ON                                                        |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

The ST/QL Emulator supports several of the accelerator boards which can
be plugged into the Atari ST computer, thus allowing much greater
operational speed. This command both enables the 16MHz mode on the Atari
ST and tells the attached accelerator board to use its memory cache (if
built in).

**NOTE**

This and the other ACCEL\_... commands will be ignored unless you have
previously used ACCEL\_SET to define the type of accelerator board
attached to the Atari ST.

**CROSS-REFERENCE**

:ref:`accel-off` turns off the 16MHz mode (if
possible) and also tells the accelerator board that it should no longer
use its memory cache. Also see
:ref:`accel-set`.

--------------


..  _accel-set:

ACCEL\_SET
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  ACCEL\_SET type,option                                           |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

Before the ST/QL Emulator can use an accelerator board plugged into the
Atari ST, it is necessary to use the command ACCEL\_SET to tell the
Emulator about the board and to activate the board.

There are currently five accelerator boards which are recognised by the
Emulator. Use the following values for type to tell the Emulator which
one is attached:

-  H - HyperCache (ProVME)
-  A - AdSpeed (ICD)
-  M - MegaSTE (ATARI)
-  P - HyperCache 030 (ProVME), 68030 Board
-  T - TT (ATARI)

If you have a 68030 board attached, the ST/QL Emulator can only use
external caches with this board.

The option parameter currently only has any effect when HyperCache is
attached. This can have the value 6 or 7 (default is 6). This is used to
specify which bit of the Atari's sound chip is used to switch
HyperCache. If you have the HyperCache 030 attached, you can pass the
parameter 0 (default) to enable external caches only, 1 to enable the
internal caches only or 2 to enable both external and internal caches.

**NOTE**

Unfortunately, due to the higher speed of the Atari ST with an
accelerator board enabled, you may encounter problems with the parallel
printer board - use the command PAR\_PULSE.

**CROSS-REFERENCE**

See also :ref:`accel-on`,
:ref:`accel-off` and
:ref:`accel-state`.

--------------


..  _accel-state:

ACCEL\_STATE
============

+----------+-------------------------------------------------------------------+
| Syntax   |  ACCEL\_STATE                                                     |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

This function returns the value 1 if the ST/QL Emulator has been told
that an accelerator board is enabled. Otherwise, it returns the value 0.

**CROSS-REFERENCE**

:ref:`accel-set` tells the Emulator that an
accelerator board is enabled.

--------------


..  _acopy:

ACOPY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ACOPY filename1,filename2                                        |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command is similar to COPY except that it copies a file from a QL
Format disk to an Atari Format disk. No conversion takes place.

**NOTE**

You will need to pass the Atari filename in quote marks if it includes a
three letter extension preceded by a dot eg:

ACOPY flp1\_PROGRAM\_BAS, "flp2\_PROGRAM.BAS"

**CROSS-REFERENCE**

:ref:`qcopy` copies a file from an Atari disk to a
QL disk.

See :ref:`aformat` and
:ref:`qaconvert`.

--------------


..  _acos:

ACOS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ACOS (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function ACOS, is the arc-cosine function, that is to say the
opposite to the cosine function (COS in SuperBASIC). However, x must
always be in the range -1...1 as the cosine of an angle can only ever be
in this range. Anything outside of this range will produce an Overflow
Error.

The angle returned will be in the range 0...PI with ACOS(1)=0 and
ACOS(-1)=PI. This means that the maximum angle which can be found with
the ACOS function is 180 degrees. It is up to you to check whether this
angle appears above or below the base line of the triangle (check the
co-ordinates of the corners).

Note that if a negative value of x is provided, the angle returned will
be the obtuse angle (ie. greater than 90 degrees).

**Example**

To calculate the angle at which a projectile was fired which has
travelled a horizontal distance of 250 metres after 10 minutes and is
travelling at 3 kilometres per hour (ignoring the effects of gravity):

::

    100 Speed=3:Distan=250/1000
    110 Time_elapsed=10
    120 Actual_distance=(Speed/60)*Time_elapsed
    130 PRINT 'Projectile fired at an angle of ';
    140 PRINT DEG(ACOS(Distan/Actual_distance))&' degrees'

**NOTE**

The angle returned will be in radians - if you wish to convert this
angle to degrees, use DEG ( ACOS (x) ).

**CROSS-REFERENCE**

:ref:`cos`, :ref:`asin`,
:ref:`sin`, :ref:`rad`.

Compare :ref:`arcosh`.

Also please see the Mathematics section in the Appendix.

--------------


..  _acot:

ACOT
====

+----------+-------------------------------------------------------------------+
| Syntax   || ACOT (x) or                                                      |
|          || ACOT (y,x) (Minerva v1.90+ only)                                 |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function ACOT, is the arc-cotangent function, that is to say the
inverse of the cotangent function (COT in SuperBASIC): COT(ACOT(x))=x
for all values of x, but due to the periodic nature of COT,
ACOT(COT(x))=x is only true for where: 0<x<PI.

Note that if a negative value of x is provided, the angle returned will
be the obtuse angle (ie. greater than 90 degrees).

**MINERVA NOTE**

ACOT can accept two parameters. If you specify two parameters then
ACOT(y,x) will give the angle from the origin to the point (x,y). This
is actually the same as ACOT(x/y) although it does also cater for when
y=0 which would otherwise give an overflow error.

**CROSS-REFERENCE**

:ref:`cot`, :ref:`atan`,
:ref:`tan`.

Please see the Mathematics section in the Appendix.

See also :ref:`arcoth`.

--------------


..  _adate:

ADATE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ADATE seconds                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

ADATE adjusts the current system clock by the given number of seconds,
so ADATE 60 would advance the internal clock by a minute and ADATE
-86400 sets it back by one day.

**Example**

Apart from adjusting the clock relatively, ADATE can also be used to set
the time and date absolutely. This is because the function DATE contains
the system time in seconds after a fictional 'Birth Date' (Midnight on 1
January 1961 on all ROM implementations):-

ADATE -DATE will set the clock to that Birth Date (when DATE=0)

ADATE 1E9 advances the clock by roughly 31 years and nine months.

ADATEs can then be combined by adding values:

ADATE 1E9-DATE sets the clock to DATE$="1992 Sep 09 01:46:40"

**NOTE 1**

ADATE generally needs one second to execute because some ROMs (notably
the THOR XVI, MG ROM and Minerva) will wait for the next full second
before amending the time (therefore do not use ADATE 1 to wind the clock
on!).

**NOTE 2**

Any attempts to wind the system clock back to earlier than 1st Jan 1961
will actually deduct the difference from 6th Feb 2097. However, the
system clock (on implementations other than Minerva and SMS) runs into
trouble here because any date later than 3.14:07 on 19th Jan 2029 should
produce a negative number (!) whenever the function DATE is used.
However, on non-Minerva ROMs and non-SMS systems, a positive number is
produced, preventing DATE from recognising later dates.

The system clock itself, does however appear able to support dates and
times between 0.0:00 on 1st Jan 1961 and 6.28:15 on 6th Feb 2097.

**NOTE 3**

On Minerva v1.63 and Minerva v1.98, the ADATE command did not work
properly - use SDATE DATE+seconds instead!

**WARNING**

ADATE will affect the time on battery backed clocks unless they are
protected in some way (see PROT\_DATE).

**CROSS-REFERENCE**

:ref:`date-dlr` returns the current system date and
time as a string, :ref:`date` does the same but in a
less readable form - in seconds after the initial date.

:ref:`sdate` sets the clock to an absolute date and
time.

Battery backed clocks generally have their own methods of altering their
date and time.

--------------


..  _addreg:

ADDREG
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ADDREG                                                           |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This function returns the value of the following Machine code address
register following the completion of a MTRAP, QTRAP or BTRAP command.

+-----------+------------------------------------------------+
| Command   | Machine Code Register Value Returned.          |
+===========+================================================+
| MTRAP     | A0                                             |
+-----------+------------------------------------------------+
| QTRAP     | A1                                             |
+-----------+------------------------------------------------+
| BTRAP     | A1 (relative to A6) - can be used by BPEEK%.   |
+-----------+------------------------------------------------+

**Example**

You could replace the ALCHP function with:

::

    100 bytes=100 : REMark Number of bytes required
    110 MTRAP 24,bytes,-1
    120 IF DATAREG < 0 : REPORT DATAREG : REMark an error has occurred
    130 IF DATAREG (1) < bytes : PRINT 'Requested area not allocated':STOP
    140 base=ADDREG

**CROSS-REFERENCE**

:ref:`datareg` allows you to read machine code
data registers.

See :ref:`mtrap`, :ref:`qtrap`
and :ref:`btrap`.

--------------


..  _adelete:

ADELETE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  ADELETE filename                                                 |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command is the same as the standard DELETE command, except that it
works on Atari and IBM PS/2 format disks.

**NOTE**

You will need to pass the filename in quote marks if it includes a three
letter extension preceded by a dot eg:

ADELETE "flp1\_TEST.BAS"

**CROSS-REFERENCE**

See :ref:`delete`!

See :ref:`adir`,
:ref:`aformat`,
:ref:`qaconvert`.

--------------


..  _adir:

ADIR
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ADIR [#channel,] device                                          |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command is the same as DIR except that it works on ATARI disks or
IBM PS/2 Disks.

**CROSS-REFERENCE**

See :ref:`dir`.

Other commands added are :ref:`astat`,
:ref:`adelete`, :ref:`acopy`
and :ref:`aformat`.

--------------


..  _aformat:

AFORMAT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  AFORMAT device\_[name]                                           |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command formats the specified device in Atari disk format, giving
it the specified name (if any).

As with FORMAT, this will normally format a disk to the highest possible
density - however, you can force it to format a disk as single-sided by
making the last character of the filename an asterisk (\*).

**CROSS-REFERENCE**

See :ref:`format` and
:ref:`iformat`.

Other commands added are :ref:`astat`,
:ref:`adelete`, :ref:`adir` and
:ref:`acopy`.

--------------


..  _ajob:

AJOB
====

+----------+-------------------------------------------------------------------+
| Syntax   || AJOB jobname,priority or                                         |
|          || AJOB jobnr,tag,priority or                                       |
|          || AJOB job\_id,priority                                            |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command forces the specified job (described by either its jobname,
its job number and tag, or its job identification number) to be
re-started at the given priority (which should be in the range 0...127
to maintain Minerva compatability - see SPJOB).

This will only work if the current priority of the given job is set to
zero, in any other case, a 'Not Complete' (-1) error will be reported.

**NOTE**

It is possible that on early versions of Toolkit II, only the second
syntax works.

**CROSS-REFERENCE**

:ref:`sjob` suspends a job.

:ref:`rel-job` releases a job.

:ref:`spjob` sets the priority of a job without
restarting it.

--------------


..  _alarm:

ALARM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ALARM hour,minutes                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command creates a Job at low priority which makes the QL sound
several beeps when the alarm time is reached and then removes itself.
Naturally, this facility only works if the system clock is correct.

The hour is based on the 24-hour clock and must therefore be specified
in the range 0...23 and the minutes in the range 0...59.

**Example**

How about a hourly alarm to remind you to switch off the cassette player
and listen to the news on the radio?

::

    100 FOR hour=8 to 18
    110   ALARM hour-1,59
    120 END FOR hour

**CROSS-REFERENCE**

Set the system clock with :ref:`sdate`, adjust it
with :ref:`adate`.

Alarm jobs can be killed by using :ref:`rjob` for
example.

--------------


..  _alchp:

ALCHP
=====

+----------+-------------------------------------------------------------------+
| Syntax   || ALCHP (space) or                                                 |
|          || ALCHP (space [,[jobID]]) (BTool only)                            |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI, BTool                                      |
+----------+-------------------------------------------------------------------+

The function ALCHP allocates space bytes in the common heap and returns
the start address of the memory set aside to be altered freely. This,
unlike RESPR, works even if there is a task running in memory.

If ALCHP fails due to lack of available memory, then it will return 0
instead of breaking with error -3 (Out of Memory).

The BTool version of ALCHP allows an extended syntax. If space is
followed by a comma ',' then the allocated memory can only be removed
with RECHP or CLCHP (unlike the other versions where this is done
automatically with NEW and CLEAR). If the jobID is specified then not
only will this be done, but the memory will also be linked to the Job
identified by jobID.

**Example 1**

The following program loads two uncompressed screens from

disk into memory and shows them alternately:

::

    100 adr=ALCHP(2*32768)
    110 LBYTES flp1_Screen1_scr,adr
    120 LBYTES flp1_Screen2_scr,adr+32768
    130 REPeat Picture_Show
    140   SCRBASE adr : REFRESH : PAUSE 150
    150   SCRBASE adr+32768 : REFRESH : PAUSE 150
    160 END REPeat Picture_Show

**Example 2**

This is an alternative to the LRESPR command (although see Note 2
below):

::

    100 DEFine PROCedure LALCHP (mc_file$)
    110  LOCal length,adress
    120  length=FLEN(\mc_file$)
    130  adress=ALCHP(length)
    140  LBYTES mc_file$,adress
    150  CALL adress
    160 END DEFine LALCHP

**NOTE 1**

ALCHP reserves memory in 512 byte chunks.

**NOTE 2**

Memory reserved by ALCHP is indirectly cleared by NEW, CLEAR, LOAD and
LRUN (this does not apply to the Btool extended variant - see above).

**WARNING 1**

Never run device drivers in the common heap - this memory can be easily
cleared, causing a spectacular crash if a device driver was stored
there. This is true for other machine code, too.

**WARNING 2**

There is no checking on the parameter for ALCHP - accordingly negative
values can be supplied. These are likely to lead to unexpected results
and will probably crash the computer - for example, x=ALCHP(-100)
crashes a JM ROM. On a Minerva ROM, values below -5 will return 0. On
SMS although only values below -20 return 0, any attempt to reclaim the
areas set aside with CLCHP or RECHP will crash the system.

**WARNING 3**

Since ALCHP returns 0 if there is not enough memory, you should always
check the value returned by ALCHP for this before writing to the
address. Otherwise, it is possible that you will be over-writing the
operating system... crash!

**CROSS-REFERENCE**

The reserved parts of memory can be given back to QDOS' memory
management by :ref:`rechp` base\_address or
:ref:`clchp`.

:ref:`respr`, :ref:`ttall`,
:ref:`allocation` and especially
:ref:`grab` and :ref:`reserve`
work similar to :ref:`alchp`.

See :ref:`del-defb` concerning heap
fragmentation.

--------------


..  _alias:

ALIAS
=====

+----------+------------------------------------------------------------------+
| Syntax   || ALIAS old\_keyword$ TO new\_keyword(ALIAS\_CODE) or             |
|          || ALIAS new\_keyword TO old\_keyword$(SAILA\_CODE)                |
+----------+------------------------------------------------------------------+
| Location || ALIAS (DIY Toolkit - Vol A)                                     |
+----------+------------------------------------------------------------------+

This command is similar to NEW\_NAME and REPLACE.

It allows you to assign another name to machine code Procedures and
Functions which are currently resident in memory. Both versions of the
command are the same, except that the second variant expects you to pass
the two parameters in the opposite order.

We shall deal with the first variant.

The first parameter (old\_keyword$) must appear as a string and is the
original name of the Procedure or Function which is to be renamed. The
second parameter (new\_keyword) is the new name to be used - this must
not appear as a string, but simply as the actual keyword to use.

The original definition is not lost and therefore you can still use the
original name to call the machine code procedure or function (as well as
the new name).

If old\_keyword$ does not contain the name of a machine code Procedure
or Function, then either a 'Not Found' or 'Bad Name' error will be
reported.

**Example**

Try the following short program:

::

    10 INPUT 'Enter Your Name: '; a$
    20 PRINT a$
    30 ALIAS 'INPUT' TO XINPUT
    40 XINPUT 'Enter My Name with XINPUT: '; s$
    50 INPUT 'You can still use INPUT to Enter your Name: ';t$
    60 PRINT s$ / t$

**NOTE 1**

Because the original definition is not lost, you can go on to assign
further 'aliases' to the original name, but any attempt to assign an
alias to the new name (XINPUT in the above example will give a Not Found
error).

**NOTE 2**

You should not use ALIAS from within programs compiled with TURBO and
SuperCharge.

**NOTE 3**

If a program compiled with TURBO or SuperCharge reports an error when
you try to EXECute the program, such as 'SYS\_VARS is Not Defined', you
could use ALIAS from SuperBASIC to circumvent this problem, for example
by using:

ALIAS 'SYSBASE','SYS\_VARS'

**NOTE 4**

The new alias is not converted by this command to uppercase - that is up
to you (not all keywords are in uppercase after all).

**NOTE 5**

You should not use all of the new names set with ALIAS in programs which
are to be compiled with TURBO or SuperCharge if you want to make the
most of those compilers. In particular, ALIASes of the following
keywords will cause problems:

RESPR (unless it has been redefined to work in the common heap before
you used ALIAS).

RUN, INPUT, READ, EOF, CLEAR, DIMN, STOP, NEW and various TURBO toolkit
commands.

You will also lose out on optimisations on the following:

PRINT, BLOCK, CODE, CHR$, LEN, PI, PEEK, PEEK\_W, PEEK\_L, POKE, POKE\_W
and POKE\_L.

**NOTE 6**

If you wish to use ALIAS for MODE and use Speedscreen, ensure
Speedscreen is loaded and enabled before you use ALIAS (Speedscreen
redefines MODE).

If you wish to use ALIAS for mathematical functions and use the
Lightning fast maths routines, again, ensure that Lighning maths is
loaded before you use ALIAS if you want the faster routines implemented
by Lightning.

**NOTE 7**

If you want to use this command from within a Multiple SBASIC on SMS or
a MultiBASIC on Minerva, you will need to use the variant of the command
implemented in the file SAILA\_CODE.

**CROSS-REFERENCE**

See also :ref:`replace` and
:ref:`new-name`.

:ref:`-name-dlr` allows you to look at the name
table.

--------------


..  _aline:

ALINE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ALINE x1,y1 TO x2,y2, Colour                                     |
+----------+-------------------------------------------------------------------+
| Location |  Shape Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command quickly draws a line between the specified absolute, window
independent co-ordinates, (x1,y1) and (x2,y2), on the screen. ALINE uses
XOR mode, which means that the line can be removed without destroying
the contents of the screen by drawing exactly the same line again. -
This does however mean that the colour of the line as it appears on
screen may not be the same as the specified parameter (see OVER -1).

**Example**

The procedure HAIRCROSS x,y allows you to move a cross wire around the
screen with the cursor keys, to alter the values of x and y. Press
<SPACE> to make x and y equal the new values, or press <ESC> to keep the
old values.

::

    100 DEFine PROCedure HAIRCROSS (px,py)
    110  LOCal Size,Key,Stepp,old_px,old_py
    120  Size=31 : old_px=px : old_py=py
    140  REPeat Move_it
    150    CROSS px,py
    160    REPeat Wait_for_key
    170      Key=KEYROW(1): Stepp=4*(KEYROW(7))+1
    180      IF Key THEN EXIT Wait_for_key
    190    END REPeat Wait_for_key
    200    CROSS px,py
    210    IF Key&&2 THEN px=px-Stepp
    220    IF Key&&16 THEN px=px+Stepp
    230    IF Key&&4 THEN py=py-Stepp
    240    IF Key&&128 THEN py=py+Stepp
    250    IF px<Size THEN px=Size
    260    IF px>511-Size THEN px=511-Size
    270    IF py<Size THEN py=Size
    280    IF py>255-Size THEN py=Size
    290    SELect ON Key
    300      =64: EXIT Move_it
    310      =8: px=old_px: py=old_py
    320          EXIT Move_it
    330    END SELect
    340  END REPeat Move_it
    350 END DEFine HAIRCROSS
    360 :
    370 DEFine PROCedure CROSS (ax,ay)
    380  ALINE ax-Size,ay-Size TO ax+Size,ay+Size ,7
    390  ALINE ax+Size,ay-Size TO ax-Size,ay+Size ,7
    400 END DEFine CROSS

**NOTE 1**

ALINE assumes that the screen starts at $20000 and will therefore not
work on Minerva's / Amiga QDOS's / QDOS Classic's second screen or on
higher resolution displays.

**NOTE 2**

ALINE also assumes that the screen measures 512x256 pixels and cannot
therefore work on higher resolution screens.

**NOTE 3**

ALINE only works in MODE 4.

**CROSS-REFERENCE**

:ref:`draw` has the same syntax as
:ref:`aline` but does not work in XOR
mode.\ :ref:`draw` is also able to draw lines on
screens stored in memory.

:ref:`line` and :ref:`line-r`
are much more flexible.

--------------


..  _allocation:

ALLOCATION
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  ALLOCATION (bytes [,taskno%,tasktag%])                           |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is very similar to RESERVE. It allocates an area in the
common heap which may be associated with a specified job. If taskno% and
taskid% are not specified, then the area is linked with the current job
and removed when the current job is removed.

**CROSS-REFERENCE**

:ref:`deallocate` should be used to remove the
allocated area.

The taskno% and taskid% can be found using
:ref:`jobs` or :ref:`list-tasks`.

--------------


..  _alt:

ALT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ALT                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch to the
alternative font (normally italics) on an EPSON compatible printer::

    PRINT #ch,ALT

is therefore equivalent to::

    PRINT #ch,CHR$(27)&"6"

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`esc`,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _alter:

ALTER
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ALTER 'variable' TO value                                        |
+----------+-------------------------------------------------------------------+
| Location |  ALTER (DIY Toolkit - Vol U)                                      |
+----------+-------------------------------------------------------------------+

This command works alongside SET from the same toolkit and allows you to
re-define the universal constants created with SET.

Unlike SET, the constant to be re-defined must appear in quotes as the
first parameter (otherwise the value of the constant is passed to be
altered by the command!!). As with SET, the constant and the value must
be of the same type, otherwise an 'error in expression' will be
reported.

If the constant has not previously been defined with SET, then if it is
recognised for some other reason an 'In Use' error will be reported. If
it is not recognised at all, then 'Not Found' will be reported.

Unlike SET, you can use ALTER from any program which is being used on
the QL and therefore you can use this to update constants or possibly
device names (or anything else you can invent).

**Example**

Set the following from SuperBASIC:

10 SET DEF\_DRIVE$ TO 'flp1\_'

If whilst using another program, the user re-defines the default device,
that program can use a line such as: ALTER 'DEF\_DRIVE$' TO
'win1\_prog\_' which will then alter the default device for all programs
which read this constant.

**NOTE**

ALTER does not work on SMS.

**CROSS-REFERENCE**

See :ref:`set`.

--------------


..  _altkey:

ALTKEY
======

+----------+-------------------------------------------------------------------+
| Syntax   || ALTKEY character$,string$ [,string2$ [,string2$... ]]  or        |
|          || ALTKEY character$  or                                            |
|          || ALTKEY                                                           |
+----------+-------------------------------------------------------------------+
| Location ||  Toolkit II                                                      |
+----------+-------------------------------------------------------------------+

This command defines a key macro which will be typed into the computer
when you press the <ALT> key at the same time as the <character$> key.
If more than one string follows the definition, then an <ENTER> (line
feed) character is inserted between each string.

ALTKEY without any parameters deletes all previously defined ALTKEYs,
whereas ALTKEY character$ will just kill the specified definition
(whether there was one or not).

A line feed will not be appended to the final string unless you add a
nul string to the definition.

**Example 1**

ALTKEY " ","RUN","" types in RUN <ENTER> if <ALT><SPACE> is pressed.

ALTKEY"a","flp1\_" types in flp1\_ when <ALT><A> is pressed.

ALTKEY removes all ALTKEY definitions.

ALTKEY "a" remove definition for <ALT><A>.

ALTKEY 1,"1000" same as ALTKEY "1","1000"

**Example 2**

There are many programs which do not support the Toolkit II default
device names and sub-directories.

To avoid having to enter FLP1\_Archive\_Adresses\_ in front of every
file name, one could compile the following line, then EXECute the
resultant program (using EX or EXEC) with the priority set to 1.

::

    100 PRIO 1
    110 REPeat Always
    120   ALTKEY "p",DATAD$
    130   ALTKEY "P",PROGD$
    140 END REPeat Always

You can replace PRIO by QP QMYJOB,1 with QLiberator or PRIORITY 1 with
Turbo, or SPJOB -1,1 with Toolkit II

**NOTE 1**

If character$ is an upper case letter, then you will need to press
<ALT><SHIFT> and the <key> (or <ALT><key> in CAPSLOCK) to call the
macro.

**NOTE 2**

The combination <ALT><ENTER> is always set aside for the last line
recall (ie. when these two keys are pressed all characters typed
inbetween the last two <ENTER>s are put into the keyboard buffer again).

**NOTE 3**

The Hotkey System is usually configured to type in the Hotkey Stuffer
contents if <ALT><SPACE> is pressed.

<ALT> <SHIFT> <SPACE> gets previous Stuffers.

**WARNING**

If you have Hotkey System II loaded, then ALTKEY will not have any
effect until you use the HOT\_GO command.

**CROSS-REFERENCE**

:ref:`force-type` and
:ref:`stamp` allow programs to access the keyboard,
:ref:`key` defines macros on function keys.

--------------


..  _and:

AND
===

+----------+-------------------------------------------------------------------+
| Syntax   |  condition1 AND condition2                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This combination operator combines two condition tests together and will
have the value 1 if both condition1 and condition2 are true or 0 if
either condition1 or condition2 are false.

A value is said to be false if it is equal to zero, anything else will
cause that value to be true.

Please note the difference between this and the bitwise and operator:
x&&y, which compares x and y bit by bit.

**Examples**

PRINT 1 AND 0 Returns 0

PRINT 12 AND 10 Returns 1

(compare PRINT 12&&10 which returns 8).

::

    10 FOR x=1 TO 5
    20   FOR y=1 TO 5
    30     IF x=3 AND y>3 THEN PRINT x;' => ';y,
    40   END FOR y
    50 END FOR x

produces the following output:

3=>4 3=>5

**CROSS-REFERENCE**

:ref:`or`, :ref:`not` and
:ref:`xor` are the other combination operators.

--------------


..  _apoint:

APOINT
======

+----------+-------------------------------------------------------------------+
| Syntax   |  APPOINT x,y,colour                                               |
+----------+-------------------------------------------------------------------+
| Location |  Shape Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is similar to POINT, except that it uses absolute
co-ordinates and plots the point in XOR mode (as with ALINE).

**NOTE**

APOINT suffers from the same problems and limitations as ALINE.

**CROSS-REFERENCE**

Use :ref:`point` instead!!

--------------


..  _append:

APPEND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  APPEND file1,file2                                               |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

This command allows you to merge two files together by appending file2
to the end of file1.

**NOTE**

Both file1 and file2 must include the device name.

**CROSS-REFERENCE**

The THOR XVI has a special form of :ref:`copy` which
is similar to this.

--------------


..  _aqconvert:

AQCONVERT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  AQCONVERT filename                                               |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command takes a file which is stored on a QL Format disk and
presumes that it was originally an Atari format file. It will then
convert special characters in that file to QL compatible characters as
well as converting any occurence of a Carriage Return character (CR)
followed by a Line Feed character (LF) to a single Line Feed character
LF.

**CROSS-REFERENCE**

Compare :ref:`iqconvert` and
:ref:`qaconvert`.

See also :ref:`acopy` and
:ref:`qcopy`.

--------------


..  _arc:

ARC
===

+----------+---------------------------------------------------------------------------------------------------------------------+
| Syntax   | ARC [#ch][,x\ :sup:`1`\ ,y\ :sup:`1`] TO x\ :sup:`2`\ ,y\ :sup:`2`\ ,angle :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] |
|          | TO x\ :sup:`j`\ ,y\ :sup:`j`\ ,angle\ :sup:`j`]\ :sup:`\*`                                                          |
+----------+---------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                              |
+----------+---------------------------------------------------------------------------------------------------------------------+

ARC causes the two points at the co-ordinates
(x\ :sup:`1`\ ,y\ :sup:`1`\ ) and (x\ :sup:`2`\ ,y\ :sup:`2`\ ) to be
connected with an arc. The arc is defined as the sector of the circle
formed by drawing two straight lines from the two given co-ordinates to
the centre of the circle, where angle is the angle (in radians) between
those two lines. Therefore, angle=0 is a straight line and angle=PI,
half a circle.

It therefore follows that the greater ABS(angle), the more pronounced is
the curve on the arc.

Multiple arcs can be draw with the same command by adding extra sets of
parameters for each additional arc. For example::

    ARC 100,10 TO 120,40,3 TO 80,70,3

will actually draw two arcs, one between the points (100,10) and
(120,40) with angle=3 and the second between the points (120,40) and
(80,70), also with angle=3.

When drawing multiple arcs, there is actually no need for the next arc
in the series to begin at the end of the previous arc, provided that a
semicolon ';' is inserted between each set of parameters. For example::

    ARC 100,10 TO 120,40,3;30,40 TO 50,60,3

Whether the arc is drawn clockwise or anti-clockwise depends upon two
factors: If y\ :sup:`1`\ >y\ :sup:`2` and angle>0, then the arc will be
drawn anti-clockwise. Swapping the two co-ordinates or making the angle
negative will force the arc to be drawn clockwise.

Co-ordinates refer to the window relative graphic co-ordinate system,
which is relative to the graphic origin. The size and position of the
arc also depend upon the SCALE of the window. If no first point is given
then the current position of the graphic cursor is used. The graphic
cursor is set to the last point of the arc on completion of the command.

**Example 1**

::

    100 WINDOW 448,200,32,16: CLS: SCALE 4,-2,-2
    110 FOR t=PI/16 TO 2*PI STEP PI/16
    120   ARC SIN(t),COS(t) TO COS(t),SIN(t),PI*SIN(t/2)
    130 END FOR t

**Example 2**

::

    100 WINDOW 448,200,32,16: CLS: SCALE 100,0,0
    110 FOR x=10 TO 90 STEP 10
    120   FOR y=10 TO 90 STEP 10
    130     ARC x,y TO y,x,PI/2
    140   END FOR y
    150 END FOR x

**Example 3**

::

    100 POINT #2,150,50
    110 FOR x=50 TO 150 STEP 20
    120   ARC #2 TO x,50,PI/2
    130 END FOR x

**NOTE 1**

On non Minerva v1.89+ ROMs, ARC does not work properly - small angles
produce rubbish, wrong co-ordinates are used and the last pixel of the
arc is not always drawn. Even SMS does not cure these problems.

**NOTE 2**

An angle of 2\*PI would form a complete circle and cannot be drawn,
therefore the maximum value for ABS(angle) is a value just less than
2\*PI.

**NOTE 3**

On some ROM versions, the command does not check that the TO separator
is present - however, SMSQ/E (at least) does and therefore some programs
may fail if used under SMSQ/E and they have used a comma instead of TO.

**WARNING**

Some QDOS implementations of this command can corrupt the hard disk
drive in some obscure circumstances. Get Minerva or SMSQ/E to be safe!!

**CROSS-REFERENCE**

:ref:`arc-r` works in exactly the same way as
:ref:`arc` but uses a relative co-ordinate system,
where the origin is the current position of the graphic cursor.

:ref:`scale` sets the graphic origin and also the
size of the window.

--------------


..  _arc-r:

ARC\_R
======

+----------+------------------------------------------------------------------------------------------------------------------------+
| Syntax   | ARC\_R [#ch][,x\ :sup:`1`\ ,y\ :sup:`1`] TO x\ :sup:`2`\ ,y\ :sup:`2`\ ,angle :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] | 
|          | TO x\ :sup:`j`\ ,y\ :sup:`j`\ ,angle\ :sup:`j`]\ :sup:`\*`                                                             | 
+----------+------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                 |
+----------+------------------------------------------------------------------------------------------------------------------------+

This command draws an arc relative to the current graphic cursor. This
means that rather than the co-ordinates (x,y) being relative to the
graphic origin, they are relative to the current graphic cursor. Arcs
are however still affected by the current SCALE.

Each set of co-ordinates used in the ARC\_R command moves the graphic
cursor, which means for example that (x\ :sup:`1`\ ,y\ :sup:`1`\ ) is
relative to the graphic cursor when ARC\_R is first called, whereas
(x\ :sup:`2`\ ,y\ :sup:`2`\ ) is relative to
(x\ :sup:`1`\ ,y\ :sup:`1`\ ).

**Example 1**

A short program to draw several equi-distant arcs using ARC\_R:

::

    100 WINDOW 448,200,32,16:SCALE 100,0,0
    110 PAPER 0:INK 4:CLS
    120 ARC 20,20 TO 90,20,PI/4
    130 FOR i=1 TO 4
    140   ARC_R 0,10 TO -70,0,-PI/4
    150   ARC_R 0,10 TO 70,0,PI/4
    160 END FOR i

**Example 2**

The same routine, but altered to use ARC:

::

    100 WINDOW 448,200,32,16:SCALE 100,0,0
    110 PAPER 0:INK 4:CLS
    120 ARC 20,20 TO 90,20,PI/4
    130 FOR i=30 TO 100 STEP 10
    140   ARC 20,i TO 90,i,PI/4
    150 END FOR i

**CROSS-REFERENCE**

The graphic cursor is moved with commands such as
:ref:`point`, :ref:`arc`,
:ref:`circle` and :ref:`line`.

Please also see :ref:`arc`.

--------------


..  _arcosh:

ARCOSH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ARCOSH (x)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

This function returns the arc hyperbolic cosine of the specified value,
that is to say it will return the value which must be passed to the
hyperbolic cosine to return the given result, so::

    COSH ( ARCOSH ( x )) = x

The ARCOSH function can be expressed as a combination of SuperBASIC
keywords: it's the same as::

    LN(x + SQRT(x*x-1)).

**CROSS-REFERENCE**

See :ref:`acos`, :ref:`asin`,
:ref:`acot`, :ref:`atan`,
:ref:`cosh`, :ref:`arcoth`,
:ref:`arsinh` and
:ref:`artanh`.

--------------


..  _arcoth:

ARCOTH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ARCOTH (x)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

This function returns the arc hyperbolic cotangent of the specified
value ie.

ARCOTH ( COTH ( x )) = x

Or to keep it simple, it can be returned with the equivalent expression
LN((x+1) / (x-1)) / 2

**CROSS-REFERENCE**

See :ref:`acot`, :ref:`arcosh`,
and :ref:`artanh`.

--------------


..  _arsinh:

ARSINH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ARSINH (x)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

This function is the arc hyperbolic sine (ie. the complementary function
to SINH).

The SuperBASIC expression:

LN(x + SQRT(x\*x-1))

gives the same value.

**CROSS-REFERENCE**

See :ref:`asin`, :ref:`arcosh`,
and :ref:`arcoth`.

--------------


..  _artanh:

ARTANH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ARTANH (x)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

The function ARTANH returns the value which must be passed to TANH to
give the specified result, so:

TANH ( ARTANH ( x )) = ARTANH ( TANH ( x )) = x

ARTANH(x) could be replaced by: LN((1+x) / (1-x)) / 2

**CROSS-REFERENCE**

See :ref:`atan`, :ref:`arcoth`,
and :ref:`arsinh`.

--------------


..  _asin:

ASIN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ASIN (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function calculates the arc-sine (in radians) which is the opposite
of the sine function, ie:

x = SIN ( ASIN ( x )) = ASIN ( SIN ( x ))

The only valid values of x are in the range -1...1. This means that the
range of angles supported by this command are -PI/2...PI/2. A negative
angle means that the hypotenuse appears below the base line of the
triangle (you must therefore always bear the orientation of the screen
in mind when using this command).

**Example**

Given that there are two points on the screen at (10,20) and (100,75),
find the angle of the line between those two points (from the
horizontal):

::

    100 PRINT CALC_ANGLE(10,20 TO 100,75)
    110 STOP
    120 :
    200 DEFine FuNction CALC_ANGLE(x1,y1,x2,y2)
    210  LOCal Distan, Radian_angle
    220  Distan = SQRT((x2-x1)^2 + (y2-y1)^2)
    230  Radian_angle = ASIN((y2-y1) / Distan)
    240  RETurn DEG(Radian_angle)
    250 END DEFine

**MINERVA NOTE**

On a Minerva you can replace line 220 with: 220 Distan =
ABS(x2-x1,y2-y1)

**CROSS-REFERENCE**

:ref:`acos`, :ref:`atan`,
:ref:`acot` are other arc functions,
:ref:`sin`, :ref:`cos`,
:ref:`tan` and :ref:`cot`\ their
relatives.

Please also see the Mathematics section of the Appendix.

Compare :ref:`arsinh`.

--------------


..  _ask:

ASK
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ASK ([#wind,] question$)                                         |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

ASK is a function which prints the question$ (plus a question mark (?)
if this was not found at the end of the string), enables the text cursor
and reads the keyboard. If the next key pressed is <Y> (for Yes), <J>
(for Ja) or <N> (for No or Nein) then ASK will disable the cursor, echo
the key next to the prompt and return 1 if either <Y> or <J> was
pressed, or 0 if <N> was pressed. If any other key is pressed, ASK will
BEEP and try again.

**Example**

In early computer days, this was a classical game which needed a hundred
lines on a (modern at the time) programmable pocket calculator:

::

    100 CLS: x1 = 0: x2 = 100
    110 PRINT "I am going to find out a number"
    120 PRINT "from"!x1!"to"!x2!"which only you know."\\
    130 REPeat find_out
    140   PRINT x1;"..";x2
    150   x = (x2+x1) DIV 2
    160   ok = ASK("Is it "&x)
    170   IF ok THEN EXIT find_out
    180   IF x1 = x2 THEN PRINT "You are cheating.": STOP
    190   large = ASK(x&" too large")
    200   IF large THEN x2 = x-1: ELSE x1 = x+1
    210 END REPeat find_out
    220 PRINT "Yippee, I found it."

**NOTE**

ASK is set up for 'yes' and 'no' in English and 'ja' and 'nein' in
German. For other languages where 'yes' is not usually connected with
<Y>, eg. 'oui' in French or 'si' in Spanish, you will need to write your
own routine.

**CROSS-REFERENCE**

:ref:`cur`, :ref:`reply`.

--------------


..  _astat:

ASTAT
=====

+----------+--------------------+
| Syntax   |  ASTAT [#channel,] |
+----------+--------------------+
| Location | ATARIDOS           |
+----------+--------------------+

This command is similar to ADIR except that it also provides extra
information, such as the length of each file, the update time and any
marks folder.

**CROSS-REFERENCE**

See :ref:`adir`. :ref:`wstat` is
similar on QL Format disks.

Other commands added are :ref:`adelete`,
:ref:`acopy` and
:ref:`aformat`.

--------------


..  _at:

AT
==

+----------+-------------------------------------------------------------------+
| Syntax   || AT [#ch,] row, column  or                                        |
|          || AT [#ch,] column,row (pre AH ROMs only)                          |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command sets the current print position in the given window
(default #1) to the given row and column number. The top left hand
corner of any window is always the position (0,0), however, the maximum
values of the row and column numbers depends on both the size of the
window and the current character size. Anything outside of this will
give the error 'Out of Range' (-4).

Unlike the PRINT parameter TO, this command does not print any spaces on
screen, thus allowing you to place text precisely on screen without
deleting any other parts of the screen.

Unfortunately for users who learnt to program on early versions of
Sinclair BASIC (on the ZX81 or Spectrum), this command is implemented
differently.

Some implementations of BASIC allow you to set the print position from
within the PRINT command, for example:

PRINT AT 3,5;'Hello'

On the QL, you would need the line:

AT 3,5: PRINT 'Hello'

**Example**

A program which uses the AT command to create an interesting effect on
screen. This will not work on pre JS ROMs as it relies upon the WHEN
ERRor command:

::

    1000 WHEN ERRor
    1010   IF ERR_OR THEN dir1=-dir1: y=y-2: RETRY 1070
    1020 END WHEN
    1025 :
    1030 MODE 4:WINDOW 448,200,32,16:CSIZE 0,0
    1040 x=0: dir1=1
    1050 FOR y=0 TO 63
    1060   AT x,y:PRINT 'Sinclair QL'
    1070   x=x+dir1
    1080 END FOR y

**NOTE**

On early QL ROMs (pre AH), the parameters were mixed up meaning that the
syntax was AT column,row. This can of course create many problems in
uncompiled SuperBASIC, however, there should not be many of these
machines left.

If you do have one of these early machines, it is recommended that you
do update the ROM.

**CROSS-REFERENCE**

:ref:`csize` sets the current character size for the
given window

:ref:`window` alters the physical size of a given
window.

:ref:`cursor` allows you to set the print position
more exactly.

:ref:`print` actually prints things on screen at the
current print position.

:ref:`ver-dlr` allows you to check the ROM version.

Also see :ref:`left`.

--------------


..  _atan:

ATAN
====

+----------+-------------------------------------------------------------------+
| Syntax   || ATAN (x)  or                                                     |
|          || ATAN (x,y) (Minerva and SMS only)                                | 
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function ATAN, is the arc-tangent function, that is to say the
inverse of the tangent function (TAN in SuperBASIC).

TAN ( ATAN ( x )) = x

for all values of x, but due to the fact that TAN works on periods; ATAN
( TAN ( x )) = x

is only true for where: -PI/2 < x < PI/2.

A negative angle indicates that the hypotenuse appears below the base
line of the triangle, and it is therefore important to bear in mind the
orientation of the screen when using this command.

**NOTE 1**

Because trigonometrical functions are calculated using polynomial
approximations, large parameters can produce small errors.

For example, on all implementations:

PRINT TAN (ATAN ( 123456 ))

gives 123461.2 instead of 123456.

The maximum error rises in direct proportion to the parameter for the
above example.

**NOTE 2**

There is a very obscure bug contained in the code for ATAN which means
that the command may crash on non-Minerva ROMs if used in a program
which is longer than 32K.

**MINERVA NOTE**

ATAN can accept two parameters. If you specify two parameters then
ATAN(x,y) will give the angle from the origin to the point (x,y). This
is actually the same as ATAN(y/x), although it does also cater for when
x=0 which would otherwise give an overflow error.

This variant also supports a full circle, for example the following can
be used to calculate the bearing travelled (with 0 degrees being north),
given that you have moved x miles east (or west if x<0) and y miles
north (or south if y<0):

::

    100 DEFine PROCedure BEARING (x,y)
    110 direction=DEG (ATAN (y,x))
    120 IF x>=0: RETurn direction: ELSE RETurn 360+direction
    130 END DEFine

The need for line 120 is because the value returned by ATAN is in the
range -PI ... PI (which converts to -180 ... +180 degrees) - the value
returned needs to be in the range 0 ... 360. Note that x and y are
swapped around in line 110 - this is to circumvent the problem that a
bearing of 0 is north, whereas in the mathematical functions, a zero is
taken to be horizontal.

**SMS NOTE**

The ATAN function has been extended to be the same as on Minerva,
although the range of values it returns have been made into four
quadrant results (as with ATN2 ), so that for ATAN(x,y) if x>0, the
result is now in the range -PI/2...PI/2 instead of the usual 0...PI.

**CROSS-REFERENCE**

:ref:`tan`, :ref:`atn`,
:ref:`atn2` and :ref:`artanh`.
Also please refer to the Mathematics section in the Appendix.

--------------


..  _atari:

ATARI
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ATARI                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

On the Atari QL-Emulator, this command switches to Atari mode.
Naturally, on other machines, it has no effect. It will also fail if a
QL ROM was found at the start address of the ROM-TOS ($FC0000) - it is
possible to load QDOS to that address.

**NOTE**

The FN Toolkit (pre v1.04) contained a function of the same name which
had a different effect - this has now been renamed QuATARI (see below).

**WARNING**

This command will most probably fail on the latest ST/QL drivers.

**CROSS-REFERENCE**

See :ref:`quatari`.

--------------


..  _atari-ext:

ATARI\_EXT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  ATARI\_EXT                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v2.15+)                                             |
+----------+-------------------------------------------------------------------+

The Atari QL-Emulators come with the additional toolkits, ATARI\_REXT
and ATARIDOS.

This command is used to enable various commands in the ATARI\_REXT
toolkit as well as the sound extensions (such as BELL).

It therefore replaced the original SND\_EXT command.

**WARNING**

ATARI\_REXT pre v2.37 may crash SMS.

**CROSS-REFERENCE**

See :ref:`tk2-ext` and
:ref:`beule-ext`.

See also :ref:`snd-ext`.

--------------


..  _atn:

ATN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ATN (x)                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function is the same as the original QL ROM variant of ATAN.

**NOTE**

ATN has been implemented to make porting programs written in other BASIC
dialects easier.

**CROSS-REFERENCE**

See :ref:`atan`.

--------------


..  _atn2:

ATN2
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ATN2 (x,y)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

ATN2 calculates ATAN(x/y) but expands the result from 0...PI to -PI...PI
which allows you to convert cartesian and polar co-ordinates in both
directions without loss of information.

**Example**

Run this graphics demonstration and you will understand the advantage of
ATN2 and the difference from ATAN:

::

    100 WTV 4: SCALE 4,-3,-2: INK 7
    110 PAPER 0: OVER -1: CLS
    120 radius=1.5: reso=128
    130 FOR angle0=PI/reso TO 2*PI STEP PI/reso
    140   x0=radius*COS(angle0): y0=radius*SIN(angle0)
    150   angle1 = ATAN(y0/x0)
    160   x1=radius*COS(angle1): y1=radius*SIN(angle1)
    170   angle2 = ATN2(x0,y0)
    180   x2=radius*COS(angle2): y2=radius*SIN(angle2)
    190   ARRAYS: PAUSE 2: ARRAYS
    200 END FOR angle0
    210 :
    220 DEFine PROCedure ARRAYS
    230  INK 3
    240  FILL 1: CIRCLE 1.25*x0,1.25*y0,5E-2: FILL 0
    250  IF x1==x2 AND y1==y2 THEN
    260    INK 7: LINE x1/5,y1/5 TO x1,y1: INK 5
    270    CURSOR x1,y1,0,0: PRINT "ATAN/ATN2"
    280  ELSE
    290    INK 7: LINE x1/5,y1/5 TO x1,y1: INK 5
    300    CURSOR x1,y1,0,0: PRINT "ATAN"
    310    INK 7: LINE x2/5,y2/5 TO x2,y2: INK 5
    320    CURSOR x2,y2,0,0: PRINT "ATN2"
    330  END IF
    340  angle=INT(DEG(angle0))
    350  CURSOR 0,0,-3*LEN(angle),-5: PRINT angle
    360 END DEFine ARRAYS

**CROSS-REFERENCE**

:ref:`atan` which is the same on Minerva and SMS.

--------------


..  _auto:

AUTO
====

+----------+-------------------------------+
| Syntax   | AUTO [start\_number][,step]   |
+----------+-------------------------------+
|Location  | QL ROM                        |
+----------+-------------------------------+

This command automatically creates line numbers in the command line (#0)
to assist in entering SuperBASIC programs. It would normally only be
entered as a direct command (although you can include it in a program
line, the line numbers will not be generated until the program has
finished its work).

Once entered, you will be presented with the first line start\_number
(default 100) - if this line already exists in the program, then the
existing line will be presented. Otherwise, you will only see the
current line number. Pressing the up and down arrow keys will move you
to the previous line or the next line (respectively) in the program,
although if there is no previous (or next) line, then you will exit the
AUTO mode. However, if you press the Enter key, the next line number
will be generated by adding step (default 10) to the current line
number.

If you wish to escape this sequence, press the Break key <CTRL><SPACE>.

**Example 1**

Generating program lines: AUTO 1000,10

generates lines 1000,1010,1020,1030,... AUTO 10

generates lines 10,20,30,40,.... AUTO ,5

generates lines 100,105,110,115,...

**Example 2**

Adding line numbers to a numberless boot program: AUTO 100,10: MERGE
flp1\_boot

**NOTE 1**

A step value of zero returns 'Bad Parameter' (-15). You can however
achieve this by using EDIT start\_number instead.

**NOTE 2**

Did you realise that AUTO 200,10 is the same as EDIT 200,10 ?

**NOTE 3**

On non-Minerva ROMs AUTO uses the same routine as RENUM to check its
parameters, which means that you can specify a start\_line and an
end\_line, although they do nothing. For example:

AUTO 100 TO 1000;1000,20

would create lines 1000,1020,1040,...

**NOTE 4**

The maximum line number is 32767 - trying to use a higher line number
will cause an overflow error.

**NOTE 5**

If start\_number and step are not integer numbers, they will be rounded
either up or down to the nearest integer (compare INT).

**SMS NOTE**

On current versions of SMS AUTO has been re-coded to be the same as ED,
therefore it will not allow a second parameter, and merely places you in
ED mode with the cursor at the specified start line number.

**CROSS-REFERENCE**

Please refer to :ref:`edit` which is very similar.

:ref:`dline` allows you to delete SuperBASIC lines.

--------------


..  _auto-dis:

AUTO\_DIS
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  AUTO\_DIS                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Super Gold Card, Gold Card v2.67+                                |
+----------+-------------------------------------------------------------------+

The Super Gold Card allows you to automatically start-up the QL
(overcoming the need to press F1 or F2 on the title screen), and also
automatically start up Toolkit II.

This command switches off these features.

**NOTE 1**

On Minerva these commands only dictate whether Toolkit II should
automatically be started up, as Minerva contains its own auto-boot code.

**NOTE 2**

These commands have no effect under SMSQ/E which already includes
Toolkit II and does not show a start-up screen.

**CROSS-REFERENCE**

See\ :ref:`auto-tk2f1` and
:ref:`auto-tk2f2` also.

--------------


..  _auto-tk2f1:

AUTO\_TK2F1
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  AUTO\_TK2F1                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Super Gold Card, Gold Card v2.67+                                |
+----------+-------------------------------------------------------------------+

The Super Gold Card allows you to automatically boot up the machine
whenever it is switched on or reset.

This command enables this auto-booting (starting the machine up in
Monitor mode) and also ensures that Toolkit II is initialised as soon as
the machine is switched on. The status set by this command is remembered
by the Super Gold Card even when the power is disconnected.

**CROSS-REFERENCE**

See also :ref:`auto-dis` and
:ref:`auto-tk2f2`.

:ref:`tk2-ext` is needed to initialise Toolkit II
if this command has not been used.

--------------


..  _auto-tk2f2:

AUTO\_TK2F2
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  AUTO\_TK2F2                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Super Gold Card, Gold Card v2.67+                                |
+----------+-------------------------------------------------------------------+

This command is the same as AUTO\_TK2F1 except that the machine is
started up in F2 TV mode.

**CROSS-REFERENCE**

See\ :ref:`auto-tk2f1`.

--------------


..  _a-blank:

A\_BLANK
========

+----------+----------------------------------------+
| Syntax   |  A\_BLANK [minutes]                    |
+----------+----------------------------------------+
| Location | ST/QL (Pre v2.24)                      |
+----------+----------------------------------------+

This command creates a small job which blanks out the screen if a key
has not been pressed for a specified number of minutes (default 5).

This command is useful, because if a very bright picture is drawn on
screen (eg. a white line on black paper), and the screen does not alter,
this can lead to what is known as 'burn in' when the monitor screen
becomes permanently marked with the 'ghost' of the picture. This does
not tend to happen very often nowadays, but in the past, monitors tended
to become unuseable as more and more of their screen became covered with
these 'ghosts'.

**NOTE**

This command will only work within the Pointer Environment.

**CROSS-REFERENCE**

:ref:`bls` is a similar function under SERMouse.

--------------


..  _a-emulator:

A\_EMULATOR
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_EMULATOR                                                      |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT v2.22+                                               |
+----------+-------------------------------------------------------------------+

This function returns a number to signify the type of ST/QL EMulator
which is being used with the Atari computer. The value returned may be
one of the following:

-  0 - QL Emulator (the original QL Emulator)
-  1 - Extended-Mode4 Emulator
-  2 - QVME Emulator

**NOTE 1**

This will only work with Level E-20 of the Drivers or later.

**NOTE 2**

It is impossible to tell whether the original QL Emulator supports MODE
8 or not.

**NOTE 3**

You can also use DISP\_TYPE to find out the Emulator type.

**CROSS-REFERENCE**

See also :ref:`processor` and
:ref:`machine`.

--------------


..  _a-machine:

A\_MACHINE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_MACHINE                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT v2.22+                                               |
+----------+-------------------------------------------------------------------+

This function is the same as MACHINE.

**CROSS-REFERENCE**

See\ :ref:`machine` and also
:ref:`a-emulator`.

--------------


..  _a-oldscr:

A\_OLDSCR
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_OLDSCR                                                        |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v2.27+)                                             |
+----------+-------------------------------------------------------------------+

A lot of software (mainly non-pointer driver programs), and some of the
toolkits covered by this book, written for the Sinclair QL in the past
always assumed that the QL screen would appear at the memory location
131072 ($20000 in hexadecimal).

These programs and toolkits will not work properly (if at all) on the
QVME board or some higher resolution screens. One of the solutions to
this is to use the command A\_OLDSCR which forces ST/QL Emulators to set
up a Job copying the QL's screen as stored at 131072 (onwards) to the
real display screen 20 times a second. This obviously slows down the
operation of the computer and thus if possible, a new version of the
software should be produced / obtained.

As from v2.30, this command will not affect the display speed as much on
a machine fitted with a blitter chip.

**NOTE 1**

This command cannot fix the problem with programs and toolkits which
assume that the QL's display is 512x256 pixels.

**NOTE 2**

This command reports 'Not Implemented' on other ST-QL Emulators.

**NOTE 3**

SuperBasic (Job 0) must be the only Job running on the machine when this
command is issued, otherwise the error 'Not Complete' is reported.

**NOTE 4**

If you try to use this command after it has already been issued, the
errror 'Already Exists' is reported.

**CROSS-REFERENCE**

:ref:`screen` can be used to find the screen
address.

:ref:`scr-size` can be used to set the
resolution of the display - much software will insist that this is set
to 512x256 pixels also.

--------------


..  _a-processor:

A\_PROCESSOR
============

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_PROCESSOR                                                     |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT v2.22+                                               |
+----------+-------------------------------------------------------------------+

This function is the same as PROCESSOR.

**CROSS-REFERENCE**

See :ref:`processor`!

--------------


..  _a-rdate:

A\_RDATE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_RDATE                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v2.10+)                                             |
+----------+-------------------------------------------------------------------+

This command sets the QL's internal clock to the date and time contained
in the battery-backed clock on the ST (if available).

**NOTE**

Before v2.28, this command did not support the TT's battery backed
clock.

**CROSS-REFERENCE**

See :ref:`a-sdate`.

--------------


..  _a-sdate:

A\_SDATE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_SDATE year, month, day, hour, minute, second                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

The Atari ST has a built in battery-backed clock which maintains the
time whilst the machine is switched off. This time is automatically
copied across to the Emulator's own internal clock when the Atari ST is
started up. However, it can be necessary to alter the Atari's battery
backed clock.

This is achieved by using the command A\_SDATE in exactly the same way
as you would use SDATE to set the internal clock.

**NOTE 1**

Before v2.19 of Atari\_rext (and in v2.23), this command will not alter
the Emulator's internal clock until the Atari is reset.

**NOTE 2**

Before v2.29, this command did not support the TT's battery backed
clock.

**CROSS-REFERENCE**

See :ref:`sdate`.

:ref:`a-rdate` will set the internal clock to the
same date and time as the battery backed clock.

--------------


..  _a-speed:

A\_SPEED
========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_SPEED value                                                   |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

Due to the enhanced hardware on which the ST/QL Emulator is running, you
may find that as with the QXL, Super Gold Card and Gold Card, some
programs run too quickly. The command A\_SPEED allows you to slow the
Emulator down so that you can use these programs. value must be in the
range 0..7.

0 allows the Emulator to run at full speed, whereas 7 makes it run very
slowly.

**CROSS-REFERENCE**

:ref:`slug` is very similar.

