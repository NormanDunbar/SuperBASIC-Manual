
==========
Keywords L
==========

TODO
====

- LANGUAGE and LANGUAGE$ have the same URL.
- LLIST, LPRINT and LPRINT$ are referenced, but are not in this file.
- :ref:`lmar` references ESC whihc is not found anywhere.



..  _lang-use:

LANG\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   || LANG\_USE num  or                                                |
|          || LANG\_USE kcode                                                  |
+----------+-------------------------------------------------------------------+
| Location ||  SMS                                                             |
+----------+-------------------------------------------------------------------+

This command sets the language to be used by SMS for its message tables
(this includes interpreter messages and error messages). The value of
num and kcode can be the same as for the SMS implementation of
:ref:`kbd-table`\ . A description of the message tables and how to link in new
message modules is contained in IQLR Volume 5 Issue 1 and Issue 5.

**NOTE**

If you set a different language to the version of the Psion programs
which you are using, then you may find that the DATE
function in Archive and Abacus fails.

**CROSS-REFERENCE**

:ref:`language`
and :ref:`language-dlr` allow you to find out
about the current language. :ref:`tra` allows you to
set the various message tables also. See
:ref:`kbd-table` and
:ref:`set-language`.

--------------


..  _language:

LANGUAGE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  LANGUAGE [(code)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This function returns a number representing the international dialling
code for the current language implementation (if code is not specified).
Otherwise it will return the dialling code of the language which would
be used if the language represented by code was installed using
LANG\_USE (in which case code can be either the international dialling
code or the car registration code).

**CROSS-REFERENCE**

:ref:`language-dlr` returns the car registration
code. :ref:`lang-use` allows you to set the
language for the messages.

--------------


..  _language-dlr:

LANGUAGE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   || LANGUAGE$  or                                                    |
|          || LANGUAGE$ (code)(SMS only)                                       |
+----------+-------------------------------------------------------------------+
| Location || THOR range of computers, SMS                                     |
+----------+-------------------------------------------------------------------+

This function returns a string representing the current language layout
of the keyboard which is linked into the QL. Unfortunately, the string
returned is different on THORs and SMS's. For a list of the strings
returned on THOR computers, see :ref:`set-language`. Under SMS the string
returned is the international car registration code for the language
currently loaded (if code is not specified). The second variant returns
the car registration code of the language which would be used if the
language represented by code
was installed using LANG\_USE (in which case code can be either the
international dialling code or the car registration code).

**CROSS-REFERENCE**

:ref:`set-language` allows you to alter
the current keyboard. See also :ref:`language`
and :ref:`lang-use`.

--------------


..  _lar:

LAR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  LAR file, array                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ARRAY                                                            |
+----------+-------------------------------------------------------------------+

LAR loads a file which must have been stored with SAR or SARO
into a dimensioned array. The array must have been initialised with DIM
to the same dimensions of the stored array, and of course the type
(float, integer, string) must be the same. The default data device is
supported.

**CROSS-REFERENCE**

See :ref:`datad-dlr` about the default data device.
:ref:`sar` and :ref:`saro` are
complementary commands.

--------------


..  _lbytes:

LBYTES
======

+----------+-------------------------------------------------------------------+
| Syntax   || LBYTES device\_filename, start  or                               |
|          || LBYTES [device\_]filename, start(Toolkit II only)  or            |
|          || LBYTES #channel, start(SMS only)                                 |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This command loads a chunk of machine code (or data) stored on the
given device under the specified filename and will report the error 'Not
Found' (-7) if either the device or filename does not exist. If Toolkit
II is present, this command supports the default data device (see
DATAD$). If found, the chunk of machine code is loaded into the QL,
starting at the specified start address. The code is loaded in one huge
block, which means that loading is very quick. However, there is also no
check on the type of file being loaded and therefore you should make
sure that you know what you are doing. Under SMS the third variant
allows you to load the data from the specified channel which must be
open to a file. This allows for more efficient programs, so that you can
perform various tests on the file beforehand (such as test its length
and file type), whilst only opening a channel to the file once.

**Examples**

One of the main uses of this command is to load in machine code Toolkits
and extensions. It is important to note that if this command is used to
do this, on pre JS ROMs, the commands in the machine code Toolkit cannot
be used in the same program which links them in. A typical boot program
would therefore be::

    100 a=RESPR (1024) : LBYTES flp1_Toolkit_ext,a : CALL a 
    110 LRUN flp1_Main_bas

Another use of LBYTES may be to load a screen which has been designed
in a drawing program. A normal QL screen is a maximum of 32768 bytes
long, however quite often screens can be much larger, so it is important
to ensure that you check the length of the file before loading in what
may be a screen file. To load a screen under SMS, use::

    10 OPEN_IN #3,flp1_Loading_scr 
    20 scr_length=FLEN (#3) 
    30 scr_size=SCR_YLIM * SCR_LLEN 
    40 IF scr_size < scr_length 
    42 PRINT #0,'Screen resolution is too small for the saved file.':STOP 
    45 END IF 
    50 IF scr_size>scr_length:PRINT #0,'Screen resolution is too big for the saved file.':STOP 
    60 LBYTES #3,SCR_BASE 
    70 CLOSE #3

**WARNING**

There is no check on the value of start, so ensure that you only try to
LBYTES machine code into RAM which has been set aside with ALCHP or
RESPR. Also ensure that the file is not too long to fit in the area of
RAM allocated.

**CROSS-REFERENCE**

Normally code loaded with :ref:`lbytes` has been
saved using :ref:`sexec` or
:ref:`sbytes`. :ref:`flen`
allows you to find out the length of a file,
:ref:`ftyp` its file type.

--------------


..  _lcm:

LCM
===

+----------+----------------------------------------------------------------------------------------------------------+
| Syntax   |  LCM (x\ :sup:`1`\ , x\ :sup:`2`\ , :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`) where x\ :sup:`i`\ =0..INTMAX  |
+----------+----------------------------------------------------------------------------------------------------------+
| Location |  Math Package                                                                                            |
+----------+----------------------------------------------------------------------------------------------------------+

LCM is a function which takes two or more numeric parameters and finds
their least common multiple, ie. the smallest number which can be
divided by all of the parameters without a remainder. The parameters
should be positive integers.

**Example**

::

    PRINT LCM (2,3,4)
    
returns 12 and indeed 12/2=6, 12/3=4 and 12/4=3.

**NOTE**

If you are not looking for the least common multiple but any common
multiple then simply multiply all the numbers, eg. 2\*3\*4=24.

**CROSS-REFERENCE**

:ref:`gcd`

--------------


..  _ldraw:

LDRAW
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LDRAW x1,y1 TO x2,y2, col                                        |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

This command is similar to DRAW, ie. it draws quite a thick line on the
screen, but LDRAW is part of the same Toolkit as SET
and uses a different col parameter to DRAW, see SET for that.

**Example**

Well, the sample listing whihc follows on below, is a bit too long for a
simple demonstration of LDRAW. 

The variable rstep% in line 110 determines via pics% how much
memory is required to run the animation. 

Unless you have SMS or Minerva, you will have to replace i% and j% by i and j. 

::

    100 WINDOW 512,64,0,0: PAPER 0: INK 3: CLS 
    110 rstep% = 20 
    120 pics% = 360 / rstep%: DIM adr(pics%): i% = 0 
    130 FOR r = 0 TO 360-rstep% STEP rstep% 
    140   i%=i%+1: CLS: AT 0,0: PRINT "(";i%;")";TO 6;r;"ø" 
    150   PYRAMID 20, 256, 32, r, r, r, 3 
    160   adr(i%) = ALCHP(HEX("2000")) 
    170   IF NOT adr(i%) THEN CLCHP: STOP: REMark memory overflow 
    180   MM_MOVE HEX("20000"), adr(i%), HEX("2000") 
    190 END FOR r 
    200 REPeat Animation 
    210   FOR i% = 1 TO pics%
    220     MM_MOVE adr(i%), HEX("20000"), HEX("2000") 
    230     IF KEYROW(1)&&8 THEN EXIT Animation 
    240   END FOR i% 
    250 END REPeat Animation 
    260 CLCHP: STOP
    270 : 
    290 DEFine PROCedure PYRAMID (size, px%,py%, rotx,roty,rotz, c%)
    300   LOCal i%, j%, p1(2), p2(2) 
    310   RESTORE 410 
    320   FOR i% = 1 TO 8 
    330     READ p1(0),p1(1),p1(2), p2(0),p2(1),p2(2) 
    340     ROTATION p1(0),p1(1),p1(2), rotx, roty, rotz 
    350     ROTATION p2(0),p2(1),p2(2), rotx, roty, rotz 
    360     FOR j%=0 TO 2: p1(j%)=size*p1(j%): p2(j%)=size*p2(j%) 
    370     LDRAW px%+p1(0),py%+p1(1) TO px%+p2(0),py%+p2(1), c% 
    380   END FOR i% 
    390   RETurn 
    400 : 
    410   REMark base square 
    420   DATA -1, -1, 0, 1,-1, 0 
    430   DATA 1, -1, 0, 1, 1, 0 
    440   DATA 1, 1, 0, -1, 1, 0 
    450   DATA -1, 1, 0, -1,-1, 0 
    460   REMark top  
    470   DATA -1, -1, 0, 0, 0, 2 
    480   DATA 1, -1, 0, 0, 0, 2 
    490   DATA 1, 1, 0, 0, 0, 2
    500   DATA -1, 1, 0, 0, 0, 2 
    510 END DEFine PYRAMID 
    520 : 
    530 : 
    540 DEFine PROCedure ROTATION (x, y, z, wx, wy, wz) 
    550   REMark rotate point (x,y,z) by angles wx, wy and wz 
    560   REMark in degrees around point (0,0,0)  
    570   LOCal x1, y1, x2, z2 
    580   LOCal cx, cy, cz, sx, sy, sz 
    590   cx = COS(RAD(wx)): cy = COS(RAD(wy)): cz = COS(RAD(wz)) 
    600   sx = SIN(RAD(wx)): sy = SIN(RAD(wy)): sz = SIN(RAD(wz)) 
    610   x1 = x * cz -y * sz 
    620   y1 = x * sz + y * cz 
    630   x = x1 * cy - z * sy 
    640   z2 = x1 * sy + z * cy 
    650   y = y1 * cx + z2 * sx 
    660   z = -y1 * sx + z2 * cx
    670 END DEFine ROTATION 
    680 :
    700 DEFine PROCedure MM_MOVE (addr1, addr2, bytes) 
    710   REMark move memory 
    720   LOCal routine 
    730   IF VER$ = "JSL1" THEN 
    740     routine = PEEK_W(344) + 16384 
    750     CALL routine, bytes, 2, 3, 4, 5, 6, 7, addr2, addr1 
    760   ELSE 
    770     REMark with HCO: 
    780     BMOVE addr1, addr1+bytes TO addr2 
    790   END IF 
    800 END DEFine MM_MOVE

**NOTE 1**

LDRAW assumes that the screen is in a resolution of 512x256 pixels and
is located at $20000.

**NOTE 2**

LDRAW only works correctly in MODE 4.

**WARNINGS**

See SET.

**CROSS-REFERENCE**

:ref:`draw`. Please use
:ref:`ldraw` only if you know what you are doing, do
not intend to write user-friendly programs, and especially if you do not
intend to show your program listing to someone else! You can always use
:ref:`line` and :ref:`line-r`,
commands, :ref:`dotlin` and
:ref:`xdraw`, which can draw dotted lines
(:ref:`dotlin`) or work in
:ref:`xor` mode (:ref:`xdraw`).

--------------


..  _left:

LEFT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LEFT [ #channel ]                                                |
+----------+-------------------------------------------------------------------+
| Location |  QSOUND                                                           |
+----------+-------------------------------------------------------------------+

This command will move the text cursor left one column in the specified
channel (default #1). If there is a pending newline on the specified
channel (for example after a PRINT
command) this will be cleared, making it as if the last PRINT
(or INPUT) statement ended with a comma - for example::

    100 PRINT 'Hello World' 
    110 PRINT 'THIS LINE IS PRINTED AFTER A PENDING NEWLINE' 
    120 LEFT
    130 PRINT 'THIS OVERWRITES PART OF THE LAST TEXT'

'Out of Range' will be reported if you try to move the cursor left past
column zero.

**CROSS-REFERENCE**

:ref:`at` allows you to position the text cursor.
:ref:`print`, :ref:`to`,
:ref:`input` and :ref:`cursor`
also affect the text cursor.

--------------


..  _len:

LEN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  LEN (string$)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function LEN returns the number of characters contained in the
given string expression. However, due to the QL's native coercion
routines, the expression passed as a parameter need not be a string (!)

**Examples**

::

    x=100: PRINT LEN(x): REMark Returns 3. 
    PRINT LEN ('A string'): REMark Returns 8. 
    DIM x$(12): PRINT LEN (x$): REMark Returns 0, but add the following 
    : x$='Hello': PRINT LEN(x$): REMark Returns 5, the same as PRINT x$(0)

**NOTE**

On pre-JS ROMs, if you use PRINT LEN(x$), an 'Out of Memory' error will
be reported if you have previously tried to make x$
longer than 32766 characters, for example with:: 

    x$=FILL$('x',32764)
    x$=x$&'xxx' 
    PRINT LEN (x$)

**CROSS-REFERENCE**

:ref:`fill-dlr` returns a string of a specified length.
:ref:`dimn` returns important information about
arrays. See also the Compatability Appendix for some important
information concerning string lengths.

--------------


..  _let:

LET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  [LET] variable=expression                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The command LET has only been implemented to make SuperBASIC more
compatible with other versions of BASIC. It assigns a specific value to
the specified variable, which can be of any type. The command may
actually be omitted altogether. Normally any mistake in this command
results in an 'Error in Expression' report.

**Examples**

::

    LET x=100+10\*20
    
Assigns the value 300 to the variable x.

::
    
    x=100+10\*20 
    
Is exactly the same as above. 
    
::
    
    LET a$='Hello '&x

This places the string 'Hello 300' into the variable a$. The value of x is converted into a
string and then appended. 

::

    LET position(100)=10
    
This assigns the value 10 to the 101st element of the array position (see DIM).

**NOTE 1**

On the AH ROM, you need to be careful of what is being assigned to a
numerical variable: LET X="." did not produce an error on this ROM.
Compare this with LET X='0.12' which in fact assigns the value 0.12 to
the variable x due to coercion.

**NOTE 2**

It may be useful to explain the error codes which may be reported when
trying to assign a value to a variable. Under SMS the improved
interpreter will report more meaningful errors if you try to use this
command incorrectly and therefore it is these errors which are
highlighted.

Assignment can only be to a variable or array element
    This is reported if you try to assign a value to a Procedure or Function
    name, eg: PRINT = 100 
    
    On other versions this causes an ...

Error in Expression
    When assigning values to arrays there are four possible error reports:

Only arrays or strings may be indexed
    This will be reported if you try to assign a value to an undimensioned
    array, for example if you used the line: position (100)=10
    without having used the line: DIM position (200)
    beforehand. On other implementations, this causes the error ...

**Bad Name**

Cannot assign to sub-array
    We have not been able to find a situation when this error occurs.

Unacceptable array index list
    This is reported normally if you try to use too many indices to
    reference an existing array, for example: DIM x(100) : PRINT x(10,10)
 
    On other implementations this causes an

**Out of Range**

Array index out of range
    This is reported if you try to use an index which is greater than that
    used when the array was dimensioned, for example: DIM x(100) :
    x(101)=100

    On other implementations this also causes an

**Out of Range**

**WARNING**

On SMS, you can easily crash SBASIC by missing out an index on an
assignment to a DIMensioned array, for example:: 

    DIM x(100) x (10, ) = 100 

Will report Not Complete::

    x(10, , ) = 100

Will crash SBASIC.

On Minerva (and possibly other ROM versions) both of these merely report
'Error In Expression'.

**CROSS-REFERENCE**

:ref:`read` and :ref:`input` also
allow you to assign a value to a variable.

--------------


..  _level2:

LEVEL2
======

+----------+-------------------------------------------------------------------+
| Syntax   | present = LEVEL2(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

If the device that has the given channel opened to it has the level 2 drivers, then present will be set to 1, otherwise it will be set to 0.  The level 2 drivers allow such things as sub_directories to be used, when a :ref:`dir` is done on one of these devices, sub-directories show up as a filename with '->' at the end of the name. Gold Cards and later models of Trump cards have level 2 drivers. Microdrives don't.

**EXAMPLE**

::

    2500 DEFine PROCedure MAKE_DIRECTORY
    2510   LOCal d$, t$, l2_ok, ch
    2520   INPUT 'Enter drive names :';d$
    2530   IF d$(LEN(d$)) <> '_' THEN d$ = d$ & '_': END IF 
    2540   PRINT 'Please wait, checking ...'
    2550   ch = DJ_OPEN_OVER (d$ & CHR$(0) & CHR$(0))
    2560   IF ch < 0: PRINT 'Cannot open file on ' & d$ & ', error: ' & ch: RETurn
    2570   l2_ok = LEVEL2(#ch)
    2580   CLOSE #ch
    2590   DELETE d$ & CHR$(0) & CHR$(0)
    2600   IF l2_ok
    2610     INPUT 'Enter directory name please : ';t$
    2620     MAKE_DIR d$ & t$
    2630   ELSE 
    2640     PRINT 'Sorry, no level 2 drivers!'
    2650   END IF 
    2660 END DEFine MAKE_DIRECTORY


-------



..  _lget:

LGET
====

+----------+-----------------------------------------------------------------------------+
| Syntax   || LGET [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
|          || LGET [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+-----------------------------------------------------------------------------+
| Location |  SMSQ/E                                                                     |
+----------+-----------------------------------------------------------------------------+

This command is very similar to BGET, although this fetches a longword
(4 bytes) at a time (in the range 0..2\ :sup:`32`\ -1) from the given channel
(default #3).

**NOTE**

LGET is affected by TRA.

**CROSS-REFERENCE**

See :ref:`bget`. :ref:`lput` is
complementary function. :ref:`wget` allows you to
fetch word values.

--------------


..  _line:

LINE
====

+----------+----------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   |  LINE [#chan,] [x,y] [TO x\ :sup:`1`,y\ :sup:`1`] :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] [TO x\ :sup:`j`\ ,y\ :sup:`j`] ]\ :sup:`\*` |
+----------+----------------------------------------------------------------------------------------------------------------------------------------+
| Location |  QL ROM                                                                                                                                |
+----------+----------------------------------------------------------------------------------------------------------------------------------------+

This command is part of the QL's graphics repertoire and allows you to
draw a straight line in the specified channel (default #1) in the
current INK colour between any two points. As with all of the other
graphics commands, the exact size and position of the line depends upon
the current SCALE. Unfortunately, there is no way of making the line any
thicker, other than by drawing parallel lines. Although the above syntax
may seem rather complex, this can be explained as follows: 

If the separator TO appears between any two sets of co-ordinates, then a line
will be drawn between those two co-ordinates. 

If however the two sets of
co-ordinates are the same, nothing will be drawn, eg: LINE 10,10 TO
10,10 has no effect. 

If the start co-ordinates are not specified, then the
current graphics cursor is used as the one end of the line, eg: LINE
10,10 TO 15,10 TO 20,20
will draw a line between the points (10,10) and (15,10) and then a line
between (15,10) and (20,20). The graphics cursor is placed at the last
set of co-ordinates. 

If the separator TO does not appear, then no line
is drawn and the graphics cursor is moved to the last set of
co-ordinates. For example: LINE 10,10 and LINE 20,20,10,10
have exactly the same effect - they both place the graphics cursor at
the point (10,10). 

Any part of the lines which lie outside of the
specified channel will not be drawn, but no error will be reported.

**Example**

A simple demonstration program::

    100 MODE 8 110 WINDOW 448,200,32,16:PAPER 0:CLS 
    120 SCALE 100,0,0 
    130 OVER -1 
    140 REPeat loop
    150   xstep=RND 
    160   INK RND(7) 
    170   FOR i=1 TO 360 STEP xstep 
    180     ix=RAD(i)
    190     LINE 50,50 TO 50+COS(ix)\*50,50+SIN(ix)\*50 
    200   END FOR i 
    210 END REPeat loop

**NOTE**

On a MG ROM, you may find that the last point is not always plotted.

**CROSS-REFERENCE**

:ref:`line-r` is very similar. See also
:ref:`ellipse`,
:ref:`circle`, :ref:`arc`,
:ref:`point` and :ref:`scale`.

--------------


..  _line-r:

LINE\_R
=======

+----------+-------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   |  LINE\_R [#chan,] [x,y] [TO x\ :sup:`1`,y\ :sup:`1`] :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] [TO x\ :sup:`j`\ ,y\ :sup:`j`] ]\ :sup:`\*` |
+----------+-------------------------------------------------------------------------------------------------------------------------------------------+
| Location |  QL ROM                                                                                                                                   |
+----------+-------------------------------------------------------------------------------------------------------------------------------------------+

This command is very similar to LINE, except that all co-ordinates are
taken to be relative to the current graphics cursor.

**CROSS-REFERENCE**

Please see :ref:`line`,
:ref:`circle-r`,
:ref:`arc-r`,
:ref:`ellipse-r` and
:ref:`point-r`.

--------------


..  _linkup:

LINKUP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  LINKUP file$                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Memory Toolkit (DIY Toolkit Vol H)                               |
+----------+-------------------------------------------------------------------+

This command is similar to LRESPR except that it will work even if jobs
are running in the system. Although it loads the specified file into the
common heap, it marks the area of memory as permanent and therefore this
memory will not be removed by CLCHP or NEW. This therefore provides a
safe means of linking in new toolkits and device drivers permanently
even when Jobs are have already been EXECuted. Unlike LRESPR the default
data device is not supported and the filename must be supplied in full
as a string.

**CROSS-REFERENCE**

See :ref:`reserve` and
:ref:`discard`. Also see
:ref:`lrespr` and :ref:`alchp`.

--------------


..  _lint2:

LINT2
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LINT2 [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command lists all interrupt (level 2) service routines and their
link pointers to the given channel (default #1). To understand this
list, you will need to refer to documentation on the operating system
(QDOS).

**CROSS-REFERENCE**

:ref:`lschd` and :ref:`lpoll`
list other information about the current system interrupts. Details of
the external interrupt service list is contained in the QDOS/SMS
Reference Manual Section 6.

--------------


..  _list:

LIST
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LIST [#ch,] [range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*` ]    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command lists (in ASCII form) the specified range of the currently
loaded SuperBASIC program to the specified channel (default #2). Range
must be in the form: [[start\_line] TO [end\_line]]. 

The default
start\_line is 1 and the default end\_line is 32767, therefore if no
range is given, the LISTing range defaults to: 1 TO 32767. 

Except under
SMS, when the last line of the given range is reached, a table is set up
which stores the current list range. This list range contains a list of
the lines of the program which are currently shown in #2 - if you alter
one of these lines (for example with EDIT or DLINE), then the listing in
#2 is re-drawn to reflect the change. Alterations to lines outside the
list range will have no effect. 

Again, except under SMS, special note is
also taken of the program line just above the displayed listing, and the
program line just below the displayed listing - if either of these lines
is altered, then the display will scroll accordingly to show the newly
altered line on screen.

**Examples**

::

    LIST #3

List the whole of the program in #3 

::

    LIST 1

List program line 1 in #2 

::

    LIST 100,1000 TO

List lines 100 and from 1000 onwards in #2

::

    OPEN#3,SER1: LIST#3: CLOSE#3 

will list the current program to a printer connected to ser1.

**NOTE 1**

Except under SMS, you may sometimes find a large chunk of the program
listing scrolling before your eyes if you alter a line outside the range
displayed in #2. This should not create any problems and generally
occurs when you press Break before the List Range has been updated.

**NOTE 2**

Version 2.13 (and later) of Toolkit II alters this command so that if
you are using LIST to output to a file, any errors will be reported
(such as 'Device Full' or 'Not Complete').

**NOTE 3**

Prior to SMS v2.67 LIST #ch where #ch does not exist would attempt to
SAVE the file.

**CROSS-REFERENCE**

When :ref:`list`\ ing to a file, this command is the
same as :ref:`save`.
:ref:`dline`, :ref:`ed`,
:ref:`edit`, and :ref:`renum` are
other commands for dealing with a SuperBASIC program in memory.

--------------


..  _list-tasks:

LIST\_TASKS
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  LIST\_TASKS [#ch]                                                |
+----------+-------------------------------------------------------------------+
| Location |  TASKCMDS (DIY Toolkit Vol J)                                     |
+----------+-------------------------------------------------------------------+

LIST\_TASKS is nearly the same as JOBS, but the output is slightly
different. Each line written to the specified channel (default #1)
consists of the job name, job number, job tag and priority. A 'w'
appended to the priority indicates that the job is currently suspended.

**CROSS-REFERENCE**

:ref:`jobs` is similar.

--------------


..  _lmar:

LMAR
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LMAR(n) with n=0..255                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to set the left margin
to n characters on EPSON compatible printers: PRINT LMAR (10)
is the same as PRINT CHR$(27)&'l'&CHR$(10)

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`alt`,
:ref:`esc`, :ref:`ff`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _ln:

LN
==

+----------+-------------------------------------------------------------------+
| Syntax   |  LN (x)                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the natural logarithm of the given value (in base
e), so that e\ :sup:`LN(x)`\ =x. Due to the nature of power numbers, the range of
x is 0>x<=2\ :sup:`2046`. 

Logarithms were first invented to make multiplication
and division easier, because whatever base you are working in,
multiplication and division can be calculated by using logarithms. For
example, x\*y is the same as EXP(LN(x)+LN(y)), or
10\ :sup:`(LOG10(x)+LOG10(y))`\ ; and x/y is the same as EXP(LN(x)-LN(y)), and
10\ :sup:`(LOG10(x)-LOG10(y))`. 

Another reason is that logarithms can make it
easier to calculate powers, for example, 10\ :sup:`(p\*LOG10(y))` gives the same
answer as y\ :sup:`p`, for any value of y or p. 

Another use for logarithms is to
enable square roots to be calculated. On the assumption that
x\*x=10\ :sup:`(2\*LOG10(x))`, the square root of a number y can be calculated
using the formula: 10\ :sup:`(LOG10 (y) / 2)`. 

Natural logarithms (base e) are
generally used in theoretical mathematics, as this can be useful in
differentiation, since if y=e\ :sup:`x`, dy<dx<y. Because negative values of x
cannot be handled by logarithms (in any base - this is because
x\ :sup:`y` must always be greater than zero!), you will need to check
for negative values and zero values separately.

**CROSS-REFERENCE**

:ref:`exp` converts natural logarithms to their true
numbers in base 10, :ref:`log10` provides logarithms
in base 10 (common logarithms), and :ref:`log2`
provides base 2 logarithms.

--------------


..  _load:

LOAD
====

+----------+-------------------------------------------------------------------+
| Syntax   || LOAD device\_filename  or                                        |
|          || LOAD [device\_]filename (Toolkit II)                             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

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


..  _loadpic:

LOADPIC
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  LOADPIC file$                                                    |
+----------+-------------------------------------------------------------------+
| Location |  PICEXT                                                           |
+----------+-------------------------------------------------------------------+

This command will load an uncompressed 32K screen file and display it
on the main screen. - This works exactly the same as LBYTES
file$,131072. Note that LOADPIC needs the full filename to be supplied
as a string.

**Example**

    LOADPIC "flp1_Example_scr"

**NOTE 1**

LOADPIC assumes that the screen will be located at $20000 and will
therefore not work on Minerva's second screen.

**NOTE 2**

LOADPIC will not work on high resolution screens as it expects the
screen to be 512x256 pixels.

**CROSS-REFERENCE**

:ref:`savepic`,
:ref:`sbytes`, :ref:`lbytes`,
:ref:`screen`, :ref:`expand`,
:ref:`compress`.

--------------


..  _local:

LOCal
=====

+----------+----------------------------------------------------------------------------------------------------------------------------+
| Syntax   |  LOCal var\ :sup:`1` :sup:`\*`\ [, var\ :sup:`x` [(index\ :sup:`1` :sup:`\*`\ [index\ :sup:`i`]\ :sup:`\*` )] ]\ :sup:`\*` |
+----------+----------------------------------------------------------------------------------------------------------------------------+
| Location |  QL ROM                                                                                                                    |
+----------+----------------------------------------------------------------------------------------------------------------------------+

This command must only be used as the first executable line within
either a PROCedure or FuNction definition block (ie. it can only be
preceded by REMark lines) - if it is used elsewhere, it will cause a
'bad line' error when the program is RUN. Under SMS's improved
interpreter the error 'Misplaced LOCal' will be reported. 

LOCal must be
followed by a list of variables which are said to be 'local' to that
definition block. This means that although a variable may already have
been used within the main body of the program, if it is local to that
definition block, on entry its value is stored and it is then made
'unset' (without value), and can then be used for any means within that
definition block (or within any sub-procedure or sub-function called by
that definition block). 

When the definition block is left (with END
DEFine or RETurn), the variable is restored to its original value.

Arrays can also be made LOCal by placing an index after their name,
which is used to specify their size (as with DIM). Indeed this is the
only way in which a simple variable can also be used as an array. In any
event, the parameters contained in the definition line are local to that
definition block and can also be safely used in the main program - these
are in fact swapped with the actual parameters passed for the duration
of the definition block (see DEFine PROCedure).

**Example**

This program shows the status of three variables at various stages -
note how x can be used as an array in the main program and a simple
variable within the PROCedure definition block::

    100 DIM x(10) 
    110 test$='Wait' 
    120 moder=4:x(1)=10 
    130 PRINT moder,test$,x(1) 
    140 Change_vars 
    150 PRINT moder,test$,x(1) 
    155 :
    160 DEFine PROCedure Change_vars 
    170   LOCal moder(2,10),x,test$ 
    180   PRINT moder(1,5),test$,x
    190   test$='Changed':moder(1,5)=10 
    200   x=5 
    210   PRINT moder(1,5),test$,x
    220 END DEFine

This produces the following output::

    4 Wait 10 line 130 
    0 * * line 180, local variables 
    10 Changed 5 line 210, local variables 
    4 Wait 10 line 150 

**NOTE 1**

On pre MG ROMs, any more than nine parameters may corrupt the program,
by replacing names with PRINT towards the end of a program. This can
however be circumvented by increasing the size of the Name Table by 8
bytes for each name (plus a little more for luck), by using the line::

    CALL PEEK_W(282)+36,N
    
This bug is fixed on the ST/QL Emulator (with E-Init software v1.27+),
Minerva and SMS.

**NOTE 2**

On most ROMs, you cannot LOCal the names of the parameters passed to the
PROCedure or FuNction. ROMs which can cope with this will simply set the
passed value to undefined. Type in the following small procedure test:: 

    100 DEFine PROCedure test(a,b)
    110   LOCal a 
    120   PRINT a,b 
    130 END DEFine
    
If your interpreter behaves correctly then::

    test 3,2

will write::

    * 2
    
SMS will print::

    0 2 

Any reference to a in the procedure, eg. a=a+1, will
break with an error in expression (-17) because the LOCal declaration of
a undefined the passed parameter. You would need to expressly assign a value to a 
within the PROCedure for this to work. This works correctly on Minerva
ROMs (ie. a is unset by the LOCal command).

**CROSS-REFERENCE**

:ref:`dim` sets up arrays normally. :ref:`define--procedure`, 
:ref:`define--function` and :ref:`end--define` are used to identify definition
blocks.

--------------


..  _lock:

LOCK
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LOCK file,code$,code                                             |
+----------+-------------------------------------------------------------------+
| Location |  CRYPTAGE                                                         |
+----------+-------------------------------------------------------------------+

This command encodes the given file (the full filename must be stated)
using two codes, a string and a number, for security. Code$ can be any
string and the code number (an integer) must range between 0 and 32767.
Decoding with UNLOCK is only possible if both codes are known, so do not
forget them otherwise the file will be lost.

**Example**

LOCK ram1\_secret\_txt,"Phew",7241

**CROSS-REFERENCE**

:ref:`unlock` has the same syntax as
:ref:`lock` but deciphers
:ref:`lock`\ ed files.

--------------


..  _log2:

LOG2
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LOG2 (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function returns the logarithm to the base 2 of the given number,
which is calculated as LN(x)/LN(2).

**Example**

The greatest number which can be handled by SuperBASIC is returned by
INF as 1.61585E616. This is exactly 2\ :sup:`2047`, because
LOG2(INF)=2047 (ie. x=2\ :sup:`LOG2(x)`).

**CROSS-REFERENCE**

:ref:`log10`, :ref:`ln`,
:ref:`inf`.

--------------


..  _log10:

LOG10
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LOG10 (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function LOG10 calculates the logarithm to the base 10 of the given
number. For the non-mathematicians out there: x=10\ :sup:`LOG10(x)`.

**Examples**

::

    100 INPUT "Integer Number:"!x 
    110 PRINT "This number has"!INT(1+LOG10(ABS(x)))!"digits."

The trivial function LOGN finds the logarithm of x to any base b which
makes sense::

    10 DEFine FuNction LOGN (x,b) 
    20   RETurn LN(x)/LN(b) 
    30 END DEFine LOGN

**CROSS-REFERENCE**

:ref:`ln`, :ref:`log2`.

--------------


..  _lookup-pct:

LOOKUP%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  LOOKUP% (search$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  Function (DIY Toolkit - Vol R)                                   |
+----------+-------------------------------------------------------------------+

This function expects you to pass a string parameter which contains a
name used by the SuperBASIC interpreter. This name can be a machine code
Procedure or Functiom (such as are described here in this manual), or a
SuperBASIC variable, PROCedure or FuNction. If the specified name is
recognised then LOOKUP% returns the number of its entry in the name
list. If the name is not recognised, then the value -7 is returned.

**Examples**

::

    PRINT LOOKUP% ('PRINT')

will return 0 on most QL ROMs as this is normally the first name in the
name list. 

::

    PRINT LOOKUP% ('FSERVE')

can be used to see if Toolkit II's fileserver is available.

**NOTE 1**

This function will only look at the name list for SuperBASIC Job 0, so
although it can be used from within a compiled task to look at Job 0, it
cannot be used to look at a multiple BASIC interpreter!!

**NOTE 2**

This function will only work correctly with machine code Procedures and
Functions on SMS.

**CROSS-REFERENCE**

See\ :ref:`elis`, :ref:`key-add`.
:ref:`-name-dlr` allows you to look at the name list.
See also :ref:`flis` and
:ref:`find`.

--------------


..  _lower-dlr:

LOWER$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  LOWER$ (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Function (DIY Toolkit - Vol R)                                   |
+----------+-------------------------------------------------------------------+

This function takes the given string and converts any upper case
letters to lower case and then returns the whole string. This will
convert both UK and accented characters, although you may have to modify
the source code to enable it to work with some international character
sets.

**CROSS-REFERENCE**

Compare :ref:`upper-dlr`. See also :ref:`convcase-dlr`.

--------------


..  _lpoll:

LPOLL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LPOLL [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command lists all polling interrupts and their link pointers to
the given channel (default #1). While this text was being written, LPOLL
produced the following list::

    List of polled tasks: 
    Link Pointer   Routine 
    1.   $0002B5D8 $000C1434 
    2.   $0002B8B8 $0009E0C2 
    3.   $0002CAAA $000BD056 
    4.   $0002B840 $0009E988 

To understand these numbers, a deep knowledge of
assembly language and the operating system is necessary. Generally, each
interrupt is a kind of background job which does not appear in the job
list. For further information, refer to system documentation.

**CROSS-REFERENCE**

:ref:`lschd` and :ref:`lint2`
list other internal routines which are running in the interrupts.
:ref:`jobs` lists all jobs.

--------------


..  _lpr-use:

LPR\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  LPR\_USE device                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

LPR\_USE sets the default output device for LPRINT and LLIST. This can
be any valid QDOS device name, provided it is not longer than 24
characters. The definition can be found with LPRINT$, the default is
SER1 (ie. if LPR\_USE has not yet been used).

**Examples**

::

    LPR_USE par 
    LPR_USE ram1_print_dat 
    LPR_USE n2_ser1 
    LPR_USE con

**NOTE**

LPR\_USE does not check the validity of the given device, so even
completely wrong parameters are accepted::

    LPR_USE #2 
    
will set LPRINT$ to "2", LPRINT$ and LLIST will report the error.

**CROSS-REFERENCE**

:ref:`llist`, :ref:`lprint-dlr`,
:ref:`lprint-dlr`.

--------------


..  _lput:

LPUT
====

+----------+-----------------------------------------------------------------------------+
| Syntax   || LPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
|          || LPUT [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+-----------------------------------------------------------------------------+ 
| Location || SMSQ/E                                                                     |
+----------+-----------------------------------------------------------------------------+

This command is the complement to LGET, in that it places the longword
value for each item into the specified channel (default #3) at the
current file position (or the specified position if the first variant is
used).

**NOTE**

LPUT is affected by TRA.

**CROSS-REFERENCE**

See :ref:`bput` and :ref:`lget`.
:ref:`wput` and :ref:`put` are also
similar.

--------------


..  _lresfast:

LRESFAST
========

+----------+-------------------------------------------------------------------+
| Syntax   |  LRESFAST mc\_file                                                |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT for QVME (v2.31+)                                    |
+----------+-------------------------------------------------------------------+

This command is the same as LRESPR except that it will only work on a
file in RAM disk and loads that file into FastRAM on the Atari TT.

**CROSS-REFERENCE**

See :ref:`lrespr` and
also\ :ref:`resfast`,
:ref:`free-fast`.

Compare\ :ref:`respr`,
:ref:`alchp` and
:ref:`free-mem`.

--------------


..  _lrespr:

LRESPR
======

+----------+-------------------------------------------------------------------+
| Syntax   |  LRESPR mc\_file                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command is used as a quick way of loading and starting machine
code routines (mainly Toolkits). It will grab enough memory from the
Resident Procedure Area to hold the given file, load the file into
memory and then call it. Toolkit II sub-directories and the default data
device are supported. LRESPR could be re-written as the following
SuperBASIC procedure:: 

    100 DEFine PROCedure LRESPR (mc_file$) 
    110   LOCal length,adress 
    120   length=FLEN(\mc_file$) 
    130   adress=RESPR(length) 
    140   LBYTES mc_file,adress 
    150   CALL adress 
    160 END DEFine LRESPR

**Examples**

::

    LRESPR BeuleTools_bin 
    LRESPR ram1_MyTool_obj

**NOTE 1**

It is impossible to remove a program loaded with LRESPR so that the
occupied memory can be given back for other purposes.

**NOTE 2**

On version 2.23 (or later) of Toolkit II, LRESPR works even if a job is
running because in this case, it will load the file into the Common
Heap. CLCHP, NEW, CLEAR etc. do not remove code loaded in this way, so a
crash is impossible.

**NOTE 3**

When using LRESPR (or any other means) to link in extensions to
SuperBASIC, bear in mind that pre JS ROMs needed the command NEW (or
LOAD / LRUN) before those commands will be available. This happens on MG
ROMs sometimes as well.

**NOTE 4**

If this command is used to link a toolkit into a MultiBASIC under
Minerva or a multiple SBASIC under SMS, then that toolkit will be local
to that BASIC interpreter - when you remove that BASIC, the toolkit will
also disappear.

**CROSS-REFERENCE**

See the second example for :ref:`alchp`. See also
:ref:`linkup` and
:ref:`lresfast`.

--------------


..  _lrun:

LRUN
====

+----------+-------------------------------------------------------------------+
| Syntax   || LRUN device\_filename  or                                        |
|          || LRUN [device\_]filename (Toolkit II)                             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This command is exactly the same as LOAD except for the fact that the
program is automatically RUN as soon as loading is complete.

**CROSS-REFERENCE**

See :ref:`load`!

--------------


..  _lschd:

LSCHD
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LSCHD [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command lists all scheduler loop tasks with their linked pointers
to the specified channel (default #1). While this text was being
written, the following list was produced::

    List of scheduler loop tasks:
    link pointer routine 
    1. $0002B848 $0009E9C0 
    2. $0002D140 $000ACC2A 
    3. $0002C0F0 $000B685C 
    4. $0002B648 $000C1572 
    5. $000B3964 $000AFAEE 
    6. $000B5FDA $000B50FE 
    7. $00001206 $0000120E 
    8. $00002D7C $00002D90 
    9. $00003504 $0000350C 

An in-depth knowledge of the operating system and
machine code is necessary to understand this list. Please refer to the
operating system documentation.

**CROSS-REFERENCE**

:ref:`lpoll`, :ref:`lint2`.

--------------


..  _lwc-dlr:

LWC$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LWC$ (string$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  LWCUPC                                                           |
+----------+-------------------------------------------------------------------+

The function exchanges all upper case characters in the given string to
lower case characters and returns the result. Only the standard alphabet
is recognised - umlauts etc. are ignored.

**CROSS-REFERENCE**

:ref:`upc-dlr` and :ref:`upper-dlr`
return the string in upper case characters.

