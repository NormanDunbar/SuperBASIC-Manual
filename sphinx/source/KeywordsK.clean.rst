==========
Keywords K
==========


..  _kbd-reset:

KBD\_RESET
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  KBD\_RESET                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This is a command which should never be needed. If you unplug the
keyboard from the Atari whilst the machine is switched on (this can ruin
your machine), when you plug it back in, you may find that the mouse
buttons no longer work. This command re-initialises the keyboard driver
so that the mouse buttons will work again!

--------------


..  _kbd-table:

KBD\_TABLE
==========

+----------+-------------------------------------------------------------------+
| Syntax   || KBD\_TABLE num     or                                            |
|          || KBD\_TABLE kcode  (SMS only)                                     |
+----------+-------------------------------------------------------------------+
| Location || ST/QL (Level C-17 Drivers onwards), SMS (v2.31+)                 |
+----------+-------------------------------------------------------------------+

Various keyboards can be attached to a computer depending on which
country the computer is being used in. It is therefore necessary to tell
the operating system which keyboard layout is to be used so that it can
recognise which keys are being pressed. 

The command KBD\_TABLE does just
that. num will have one of six possible values depending on the keyboard
layout (under SMSQ/E this equates to the international dialling code for
that country) or you can use the second variant to pass up to four
letters representing the Car Registration Letters for that country (the
fourth letter is used where that country has more than one language):

+-----+-------+-------------+
| Num | Kcode | Language    |
+=====+=======+=============+
| 33  | F     | French      |
+-----+-------+-------------+
| 34  | E     | Spanish     |
+-----+-------+-------------+
| 44  | GB    | English     |
+-----+-------+-------------+
| 45  | DK    | Danish      |
+-----+-------+-------------+
| 46  | S     | Swedish     |
+-----+-------+-------------+
| 47  | N     | Norwegian   |
+-----+-------+-------------+
| 49  | D     | German      |
+-----+-------+-------------+

Num can also be used as a pointer to a user-defined keyboard
table for countries which are not covered. Details are beyond the scope
of this book. A desription of how to create new keyboard tables and
languages appears in IQLR Volume 5 Issue 1 and 5.

**ST/QL NOTES**

The values for num must be one of the following values: 0 English 1
German 2 French 3 Norwegian 5 Danish 6 Spanish

**CROSS-REFERENCE**

:ref:`set-language` is similar for the
THOR XVI. :ref:`language` and
:ref:`language-dlr` allow you to enquire about a
language. :ref:`lang-use` allows you to change
the language used by the system. :ref:`tra` allows you
to change the output to a printer.

--------------


..  _kbd-use:

KBD\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  KBD\_USE [ser\_port]                                             |
+----------+-------------------------------------------------------------------+
| Location |  XKBD                                                             |
+----------+-------------------------------------------------------------------+

This command ensures that any incoming data from the specified serial
port (1 for ser1, 2 for ser2) is transformed into keystrokes. Thus other
computers or 8 bit keyboards can be used as an additional external
keyboard. Using the command without a parameter, or zero (eg. KBD\_USE
0) closes the ser channel and stops this operation.

**NOTE**

This task is carried out in the background of any other programs, but
does not actually create a job.

--------------


..  _kbytes-free:

KBYTES\_FREE
============

+----------+-------------------------------------------------------------------+
| Syntax   | memory = KBYTES\_FREE                                             |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The amount of memory considered by QDOS to be free is returned rounded down to the nearest kilo byte.  See also :ref:`bytes-free` if you need the answer in bytes.  The value in KBYTES\_FREE may not be equal to :ref:`bytes-free`\ /1024 as the value returned by KBYTES\_FREE has been rounded down.


**EXAMPLE**

::

    kb_available = KBYTES_FREE


**CROSS-REFERENCE**

:ref:`bytes-free`.


-------



..  _key:

KEY
===

+----------+-------------------------------------------------------------------+
| Syntax   || KEY keynr, string$  or                                           |
|          || KEY keynr (KEYMAN only) or                                       |
|          || KEY (KEYMAN only)                                                |
+----------+-------------------------------------------------------------------+
| Location || FKEY, KEYMAN                                                     |
+----------+-------------------------------------------------------------------+

