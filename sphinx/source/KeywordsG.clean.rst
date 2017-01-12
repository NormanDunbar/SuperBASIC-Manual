
==========
Keywords G
==========

TODO
====

- There doesn't appear to be an entry for GE$ in this file. But it is referenced as a link in GT$.
- Other links to non existing functions are LT$, LE$ and NE$.






..  _gcd:

GCD
===

+----------+---------------------------------------------------------------------------------------------------------+
| Syntax   |  GCD (x\ :sup:`1`\ , x\ :sup:`2` :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`\ ) Where x\ :sup:`i`\ =0..INTMAX  |
+----------+---------------------------------------------------------------------------------------------------------+
| Location |  Math Package                                                                                           |
+----------+---------------------------------------------------------------------------------------------------------+

The function GCD takes two or more positive integers and finds their
greatest common denominator, ie. the largest number by which all of the
given parameters can be divided without remainder. There is always such
a number because 1 (the smallest common denominator) divides every
number without remainder. GCD converts all passed values into integers
by removing any decimal places (as with INT) before looking for the
denominator.

**CROSS-REFERENCE**

:ref:`lcm`

--------------


..  _ger-msg:

GER\_MSG
========

+----------+-------------------------------------------------------------------+
| Syntax   |  GER\_MSG                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

The file GER\_TRA\_rext is supplied with the ST/QL Emulator which
contains translation tables to allow the Emulator to use German. Once
this file has been LRESPR'd, this function can be used to find the start
of the message translation table to be used with the TRA command. You
can use: TRA GER\_TRA,GER\_MSG to set up the printer and message translation tables for Germany.

**CROSS-REFERENCE**

See :ref:`nor-msg` and
:ref:`ger-tra`. Also see
:ref:`tra`.

--------------


..  _ger-tra:

GER\_TRA
========

+----------+-------------------------------------------------------------------+
| Syntax   |  GER\_TRA                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

This is the complementary function to GER\_MSG and points to the
printer translation table for Germany contained in the file
GER\_TRA\_rext.

**CROSS-REFERENCE**

See :ref:`ger-msg`.

--------------


..  _get:

GET
===

+----------+------------------------------------------------------------------------------------------------+
| Syntax   || GET [#channel\\file\_position,] [var\ :sup:`1` :sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*` ...] or |
|          || GET [#channel,] [var\ :sup:`1` :sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*` ...]                    |
+----------+------------------------------------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                                                          |
+----------+------------------------------------------------------------------------------------------------+


This command, together with PUT, helps to provide the QL with a means
of using a file as a store for variables. The QL stores variables in one
of four ways: short%(range -128 to 127) is stored as 2 bytes. Short
integers are only available on Minerva ROMs, when integer tokenisation
is enabled. integer%(range -32768 to 32767) is stored as 4 bytes.
float(eg. 1.23 or any numbers outside the integer%
range) is stored as 6 bytes. string$(eg. 'Hello') is stored as 2 bytes
containing the length of the string followed by the string itself. 

GET enables variables which have been stored in this manner to be retrieved
from a file opened to the given channel (default #3). The variable
stored at the current position in the file (or the file position given
with the command, if the first variant is used) is read directly into
the variable name given with the command. 

If you provide more than one
variable name as the second, third parameter etc, then more variables
will be read from the file in one go. 

If the first variant is used, the
file position is always calculated as an absolute distance from the
start of the file. However, to help you, if you supply a variable for
the file\_position (eg. GET \\pointer), this variable will always be
updated to the current file pointer at the end of the command. 

Compare
GET \\pointer+3 which supplies an expression for the file\_pointer and
cannot therefore be updated automatically by the command. 

If no variable
is specified, the file pointer will be set to the specified position if
the first variant is used. 

If the second variant is used, this will have
no effect.

**Example**

A program to store three names on a file and then to retrieve them (this
would be useful in a database for instance)::

    100 RESTORE 
    110 DIM a$(3,20) 
    120 FOR i=1 TO 3: READ a$(i) 
    130 OPEN_NEW #3,ram1_storage 
    140 PUT #3,a$(1),a$(2),a$(3) 
    150 CLOSE #3 160 : 
    170 REPeat opt_loop 
    180   CLS: INPUT 'Which Number Name do you want?',no$
    190   IF no$='':NEXT opt_loop 
    200   IF no$(1) INSTR '123': opt=no$(1): EXIT opt_loop 
    210 END REPeat opt_loop 
    220 OPEN_IN#3, ram1_storage 
    230 FOR i=1 TO opt:GET#3,retrieve$ 
    240 PRINT retrieve$ 
    250 CLOSE #3 
    260 DATA 'Fred Bloggs','Filthy Rich','Peter Rabbit'

**NOTE 1**

The example works fine if only a few fields have to be stored.
Generally, it is better to move around a file using file pointers in a
file based database.

**NOTE 2**

Current versions of the Turbo and Supercharge compilers are not able to
compile programs which use GET.

**NOTE 3**

Except under SMS v2.81+, this command can crash the system if you try to
GET a string variable which has been dimensioned {or even set with LOCal
a$(512) for example}. This can be avoided by using::

    a$=FILL$(' ',512) 
    
to initialise the string instead.

**NOTE 4**

Although it is possible to use this command with non-file related
channels, this is inadvisable, as each entry would need to be typed in
from the keyboard in its internal form, which can be rather difficult.
If you do use the command on a non-file related channel by accident,
press the Break key to escape.

**CROSS-REFERENCE**

See :ref:`put`, :ref:`bput`,
:ref:`bget`, :ref:`lget`,
:ref:`wget`.

--------------


..  _get-byte-dlr:

GET\_BYTE$
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  GET\_BYTE$ (#channel,bytes)                                      |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function will read a specific number of bytes from the given
channel and return the result as a string. If GET\_BYTE$
cannot get the specified number of bytes from that channel, it will
wait until there are enough bytes present in the channel or until it
detects an End Of File character. GET\_BYTE$ does not care which
characters are read, so <LF> = CHR$(10) will not cause any problems
unlike INPUT.

**Example**

A program to compare the contents of two files, both of which are the
same length. The greater the buffer size (maximum 32767 bytes), the
faster will be the execution, but then again the greater the work space
which will be needed (maximum 64K). This is an example of the
fundamental link between available memory and operation speed::

    100 File1$="ram1_a" 
    110 File2$="ram1_b" 
    120 Buffer=10000 
    130 : 
    140 Pieces=FILE_LEN(File1$) DIV Buffer 
    150 Rest=FILE_LEN(File1$) MOD Buffer 
    160 OPEN#3,File1$: OPEN#4,File2$ 
    170 FOR Blk=0 TO Pieces+1 
    180   IF Blk>Pieces THEN Buffer=Rest 
    190   One$=GET_BYTE$(#3,Buffer) 
    200   Two$=GET_BYTE$(#4,Buffer) 
    210   PRINT "Block"!Blk TO 12; 
    220   IF One$<>Two$ THEN 
    230     PRINT "Difference between"!Buffer*Blk!"and"! Buffer*(Blk+1) 
    240   ELSE 
    250     PRINT "OK" 
    260   END IF 
    270 END FOR Blk 
    280 CLOSE#3: CLOSE#4

**NOTE**

Earlier TinyToolkit versions (pre v1.10) called this function GET$,
which unfortunately caused problems with a similar function in the Turbo
Toolkit and EASYPTR.

**CROSS-REFERENCE**

:ref:`inkey-dlr` reads just one byte from the given
channel, which is therefore much slower than
:ref:`get-byte-dlr` if blocks of bytes are to be
read. On the other hand, :ref:`inkey-dlr` allows you
to specify a timeout. 

The :ref:`input` command
combines input/output and reads blocks, but a block must end with <LF>.

The usage of the different keywords depends mainly on the structure of
the incoming data. User input and lines in an ASCII file normally
terminate with Enter <LF>, while internal data such as disk directory
entries are stored as blocks with a fixed length (see
:ref:`fop-dir`). Have a look at
:ref:`get`, :ref:`put`,
:ref:`bget` and :ref:`bput`, too.
:ref:`file-ptrr`,
:ref:`file-pos`, :ref:`fpos`
can be used for movement.

--------------


..  _get-byte:

GET\_BYTE
=========

+----------+-------------------------------------------------------------------+
| Syntax   | byte = GET\_BYTE(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Reads one character  from the file attached to the channel  number given and returns it as a value between 0 and 255.  This is equivalent to CODE(INKEY$(#channel)). 

BEWARE, :ref:`put-byte` can put negative values to file, for example -1 is put as 255, GET\_BYTE will return 255 instead of -1. Any negative numbers returned are always error codes.


**EXAMPLE**

::

    c = GET_BYTE(#3)


**CROSS-REFERENCE**

:ref:`get-float`, :ref:`get-long`, :ref:`get-string`, :ref:`get-word`.


-------


..  _get-float:

GET\_FLOAT
==========

+----------+-------------------------------------------------------------------+
| Syntax   | float = GET\_FLOAT(#channel)                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Reads 6 bytes from the file and returns them as a floating point value. 

BEWARE, if any errors occur, the value returned will be a negative QDOS error code. As GET\_FLOAT does return negative values, it is difficult to determine whether that returned value is an error code or not. If the returned value is -10, for example, it could actually mean End Of File, this is about the only error code that can be (relatively) safely tested for.


**EXAMPLE**

::

    fp = GET_FLOAT(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-long`, :ref:`get-string`, :ref:`get-word`.


-------



..  _get-long:

GET\_LONG
=========

+----------+-------------------------------------------------------------------+
| Syntax   | long = GET\_LONG(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Read the next 4 bytes  from the file and return  them as a number  between 0 and 2^32 -1 (4,294,967,295 or HEX FFFFFFFF unsigned).

BEWARE, the same problem with negatives & error codes applies here as well as :ref:`get-float`.

**EXAMPLE**

::

    lv = GET_LONG(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-float`, :ref:`get-string`, :ref:`get-word`.


-------



..  _get-string:

GET\_STRING
===========

+----------+-------------------------------------------------------------------+
| Syntax   | a$ = GET\_STRING(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Read the next 2 bytes from the file and assuming them to be a QDOS string's length, read that many characters into a$.  The two bytes holding the string's length are NOT returned in a$, only the data bytes.  

The subtle difference between this function and :ref:`fetch-bytes` is that this one finds out how many bytes to return from the channel given, :ref:`fetch-bytes` needs to be told how many to return by the  user. GET\_STRING is the same as::

    FETCH_BYTES(#channel, GET_WORD(#channel))

WARNING - JM and AH ROMS will give a 'Buffer overflow' error if the length of the returned string is more than 128 bytes. This is a fault in QDOS, not DJToolkit. The demos file, supplied with DJToolkit, has a 'fix' for this problem.


**EXAMPLE**

::

    b$ = GET_STRING(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-float`, :ref:`get-long`, :ref:`get-word`, :ref:`fetch-bytes`.


-------



..  _get-stuff-dlr:

GET\_STUFF$
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  GET\_STUFF$                                                      |
+----------+-------------------------------------------------------------------+
| Location |  GETSTUFF                                                         |
+----------+-------------------------------------------------------------------+

The Hotkey System II uses the keys <ALT><SPACE> and <ALT><SHIFT><SPACE>
to type into the current keyboard buffer the contents of a certain piece
of memory, known as the Hotkey Stuffer Buffer. The command HOT\_STUFF
text$ puts text$ into this buffer. 

The function GET\_STUFF$ returns the
contents of the hotkey stuffer or "0" if it does not contain anything.
If the FILES Thing of QPAC2 is present, this will be started first,
prior to returning the stuffer contents. This means that a program can
easily ask for a filename - just by calling GET\_STUFF$.

**NOTE**

GET\_STUFF$ returns cryptic numbers in unusual circumstances, for
example::

    HOT_STUFF "" 
    PRINT GET_STUFF$

**WARNING**

This function crashes SMSQ/E and Minerva when you Quit the Files Menu of
QPAC 2.

**CROSS-REFERENCE**

See :ref:`hot-stuff`.

--------------


..  _gethead:

GetHEAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  GetHEAD #ch, adr                                                 |
+----------+-------------------------------------------------------------------+
| Location |  HEADER (DIY Toolkit)                                             |
+----------+-------------------------------------------------------------------+

GetHEAD loads the header of an opened file pointed to by the channel
#ch into memory at adr, which must point to at least 64 bytes of
reserved memory.

**Example**

If the file header of an executable file is lost then you must modify it
so that the file can be executed again. Executable files need the file
type set to 1 and the dataspace to be specified, the latter must be
large enough to avoid a serious crash. MAKEJOB does this with file$,
demonstrating GetHEAD and SetHEAD:: 

    100 DEFine PROCedure MAKEJOB (file$, dataspace) 
    110 LOCal fp 
    120 fp=FOPEN(file$): IF fp<0 THEN STOP 
    130 adr=ALCHP(64): IF adr=0 THEN STOP 
    140 GetHEAD#fp,adr 
    150 POKE adr+5,1
    160 POKE_L adr+6,dataspace 
    170 SetHEAD#fp,adr 
    180 CLOSE#fp: RECHP adr
    190 END DEFine MAKEJOB

**CROSS-REFERENCE**

:ref:`sethead` saves a file header. See
:ref:`fgeth-dlr` for information about the file
header. :ref:`headr` is very similar to
:ref:`gethead`. See also
:ref:`hget` and :ref:`hput`.

--------------


..  _get-word:

GET\_WORD
=========

+----------+-------------------------------------------------------------------+
| Syntax   | word = GET\_WORD(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The next two bytes are read from the appropriate file and returned as an integer value.  This is equivalent to CODE(INKEY$(#channel)) \* 256 + CODE(INKEY$(#channel)). See the caution above for :ref:`get-byte` as it applies here as well. Any negative numbers returned will always be an error code.

**EXAMPLE**

::

    w = GET_WORD(#3)
    

**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-float`, :ref:`get-long`, :ref:`get-string`.


-------



..  _getxy:

GETXY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  GETXY x%, y%                                                     |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

This command draws a haircross (with its centre at (x%,y%) which can be
moved with the cursor keys. Holding down <SHIFT> while pressing a cursor
key will speed up movement. Once the haircross is placed in the correct
position, press <SPACE> to return to BASIC. The two parameters x% and y%
will be updated to the position of the centre of the cross.

**NOTE 1**

It is obligatory to pass integer variables to GETXY.

**NOTE 2**

GETXY returns a wrong value for y% on Minerva ROMs, so it is unusable.

**NOTE 3**

Turbo and Supercharge compilers cannot compile this command.

**WARNINGS**

See :ref:`set`\ .

**CROSS-REFERENCE**

:ref:`invxy`

--------------


..  _go--sub:

GO SUB
======

+----------+-------------------------------------------------------------------+
| Syntax   |  GO SUB line\_number (GOSUB is expanded to GO SUB)                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The command GO SUB was only implemented to make SuperBASIC more
compatible with other versions of BASIC. 

SuperBASIC offers much more
elegant and powerful alternatives to this command - 'structured
programming'. Structured programs do not have to be longer than the same
program using GO SUB commands. 

It is strongly recommended that you do
not use GO SUBs in programs. A similar effect (and much more besides)
can be achieved by using DEFine PROCedure and DEFine FuNction. 

The idea behind GO SUB is that it jumps to a sub-routine within a program which
starts at the specified line\_number. Program flow then continues
through that sub-routine until a RETurn statement is found, in which
case, control is then returned to the statement following the original
GO SUB.

**Example**

A simple program which prints a title in shadow writing, using GO SUB to
call up the shadow writing routine:: 

    100 MODE 8 
    110 WINDOW 448,200,32,16:PAPER 0:CLS 
    120 a$='Hello there World' 
    130 GO SUB 1000 
    140 PAUSE 
    150 CLS 
    160 : 
    999 STOP 
    1000 CSIZE 2,0 
    1010 AT 10,10:INK 4:PRINT a$
    1020 CURSOR 42,56,10,10:INK 7:OVER 1:PRINT a$:OVER 0 
    1030 RETurn

This is actually much easier to read (and more flexible) if re-written
to use DEFine PROCedure instead (note that there is no longer any need
for line 999). 

::

    100 MODE 8 
    110 WINDOW 448,200,32,16:PAPER 0:CLS 
    130 SHADOW_PRINT "Hello there World' 
    140 PAUSE 
    150 CLS 
    160 : 
    1000 DEFine PROCedure SHADOW_PRINT(v$) 
    1010   CSIZE 2,0 
    1020   AT 10,10:INK 4:PRINT v$
    1030   CURSOR 42,56,10,10:INK 7:OVER 1:PRINT a$:OVER 0 
    1040 END DEFine

**NOTE 1**

It is not a crime to use GO SUB in your programs, after all, machines
are built for human beings, so the machines should be adapted to users,
and users must all find the most comfortable way for them to use their
machines.

**NOTE 2**

A calculated GO SUB statement, eg::

    GO SUB 1000+x*100
    
although allowed by the interpreter, is unlikely to be compiled successfully. Secondly,
RENUM is unable to change the line number of such GO SUBs. There were
also problems with using an expression for GO SUB in SMS pre v2.59.

**NOTE 3**

Avoid using GO SUB in an in-line FOR loop - see Note 2 of FOR.

**CROSS-REFERENCE**

Try to use SuperBASIC's more powerful
:ref:`repeat`, :ref:`for`,
:ref:`define--procedure` and :ref:`define--function` structures instead!

--------------


..  _go--to:

GO TO
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  GO TO line\_number(GOTO is expanded to GO TO)                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The command GO TO behaves in a similar way to GO SUB in that it forces
program flow to jump to a different part of the program. It is not
possible to RETurn to the statement following GO TO, unless you use
another GO TO command. SuperBASIC allows much more elegant and powerful
structures which should be used.

**Example**

An extremely simple password check::

    10 INPUT Password$ 
    20 IF Password$=='QL lives' THEN GO TO 50 
    30 PRINT 'Access DENIED' 
    40 GO TO 10
    50 PRINT 'Access Granted'

 This would be much better if re-written::

    10 REPeat Pass_loop 
    20   INPUT Password$ 
    30   IF Password$=='QL lives' THEN EXIT Pass_loop 
    40   PRINT 'Access DENIED' 
    50 END REPeat Pass_loop 
    60 PRINT 'Access Granted'

**CROSS-REFERENCE**

Please read :ref:`go--sub` before you dare to try
:ref:`go--to`!

--------------


..  _gpoint:

GPOINT
======

+----------+------------------------------------------------------------------------------------+
| Syntax   |  GPOINT [#ch,] x,y [,x\ :sup:`2`\ ,y\ :sup:`2` [,x\ :sup:`3`\ ,y\ :sup:`3`, ...] ] |
+----------+------------------------------------------------------------------------------------+
| Location |  GPOINT                                                                            |
+----------+------------------------------------------------------------------------------------+

This command is the same as POINT but fixes the bug in MGx ROMs.

--------------


..  _grab:

GRAB
====

+----------+-------------------------------------------------------------------+
| Syntax   |  GRAB (bytes)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

GRAB is a function which reserves a specified amount of space in the
common heap area of memory for use and returns the start address of the
allocated area.

**CROSS-REFERENCE**

With :ref:`grab` (unlike
:ref:`alchp`), reserved memory can only be given
back to QDOS for other purposes with
:ref:`release`. It is necessary to know the start
address returned by :ref:`grab` to do this, so a
formula like :ref:`scrbase` GRAB(32768) wastes 32k of RAM
if :ref:`scrbase` is used again. Although
:ref:`grab` is comparable to
:ref:`respr` in this respect, it will work with jobs
in memory just like :ref:`alchp`. See also
:ref:`reserve`. The amount of available memory can
be found by using :ref:`free` or :ref:`free-mem`.

--------------


..  _gregor:

GREGOR
======

+----------+-------------------------------------------------------------------+
| Syntax   |  GREGOR (day%, month%, year%)                                     |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function GREGOR takes three integers (floats & longs are rounded to the
nearest integer) to specify a date and returns the weekday as a number
from 1 to 7 where: 

- 1 = Sunday, ( See Note 1 !) 
- 2 = Monday, 
- 3 = Tuesday,
- 4 = Wednesday, 
- 5 = Thursday, 
- 6 = Friday,
- 7 = Saturday. 

As the name of the function suggests GREGOR uses the Gregorian calender. 

This was introduced in 1583, so GREGOR has to refuse earlier years. Invalid
parameters are not reported by breaking with an error (unless one of the
parameters is out of integer range) but by returning zero.

**Example**

Print your own calendar! 

::

    100 CLS 
    110 REPeat getmonth 
    120   INPUT "Year:"!year;TO 12;"Month:"!month 
    130   firstday$ = GREGOR(1,month,year)
    135   firstday=firstday$(1) 
    140   IF NOT firstday THEN 
    150     PRINT "Invalid input." 
    160   ELSE EXIT getmonth 
    170   END IF 
    180 END REPeat getmonth 
    190 FOR lastday = 28 TO 31 
    200   IF NOT GREGOR(lastday+1,month,year): EXIT lastday 
    210 END FOR lastday 
    220 : 
    230 PRINT \" Sun Mon Tue Wed Thu Fri Sat" 
    240 PRINT FILL$(" ",4*(firstday-1)); 
    250 FOR day = 1 TO lastday
    260   PRINT FILL$(" ",4-LEN(day));day; 
    265   xday$=GREGOR(day,month,year)
    270   IF xday$(1) = 7 THEN PRINT 
    280 END FOR day

**NOTE 1**

GREGOR was originally intended to return 1 for Monday, 2 for Tuesday and
so on. The current version (v2.05) follows the Christian tradition where
Sunday was regarded as the first day of the week. The programming
example above corrects this by applying this interpretation and uses::

    230 PRINT " Sun Mon Tue Wed Thu Fri Sat"
    
instead of::

    230 PRINT " Mon Tue Wed Thu Fri Sat Sun".

**NOTE 2**

Current versions (v2.05) of this command include a bug which mean that
it will not work correctly on Minerva, SMSQ/E and possibly other ROMs.

**CROSS-REFERENCE**

:ref:`easter`, :ref:`day-dlr`

--------------


..  _gt-dlr:

GT$
===

+----------+-------------------------------------------------------------------+
| Syntax   |  GT$ (type, string1$, string2$)                                   |
+----------+-------------------------------------------------------------------+
| Location |  Btool                                                            |
+----------+-------------------------------------------------------------------+

This function allows you to compare two strings using the comparison
types supported by QDOS - it is therefore more flexible than direct
comparison using operators (see Appendix 11). The function will always
return 1 if string1$ is greater than string2$ and is therefore similar
to::

    PRINT string1$ > string2$
    
However, you can specify one of four comparison types, which will
affect the outcome: 

+------+-----------------------------------------------------------------------------------------------------------------------------------+
| TYPE | Effect                                                                                                                            |
+======+===================================================================================================================================+
| 0    | Compare the two strings character by character                                                                                    |
+------+-----------------------------------------------------------------------------------------------------------------------------------+
| 1    | Ignore the case of the letters                                                                                                    |
+------+-----------------------------------------------------------------------------------------------------------------------------------+
| 2    | If there is no difference in the characters, compare the values of any embedded numbers.                                          |
+------+-----------------------------------------------------------------------------------------------------------------------------------+
| 3    | Ignore the case of the letters and still if there is no difference in the characters, compare the values of any embedded numbers. |
+------+-----------------------------------------------------------------------------------------------------------------------------------+

The characters are compared by using the following order::

    SPACE
    !"#$%&'()\*+,-/:;<=>?@[\\]^\_£{\|}~© 01234567890
    AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz 
    Foreign characters (in order of the character set)

**CROSS-REFERENCE**

See :ref:`instr`. :ref:`ge-dlr`,
:ref:`lt-dlr`, :ref:`le-dlr`,
:ref:`eq-dlr` and :ref:`ne-dlr` are all
similar facilities.

