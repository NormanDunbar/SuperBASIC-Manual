
==========
Keywords I
==========

TODO
====

- Fix that table in I2C\_IO - it's far too wide!
- DISP_COLOUR is linked from :ref:`ink` in this file, but DISP_COLOUR is not in KeywordsD.
- :ref:`is-basic` references JOB_NAME$ for Minerva but it's not listed in any source file.


..  _i2c-io:

I2C\_IO
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  I2C\_IO (cmd$, res\_len [,device [,param ]] )                    |
+----------+-------------------------------------------------------------------+
| Location |  Minerva extensions                                               |
+----------+-------------------------------------------------------------------+

The Minerva MKII operating system comes complete with a battery backed
clock and a small amount of on-board RAM (256 bytes) which can be used
to store various details whilst a machine is switched off, using some of
those details to dictate the state of the machine when it is first
switched on (or re-set). 

An on-board serial bus is also included which
can be used to link add-on interfaces and can transfer data at speeds up
to 100kbits per second. 

Interfaces currently exist to allow the QL to
drive motors (up to 4 amps), relay switches (up to 3 amps) and an
Analogue to Digital converter. 

The I2C\_IO function allows you to access the
battery backed clock, RAM and other interfaces provided by Minerva MKII,
through what is known as the I\ :sup:`2`\ C bus. The results of the
function will be returned by way of a string. 

The cmd$ should contain a
series of bytes which are sent to the I\ :sup:`2`\ C bus to be sent to
the device pointed to by the other parameters. This is normally a byte
which represents a command, followed by the parameters for that command.

For the battery backed clock and RAM supplied with Minerva MKII, there
are only three commands which are required: 

- CHR$(164) -Write param bytes to the specified device. The first byte to be written should in fact be
  the memory address to write to. Param can be altered by preceding the
  command character in the cmd$ by the number of bytes to write (eg.
  CMD$=CHR$(6)&CHR$(164)&CHR$(36)&'HELLO' will write the string 'HELLO' to
  memory address 36 in the RAM). If you only use this to write one byte,
  then this will merely set the memory address for access by further Write
  or Read commands. 

- CHR$(188) -Read param bytes from the specified device.
  Again, you can precede this command character by the number of bytes to
  be read if you wish. The bytes which are read will be returned as the
  resultant string. 

- CHR$(255) -This signifies the end of the command
  string. 
  
The other parameters allowed by the function are: 

- Res\_len which signifies the expected length of the return string , which must not be too short!! 
- Device signifies which device is to be accessed. The value 80 is used to access the battery backed RAM. 
- Param depends upon the command being sent via cmd$. 

The on-board RAM is allocated as follows:

+---------+-----------------------------------------------------------------------------+
| Bytes   | Meaning                                                                     |
+=========+=============================================================================+
| 0-15    | Reserved for the clock and other things set by the configuration program.   |
+---------+-----------------------------------------------------------------------------+
| 16-19   | QDOS version number (if this is different to the string returned by VER$,   | 
|         | then the rest of the configuration data stored in the RAM will be ignored). | 
+---------+-----------------------------------------------------------------------------+
| 20-23   | Warm reset value (as per CALL 390) to be used when the QL is re-booted.     |
+---------+-----------------------------------------------------------------------------+
| 24-25   | Year\*2+month DIV 10 (do not amend!)                                        |
+---------+-----------------------------------------------------------------------------+
| 26-27   | Copy of locations 22 and 23 - this is used to reset the system if the the   |
|         | values in locations 20-23 do not make any real sense (do not amend)         |
+---------+-----------------------------------------------------------------------------+
| 28-29   | Each bit in these two locations can be set to disable up to 16 plug-in ROMs |
|         | linked to the QL (bit 7 of location 28 represents the ROM which             |
|         | appears at the top of the F1...F2 screen when the QL is reset, bit 6        |
|         | represents the second ROM and so on).                                       |
+---------+-----------------------------------------------------------------------------+
| 30      | NET station number                                                          |
+---------+-----------------------------------------------------------------------------+
| 31      | System Enhancements (equivalent to POKE !124!49,x)                          |
+---------+-----------------------------------------------------------------------------+
| 32      | SuperBasic Enhancements (equivalent to POKE \\\\212,x)                      |
+---------+-----------------------------------------------------------------------------+
| 33-34   | RESERVED                                                                    |
+---------+-----------------------------------------------------------------------------+
| 35      | Length of boot string (0 to 128)                                            |
+---------+-----------------------------------------------------------------------------+
| 36-163  | Boot string or user area                                                    |
+---------+-----------------------------------------------------------------------------+
| 164-251 | RESERVED                                                                    |
+---------+-----------------------------------------------------------------------------+
| 252     | SER1 device (see below)                                                     |
+---------+-----------------------------------------------------------------------------+
| 253     | SER2 device (see below)                                                     |
+---------+-----------------------------------------------------------------------------+
| 254     | PAR device (see below)                                                      |
+---------+-----------------------------------------------------------------------------+
| 255     | RESERVED                                                                    |
+---------+-----------------------------------------------------------------------------+

The bytes contained in locations 
252 - 254 are intended for use by programs to find out if printers or modems are
connected and what type they are. The values currently supported are:-

- 0: Nothing connected to this port 
- 1-23: Printer type (as per SDUMP command)
- 253: Tandata Modem 
- 254: Astracom 'Native' Modem 
- 255: Astracom Hayes-Compatible Modem

**Example**

You can use this command to make the QL always start up by loading a
specified program::

    startup$ = CHR$(232) & 'LRUN win1_ROUTE_boot' & CHR$(10)
    command$ = CHR$(164) & CHR$(35) & CHR$ (LEN (startup$)) & startup$ & CHR$ (255) 
    PRINT IC2_IO (command$, 0, 80, LEN (startup$) + 1)

**CROSS-REFERENCE**

Some expansion boards have their own in-built battery backed clock,
which may need to be protected from programs which re-set the system
clock for their own purposes using :ref:`sdate`. 

See :ref:`prot-date`. 

Because Minerva MKII's battery backed clock is read through the I\ :sup:`2`\ C bus, it cannot
be affected by programs, unless you abuse the :ref:`i2c-io` function!!

--------------


..  _idec-dlr:

IDEC$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  IDEC$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function is exactly the same as CDEC$ except that it does not
place commas between the characters to the left of the decimal point.

**CROSS-REFERENCE**

See :ref:`cdec-dlr`.

--------------


..  _if:

IF
==

+----------+-------------------------------------------------------------------+
| Syntax   |  IF condition .....                                               |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is used to mark the start of yet another powerful
SuperBASIC structure which allows a program to perform various functions
dependent upon the status of a condition. The condition will always be
interpreted as having either the value 1 (true) or 0 (false), using
boolean logic if necessary. Such conditions may be simple, such as x=2
or complex, as in x=3 AND (y=1 OR y=2). 

There are actually two forms of
the SuperBASIC structure:

IF condition {THEN \| :} statement :sup:`\*`\ [:statement]\ :sup:`\*` [:ELSE statement :sup:`\*`\ [:statement]\ :sup:`\*`] 

or 