The KEY command allows you to install keyboard short-cuts: that means
if a certain key (specified with keynr) is pressed the specified string$
will be typed into the current keyboard queue. The actual implementation
of the command under the two Toolkits is different, in that the FKEY
variant only allows keynr to be in the range 1..5 representing the five
function keys (F1 to F5) (see table below). 

The KEYMAN version allows
keynr to be in the range 1...60 which represents the following key
presses: 

+----------------------+----------------------+
| Key Result           | Key Result           |
+======================+======================+
| 1 <F1>               | 31 <CTRL><K>         | 
+----------------------+----------------------+
| 2 <F2>               | 32 <CTRL><L>         | 
+----------------------+----------------------+
| 3 <F3>               | 33 <CTRL><M>         |
+----------------------+----------------------+
| 4<F4>                | 34 <CTRL><N>         |
+----------------------+----------------------+
| 5<F5>                | 35 <CTRL><O>         |
+----------------------+----------------------+
| 6<SHIFT><F1>,  <F6>  | 36 <CTRL><P>         |
+----------------------+----------------------+
| 7<SHIFT><F2>,  <F7>  | 37 <CTRL><Q>         |
+----------------------+----------------------+
| 8<SHIFT><F3>,  <F8>  | 38 <CTRL><R>         |
+----------------------+----------------------+
| 9<SHIFT><F4>,  <F9>  | 39 <CTRL><S>         |
+----------------------+----------------------+
| 10<SHIFT><F5>, <F10> | 40 <CTRL><T>         |
+----------------------+----------------------+
| 11<CTRL><F1>,  <F11>\| 41 <CTRL><U>         |
+----------------------+----------------------+
| 12<CTRL><F2>,  <F12>\| 42 <CTRL><V>         |
+----------------------+----------------------+
| 13<CTRL><F3>         | 43 <CTRL><W>         |
+----------------------+----------------------+
| 14<CTRL><F4>         | 44 <CTRL><X>         |
+----------------------+----------------------+
| 15<CTRL><SHIFT><ESC> | 45 <CTRL><Y>         |
+----------------------+----------------------+
| 16<CTRL><SHIFT><F1>  | 46 <CTRL><Z>         |
+----------------------+----------------------+
| 17<CTRL><SHIFT><F2>  | 47 <CTRL><SHIFT><1>  |
+----------------------+----------------------+
| 18<CTRL><SHIFT><F3>  | 48 <CTRL><SHIFT><K>  |
+----------------------+----------------------+
| 19<CTRL><SHIFT><F4>  | 49 <CTRL><SHIFT><L>  |
+----------------------+----------------------+
| 20<CTRL><SHIFT><F5>  | 50 <CTRL><SHIFT><M>  |
+----------------------+----------------------+
| 21<CTRL><A>          | 51 <CTRL><SHIFT><N>  |
+----------------------+----------------------+
| 22<CTRL><B>          | 52 <CTRL><SHIFT><O>  |
+----------------------+----------------------+
| 23 <CTRL><SHIFT><C>  | 53 <CTRL><SHIFT><P>  |
+----------------------+----------------------+
| 24 <CTRL><D>         | 54 <CTRL><SHIFT><Q>  |
+----------------------+----------------------+
| 25 <CTRL><E>         | 55 <CTRL><SHIFT><R>  |
+----------------------+----------------------+
| 26 <CTRL><F>         | 56 <CTRL><SHIFT><S>  |
+----------------------+----------------------+
| 27 <CTRL><G>         | 57 <CTRL><SHIFT><T>  |
+----------------------+----------------------+
| 28 <CTRL><H>         | 58 <CTRL><SHIFT><W>  |
+----------------------+----------------------+
| 29 <CTRL><SHIFT><I>  | 59 <CTRL><SHIFT><X>  |
+----------------------+----------------------+
| 30 <CTRL><SHIFT><J>  | 60 <CTRL><SHIFT><Y>  |
+----------------------+----------------------+


Once initiated, each time that the
specified keying is pressed, the given string will be typed into the
keyboard queue, (note there is a maximum of 80 characters). The KEYMAN
variant allows the second syntax, KEY keynr, which allows you to check
the current definition of keynr, which is then written to #0. 

