
==========
Keywords T
==========

TODO
====

- This file references EXTERNAL, QCONNECT. They doesn't exist.


..  _tan:

TAN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TAN (angle) angle <> (2n+1) \* PI/2 (n=0,1,2,...)                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function calculates the tangent of an angle given in radians. The
solution of TAN(PI/2) is not actually defined because the definition of
TAN is TAN(x)=SIN(x)/COS(x) and COS(PI/2)=0. In practice, most ROM
implementations will return a value of about 1E10 instead of an error
because they calculate COS(PI/2)<>0. Due to the periodic nature of this
function function, values for angle should really be in the range -PI/2
< angle < PI/2.

**Example**

::

    100 WINDOW 448,200,32,16: PAPER 3: CLS 
    110 SCALE 8,-.2,-.2: INK 7 
    120 INPUT "Angle (0..90):"!angle 
    130 INPUT "Speed (..11 m/s):"!speed 
    140 angle=RAD(angle): c1=TAN(angle) 
    150 c2=9.81 / 2 / speed^2 / COS(angle)^2
    160 : 
    170 FOR x=0 TO c1/c2 STEP c1/c2/20 
    180   y=c1 * x - c2 * x^2 
    190   FILL 1: CIRCLE x,y,.2: FILL 0 
    200 END FOR x

**NOTE 1**

TAN(PI)==0 on all implementations - this should be zero. Only SMS
currently corrects this.

**NOTE 2**

On Minerva v1.96+ large values of angle return 0. On other ROMs it
produces an overflow error.

**CROSS-REFERENCE**

:ref:`sin`, :ref:`cos`,
:ref:`cot`, :ref:`asin`,
:ref:`acos`, :ref:`atan` and
:ref:`acot` are other common trigonometrical
functions. :ref:`rad` converts degrees into radians,
:ref:`deg` vice-versa. Please also refer to the
Mathematics section of the Appendix.

--------------


..  _tanh:

