PAGDIS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PAGDIS (lines) lines=0..127                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

 This function returns the printer control codes needed to set the
length of the page header when sent to EPSON compatible printers. PRINT
PAGDIS (lines) is equivalent to: PRINT CHR$(27) & CHR$(78) & CHR$(lines)

**Example**

To set the header to three lines: OPEN #3,ser1:PRINT
#3,PAGDIS(3):CLOSE#3

**CROSS-REFERENCE**

`PAGLIN <KeywordsP.clean.html#paglin>`__, `PAGLEN <KeywordsP.clean.html#paglen>`__,
`LMAR <KeywordsL.clean.html#lmar>`__, `RMAR <KeywordsR.clean.html#rmar>`__.

--------------

PAGLEN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PAGLEN (inches) inches=0..22                                     |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

 This function returns the control codes needed to set the length of a
page (in inches) when sent to EPSON compatible printers. This is
normally 12". The function is equivalent to:
CHR$(27)&'C'&CHR$(0)&CHR$(inches)

**CROSS-REFERENCE**

`PAGDIS <KeywordsP.clean.html#pagdis>`__, `PAGLIN <KeywordsP.clean.html#paglin>`__,
`LMAR <KeywordsL.clean.html#lmar>`__, `RMAR <KeywordsR.clean.html#rmar>`__.

--------------

PAGLIN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PAGLIN (lines) lines=0..127                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

 This function returns the control codes needed to set the length of a
page (in lines) when sent to EPSON or compatible printers. This is
normally either 66 or 72 lines. PRINT PAGLIN (lines)
 is the same as: PRINT CHR$(27)&'C'&CHR$(lines)

**CROSS-REFERENCE**

`PAGDIS <KeywordsP.clean.html#pagdis>`__, `PAGLEN <KeywordsP.clean.html#paglen>`__,
`LMAR <KeywordsL.clean.html#lmar>`__, `RMAR <KeywordsR.clean.html#rmar>`__.

--------------

PAINT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PAINT x, y, col, bufadr, buflen                                  |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

 The command PAINT addresses the screen directly and fills a closed
figure with the colour col (which must be in the range 0..4, see SET).
The command requires a buffer of at least 4K whose start address is
passed to PAINT as bufadr and whose length as buflen (which must be a
minimum of 4096 bytes). The larger the buffer, the better, but very
large buffers (say, 100K) seem to confuse PAINT and will make it stop
before it has finished - therefore keep the buffer below 32K.

**Example 1**

Random drawing: 100 WINDOW 512,256,0,0: BORDER 1,3: PAPER 0: CLS 110
buflen = 10240 120 : 130 FOR i = 1 TO 15 140 LDRAW RND(511),RND(255) TO
RND(511),RND(255), 3 150 END FOR i 160 : 170 buffer = ALCHP(buflen) 180
PAINT RND(1 TO 510), RND(1 TO 255), 2, buffer, buflen 190 RECHP buffer

**Example 2**

A spectacular crash(!): PAINT 50,50,4,131072,32768

**WARNING 1**

See those at SET.

**WARNING 2**

PAINT will crash the machine if it runs out of the screen, so you have
to ensure that the figure to be filled is closed. Another means of
protection is to use a BORDER, as in the example.

**CROSS-REFERENCE**

`FILL <KeywordsF.clean.html#fill>`__, `SET <KeywordsS.clean.html#set>`__,
`LDRAW <KeywordsL.clean.html#ldraw>`__

--------------