KEY without any parameters activates the key translation if necessary. KEY
keynr, "" can be used to clear a definition with the KEYMAN variant.

**Example**

::

    KEY 5,"STAT"&CHR$(10)

**NOTE 1**

In applications such as word-processors many of these key- presses are
already used for other purposes and this may cause problems - if you do
use KEY to set a function key and then load a program which uses those
function keys, the program will first of all register that the function
key has been pressed and will then receive a stream of other keypresses
(ie. the defined string).

**NOTE 2**

Key is quite a common variable name and so there is a large danger of
errors occurring if KEY has been loaded into the computer alongside a
program which uses such a variable name - for example, the statement::

    key = KEYROW(1)  
    
will make the program stop with error -17, (Error in expression).

Another problem would exist if key was declared in a program as a BASIC
procedure or function, for example:: 

    DEFine PROCedure Key
    
in which case, this would overwrite the machine code definition and
even the command NEW will not restore it, however all stored KEY
definitions are kept active, and they can no longer be altered because
the keyword KEY is no longer recognised by the system.

**NOTE 3**

Neither of these Toolkits should be linked into a Qliberated job,
otherwise it is possible that the code used for KEY will exist twice in
memory, which would crash the machine. Also, the Toolkits should not be
loaded into a MultiBASIC or Multiple SBASIC unless you are certain that
this Interpreter will never disappear.

**CROSS-REFERENCE**

:ref:`nokey` under KEYMAN is equivalent to
:ref:`key` without parameters. See
:ref:`altkey` for a concept similar to this one
here.

--------------


..  _keyrow:

KEYROW
======

+----------+-------------------------------------------------------------------+
| Syntax   |  KEYROW (row)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function is used to read the keyboard. It is not linked with a
channel which means that it can be used by a job to read the keyboard
whether or not that job has an active cursor. This is mainly only of use
for programs which work in the background unless a certain key is
pressed to bring them to life. If you try to use this command in a
program to control the screen, then this will undoubtedly lead to screen
corruption as the active program may itself be accessing the screen. 

The main advantage which this function has when compared to INKEY$ is that
it allows programs to recognise when the user is pressing several keys
at once, such as the left and up cursor keys to move diagonally. 

The function KEYROW is able to read several keys at once by using a keyboard
matrix, where each row is numbered and each key is assigned to a certain
row. If that key is pressed, then a bit is set in the integer value of
that row to represent which key has been pressed. 