TANH
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TANH (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Hyper, Hyperbola                                                 |
+----------+-------------------------------------------------------------------+

This function is analogous to the tangent (TAN) - the hyperbolic
tangent (TANH) is the hyperbolic sine divided by the hyperbolic cosine::

    TANH(x) = SINH(x) / COSH(x)
    
resulting in the following formula (if SINH and COSH are replaced by
their definitions)::

    TANH(x) = (EXP(x) - EXP(-x)) / (EXP(x) + EXP(-x))

**CROSS-REFERENCE**

:ref:`artanh` is the inverse function of
:ref:`tanh`, :ref:`coth` a
complementary function to :ref:`tanh`.

--------------


..  _tca:

TCA
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TCA (i,n)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function TCA returns the value of: i/(1-(1+i)\ :sup:`-n`)
where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`vfr`, :ref:`var`,
:ref:`tnc`, :ref:`tee`,
:ref:`rae`, :ref:`rafe`

--------------


..  _tconnect:

TCONNECT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TCONNECT #pipechan TO #anychan                                   |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Pipes are serial devices for buffered data transfer, they have two
sides: 

- The input pipe which puts any data into the buffer until it's full and;
- the output pipe which reads the data from the buffer::

    input pipe ---> buffer ---> output pipe 
    
There are two kinds of pipes on the QL: 

- Standard pipes are part of the original QL ROM, the input pipe
  device name is pipe\_<buffer> where <buffer> is the buffer size in bytes
  (1..32767). It is necessary to know the CHANID of the input pipe to open
  the output pipe, see FILE\_OPEN. 

- The second type are named pipes which
  have the same concept except that the output pipe can be identified by 
  name: The input pipe is pipe\_<name>\_<buffer> and the output pipe
  pipe\_<name>. See the Appendix on Device Drivers regarding Pipes for
  more information. 

TCONNECT makes standard pipes useable: the command
expects two opened channels where the first, #pipechan, must be an input
pipe and the second, #anychan can be anything. TCONNECT changes the
internal meaning of #anychan so that it becomes an output pipe connected
to the input pipe #pipechan: 

Before TCONNECT:: 

    #pipechan -> input pipe -> buffer scr_2x2 <- #anychan
    
After TCONNECT::

    #pipechan -> input pipe -> buffer -> output pipe -> #anychan

**Example**

DEVLIST$ returns the devices listed by DEVLIST in a string, separated by
spaces. ISDEVICE takes a device and checks with the help of DEVLIST$ if
it is a legal device::

    100 DEFine FuNction DEVLIST$ 
    110   LOCal list$,dev$: list$="" 
    120   OPEN#3,pipe_80 
    130   OPEN#4,scr_ 
    140   TCONNECT #3 TO #4 
    150   DEVLIST#3 
    160   INPUT#4,dev$\dev$ 
    170   REPeat read_devs 
    180     IF NOT PEND(#4) THEN EXIT read_devs 
    190     INPUT#4,dev$ 
    200     list$=list$&" "&dev$ 
    210   END REPeat read_devs 
    220   CLOSE#3: CLOSE#4 
    230   RETurn list$ 
    240 END DEFine DEVLIST$

A legal drive device consists of three letters (the device name), a
drive number (1..8) and an underscore:: 

    250 :
    260 DEFine FuNction ISDEVICE(dev$) 
    270   IF LEN(dev$)<>5 THEN RETurn 0 
    280   IF dev$(5)<>"_" THEN RETurn 0 
    290   IF dev$(4)<"1" OR dev$(4)>"8" THEN RETurn 0 
    300   IF NOT (dev$(1 TO 3) INSTR DEVLIST$) THEN RETurn 0 
    310   RETurn 1 
    320 END DEFine ISDEVICE

**CROSS-REFERENCE**

See :ref:`file-open`,
:ref:`chanid`, pipes and
especially :ref:`pend`. Some more examples appear at
:ref:`file-len` and
:ref:`fupdt`. :ref:`qlink` is
the same. Qliberator gives the :ref:`qconnect`
command which is the same.

--------------


..  _tee:

TEE
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TEE (i,n)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function TEE returns the value of (1+(i/n)\ :sup:`n`-1)
where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`vfr`, :ref:`var`,
:ref:`tca`, :ref:`tnc`,
:ref:`rae`, :ref:`rafe`

--------------


..  _then:

THEN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  THEN [statement] :sup:`\*`\ [:statement]\ :sup:`\*`              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This keyword is optional and is used as part of the IF..END IF
structure. It has no use on its own.

**CROSS-REFERENCE**

See :ref:`if`.

--------------


..  _thing:

THING
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  THING (thingname$)                                               |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This function is used to check whether a Thing is present in memory
(ie. whether a given item appears on the Thing list). If the Thing is
present, then the function will return 0, otherwise it will return -7
(not found).

**Examples**

::

    PRINT THING('Button_sleep') 
    PRINT THING('HOTKEY')

**NOTE**

In versions earlier than v1.02, this function may sometimes return a
value greater than zero if the Thing exists.

**CROSS-REFERENCE**

:ref:`th-ver-dlr` explains what Things are.

--------------


..  _th-fix:

TH\_FIX
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TH\_FIX                                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E and ST/QL Level B-11 drivers onwards                      |
+----------+-------------------------------------------------------------------+

This command fixes some programs which were written before the current
Thing List was standardised (in the Level B-10 drivers for the ST/QL
Emulator) and allows them to work under current versions by adopting the
old style Thing List. You should really update the problem program.

--------------


..  _th-ver-dlr:

TH\_VER$
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TH\_VER$ (thingname$)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

Things in QDOS terms refer to an extension of QDOS which was introduced
by the Thing System provided by Qjump's Extended Pointer Interface and
was also implemented (although slightly differently) on the THOR XVI
computer. It is an universal storage method for named resources. 

A Thing
List is created by the Thing System which lists all of these named
resources, which can range from a piece of machine code to a printer
driver (and much more). The idea is that any program which wants to
access a specified utility or driver need only search in this list to
see if the Thing is installed in the current system, and then pointers
contained in this list allows the program to access the Thing (if
available). 

Each Thing can be useable by several users at the same time
or can be restricted so that it can only be accessed if nothing else is
using it. Things are identified by their name and have a version number
which is returned by the function TH\_VER$. The version number of a
Thing can be something like 1.03, or it can actually be representative
of the functions provided in this version (eg. 1001100) - although it is
not certain if this second type of 'version number' will be correctly
returned by the current version of TH\_VER$, since at the time of
writing we have not come across anything which uses this. 

If a Thing was
not found in memory or another error occurred, TH\_VER$ will return the
standard error code (see ERNUM).

**Example**

The Hotkey System (HOT\_REXT), a part of the Extended Pointer
Environment (regarded as standard today), is installed as a Thing. Get
its version with::

    PRINT TH_VER$ ("HOTKEY")

**NOTE 1**

In versions prior to version 1.02, this function could return the wrong
value for some Things.

**NOTE 2**

The current version of this command will not work on a THOR XVI
computer.

**CROSS-REFERENCE**

:ref:`thing`, :ref:`th-fix`.

--------------


..  _tiny-ext:

TINY\_EXT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  TINY\_EXT                                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command installs/updates the extensions provided by the Tiny
Toolkit. TinyToolkit and Toolkit II have some commands in common (eg.
REPORT). If you prefer to use Toolkit II's REPORT command you will
generally need to install TK2\_EXT after TINY\_EXT (on post JM ROMs the
Toolkit which was installed second will have priority!). Prior to JS
ROMs, the first version of a command loaded as a toolkit has priority.

**NOTE**

Updating TinyToolkit is different from updating other Toolkits with
\_EXT type commands, in that TinyToolkit simply adds its commands' names
to the name list and does not check to see if they were already present.
SXTRAS and EXTRAS will list commands twice (or more) and each time that
TINY\_EXT is issued, memory will be used up (max. 1 KB). Actually, the
Toolkit is only present in one place in memory because duplicated
commands are stored at the same place in RAM. This problem can be cured
with TINY\_RMV.

**CROSS-REFERENCE**

:ref:`tk2-ext` updates Toolkit II,
:ref:`beule-ext` the Beule Toolkit.
:ref:`tiny-rmv` removes most extensions of
TinyToolkit from the name list.

--------------


..  _tiny-rmv:

TINY\_RMV
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  TINY\_RMV                                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command removes most of TinyToolkit's commands.

**NOTE**

You should not really use TINY\_RMV because the extensions are not
removed from the Name List but overwritten with undefined strings.
Depending on the operating system and programming environment it may not
be possible to re-activate TinyToolkit and internal system conflicts are
possible.

**CROSS-REFERENCE**

Re-activate the Toolkit with :ref:`tiny-ext`.

--------------


..  _tk2-ext:

TK2\_EXT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TK2\_EXT                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

As with other Toolkits, Toolkit II has to be linked into the computer
(except on the ST/QL Emulator and under SMSQ/E where it is automatically
linked in when the computer is started). This command forces all of the
Toolkit II commands to link themselves into the operating system,
overwriting existing definitions of any commands with the same name.

**NOTE**

TK2\_EXT contains special code to enable Toolkit II commands to be used
on JM (and earlier) ROMs in the same program as the TK2\_EXT command.

**CROSS-REFERENCE**

See :ref:`tiny-ext`.

--------------


..  _tk-ver-dlr:

TK\_VER$
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TK\_VER$                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns the version ID of the Turbo Toolkit, eg. 3e27

**NOTE**

Before v3.00 the Turbo Toolkit did not install properly under Minerva
and SMS.

--------------


..  _tnc:

TNC
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TNC (i,n)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function TNC returns the value of: n\*((1+i)\ :sup:`1/n`-1)
where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`vfr`, :ref:`var`,
:ref:`tca`, :ref:`tee`,
:ref:`rae`, :ref:`rafe`

--------------


..  _to:

TO
==

+----------+-------------------------------------------------------------------+
| Syntax   || ... TO line (GO TO) or                                           |
|          || TO column (Separator)                                            |
+----------+-------------------------------------------------------------------+
| Location ||  QL ROM                                                          |
+----------+-------------------------------------------------------------------+

This keyword has two uses. The first syntax operates as part of the
keyword GO TO. The second syntax is used as a separator in the commands
PRINT and INPUT (and also in some toolkit extensions). We shall only
deal with the use of TO for PRINT and INPUT here. 

As a separator, TO can
be very useful for placing data into columns. Its effect is to place the
text cursor onto the specified column, or if the text cursor is already
at or past that column, then the text cursor is moved one column to the
right. This means for instance that:: 

    PRINT TO 0

will always leave the leftmost column blank! 

TO is also affected by the
WIDTH setting on non-screen devices. If the specified column is greater
than the WIDTH
value, the text cursor will be placed onto the next line. On screen
devices, if the specified column is too great to fit in the window, the
text cursor is placed onto the next line rather than causing an error -
note however, that TO carries on counting!!. 

TO has no meaning on its
own and will cause the error 'Bad Line' if entered on its own.

**NOTE**

On the THOR XVI, if the cursor is already at or past the given column,
the text cursor is not moved, in contrast to all other implementations.
Programs compiled with Turbo will however display the text as per the
standard QL implementation.

**CROSS-REFERENCE**

See :ref:`go--to` and
:ref:`print`, :ref:`input`.
:ref:`at` and :ref:`cursor` allow
you to position the text cursor more precisely.

--------------


..  _top-window:

TOP\_WINDOW
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  TOP\_WINDOW [#ch]                                                |
+----------+-------------------------------------------------------------------+
| Location |  all THORs                                                        |
+----------+-------------------------------------------------------------------+

This command is similar to the PICK command provided by Qjump's QPTR
package on the QL. This command brings the specified window (default #1)
to the top of the display pile. Under the THOR's windowing system (when
this is enabled), as with the Pointer Environment, a program cannot
access a window which is partly or fully hidden from view. This command
allows the program to force the given window to the top of the pile,
thus allowing it to be seen on screen and therefore open to access. If
possible, the keyboard queue is also connected to the window, so it is
as if the Job has been 'picked' using the keys CTRL C.

**CROSS-REFERENCE**

:ref:`window` allows you to re-position a window.
:ref:`pie-on` allows programs to continue even
though their windows are buried under the Pointer Interface.
:ref:`pick-pct` is similar. :ref:`poke` SYS\_VARS+133 allows you to
enable / disable the THOR's windowing system.

--------------


..  _tpfree:

TPFree
======

+----------+-------------------------------------------------------------------+
| Syntax   |  TPFree                                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function TPFree returns a slightly larger or equal value than FREE
and FREE\_MEM. The reported free memory is available for new jobs.

--------------


..  _tra:

TRA
===

+----------+-------------------------------------------------------------------+
| Syntax   || TRA table1 [,table2] or                                          |
|          || TRA [table1] ,table2                                             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM (post JM Version)                                         |
+----------+-------------------------------------------------------------------+

This command allows you to perform various translations on data that is
passing through the serial ports. It is however one of the most
difficult commands in SuperBASIC to use. 

The use of TRA will (on non-SMS
implementations) affect all data which is sent through the serial ports
after the command has been issued, translating bytes whether they are
screen dumps, printer control codes, or letters of the alphabet. 

The two
parameters are addresses of two tables, table1 which contains details of
translations to be carried out on both incoming and outgoing data and
table2 which contains details of various messages used by the system.
Both tables are recognised by the word 19195 ($4AFB) at their start. If
either parameter is not specified, then the default value of -1 is
assumed, which tells QDOS to leave that translation table alone. 

When
QDOS is first initiated translation is not enabled, which means that
data passing through the serial ports is unaffected. You can revert to
this situation by using the command TRA 0. You can also revert to the
original error messages with TRA ,1 (use TRA 0,1 to reset both to their
original status). The English character set is used in all ROM
implementations of the QL (no matter which country the machine is set up
for). However, you can select to use the 'local' character set for
serial communication purposes if you wish by using the command TRA 1
which tells QDOS to use the 'local' translation table (this has no
effect on UK ROMs). 

The two translation tables have different formats
and uses, depending on whether the serial ports are being used for
transmission or receipt of data. We therefore deal with each table
separately. Note that TRA is implemented differently on THORs and SMS
see the separate notes on the makeup of their translation tables.

**Table 1**


Table 1 is actually split into two lists: 

- Transa contains a list of single character conversions;
- Transb which contains a list of multiple character conversions. 

As to which list is used depends on whether the
channel is sending or receiving data: 

1. If the channel is sending data, the outgoing character is first translated 
   according to Transa, using the character code as an index. If the resulting 
   value is a zero, Transb
   is scanned for the proper entry. However, if the resulting value is
   non-zero, then this is used as a replacement for the byte to be sent.

2. When receiving, only Transa is used. The table is scanned cyclically
   starting at the received character's position until a position is found
   containing the received value. The translated value will be this
   position index. If the received value is not found in the table, the
   value itself is used. 

The physical format of table1 is as follows:

::

    Table1 Word      19195 
           Word      Offset of Transa from Table1 (Transa-Table1) 
           Word      Offset of Transb from Table1 (Transb-Table1) 
           
    Transa 256 bytes (see below) 
    Transb Byte      Number of multiple translations or 0 x bytes(see below) 

Transais a 256 byte list of character substitute codes for each character code from 0 to 255. 
If you wish to use multiple translates for a given character, then you will
need to insert 0 in the appropriate place in this list. 

Transb is a
table of multiple translations (which can only be used in transmit
mode). It is made up of four bytes for each translate, being the code to
be translated, followed by three replacement codes. If you do not need
three replacement codes, the unused ones should be zero. Unfortunately,
you cannot combine the effects of these various translations (see the
second example below).

**Table 2**

Table 2 allows you to set the various system and error messages used by
QDOS (for example to implement other languages). The format of Table2 is
even more complex::

    Table2  Word      19195
            Word      Offset of error1 from Table2 (error1-Table2) 
            Word      Offset of error2 from Table2 (error2-Table2) 
            ....
            Word      Offset of error20 from Table2 (error20-Table2) 
            Word      Offset of error21 from Table2 (error21-Table2) 
            Word      Offset of mess1 from Table2 (mess1-Table2) 
            Word      Offset of mess2 from Table2 (mess2-Table2) 
            ....
            Word      Offset of mess7 from Table2 (mess7-Table2) 
            Word      Offset of mess8 from Table2 (mess8-Table2) 
            
    error1  Word      Length of string 
            Bytes     String forming message for 'not complete' 
            
    error2  Word      Length of string 
            Bytes     String forming message for 'invalid job' 
            
            ....
            
    error21 Word      Length of string 
            Bytes     String forming message for 'Bad Line' 
            
    mess1   Word      Length of string 
            Bytes     String to replace 'At line ' (***)
            
    mess2   Word      Length of string 
            Bytes     String to replace ' sectors'
            
    mess3   Word      Length of string 
            Bytes     String to replace 'F1 .. monitor F2 .. TV ' (***)
            
    mess4   Word      Length of string 
            Bytes     String to replace '© 1983 Sinclair Research Ltd' (***)
            
    mess5   Word      Length of string 
            Bytes     String to replace 'during WHEN processing'
            
    mess6   Word      Length of string 
            Bytes     String to replace 'PROC/FN cleared'
            
    mess7   Bytes     String to replace 'SunMonTueWedThuFriSat' (***)
    
    mess8   Bytes     String to replace 'JanFebMarAprMayJunJulAugSepOctNovDec' (***)

Please note that all strings other than those marked (\*\*\*) *must* end with
a newline, CHR$(10). 

Also please also note the differing format of mess7 and mess8. 

Although the THOR computers support both of the above table
formats, the THOR has extended the usefulness of TRA in order to allow
you to send longer strings of characters for each translation. On the
other hand, SMS has implemented a different way of amending the messages
generated by the operating system (see below). Examples of the standard
format follow:

**Example 1**

A program to change all of the error messages to more meaningful
messages::

    100 Chk$=VER$ 
    105 IF Chk$='AH' OR Chk$='JM': PRINT'Not supported' 
    110 table2=ALCHP(1024) 
    120 RESTORE 
    130 POKE_W table2,19195 
    140 mess_add=table2+30*2 
    150 FOR errx=1 TO 29 
    160 POKE_W table2+errx*2,mess_add-table2 
    170 READ mess$ 
    180 IF errx<28 
    190 SELect ON errx: =1 TO 21,23,26 TO 27: mess$=mess$&CHR$(10) 
    200 POKE_W mess_add,LEN(mess$): mess_add=mess_add+2 
    210 END IF 
    220 FOR move_mess=1 TO LEN(mess$) 
    230 POKE mess_add,CODE(mess$(move_mess)): mess_add=mess_add+1 
    240 END FOR move_mess 
    250 overf=mess_add/2:IF overf<>INT(overf): mess_add=mess_add+1 
    260 END FOR errx 
    270 TRA 0,table2 
    280 DATA 'Operation Not Complete' 
    290 DATA 'Job Does Not Exist'
    300 DATA 'Insufficient Memory' 
    310 DATA 'Parameter Outside Permitted Range' 
    320 DATA 'Buffer Full' 
    330 DATA 'Channel Not Open' 
    340 DATA 'File or Device Not Found' 
    350 DATA 'File Already Exists' 
    360 DATA 'File or Device In Use' 
    370 DATA 'End of File' 
    380 DATA 'Drive Full' 
    390 DATA 'Invalid File or Device Name' 
    400 DATA 'Transmit Error' 
    410 DATA 'Format Failed' 
    420 DATA 'Invalid Parameter' 
    430 DATA 'Filing System Medium Check Failed' 
    440 DATA 'Invalid Expression' 
    450 DATA 'Maths Overflow' 
    460 DATA 'Operation Not Implemented' 
    470 DATA 'Read Only Device' 
    480 DATA 'Invalid Syntax' 
    490 DATA 'At line ' 
    500 DATA ' sectors' 
    510 DATA 'F1 .. monitor'&CHR$(10)&'F2 .. TV' 
    520 DATA '©1983 Sinclair Research Ltd.' 
    530 DATA 'During WHEN processing' 
    540 DATA 'PROC/FN Definition Cleared' 
    550 DATA 'SunMonTueWedThuFriSat' 
    560 DATA 'JanFebMarAprMayJunJulAugSepOctNovDec'

**Example 2**

A short program to allow you to print pound signs (£) from SuperBASIC
(this assumes an Epson compatible printer which is set up in US ASCII
mode)::

    100 table1=ALCHP(1024) 
    110 POKE_W table1,19195 
    120 Transa=table1+6 
    130 Transb=Transa+256 
    140 FOR i=0 TO 255:POKE Transa+i,i 
    150 POKE_W table1+2,Transa-table1 
    160 POKE_W table1+4,Transb-table1 
    170 POKE Transb,3 
    175 POKE Transa+128,0: POKE Transa+129,0: POKE Transa+CODE('£'),0 
    180 POKE Transb+1,128 
    190 POKE Transb+2,27: POKE Transb+3,CODE('R'): POKE Transb+4,3 
    200 POKE Transb+5,129 
    210 POKE Transb+6,27: POKE Transb+7,CODE('R'): POKE Transb+8,0 
    215 POKE Transb+9,CODE('£') 
    216 POKE Transb+10,128: POKE Transb+11,CODE('#'): POKE Transb+12,129 
    220 TRA table1,0  

Unfortunately, despite lines 215 and 216, the command::

    OPEN #3,ser1: PRINT #3,'£'
    
will still fail to produce a pound sign on your printer (you will get a
single quote mark normally). 

This demonstrates the fact that you cannot
link translates. To get a pound sign, you will need to use the line::

    OPEN #3,ser1: PRINT#3,CHR$(128) & '£' & CHR$(129)

Indeed, because of the nature of the translation tables, the following
has exactly the same effect as the above program:: 

    100 table1=ALCHP(1024) 
    110 POKE_W table1,19195 
    120 Transa=table1+6 
    130 Transb=Transa+256 
    140 FOR i=0 TO 255:POKE Transa+i,i 
    150 POKE_W table1+2,Transa-table1 
    160 POKE_W table1+4,Transb-table1 
    170 POKE Transb,2 
    180 POKE Transa+128,0:POKE Transa+129,0 
    190 POKE Transa+CODE('£'),CODE('#') 
    200 POKE Transb+1,128 
    210 POKE Transb+2,27: POKE Transb+3,CODE('R'):POKE Transb+4,3 
    220 POKE Transb+5,129 
    230 POKE Transb+6,27: POKE Transb+7,CODE('R'):POKE Transb+8,0 
    240 TRA table1,0

**NOTE 1**

An extended serial driver is available in the public domain which
enables Minerva machines and Amiga QDOS to use a translation table the
same as the extended translation table provided on the THOR XVI.

**NOTE 2**

On Minerva ROMs (v1.83 or earlier), there are problems when using TRA
with only one parameter.

**NOTE 3**

JS ROMs have problems in translating characters above CHR$(127)

**SMS NOTES**

SMS supports the standard format table1. However, the messages cannot be
altered using table2 - use LANG\_USE for this. As with the original
version, if table1 is specified to be 0, this will deactivate the
translation. However, it does not smash the pointer to a user-defined
translation routine which can then be re-activated with TRA 1 (compare
the original version where you would need to re-run the program setting
up the user-defined translation table). 

SMS also allows you to have
language dependent translation tables (linked to one of the languages
currently loaded - see LANG\_USE). To enable these, use the command::

    TRA 1,lang
    
where lang is the Car Registration Code or Language code of the
country. 

::

    TRA 0,lang
    
will set up the relevent translation table, ready to be enabled with
TRA 1. 

There are also several in-built language independent translate
tables which are accessed by setting table1 to small values. The
dip-switches on your printer need to be set to USA. Currently there are
only two language independent translate tables supported (so far as we
are aware): 

- The command TRA 3 will enable IBM Graphics translation table:

    - QDOS CHR$(HEX('C0')) to CHR$(HEX('DF')) and 
      CHR$(HEX('F0')) to CHR$(HEX('FF')) are passed through the channel unchanged.
    - CHR$(HEX('E0')) to CHR$(HEX('EF')) are translated to represent CHR$(HEX('B0')) to
      CHR$(HEX('BF')) respectively. 
    - As from v2.50, the paragraph sign, CHR$(HEX('15')) is also passed through unaffected. 


- The command TRA 5 will enable GEM VDI translation table:

    - Here QDOS CHR$(HEX('C0')) to CHR$(HEX('FF')) are passed through the port unchanged. 

Also please note that under SMS, TRA will only affect
channels which are OPENed after the TRA command, or channels which have
already been OPENed with TRA active. In any case, TRA 0
never affects OPEN channels. TRA address will also not affect OPEN
channels which have been affected by TRA 0. Note however that changing
the BAUD rate will affect the translate on ALL channels.

**SMS Example**

::

    TRA 1: REMark Enable translate table for Country set up by default. 
    TRA 1,F: REMark Enable French Translation table.
    TRA 0: REMark Disable Translate Tables. 
    TRA 1: REMark Re-enable French Translation Table

**THOR XVI NOTES**

The THOR XVI supports both the standard translation format above and
also an expanded Translation Table, which replaces Table1 by a larger
table in the following format:

**Thor Table1**

The format of the new expanded Translation Table is::

    Table1  Longword  $4AFB0001 Distinguishes the new table from the old one. 
            Word      Offset of Transa from table1 (Transa-table1) 
            Word      Offset of Transb from table1 (Transb-table1) 
            Longword  Offset of Pream from table1 (Pream-table1)
            Longword  Offset of Post from table1 (Post-table1) 
            
    Transa  256 Bytes (See below) 
    Transbx Bytes     (See below) 
    Pream   Word      Length of preamble string
            Bytes     String to be sent when channel is opened 
    Post    Word      Length of postamble string 
            Bytes     String to be sent when channel is closed

The format of Transa and Transb is slightly different from the standard
translation table: 

Transa is a 256 byte list of one character conversions, with an entry of zero if Transb is to be used. 

Transbis however much more complex as each entry is made up of the following
(allowing a string of up to 255 characters to be sent as a replacement
for the given character)::

    Transb  Byte      Character to be replaced 
            Byte      Length of a string to replace character x 
            Bytes     A string (up to 255 characters long) to replace the given character. 
            
The last entry in this list must be 0,1,0 to allow nul characters to be sent. 

Transb is generally therefore in the following format::

    Transb   x Bytes ch1,len1,'text1' 
             x Bytes ch2,len2,'text2' 
             .... 
             x Bytes chn,lenn,'textn' 
             x Bytes 0,1,0

**THOR Example**

For example, following upon our earlier example, one entry in Transb
would allow for trouble-free translation of the pound sign. This could
therefore be achieved by the program listed below::

    100 table1=ALCHP(1024) 
    110 POKE_L table1,HEX('4AFB0001') 
    120 Transa=table1+16 
    130 Transb=Transa+256 
    140 FOR i=0 TO 255: POKE Transa+i,i 
    150 POKE_W table1+4,Transa-table1 
    160 POKE_W table1+6,Transb-table1 
    170 POKE_L table1+8,0 
    180 POKE_L table1+12,0 
    190 POKE Transa+CODE('£'),0 
    200 POKE Transb,CODE('£') 
    210 POKE Transb+1,7 
    220 POKE Transb+2,27: POKE Transb+3,CODE('R'): POKE Transb+4,3 
    230 POKE Transb+5,CODE('#') 
    240 POKE Transb+6,27: POKE Transb+7,CODE('R'): POKE Transb+8,0 
    250 POKE Transb+9,0: POKE Transb+10,1: POKE Transb+11,0 
    260 TRA table1,0

The preamble and postamble entries allow you to set up the printer when
the channel is opened or closed. These can both be up to 32767
characters long. 

From version 6.41, the TRA command has been enhanced to
make extra use of the various different character sets supplied as
standard on this QDOS implementation. The Russian, Russisk and Greek
language set-ups now use a table converting $80 ... $BF to $60 ... $DF
to allow use with down-loaded character sets or Brother/HP Laser Jet +
laser printers, where codes $80 ... $9F are often treated as control
codes. 

The default translate table (TRA 1) now works reasonably with ISO
codes, allowing printers to be set in the appropriate language range.
This works okay with the French, Danish, Spanish, Japanese, and German
set-ups (except for the paragraph character in German). On the Swedish
language set-up, only U/u umlaut (Ü/ü) does not work and the Italian language
set-up fails on e grave (é), u and a acute (ú and á), due to the conflict with French.

A special extended translation table will always be required for the
Russisk, Russian and Greek language set-ups, depending on the type of
printer connected to the system.

**CROSS-REFERENCE**

Please refer to the Appendix concerning serial and parallel device
drivers.

--------------


..  _trim-dlr:

TRIM$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TRIM$ (string$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TRIM                                                             |
+----------+-------------------------------------------------------------------+

The function strips off all preceding and appended spaces from a string
and returns the result of this. Any string can be used as a parameter.

**Examples**

::

    TRIM$(" Hello World"): REMark = "Hello World" 
    TRIM$("second try "): REMark = "second try"
    TRIM$(" "): REMark = "" 
    TRIM$(""): REMark = "" 
    TRIM$(CHR$(27)): REMark = CHR$(27)

**CROSS-REFERENCE**

:ref:`len` returns the length of a string.

--------------


..  _trint:

TRINT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TRINT (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  TRIPRODRO                                                        |
+----------+-------------------------------------------------------------------+

The function TRINT gives the integer part of a floating point number,
it differs from INT for negative numbers only: INT always returns the
next lowest integer, this is the same as the integer part for positive
numbers; however below zero INT
always returns one less than TRINT. For example::

    INT(-PI)

will return -4 and::

    TRINT(-PI)

will return -3.

**CROSS-REFERENCE**

The fact that::

    x = TRINT(x) + FRACT(x) 

can be exploited to substitute one of the two functions by the other, for
example::

    100 DEFine FuNction MYTRINT(x) 
    110   RETurn x - FRACT(x)
    120 END DEFine MYTRINT

If you want to round numbers, refer to
:ref:`dround` and
:ref:`pround`.

--------------


..  _troff:

TROFF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TROFF                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Minerva (TRACE)                                                  |
+----------+-------------------------------------------------------------------+

This command turns off the trace function and closes any file
associated with the trace output.

**CROSS-REFERENCE**

:ref:`tron` and :ref:`sstep` turn
the trace function on.

--------------


..  _tron:

TRON
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TRON [ {#ch \| device\_file}] [; [first] [TO [last]]]            |
+----------+-------------------------------------------------------------------+
| Location |  Minerva (TRACE)                                                  |
+----------+-------------------------------------------------------------------+

This command is very similar to SSTEP except that it does not wait for
a key to be pressed before each statement is executed.

**NOTE**

Minerva's TRACE Toolkit is quite useful but is still just a simple
demonstration of an extension which has been internally added to the
SuperBASIC code.

**CROSS-REFERENCE**

See :ref:`troff` and
:ref:`sstep`.

--------------


..  _true-pct:

TRUE%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TRUE%                                                            |
+----------+-------------------------------------------------------------------+
| Location |  TRUFA                                                            |
+----------+-------------------------------------------------------------------+

TRUE% is the constant 1. It is used to write programs which are more
legible or which adopt habits from the PASCAL language.

**Example**

::

    IF QuATARI=TRUE% THEN ... 
    
is the same as::

    IF QuATARI THEN ...

**CROSS-REFERENCE**

:ref:`false-pct` is 0. :ref:`set`
can be used to create constants as resident keywords.

--------------


..  _truncate:

TRUNCATE
========

+----------+-------------------------------------------------------------------+
| Syntax   || TRUNCATE #channel [\\position] or                                |
|          || TRUNCATE                                                         |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

Every file has a certain length, measured in bytes, which can be
reduced with the command TRUNCATE. If TRUNCATE is used without the
position parameter, the end of the file will be moved to the current
file pointer position, meaning that for most purposes, the last byte of
the file is the byte which was being pointed to. 

If you supply a second
parameter, then the file pointer is set to the given position before the
file is TRUNCATEd. Note that any data after the new 'end of file' will
be lost. 

TRUNCATE returns error -15 (invalid parameter) if the specified
channel is not actually linked to a file. A position
greater than the actual file length, such as position>=FLEN(#channel)
has no effect. TRUNCATE without any parameters uses #3 as the default
channel and is therefore the same as::

    TRUNCATE #3

**NOTE**

The syntax TRUNCATE \\position is not valid, error -17 (error in
expression) will be reported. You have to specify a channel number if
you intend to set the file pointer before truncating the file.

**CROSS-REFERENCE**

:ref:`flen` and
:ref:`file-len` return the length of a file,
:ref:`fpos` and
:ref:`file-pos` the current file pointer
position, :ref:`file-ptra` and
:ref:`file-ptrr` move the file pointer as do
:ref:`get`, :ref:`put`,
:ref:`bget` and :ref:`bput`.

--------------


..  _ttall:

TTALL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTALL (space [,jobid] )                                          |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function is the same as ALCHP but memory allocated with TTALL
cannot be cleared with CLCHP or RECHP: TTREL must be used on the return
value of TTALL; see TTFINDM for an example.

**CROSS-REFERENCE**

:ref:`ttrel` See also
:ref:`reserve`.

--------------


..  _ttedelete:

TTEDELETE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEDELETE (file$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is a function analagous to the command DELETE - it will return the
QDOS error code. The default device is not supported, ie. the file name
must be specified absolutely.

**NOTE**

In contrast to DELETE, TTEDELETE will return the value -7 if the file
did not exist.

**CROSS-REFERENCE**

:ref:`delete` of course.

--------------


..  _ttefp:

TTEFP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEFP (floatvar, floatstr$)                                      |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function tries to convert the string given as the second parameter
into a floating point number and assign this value to the floating point
variable given as the first argument. There is no difference to the
assignment::

    floatvar = floatstr$
    
except where an error occurs, ie. if floatstr$ cannot be converted to a
float. Whereas the assignment above will break with an error, TTEFP will
allow you to track that down by checking its return; the number returned
by TTEFP is the QDOS error code (or 0 if the assignment was successful).

**Example**

A piece of code which asks for the age of the user would look similar to
this::

    100 CLS 
    110 REPeat question 
    120   INPUT "How old are you?"!age$ 
    130   ec = TTEFP(age, age$) 
    140   SELect ON ec 
    150     = 0: IF age < 13 OR age > 100 THEN 
    160            PRINT "You're surely kidding!!" 
    170          ELSE EXIT question 
    180          END IF 
    190     = -17: PRINT "Digits, not letters, ok?" 
    200     = -18: PRINT "Reasonable numbers, please." 
    210     = REMAINDER : PRINT "What's this about?" 
    220   END SELect 
    230 END REPeat question 
    240 PRINT "So you are"!age!"years old... :-)"

**CROSS-REFERENCE**

:ref:`check-pct`, :ref:`checkf`.

--------------


..  _tteopen:

TTEOPEN
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEOPEN (#channel [,openmode], device$)                          |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

The TTEOPEN function opens the specified #channel to any device given
as a string. The type of open is optional and ranges from 0 to 4 - the
meaning is the same as for Minerva's extended OPEN or FILE\_OPEN. If
TTEOPEN is called from the interpreter (Multiple BASICs included) then
channel must either be an existing channel number (which would be then
closed by TTEOPEN prior to being reopened) or lower than the highest
channel number currently used: TTEOPEN will break with 'bad parameter'
if that is not the case.

**CROSS-REFERENCE**

:ref:`open`, :ref:`file-open` and the various FOP_XXX keywords.

--------------


..  _ttet3:

TTET3
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTET3 ( [#ch,] [timeout%,] trapno%, bufadr)                      |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is a really extraordinary function because it allows you to call
the TRAP #3 operating system calls which handle screen devices, so you
would not theoretically need many other commands other than this one to
manipulate windows, if the use of TTET3 were not complicated by the
nature of its design. 

The function TTET3 should only be used by
experienced users (except for some fool-proof usages shown in the
examples), so do not worry if you do not understand the following...
although we have tried to keep it simple.

Let's first turn to the syntax: 

- The channel #ch (default #1) must refer to a window (con\_ or scr\_). 
- The timeout for the machine code call trap is optional, the
  default is -1 (that means the operating system will try indefinitely to
  execute the trap) which is fine for most purposes. 
- Trapno% is a small positive integer that identifies the trap. 
- Bufadr must point to a piece of memory at least 16 bytes long. 

Since this toolkit provides its own
buffer starting at TTV, it is recommended and safe to use this for
bufadr. 

The required 16 bytes buffer is used to communicate with the
processor, the registers D1, D2, A1 and A2 occupy four bytes (one
longword) each within the buffer - they are copied to the processor when
the trap is executed and after the trap has finished will hold any
return values and be copied back into the buffer so that they may be
read with the lines::

    D1=PEEK_L(bufadr) 
    D2=PEEK_L(bufadr+4)
    A1=PEEK_L(bufadr+8) 
    A2=PEEK_L(bufadr+12)

**Example 1**

Superfluous with CLS but::

    x=TTET3(#2,32,TTV) 
    
does a::

    CLS#2.

**Example 2**

The procedure SD\_ENQUIRE reads the window size and cursor position, the
values are placed in the passed integer variables. You can test if
anything went wrong (eg. #ch does not refer to a window) by checking if
any of the values returned are negative. 

The parameter what% determines
the units, 

- what% = 0 will have the effect that wsx% and wsy% are the window width and height in pixels and that (cpx%, cpy%) is the position of the text cursor in screen pixels; 
- what%<>0 will give the same information but in characters. 

::

    100 FOR i = 0, 1 
    110   SD_ENQUIRE #2, i, a%, b%, c%, d% 
    120   PRINT a%, b%, c%, d% 
    130 END FOR i 
    140 : 
    150 DEFine PROCedure SD_ENQUIRE (ch, what%, wsx%, wsy%, cpx%, cpy%) 
    160   LOCal trapno% 
    170   POKE_L TTV+8, TTV+16 
    180   trapno% = 10 + NOT(NOT what%) 
    190   IF TTET3(#ch, 100, trapno%, TTV) THEN 
    200     wsx% = -1: wsy% = -1: cpx% = -1: cpy% = -1 
    210     RETurn 
    220   END IF 
    230   wsx% = PEEK_W(TTV+16): wsy% = PEEK_W(TTV+18) 
    240   cpx% = PEEK_W(TTV+20): cpy% = PEEK_W(TTV+22) 
    250 END DEFine SD_ENQUIRE 

On Minerva, you can write NOT (NOT what%) without brackets. SD\_ENQUIRE
is absolutely clean, there is no danger at all that the system might
crash, that it does not run on all QDOS machines or anything like that.

All other machine code traps available through TTET3 are covered by
commands in this manual, but TTET3 can be used to avoid the need to link
in a Toolkit.

**CROSS-REFERENCE**

Please refer to system documentation for details on each trap! See also
:ref:`io-trap`, :ref:`qtrap`
and :ref:`mtrap`.

--------------


..  _ttex:

TTEX
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEX file$ [;cmd$]                                               |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This command is analogous to EXEC - like EX, a command string can be
passed to the program. However, unlike EX, default devices, pipes and
channel passing are not supported.

**CROSS-REFERENCE**

See :ref:`ttex-w` and :ref:`ex`.

--------------


..  _ttex-w:

TTEX\_W
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEX\_W file$ [;cmd$]                                            |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This bears the same relation to EXEC\_W and EW as TTEX does to EXEC and
EX.

**CROSS-REFERENCE**

See :ref:`ttex` and :ref:`ew`.

--------------


..  _ttfindm:

TTFINDM
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTFINDM (addr, length, tosearch$)                                |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function will search for a given string in memory, see SEARCH,
MSEARCH and BLOOK. Memory is scanned from address addr for length bytes
onwards. The search is case-sensitive. TTFINDM returns zero if the
string was not found or the positive relative address plus one where the
string first occurs.

**Example**

Old or badly written programs and Toolkits require the screen located at
address $20000 and the System Variables at $28000, this causes great
problems an Minerva in Dual Screen Mode and other advanced systems as
well. 

Our demonstration for TTFINDM loads a file into memory and scans
it for the occurrence of the two mentioned numbers in their internal
format. This method of checking code is pretty reliable for hand-written
machine code. The problem$ values have been computed with::

    MKL$(HEX("20000")) 
    
and ::

    MKL$(HEX("28000"))
    
::    
    
    100 file$ = "flp2_tool_shape_cde" 
    110 length = FLEN(\file$) 
    120 DIM problem$(2,4) 
    130 problem$(1) = CHR$(0)&CHR$(2)&CHR$(0)&CHR$(0) 
    140 problem$(2) = CHR$(0)&CHR$(2)&CHR$(128)&CHR$(0) 
    150 : 
    160 PAPER 3: CLS: INK 7 
    170 PRINT "Allocating memory..."; 
    180 adr = TTALL(length): PRINT "done" 
    190 IF adr = 0 THEN PRINT "No memory.": STOP 
    200 PRINT "Loading"!file$;"..."; 
    210 LBYTES file$ TO adr: PRINT "done" 
    220 FOR test = 1 TO DIMN(problem$) 
    230   PRINT "Test"!test;"..."; 
    240   found = TTFINDM(adr, length, problem$(test)) 
    250   IF found THEN 
    260     PRINT "failed" 
    270     DUMPIT adr+found-1, 4, 20 
    280   ELSE PRINT "ok" 
    290   END IF 
    300 END FOR test 
    310 PRINT "Releasing memory..."; 
    320 TTREL adr: PRINT "done" 
    330 : 
    340 DEFine PROCedure DUMPIT (adr, length%, surr%) 
    350   INK 4: PRINT TTPEEK$(adr-surr%, surr%); 
    360   INK 7: PRINT TTPEEK$(adr, length%); 
    370   INK 4: PRINT TTPEEK$(adr+length%, surr%): INK 7 
    380 END DEFine DUMPIT

**CROSS-REFERENCE**

:ref:`search`, :ref:`blook`,
:ref:`msearch` are all similar.

--------------


..  _ttinc:

TTINC
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTINC #ch, xsp%, ysp%                                            |
+----------+-------------------------------------------------------------------+
| Location |  QViewTiny Toolkit                                                |
+----------+-------------------------------------------------------------------+

This command is identical to CHAR\_INC.

--------------


..  _ttme-pct:

TTME%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTME%                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function gives the job number of the current job.

**CROSS-REFERENCE**

See :ref:`jobs` for information about
:ref:`ttme-pct`'s return.

--------------


..  _ttmode-pct:

TTMODE%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTMODE%                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is the same as RMODE.

--------------


..  _ttpeek-dlr:

TTPEEK$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTPEEK$ (adr, length)                                            |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

See PEEK$.

**Example**

::

    PRINT TTPEEK$(TTV-2,2) 
    
always shows the letters QV.

--------------


..  _ttpokem:

TTPOKEM
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTPOKEM adr2 { , \| ! \| TO } adr1, bytes                        |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

The command TTPOKEM moves any amount of bytes in memory from address
adr1 to adr2. The choice of the separator only makes a difference if the
source memory area overlaps with the destination. The separator has the
following effects:

- Comma (,) : the move is non-destructive, meaning that the memory area from adr1 has been copied to adr2 so that it is identical to the area which was previously located at adr1 (the area at adr1 has changed of course if the areas overlap). 
- ! or TO : The move is destructive and the overlapping parts of or both blocks will be messed up, that is because the first few bytes stored at adr1 will be stored at adr2 onwards, thus overwriting the last few bytes of adr1 which should have been copied.

**CROSS-REFERENCE**

:ref:`bmove`, :ref:`copy-b`,
:ref:`copy-l`, :ref:`copy-w`

--------------


..  _ttpoke-dlr:

TTPOKE$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTPOKE$ adr, string$                                             |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is the same as POKE$.

--------------


..  _ttrel:

TTREL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTREL adr                                                        |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is similar to the RECHP command, except that it will only remove
areas set aside with TTALL.

**CROSS-REFERENCE**

:ref:`ttall`. See also
:ref:`discard`.

--------------


..  _ttrename:

TTRENAME
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TTRENAME file1$, file2$                                          |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This command is similar to RENAME except that no default devices are
supported. Toolkit II (which apart from providing the SuperBASIC keyword
RENAME adds an operating system extension to rename files) is not
required.

--------------


..  _ttsus:

TTSUS
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTSUS frames                                                     |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

The command TTSUS will cause the current job to be suspended for
frames/50 seconds (frames/60 on some QLs), ie. the job will wait at the
TTSUS command for the specified time and then continue with the next
command. It is suggested that TTSUS is used as an alternative to the
PAUSE command (same parameter) because it does not require an open
channel - it's a good idea, but please take into account that pressing a
key will not break the pause generated by TTSUS.

**CROSS-REFERENCE**

:ref:`sjob`, :ref:`prio`,
:ref:`pause`

--------------


..  _ttv:

TTV
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TTV [ ( x1 :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*` )]               |
+----------+-------------------------------------------------------------------+
| Location | QView Tiny Toolkit                                                |
+----------+-------------------------------------------------------------------+

The function TTV returns the address of the QView Toolkit workspace,
which is a piece of shared memory of 176 bytes which can be accessed
from any job. The idea is that this workspace is used for communication
between different parts of the same program. By default, these bytes are
set to zero, so that you can freely POKE to them without the danger of
crashes. Note that the value of TTV is the same for all jobs. The
parameters are (more or less) just for fun, their sum is added to the
start address of the QView Toolkit workspace before that address is
returned. So:: 

    TTV = TTV(0) 
    TTV(10) = TTV+10 = TTV(3,3,3,1)

**Example**

The workspace is preceded by 64 bytes for QView Toolkit's internal use.
There is however one value that is interesting to look at::

    PEEK_L(TTV-64) 
    
is a very precise counter, it increases once every
frame. This is ideal for checking program speed without the need for
long lasting benchmarks, the following programs demonstrates the
difference in speed between some different types of FOR constructions::

    100 TIMER_START 
    110 FOR i = 1 TO 10000 
    120   REMark 
    130 END FOR i 
    140 TIMER_STOP 
    150 : 
    160 TIMER_START 
    170 FOR i = 1 TO 10000: REMark 
    180 TIMER_STOP 
    190 : 
    200 TIMER_START 
    210 FOR i% = 1 TO 10000: REMark 
    220 TIMER_STOP 
    230 : 
    240 : 
    250 DEFine PROCedure TIMER_START 
    260   POKE_L TTV(-64),0 
    270 END DEFine TIMER_START 
    280 : 
    290 DEFine PROCedure TIMER_STOP 
    300   LOCal count 
    310   count = PEEK_L(TTV-64) 
    320   PRINT INT (count/5) /10;"s" 
    330 END DEFine TIMER_STOP

The third test (lines 200 to 220) works on Minerva and SMS only, and is
the fatest: 78% faster than the first test! Some QLs (mainly those in
the UK using TV's) will need to amend line 320 to read:: 

    320 PRINT INT (count/6 )/10;'s'

**CROSS-REFERENCE**

See :ref:`t-on`, :ref:`t-off`,
:ref:`t-start` and
:ref:`t-stop`

--------------


..  _tt-dlr:

TT$
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TT$                                                              |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function returns the version ID of the QView Tiny Toolkit, eg.
QVTK1.3

--------------


..  _turbo-diags:

TURBO\_diags
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_diags " [ d \| i \| o ] "                                 |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. A program can be
compiled with line numbers included, which increases the amount of
memory and dataspace required by a program, but does mean that if an
error occurs, the line number will be displayed. If you do not include
line numbers, any errors will report 'at line 0' and ERLIN% will return
0. This directive accepts a single character string which should be one
of the following values: 

- d: Display line numbers during compilation process but do not include them in final code.
- i: Include line numbers in final code. 
- o: Omit line numbers all together. 

As with other compiler
directives, this value can be changed by configuring the parser\_task
program or by entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_diags "i"

**CROSS-REFERENCE**

See
:ref:`turbo-f`,\ :ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objdat`,\ :ref:`turbo-objfil`,
:ref:`turbo-optim`,\ :ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-f:

TURBO\_F
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_F                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This directive forms part of the EXTERNAL and GLOBAL Turbo directives
and is used to specify the names of FuNctions contained in another
compiled module for a program where that program is loaded as several
linked modules (using LINK\_LOAD) rather than one huge program.

**NOTE**

Before v3.00, this directive was called FUNCTION which caused problems
with installing Turbo Toolkit under Minerva and SMS.

**CROSS-REFERENCE**

See :ref:`turbo-locstr` and
:ref:`turbo-p` for other directives Refer to
:ref:`external` for more information. Use
:ref:`tk-ver-dlr` to check on the version of TURBO
toolkit.

--------------


..  _turbo-locstr:

TURBO\_locstr
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_locstr " [ i \| r \| c ] "                                |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. All strings used
within a compiled program should be dimensioned so that the compiler
knows the maximum amount of memory which needs to be set aside to store
a string. Any attempt to assign a longer value to the string than that
set with a DIM or LOCal command will be cut to the appropriate length.

If TURBO has to automatically DIMension a string, it assumes a length of
100 characters (unless configured otherwise). 

The TURBO\_locstr
directive relates to the way in which TURBO should deal with LOCal
strings or string parameters. It accepts a single character string which
should be one of the following values: 

- i: Ignore any strings which are used in the program but not dimensioned. TURBO assumes that you know what you are doing with them. 
- r: Report any undimensioned strings - do nothing with them. 
- c: Create a DIM statement for any undimensioned strings, making them global sizes for the whole program. 

As with other compiler directives, this value can be changed by configuring the
parser\_task program or by entering a different value on the Parser's
front panel.

**Example**

::

    5 TURBO_locstr "c"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,\ :ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-model:

TURBO\_model
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_model " [ < \| > ] "                                      |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. The TURBO
compiler is able to generate code using either 16 bit addressing or 32
bit addressing. The former produces more compact and slightly faster
code than the latter, but runs into problems if the compiled version of
your program (excluding dataspace) is larger than 64K. You should
therefore experiment with this setting - if your program is too large to
be compiled with 16 bit addressing, the TURBO compiler will report an
error during the code generation stage to the effect that the program is
'too large for optimistion'. This does not overcome the problem with
running TURBO compiled programs on systems which have a lot of memory or
which do not have the system variables stored at $28000. To cover these
programs, it is necessary to run them through the TurboPatch program
supplied with later versions of the TURBO toolkit. 

The TURBO\_model
directive accepts a single character string which should be one of the
following values: 

- <: Generate code using 16-bit addressing (shown as <64K on screen). 
- >: Generate code using 32-bit addressing. 

As with other compiler directives, this value can be changed by configuring the
parser\_task program or by entering a different value on the Parser's
front panel.

**Example**

::

    5 TURBO_model "<"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-objdat:

TURBO\_objdat
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_objdat sizesize=0...850                                   |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This directive is exactly the same as DATA\_AREA.

**NOTE**

This setting will override a previous DATA\_AREA directive in the same
program. It will also be overridden by a later DATA\_AREA directive in
the same program.

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-objfil:

TURBO\_objfil
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_objfil filename$                                          |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This directive
expects you to specify a string which will form the filename of the
compiled program produced by TURBO. The full filename (including device)
should be specified in quote marks. As with other compiler directives,
this value can be changed by configuring the parser\_task program or by
entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_objfil "ram1_CT_exe"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-optim:

TURBO\_optim
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_optim " [ b \| r \| f ] "                                 |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. The way in which
TURBO compiles a program can be optimised using a trade off between
speed and code size. 

The TURBO\_optim directive allows you to dictate
how the compiled program is to be optimised and accepts a single
character string which should be one of the following values: 

- b: Generate BRIEF code, which ensures that the program uses as little memory as possible. This generates the slowest programs. 
- r: Optimise code according to REMarks in the program. Normally this will generate BRIEF code unless you include a line containing REMark + in your program which tells TURBO to switch to FAST code. The code will then be optimised for speed until a line containing REMark - is encountered. 
- f: Generate FAST code, which ensures that the program runs as quickly as possible. This may however cause the program to need a lot more memory. As with other compiler directives, this value can be changed by configuring the parser\_task program or by entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_optim "b"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-p:

TURBO\_P
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_P                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This directive forms part of the EXTERNAL and GLOBAL Turbo directives
and is used to specify the names of PROCedures contained in another
compiled module for a program where that program is loaded as several
linked modules (using LINK\_LOAD) rather than one huge program.

**NOTE**

Before version 3.00 of the Turbo Toolkit, this directive was called
PROCEDURE which would cause problems with installing the Turbo Toolkit
under Minerva and SMS.

**CROSS-REFERENCE**

See :ref:`turbo-locstr` and
:ref:`turbo-f` for other directives Refer to
:ref:`external` for more information. Use
:ref:`tk-ver-dlr` to check on the version of TURBO
toolkit.

--------------


..  _turbo-repfil:

TURBO\_repfil
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_repfil filename$                                          |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This directive
expects you to specify a filename as a string. TURBO will use this file
to produce a report on the compilation process, which can be useful to
track down compilation errors and warnings. If no filename is specified,
then all errors and warnings are merely shown on screen. The full
filename (including device) should be specified in quote marks. As with
other compiler directives, this value can be changed by configuring the
parser\_task program or by entering a different value on the Parser's
front panel.

**Example**

::

    5 TURBO_repfil "ram2_CT_report"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-struct:

TURBO\_struct
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_struct " [ s \| f ] "                                     |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. TURBO is able to
compile a wide variety of programs. However, if the program does not
follow strict programming rules, it will take longer to compile and will
run more slowly (even if TURBO can manage to compile it). 

Programs which
follow the programming rules are known as Structured. These programming
rules are set out below: 

#. The main section of the program must appear at the start and not contain any PROCedure or FuNction definitions. 
#. At the end of the main section appears only PROCedure and FuNction definitions without any other lines between the end of one definition and start of another except for REMarks. 
#. All FOR, REPeat, IF, SELect ON, WHEN, strutures are contained within each section (either the main section or a PROCedure / FuNction definition) of the program and not referenced from outside that section. 

All other programs are known as Freeform. 

The TURBO\_struct directive allows you to specify the
type of programming style used in the program which is to be compiled.
It accepts a single character string which should be one of the
following values: 

- f: The program is Freeform. 
- s: The program is Structured.

As with other compiler directives, this value can be changed by
configuring the parser\_task program or by entering a different value on
the Parser's front panel.

**Example**

::

    5 TURBO_struct "s"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-taskn:

TURBO\_taskn
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_taskn name$                                               |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This directive
allows you to specify the name for the compiled program which will
appear in its header and appear when JOBS is used for example. The full
name should be specified in quote marks. 

As with other compiler
directives, this value can be changed by configuring the parser\_task
program or by entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_taskn "Main v1.2"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct` and
:ref:`turbo-window` for other directives

--------------


..  _turbo-window:

TURBO\_window
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_window number                                             |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This tells the
TURBO parser to copy across number windows from the existing channel
structure into the compiled program. If number=1 only window #1 will
appear in the compiled program. Any greater value for number will copy
window #0 also. It is usually better to ensure that your compiled
program opens all of its own windows, using commands such as::

    100 OPEN #1,'con_448x200a32x16'

This reduces the amount of memory used up by each channel and also
ensures that your program only opens the windows which it actually needs
to work. As with other compiler directives, this value can be changed by
configuring the parser\_task program or by entering a different value on
the Parser's front panel.

**Example**

::

    5 TURBO_window 0

**NOTE**

Only the active area of a window is copied across to the compiled
program, so if a BORDER has been specified, this will not appear in the
compiled program (only the area inside the border will be copied
across). If your compiled program then defines its own BORDER on that
window, the size of the window will be further reduced.

**CROSS-REFERENCE**

See
:ref:`turbo-diags`,\ :ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,\ :ref:`turbo-repfil`,
:ref:`turbo-struct`, and
:ref:`turbo-taskn` for other directives

--------------


..  _turn:

TURN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TURN [#ch,] degrees                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is part of the QL's turtle graphics set and alters the
current direction of the turtle in the specified window (default #1).
When a window is first opened, the turtle will be facing the right hand
side of the window (this is zero degrees). 

TURN will force the turtle to turn anti-clockwise by the specified number of
degrees (note that this does not work in radians!). If a negative number
of degrees is specified, the turtle will be turned in a clockwise
direction.

**CROSS-REFERENCE**

:ref:`turnto` forces the turtle to face in an
absolute direction. Please also see :ref:`move`.

--------------


..  _turnto:

TURNTO
======

+----------+-------------------------------------------------------------------+
| Syntax   |  TURNTO [#ch,] angle                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command, in contrast to TURN forces the turtle in the specified
window (default #1) to face in the direction specified by angle. If
angle=0, the turtle will face the right hand edge of the window, whereas
an angle of 90 will force the turtle to point towards the top of the
window. A negative value of angle will cause the turtle to turn
clockwise, so that angle=-90 is the same as angle=270.

**CROSS-REFERENCE**

Please refer to :ref:`move` and
:ref:`turn`.

--------------


..  _txtras:

TXTRAS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  TXTRAS [#ch]                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command lists extensions to SuperBASIC in the specified channel
#ch (default #1). Apart from printing the mere keyword name, it will
also report the type, ie. whether it is a function or command.

**Example**

TXTRAS might print::

    Proc RUN 
    Proc STOP 
    Proc OPEN 
    Proc CLOSE

**NOTE**

On pre 1.10 versions of TinyToolkit, TXTRAS was named EXTRAS.

**CROSS-REFERENCE**

:ref:`extras`, :ref:`sxtras`
and :ref:`vocab` are all similar.

--------------


..  _type:

TYPE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TYPE (name$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

The function TYPE returns the internal identification number of any
variable, device name, keyword, command, function etc. as a decimal
number. Each type corresponds to a certain number:

+------+------+-------------------------------+-------------------------+
| Hex  | Dec  | Type                          | Example                 |
+======+======+===============================+=========================+
| 0001 | 1    | undefined string              | Name$                   |
+------+------+-------------------------------+-------------------------+
| 0002 | 2    | undefined floating point      | Size                    |
+------+------+-------------------------------+-------------------------+
| 0003 | 3    | undefined integer             | Age%                    |
+------+------+-------------------------------+-------------------------+
| 0201 | 513  | string variable               | Name$="Smith"           |
+------+------+-------------------------------+-------------------------+
| 0202 | 514  | floating point number         | Size=1.85               |
+------+------+-------------------------------+-------------------------+
| 0203 | 515  | integer number                | Age%=38                 |
+------+------+-------------------------------+-------------------------+
| 0301 | 769  | string array                  | DIM a$(10,20)           |
+------+------+-------------------------------+-------------------------+
| 0302 | 770  | floating point array          | DIM a(221)              |
+------+------+-------------------------------+-------------------------+
| 0303 | 771  | integer array                 | DIM a%(10000)           |
+------+------+-------------------------------+-------------------------+
| 0400 | 1024 | BASIC PROCedure               | DEFine PROCedure QUIT   |
+------+------+-------------------------------+-------------------------+
| 0501 | 1281 | BASIC string FuNction         | DEFine FuNction Who$    |
+------+------+-------------------------------+-------------------------+
| 0502 | 1282 | BASIC floating point FuNction | DEFine FuNction Tm(day) |
+------+------+-------------------------------+-------------------------+
| 0503 | 1283 | BASIC integer FuNction        | DEFine FuNction Age%    |
+------+------+-------------------------------+-------------------------+
| 0602 | 1538 | REPeat loop name              | REPeat forever          |
+------+------+-------------------------------+-------------------------+
| 0702 | 1794 | FOR loop name                 | FOR i=1 TO n            |
+------+------+-------------------------------+-------------------------+
| 0800 | 2048 | machine code procedure        | RUN, ED, NEW            |
+------+------+-------------------------------+-------------------------+
| 0900 | 2304 | machine code function         | QDOS$, VER$, FILL$      |
+------+------+-------------------------------+-------------------------+

**NOTE 1**

Parameters must be given in quotes if you want to find out the type of
the actual name, eg::

    PRINT TYPE ('RUN')
    
If quote marks are not used,
then the value of the parameter is passed instead - eg::

    name$="RUN"
    PRINT TYPE(name$)

will not return the type of name$ but the type of RUN.

**NOTE 2**

TYPE can also take any kind of expression, whether or not they are
valid.

**CROSS-REFERENCE**

:ref:`key-add` and :ref:`elis`
return the address where a machine code keyword is stored.
:ref:`defined` checks if a variable is set.

--------------


..  _type-in:

TYPE\_IN
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TYPE\_IN string$                                                 |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

Same as FORCE\_TYPE.

--------------


..  _t-count:

T\_COUNT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_COUNT [ (watch) ]                                             |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This function reads the time elapsed on the specified stop- watch
(default 1). If the watch has not been started, the value 2,147,483,647
is returned by this function.

**CROSS-REFERENCE**

See :ref:`t-start` and
:ref:`t-stop`. :ref:`t-on`
contains a general description of the stop-watches.

--------------


..  _t-off:

T\_OFF
======

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_OFF                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This command removes all of the stop-watches from memory, although they
can be re-enabled with T\_ON.

**NOTE**

None of the times on the stop-watches are reset and can therefore be
continued once T\_ON has been used.

**CROSS-REFERENCE**

See :ref:`t-on`.

--------------


..  _t-on:

T\_ON
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_ON                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This toolkit provides the QL with five independent stop-watches which
can be used to make accurate timings (more accurate than using DATE).

The stop-watches are linked into the QL's 'polled list' of small
routines which are run every frame on the computer (1/50 second on a
British QL, 1/60 on most foreign QLs). There is a slight disadvantage in
using the polled interrupts in that they are sometimes disabled by
machine code routines, for example when accessing microdrives and disks.

Because of this, these commands are not much for timing programs which
depend heavily on external hardware. These stop-watches are however very
useful for comparing the speed of various program routines without
having to make thousands of loops in order to show any difference in
speed. 

This command enables all the stop-watches. This must be issued
before T\_START can be used.

**CROSS-REFERENCE**

See :ref:`ttv`, :ref:`t-start`,
:ref:`t-stop`,
:ref:`t-restart`

--------------


..  _t-restart:

T\_RESTART
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_RESTART [watch]                                               |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This command restarts a specified stop-watch (default 1) once it has
been stopped, without resetting the initial time to zero. This command
can have spurious effects if the stop-watch has not previously been
used.

**CROSS-REFERENCE**

:ref:`t-stop` stops a stop watch. See
:ref:`t-start` also.

--------------


..  _t-start:

T\_START
========

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_START [watch]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This command starts the specified stop-watch (default 1), setting the
initial time to zero.

**CROSS-REFERENCE**

You need to have used :ref:`t-on` before
:ref:`t-start` can be used. See also
:ref:`t-stop` and
:ref:`t-restart`.

--------------


..  _t-stop:

T\_STOP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_STOP [watch]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This command stops the specified stop-watch (default 1) from running.

**CROSS-REFERENCE**

:ref:`t-restart` restarts a stop-watch.
:ref:`t-start` starts a stop-watch from afresh.