IF condition [{THEN \| :}] :sup:`\*`\ [:statement]\ :sup:`\*` ... [ELSE] :sup:`\*`\ [:statement]\ :sup:`\*` ... END IF

The first syntax represents in-line code, and the keyword THEN can
either appear or be replaced by a colon (:). If the condition is true,
the statements following THEN (or :) are executed, until the end of the line is
reached. There is actually no need for a colon after THEN, for example
the following are all the same::

    IF x=1 : PRINT 'x is 1' 
    IF x=1 THEN PRINT 'x is 1' 
    IF x=1 THEN:PRINT 'x is 1'

If during processing of the statements following THEN, a corresponding
ELSE keyword is found, the interpreter will search the line for the
corresponding END IF, in which case control will jump to the statement
following the END IF. If however, the line does not contain a
corresponding END IF, as with all other types on in-line code, control
will jump to the next program line. 

On the other hand, if the condition
is false, the interpreter will search the line for the corresponding
ELSE, which, if found, will force control to jump to the first statement
following ELSE. Control then just continues along the program line and
to the next program line. Note that a colon must appear before the word
ELSE, and although not strictly necessary after the word ELSE, it is
advisable to place a colon after the ELSE keyword (see the Note below).

If ELSE does not appear, control is passed to the statement following
the corresponding END IF, or if not present, the next program line. 

The second syntax represents the much more flexible long-form of the IF..END
IF statement. On the first line containing the IF condition, the keyword
THEN may be replaced by a colon, or even omitted altogether. If the
condition is true, control is passed to the next program line. If during
interpretation, an ELSE statement is found, the interpreter searches for
the corresponding END IF and passes control to the statement following
this. 

If the condition is false, the interpreter once again searches for
a corresponding ELSE. If this is not present, then control is passed to
the next statement after the corresponding END IF. If on the other hand,
ELSE is present, control passes to the statement following ELSE (which
may be on the same line as the ELSE keyword). There is no need to follow
ELSE by a colon in this long form.

**Example 1**

A short program to move a cross around the screen, using the keys
<N>orth, <S>outh, <E>ast and <W>est, press <ESC> to leave program:: 

    100 WINDOW 448,200,32,16:PAPER 0:CLS 
    110 x=224:y=100:OVER 0:INK 7 
    120 CURSOR x,y:PRINT 'X':OVER -1 
    130 REPeat loop 
    140 dir$=INKEY$(-1) 
    150 old_x=x:old_y=y 
    160 IF dir$ INSTR 'nesw' 
    170 IF dir$=='n':IF y>0:y=y-1
    180 IF dir$=='s' AND y<200-10:y=y+1 
    190 IF dir$=='e':IF x<448-6:x=x+1
    200 IF dir$=='w' AND x>0:x=x-1 
    210 ELSE IF dir$=CHR$(27):EXIT loop:ELSE NEXT loop 
    220 END IF 
    230 CURSOR old_x,old_y:PRINT 'X' 
    240 CURSOR x,y:PRINT 'X' 
    250 END REPeat loop 
    260 OVER 0

Notice the use of both AND logic operators and second IF
statements (these can be swapped around). Placing the check for the
keys <N>, <E>, <S> and <W> within another IF
statement increases the speed of this routine, as the four statements
in lines 170 to 200 do not need to be processed if another key is
pressed.

**Example 2**

The whole program can be simplified a little by using boolean logic, by
replacing lines 170 to 200 with the following::

    170 IF dir$=='n':y=y-(y>0) 
    180 IF dir$=='s':y=y+(y<200-10) 
    190 IF dir$=='e':x=x+(x<448-6) 
    200 IF dir$=='w':x=x-(x>0)

This is about 2.5% quicker than the first example.

**Example 3**

On a Minerva ROM, the powerful and even quicker SELect ON statement
could be used to make things even easier to understand, by replacing
lines 160 to 220 with:: 

    160 SELect ON dir$ 
    170   ='n':y=y-(y>0) 
    180   ='s':y=y+(y<200-10) 
    190   ='e':x=x+(x<448-6) 
    200   ='w':x=x-(x>0) 
    210   =CHR$(27):EXIT loop 
    215   =REMAINDER :NEXT loop 
    220 END SELect

This is about 22.5% quicker than the first example. Don't worry that
the 'X' disappears in a band across the screen as it is being moved - as
soon as you take your finger off the button, you are okay! It is unknown
why this phenomenon occurs..

**NOTE 1**

On ROM versions earlier than Minerva v1.92 (unless you have SMS), when
using multiple in-line IF statements, you need to be very careful over
the use of ELSE and the colon ':'. Although the following two lines have
exactly the same effect::

    IF x=0 : PRINT 'HELLO' : ELSE PRINT 'Bye' 
    IF x=0 : PRINT 'HELLO' : ELSE : PRINT 'Bye'

The following gives the interpreter problems:: 

    10 x=0 
    20 PRINT x 
    30 IF x=0 : PRINT 'HELLO' : ELSE IF x=2 : PRINT 'GOODBYE' : END IF : x=x+1 
    40 x=x+2 
    50 PRINT x

This should make x=2 at line 40, but in fact x=3. 

This is because the
interpreter does not look for an END IF following the ELSE IF structure.

Compare this with what happens if line 30 is made to read:: 

    30 IF x=0 : PRINT 'HELLO' : ELSE : IF x=2 : PRINT 'GOODBYE' : END IF : x=x+1
    
This is actually a bug in the interpreter rather than a feature, as
adding more IF statements into line 30 would appear to rectify it! The
answer therefore is to ensure that a colon appears after every ELSE (or
compile the program).

**NOTE 2**

Another problem also exists with in-line IF...END IF
statements - in the following program, line 100 is called twice when
d=1 and only once if d<>1. 

::

    2 IF d=1:PRINT 'd is 1':ELSE :PRINT 'd is not 1':END IF :PRINT 'A simple test':GO SUB 100 
    3 STOP 
    100 PRINT "Now this is peculiar!!":RETurn

The rule would appear to be that the first GOSUB/PROCedure call after
the END IF contained in an in-line IF...ELSE...END IF structure is
called twice PROVIDED that the fist condition of the IF..ELSE..END IF
statement is true. Both Minerva v1.93+ and SMS cure this. Otherwise, set
the IF..ELSE..END IF statement out over several lines.

**SMS NOTES**

The improved interpreter checks whether IF statements are valid
constructs before RUNning or SAVEing a program and will report one of
the following errors if there is a problem:

**Incomplete IF clause**

Normally appears where END IF has been omitted other than in the in-line
format.

**Misplaced END IF**

There is no matching IF ... clause

**Misplaced ELSE**

This error is normally reported if an ELSE statement has not been placed
inside an IF...END IF construct.

**CROSS-REFERENCE**

:ref:`select--on` provides a much quicker
(although less flexible) means of testing a variable. Other SuperBASIC
structures are :ref:`when--condition`, 
:ref:`when--error`, 
:ref:`define--procedure`,
:ref:`define--function`,
:ref:`repeat` and :ref:`for`.

--------------


..  _iformat:

IFORMAT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  IFORMAT device\_[name]                                           |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command formats the specified device in IBM PS/2 disk format,
giving it the specified name (if any). The only difference between this
and AFORMAT is the way in which the boot sector is created. As with
FORMAT, this will normally format a disk to the highest possible density
- however, you can force it to format a disk as single-sided by making
the last character of the filename an asterisk (\*). However, some IBM
compatible PC's are unable to read single-sided disks.

**NOTE**

Unfortunately, you cannot format 360K or 1.2M disks with this command.

**CROSS-REFERENCE**

See :ref:`format` and
:ref:`aformat`. Other commands added are
:ref:`iqconvert`,
:ref:`adelete` and
:ref:`qcopy`.

--------------


..  _inarray-pct:

INARRAY%
========

+----------+--------------------------------------------------------------------+
| Syntax   |  INARRAY% (array[ { $ \| % } ] [ ,first ] ,tofind[ { $ \| % } ] )  |
+----------+--------------------------------------------------------------------+
| Location |  INARRAY (DIY Toolkit - Vol Z)                                     |
+----------+--------------------------------------------------------------------+

This function searches a given array for a specified value. The array
can be of any type, a string (although this must only be
two-dimensional), a floating point or integer (these latter two can be
any number of dimensions, up to 15 !!). INARRAY% will then search the
specified array for the given value (tofind) which must be a string,
floating point or integer value, although it does not have to be the
same type as the array itself provided that you could assign the value
to the array, for example::

    array%(10)='2020'

and::

    PRINT INARRAY%(array%,'2020')
    
are okay, compare::

    array%(10)='x' 
    
and::

    PRINT INARRAY%(array%,'x')
    
which both return an error. 

The search is not case-sensitive and will
also equate embedded numbers so that the strings '020' and '20.00' are
seen as the same as '20'. Like the function SEARCH, the search is very
fast. 

The first parameter can be specified, which allows you to tell
INARRAY% from which element onwards it should look (remember that the
first element is indexed with 0). 

The value returned by INARRAY% will be
-7 if the value is not found in the specified array. 

An error will be
generated if tofind could not be coerced to the same type as the array.

An error will also be generated if the array contains more than 32768
entries. 

If the search is successful, INARRAY% will return one value
which represents the index of the entry. For strings and single
dimensional arrays, this is easy - if the value returned is srch, then::

    PRINT array(srch)
    
will show the value you searched for. However, where the array has more
dimensions, you will need a little work to find out the entry referred
to. 

For example, take a three-dimensional array s%(10,20,30) - this
contains 11\*21\*31 (7161) entries, with the first entry being index 0,
this being s%(0,0,0) and the last entry being index 7160, this being
s%(10,20,30). 

If INARRAY% (s%,300) returned the value 32, this would be
index number 32, equivalent to s%(0,1,1). This could be found out by
using the formula for s%, where the value returned (index) points to
s%(x,y,z), where::

    z=index MOD (31*21) MOD 31 
    y=index MOD (31*21) DIV 31 
    x=index DIV (31*21) MOD 31
    
It is important to work from right to left along the list of array
elements, alternating MOD and DIV for each entry.

**NOTE**

This function will not work in a program compiled with Turbo or
SuperCharge.

**CROSS-REFERENCE**

Use :ref:`instr` to locate a sub-string in a string.
See :ref:`search` which is similar.

--------------


..  _inf:

INF
===

+----------+-------------------------------------------------------------------+
| Syntax   |  INF                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function INF is a constant and holds the greatest number which can
be used in SuperBASIC. It is a floating point number exactly equal to
2\ :sup:`2047`. If any value becomes greater than INF, an overflow will
occur. The smallest possible value is -INF.

**CROSS-REFERENCE**

:ref:`maximum` and
:ref:`minimum` can also be used to return this
value.

--------------


..  _ink:

INK
===