PALETTE\_QL
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  PALETTE\_QL [#ch,] start, true\_colour1 \*[,true\_colourx]\*     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

 This command allows you to redefine the eight colours used by the
Extended Colour Drivers to display COLOUR\_QL. A valid window channel
must be open, default #1 (or #0 on a SBASIC with only #0 open), although
one may also be supplied as #ch. start is the number of the first colour
to change, followed by each of the new colours described in 24 Bit
Colour Mode. On hardware with a true palette map (most PCs), this
command will affect all programs, including information already
displayed on screen. However, on all other hardware, most notably the
Q40 and Q60, existing information will remain unaffected.

**Example 1**

PALETTE\_QL 4,$FFB6DB makes the computer use PINK instead of GREEN when
INK 4 (QL Colour Value) is used within a program. PALETTE\_QL
5,$B6FFFF,$929200will change INK 5 to Light Blue (from Cyan) and INK 6
to Mustard (from Yellow).

**Example 2**

Many programs written with MODE 4 in mind, presume that INK 3
 is the same as INK 2 (for example). However, under COLOUR\_QL, even
MODE 4 programs can access the standard MODE 8 colours, therefore INK 3
becomes MAGENTA. To overcome this problem, use the following routine:
100 red=255\*65536+100:REMark $FF0064 - red and a bit of blue 110
blue=255\*256+155:REMark $00FF9B - green and the rest of blue 120
white=blue+red:REMark $FFFFFF 125 REMark - Now change all 8 colours,
starting at INK 0 130 PALETTE\_QL 0,0,0,red,red,blue,blue,white,white

**NOTE**

The problem with using 24 bit values is that they have to be trimmed to
fit into the native colour scheme on the computer in use - as a result,
although the same 24 bit colour value is specified, the resultant colour
will be slightly different on QPC, Q40 and Aurora.

**CROSS-REFERENCE**

`COLOUR\_QL <KeywordsC.clean.html#colour-ql>`__, `INK <KeywordsI.clean.html#ink>`__,
`PALETTE\_8 <KeywordsP.clean.html#palette-8>`__ Also refer to Appendix 16
which lists the first 256 24 Bit Colours.

--------------

PALETTE\_8
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PALETTE\_8 [#ch,] start, true\_colour1 \*[,true\_colourx]\*      |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

 This command is similar to PALETTE\_QL, except that it allows you to
redefine all 256 colours available under COLOUR\_PAL. As with
PALETTE\_QL, start is the number of the first colour to change, followed
by each of the new colours described in 24 Bit Colour Mode. A valid
window channel must also be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch. On hardware
with a true palette map (most PCs), this command will affect all
programs, including information already displayed on screen. However, on
all other hardware, most notably the Q40 and Q60, existing information
will remain unaffected.

**Examples**

PALETTE\_8 4,$FFB6DB makes the computer use PINK, instead of BLUE when
INK 4 (PAL Colour Value) is used within a program. PALETTE\_8
5,$B6FFFF$929200will change INK 5 to Light Blue (from Magenta) and INK 6
to Mustard (from Yellow).

**NOTE 1**

This command will not have any effect on Aurora, which only provides 256
colours to choose from. It may therefore not be implemented on the
Aurora version of SMSQ/E.

**NOTE 2**

The problem with using 24 bit values is that they have to be trimmed to
fit into the native colour scheme on the computer in use - as a result,
although the same 24 bit colour value is specified, the resultant colour
will be slightly different on QPC and Q40.

**CROSS-REFERENCE**

See `PALETTE\_QL <KeywordsP.clean.html#palette-ql>`__ and
`COLOUR\_PAL <KeywordsC.clean.html#colour-pal>`__ for more details.

--------------

PAN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  PAN [#ch,] distance [,area]                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This command is very similar to SCROLL except that this enables you to
move a window left and right as opposed to up and down. In its most
simple form, PAN allows you to move the specified window (default #1) a
given number of pixels sideways. If a positive value for the distance is
given, the window will move to the right, whereas a negative distance
will move the window to the left. Again, as with SCROLL, the gap left
behind from the move will be coloured in the current PAPER
 colour, and any contents of the window moved off the screen will be
lost. The additional parameter allowed by PAN lets you specify an area
of the given window to be moved. This can have one of the following
values:

areaEffect
~~~~~~~~~~

0This moves the whole window (this is the default). 3This moves the
whole of the text cursor line. 4This moves everything on the text cursor
line to the right of the cursor (including the character under the
cursor).

**Example**

A short procedure to scroll a given text message across the screen: 100
DEFine PROCedure SCROLL\_TEXT(line$) 110 LOCal l$,loop 120 l$=line$ 130
OPEN #3,scr\_448x10a32x246 140 PAPER#3,2:INK#3,0:CSIZE#3,1,0:CLS#3 150
AT #3,0,0:PRINT#3,'INCOMING MESSAGE:' 160 INK#3,7 170 REPeat loop 180 IF
LEN(l$)=0:EXIT loop 190 AT #3,0,55:PRINT#3,l$(1) 200 BEEP 100,10 210 IF
LEN(l$)<=1:EXIT loop 220 l$=l$(2 TO) 230 AT #3,0,18:PAN #3,-8,4 240
PAUSE 30 250 END REPeat loop 260 END DEFine

**NOTE 1**

In low-resolution mode (8 or 12), the distance will always be rounded
down to an even number of pixels.

**NOTE 2**

As with SCROLL, odd values for area and distance allow you to access
machine code routines (unless you have a THOR XVI, SMS, or Minerva ROM
(v1.63 or v1.64). To access these machine code routines, take the TRAP
#3 value for D0 and deduct 27. If the figure is less than 27, then take
the negative result and add to 128. For example, PAN 0,115 turns on
cursor in #1 (TRAP #3,D0=$E). This is in fact more useful than SCROLL or
CLS as area can be used to pass a parameter to D1, thus allowing you for
example, to access IOF.POSR - use PAN #3,n%,40 - to move the file
pointer.

**NOTE 3**

On pre MG ROMs, this command may fail if the window is smaller than the
cursor.

**NOTE 4**

On SMSQ/E pre v2.88, PAN in MODE 8 could ruin the screen display if an
odd parameter was specified, since SMSQ/E tried to move the screen by an
odd number of pixels (not supported in MODE 8). Although annoying, this
only had small effects.

**CROSS-REFERENCE**

Also please see `SCROLL <KeywordsS.clean.html#scroll>`__ and
`PAPER <KeywordsP.clean.html#paper>`__. THORs allow you to use
`IO\_TRAP <KeywordsI.clean.html#io-trap>`__ to access additional system calls.
Most system calls can be accessed using Toolkit II in any event.
Otherwise, see `BTRAP <KeywordsB.clean.html#btrap>`__,
`QTRAP <KeywordsQ.clean.html#qtrap>`__, `TTET3 <KeywordsT.clean.html#ttet3>`__ and
`MTRAP <KeywordsM.clean.html#mtrap>`__. The QDOS/SMS Reference Manual Section
15 contains full details of the TRAP #3 calls.

--------------

PAPER
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PAPER [#window,] colour  or PAPER [#window,] colour1,colour2 [,pattern] |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This command sets the background colour inside a window (default #1).
Characters printed to that window will be written with the PAPER colour
as a background unless another colour has been specified with STRIP.

**Example**

100 OPEN#3,scr\_512x256a0x0 110 REPeat forever 120 FOR c=0 TO 7 130
BORDER#3,RND(100) 140 PAPER#3,c 150 CLS#3 160 END FOR c 170 END REPeat
forever

**NOTE**

PAPER also resets the STRIP to the specified colour.

**CROSS-REFERENCE**

`INK <KeywordsI.clean.html#ink>`__ sets the foreground colour and
`STRIP <KeywordsS.clean.html#strip>`__ the background for characters only.
`CLS <KeywordsC.clean.html#cls>`__ clears a window in the current paper
colour. See `INK <KeywordsI.clean.html#ink>`__ concerning colour in general.

--------------

PARHASH
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARHASH (parameter)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

 This is an addition to the normal PARUSE and PARNAM$ functions which
allows you to check whether a value passed as a parameter to a
SuperBASIC PROCedure or FuNction was preceded by a hash or not.

**Example**

The following PROCedure allows you to create a CAT command which is
similar to DIR, allowing you to use the syntax: CAT #channel [,device]
or CAT [#channel,] [device] to read a directory. If device is not
specified, then a directory of the default data device is produced. If a
channel is not specified, then #1 will be used. The device can be in
quotes or not if you prefer. The following can therefore all be used:
CAT #2 CAT CAT flp1\_ CAT #3,'win1\_'
 100 DEFine PROCedure CAT (ch,direct) 110 LOCal dir\_ch,sepa%,hash% 112
hash%=PARHASH(ch): sepa%=PARSEPA(ch) 120 IF sepa%>0 130
file$=PARSTR$(direct,2) 140 ELSE 150 IF hash% 160 file$=DATAD$ 170 ELSE
180 file$=PARSTR$(ch,1):ch=1 185 IF file$='': file$=DATAD$ 187 END IF
190 END IF 200 dir\_ch=FOP\_DIR(file$) 210 IF dir\_ch<0: PRINT
#0,'CANNOT ACCESS DIRECTORY ON ';file$:RETurn 220 CLOSE #dir\_ch 230 DIR
#ch,file$ 250 END DEFine

**NOTE 1**

There is a problem with this function that prevents the above example
from working under SMS - once either PARHASH or PARSEPA have been used
once on a parameter, they will not work again!! For example, try adding
the following lines to the above and compare the results: 116 PRINT
PARHASH(ch), PARSEPA(direct), PARNAME$(2), PARTYP(ch), PARTYPE(direct)
117 PRINT PARHASH(ch), PARSEPA(direct), PARNAME$(2), PARTYP(ch),
PARTYPE(direct) 118 STOP

**NOTE 2**

TURBO and SuperCHARGE cannot compile programs which use PARHASH.

**CROSS-REFERENCE**

`PARTYP <KeywordsP.clean.html#partyp>`__\ E, `UNSET <KeywordsU.clean.html#unset>`__
and `PARNAME$ <KeywordsP.clean.html#parname>`__ are also added by this
toolkit.

--------------

PARNAM$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARNAM$ (number)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

 This function can be used to find the name of an actual parameter
passed to a SuperBASIC PROCedure or FuNction. You merely need to supply
the number of the parameter in the definition line which you wish to
find. If the parameter was passed as a name (ie. by reference), then
this name will be returned by PARNAM$, however, in all other cases, a
nul string will be returned.

**Example**

A short procedure which prints the square of the parameter passed (and
if possible squares the actual parameter!): 1000 DEFine PROCedure Square
(x) 1010 LOCal param$,loop,key$ 1020 param$=PARNAM$(1) 1030 IF
param$<>'' THEN 1040 PRINT #0,param$!'will be altered - is this okay?'
1050 REPeat loop:key$=INKEY$(-1):IF key$ INSTR 'yn':EXIT loop 1060 IF
key$=='n':RETurn 1070 END IF 1080 x=x^2:PRINT x 1090 END DEFine
 Compare the following: number=2:Square number(number is passed by
reference) and number=2:Square (number) (number is passed by value)

**NOTE**

TURBO and SuperCHARGE cannot compile programs which use PARNAM$.

**CROSS-REFERENCE**

`PARTYP <KeywordsP.clean.html#partyp>`__, `PARUSE <KeywordsP.clean.html#paruse>`__
and `PARSTR$ <KeywordsP.clean.html#parstr>`__ allow you to find out other
information about parameters. See also `DEFine
FuNction <KeywordsD.clean.html#define20function>`__ and `DEFine
PROCedure <KeywordsD.clean.html#define20procedure>`__.
`PARNAME$ <KeywordsP.clean.html#parname>`__ is exactly the same.

--------------

PARNAME$
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PARNAME$ (number)                                                |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

 This is exactly the same as PARNAM$.

**CROSS-REFERENCE**

`PARTYP <KeywordsP.clean.html#partyp>`__\ E,
`PARHASH <KeywordsP.clean.html#parhash>`__ and
`PARSEPA <KeywordsP.clean.html#parsepa>`__ are also added by this toolkit.

--------------

PARSEPA
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARSEPA (name)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

 This function is a useful addition that allows you to check on the type
of separator which follows a value passed as a parameter to a SuperBASIC
PROCedure or FuNction. The value returned by PARSEPA is:

PARSEPAmeaning
~~~~~~~~~~~~~~

0 No separator follows - this is the end of the line. 1 A comma (,)
follows 2 A semicolon (;) follows 3 A backslash (\\) follows 4An
exclamation mark (!) follows 5The word TO follows.

**NOTE**

This function suffers from the same problems as PARHASH.

**CROSS-REFERENCE**

See\ `PARHASH <KeywordsP.clean.html#parhash>`__ in particular - this contains
an example which uses this function.

--------------

PARSTR$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARSTR$ (name,number)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

 This function, together with its associated functions: PARTYP, PARUSE
and PARNAM$ allows you to find out information about a parameter passed
to a SuperBASIC PROCedure or FuNction. PARSTR$ is aimed for use in
PROCedures or FuNctions where a user might more naturally pass a
parameter as a name rather than a string (for example, when passing a
filename). Many users will have noted how many machine code procedures
and functions do not need filenames to be passed as a string, for
example: SAVE flp1\_boot
 and wondered why when they write a PROCedure, it has to be passed as a
string (for example, SSAVE 'flp1\_boot'). Well, PARSTR$
 allows you to do either!! The two parameters which need to be supplied
to PARSTR$ are the name of the parameter as listed in the definition
line and the number of that parameter in the parameter list.

**Example**

A re-write of a SAVE routine to keep the current file version up to date
(this could be used for example when developing a program): 100 DEFine
PROCedure SSAVE(file) 110 LOCal version 120 file$=PARSTR$(file,1) 130
version=FVERS(\\file$) 140 SAVE file$ 150 SET\_FVERS \\file$,version+1
160 END DEFine
 To update the saved version of the program in memory, you can then use
either SSAVE flp1\_program\_bas or SSAVE 'flp1\_program\_bas'. Note that
SMS users can just use SAVE (without a filename) to achieve this.

**NOTE 1**

If you try to assign the string returned by PARSTR$ back into the
original parameter (eg. change the variable file in the example program
to the variable file$), this will cause an 'error in expression'. You
could try adding file$ to the LOCal
 definition, however although this will avoid the 'error in expression',
file$ is set to a nul string by the LOCal
 definition!!

**NOTE 2**

TURBO and SuperCHARGE cannot compile programs which use PARSTR$.

**CROSS-REFERENCE**

Please also see `PARNAM$ <KeywordsP.clean.html#parnam>`__.
`FBKDT <KeywordsF.clean.html#fbkdt>`__ also contains a useful example of
`PARSTR$ <KeywordsP.clean.html#parstr>`__.

--------------

PARTYP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARTYP (name)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

 As disclosed in the description of DEFine FuNction, a parameter is
passed to a SuperBASIC PROCedure or FuNction by reference, meaning that
the variable type listed in the definition line will actually be
overriden by the type of variable which has been passed as a parameter.
The function PARTYP returns the type of the actual parameter which has
been passed, which can be used to error trap PROCedures and FuNctions.
PARTYP expects only one parameter - the name of the parameter from the
definition line to be looked at. PARTYP will then return one of the
following values depending on the type of the actual parameter passed:

PARTYPmeaning
~~~~~~~~~~~~~

0 a null string has been passed 1 a string has been passed 2 a floating
point has been passed 3 an integer has been passed

**Example**

A PROCedure to swap any two variables (it can only handle simple strings
and variables, not arrays): 100 a=1:b%=2 110 swap\_var a,b% 120 DEFine
PROCedure swap\_var (x,y) 130 LOCal xa,xa$,param 140 IF PARUSE(x)=0 OR
PARUSE(y)=0 150 PRINT 'A variable is unset!':RETurn 160 END IF 162 IF
PARNAM$(1)="" OR PARNAM$(2)="" 164 PRINT 'Parameters are not both
variables!':RETurn 165 END IF 170 IF PARUSE(x)=3 OR PARUSE(y)=3 180
PRINT 'Arrays not handled':RETurn 190 END IF 200 param=PARTYP(x) 210 IF
PARTYP(y)=1 AND param<>1 OR param=1 AND PARTYP(y)<>1 220 PRINT 'You
cannot swap a string with a value!' 230 RETurn 240 END IF 250 SELect ON
param 260 =0,1:xa$=y:y=x:x=xa$ 270 =2,3:xa=y:y=x:x=xa 280 END SELect 290
END DEFine

**NOTE 1**

There is a difference in the way that PARTYP will report an omitted
parameter, depending on whether you implicitly omit the parameter. Try
the following using the above example: Implicit omission: swap\_var a$
 or even swap\_var a$, - PARTYP(y) returns the type of the notional
parameter (here y is a floating point, so PARTYP (y) returns 2), and
PARUSE(y) also reports 2. Compare explicit omission: swap\_var ,a$
 PARTYP(x) will return 0 as will PARUSE(x)
 If a program is Qliberated, PARTYP will return 0 whether parameters are
implicitly or explicitly omitted.

**NOTE 2**

If you pass a null string as a parameter, eg. swap\_var a$,'' in the
above example, PARTYP will still return 1 (and not zero) as you may
think, hence the need to look at PARUSE also.

**NOTE 3**

TURBO and SuperCHARGE cannot compile programs which use PARUSE.

**CROSS-REFERENCE**

`PARTYP <KeywordsP.clean.html#partyp>`__ should be used alongside
`PARUSE <KeywordsP.clean.html#paruse>`__ to find out whether a parameter was
passed as a variable (ie. by reference) or as a value.
`PARTYPE <KeywordsP.clean.html#partype>`__ is the same.
`PARNAM$ <KeywordsP.clean.html#parnam>`__,
`PARHASH <KeywordsP.clean.html#parhash>`__,
`PARSEPA <KeywordsP.clean.html#parsepa>`__ and
`PARSTR$ <KeywordsP.clean.html#parstr>`__ form companions to these commands.

--------------

PARTYPE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARTYPE (name)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

 This function is exactly the same as PARTYP and suffers from the same
problems.

**CROSS-REFERENCE**

`PARHASH <KeywordsP.clean.html#parhash>`__, `UNSET <KeywordsU.clean.html#unset>`__
and `PARNAME$ <KeywordsP.clean.html#parname>`__ are also added by this
toolkit.

--------------

PARUSE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARUSE (name)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

 PARUSE is a companion function to PARTYP. PARUSE also expects only one
parameter - the name of the parameter from the definition line to be
looked at. PARUSE will then return one of the following values depending
on the actual parameter passed:

PARUSEmeaning
~~~~~~~~~~~~~

0 an unset variable has been passed 2 a variable (or value) has been
passed 3 an array has been passed

**NOTE 1**

The Toolkit II Manual gives incorrect values.

**NOTE 2**

There is a difference in the way that PARUSE will report an omitted
parameter, depending on whether you implicitly omit the parameter or
explicitly omit it - see Note 1 relating to PARTYP. Under current
versions of Qliberator a program, PARUSE will always return 2 whether
the parameter is implicitly or explicitly omitted.

**NOTE 3**

TURBO and SuperCHARGE cannot compile programs which use PARUSE.

**CROSS-REFERENCE**

Please see `PARTYP <KeywordsP.clean.html#partyp>`__.

--------------

PAR\_ABORT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_ABORT or PAR\_ABORT port\_number(SMSQ/E only)               |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 This command clears out all of the closed PAR buffers and then sends an
'aborted' message, to the PAR device, thus effectively stopping the
computer from sending any information still in the buffers through the
PAR device. Any open channels connected to the port are unaffected.

**NOTE**

Although the SMSQ/E implementation allows a port to be specified, there
are currently no implementations of the QL which have more than one
parallel port, therefore trying to pass a port\_number at present
results in a bad parameter error.

**CROSS-REFERENCE**

`SER\_ABORT <KeywordsS.clean.html#ser-abort>`__ and
`PRT\_ABORT <KeywordsP.clean.html#prt-abort>`__ are very similar.
`PAR\_CLEAR <KeywordsP.clean.html#par-clear>`__ clears out the buffers but
does not tell anyone. `PRT\_ABT <KeywordsP.clean.html#prt-abt>`__ is similar
on the Trump Card and Gold Cards.

--------------

PAR\_BUFF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_BUFF [size] or PAR\_BUFF port\_number, size(SMSQ/E only)    |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 Normally, SMSQ/E and the Emulator will use all available memory as a
buffer for its serial and parallel ports (this is known as a dynamic
buffer). Although this enables control to be returned to programs very
quickly after sending output to one of the ports, it can however mean
that the whole of the memory can be filled up with printer output. The
command PAR\_BUFF therefore allows you to specify a fixed size in bytes
for the parallel buffer for each channel opened to it. If no size is
specified, or a size of 0 bytes is set, then the parallel buffer becomes
dynamic once again. Otherwise, size
 should be at least 5 bytes to ensure future compatability.

**Example**

PAR\_BUFF 10000
 sets the parallel buffer to 10000 bytes.

**NOTE**

Although the SMSQ/E implementation allows a port to be specified, there
are currently no implementations of the QL which have more than one
parallel port, therefore trying to pass a port\_number at present
results in a bad parameter error.

**CROSS-REFERENCE**

`PRT\_USE <KeywordsP.clean.html#prt-use>`__ sets up a dynamic printer buffer
except under SMSQ/E.

--------------

PAR\_CLEAR
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_CLEAR  or PAR\_CLEAR port\_number(SMSQ/E only)              |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 This clears out all currently closed PAR buffers, thus preventing any
further output. Any channels which are open to the PAR port will be left
unaffected.

**NOTE**

Although the SMSQ/E implementation allows a port to be specified, there
are currently no implementations of the QL which have more than one
parallel port, therefore trying to pass a port\_number at present
results in a bad parameter error.

**CROSS-REFERENCE**

`SER\_CLEAR <KeywordsS.clean.html#ser-clear>`__ and
`PRT\_CLEAR <KeywordsP.clean.html#prt-clear>`__ are similar.

--------------

PAR\_PULSE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_PULSE x                                                     |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for the Atari                                      |
+----------+-------------------------------------------------------------------+

 Some accelerator boards enhance the speed of the Atari ST and TT
computers so much that the parallel printer port may be affected. This
can be fixed by using PAR\_PULSE to increase the rate of the strobe
pulse. This problem tends to be required if you have a printer which has
heavy drive requirements (notably a CANON) or if you use a long printer
cable.

**Example**

PAR\_PULSE 80

**NOTE**

On SMSQ/E running on non-Atari's, this command has no effect.

--------------

PAR\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_USE [device]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E, SuperQBoard, PAR/SER                              |
+----------+-------------------------------------------------------------------+

Interfaces, Super Gold Card
 As with many other devices, such as RAM, FLP and WIN, it can be useful
to alter the three letter description used to access the parallel
printer port on the Atari ST. The command PAR\_USE allows you to replace
the three letter description by any other three letters. If device is
not specified, this changes the description back to PAR.

**Example**

PAR\_USE ser
 will divert any attempt to access the serial ports to the parallel
printer port.

**CROSS-REFERENCE**

`RAM\_USE <KeywordsR.clean.html#ram-use>`__,
`FLP\_USE <KeywordsF.clean.html#flp-use>`__,
`WIN\_USE <KeywordsW.clean.html#win-use>`__,
`SER\_USE <KeywordsS.clean.html#ser-use>`__ and
`PRT\_USE <KeywordsP.clean.html#prt-use>`__ are all very similar.

--------------

PAUSE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PAUSE [timeout] or PAUSE [#chan,] [timeout](Minerva v1.80+, THORv6.41, SMS, ST/QL E-init v1.27+)  |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 The command PAUSE halts execution of a program temporarily for the
specified timeout number of frames (there are 50 frames per second in
the UK and Europe, 60 frames per second in the US). If no timeout or a
negative timeout is specified, the command will wait indefinitely. If a
timeout of zero is specified, no actual PAUSE will take place. Execution
will continue at the end of the timeout, or if a key is pressed. The key
is read from channel #0 and therefore the command will report the error
'channel not open' if #0 is not open. The second variant of this command
allows you to specify a channel #chan (default #0) upon which the
command should operate, thus allowing the command to be used in programs
which do not have #0 open.

**Example**

PAUSE 100
 Pauses for approximately 2 seconds, unless a key is pressed in the
meantime!

**NOTE 1**

Using timeouts allows programs to run at the same speed on all QL
implementations.

**NOTE 2**

Normally, if #0 or the specified channel (in the THOR variant of this
command) is not a console window (or not open), an error will be
generated, of either 'Bad Parameter' or 'Channel not open' respectively.
However, the Minerva and SMS variants of this command do not report any
error messages and merely return straight away (although see next note).

**NOTE 3**

On Minerva (v1.90+), the second variant of this command will also work
on a screen (scr\_) channel.

**NOTE 4**

The second variant didn't really work on ST/QL Emulators until v1.30 of
E-Init).

**CROSS-REFERENCE**

`INKEY$ <KeywordsI.clean.html#inkey>`__ allows you to read the key which has
been pressed, as well as halting program execution.

--------------

PEEK
====

--------------

PEEK\_W
~~~~~~~

--------------

PEEK\_L
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PEEK (address)address=0,1,2,3,...  and PEEK\_W (address)address=0,2,4,6,...  and PEEK\_L (address)address=0,2,4,6,...  |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 These three functions are complementary to POKE, POKE\_W and POKE\_L,
in that instead of setting a byte, word or longword in memory, these
three functions return the value of the byte, word or longword stored at
the given address.

**NOTE 1**

Due to the way in which values are stored in memory, it can be difficult
to read negative values. However, although PEEK
 will return an unsigned byte in the range 0..255, PEEK\_W will return a
signed word in the range -32768...32767 and PEEK\_L a signed longword.

**NOTE 2**

Do not try to PEEK\_W or PEEK\_L with an odd address (eg. 10001) as this
will cause an error unless you are using Minerva (see below).

**MINERVA NOTES**

As with the POKE commands, the PEEK functions on Minerva (version 1.77
or later) are very much enhanced and different. Minerva allows you to
use PEEK\_W and PEEK\_L on odd addresses, eg: PRINT PEEK\_W(131073)
 Minerva has also added to the usefulness of the PEEK, PEEK\_W
 and PEEK\_L functions by allowing them to access system variables,
Minerva's System Xtensions and SuperBASIC variables. You will need a
good book on QDOS (eg. QDOS/SMS Reference Manual) to find out what the
possible values are. The syntax for these extra commands is:

(1) Look at SuperBASIC variables.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PEEK (\\\\SBvar) PEEK\_W (\\\\SBvar) PEEK\_L (\\\\SBvar) PEEK
(\\SBvar\\Offset) PEEK\_W (\\SBvar\\Offset) PEEK\_L (\\SBvar\\Offset)

(2) Look at System variables.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PEEK (!!Sysvar) PEEK\_W (!!Sysvar) PEEK\_L (!!Sysvar) PEEK
(!Sysvar!Offset) PEEK\_W (!Sysvar!Offset) PEEK\_L (!Sysvar!Offset)

(3) Look at System Xtensions.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

sx\_base=PEEK\_L(VER$(-2) + 124) PEEK (sx\_base + offset)

**SMS NOTES**

SMS has altered the PEEK functions so that they are able to access
System variables and SuperBASIC variables, using the same format as
Minerva.

**CROSS-REFERENCE**

Please see in particular `POKE <KeywordsP.clean.html#poke>`__,
`POKE\_W <KeywordsP.clean.html#poke-w>`__, and
`POKE\_L <KeywordsP.clean.html#poke-l>`__. `PEEK$ <KeywordsP.clean.html#peek>`__
reads a string stored in memory and contains some examples of the new
variants introduced on Minerva and SMS.
`PEEK\_F <KeywordsP.clean.html#peek-f>`__ and `PEEKS <KeywordsP.clean.html#peeks>`__
are also worth a look.

--------------

PEEKS
=====

--------------

PEEKS\_W
~~~~~~~~

--------------

PEEKS\_L
~~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  PEEKS(address) address=0,1,2,3,...  and PEEKS\_W(address) address=0,2,4,6,...  and PEEKS\_L(address) address=0,2,4,6,...  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E and ATARI\_REXT v2.17+                                    |
+----------+-------------------------------------------------------------------+

 These three functions are only of any use on the Atari series of
computers. They are the same as the normal forms of PEEK, PEEK\_W and
PEEK\_L, except that they operate in Supervisor Mode and can therefore
be used to read data direct from the Atari's IO hardware. On all other
implementations they are the same as PEEK, PEEK\_W and PEEK\_L.

**CROSS-REFERENCE**

See `PEEK <KeywordsP.clean.html#peek>`__. `POKES <KeywordsP.clean.html#pokes>`__ is
the complementary command. See `PROT\_MEM <KeywordsP.clean.html#prot-mem>`__
also.

--------------

PEEK$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEEK$ (start\_address,bytes)  or PEEK$ (start\_address [,bytes])(BTool only)  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT, SMS, TinyToolkit, BTool                             |
+----------+-------------------------------------------------------------------+

 This function will read a specified number of bytes from start\_address
in memory onwards and return the result as a string. For BTool the
second parameter is optional. If bytes is not specified then BTool's
PEEK$ will try to read a string in QDOS format (ie. two bytes specifying
the length of the string followed by the string itself) from the
location start\_address, just like CVS$ does. This string will then be
returned. Note that start\_address must always be if bytes is omitted.

**Example**

Do you know how many keywords, filenames, variables etc. are currently
known to the interpreter? This program lists and counts them. 100
adr=BASICP(32): num=0 110 REPeat all\_names 120 length=PEEK(adr) 130 IF
NOT length THEN EXIT all\_names 140 name$=PEEK$(adr+1,length) 150 PRINT
name$, 160 adr=adr+length+1: num=num+1 170 END REPeat all\_names 180
PRINT\\\\num!"names"

**SMS NOTE**

PEEK$ allows you to access the System Variables and SuperBASIC variables
in the same way as PEEK (etc.). For example, the above short program may
be re-written as: 100 adr=0: num=0 110 REPeat all\_names 120
length=PEEK(\\$20\\adr) 130 IF NOT length THEN EXIT all\_names 140
name$=PEEK$(\\$20\\adr+1,length) 150 PRINT name$,:PAUSE 160
adr=adr+length+1: num=num+1 170 END REPeat all\_names 180
PRINT\\\\num!"names"

**WARNING**

A string cannot be longer than 32766 characters and so an expression
such as a$=PEEK$(0,40000) may lead to unpredictable effects. Be careful!

**CROSS-REFERENCE**

`POKE$ <KeywordsP.clean.html#poke>`__ is the complementary procedure to
`PEEK$ <KeywordsP.clean.html#peek>`__. `PEEK <KeywordsP.clean.html#peek>`__,
`PEEK\_W <KeywordsP.clean.html#peek-w>`__ and
`PEEK\_L <KeywordsP.clean.html#peek-l>`__ read single bytes, words and long
words from memory. `TTPEEK$ <KeywordsT.clean.html#ttpeek>`__ is the same as
this function.

--------------

PEEK\_F
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PEEK\_F (address)                                                |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

 PEEK\_F is a function which reads six bytes from any position in
memory, which it assumes is the internal representation of a SuperBASIC
floating point number, and returns its value.

**WARNING**

PEEK\_F will lead to a crash if the six bytes at address did not
represent a valid floating point, compare this with CVF.

**CROSS-REFERENCE**

`POKE\_F <KeywordsP.clean.html#poke-f>`__, `CVF <KeywordsC.clean.html#cvf>`__,
`MKF$ <KeywordsM.clean.html#mkf>`__ See also `PEEK$ <KeywordsP.clean.html#peek>`__

--------------

PEND
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEND (#channel)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

 PEND is a logical function and returns 1 if there is data waiting in
the specified channel to be read and 0 if not.

**Example 1**

If the Window Manager is present, PEND can be used to check if a window
is currently hidden, and therefore to decide whether information should
be printed to that channel or not. Under the Pointer Environment, jobs
which are trying to output data to a window channel cannot do so until
the channel is activated (eg. by pressing <CTRL><C>). - The following
program calculates a large sum and prints the current value of the
calculation in a small window, however, the calculation itself will not
stop if one switches to another window, thus hiding this one. 100
n=1546: sum=0 110 OPEN#3,"con\_"&(6\*LEN(n)+6)&"x12a0x0" 120
BORDER#3,1,3: INK#3,7: CLS#3 130 FOR i=1 TO n 140 sum=sum+i 150 IF
PEND(#3) THEN PRINT#3;FILL$(" ",4-LEN(i));i 160 END FOR i 170 IF
sum<>n\*(n+1)/2 THEN BEEP 0,33,44,66,22,44 180 CLOSE#3

**Example 2**

Pipes should be used for communication between jobs. It is very bad
practice to write information to a file and let the other job read it
because other tasks may be affected. Here are two programs which have to
be compiled and executed to multitask. Both open a small window, the
first job inputs text and then sends it to the second job which shows
that text. Typing "end" will terminate both jobs. The output job would
work without PEND but would not be able to do something else whilst
waiting for further input. 100 REMark Input Job 110 : 120
OPEN#3,con\_50x30a30x40: PAPER#3,3 130 INK#3,7: BORDER#3,1,4: CLS#3 140
OPEN#4,pipe\_communication\_200 150 REPeat input\_loop 160 INPUT#3,text$
170 PRINT#4,text$ 180 IF text$=="END" THEN EXIT input\_loop 190 END
REPeat input\_loop 200 CLOSE#3: CLOSE#4

100 REMark Output Job 110 : 120 OPEN#3,scr\_50x30a100x40: PAPER#3,3 130
INK#3,7: BORDER#3,1,4: CLS#3 140 OPEN#4,pipe\_communication 150 REPeat
output\_loop 160 IF PEND(#4) THEN 170 INPUT#4,text$ 180 IF text$=="END"
THEN EXIT output\_loop 190 PRINT#3,text$ 200 END IF 210 IF NOT RND(200):
d$=DATE$: PRINT#3,d$(16 TO) 220 END REPeat output\_loop 230 CLOSE#3:
CLOSE#4
 By the way, in this case it is not very efficient to separate the input
and output jobs, but good terminal Emulators do this. You will also
notice that the programs use named pipes which make it much easier for
them to link up with each other. These named pipes are present in the
latest version of the ST/QL Emulator as well as SMS. They are also
provided by several public domain device drivers - See the appendix on
devices for further details.

**NOTE**

PEND only works with channels which will accept input (not scr\_) and
reports an "end of file" error (ERNUM=-10, ERR\_EF=1) if a connected
output pipe has been closed. Unfortunately, EOF cannot be used to trap
the end of a named pipe early enough, so you have to ensure that the
output pipe tells the accompanying input pipe that it is about to be
closed.

**CROSS-REFERENCE**

See `TCONNECT <KeywordsT.clean.html#tconnect>`__ and
`FILE\_OPEN <KeywordsF.clean.html#file-open>`__ about connecting two unnamed
pipes. `EOF <KeywordsE.clean.html#eof>`__ checks if a file is at its end.
`IO\_PEND% <KeywordsI.clean.html#io-pend>`__ and `NOT
EOFW <KeywordsN.clean.html#not20eofw>`__ are identical to
`PEND <KeywordsP.clean.html#pend>`__.

--------------

PENDOWN
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PENDOWN [#ch]                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This command is part of the QL's turtle graphics set of commands, and
places the pen to the down position in the specified window (default
#1). When a window is first opened, the pen is set to the up position.

**CROSS-REFERENCE**

`PENUP <KeywordsP.clean.html#penup>`__ has the opposite effect to this
command. Also see `MOVE <KeywordsM.clean.html#move>`__.

--------------

PENUP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PENUP [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This command places the turtle's pen to the up position in the
specified window (default #1), thus preventing any further drawing.

**CROSS-REFERENCE**

See `PENDOWN <KeywordsP.clean.html#pendown>`__ and
`MOVE <KeywordsM.clean.html#move>`__ for more details.

--------------

PEOFF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEOFF [{ #ch \| chan\_ID \| job\_name$ }]                        |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This command is similar to PIE\_OFF except that it allows you to
disable background screen access for specific multitasking jobs if you
wish (reverting to the original Pointer Environment method of managing
windows). The same parameters as for PEON can be used to specify the
Jobs or windows to be affected.

**NOTE**

PEX should not be used with PIE.

**CROSS-REFERENCE**

Refer to `PEON <KeywordsP.clean.html#peon>`__.

--------------

PEON
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEON [{ #ch \| chan\_ID \| job\_name$ }]                         |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 PEX is similar to the PIE system extension (see PIE\_ON for more
details), in that it allows buried programs to access the screen in the
background. However, PEX cannot be used with PIE and is completely
independent. PEX should be loaded after the Pointer Environment (notably
the PTR\_GEN file), and after any other code which redefines the window
handling of the QL (for example Lightning or Speedscreen). It must
however be loaded before the History device (except on SMSQ/E which has
a built in History device). People who use PEX or PIE may like to also
use another utility PICE which updates the QL screen at pre-defined time
intervals so that any part of a window which is not buried will actually
appear on screen (whether or not part of that window is buried). If you
wish to use PICE, it is recommended to set the PICE job to a priority of
1 so as not to slow the system down too much. The PEON command allows
you to select which windows and Jobs should allow background screen
access - this is important since the more programs which continue to run
in the background, the slower your QL will appear!! If no parameter is
specified, then background screen access is enabled for all Jobs. You
can however pass any number of parameters, which can be: 1) A SuperBASIC
channel number for the current program 2) A QDOS channel number (see
CHANNELS) in which case PEX will only affect that specific channel 3)
The name of a Job (passed as a string - use a null string ("") for
SuperBASIC). PEX will affect all windows used by that specified Job.

**NOTE 1**

PEX will not work on pre-JS ROMs. On JS and MG ROMs, its functionality
is reduced in that it can only be used to allow a few machine code calls
which do not access the screen to operate notwithstanding that the
Pointer Environment would normally stop them from working from within a
buried program (it is equivalent to: FOR i=0 TO 127:x=IS\_PTRAP(i,3)

**NOTE 2**

Some toolkits report errors when used alongside PEX and some Qliberated
programs refuse to work.

**CROSS-REFERENCE**

See `PEOFF, PIE\_ON <KeywordsP.clean.html#peoff,20pie-on>`__,
`PXON <KeywordsP.clean.html#pxon>`__, `PEX\_INI <KeywordsP.clean.html#pex-ini>`__
and `IS\_PEON <KeywordsI.clean.html#is-peon>`__ for more
details.\ `IS\_PTRAP <KeywordsI.clean.html#is-ptrap>`__ allows you to enable
PEX for specific machine code routines.

--------------

PEX$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEX$                                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This function returns the date of assembly, version and sub-version of
the PEX file.

**CROSS-REFERENCE**

`PEX\_SAVE <KeywordsP.clean.html#pex-save>`__ alters the sub-version number.
See also `QL\_PEX <KeywordsQ.clean.html#ql-pex>`__ and
`PIF$ <KeywordsP.clean.html#pif>`__.

--------------

PEX\_INI
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PEX\_INI                                                         |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This command initiates PEX and makes it take effect - it may be useful
for example to set up the various programs and the windowing
environment, using PEON and IS\_PTRAP and then to start PEX working at
that stage, by using this command.

**NOTE**

Some toolkits report errors when used alongside PEX and some Qliberated
programs refuse to work.

**CROSS-REFERENCE**

See `PEON <KeywordsP.clean.html#peon>`__ for more general details. You should
also see `PEX\_XTD <KeywordsP.clean.html#pex-xtd>`__ and
`PX1ST <KeywordsP.clean.html#px1st>`__.

--------------

PEX\_SAVE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PEX\_SAVE directory$                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This command stores the current settings of PEX in a file called
PEX19\_byt (for version 19.30) in the specified directory
 so that when you next load PEX (with LBYTES directory$&PEX\_19\_byt for
example), you will not have to re-set all of the various settings. The
sub-version number of PEX is increased by one.

**Example**

PEX\_SAVE 'win1\_start\_'
 will create the file win1\_start\_PEX19\_byt

**NOTE**

An underscore must appear at the end of directory$.

**CROSS-REFERENCE**

See `PEON <KeywordsP.clean.html#peon>`__ for more general details. The
settings which are saved are set with the command
`IS\_PTRAP <KeywordsI.clean.html#is-ptrap>`__ and
`IS\_PX1ST <KeywordsI.clean.html#is-px1st>`__. `PEX$ <KeywordsP.clean.html#pex>`__
returns the sub-version number.

--------------

PEX\_XTD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PEX\_XTD                                                         |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This command re-installs the keywords provided as part of PEX and can
help overcome the problem of other toolkits re- defining PEX keywords.

**CROSS-REFERENCE**

See `PEON <KeywordsP.clean.html#peon>`__ for more general details. You should
also see `PEX\_INI <KeywordsP.clean.html#pex-ini>`__ and
`PX1ST <KeywordsP.clean.html#px1st>`__.

--------------

PHONEM
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PHONEM (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  �hnlichkeiten                                                  |
+----------+-------------------------------------------------------------------+

 This function returns a string (even though the name does not end with
$) which is a (more germanic) phonetical transcription of the supplied
string. If two words sound similar or are even homophones, their
PHONEM's are identical. The function is not case-sensitive.

**Examples**

PHONEM ("Toolkit")="DOLCYD" PHONEM ("DoolGid")="DOLCYD" PHONEM
("DOLGYD")="DOLCYD"

**NOTE**

An expression such as: PRINT PHONEM (a$) INSTR PHONEM (b$)
 will always return 0 on pre Minerva ROMs. Use temporary variables to
get around this problem: t1$=PHONEM(a$) : t2$=PHONEM(b$)
 PRINT t1$ INSTR t2$
 will work properly.

**CROSS-REFERENCE**

`SOUNDEX <KeywordsS.clean.html#soundex>`__, `WLD <KeywordsW.clean.html#wld>`__.

--------------

PI
==

+----------+-------------------------------------------------------------------+
| Syntax   |  PI                                                               |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This function is a constant number which returns the value of � with an
error of 10^(-29). You can test the precision of PI with such a program:
100 p=PI-3: PRINT "PI=3."; 110 FOR n=1 TO 35 120 p=p\*10 130 PRINT
INT(p); 140 p=p-INT(p) 150 END FOR n 160 PRINT

**CROSS-REFERENCE**

The trigonometrical functions (`SIN <KeywordsS.clean.html#sin>`__,
`TAN <KeywordsT.clean.html#tan>`__, `ACOS <KeywordsA.clean.html#acos>`__ etc) expect
parameters in radians, so `PI <KeywordsP.clean.html#pi>`__ must be used in
most cases. Another fundamental mathematical constant, e, can be
obtained with `EXP(1) <KeywordsE.clean.html#exp(1)>`__.

--------------

PICK$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PICK$ (n, slct\ :sup:`1`\ $ :sup:`\*`\ [,slct\ :sup:`i`\ $]\ :sup:`\*`\ )  |
+----------+-------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                      |
+----------+-------------------------------------------------------------------+

 The function PICK$ takes one positive integer n and one or more other
parameters slct1$, slct2$, etc. The function returns the value of the
nth parameter, so n must be smaller than or equal to the number of
supplied slctx$. Don't forget, n must be greater than zero!

**Example**

PICK$ is intended to simplify expressions, here are some silly examples:
100 bool%=RND (0 TO 1) 110 IF bool% THEN PRINT "yes": ELSE PRINT "no"
 becomes 100 bool%=RND (0 TO 1) 110 PRINT PICK$ (bool%+1,"no","yes")
 whereas 100 members = RND (4) 110 PRINT "The team has "; 120 IF
members>0: PRINT members;: ELSE PRINT "no"; 130 PRINT " member"; 140 IF
members<>1 THEN PRINT "s": ELSE PRINT
 becomes 100 members = RND(4) 110 PRINT "The team has "; 120 PRINT PICK$
(1+(members<>0),"no",members); 130 PRINT " member";PICK$
(1+(members<>1),"","s")
 The slightly more complex: 100 DIM num$ (9,5) 110 RESTORE : FOR i=0 TO
9: READ num$(i) 120 DATA "zero","one","two","three","four" 130 DATA
"five","six","seven","eight","nine","ten" 140 : 150 REPeat typing 160
key = CODE (INKEY$ (-1))-48 170 IF key<0 OR key>9 THEN EXIT typing 180
PRINT num$ (key)!! 190 END REPeat typing
 becomes 100 REPeat typing 110 key = CODE (INKEY$(-1))-48 120 IF key<0
OR key>9 THEN EXIT typing 130 PRINT PICK$
(key+1,"zero","one","two","three","four","five","six","seven","eight",
"nine", "ten") 140 END REPeat typing

**CROSS-REFERENCE**

Note that conditions have a numeric value, see
`IF <KeywordsI.clean.html#if>`__, `AND <KeywordsA.clean.html#and>`__ and
`OR <KeywordsO.clean.html#or>`__ for details. `SELect ON..END
SELect <KeywordsS.clean.html#select20on..end20select>`__ is a less
restrictive alternative to `PICK$ <KeywordsP.clean.html#pick>`__.

--------------

PICK%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PICK% [(JobID] or PICK% (JobID, action)                          |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This function can be used to perform various acts. The first syntax is
the more common and will bring the specified Job (by reference to its
QDOS Job id or its Job Number as specified by JOBS) to the top of the
pile under the Pointer Environment, making all of its windows appear on
screen as if it had been Picked from the Qpac 2 file menu. If JobID is
-1 or omitted, then the Job which contains this command is brought to
the top of the pile. This variant is therefore similar to TOP\_WINDOW.
If JobID is -2, then the next Job in the Job Table (see NXJOB) is
brought to the top of the pile - this is therefore similar to pressing
<CTRL><C>. The second variant is more complex and depends upon the
values of JobID and action. (1) If JobID refers to an existing Job and
action is -4, then the screen is frozen - this is equivalent to pressing
<CTRL><F5>. (2) If JobID equals -3 and action is an existing QDOS
channel number (see CHANNELS) or SuperBASIC channel number then that
particular channel is unfrozen, allowing input from / output to that
channel provided that the Job which owns that channel is at the top of
the pile or can use background screen access under PEX. (3) If JobID
equals -4 and action is an existing QDOS channel number (see CHANNELS)
or SuperBASIC channel number then that particular channel is frozen
again and any attempt by a program to access that channel will (unless
that program is not buried) cause that program to halt temporarily. The
values returned by PICK% are normally zero if the function is
successful. Otherwise errors are returned as follows: -1 : Job is In Use
(although we are not certain when this will be reported). -2 : Job does
not exist -6 : Specified QDOS channel number does not exist

**CROSS-REFERENCE**

`OJOB <KeywordsO.clean.html#ojob>`__ and `NXJOB <KeywordsN.clean.html#nxjob>`__
allow you to find out details about a specified Job.
`PEON <KeywordsP.clean.html#peon>`__ allows background screen access.

--------------

PIE\_EX\_OFF
~~~~~~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  PIE\_EX\_OFF                                                     |
+----------+-------------------------------------------------------------------+
| Location |  PIE                                                              |
+----------+-------------------------------------------------------------------+

 PIE\_ON contains details about what PIE is used for and you should
first of all refer to that. Presuming that PIE is enabled (with
PIE\_ON), you may want to treat any programs (or toolkits) which use
SD.EXTOP machine code calls to access the screen differently. Normally,
the Window Manager halts any program which attempts to call the SD.EXTOP
machine code routine unless that program does not have any buried
windows. However, PIE\_ON allows all buried programs to continue in the
background, storing the changes to the screen as necessary. However,
SD.EXTOP routines may be used for various purposes including writing to
the screen directly and for this reason, if PIE is active, you may find
that a program writes to the screen using SD.EXTOP even though its
windows are buried (thus overwriting part of an existing program's
display). PIE\_EX\_OFF prevents this effect by still halting any program
which attempts to use SD.EXTOP.

**CROSS-REFERENCE**

See `PIE\_ON <KeywordsP.clean.html#pie-on>`__ and
`PIE\_EX\_ON <KeywordsP.clean.html#pie-ex-on>`__. See also
`PXOFF <KeywordsP.clean.html#pxoff>`__ which is similar.

--------------

PIE\_EX\_ON
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  PIE\_EX\_ON                                                      |
+----------+-------------------------------------------------------------------+
| Location |  PIE                                                              |
+----------+-------------------------------------------------------------------+

 This command re-enables PIE for SD.EXTOP system calls, so that they are
affected by the normal PIE\_ON and PIE\_OFF commands.

**CROSS-REFERENCE**

See `PIE\_ON <KeywordsP.clean.html#pie-on>`__.

--------------

PIE\_OFF
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PIE\_OFF                                                         |
+----------+-------------------------------------------------------------------+
| Location |  PIE                                                              |
+----------+-------------------------------------------------------------------+

 See PIE\_ON below.

--------------

PIE\_ON
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PIE\_ON                                                          |
+----------+-------------------------------------------------------------------+
| Location |  PIE                                                              |
+----------+-------------------------------------------------------------------+

 The Window Manager forms part of the Pointer Environment and is a
standard system extension: it allows you to multitask all kinds of
programs easily, provides non-destructible windows and more. One of the
main problems with current versions of the Window Manager is that if any
part of the windows owned by a given Job is buried under another Job's
windows (ie. you cannot see that part of the window on-screen because of
another program), then if that buried Job tries to access the screen
(with PRINT for example), the Window Manager will pause that Job until
its window is no longer buried. The Pointer Interface Extension (PIE)
modifies the Pointer Environment so that a program is not halted when it
tries to send screen output while its window is fully or partially
buried by another job. It does this by storing the changes to the buried
window in memory and then when the buried Job is brought to the top of
the pile (see PICK%), then its window is updated. PIE\_ON enables PIE,
PIE\_OFF disables it. These commands on their own cannot lead to any
problems, you can switch PIE on and off whenever you like.

**CROSS-REFERENCE**

`PIE\_EX\_ON <KeywordsP.clean.html#pie-ex-on>`__ and
`PIE\_EX\_OFF <KeywordsP.clean.html#pie-ex-off>`__. See also
`PEON <KeywordsP.clean.html#peon>`__ and `PXON <KeywordsP.clean.html#pxon>`__ which
greatly enhance these facilities. `PEND <KeywordsP.clean.html#pend>`__ can be
used to check if a Job can send output to the screen.

--------------

PIF$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PIF$                                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This is the same as QRAM$!

--------------

PINF$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PINF$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

 This is the same as QRAM$ and PIF$!

--------------

PIXEL%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PIXEL% ( [#ch,] x1,y1 )                                          |
+----------+-------------------------------------------------------------------+
| Location |  PIXEL (DIY Toolkit - Vol G)                                      |
+----------+-------------------------------------------------------------------+

 This function can be used to read the colour of a point in absolute
co-ordinates on the screen with reference to the specified window
channel (if any - default #1). This function will work in MODE 4, 8 and
12 (on the THOR XVI, if you have v0.9+). The main limitation on this
function is that the point must appear within the specified window, so
x1 and y1 cannot exceed the width or height of the specified window (in
pixels), or be less than zero.

**NOTE**

Although PIXEL% will work wherever the screen base is located, prior to
v1.0, it assumed that a line of pixels takes 128 bytes - early versions
will not therefore work on higher resolutions.

**CROSS-REFERENCE**

`PLOT <KeywordsP.clean.html#plot>`__ and `DRAW <KeywordsD.clean.html#draw>`__ allow
you to draw points and lines on the screen. `INK <KeywordsI.clean.html#ink>`__
gives details about the various colour values which may be returned
(this will be in the range 0...16).

--------------

PJOB
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PJOB (job\_ID)  or PJOB (jobnr,tag)  or PJOB (jobname)           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

 Each job has a priority - the function PJOB finds it and returns 0 if
the given job does not exist, otherwise it returns the priority of the
specified job. You can calculate the job\_ID with the formula
job\_id=jobnr+tag\*2^16, a negative job\_ID
 (preferably -1) identifies the job calling PJOB. The higher the
priority, the more working time a job draws from the processor, and
therefore the faster the execution.

**Example**

The priority of the main SuperBASIC interpreter can be seen with: PRINT
PJOB(0).

**MINERVA NOTE**

The maximum priority for a job on a standard QL is 255, however, on a
Minerva ROM, the acceptable priority range is altered to -128...127. If
PJOB returns a value over 127, then deduct the difference between this
and 256 from zero to get the priority on a Minerva machine - see SPJOB
for further details.

**CROSS-REFERENCE**

`JOB$ <KeywordsJ.clean.html#job>`__, `OJOB <KeywordsO.clean.html#ojob>`__ and
`NXJOB <KeywordsN.clean.html#nxjob>`__ return other information about a job.

--------------

PLAY
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PLAY nr, music$                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, QSound                                                    |
+----------+-------------------------------------------------------------------+

 The command PLAY will store the sequence music$ under the sequence
number nr. The sequences are numbered 1, 2, 3, etc. No details are
available for the limits of nr and the structure of music$.

**CROSS-REFERENCE**

`RELEASE nr <KeywordsR.clean.html#release20nr>`__ plays a sequence.
`SND\_EXT <KeywordsS.clean.html#snd-ext>`__.

--------------

PLOT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PLOT x,y,colour                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

 This command forces a pixel to be set at the absolute screen position
x,y. The origin (0,0) is the upper left corner of the full QL screen,
the opposite corner (diagonally) is (511,255). Two neighbouring points
do not have any space between them. Co-ordinates greater than 511 (x) or
255 (y) or smaller than 0 are modulated (eg. x MOD 511). The base
address of the screen used by PLOT is defined with SCRBASE. PLOT works
in MODE 4 only.

**Example**

The following procedure plots a point given in polar co-ordinates. A
simple approach to draw a line in a polar system is listed at DRAW. A
sensible range for the radius is 0<=r<=127. 100 DEFine PROCedure
POLAR\_PLOT (r,phi,col) 110 LOCal x,y 120 x=1.35\*r\*SIN(phi+PI/2)+255
130 y=r\*COS(phi+PI/2)+127 140 PLOT x,y,col 150 END DEFine POLAR\_PLOT

**NOTE 1**

PLOT writes directly into screen memory and will work on 512x256
resolutions only, it assumes by default that the screen starts at $20000
(redefine with SCRBASE) and works in MODE 4
 only.

**NOTE 2**

Minerva users can SCRBASE SCREEN(#3) to allow PLOT to draw on the screen
on which channel #3 is located.

**CROSS-REFERENCE**

`DRAW <KeywordsD.clean.html#draw>`__ draws a line,
`SCLR <KeywordsS.clean.html#sclr>`__ clears the screen, and
`REFRESH <KeywordsR.clean.html#refresh>`__ makes the screen defined by
`SCRBASE <KeywordsS.clean.html#scrbase>`__ visible. Compare the other
implementation of `PLOT <KeywordsP.clean.html#plot>`__.

--------------

PLOT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PLOT [#ch,] x1,y1                                                |
+----------+-------------------------------------------------------------------+
| Location |  DRAW (DIY Toolkit - Vol G)                                       |
+----------+-------------------------------------------------------------------+

 This command plots a point in absolute co-ordinates on the screen with
reference to the specified window channel (if any - default #1). This is
also used to specify the start point of a line to be drawn with the DRAW
command from the same toolkit. This is quicker than using the SuperBASIC
POINT command and unlike other similar commands, it will support the
current INK
 colour and OVER mode. <CTRL><F5> will pause the point drawing and it
will even work in MODE 4, 8 and 12 (on the THOR XVI, if you have v1.6+).
The main limitation on this command is that the point must appear within
the specified window, so x1 and y1 cannot exceed the width or height of
the specified window (in pixels), or be less than zero.

**NOTE**

Although PLOT will work wherever the screen base is located, it assumes
that a line of pixels takes 128 bytes - it will not therefore work on
higher resolutions.

**CROSS-REFERENCE**

See the other variant of\ `PLOT <KeywordsP.clean.html#plot>`__. See also
`DRAW <KeywordsD.clean.html#draw>`__. Compare
`POINT <KeywordsP.clean.html#point>`__.

--------------

POINT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  POINT [#ch,] x,y :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`]\ :sup:`\* ` |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM, GPOINT                                                   |
+----------+-------------------------------------------------------------------+

 This command draws one or more specified points in the given window
(default #1). The co-ordinates are floating point numbers, which means
that two POINTs drawn with: POINT 20,20: POINT 21,20
 (or POINT 20,20;21,20) for example, are not normally neighbours. If a
point lies outside a window, it is simply not drawn, ie. overflow errors
do not occur. The graphics cursor is updated to the last point to be
plotted.

**Examples**

POINT 50,50 POINT 50,50;60,60 POINT#2,20,50 POINT
#2,20,50;50,20;20,20;50,50

**NOTE**

On MGx ROMs, there is a well-known POINT bug which makes POINT draw two
points instead of one. This is fixed by some versions of Toolkit II, the
ST/QL Emulator, SMS, Gold Card, other ROMs (especially Minerva) and
small patches like GPOINT. GPOINT includes two commands: a replacement
POINT and GPOINT
 which is just another name for the same thing.

**CROSS-REFERENCE**

The relation between the supplied co-ordinates and their position in the
window is defined with `SCALE <KeywordsS.clean.html#scale>`__. The colour of
the point(s) is set with `INK <KeywordsI.clean.html#ink>`__. The window can be
resized with `WINDOW <KeywordsW.clean.html#window>`__.
`LINE <KeywordsL.clean.html#line>`__ draws a line. The
`GPOINT <KeywordsG.clean.html#gpoint>`__ command is fully identical to
`POINT <KeywordsP.clean.html#point>`__ except that it fixes the MGx ROM bug.
Check the ROM version with `VER$ <KeywordsV.clean.html#ver>`__.

--------------

POINT\_R
========

+----------+-------------------------------------------------------------------+
| Syntax   |  POINT\_R [#ch,] x,y :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`]\ :sup:`\* ` |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This command is similar to POINT except that all co-ordinates given are
relative to the current graphics pointer.

**CROSS-REFERENCE**

See `POINT <KeywordsP.clean.html#point>`__! Also see
`LINE\_R <KeywordsL.clean.html#line-r>`__ and
`CIRCLE\_R <KeywordsC.clean.html#circle-r>`__.

--------------

POKE
====

--------------

POKE\_W
~~~~~~~

--------------

POKE\_L
~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  POKE address,valueaddress=0,1,2,3,...value=0..255  or POKE address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ (Minerva and SMS only)  or POKE address, {value\ :sup:`1` \| value\ :sup:`1`\ $} :sup:`\*`\ {,value\ :sup:`i` \| value\ :sup:`i`\ $}\ :sup:`\* ` (SMS only)  and POKE\_W address,value address=0,2,4,6,...value=-32768..32767  or POKE\_W address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ (Minerva and SMS only)  and POKE\_L address,valueaddress=0,2,4,6,... value=-655362/2..655362/2-2  or POKE\_L address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ (Minerva and SMS only)  |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 Both kinds of internal memory (RAM and ROM) are organised as a stream
of values. The basic unit for memory is a bit (a value of 0 or 1
relating to false or true), which relates to the binary system of
counting. Eight bits are combined to form a byte (0 to 255), sixteen
bits make a word, and thirty-two a longword. Words and longwords are
signed whilst bytes are unsigned. The POKE commands allow you to set
values in memory. It is however unwise to POKE just anywhere, because
there could be important code present in that part of memory which will
be disrupted by POKEs and could crash your computer. You would generally
have already set aside a part of memory for use by your own programs, by
using RESPR or ALCHP and then you would POKE
 different values in that part of memory, eg. for storing data. This is
a representation of the relationship betwen bits, bytes, words and
longwords: 10011000 10001000 11011111 10111000 01110110 11000111
01100000 00000011 \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / byte 152 136
223 184 118 199 96 3 \\ / \\ / \\ / \\ / words 39048 57272 30407 24579
\\ / \\ / longwords -1.73586E9 1.992778E9

**NOTE 1**

Negative values can also be stored in memory. However, they are stored
by deducting the number from the maximum number which can be stored in a
byte plus one. POKE 131072,255 and POKE 131072,-1 have the same effect!

**NOTE 2**

Do not try to POKE\_W or POKE\_L to an odd address (eg. 10001) as this
will cause an error unless you are using Minerva (see below).

**NOTE 3**

If you try to poke a value which is too big to fit into the given space,
eg. POKE 131072,-32768 then only the least significant byte is used
(with POKE) and the low word is used (with POKE\_W).

**NOTE 4**

The THOR XVI limits value to the following ranges: POKE: -128..255;
POKE\_W: -32768..65535

**MINERVA NOTES**

The POKE, POKE\_W and POKE\_L commands on Minerva (version 1.77 or
later) are very much enhanced and different. Minerva allows you to
POKE\_W and POKE\_L to odd addresses (eg. POKE\_W 131073,100100
 Minerva has also added to the usefulness of the POKE, POKE\_W
 and POKE\_L commands by allowing them to store a list of numbers in one
go. As an example the following two program lines have exactly the same
effect, although only line 100 will run on a non-Minerva QL. 100 POKE\_W
start,10:POKE\_W start+2,125:POKE\_W start+4,10322
 110 POKE\_W start,10,125,10322
 Minerva also allows the BASIC programmer to access the QL's SuperBASIC
variables, system variables and Minerva's own System Xtensions (although
the extended PEEKs should be of more use). You will need a good book on
QDOS (eg. QDOS/SMS Reference Manual) to find out what the possible
values are. The syntax for these extra commands is:

(1) Alter SuperBASIC variables.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

POKE \\\\SBvar,value SBvar=0...256 POKE\_W \\\\SBvar,value POKE\_L
\\\\SBvar,value POKE \\SBvar\\Offset,value POKE\_W \\SBvar\\Offset,value
POKE\_L \\SBvar\\Offset,value

(2) Alter System variables.
~~~~~~~~~~~~~~~~~~~~~~~~~~~

POKE !!Sysvar,value Sysvar=0...1152 POKE\_W !!Sysvar,value POKE\_L
!!Sysvar,value POKE !Sysvar!Offset,value POKE\_W !Sysvar!Offset,value
POKE\_L !Sysvar!Offset,value
 POKE \\\\SBvar,value
 will alter the SuperBASIC variable pointed to by Sysvar, such as the
current line number. The most useful of these are variables $68 onwards.
POKE \\SBvar\\Offset,value
 allows you to alter the different SuperBASIC tables used by the QL (eg.
the channel table). The start addresses of the different tables are
contained in the SuperBASIC variables $0 to $64. SBvar must contain the
relevant SuperBASIC variable (the pointer to the required table), then
the Offset is the required address within the table. POKE !!Sysvar,value
 allows you to alter the different system variables (normally stored at
$28000 on a QL, but they can move!). These are useful for accessing the
current network number, finding free space, accessing device drivers,
forcing <CAPSLOCK>..... Sysvar merely contains the number of the
required system variable. POKE !Sysvar!Offset,value
 takes the address contained within the given system variable, adds the
Offset to that address and then pokes it with the given value. On a
Minerva machine the system variable stored at $7C (124) (SV.CHTOP)
contains the address of the Minerva System Xtensions, therefore to alter
these: SysX=PEEK\_L (ver$(-2) + 124) POKE SysX+offset,value POKE\_W
SysX+offset,value POKE\_L SysX+offset,value
 Minerva's System Xtensions provide such things as the addresses for
translation tables, the attributes for the size type and colour of a
cursor, the fonts for all subsequently opened windows and much more...
(see Minerva manual for list).

**Minerva Example 1**

It is sometimes useful to alter the key repeat delay and frequency to
make allowances for when a different keyboard is attached to the QL, so
that you can type more quickly without having the problem that you are
waiting around for auto-repeat to take effect. These two values can now
simply be altered using: POKE\_W !!140,key\_delay POKE\_W
!!142,key\_frequency

**Minerva Example 2**

Want to attach a new font to all channels which will be opened in the
future? 100 a=RESPR(2000) 110 LBYTES flp1\_new\_font,a 120 POKE\_L
!124!40,a

**Minerva Example 3**

It might be useful in an error trapping routine to find the current DATA
position (eg. if there is an error when reading data into a variable),
so that the position may be returned to later once the error has been
overcome. You may even wish to miss out the problem DATA line. This
program is an 'intelligent' data-loader: 100 WHEN ERRor 110
data\_line=PEEK\_W(\\\\148) 115 PRINT 'ERROR IN DATA
LINE'!data\_line!';statement'! PEEK(\\\\151)-1 120 INPUT 'Go to next
data line (y/n)'!a$ 130 IF a$=='y': POKE\_W\\\\148,data\_line+1:
POKE\\\\150,1:POKE\\\\151,1: RETRY 140 IF a$=='n' THEN 145
data\_store=PEEK\_W(\\\\148)\*65536+(PEEK(\\\\150)-1)\*256+PEEK(\\\\151)-1
147 PRINT"Alter offending line then enter re\_run":STOP 149 END IF 150
END WHEN 155 : 160 RESTORE 170 ax=RESPR(100):i=0 180 REPeat data\_load
190 IF EOF: EXIT data\_load 200 READ b 210 PRINT b,i:POKE ax+i,b 220
i=i+1 230 END REPeat data\_load 240 DATA 10,10,2,3,3a,10 250 DATA
10,2,2,3,3,2 255 : 260 DEFine PROCedure RE\_run 270 POKE\_L
\\\\148,data\_store: GO TO 170 280 END DEFine

**SMS NOTE**

POKE, POKE\_W and POKE\_L have been made the same as on Minerva except
that POKE\_W and POKE\_L cannot address odd addresses. SMS does not
possess Minerva's System Xtensions. Please also note that SMS's improved
interpreter won't allow you to enter line 240 in the Minerva Example 1.
One extra addition to SMS is that the POKE command can actually accept a
string as a value to be poked into memory. If a string is passed as a
parameter, each character of the string is converted to its character
code and then that byte poked into memory, for example: POKE
base,0,5,'WIN1\_'
 will store 'WIN1\_' as a standard QL string (a word containing its
length followed by the string itself) at the address in memory pointed
to by base. Note that if you pass an empty string, this will have no
effect.

**WARNING**

If you are POKEing around in memory then make sure that you know what
you are doing. On every QDOS machine, even RAM areas which have not been
set aside for program use are used by the operating system, eg. for
buffering purposes. On Emulators and QLs fitted with a Gold Card, the
operating system itself is no longer in ROM but is moved into RAM.
POKEing in this area will almost surely lead to crashes. Even advanced
users who know which parts of memory are used by QDOS should avoid
amending QDOS directly. There are more elegant and safer methods how to
do this which will run on every QDOS compatible computer.

**CROSS-REFERENCE**

`PEEK <KeywordsP.clean.html#peek>`__, `PEEK\_W <KeywordsP.clean.html#peek-w>`__,
`PEEK\_L <KeywordsP.clean.html#peek-l>`__ and `PEEK$ <KeywordsP.clean.html#peek>`__
read memory values and `POKE$ <KeywordsP.clean.html#poke>`__ is another
command to set them. `CHAR\_DEF <KeywordsC.clean.html#char-def>`__ allows you
to attach a font to all channels `OPEN <KeywordsO.clean.html#open>`__\ ed
after the command. `POKES <KeywordsP.clean.html#pokes>`__ allows you to
`POKE <KeywordsP.clean.html#poke>`__ memory in Supervisor mode.

--------------

POKES
=====

--------------

POKES\_W
~~~~~~~~

--------------

POKES\_L
~~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  POKES address, {value\ :sup:`1` \| value\ :sup:`1`\ $} :sup:`\*`\ {,value\ :sup:`i` \| ,value\ :sup:`i`\ $}\ :sup:`\* ` address=0,1,2,3,... value=0...255  and POKES\_W address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ address=0,2,4,6,... value=-32768..32767  and POKES\_L address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ address=0,2,4,6,... value=-655362/2..655362/2-2  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E and ATARI\_REXT v2.17+                                    |
+----------+-------------------------------------------------------------------+

 These three commands are only of any use on the Atari series of
computers. They are the same as the simple forms of POKE, POKE\_W and
POKE\_L, except that they operate in Supervisor Mode and can therefore
be used to write data direct into the Atari's IO hardware. On all other
implementations they are the same as POKE, POKE\_W
 and POKE\_L.

**CROSS-REFERENCE**

See `POKE <KeywordsP.clean.html#poke>`__ and `PEEKS <KeywordsP.clean.html#peeks>`__.
Also see `PROT\_MEM <KeywordsP.clean.html#prot-mem>`__.

--------------

POKE$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  POKE$ address,string$                                            |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT, TinyToolkit, BTool, SMS                             |
+----------+-------------------------------------------------------------------+

 The standard version of this command pokes the code of each of the
given string's characters to memory from address onwards. In SuperBASIC,
the procedure might look similar to: 100 DEFine PROCedure POKE$
(address,string$) 110 LOCal i 120 FOR i=1 TO LEN(string$) 130 POKE
address+i-1,CODE(string$(i)) 140 END FOR i 150 END DEFine POKE$
 The BTool version writes the string in QDOS internal format: the
string's contents are preceded by two additional bytes (one word)
indicating the length of the string. address must be even. If you pass
an empty string, all versions of this command will not do anything.

**SMS NOTE**

This command is now very similar to POKE in that POKE allows you to pass
a string as a parameter. POKE$ can also now access the System Variables
and SuperBASIC variables directly as with POKE.

**CROSS-REFERENCE**

`PEEK$ <KeywordsP.clean.html#peek>`__ reads strings from memory.
`MKS$ <KeywordsM.clean.html#mks>`__ returns the internal format of a given
string. `TTPOKE$ <KeywordsT.clean.html#ttpoke>`__ is the same as this
command.

--------------

POKE\_F
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  POKE\_F address,float                                            |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

 Floating point numbers are internally stored as six bytes. POKE\_F will
store any float at address in memory where ODD(address)=0.

**Example**

Floating point numbers can be stored in internal format in a file with
PUT. The disadvantage of that method is low disk access speed if you
need to store a large number of values. Compare the following two
programs which store the same amount of data at different speeds: (a)
slow but minimal memory usage: 100 n=1000: file$="flp1\_test\_dat" 120
fp=FOP\_NEW(file$) 130 FOR i=1 TO n: PUT#fp,RND 140 CLOSE#fp
 (b) fast but 6K buffer required: 100 n=1000: file$="flp1\_test\_dat"
120 a=ALCHP(6\*(n+1)) 130 FOR i=0 TO n: POKE\_F a+i\*6,RND 140 SBYTES
file$,a,6\*(n+1) 150 RECHP a

**CROSS-REFERENCE**

`POKE <KeywordsP.clean.html#poke>`__, `POKE\_W <KeywordsP.clean.html#poke-w>`__ and
`POKE\_L <KeywordsP.clean.html#poke-l>`__ store different ranges of integer
numbers. `MKF$ <KeywordsM.clean.html#mkf>`__ returns the internal
representation of a floating point number as a string.
`GET <KeywordsG.clean.html#get>`__ and `PUT <KeywordsP.clean.html#put>`__ write all
kinds of data types in their internal format to a channel,
`FPUTF <KeywordsF.clean.html#fputf>`__ and `FGETF <KeywordsF.clean.html#fgetf>`__
are specialised variants for floats only. See also
`PEEK\_F <KeywordsP.clean.html#peek-f>`__!

--------------

PRINT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PRINT [#chan,] :sup:`\*`\ [ [separator] [strg\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\* ` or PRINT :sup:`\*`\ [ [#chan,] [separator] [strg\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\* ` (THOR XVI & Minerva v1.97+ only)  |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This command will send a string of bytes to the specified channel
(default #1). If any variables (var) are specified, the contents of
those variables are PRINTed in the specified channel. If the channel is
a window, the characters printed appear at the current text cursor
position, in the current INK
 colour on the current STRIP colour, and will also be affected by the
settings of CSIZE, UNDER, FLASH and OVER. If you tell PRINT to use an
unset variable, an asterisk ('\*') will be PRINTed on screen rather than
an error being reported (except on SMS where an unset variable is given
the value 0 (if a numeric variable) or '' for a string). Beware, however
that if you try to use an unset variable in a calculation inside the
PRINT statement, an 'Error in Expression' error will be generated, for
example: 1 a=10 : PRINT 'A is :'! a ,'B is :'! b : PRINT 'A\*B is :'
!a\*b
 If a channel is specified, this must be followed by a comma. It may
however also be followed by one or more separators, as with INPUT. At
the end of the PRINT command, the text cursor is placed at the start of
the next print line (unless an end separator of '!', '\\' or ';' is
used). When using a separator of '!', TO or ',' on a non-window channel,
the PRINT statement will always assume the end of each line to be the
number of characters specified with the WIDTH
 command, thus allowing you to format your output on a printer, for
example.

**Example**

The following procedure allows you to print text to a given channel
without splitting words when the text wraps onto the next line: 100
DEFine PROCedure PRINT\_TEXT(ch,txt$) 110 LOCal print\_loop 120 REPeat
print\_loop% 130 IF LEN(txt$)=0:PRINT #ch:RETurn 140 I%=' ' INSTR txt$
150 IF I%=0:PRINT #ch!!txt$:RETurn 160 PRINT #ch!!txt$(1 TO I%-1)! 170
IF I%<LEN(txt$):txt$=txt$(I%+1 TO):ELSE txt$='' 180 END REPeat
print\_loop% 190 END DEFine
 Try: WINDOW #1,50,100,32,16:PRINT\_TEXT #1,'This is a test line'
 Compare: PRINT #1,'This is a test line'

**NOTE 1**

Version 6.40 of the THOR XVI ROM can crash if you try to use PRINT with
the '!' separator in a non-window channel.

**NOTE 2**

The THOR XVI (all versions) and non-Minerva ROMs (unless SMS is
installed) have problems with the concatenation of values which should
produce an 'Overflow Error'. For example, PRINT 'hello'&(1/0)
 may crash the computer rather than producing an overflow error.

**NOTE 3**

PRINT can only show a maximum of six integer digits. If a number is
larger than this, it will be represented by the E function (eg. 1E2 is
the same as 100). If on the other hand, the figure is a floating point,
then the QL can cope with seven digits excluding the decimal point, eg.
123.4567. Any more digits will cause the number to be rounded up or down
as appropriate.

**MINERVA NOTE**

v1.97+ allows different channels part way through statement as per THOR
XVI.

**THOR XVI NOTE**

Version 6.41 of the THOR XVI allows you to put channel numbers part way
through a statement, for example: PRINT 'Name:'!name$ \\#0; 'Address:'
!address$
 instead of: PRINT 'Name '!name$ : PRINT #0;'Address:'!address$

**CROSS-REFERENCE**

See also `INPUT <KeywordsI.clean.html#input>`__ which contains a description
of the different types of separators. Please also see
`WIDTH <KeywordsW.clean.html#width>`__. `TO <KeywordsT.clean.html#to>`__ has other
meanings - see `TO <KeywordsT.clean.html#to>`__.
`VG\_PRINT <KeywordsV.clean.html#vg-print>`__ allows you to print using
scaleable fonts on screen. `CHAR\_USE <KeywordsC.clean.html#char-use>`__ and
`CHAR\_DEF <KeywordsC.clean.html#char-def>`__ allow you to alter the fonts
used for printing characters on screen.

--------------

PRINT\_USING
============

+----------+-------------------------------------------------------------------+
| Syntax   |  PRINT\_USING [#ch,] format$, :sup:`\*`\ [item\ :sup:`i`]\ :sup:`\* ` |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

 This command allows you to send output to the specified channel
(default #1) in a particular format. This for example, allows you to
print neat columns of figures easily, all lined up on the decimal point.
The format$ is made up of a mixture of special characters, text and
fields. Basically, PRINT\_USING will print out format$ as normal, until
one of these special characters is met. The special characters currently
supported are: � (copyright) + - ( # \* , . ! \\ ' " and $. These have
the following effects:

CharacterEffect
~~~~~~~~~~~~~~~

�This forces PRINT\_USING to print out the next character in format$
even if it is a special character. If you want to print some text
including one of the special characters, this must be used. +This is
used to either prefix or postfix a decimal field. If present, then the
sign of the decimal number is written out in this position. -This is
used to either prefix or postfix a decimal field. The sign of the
decimal number will only be written in this position if the number is
negative. (This and the closing bracket can be used to surround a
decimal field, in which case if the number is negative, it will appear
in brackets. #This is used to mark a type of field (see below). \*This
is also used to mark a type of field (see below). \\This will force a
newline to take place. Unlike PRINT, PRINT\_USING does not automatically
carry out a newline after finishing its work. " and 'Anything between
either single or double quotation marks will be printed out without
looking for special characters. $This is used to signify the start of a
currency field. Any characters between this sign and the next '#' symbol
are taken to be the name of the currency and are pushed right to line up
with the actual amount. The fields in the format$ allow you to print
text and/or figures in specific formats. Each item following format$ is
then read and inserted in place of each field. If however, a numeric
field is not long enough to hold the specified figure, then the field
appears as just '#' marks on screen. Text fields will just truncate the
text supplied to fit. The fields which are recognised are:

FieldMeaning
~~~~~~~~~~~~

####If item is text, write it left justified and truncate to fit size of
field if necessary. If item is a number, write the integer part of the
number right justified (eg. PRINT\_USING '###','Hello'
 will print Hel). \*\*\*\*This is the same as #### except that any
unused part of the field to the left of the characters is filled with
'\*' (eg. PRINT\_USING '\*\*\*\*',1.234 will print \*\*\*1). ###.##Print
a fixed decimal point number right justified to a set number of decimal
places. (eg. PRINT\_USING '##.#',1.26 will print 1.3). \*\*\*.\*\*The
same as ###.## except that any unused part of the field is filled with
'\*'. #,###.##This is the same as ###.## except that a comma will be
used to separate thousands. \*,\*\*\*.\*\*This is similar to #,###.##
except that any unused part of the field will be filled with '\*'.
-#.###!!!!This is used for an exponential field with the sign only being
shown if the figure is negative (eg. PRINT\_USING '-#.##!!!!',3120 will
print 3.12E+03). An exponential field must always begin with a sign
followed by one # mark and a decimal point, and always end with four !
marks. +#.###!!!!This is the same as -#.###!!!! except that the sign of
the number is always shown. ###.>>This is introduced by SMSQ/E v2.73+
and is the same as ###.## except that it is for fixed point decimal
figures, scaled accordingly. This allows you, for example, to convert a
calculation from pennies into pounds (eg. PRINT\_USING '###.>>',312.01
will print 3.12). You can add more > characters after the decimal point
if you need to convert to three decimal places. \*\*\*.>>This is
introduced by SMSQ/E v2.73+ and is the same as ###.>> except that any
unused part of the field is filled with '\*'.

**Example**

A program which prints out a stocklist, which might be useful for a
small business: 100 RESTORE 110 MODE 4 120 WINDOW 448,200,32,16:PAPER
0:INK 7:CLS 130 CSIZE 2,0:AT 1,10:UNDER 1:PRINT 'STOCK LIST' 140 CSIZE
1,0:AT 5,0 150 PRINT 'NO ITEM IND. PRICE TOTAL' 160 UNDER 0 170
total=0:Lines=6 180 REPeat loop 190 IF EOF:EXIT loop 200 READ
equipment$,items,ind\_price 210 price=ind\_price\*items 220
total=total+price:Lines=Lines+1 230 PRINT\_USING '#,###.
##############',items,equipment$ 240 PRINT\_USING ' $##.##
$##,###.##\\',ind\_price,price 250 END REPeat loop 260 OVER 1:AT
Lines-1,0:UNDER 1 270 PRINT FILL$(' ',45):UNDER 0 280 IF
INT(total)<>total:total=total\*100 290 PRINT TO 23;'Total Stock
�';CDEC$(total,9,2) 1000 DATA 'Minerva',110,40,'Minerva MKII',205,65.61
1010 DATA 'Hermes',100,25,'68008 CPU',1230,8.7

**NOTE 1**

On Toolkit II versions before v2.08, this command could cause problems
if an empty string was passed to it.

**NOTE 2**

Some versions of the Toolkit II manual get the copyright symbol ('�')
mixed up with the address symbol ('@'). The latter has no special
meaning.

**NOTE 3**

Because of variations in the way in which numbers are represented in
different countries, either a comma or full stop is recognised as a
decimal point by PRINT\_USING. If a field only contains one comma or
full stop, that is taken to be the decimal point, however, if more than
one comma and/or full stop appears in the field, the last one is taken
to be the decimal point, the others being assumed to be thousands
separators. If you want numbers to be printed with thousands separators
but no decimal point, use a comma or full stop as the last character of
the field.

**CROSS-REFERENCE**

See also `FDEC$ <KeywordsF.clean.html#fdec>`__,
`IDEC$ <KeywordsI.clean.html#idec>`__ and `CDEC$ <KeywordsC.clean.html#cdec>`__.

--------------

PRIO
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PRIO priority                                                    |
+----------+-------------------------------------------------------------------+
| Location |  PRIO                                                             |
+----------+-------------------------------------------------------------------+

 This command sets the priority of the current job to the given
priority. Priority must range from 0 to 127.

**Example**

Multitasking jobs waiting for a keypress or anything else to be
activated slow down the whole system although they are actually doing
nothing. A job which is waiting (perhaps for a certain amount of time)
for input could set its own priority to one, and then when it is able to
continue, reset to a higher priority value.

**NOTE**

If a job has priority 0 it will not be able to run. Other tasks may
however set that job's priority (eg. with SPJOB and allow it to
continue).

**CROSS-REFERENCE**

`SPJOB <KeywordsS.clean.html#spjob>`__, `SP\_JOB <KeywordsS.clean.html#sp-job>`__,
and `PJOB <KeywordsP.clean.html#pjob>`__ also deal with job priorities. `SPJOB
-1 <KeywordsS.clean.html#spjob20-1>`__,
`priority <Keywordsp.clean.html#priority>`__ is exactly the same as `PRIO
priority <KeywordsP.clean.html#prio20priority>`__ or
`PRIORITISE <KeywordsP.clean.html#prioritise>`__
`priority <Keywordsp.clean.html#priority>`__.

--------------

PRIORITISE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRIORITISE [jobnr, jobtag,] priority                             |
+----------+-------------------------------------------------------------------+
| Location |  TASKCMDS (DIY Toolkit Vol J)                                     |
+----------+-------------------------------------------------------------------+

 PRIORITISE is a command which takes either one or three parameters and
sets the priority of the current job (if only one parameter is used) or
the job specified by jobnr and jobtag to priority.

**Example**

PRIORITISE 127 gives the current job the maximum amount of processor
time available when multitasking.

**CROSS-REFERENCE**

A one parameter variant of `PRIORITISE <KeywordsP.clean.html#prioritise>`__ is
`PRIO <KeywordsP.clean.html#prio>`__. Refer to
`SPJOB <KeywordsS.clean.html#spjob>`__ and connected keywords for more
information on jobs and priorities. `JOBS <KeywordsJ.clean.html#jobs>`__ will
give details of job numbers and job tags.

--------------

PRO
===

+----------+-------------------------------------------------------------------+
| Syntax   |  PRO                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

 This function returns the codes needed to switch on the proportional
font on an EPSON compatible printer: PRINT PRO
 is the same as PRINT CHR$ (27) &"p" &CHR$ (1)

**CROSS-REFERENCE**

`NORM <KeywordsN.clean.html#norm>`__, `BLD <KeywordsB.clean.html#bld>`__,
`EL <KeywordsE.clean.html#el>`__, `DBL <KeywordsD.clean.html#dbl>`__,
`ENL <KeywordsE.clean.html#enl>`__, `SI <KeywordsS.clean.html#si>`__,
`NRM <KeywordsN.clean.html#nrm>`__, `UNL <KeywordsU.clean.html#unl>`__,
`ALT <KeywordsA.clean.html#alt>`__, `ESC <KeywordsE.clean.html#esc>`__,
`FF <KeywordsF.clean.html#ff>`__, `LMAR <KeywordsL.clean.html#lmar>`__,
`RMAR <KeywordsR.clean.html#rmar>`__, `PAGDIS <KeywordsP.clean.html#pagdis>`__,
`PAGLEN <KeywordsP.clean.html#paglen>`__.

--------------

PROCESSOR
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROCESSOR                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

 This function returns a value which can be used to find the type of
Processor on which SuperBASIC is running (normally a member of the
Motorola 680xx family). The values returned are:

PROCESSORChip Type
~~~~~~~~~~~~~~~~~~

0x68000 or 68008 1x68010 or an INTEL chip (if QPC is running) 2x68020
3x68030 4x68040 6x68060 (x is replaced by a value between 0 and 8 to
indicate if a maths co-processor is installed). You can also test if a
maths co-processor is installed, by using: coprocessor%=PEEK(!!$A1) &&
BIN('1111')
 The following values may be returned:

coprocessor%Meaning
~~~~~~~~~~~~~~~~~~~

0No FPU fitted 1An Internal MMU is fitted. 2A 68851 MMU is fitted 4An
internal FPU is fitted. 8EIther a 68881 or 68882 FPU is fitted

**NOTE**

The processor type was not stored before Level E-20 of the ST/QL
Drivers.

**CROSS-REFERENCE**

See `MACHINE <KeywordsM.clean.html#machine>`__,
`QDOS$ <KeywordsQ.clean.html#qdos>`__ and `VER$ <KeywordsV.clean.html#ver>`__

--------------

` <>`__... PROCedure
====================

+----------+-------------------------------------------------------------------+
| Syntax   |  ... PROCedure                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

 This keyword forms part of the structure DEFine PROCedure. As such, it
cannot be used on its own within a program - this will cause a 'bad
line' error.

**CROSS-REFERENCE**

Please refer to the individual structure descriptions for more details.

--------------

PROGD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PROGD$                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

 This function returns the default program device as set by PROG\_USE,
see below.

**CROSS-REFERENCE**

`PROG\_USE <KeywordsP.clean.html#prog-use>`__,
`DLIST <KeywordsD.clean.html#dlist>`__, `DATAD$ <KeywordsD.clean.html#datad>`__.

--------------

PROG\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROG\_USE default\_device                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

 The command PROG\_USE and dependent commands behave in the same way as
DATA\_USE with a few differences: The program device set with PROG\_USE
is used by the EX (EXEC), EW (EXEC\_W) and (exceptionally SEXEC)
commands as the default device. Whereas some commands which use the data
device (eg. MERGE, LOAD) check the program device if they do not find a
given file on the data device, the above commands which use the program
device will not look at the data device should they fail on the program
device.

**NOTE**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to assign a longer string will result in the
error 'Bad Parameter' (error -15).

**CROSS-REFERENCE**

`PROGD$ <KeywordsP.clean.html#progd>`__ returns the program device setting.
See `DATA\_USE <KeywordsD.clean.html#data-use>`__ for more information.

--------------

PROT\_DATE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROT\_DATE flag                                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Gold Card                                                   |
+----------+-------------------------------------------------------------------+

 Many systems which can run SMS (including QXL, the Gold Card and Super
Gold Card) include a battery backed clock (also known as a real-time
clock). In this case, there are actually two clocks running: One is run
by the operating system (the QL internal clock) which is found on each
QL implementation. The internal clock forgets the time if the computer
is switched off and has to be set each time the machine is powered up.
The other clock is the battery backed clock which keeps the time even
when the QL is switched off (until the battery runs flat) and this
normally sets the Internal Clock each time the QL is reset (or switched
on). It may be necessary to adjust the QL's internal clock whilst the QL
is being used, without wishing to disrupt the battery backed clock -
some software alters the QL's internal clock when there is no need, the
internal clock can also be affected by crashes during program
development. Some battery backed clocks may alter their time when the
QL's internal clock is altered and therefore some form of protection is
needed - you will normally need to enable the protection by using the
command: PROT\_DATE 1. PROT\_DATE 0 will disable the protection.

**NOTE 1**

This has no effect on the battery backed clock provided by Minerva MKII
which has to be altered using the configuration program.

**NOTE 2**

If you reset the Gold Card or Super Gold Card to 128K, PROT\_DATE 1 is
executed.

**NOTE 3**

Serious crashes and some old games may disturb the battery backed clock
even in protected mode.

**NOTE 4**

On some conbinations of AURORA and Super Gold Card, if you use
PROT\_DATE 1, the QL's internal clock will run too quickly (see also the
notes on DISP\_SIZE).

**WARNING**

SMS, the Gold Card and Super Gold Card do not automatically protect the
battery backed clock. It is therefore advisable to include the line:
PROT\_DATE 1
 in your boot program.

**CROSS-REFERENCE**

`SDATE <KeywordsS.clean.html#sdate>`__ and `ADATE <KeywordsA.clean.html#adate>`__
alter the QL's internal clock.\ `DATE$ <KeywordsD.clean.html#date>`__ and
`DAY$ <KeywordsD.clean.html#day>`__ can be used to read the time on the QL's
internal clock.

--------------

PROT\_MEM
~~~~~~~~~

+----------+-------------------------------------------------------------------+
| Syntax   |  PROT\_MEM level                                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

 The command PROT\_MEM can be used to set the level of memory protection
which is afforded on Atari ST and TT computers, to try and stop the user
from altering essential areas of the operating system by mistake. There
are five levels of memory protection currently available:

LevelProtection
~~~~~~~~~~~~~~~

0Memory access faults are not reported. 1Write memory access faults are
trapped from all jobs except from Job 0. Read operations from a
protected area read 0. 2Read memory access faults are trapped from all
jobs except Job 0. Any Write operations to a protected area are ignored.
3Both Read and Write memory access faults are trapped from all jobs
except Job 0. 7Both Read and Write memory access faults are trapped from
all jobs. The default level is 3. We would recommend that Level 0 is
avoided if at all possible. Memory access faults tend to occur when the
user (or a program) tries to access memory which does not exist or can
only be accessed in Supervisor Mode (the vector area, the TOS system
variables and the IO hardware). However, under SMSQ/E, if there is an
attempt to read an address which actually forms part of the legitimate
QL vector area, this will not cause a fault. If a memory access fault is
trapped, the Job which has caused the fault is paused and the program
counter is placed on the stack (all registers are preserved). An
advanced user may then use a debugger to examine the Job to find out
what has caused the fault.

**NOTE**

Unfortunately, on other implementations, this command has no effect, and
it is therefore still possible to overwrite the operating system on QL
Emulators (non-Atari based), Gold and Super Gold Cards.

**CROSS-REFERENCE**

See `POKES <KeywordsP.clean.html#pokes>`__ and
`PEEKS <KeywordsP.clean.html#peeks>`__.
`PROT\_DATE <KeywordsP.clean.html#prot-date>`__ protects a battery backed
clock.

--------------

PROUND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PROUND (p, x)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  TRIPRODRO                                                        |
+----------+-------------------------------------------------------------------+

 PROUND is a function which rounds the given floating pointer number x
to the precision of 10\ :sup:`p`. It looks at the next digit to decide
whether to round upwards or downwards and ignores any others.

**Example**

Print ten random number with three digits after the decimal point: 100
RANDOMISE 110 FOR i = 1 TO 10 120 PRINT PROUND(-3, 10\*RND) 130 END FOR
i

**CROSS-REFERENCE**

`DROUND <KeywordsD.clean.html#dround>`__

--------------

PRT\_ABORT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_ABORT                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 This is the same as PAR\_ABORT or SER\_ABORT, depending on which device
PRT is linked to.

**CROSS-REFERENCE**

See `SER\_ABORT <KeywordsS.clean.html#ser-abort>`__ and
`PAR\_ABORT <KeywordsP.clean.html#par-abort>`__.
`PRT\_USE <KeywordsP.clean.html#prt-use>`__ allows you to specify which port
`PRT <KeywordsP.clean.html#prt>`__ emulates.

--------------

PRT\_ABT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_ABT                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Trump Card, Gold Card, QXL                                       |
+----------+-------------------------------------------------------------------+

 Because all output sent to the Trump Card, Gold Card and Super Gold
Card's built in PRT device is buffered (except if you are running SMSQ/E
which uses its own PRT device), it can be useful to stop the port from
outputting any further data. PRT\_ABT will prevent any further output
and clear the contents. The message \*\*\*\*\*\* ABORTED \*\*\*\*\*\*
 will then be sent to the port.

**CROSS-REFERENCE**

`PRT\_USE <KeywordsP.clean.html#prt-use>`__ allows you to specify the type of
output to be buffered. The ST/QL Emulator and SMSQ/E support a similar
function with `PRT\_ABORT <KeywordsP.clean.html#prt-abort>`__,
`PAR\_ABORT <KeywordsP.clean.html#par-abort>`__ and
`SER\_ABORT <KeywordsS.clean.html#ser-abort>`__.

--------------

PRT\_BUFF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_BUFF [size]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 This is exactly the same as PAR\_BUFF except that it creates buffered
output on whichever port is attached to the PRT
 device.

**CROSS-REFERENCE**

See `PAR\_BUFF <KeywordsP.clean.html#par-buff>`__.

--------------

PRT\_CLEAR
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_CLEAR                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 This clears out all currently closed PRT buffers, thus preventing any
further output, in the same way as PAR\_CLEAR.

**CROSS-REFERENCE**

`PAR\_CLEAR <KeywordsP.clean.html#par-clear>`__ and
`SER\_CLEAR <KeywordsS.clean.html#ser-clear>`__ are similar.

--------------

PRT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_USE device                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 The ST/QL Emulator and SMSQ/E allow you to set up the PRT
 device so that it mimics the SER, STX or PAR device. This means that
programs can be written which merely send their output to the PRT device
and it is then up to the user to set the port and options required by
the device attached to either the serial or parallel port. The command
PRT\_USE allows you to specify both the port and options to be
associated with PRT. It will ignore SER\_USE and PAR\_USE settings and
therefore expects device to be in one of the following forms:-
PAR<port><translate><convert><eof>
SER<port><parity><handshake><translate><convert><eof>
STX<port><parity><handshake><translate><convert><eof> See the Appendix
on drivers for further details.

**Example**

PRT\_USE ser1etf
 will cause all attempts to access the PRT device to be re-directed to
serial port 1 with Even parity, translation enabled and a form feed
being printed at the end of the file.

**CROSS-REFERENCE**

`RAM\_USE <KeywordsR.clean.html#ram-use>`__,
`FLP\_USE <KeywordsF.clean.html#flp-use>`__,
`WIN\_USE <KeywordsW.clean.html#win-use>`__,
`SER\_USE <KeywordsS.clean.html#ser-use>`__ and
`PAR\_USE <KeywordsP.clean.html#par-use>`__ are all very similar. See the
other version of this command.

--------------

PRT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_USE usage,device                                            |
+----------+-------------------------------------------------------------------+
| Location |  Qjump RAMPRT, Trump Card, Gold Card, QXL Card                    |
+----------+-------------------------------------------------------------------+

 Unlike the ST/QL Emulator and SMSQ/E implementations of this command,
this version of this command is used to enable you to set up dynamic
buffering on serial and parallel ports. The command PRT\_USE enables you
to connect a buffer to a specified device, altering the description
(usage) used to access that buffered device. Initially, the default
usage is PRT and the default device is SER which means that any attempt
to send output to the PRT
 device will actually access ser1, using the whole of the available
memory as a buffer. PRT\_USE will actually recognise the full device
name, allowing it to have a similar effect as the alternative version of
this command. For example, the following are both equivalent:- PRT\_USE
prt,ser1c (On the Gold Card) PRT\_BUFF 0:PRT\_USE ser1c (Under SMSQ/E)
The PRT device will also allow the same options as the device which it
is emulating, for example, the following are both the same (except the
latter uses buffered output): OPEN #3,ser1c PRT\_USE prt,ser:OPEN
#3,prt1c
 If you wish to buffer output on a given device, then you merely need to
specify the usage to be the same as the device. For example, PRT\_USE
ser,ser
 will create buffered output to the serial ports whenever ser is used.
PRT\_USE will also allow you to specify the device to be buffered at
run-time. This is achieved by leaving the device
 parameter as an empty string. For example: PRT\_USE buff\_,"" allows
you to use the device name buff\_ser1 to access ser1, buff\_par to
access the parallel port etc. and all with buffered output.

**NOTE 1**

PRT\_USE prt,ser will return the QL to the normal state after being
switched on (ie. only buffered output will occur if the device PRT is
used).

**NOTE 2**

If PRT\_USE is used to allow background printing, then some characters
may be lost (especially if you are using an old serial to parallel
convertor), if you use a command which stops the QL multitasking (for
example FORMAT, LOAD, LBYTES, SBYTES
 and SAVE). You can tell when this happens as the printer will stop
while the command is being carried out.

**CROSS-REFERENCE**

See also `PRT\_ABT <KeywordsP.clean.html#prt-abt>`__. See the other version of
this command.

--------------

PRT\_USE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_USE$                                                        |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

 This function returns a string representing the current port emulated
by the PRT device, thus allowing you to check whether or not you need to
alter the device set with PRT\_USE.

**Example**

PRT\_USE ser1etf
 PRINT PRT\_USE$
 will return 'ser1etf'.

**CROSS-REFERENCE**

See `PRT\_USE <KeywordsP.clean.html#prt-use>`__.

--------------

PTH\_ADD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_ADD [n,] directory                                          |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

 First we need to explain the PTH device before you can understand what
the command PTH\_ADD and its related commands/ functions do. Using
sub-directories helps to clean up disk storage - even if you know on
which disk a file is kept, if you are using a large storage media like
HD/ED disks or even hard disks, you will soon find yourself searching
through the whole directory tree with a desktop or WDIR. That's why PTH
was created. This virtual device interfaces with any kind of drive and
searches through a list of directories when a file is to be opened. For
instance, instead of being forced to type: VIEW
win1\_games\_defender\_manual\_txt
 a short VIEW pth1\_manual\_txt
 would be enough to show the manual\_txt if the directory
win1\_games\_defender\_ is in the path list. The size of the search list
is only limited by memory available; a list of 30000 entries has been
tested, 900k was necessary to store it - but this is not a realistic
limitation. Who works with several thousand directories? PTH\_ADD
modifies that list which can have as many entries as necessary. PTH\_ADD
(the name says it already) adds a directory to the path list, it can be
inserted (you cannot replace pathnames!) at a certain position by
directly specifying the position n (a non-negative integer) in the list.
If n is not specified, the new directory is merely added to the end of
the list. The example will clarify this.

**Example**

We assume the path list is empty. PTH\_ADD flp1\_
 will add flp1\_ to the list which will now look like this (the list can
be obtained with PTH\_LIST): 0 flp1\_
 The first column is the number of the entry, programmers tend to start
counting with zero, that's why the first entry has the number 0. If you
type, for example, SPL pth1\_pth\_bin,#1

the binary file pth\_bin in flp1\_ will be spooled to channel #1
(usually a window under the interpreter). Now let's add a few more
entries to exploit the power of the path device: PTH\_ADD flp1\_basic\_
PTH\_ADD flp2\_ PTH\_ADD ram1\_
 The list is: 0 flp1\_ 1 flp1\_basic\_ 2 flp2\_ 3 ram1\_
 Assume the file myprog\_bas is in ram1\_. LOAD pth1\_myprog\_bas
 tries to load the following files one by one and skips to the next one
in case of failure: flp1\_myprog\_bas flp1\_basic\_myprog\_bas
flp2\_myprog\_bas ram1\_myprog\_bas
 If myprog\_bas does not appear in any of the directories, the usual
'Not Found' error would appear.

**NOTE 1**

The name of the path device can be freely configured with the Qjump
standard configuration program Config (or MenuConfig). We use the
default in this manual, which is PTH. The name can be changed
temporarily with PTH\_USE.

**NOTE 2**

PTH suffers from the same problem as the DEV device, see the note at
DEV\_USE.

**NOTE 3**

An underscore is added to the directory if it's missing. On this point
PTH\_ADD behaves differently from DEV\_USE.

**WARNING**

Some applications do not co-operate happily with PTH so that a file may
get spread over all directories if you save it from some editors etc.
There are no crashes, do not worry, but this strange behaviour could
lead to a loss of data if you are not aware of the strange phenomenon.

**CROSS-REFERENCE**

The path device is very similar to the `DEV <KeywordsD.clean.html#dev>`__
device, please read through `DEV\_USE <KeywordsD.clean.html#dev-use>`__ to
understand the idea behind both devices. It's pretty useful to set the
Toolkit II `DATAD$ <KeywordsD.clean.html#datad>`__ and
`PROGD$ <KeywordsP.clean.html#progd>`__ to `pth1\_ <Keywordsp.clean.html#pth1->`__:
`DATA\_USE pth1\_ <KeywordsD.clean.html#data-use20pth1->`__ `PROG\_USE
pth1\_ <KeywordsP.clean.html#prog-use20pth1->`__ Do this preferably in your
BOOT program. - Look at the other `PTH\_ <KeywordsP.clean.html#pth->`__..
style keywords!

--------------

PTH\_LIST
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_LIST [#ch]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

 The command PTH\_LIST prints a list of the search paths available to
the PTH device.

**Examples**

PTH\_LIST PTH\_LIST#2

**CROSS-REFERENCE**

`PTH$ <KeywordsP.clean.html#pth>`__ is an alternative way to get the path
list.

--------------

PTH\_RMV
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_RMV n                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

 This command removes a search path from the search list and all
directories below the removed entry are moved up in the list by one
position to fill the gap. The number n corresponds to the number in the
list produced by PTH\_LIST.

**Example**

Assume the following search list: 0 flp1\_ 1 flp1\_basic\_ 2 flp2\_ <-
to be removed 3 ram1\_
 PTH\_RMV 2
 will remove entry 2 (flp2\_), entry 3 will become entry 2 so that the
new list will be: 0 flp1\_ 1 flp1\_basic\_ 2 ram1\_
 The search list can be totally cleaned up with the following little
procedure PTH\_CLEAR: 10 DEFine PROCedure PTH\_CLEAR 20 REPeat clean\_up
30 IF PTH$(0)="" THEN EXIT clean\_up 40 PTH\_RMV 0 50 END REPeat
clean\_up 60 END DEFine PTH\_CLEAR

**CROSS-REFERENCE**

The other `PTH\_ <KeywordsP.clean.html#pth->`__... keywords

--------------

PTH\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_USE [path\_name]                                            |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

 The default name used for the path device is PTH. If you don't like
that, you can change it with PTH\_USE to any other combination of three
letters, including existing drive names. If no parameter is used, the
default name is restored.

**Examples**

PTH\_USE huh PTH\_USE flp PTH\_USE

**NOTE**

The default name can be permanently configured with Qjump's Config
program.

**CROSS-REFERENCE**

`PTH\_USE$ <KeywordsP.clean.html#pth-use>`__ returns the current setting.

--------------

PTH\_USE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_USE$                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

 As mentioned above, the function PTH\_USE$ gives you the name which is
used for the path device.

**Example**

PRINT PTH\_USE$

--------------

PTH$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH$ (n)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

 The function PTH$ returns the nth directory in the search list of the
path device.

**Examples**

The procedure PTH\_INFO prints all of the current settings concerning
the the pth device to #1. The function PTH\_ENTRIES%
 returns the number of directories in the path list. 100 DEFine
PROCedure PTH\_INFO 110 LOCal n: n=0 120 PRINT "Path device:"!PTH\_USE$
130 PRINT\\"Search paths"; 140 REPeat list\_them 150 IF PTH$(n)="" THEN
EXIT list\_them 160 IF NOT n THEN PRINT 170 PRINT FILL$("
",3-LEN(n));n;TO 5,PTH$(n) 180 n=n+1 190 END REPeat list\_them 200 IF
NOT n THEN PRINT " no entries" 210 END DEFine PTH\_INFO 220 : 240 DEFine
FuNction PTH\_ENTRIES% 250 LOCal n 260 FOR n=0 TO 32767: IF PTH$(n)=""
THEN EXIT n 270 RETurn n 280 END DEFine PTH\_ENTRIES%

**CROSS-REFERENCE**

`PTH\_ADD <KeywordsP.clean.html#pth-add>`__,
`PTH\_LIST <KeywordsP.clean.html#pth-list>`__

--------------

PTR\_FN%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_FN% (offset)                                                |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I - v2.8+)                      |
+----------+-------------------------------------------------------------------+

 The DIY Toolkit includes code which allows you to link a serial mouse
to the QL, similar to the commercial SERMouse package which is packaged
with SMSQ/E for the Gold Card. Refer to the Appendix on Mice for more
details. The mouse is enabled with PTR\_ON. This function can be used to
read various values used by the DIY mouse driver and which can be
altered using other commands from this toolkit. The value of offset
should be in the range 0...13 and returns the following: 0Latest X
position(Read with X\_PTR%) 1Latest Y position(Read with Y\_PTR%)
2Maximum X co-ordinate(Set with PTR\_MAX) 3Maximum Y co-ordinate(Set
with PTR\_MAX) 4Step X(Set with PTR\_INC) 5Step Y(Set with PTR\_INC)
6Details of buttons pressed(Read with BUTTON%) 7Synchronisation
counter(Read with SYNCH%) 8+9Zero, or serial channel ID 10Accumulated X
drift 11Accumulated Y drift 12Set = cursor key emulation(Set with
PTR\_KEY) 13Set = Pointer Wrap(Set with PTR\_KEY) The Accumulated X and
Y drift are counters, used by the serial mouse driver to judge how far
off the horizontal / vertical the mouse has moved and whether to
continue moving the pointer in a straight line or to take this into
account.

**CROSS-REFERENCE**

For more details, refer to the individual commands/ functions.

--------------

PTR\_INC
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_INC x\_step, y\_step                                        |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE (DIY Toolkit - Vol I)                                     |
+----------+-------------------------------------------------------------------+

 This command is only really of any use when the Cursor Key emulation is
enabled (see PTR\_KEY). It allows you to set the number of mouse pulses
which are taken to correspond to moving the cursor 1 character either in
an x direction or a y direction. The two values given are normally set
to 12 and 24 respectively for MODE 4 operation, although if this proves
too quick (especially in MODE 8), you could try PTR\_INC 24,24. The
higher the values, the slower the cursor will move as you push the mouse
about the table.

**CROSS-REFERENCE**

See `PTR\_KEY <KeywordsP.clean.html#ptr-key>`__ and also compare
`SERMSPEED <KeywordsS.clean.html#sermspeed>`__.

--------------

PTR\_KEY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_KEY cursor, edge                                            |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE (DIY Toolkit - Vol I)                                     |
+----------+-------------------------------------------------------------------+

 Normally DIY Toolkit's mouse driver will enable you to control the
mouse pointer on screen. This mouse pointer is however, not the one used
by the Pointer Environment (therefore the mouse cannot be used to
control programs written specifically for the Pointer Environment except
in cursor emulation mode) and you need a separate program to run in the
background which will display a symbol to show the position of the mouse
on screen. However, this command allows you to specify whether the
serial mouse driver should emulate the cursor keys (instead of the
pointer), which allows it to operate software such as word processors.
To emulate the cursor keys, cursor should be 1 - to emulate the pointer
again, set cursor to 0. The DIY Toolkit mouse driver is actually better
than the SERMouse driver in this respect in that the mouse does not
automatically switch back into Pointer Mode when you leave the program
(see SERMCUR). Then again, you cannot switch between the two modes using
the mouse buttons, or control Pointer Environment programs... The second
parameter expected by this command is used to specify what should happen
to the cursor (or pointer) at the edge of the screen - if edge=1, moving
the cursor or pointer over the edge of the screen will make it re-emerge
on the opposite edge (a wrapping effect). edge=0 disables this.

**CROSS-REFERENCE**

See `PTR\_INC <KeywordsP.clean.html#ptr-inc>`__ also. Also see
`PTR\_ON <KeywordsP.clean.html#ptr-on>`__ and
`SERMPTR <KeywordsS.clean.html#sermptr>`__

--------------

PTR\_LIMITS
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_LIMITS minx, miny, maxx, maxy                               |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS (v3.20+)         |
+----------+-------------------------------------------------------------------+

 This command is used to set the limits of the screen over which the
mouse pointer can be moved using the mouse. The command expects four
parameters, the minimum x and y co- ordinates and the maximum x and y
co-ordinates. For a standard QL, you would normally set these values
with: PTR\_LIMITS 0,0,511,255
 However, on larger resolution displays, larger limits will be needed.
On the DIY Toolkit variant, the first two limits are ignored (they are
always taken to be zero). The maximum co- ordinates should be in pixel
sizes and can be any positive number up to 32767. On Amiga QDOS,
negative numbers can be used, but to retain compatability, the first two
parameters should be zero. Having set these parameters, once the mouse
pointer has reached this position on screen then what happens depends on
whether the wrap-around display mode has been enabled with PTR\_KEY 0,1
or PTR\_KEY 1,1 (or not). If it has been disabled, then the mouse
pointer will move no further. If it has been enabled, then the mouse
pointer will appear at the other extreme limit.

**CROSS-REFERENCE**

`PTR\_POS <KeywordsP.clean.html#ptr-pos>`__ can be used to dictate where the
mouse pointer should appear on screen. This command only calls
`PTR\_MAX <KeywordsP.clean.html#ptr-max>`__ on the DIY implementation.

--------------

PTR\_MAX
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_MAX maxx, maxy                                              |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

 This command is the same as: PTR\_LIMITS 0,0,maxx,maxy

**CROSS-REFERENCE**

See `PTR\_LIMITS <KeywordsP.clean.html#ptr-limits>`__!

--------------

PTR\_OFF
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_OFF                                                         |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

 This command switches off the mouse driver, releasing memory which is
used by it for temporary shortage. PTR\_ON switches the driver back on.

**CROSS-REFERENCE**

This is similar to `SERMOFF <KeywordsS.clean.html#sermoff>`__.

--------------

PTR\_ON
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_ON                                                          |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

 This command enables the mouse driver after it has been loaded or after
it has been disabled with PTR\_OFF. All of the mouse settings are reset
to the defaults (set when the files were originally assembled) and the
pointer is positioned in the top left corner of the screen (position
0,0).

**CROSS-REFERENCE**

You can re-position the mouse with
`PTR\_POS <KeywordsP.clean.html#ptr-pos>`__. See
`SERMON <KeywordsS.clean.html#sermon>`__ and
`PTR\_OFF <KeywordsP.clean.html#ptr-off>`__.
`PTR\_INC <KeywordsP.clean.html#ptr-inc>`__,
`PTR\_KEY <KeywordsP.clean.html#ptr-key>`__ and
`PTR\_MAX <KeywordsP.clean.html#ptr-max>`__ are also needed to set various
parameters on start-up.

--------------

PTR\_POS
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_POS x,y                                                     |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

 This command can be used to set the initial position of the mouse
pointer on screen - it is normally located at 0,0 (the top left hand
corner of the screen). You can however use this command to set it to the
specified absolute pixel co- ordinates, which must be within the area
defined with the PTR\_LIMITS command.

**CROSS-REFERENCE**

See `PTR\_LIMITS <KeywordsP.clean.html#ptr-limits>`__ and
`PTR\_ON <KeywordsP.clean.html#ptr-on>`__. The pointer position can be read
with `X\_PTR% <KeywordsX.clean.html#x-ptr>`__,
`Y\_PTR% <KeywordsY.clean.html#y-ptr>`__ and
`PTR\_FN%. <KeywordsP.clean.html#ptr-fn.>`__

--------------

PTR\_X
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_X (argument, module)                                        |
+----------+-------------------------------------------------------------------+
| Location |  PTRRTP                                                           |
+----------+-------------------------------------------------------------------+

 The function PTR\_X transforms a point (described in polar
co-ordinates) into the rectangular co-ordinates and returns the real
part of the latter. argument is an angle in radians, module a radius.

**Example**

A line in rectangular co-ordinates transformed to polar co- ordinates
looks like a circle when plotted on screen. However, if you were to look
at this line using polar co-ordinates, it would appear as straight line
again. Confused? 100 SCALE 10,-5,-5: PAPER 0: CLS 110 FOR a = 0 TO 2\*PI
STEP PI/128 120 POINT PTR\_X(a,2), PTR\_Y(a,2) 130 END FOR a

**CROSS-REFERENCE**

The other rectangular co-ordinate is found with
`PTR\_Y <KeywordsP.clean.html#ptr-y>`__ below. Also see
`RTP\_R <KeywordsR.clean.html#rtp-r>`__ and `RTP\_T <KeywordsR.clean.html#rtp-t>`__

--------------

PTR\_Y
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_Y (argument, module)                                        |
+----------+-------------------------------------------------------------------+
| Location |  PTRRTP                                                           |
+----------+-------------------------------------------------------------------+

 This function is very similar to PTR\_X but this time the imaginary
part is returned.

--------------

PURGE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PURGE                                                            |
+----------+-------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                      |
+----------+-------------------------------------------------------------------+

 The command PURGE has the same (fatal) effect as KILL or KJOBS.

--------------

PUT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  PUT [#channel\\file\_position,] [item\ :sup:`1` :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ...] or PUT [#channel,] [item\ :sup:`1` :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ...] |
+----------+-------------------------------------------------------------------+
| Location |                                                                   |
+----------+-------------------------------------------------------------------+

Toolkit II, THOR XVI
 This command forms the complement to GET and allows you to store
variables in the specified channel (default #3) in the QL's internal
format. The variables are stored at the current position in the file (or
the file\_position given with the command, if the first variant is
used). If you provide more than one variable name as the second, third
parameter etc, then several variables will be stored in the file in one
go. If no variable is specified, the file pointer will be set to the
specified position if the first variant is used. If the second variant
is used, this will have no effect. If a variable is given as the file
pointer, then this variable will be updated with the current file
position once PUT has finished its work. PUT can actually be used to
store variables in a different type to their current use (this might,
for example, be useful if storing part of a string), by adding the
following suffixes to each item: ...+0Force floating point type (see
note 2 below!) ...&''Force string type ...\|\|0Force integer type

**Example**

a$='Entry 123':PUT #3,a$,a$(7 TO) \|\| 0
 will store in channel #3 two bytes giving the length of the string a$,
followed by the characters of the string itself, followed by two bytes
representing the integer value 123 (ie. 0\*256+123).

**NOTE 1**

On version 2.09 (or earlier) of Toolkit II, PUT could cause problems
when used on a channel opened over the network.

**NOTE 2**

Although PUT can convert variable types as above, if integer
tokenisation is enabled on Minerva, then PUT x%+0 will not work. You
need to use something such as PUT x%+1e-555 instead.

**NOTE 3**

Whenever storing data on disk, it is always preferable to store it in
its internal format (unless it is to be read on other systems as well).
Internal storage is faster because conversion between internal and
readable format is no longer necessary. It also produces shorter files
since the internal format needs less space and for floating point
numbers, the internal format gives the greatest possible accuracy.

**CROSS-REFERENCE**

See `PUT <KeywordsP.clean.html#put>`__, `BPUT <KeywordsB.clean.html#bput>`__,
`WPUT <KeywordsW.clean.html#wput>`__, `LPUT <KeywordsL.clean.html#lput>`__,
`UPUT <KeywordsU.clean.html#uput>`__ and `GET <KeywordsG.clean.html#get>`__.

--------------

PXOFF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PXOFF                                                            |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This command is the same as PIE\_EX\_OFF except for the PEX system
extension - it disables PEX for SD.EXTOP system calls, so that they are
trapped by the Pointer Environment.

**CROSS-REFERENCE**

See `PXON <KeywordsP.clean.html#pxon>`__ and\ `PEON <KeywordsP.clean.html#peon>`__.

--------------

PXON
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PXON                                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This command is the same as PIE\_EX\_ON except for the PEX system
extension - it enables PEX for SD.EXTOP system calls, so that they can
work in the background.

**CROSS-REFERENCE**

See `PXOFF <KeywordsP.clean.html#pxoff>`__
and\ `PEON <KeywordsP.clean.html#peon>`__.

--------------

PX1ST
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PX1ST [{ flag }]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

 This function can be used to determine whether IS\_PTRAP has been used
to dictate that any screen operations should just be ignored (this is
the default under PEX on JS and MG ROMs). If the value returned is 0,
then (providing that you do not have a JS or MG ROM), PEX may be
allowing background screen access. If the value is not 0, then screen
operations are merely ignored by the operating system (and therefore the
display is not affected). If you use this function to pass a parameter,
then if the parameter is 0, then screen operations will not be ignored
and whether they cause a Buried program to halt will depend on whether
PEX is active. If you pass a non-zero parameter, then any screen
operations will be ignored.

**CROSS-REFERENCE**

See `PEON <KeywordsP.clean.html#peon>`__ and in particular, refer to
`IS\_PTRAP <KeywordsI.clean.html#is-ptrap>`__ for more details. See also
`IS\_PEON <KeywordsI.clean.html#is-peon>`__.

--------------

P\_ENV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  P\_ENV (#ch)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  MULTI                                                            |
+----------+-------------------------------------------------------------------+

 This function detects whether the given channel is running under the
Pointer Environment and returns: 0if the Pointer Environment is not
connected to that channel, or no parameter was used, or #ch is not a
screen channel; or 1if the Pointer Interface (ptr\_gen) is active in
that channel; or 2if the Pointer Interface and the Window Manager (wman)
are present for that channel.

**Example**

All programs which need the Pointer Environment to work, should check to
see if it is present. This short program does so: 100
ch=FOPEN(con\_2x2a0x0): p=P\_ENV(#ch): CLOSE#ch 110 IF p<2 THEN 120
PRINT "This program does not run without the P.E.," 130 PRINT "so
program execution has to stop here." 140 PRINT " Press any key...":
PAUSE 400 150 STOP 160 END IF

**CROSS-REFERENCE**

`WMAN$ <KeywordsW.clean.html#wman>`__ finds the version of the Window Manager
and `QRAM$ <KeywordsQ.clean.html#qram>`__ the version of the Pointer
Interface. These functions can also be used to detect the presence of
the Pointer Environment (=Window Manager & Pointer Interface).