For British QLs, the format of the matrix is::

    Row 0| 7 4 F5 F3 F2 5 F1 F4
    Row 1| DOWN SPACE \ RIGHT ESC UP LEFT ENTER
    Row 2| " M £ B C . Z ]
    Row 3| ; G = F S K CAPSLOCK [
    Row 4| J D P A 1 H 3 L
    Row 5| O Y - R TAB I W 9
    Row 6| U T 0 E Q 6 2 8
    Row 7| , N / V X ALT CTRL SHIFT


+-------+----+----+----+----+---+---+---+---+
| Bit   |  7 |  6 |  5 |  4 | 3 | 2 | 1 | 0 |
+-------+----+----+----+----+---+---+---+---+
| Value |128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
+-------+----+----+----+----+---+---+---+---+

Please see the :ref:`a9-character--sets`\ . 

The table reflects the physical keyboard layout and so may be different 
on other languages. 

Unfortunately, only one row at a time can be read with KEYROW and so the keys are arranged
into groups - for example, all of the cursor keys appear on one row, as
do all of the function keys. 

When the function is used, the supplied parameter row specifies which row of the matrix is to be looked at. The
value returned will have bits set representing which keys (if any) in
that row were being pressed. 

When KEYROW is used, any characters in the
type-ahead buffer are cleared, therefore, if you wish to avoid
accidental input by the user of unwanted keys, you could use::

    dummy = KEYROW(0): Quit$ = INKEY$(-1)

This will clear the type-ahead buffer and then wait for a new key to be
pressed - this is essential where, for example, you are asking for
confirmation that a program should be quit.

**Example 1**

If you were holding the <SHIFT> key down together with the left and up
cursor keys down:: 

    PRINT KEYROW(7) 

would return the value 1 and::

    PRINT KEYROW(1)

would return the value 6.

**Example 2**

The following program moves a cross about the screen, using the cursor
keys - diagonal movement is allowed::

    100 MODE 4 
    110 WINDOW 512,256,0,0:PAPER 0:CLS 
    120 WINDOW 448,200,32,16 
    130 INK 7:OVER -1 
    140 SCALE 150,-120,-75 
    150 x=0:y=0 
    160 LINE x-10,y TO x+10,y,x,y-10 TO x,y+10 
    170 REPeat loop 
    180   ax=KEYROW(1) 
    190   IF NOT ax:NEXT loop 
    200   LINE x-10,y TO x+10,y,x,y-10 TO x,y+10 
    210   IF ax&&2:x=x-(x>-120) 
    220   IF ax&&16:x=x+(x<128) 
    230   IF ax&&4:y=y+(y<75) 
    240   IF ax&&128:y=y-(y>-75)
    250   IF ax&&8:PRINT 'Program Escaped':OVER 0:STOP 
    260   LINE x-10,y TO x+10,y,x,y-10 TO x,y+10 
    270 END REPeat loop

**NOTE 1**

Except under SMS, if you are holding three keys down which form three
corners of a rectangle on the keyboard matrix, the KEYROW function will
return the same value as if the key which appears in the fourth corner
of the rectangle was also depressed. The QL Manual suggests this does
not happen where one of the keys is <CTRL>, <ALT> or <SHIFT>, but this
still happens on the QL, even with Hermes.

**NOTE 2**

Some replacement full-sized keyboard interfaces will not recognise where
two letter keys, two function keys or two numerical keys are held down
at the same time.

**NOTE 3**

It is just possible that if KEYROW is being executed whilst a task is
being loaded or unloaded, the system will crash (the command does not
take place in supervisor mode). This has been fixed on THORs v4.16 (or
later) and Minerva.

**NOTE 4**

KEYROW had various problems under SMS before v2.58.

**NOTE 5**

This command is only partly implemented on THORs v4.16 (and later), and
does not work at all on earlier versions: the only multiple keystrokes
recognised are: <SHIFT>, <CTRL>, <ALT> and one other key! The corners of
the numeric pad act as diagonal cursor keys and the <CAPSLOCK> result is
obtained by pressing <5> on the numeric pad. INKEY$ should be used
instead.

**NOTE 6**

It is highly recommended that KEYROW is *not used* at all. 

It reads the
physical keyboard directly, so will conflict with other jobs running in
a multitasking environment. 

Another problem is the differences between
keyboards, for example, on a German QL the <Z> and <Y> keys are swapped
over compared to a British QL - INKEY$ is much better!

**ST/QL NOTES**

On the ST/QL Emulator, the KEYROW table is much extended, with the
following rows being added, both to take account of the additional keys
available on an ST keyboard and also to take account of the numeric
keypad (hence the repetition of various keys!):: 

    Row 8 | F10 F9 F8 F7 F6 BACKSPACE ~
    Row 9 | + - CLR/HOME
    Row 10| DELETE INSERT
    Row 11| <
    Row 12| 8 7 * / ) ( HELP UNDO
    Row 13| 0 3 2 1 6 5 4 9
    Row 14| ENTER .

+-------+----+----+----+----+---+---+---+---+
| Bit   |  7 |  6 |  5 |  4 | 3 | 2 | 1 | 0 |
+-------+----+----+----+----+---+---+---+---+
| Value |128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
+-------+----+----+----+----+---+---+---+---+


The additional keys have the following meanings: 

- BACKSPACE Delete one character to left (CTRL left). 
- SHIFT BACKSPACE Deletes a word to the left. 
- DELETE Delete character under cursor (CTRL right). 
- SHIFT DELETE Deletes word under cursor. 
- UNDO Undo current operation (CTRL ALT up). 
- SHIFT UNDO Mega undo! 
- CLR/HOME Freezes screen (CTRL F5) 
- INSERT Hard space (SHIFT SPACE) 
- CTRL SHIFT ALT UNDO Hard reset. 

The keys on the numeric keypad have been redefined as follows:

+------------+--------+
| Keying     | Result |
+============+========+
| SHIFT (    | [      |
+------------+--------+
| SHIFT )    | ]      |
+------------+--------+
| SHIFT /    | \      |
+------------+--------+
| SHIFT ENTER| =      |
+------------+--------+
| CTRL (     | {      |
+------------+--------+
| CTRL )     | }      |
+------------+--------+
| CTRL \\    |  \|    |
+------------+--------+

**CROSS-REFERENCE**

:ref:`inkey-dlr` and :ref:`input`
allow user input from the keyboard whilst retaining compatibility across
the various QDOS implementations. These commands are also job specific,
and hence much better for use in multitasking programs. Some of the
HOT_XXX commands and
:ref:`exep` allow you to pass a U option to the
program to force the computer to freeze all other programs whilst this
one is running - this can be used to ensure that a program which uses
:ref:`keyrow` does not carry on reading the
keyboard whilst you are using another program.

--------------


..  _keyw:

KEYW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  KEYW (keyword$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This is a function which can be used to find whether or not a given
keyword is linked into the interpreter. If the keyword is known to the
interpreter, KEYW returns 0, otherwise -7.

**Example**

The following function returns 1 on Gold Cards and 0 on other systems
(or some early Gold Cards if they do not support the SLUG command). It
will unfortunately always return 1 under SMS which has the SLUG command
built-in. 

::

    100 DEFine FuNction Gold_Card 
    110   RETurn NOT KEYW("FLP_DENSITY") + KEYW("SLUG") 
    120 END DEFine Gold_Card

A better way would be to use the MACHINE function.

**NOTE**

This will always access Job 0, therefore it cannot tell you whether or
not a keyword is linked into a MultiBASIC interpreter or a multiple
SBASIC interpreter.

**CROSS-REFERENCE**

:ref:`elis`, :ref:`defined` and
:ref:`key-add` are similar. Compare
:ref:`lookup-pct`.

--------------


..  _key-add:

KEY\_ADD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  KEY\_ADD (keyword$)                                              |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the start address of where the machine code
routine for the given keyword is stored. If the keyword is unrecognised
by the system, 0 will be returned. This command will work from
MultiBASICs and Multiple SBASICs.

**Example 1**

The file server functions of Toolkit II will only work if the code is in
ROM, on an EPROM cartridge, under SMS or on a Trump Card for example.

Nevertheless, the FSERVE command is also found in the configurable
software version. You can easily check what version of Toolkit II is
present by looking at the base address of TK2\_EXT and then adapt your
program to take account of the system configuration. 

::

    100 TK2_location=KEY_ADD("TK2\_EXT") 
    105 FILE_SERVER=0 
    110 SELect ON TK2_location 
    120   = 48*1024 TO 64*1024: FILE_SERVER=1 
    130   = REMAINDER: IF VER$='HBA': FILE_SERVER=1 
    140 END SELect 
    150 : 
    160 IF FILE_SERVER THEN 
    170   FSERVE 
    180 ELSE PRINT "Sorry, no ROM based file server." 
    190 END IF

**Example 2**

KEY\_ADD does not produce an error (unlike ELIS) when a keyword is not
found, and is therefore ideal to check if a certain Toolkit, command or
function is present. This can be used within programs to adapt to
available facilities. 

In this example the internal date and time is
saved as a hexadecimal number (this is more precise) if the necessary
functions are present, otherwise it saves it as a floating point number.

The load routine then checks if the DATE was stored as a hexadecimal or
decimal number, taking whatever action is necessary. 

::

    100 DateFile$="flp1_LastDATE_dat" 
    110 : 
    120 DEFine PROCedure WRITE\_DATE
    130   IF KEY_ADD("OPEN_OVER") THEN 
    140   OPEN_OVER#3,DateFile$ 
    150   ELSE OPEN#3,DateFile$ 
    160   END IF 
    170   IF KEY_ADD("HEX$") AND KEY_ADD("HEX") THEN 
    180     PRINT#3,"$" & HEX$(DATE,32) 
    190   ELSE PRINT#3,DATE 
    200   END IF
    210   CLOSE#3 
    220 END DEFine WRITE_DATE 
    230 :
    240 DEFine PROCedure READ_DATE 
    250   LOCal d$ 
    260   OPEN_IN#3,DateFile$
    270   INPUT#4,d$: CLOSE#3 
    280   IF d$(1)="$" THEN 
    290   IF NOT KEY_ADD("HEX") THEN RETurn 
    300   d$=HEX(d$(2 TO)) 
    310   END IF 
    320   ADATE d$-DATE 
    330 END DEFine READ_DATE

**CROSS-REFERENCE**

:ref:`elis` differs from
:ref:`key-add` in that it returns zero if the
keyword is not found, rather than an error message. See also
:ref:`keyw` and :ref:`lookup-pct`.
:ref:`find` and :ref:`flis` are
also useful.

--------------


..  _key-rmv:

KEY\_RMV
========

+----------+-------------------------------------------------------------------+
| Syntax   |  KEY\_RMV keyword$                                                |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This is the same as ZAP !

--------------


..  _kill:

KILL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  KILL                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools, KILL                                                 |
+----------+-------------------------------------------------------------------+

This command will cause all current jobs, except the main SuperBASIC
interpreter (Job 0), to be stopped and removed from memory.

**Example**

The presence of jobs prevents the commands RESPR / LRESPR from grabbing
memory in the Resident Procedure Area (although some implementations
overcome this restriction, they do so by by allocating space in the
Common Heap) and because some machine code programs cannot or should not
be loaded into the common heap, the command KILL can be of assistance.

**WARNING**

Be sure that no important data gets lost!

**CROSS-REFERENCE**

:ref:`rjob` removes single jobs,
:ref:`kjobs` works in the same way as
:ref:`kill`.

--------------


..  _killn:

KILLN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  KILLN                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command removes all current jobs and reactivates the following
jobs if the respective facilities are available: HOTKEY (Qjump's Hotkey
System) BLANK (Blanks screen if no key pressed) Qmons Nix-Job (see NIX)
Server (see FSERVE)

**WARNING**

Again, be careful!

**CROSS-REFERENCE**

:ref:`kill` removes all jobs as does
:ref:`kjobs`. :ref:`kill-a`
removes all jobs and clears the whole system for SuperBASIC.

--------------


..  _kill-a:

KILL\_A
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  KILL\_A                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command forces everything which can be accessed from SuperBASIC to
be cleared, killed or removed: Jobs, file definition blocks (except if
Qjump's Hotkey System is present), variables, the DATA pointer, the
common heap and all channels are closed. On an Atari QL-Emulator and
under SMS, the buffer for the serial and parallel port is also cleared.

**WARNING**

Be very careful! All data will be lost. Avoid this command if you can:
it is more like a safe emergency break.

**CROSS-REFERENCE**

:ref:`kill`, :ref:`killn`,
:ref:`kjobs`,
:ref:`del-defb`,
:ref:`clchp`.

--------------


..  _kjob:

KJOB
====

+----------+-------------------------------------------------------------------+
| Syntax   || KJOB jobname (TinyToolkit only)  or                              |
|          || KJOB jobnr  or                                                   |
|          || KJOB jobnr,tag (BTool only)                                      |
+----------+-------------------------------------------------------------------+
| Location || TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This command kills the given job (causing it, together with all of its
owned jobs, channels and memory to be removed or freed). Jobname in the
first variant can be passed as a string or as just the name of the Job
without quotes (so long as that name is not defined as a variable or
SuperBASIC PROCedure or FuNction). jobnr is the Job number as listed by
the JOBS command. If this is -1, this will kill the current Job. 

The last variant is surplus at present - it was intended that it would pass
the second parameter back to the owner of the job, but due to an error
in the code, this second parameter is seen as the job tag.

**Examples**

::

    KJOB 'Perfection v2.04' 
    KJOB 1

**NOTE**

Before v1.11 of TinyToolkit, you could not pass jobnr as -1 nor could
you use a variable to pass the jobnr (see JBASE).

**CROSS-REFERENCE**

:ref:`rjob` has a slightly different syntax.
:ref:`kill` and :ref:`kjobs`
remove all jobs. :ref:`spjob`,
:ref:`sjob`, :ref:`rel-job`,
:ref:`ajob` are other commands which handle jobs. The
function :ref:`job-dlr` will return the name of the
given job.

--------------


..  _kjobs:

KJOBS
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  KJOBS                                                            |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This is the same as KILL