+----------+-------------------------------------------------------------------+
| Syntax   || INK [#ch,] colour  or                                            |
|          || INK [#ch,] colour1,colour2 [,pattern]                            |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command sets the ink colour used inside the given window ch
(default #1). Since the advent of the Extended Colour Drivers under
SMSQ/E v2.98+ the scope of colours accepted by this command has been
much enhanced and depends upon the colour mode selected for the current
program. As a result, the ink colour can be either a solid colour if the
first syntax is used (in chich case colour can be any integer in the
range 0..16777215) or a composite colour made up of the three parameters
supplied in the second syntax (colour1 and colour2 must both be in the range dictated by the current MODE).

Luckily, SMSQ/E allows you to include binary and hexadecimal numbers
directly in programs (eg INK $f800) which may make the non-standard QL
colours easier to use. The way in which colours are handled depends upon
the operating system. On most systems, only the Standard QL Colour
Drivers are supported. However, SMSQ/E v2.98+ can be used to access
further Extended Colour Drivers by configuring SMSQ/E to start with them
loaded, or using the start-up screen on QPC.

STANDARD COLOUR DRIVERS
-----------------------

**MODE 4 and MODE 8**

This applies to standard QL operating systems, or can be set under
SMSQ/E v2.98+ with the command DISP\_COLOUR 0,800,600 or by altering the
configuration of the operating system. There are eight solid colours
which have the following values (although only four of these colours are
available in MODE 4):

+-------+---------------+---------------------------+
| Value | MODE 8 colour | MODE 4 colour             |
+=======+===============+===========================+
| 0     | black         | black                     |
+-------+---------------+---------------------------+
| 1     | blue          | black (should be avoided) |
+-------+---------------+---------------------------+
| 2     | red           | red                       |
+-------+---------------+---------------------------+
| 3     | magenta       | red (should be avoided)   |
+-------+---------------+---------------------------+
| 4     | green         | green                     |
+-------+---------------+---------------------------+
| 5     | cyan          | green (should be avoided) |
+-------+---------------+---------------------------+
| 6     | yellow        | white (should be avoided) |
+-------+---------------+---------------------------+
| 7     | white         | white                     |
+-------+---------------+---------------------------+

The values in MODE 4 which are marked
"should be avoided" can be used on standard QLs, but lead to
compatability problems when run under the Enhanced Colour Drivers (see
below). Other integer values in the range 8 to 255 are allowed, but
these are generally 'composite' colours and repeats of other values.

EXTENDED COLOUR DRIVERS
-----------------------

The following is a description of the various colour modes available
under the Extended Colour Drivers provided by SMSQ/E v2.98+. These are
available once SMSQ/E is configured to use the Extended Colour Drivers.
DISP\_COLOUR can be used to switch between the standard and extended
colour drivers.

**QL Colour Mode**

This is selected with the command COLOUR\_QL and is the default when a
program is executed. For the purposes of INK, PAPER, STRIP
etc commands, it provides the same colours as under the Standard QL
Colour Mode (provided the standard colour=0 to colour=7
is used), except that MODE 4 programs can actually access all 8 colours
not just the standard 4. However, the actual colours which represent
each of the different values can be amended by changing the palette (see
PALETTE\_QL). This can be used, for example, to rectify programs which
display the wrong colours because they presume INK 3 would always be the
same as INK 2.

**8 Bit Colour Mode**

This is supported on the Aurora motherboard (not yet implemented) and
QPC, QXL and the Q40/Q60. It is selected with COLOUR\_PAL and allows
colour to be in the range 0...255. This is the PAL value and is hardware
independent - refer to Appendix 16 for a full list of the colours
available. 

The colours which represent each of the 256 values allowed
can be amended by changing the palette (see PALETTE\_8). For this mode,
the INK parameter should be the PAL value listed in the table. If a
stipple is required, the two composite PAL colours will need to be
specified explicitly - see below.

**Native Colour Mode (8 or 16 bit colour)**

This should be supported on all implementations of SMSQ/E v2.98+ and is
selected with COLOUR\_NATIVE. The range supported by colour and the
effects all depend upon the display hardware currently in use. As a
result, under Aurora, it is similar to COLOUR\_PAL in that it only
supports 8 bit colours, but the colour is specified by the Native Colour
Value instead of the PAL value. On the QPC, QXL and Q40/Q60, it supports
65536 colours as standard. The value required for INK, PAPER, STRIP etc.
depends upon the hardware in use - look at the tables in Appendix 16 for
the appropriate hardware and then the Native Colour Value to use. It may
be easier to use hexadecimal or binary to specify the colour, for
example INK $F81F for magenta on QPC/QXL.

**24 Bit Colour Mode**

This is only supported on QPC (dependent on hardware). It is selected
with COLOUR\_24 and allows colour to be in the range 0..16777215. Due
the values possible in 24 bit colour mode, it is essential that
hexadecimal is used to describe colours. Colours are defined as a 3 byte
value representing a value for red, green and blue respectively. For
example, yellow would be INK $FFFF00.

**COMPOSITE COLOURS**

These are colours made up of either two or three values, for example::

    INK 2,7
    INK 1,7,2
    INK $F800,$FDBF,1
    
Depending upon the combinations, they may not be displayed correctly on
a television. 


::

    INK colour1,colour2  
    
This creates a composite colour made up of the two given colours in a checkerboard pattern (stipple 3). 

::

    INK colour1,colour2,stipple 
    
This creates a composite colour which is a mixture of the two given colours, and displayed in the given stipple pattern. 

The values for stipple are:

+-------+--------------------+
| Value | Pattern            | 
+=======+====================+
| 0     | Dots               |
+-------+--------------------+
| 1     | Horizontal stripes |
+-------+--------------------+
| 2     | Vertical stripes   |
+-------+--------------------+
| 3     | Checkerboard       |
+-------+--------------------+

If you wish to calculate the equivalent single parameter for Standard QL Colour Mode, you will need
to set various bits of colour by referring to the following table (note
that this cannot be used under the Extended Colour Drivers except under
COLOUR\_QL):

.. Original HTML, commented out here. Just for reference to get the table right. NDunbar.
.. <br><h3>BIT7  6    5  4  3    2  1  0
.. <br>STIPPLE                               COLOUR
.. <br></h3>Dots0  0|  0  0  0  |  0  0  0Black
.. <br>Vertical lines0  1|  0  0  1  |  0  0  1Blue
.. <br>Horizontal lines1  0|  0  1  0  |  0  1  0Red
.. <br>Checkerboard1  1|  0  1  1  |  0  1  1Magenta
.. <br>                |  1  0  0  |  1  0  0Green
.. <br>                |  1  0  1  |  1  0  1Cyan
.. <br>                |  1  1  0  |  1  1  0Yellow
.. <br>                |  1  1  1  |  1  1  1White

+-------------------+---------+----------+----------+----------+
| Stipple           | BITS 76 | BITS 543 | BITS 210 | Colour   |
+===================+=========+==========+==========+==========+
| Dots              |    00   |     000  | 000      | Black    |
+-------------------+---------+----------+----------+----------+
| Vertical Lines    |    01   |     001  | 001      | Blue     |  
+-------------------+---------+----------+----------+----------+
| Horizontal lines  |    10   |     010  | 010      | Red      |
+-------------------+---------+----------+----------+----------+
| Checkerboard      |    11   |     011  | 011      | Magenta  |
|                   +---------+----------+----------+----------+
|                   |    11   |     100  | 100      | Green    |
|                   +---------+----------+----------+----------+
|                   |    11   |     101  | 101      | Cyan     |
|                   +---------+----------+----------+----------+
|                   |    11   |     110  | 110      | Yellow   |
|                   +---------+----------+----------+----------+
|                   |    11   |     111  | 111      | White    |
+-------------------+---------+----------+----------+----------+

**NOTE**

Turbo and Supercharge cannot compile the THOR's floating point colours
as they expect all parameters to be integers. Use IO\_TRAP instead, for
example::

    a=IO_TRAP(#ch,39,colour): REMark Sets the PAPER colour.
    a=IO_TRAP(#ch,40,colour): REMark  Sets the STRIP colour.
    a=IO_TRAP(#ch,41,colour): REMark  Sets the INK colour. 

Unlike the PAPER command, if you use IO\_TRAP here, you will also need to set the STRIP colour
explicitly.

**THOR XVI NOTE**

The THOR XVI allows a total of 16 colours in MODE 12 in the range 0 to
7.5 (stipple will actually fall in the range 0...1023). If you add .5 to
the normal colour, this switches on the THOR's intensity bit, meaning
that for example, the resultant colour for INK 1.5 is somewhere between
black and blue (ie. a very dark blue). You can also add .25 to each
colour, which will result in a stipple mixture of colours (details
unknown at present).

**CROSS-REFERENCE**

:ref:`paper` and :ref:`strip`
also set colours within windows. :ref:`rmode` can be
used to read the current colour mode.
:ref:`colour-ql`,
:ref:`colour-pal`,
:ref:`colour-native` and
:ref:`colour-24` will also affect the colours
produced. :ref:`palette-ql` and
:ref:`palette-8` can be used to change the
palette of colours available.
:ref:`disp-colour` can be used to switch from
Extended Colour Drivers to Standard Colour Drivers. Also refer to
:ref:`inverse`. Please also look at the QL Display
appendix (Appendix 16).

--------------


..  _inkey-dlr:

INKEY$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  INKEY$ ( [#chan,][timeout] )                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function fetches a single character from the specified channel
(default #0). If a timeout is specified, INKEY$ will wait for timeout
frames (there are 50 frames per second in the UK, 60 frames per second
in most other countries). If a character is read, the function will
return straight away, otherwise, it will wait for the specified number
of frames and then return. Timeout can be in the range -32768..32767. If
a negative timeout is specified, INKEY$ will wait forever until a
character is read from the specified channel. The default of timeout is
0 which means return immediately. A timeout is therefore not really
necessary if INKEY$ is being used to access a channel opened to a file,
as the data will either be there or not! If #chan is not an input
channel (eg. scr\_), error -15 (bad parameter) will be reported.

**NOTE 1**

Using timeouts allows programs to run at the same speed on all QL
compatibles.

**NOTE 2**

It may be useful to clear the input buffer before trying to read a
character from the keyboard (this prevents overrun on keys) - you can do
this by using something along the lines of::

    100 dummy=KEYROW(0) 
    110 key$=INKEY$(-1)

**CROSS-REFERENCE**

:ref:`inkey-dlr` is channel based, which means that it
can be used safely in multi-tasking programs.
:ref:`keyrow` will read the keyboard even though
the current Job is not the one executing the
:ref:`keyrow` command (although see the options
available with :ref:`exep`).
:ref:`input` allows you to read a string of
characters in one go. :ref:`pause` halts program
execution temporarily.

--------------


..  _input:

INPUT
=====

+----------+-----------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   || INPUT [#chan,] :sup:`\*`\ [ [separator] [prompt\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\*`  or                                  |
|          || INPUT :sup:`\*`\ [ [#chan,] [separator] [prompt\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\*`  (THOR XVI and Minerva v1.97+ only)  |
+----------+-----------------------------------------------------------------------------------------------------------------------------------------+
| Location || QL ROM                                                                                                                                 |
+----------+-----------------------------------------------------------------------------------------------------------------------------------------+

This command will read a string of bytes from the specified channel
(default #1), which must end in CHR$(10) = <ENTER>. The fetched string
is then placed in the specified variable (var), which may be of any
type. Several sets of bytes may be read at the same time by specifying
more than one variable, for example by::

    INPUT a$,x,b$
    
Although each set of bytes must again be terminated by CHR$(10). 

If the channel is write-only (eg. scr), error -15 (bad parameter) will be
reported. 

If the specified channel is a console channel (con), the
cursor will be activated and the user will be able to type in a string
of characters at the current text cursor position. The characters typed
will appear in the current INK colour on the current STRIP colour, and
will also be affected by the settings of CSIZE, UNDER, FLASH and OVER.

If a channel is specified, this must be followed by a comma. It may
however also be followed by one or more separators. Each separator may
be one of the following:

- ! - (Exclamation mark) If a character other than a space appears immediately to the left of
  the current text cursor position, print a space. If prompt$ is specified
  after this, if prompt$ is too long to fit on the line from the current
  text cursor position, it will be placed at the start of the next line.

  If nothing follows this separator, then the text cursor is not moved at
  the end of the command. 
  
- , - (Comma) This forces the text cursor to be placed on the
  next column which is a multiple of 8. Note that anything which appears
  on screen underneath the columns which are stepped over will in fact be
  blanked out in the current STRIP colour. If the next column which is a
  multiple of 8 is at the end of the current line, then the comma will
  move the text cursor to the start of the next line, not overwriting any
  text on screen!

- \\ - (Back slash) This forces the text cursor to be placed at the start of the next
  line. If nothing follows this separator this has no further effect - the
  text cursor is automatically placed at the start of the next line at the
  end of INPUT anyway (see below). This has no effect unless nothing
  follows this separator, in which case the text cursor is left alone at
  the end of the command. 
  
- TO col - This moves the text cursor to the
  specified column (col). If however, the text cursor is already at or
  beyond the specified column, the text cursor is moved one space to the
  right (unless you have a THOR XVI - see TO). This separator must however
  be followed by yet another separator (normally ; (semicolon) so as to avoid
  confusion). If the specified column is further than the far right side
  of the specified channel, then TO merely wraps around the channel,
  continuing to count from the start of the next line. Note that any text
  under the columns which are jumped by TO will be blanked out in the
  current STRIP colour. 
  
At the end of the INPUT command, the text cursor
is placed at the start of the next print line (unless an end separator
of '!', '\\' or ';' is used). 

If prompt$ is specified, this will have no
effect unless the specified channel (#chan) is a console channel. If
this is the case, the specified string is written to the console
channel, (as with PRINT), followed by the specified separator. The
cursor on the specified channel is then activated at the current print
position and input awaited as normal if required. 

If you are wondering
how to include a variable as part of prompt$, this is achieved by
placing the variable in brackets, for example the following will prompt
for 3 names to be entered::

    100 DIM a$(3,10) 
    110 FOR i=1 TO 3 
    120   INPUT 'Enter name number' ! (i) ! a$(i) TO 40; '-- Thank you' 
    130 END FOR i

Unfortunately, you cannot include the variable which has been entered
in that same INPUT statement as a part of prompt$. If you do so, the
prompt$ will include the variable at the value it contained at the start
of the INPUT statement. For example, the following will not work
correctly, always saying x^2=1 no matter what value you enter::

    x=1: INPUT #2 ; 'Enter Number to Square' ! x \ 'x^2=' ; (x^2)
    
This could be fixed by using the following::

    x=1: INPUT #2 ; 'Enter Number to Square' ! x: PRINT 'x^2=' ; (x^2)

The keys available for editing the string of characters as you enter it
(via a console window) are shown on the next page. Once the string has
been entered, it is assigned to the specified variable and the
interpreter then looks at the INPUT
command to see if any further prompt$ need to be printed out, or
whether any further variables need to be entered; and if so, will repeat
the above steps.

**KEYS AVAILABLE FOR EDITING**

Once any prompt$ has been printed, whilst the user is inputting a
string, the following keys are available to the user to edit the string
being entered: 

- <LEFT> Move cursor left one character (if possible)
- <RIGHT> Move cursor right one character (if possible) 
- <ENTER> Accept string input 
- <UP> Ditto 
- <DOWN> Ditto 
- <CTRL><LEFT> Delete character to left of cursor 
- <CTRL><RIGHT> Delete character under cursor 
- <CTRL><SPACE> Break current command - return control to #0

**Example 1**

::

    INPUT #2, TO 10 ; x$ \ TO 10 ; y$ \ 'Name:' ! : INPUT #2, TO 10 ; a$

**Example 2**

A function which will return a numeric variable safely. This accepts
leading and trailing spaces, and even spaces before the E part of a
number. Unfortunately, there is no way to prevent overflow errors, where
the number is outside the range 10E-616...10E616. However, it will
accept for example: ' +1.32 E-20 '::

    100 REMark Demonstration 
    110 AT 10,0:PRINT 'Enter number: ':no=INPUT_no(#1,10,13) 
    120 PRINT #0,lives 
    125 :
    130 DEFine FuNction  INPUT_no (chan, posx, posy) 
    140   LOCal var$,ix,loop,er,E_pos,dota,c 
    150   er=0 
    160   REPeat loop 
    170     IF er<0:BEEP 1000,10:er=0 
    180     dota=0 
    190     AT#chan,posx,posy:PRINT#chan,FILL$(' ',20) 
    200     AT#chan,posx,posy:INPUT#chan,var$ 
    210     IF var$="":er=-1:NEXT loop 
    220     FOR ix=1 TO LEN(var$) 
    230       IF var$(ix)<>' ':var$=var$(ix TO):EXIT ix 
    240     END FOR ix 
    250     FOR ix=LEN(var$) TO 1 STEP -1 
    260       IF var$(ix)<>' ':var$=var$(1 TO ix):EXIT ix 
    270     END FOR ix 
    280     IF var$(1) INSTR '.1234567890-+'=0:er=-1:NEXT loop 
    290     IF var$(1)='.':dota=1 
    300     E_pos='E' INSTR var$ 
    310     IF E_pos+1>LEN(var$):er=-1:NEXT loop 
    320     IF E_pos=0:E_pos=LEN(var$)+1 
    330     FOR ix=2 TO E_pos-1 
    340       c=CODE(var$(ix)):IF c=46:dota=dota+1 
    350       IF c<>46 AND (c<48 OR c>57) OR dota>1:er=-1:NEXT loop 
    360     END FOR ix 
    370     IF E_pos>LEN(var$):RETurn var$ 
    380     FOR ix=E_pos+1 TO LEN(var$) 
    390       IF var$(ix)<>' ':E_pos=ix-1:EXIT ix 
    400     END FOR ix 
    410     IF var$(E_pos+1) INSTR '1234567890-+'=0:er=-1:NEXT loop 
    420     IF var$(E_pos+1) INSTR '-+':IF E_pos+2>LEN(var$):er=-1: NEXT loop 
    430     FOR ix=E_pos+2 TO LEN(var$) 
    440       c=CODE(var$(ix)):IF c<48 OR c>57:er=-17:NEXT loop 
    450     END FOR ix 
    460     RETurn var$ 
    470   END REPeat loop
    480 END DEFine

**NOTE 1**

If you try to INPUT a string greater than 32766 characters, this may
crash the system. It is therefore important that when INPUTting from a
file which is longer than 32766 characters, you are certain that it
contains a CHR$(10). If not, then use INKEY$.

**NOTE 2**

If no variable is specified, INPUT will have the same effect as PRINT.
In particular, as from SMS v2.57, INPUT on its own will clear a pending
newline, in the same way as PRINT on its own.

**NOTE 3**

Pre JS ROMs have a small input buffer, meaning that strings over 128
characters long lead to a 'Buffer Full' (-5) error. You can fix this for
QLiberator with a compiler directive.

**NOTE 4**

INPUT a% cannot accept -32768 (except on Minerva v1.76+ and SMS).

**NOTE 5**

If you try to INPUT a value into a slice of an undimensioned string, the
value will not be stored and BASIC may stop without a message. For
example::

    100 a$='Hello World' 
    200 INPUT a$(7 TO) 
    210 PRINT a$

The above program will not even attempt to allow you to INPUT the
value. The cure on all ROMs is to dimension the string, or to INPUT a
temporary variable::

    100 a$='Hello World' 
    110 INPUT g$ 
    120 a$(7 to)=g$
    130 PRINT a$

**NOTE 6**

If the specified channel is not a console channel, prompt$ and any separators 
are completely ignored. If there is no data in the
channel to be read, then the error 'End of File' (-10) is reported.
Under SMS, the prompt$ is still printed out, but any attempt to read a
variable results in 'Invalid parameter'.

**NOTE 7**

Except under Minerva v1.97+, if CURSOR was used to specify the position
of the input line and the position specified could not be set with the
AT comand, the display could become messy if the cursor was moved off
the initial row and then returned to it.

**NOTE 8**

Before SMS v2.59 if the <BREAK> key was pressed during an INPUT command,
the cursor could be left active.

**MINERVA NOTES**

Minerva provides the following additional keys for use in editing the
string: 

- <ALT><LEFT> move to start of current text 
- <ALT><RIGHT> move to end of current text 
- <TAB> move along to x\*8th character from start of line (or end of data if nearer) 
- <SHIFT><TAB> moves back in steps of 8 characters (or start of data if nearer) 
- <CTRL><ALT><LEFT> delete to start of current (visible) line 
- <CTRL><ALT><RIGHT> delete from current character to end of line 
- <ESC> same as <CTRL><SPACE> (Break key)
- <SHIFT><ENTER> same as <ENTER> 
- <SHIFT><SPACE> same as <SPACE> 

Minerva v1.93+ alters keys further, both to make editing text easier and also to
prevent some anomolies in earlier versions:

- <UP> where the input data consists of more than one line, the up key moves up a line, unless
  cursor on first line of data in which case ends input. Any lines which
  have scrolled up out of the window will be re-shown if you press <UP> to
  move onto those lines. On previous ROM versions, if a line had
  disappeared off the screen, you could not access it. The only downside
  to this, is that any prompt which appeared before the text being edited
  cannot be re-shown - the prompt is simply 'blanked out' in the current
  PAPER colour. 

- <DOWN> where input data consists of more than one line, the
  down key moves down a line, unless cursor on last line of data in which
  case it ends the input. This will allow you to access data lines which
  have scrolled down out of the window. 

- <SHIFT><RIGHT> moves you right to
  the start of the next word (or end of the data). The start of a word is
  taken to be where the character to left of the cursor is space and the
  character under the cursor is something other than space.

- <SHIFT><LEFT> moves you left to the start of the previous word (or start
  of the data). 

- <CTRL> + any combination with <LEFT> or <RIGHT> will
  delete the characters moved over. Spaces to the right which are caused
  by deletions are cleared in current PAPER colour - all other versions
  clear in current STRIP colour. Minerva v1.96+ (as with THOR XVI) will
  also allow: DIM x(4):INPUT x

This will patiently ask you to input the five values of x(0) to x(4).
Minerva v1.96+ (as per THOR XVI) also allows you to insert channel
numbers part way through an INPUT statement, although - unlike the THOR
XVI implementation - you still cannot use the variable entered as part
of the output.

**SMS NOTES**

SMS provides the following additional keys for use in editing the
string: 

- <ALT><LEFT> move to start of current text 

- <ALT><RIGHT> move to end of current text 

- <TAB> move along to x\*8th character from start of line

- <SHIFT><TAB> moves back in steps of 8 characters <ALT><LEFT>move to start
  of current text 

- <ALT><RIGHT> move to end of current text 

- <TAB> move along to x\*8th character from start of line 

- <SHIFT><TAB> moves back in steps of 8 characters 

- <CTRL><DOWN> Deletes the whole of the input line


- <SHIFT><RIGHT> moves you right to the start of the next word (or end of
  the data). The start of a word is taken to be where the character to
  left of the cursor is space and the character under the cursor is
  something other than space. 

- <SHIFT><LEFT> moves you left to the start of
  the previous word (or start of the data). 

- <CTRL> + any combination with <LEFT> or <RIGHT> will delete the characters 
  moved over. 
  
The following keyings have also been altered: 

- <DOWN> Has no effect! 
- <UP> Has no effect!

**THOR XVI NOTES**

The THOR XVI (version 6.41) allows you to put channel numbers part way
through a statement, for example:: 

    INPUT 'Your name' ; #0 , name$ \ #1 ; ' is ' ; (name$)

instead of::

    PRINT 'Your name ' ; : INPUT #0,name$ : PRINT 'is ';name$

The THOR XVI also allows you to INPUT arrays with one statement. For
example:: 

    DIM x(4): INPUT x
    
will wait around for five values to be entered. No other implementation
(other than Minerva v1.96+) currently allows this.

**WARNING 1**

There is no facility to check the characters entered using INPUT and if
someone tries to enter a non-numeric character when INPUTting a numeric
variable an error will be caused. The second example provides a means of
ensuring numeric input is entered safely. Also refer to CHECKF and
CHECK%.

**WARNING 2**

You can crash SMS if you try to omit unwanted data by using the same
variable more than once in the INPUT statement. For example, consider
opening a channel to a file which contains a copy of a directory. The
first two lines contained in the file are not needed, being the disk
name and the number of sectors. You therefore may use a line similar to::

    100 OPEN_IN #3,ram1_direc
    110 INPUT #3,dummy$\dummy$

which would simply read these two lines. Unfortunately, on SMSQ/E (pre
v2.88), this appears to corrupt the return stack and may cause problems
when you try to use other variables. Minerva also exhibits some of the
same traits, although it manages to avoid a system crash. Oddly, if you
enter PRINT dummy$ following this command, will print either rubbish (on SMSQ/E pre v2.88)
or the first line of the file (on Minerva), whereas it should in fact
show the second line!! Even more curiously, if you RUN the program a
second time, INPUT works correctly! Later versions of SMSQ/E act in the
same way as Minerva. The original QL ROMs get this one correct.

**CROSS-REFERENCE**

The text cursor is positioned using commands such as
:ref:`at` and :ref:`cursor`. You
may prefer to use :ref:`edline-dlr` which allows you
to provide a default string for alteration, as well as specifying the
maximum number of characters that can be typed in.
:ref:`print` has some similar characteristics.
:ref:`his-set` allows you to set a history for a
console channel.

--------------


..  _input-dlr:

INPUT$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  INPUT$ ([#ch,] length)                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

INPUT$ is identical to FREAD$ with the single difference that the
function also stops reading if a line feed character CHR$(10)
has been found. So, INPUT$ is dedicated to read line based text.

--------------


..  _instr:

INSTR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  str1$ INSTR str2$                                                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This operator searches str2$ for str1$ and if found, it will return the
position of the first character of str1$ in str2$. The search is not
normally case-sensitive. If str1$ cannot be found, the value 0 is
returned.

**Examples**

::

    s$='Hello World':PRINT 'world' INSTR s$ 
    
will print 7. 

::

    PRINT 'worlds' INSTR s$

will print 0.

**NOTE**

If str1$ is a nul string, eg. str1$="", INSTR will always return the
value 1.

**SMS NOTE**

You can specify a case sensitive search using INSTR\_CASE.

**CROSS-REFERENCE**

See :ref:`instr-case`.
:ref:`inarray-pct` and
:ref:`search` can be used to compare entries within
arrays.

--------------


..  _instr-case:

INSTR\_CASE
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  INSTR\_CASE flag                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.58+                                                    |
+----------+-------------------------------------------------------------------+

Normally the INSTR operator carries out a non-case sensitive search.
This command allows you to specify that the search should be case
sensitive (if flag=1) or revert to the old system (if flag=0).

**Example**

::

    INSTR_CASE 1 
    PRINT 'Hello' INSTR 'HELLO'
    
will return 0 

::

    INSTR_CASE 0
    PRINT 'Hello' INSTR 'HELLO'
    
will return 1

**NOTE 1**

This command does not seem to have any effect on the speed of the INSTR
operator.

**NOTE 2**

The setting of INSTR\_CASE is cleared (to non-case sensitive) following
NEW, LOAD, MERGE, LRUN, RUN, MRUN.

**CROSS-REFERENCE**

See :ref:`instr`.

--------------


..  _int:

INT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  INT(x)                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the closest integer which is smaller than or
equal to x. For positive parameters this means that the non-integer part
of the number is cut off, so INT(12.75)=12 and INT(5)=5. Note that for
negative numbers this is not true: INT(-12.75) = -13 because -13 <
-12.75. INT can handle any number in the range -2^31<=x<2^31, except
under SMS where it can handle much larger numbers, in the range
-2^255 <= x <= 2^2047.

**Example**

A function Rond(x,d) to round a number x to d decimal places:: 

    100 DEFine FuNction Rond(no,plac) 
    110   LOCal temp 
    120   temp=INT(no*10^(plac+1)+.5)/10^(plac+1) 
    130   RETurn INT(temp*10^plac+.5)/10^plac 
    140 END DEFine
    
::
    
    PRINT Rond (10.3226,2)
    
gives the result 10.32

**NOTE 1**

The INT function does not round to the nearest integer, use INT(x+.5)
instead.

**NOTE 2**

On non-Minerva ROMs, unless you have SMS installed, INT with x>(2^31)-2
gives an overflow error.

**CROSS-REFERENCE**

:ref:`ceil` is complementary to
:ref:`int`.

--------------


..  _intmax:

INTMAX
======

+----------+-------------------------------------------------------------------+
| Syntax   |  INTMAX                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function INTMAX returns the constant 10737421823 = 2^30-1. Although
SuperBASIC's integers can only handle a maximum of 16 bits (resulting in
a range of 2\ :sup:`16` different values: -32768 to 32767), the QL can
internally, on a machine code level, happily handle larger integers.
Many keywords listed in this book actually make use of this possibility
and that explains their valid parameter range.

**NOTE**

An error in the Maths Package (up to v2.04) means that a line such as
PRINT 2^30-INTMAX will report an out of memory error. This is fixed in
later versions of the package.

**CROSS-REFERENCE**

:ref:`eps`\ (x) = 1  if and only if :ref:`abs`\ (x) = 2 \* INTMAX.

--------------


..  _inverse:

INVERSE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  INVERSE [ #channel ]                                             |
+----------+-------------------------------------------------------------------+
| Location |  ALIAS (DIY Toolkit - Vol A)                                      |
+----------+-------------------------------------------------------------------+

This command provides the QL with a facility which is available on most
other implementations of BASIC - inverse video. What this command
actually does is swap over the values which have been set for the
specified window channel (default #1) for the STRIP and INK colours,
thereby making any futher text which is PRINTed to that window stand
out. This means that for example, if you set the INK to 7 (white) and
the STRIP (or PAPER colour) to 2 (red), after INVERSE, text will be
printed in red INK on a white STRIP.

**Example**

::

    STRIP #2,7:INK #2,0:PRINT #2,'This text is normal' 
    INVERSE #2:PRINT #2,'But this is in inverse video!!'

**CROSS-REFERENCE**

See also :ref:`ink` and
:ref:`strip`.

--------------


..  _invxy:

INVXY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  INVXY x%, y%                                                     |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

This is a simple command which draws a haircross on screen with its
centre at (x%,y%). It is drawn with OVER -1 and uses the full screen.

**WARNING**

Do not use this!

--------------


..  _io-pend-pct:

IO\_PEND%
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  IO\_PEND% (#ch)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function is the same as NOT PEND.

--------------


..  _io-priority:

IO\_PRIORITY
============

+----------+-------------------------------------------------------------------+
| Syntax   |  IO\_PRIORITY level (level=1 to 1000)                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is used to set the priority of the In / Out retry
operations. This means that it affects the amount of time that the
scheduler will spend retrying IN / OUT operations (such as INKEY$ or
PRINT). Due to the QL's multitasking abilities, it is possible that a
program can be running in the background whilst you are doing something
else. If that program is trying to access a file or the Network port for
example, then it may find that there is no information waiting to be
read at the time and the scheduler will keep trying to access the file
or Network until that information is received. By using this command to
set a higher priority, the scheduler will allocate more time to doing
this and less time to running another job. IO\_PRIORITY 1is equivalent
to the way in which the scheduler worked on the original QL ROM.

--------------


..  _io-trap:

IO\_TRAP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  IO\_TRAP ( [#ch], D0 [,D1 [,D2 [,A1 [,A2 [,D3 ]]]]] )            |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI                                                         |
+----------+-------------------------------------------------------------------+

This function enables you to directly access QDOS's I/O TRAP (TRAP #3)
machine code utilities. You need to supply the number of the TRAP call
as the parameter D0, but you can also set certain of the other internal
machine code registers used by the trap call by setting the other
optional parameters. The TRAP call will affect the specified channel
(default #1). Apart from parameter D3 (this defaults to -1), the purpose
of the other parameters depends upon the TRAP call being used. Unless D3
is negative, 'Not Complete' errors will not be reported, thus allowing
programs to continue even though their windows are buried under the
THOR's windowing system and therefore unusable. The return parameter is
the value returned in the machine code register D0 by the call.

**Example 1**

A short program to get the current window sizes and cursor position in
the variables Window\_Width, Window\_Height, Window\_posx and
Window\_posy respectively:: 

    100 a = ALCHP (8) 
    110 dummy=IO_TRAP (11,0,0,a) : REMark IOW.CHRQ TRAP 
    120 Window_Width = PEEK_W (a): Window_Height = PEEK_W (a+2) 
    130 Window_posx = PEEK_W (a+4): Window_posy = PEEK_W (a+6) 
    140 RECHP a

**Example 2**

Switch on the cursor in #1 (call IOW.ECUR)::

    t = IO_TRAP ( HEX ('E') )

**Example 3**

Set cursor to column x in #3 (call IOW.SCOL):: 

    t = IO_TRAP (#3,HEX ('11'), x )

**CROSS-REFERENCE**

:ref:`cls`, :ref:`scroll` and
:ref:`pan` all allow you to access machine code trap
calls on different ROMs. :ref:`ink` contains a good
example of how to use :ref:`io-trap`.
:ref:`ttet3`,\ :ref:`mtrap`,
:ref:`qtrap` and :ref:`btrap`
are much better as they can be used on all ROM versions. The QDOS/SMS
Reference Manual (Section 15) contains details of the I/O Access Traps.

--------------


..  _iqconvert:

IQCONVERT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  IQCONVERT filename                                               |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command takes a file which is stored on a QL Format disk and
presumes that it was originally an IBM format file. It will then convert
special characters in that file to QL compatible characters as well as
converting any occurence of a Carriage Return character (CR) followed by
a Line Feed character (LF) to a single Line Feed character LF.

**CROSS-REFERENCE**

Compare :ref:`aqconvert` and
:ref:`qiconvert`. See also
:ref:`iformat` and
:ref:`qcopy`.

--------------


..  _is-basic:

IS\_BASIC
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  IS\_BASIC                                                        |
+----------+-------------------------------------------------------------------+
| Location |  MULTI                                                            |
+----------+-------------------------------------------------------------------+

The function IS\_BASIC allows you to find out whether the SuperBASIC
program which executes the command is running under the interpreter or
has been compiled. This is done by returning the sum of the jobnumber
and the jobtag: the sum is 0 for the interpreter and a positive number
for a compiled job. So NOT IS\_BASIC is 1 under the interpreter and 0 in
a compiled program (or a MultiBASIC on Minerva or Mutiple SBASIC under
SMS).

**Example**

If a compiler is available, programs are normally compiled for: - faster
loading - faster execution - possibly linking in Toolkits (QLiberator
only) - easier multitasking - operating system independent
code(QLiberator only) - shared code/hotkey execution (QLiberator only)
IS\_BASIC helps the programmer who uses the interpreter to develop
programs which distinguish between features which are only available in
compiled programs, for instance passing a command string::

    100 IF NOT IS_BASIC THEN 
    110   CMD$="Test" 
    120 ELSE 
    130   INPUT CMD$ 
    140 END IF

**NOTE**

IS\_BASIC will fail to spot a MultiBASIC or SBASIC interpreter.

**CROSS-REFERENCE**

:ref:`prio` sets the priority of the current job.
Under SMS or Minerva, you can use
:ref:`job-name-dlr` to look at the name of the
task which would normally be SBASIC or have its first two letters as MB
respectively for a Multiple SBASIC or MultiBASIC interpreter, unless the
name of the Interpreter has been altered. Refer
to\ :ref:`job-name`.

--------------


..  _is-peon:

IS\_PEON
========

+----------+-------------------------------------------------------------------+
| Syntax   |  IS\_PEON [{ #ch \| chan\_ID \| job\_name$ }]                     |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This function takes the same parameter as PEON and returns 0 if PEX is
not activated for the specified window (or Job) and returns a value not
equal to 0 if PEX is active. If no parameter is specified, then this
function just checks if PEX is active at all. If a pre-JS ROM is
installed, then this function will return the value -19.

**CROSS-REFERENCE**

See :ref:`peon` and
:ref:`is-ptrap` for more details.

--------------


..  _is-ptrap:

IS\_PTRAP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  IS\_PTRAP (trapno [,status] )                                    |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

Not only does PEX allow you to enable background screen access for
specific Jobs or windows, but you can also dictate how the various TRAP
#3 machine code routines should be treated (which has a knock on effect
on programs, since these routines are generally used to access the
screen). For each TRAP #3 routine, you can specify the following status:

- 0 - if the window is buried, then halt the program when this routine is
  called (this is the normal case under the Pointer Environment) 

- 1 - Enable
  background screen access for this routine (if PEX is active - see PEON).

- 2 - This only enables background screen access for this routine if both
  PEX is active and PXON has been used to enable SD.EXTOP routine calls. 

- 3 - If the window is buried, then just ignore this call and allow the
  program to carry on. This could be used for example to allow a program
  which has a large amount of calculation to do to carry on in the
  background, printing a message to the screen only when its window is not
  buried to inform the user of its progress. 

On JS and MG ROMs, only
values of 0 and 3 are recognised - PEON activates all routines as having
a status of 3 on these implementations. On all other implementations
using the defaults provided with PEX, PEON activates all of the
following routines as having a status of 1. 

- $05 iob.sbyt 
- $07 iob.smul
- $09 iow.xtop to $0B iow.chrq 
- $0F iow.dcur to $36 iog.sgcr 
- $6C iop.flim
- $72 iop.rpxl to $76 iop.spry 

If you use PEX\_SAVE, PEON will set the
various routines as specified by you previously. Not all TRAP #3 machine
code routines should be treated in this way - the following routines
should be avoided if possible: 

- $00 iob.test 
- $01 iob.fbyt 
- $04 iob.elin
- $0C iow.defb 
- $0E iow.ecur 

If you decide to use this function to
fine-tune the operation of PEX, then you can save the various settings
using the PEX\_SAVE command. If status is not specified, then the value
returned will be the status of that particular machine code routine. If
a negative number is returned then you probably have a JS or MG ROM (or
earlier). If you are writing a program which will is to run on all QLs,
then you may wish to use IS\_PTRAP to set all of the routines to 0 if
the QL ROM version is JS, MG or earlier.

**NOTE**

You need a good book on the QL's operating system to be able to use this
feature.

**CROSS-REFERENCE**

See :ref:`peon` for more details. The QDOS/SMS
Reference Manual Section 15 contains details of the various TRAP #3
calls.

