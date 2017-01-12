
==========
Keywords B
==========

TODO
====

- :ref:`bicop` cross references keywords HCO and FCO- neither of which exist.
- :ref:`bld` cross references keyword ESC which doesn't exist.


..  _basic:

BASIC
=====

+----------+-------------------------------------------------------------------+
| Syntax   | BASIC [(offset)]                                                  |
+----------+-------------------------------------------------------------------+
| Location | BTool                                                             |
+----------+-------------------------------------------------------------------+

The function BASIC is identical to BASICP except that if no parameter is
supplied, the function BASIC will return the base address of the
SuperBASIC program area.


**NOTE**

Although this function is written in such a way that it can be used from
within compiled programs to access SuperBASIC variables, it cannot
access MultiBASIC variables on Minerva nor SBASIC variables on SMS and
will always return a value representing the location of the equivalent
SuperBASIC variable.


**WARNING**

You should use commands such as the extended PEEK or POKE provided by
Minerva and SMS to read or set the tables pointed to by the values
returned by this function, as the SuperBASIC tables can move when tasks
are started up or removed from memory.


**CROSS-REFERENCE**

See :ref:`basicp` and
:ref:`basic-w`.

--------------


..  _basicp:

BASICP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  BASICP (offset)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function returns an internal pointer (address) used by the
SuperBASIC interpreter. offset must be non-negative and a multiple of 2
(up to a maximum of HEX('64').

Refer to system documentation for more information.


**Example**

PRINT BASICP(16)

returns the start address of the current SuperBASIC program in memory.

PRINT BASICP(32)

returns the start address of the SuperBASIC name list.


**NOTE**

This suffers from the same problem as BASIC.


**CROSS-REFERENCE**

:ref:`basic-b`,
:ref:`basic-l`,
:ref:`basic-w`. See
:ref:`new-name` for a useful example!

:ref:`basic-pointer` is the same as this
function.

:ref:`-name-dlr` and
:ref:`basic-name-dlr` allow you to access the
SuperBASIC name list safely.

--------------


..  _basic-b:

BASIC\_B
========

See :ref:`basic-l` below.


..  _basic-w:

BASIC\_W
========

See :ref:`basic-l` below.


..  _basic-l:

BASIC\_L
========

+----------+-------------------------------------------------------------------+
| Syntax   || BASIC\_B (offset) and                                            |
|          || BASIC\_W (offset)                                                |
|          || BASIC\_L (offset)                                                |
+----------+-------------------------------------------------------------------+
| Location ||  TinyToolkit, BTool, Turbo Toolkit (BASIC\_L only)               |
+----------+-------------------------------------------------------------------+

These three functions are modified version of PEEK which return values
at memory locations in the SuperBASIC system variables, which are used
for storage by the SuperBASIC interpreter.

BASIC\_B returns bytes, BASIC\_W words and BASIC\_L long words.


**Example**

Although additional information about internal machine structures is
necessary to make full use of these functions, some simple tasks can be
performed without this knowledge, for example:

PRINT BASIC\_W ( 1076 )

gives the first line number of a program in memory - this enables a
machine code program to check if a program is actually loaded in the
machine. The value returned by this example will always be zero from the
interpreter.

::

    100 IF NOT BASIC_W (1076) THEN
    110   PRINT "No SuperBASIC program loaded"
    120 END IF


**NOTE**

These functions generally suffer the same problem as BASIC.

A file called TurboFix\_bin can be used to allow BASIC\_L to access
Minerva MultiBASIC and SMS SBASIC variables. Some early versions of
TurboFix\_bin have bugs in it. Beware that not all versions of this file
supports SMS SBASICs.


**CROSS-REFERENCE**

:ref:`peek`, :ref:`peek-w`,
:ref:`peek-l`, :ref:`basicp`.

:ref:`basic-b-pct`, :ref:`basic-w-pct`,
:ref:`bpeek-pct`,
:ref:`bpeek-w-pct` and
:ref:`bpeek-l` are similar.

See also :ref:`basic-f` and
:ref:`peek-f`.

The SuperBASIC variables appear in the QDOS/SMS Reference Manual
(Section 18.3)

--------------


..  _basic-b-pct:

BASIC\_B%
=========

See :ref:`basic-f` below.


..  _basic-w-pct:

BASIC\_W%
=========

See :ref:`basic-f` below.


..  _basic-f:

BASIC\_F
========

+----------+-------------------------------------------------------------------+
| Syntax   || BASIC\_B% (offset) and                                           |
|          || BASIC\_W% (offset) and                                           |
|          || BASIC\_F (offset)                                                |
+----------+-------------------------------------------------------------------+
| Location || Turbo Toolkit, BTool, Turbo Toolkit (BASIC_L only)               |
+----------+-------------------------------------------------------------------+

The functions BASIC\_B% and BASIC\_W% are similar to BASIC\_B and
BASIC\_W. BASIC\_F is a further function which can be used to return a
floating point number stored as six bytes starting at the specified
offset within the SuperBASIC system variables.


**NOTE**

A file called TurboFix\_bin can be used to allow these functions to
access Minerva MultiBASIC / SBASIC variables. Some early versions of
TurboFix\_bin have bugs in it. Beware that not all versions of this file
supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`basic-b` and
:ref:`basic-w`. :ref:`peek-f`
is similar to :ref:`basic-f`.

--------------


..  _basic-index-pct:

BASIC\_INDEX%
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_INDEX% (name$)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is similar to LOOKUP%, except it does not suffer with any
problems under SMS.

If the specified name$ does not exist, -12 is returned. -7 is returned
if there is some mismatch between table entries.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_INDEX% to access
the Minvera MultiBASIC and SMS SBASIC name tables. Some early versions
of TurboFix\_bin have bugs in it. Beware that not all versions of this
file supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`lookup-pct` and
:ref:`basic-name-dlr`.

--------------


..  _basic-name-dlr:

BASIC\_NAME$
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_NAME$ (index)                                             |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is exactly the same as \_NAME$.

If the specified index is greater than the maximum name table entry, a
bad parameter error is returned. If it is smaller than 0, an error may
be generated, or junk may be returned.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_NAME$ to access
the Minvera MultiBASIC and SMS SBASIC name tables. Some early versions
of TurboFix\_bin have bugs in it. Beware that not all versions of this
file supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`-name-dlr` and
:ref:`basic-index-pct`.

--------------


..  _basic-pointer:

BASIC\_POINTER
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_POINTER (offset)                                          |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is exactly the same as BASICP.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_POINTER to
access the Minvera MultiBASIC and SMS SBASIC name tables. Some early
versions of TurboFix\_bin have bugs in it. Beware that not all versions
of this file supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`basicp`.

--------------


..  _basic-type-pct:

BASIC\_TYPE%
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_TYPE% (offset)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function looks at the entry in the SuperBASIC name table for Job 0
at the specified offset and returns its type in accordance with the
following values:

-  0 .... no type
-  1 .... string
-  2 .... floating point
-  4 .... integer

If the specified offset is greater than the maximum name table entry, a
bad parameter error is returned. If it is smaller than 0, an error may
be generated, or junk may be returned.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_TYPE% to access
the Minvera MultiBASIC and SMS SBASIC name tables. Some early versions
of TurboFix\_bin have bugs in it. Beware that not all versions of this
file supports SMS SBASICs.


**CROSS-REFERENCE**

:ref:`type` is similar.

See also :ref:`basic-name-dlr`.

--------------


..  _bat:

BAT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  BAT                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command forces the command string defined with BAT\_USE to be typed
into the command line (#0). No parameters are allowed. BAT will work
okay in Minerva's MultiBASICs, SMS's SBASICs and even if #0 has been
redefined.


**CROSS-REFERENCE**

See :ref:`bat-use` for an example.

Refer to :ref:`type-in` also.

--------------


..  _bat-dlr:

BAT$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  BAT$                                                             |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the current string (if any) which has been set up
with the BAT\_USE command.


**CROSS-REFERENCE**

See :ref:`bat-use` and
:ref:`bat` for more details.

--------------


..  _bat-use:

BAT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  BAT\_USE batch$                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command is used to specify a command string containing SuperBASIC
keywords which will be typed into the command line (#0) when the command
BAT is issued. The string may be up to 128 characters long. You may add
CHR$(10) to the end of the string in order to emulate an <ENTER>
keypress (as in the example below).


**Example**

BAT\_USE "PAPER 3: INK 7: PAPER#2,3: PAPER#2,3: INK#2,7: WMON 4: BORDER
1,0: BORDER#2,0" & CHR$(10)

The command BAT will now reset the standard start-up windows.


**CROSS-REFERENCE**

:ref:`bat` executes the batch string set with
:ref:`bat-use`.

See
:ref:`force-type`,\ :ref:`stamp`
and :ref:`type-in` also.

:ref:`do` allows batch files of any size to be
executed.

--------------


..  _baud:

BAUD
====

+----------+-------------------------------------------------------------------+
| Syntax   || BAUD bps  or                                                     |
|          || BAUD [port,] bps(SMS and ST/QL only)                             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The serial port(s) use a certain speed to communicate with printers,
modems, other computers, interfaces etc. This speed is set with BAUD.
The only values allowed are set out below, any other value for bps will
produce an error. The unit of the parameter is bits per second.

BAUD will set the same output and input baud rate for both serial ports.

+------------+-------------+------------------+
| Bits/Sec   | Bytes/Sec   | Time/32Kb        |
+============+=============+==================+
| 75         | 9.375       | 58 min, 15 sec   |
+------------+-------------+------------------+
| 300        | 37.5        | 14 min, 34 sec   |
+------------+-------------+------------------+
| 600        | 75          | 7 min, 17 sec    |
+------------+-------------+------------------+
| 1200       | 150         | 3 min, 38 sec    |
+------------+-------------+------------------+
| 2400       | 300         | 1 min, 49 sec    |
+------------+-------------+------------------+
| 4800       | 600         | 55 sec           |
+------------+-------------+------------------+
| 9600       | 1200        | 27 sec           |
+------------+-------------+------------------+
| 19200      | 2400        | 14 sec           |
+------------+-------------+------------------+


**NOTE 1**

The effect of BAUD 19200 depends on the hardware. On standard QLs the
serial port can only send data at that baud rate and tends to be
affected by the QL's sound chip.


**NOTE 2**

On a standard QL without Minerva the actual baudrate is slighty lower
than that stated above.


**NOTE 3**

In practice, data is compressed and transmitted with transfer protocols
(to reduce transmission errors), so the above transmission times refer
to the actual speed of the hardware, not the amount of data.


**NOTE 4**

The standard QL cannot safely handle the input of data at baud rates
greater than 1200.


**NOTE 5**

A modified co-processor Hermes which replaces the 8049 chip by a 8749 is
available, which allows independent input baud rates and (if Minerva
v1.95+ is present) independent output baud rates as well as fixing all
mentioned problems for QLs and AURORA boards. The more expensive version
of Hermes (SuperHermes) also provides three additional low speed RS232
input ports (supporting 30 to 1200 bps) and a high speed RS232 two way
serial port (supporting up to 57,600 bps, which equates to 4800
characters per second).


**NOTE 6**

On a QXL board without SMS v2.57+, a BAUD command would not have
immediate effect if a serial channel was open - it waited until you
closed the channel.


**NOTE 7**

It is possible to connect a mouse to a QL through the standard serial
port. Although the mouse operates at 1200 baud, you can use the mouse
alongside a printer (or modem) either with the assistance of Hermes or
by configuring the mouse software to de-activate whilst the higher baud
rate is in use.


**THOR XVI NOTES**

The THOR XVI allows the following additional baud rates:

+------------+-------------+------------------+
| Bits/Sec   | Bytes/Sec   | Time/32Kb        |
+============+=============+==================+
| 110        | 13.75       | 39 min, 43 sec   |
+------------+-------------+------------------+
| 134.5      | 16.8125     | 32 min, 29 sec   |
+------------+-------------+------------------+
| 150        | 18.75       | 29 min, 08 sec   |
+------------+-------------+------------------+
| 1800       | 225         | 2 min, 26 sec    |
+------------+-------------+------------------+

Independent baud rates may also be used on output and input channels
when the channel is opened by using an extended device name.


**MINERVA NOTES**

Minerva v1.93+ now enables you to set different output baudrates for
ser1 and ser2 - if you want different input baudrates for the two ports,
you will need Hermes (see above). Unfortunately, this enhancement will
only work on QLs without Hermes if both ports are output only.

If you want to disable the ability to handle different output baud
rates, do so with the command: POKE !124 !49,2

In order to set the two baudrates independently, BAUD will now accept
additional values in the range -1 to -128. This is calculated by looking
at the following table, working out which features you will need and
adding the values accordingly to -128:

+----------------+----------------------------------------------------------------------+
| Value to Add   | Effect                                                               |
+================+======================================================================+
| 64             | Alters ser2 baudrate (ser1 is default)                               |
+----------------+----------------------------------------------------------------------+
| 16             | Prevents standard BAUD command from altering baudrate on this port   |
+----------------+----------------------------------------------------------------------+
| 7              | Selects BAUD 75 on this port                                         |
+----------------+----------------------------------------------------------------------+
| 6              | Selects BAUD 300 on this port                                        |
+----------------+----------------------------------------------------------------------+
| 5              | Selects BAUD 600 on this port                                        |
+----------------+----------------------------------------------------------------------+
| 4              | Selects BAUD 1200 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 3              | Selects BAUD 2400 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 2              | Selects BAUD 4800 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 1              | Selects BAUD 9600 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 0              | Selects BAUD 19200 on this port                                      |
+----------------+----------------------------------------------------------------------+

Please only try to add one baud rate value!!


**Minerva Examples**

BAUD -128

sets the baud rate for ser1 output at 19200. ser2 is unaffected.

BAUD -47

fixes the baud rate for ser2 output at 9600. ser1 is unaffected (-47 =
-128+64+16+1).


**SMSQ AND ST/QL NOTES**

If BAUD is only followed by one parameter, then it sets the baud rates
for both SER1 and SER2 on the QL, AURORA and QXL boards. However, if
SMSQ/E is running on an ATARI computer, or the command is used on an
ST/QL Emulator then it only sets the baud rate on SER1.

You can however supply two parameters to the command to set independent
baud rates (note that on a standard QL or Aurora, Hermes is needed for
independent baud rates on each serial port). In this case, the first
parameter is the number of the serial port to be set and the second
number is the new baud rate, for example:

BAUD 1,19200

sets the baud rate on SER1 to 19200 - any other serial ports are left
unaffected. If the rate (bps) is specified as zero, this selects the
highest possible BAUD rate on that port.

Please also note that if a translate has been set up with the TRA
command, changing the BAUD rate will make that translate apply to all
channels opened to the serial ports, whether or not they are already
open. See TRA for more details.

The following additional BAUD rates are also supported on the specified
SMSQ/E version:

**GOLD CARD & SUPER GOLD CARD**


-  1275(1200 receive and 75 transmit - only works with HERMES)
-  75(75 receive and 1200 transmit - only works with HERMES)

(The standard 1200 and 75 Baud rates are not supported)

**ATARI ST and TT**

On these computers, the different serial ports support different baud
rates. An ST/STE only has one serial port (SER1), a Mega STE has three
(SER1, SER2 and SER4), and a TT has four (SER1, SER2, SER3 and SER4).

Support for SER2, SER3 and SER4 was only added to the ST/QL Emulators in
version E-37 of the Drivers. It has always existed in SMSQ/E.

SER1

-  supports all the standard baud rates from 300 to 19200, except 7200.

SER2

-  supports all the standard baud rates from 300 to 19200 (including
   7200) as well as 38,400, 76,800, 83,333 and 125,000 baud (1x and 2x
   MIDI speeds).

   -  If the rate specified is 0, the rate used is 153,600.

-  Note that 38,400 on the TT was implemented in v2.69. 38,400, 76,800,
   83,333, 125,000 and 153,600 BAUD were implemented for the STE and TT
   in v2.73.

SER3

-  supports the same rates as SER1.

-  Hardware handshaking is not available on this port.

SER4

-  supports all the standard baud rates from 300 to 38,400 plus 57,600.

-  If the rate specified is 0, the rate used is 230,000.

**QXL**

All of the standard baud rates available to the normal QL are supported
except for 75 Baud.

**QPC**

All of the same baud rates as the QXL implementation are supported plus
38,400 and 57,600 baud.


**QXL AND QPC NOTES**

If one of the PC's serial ports is already linked to a mouse (in DOS)
then the BAUD command will not affect that port.


**CROSS-REFERENCE**

The Devices Appendix supplies details about the serial device ser and
parallel device par. The ser\_... and
par\_... commands allow you to set various
other parameters for serial and parallel ports.

You can check the current baud rate setting with
:ref:`baudrate`.

--------------


..  _baudrate:

BAUDRATE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  BAUDRATE                                                         |
+----------+-------------------------------------------------------------------+
| Location |  SERMouse                                                         |
+----------+-------------------------------------------------------------------+

This function returns the actual baud rate of the system which will be
used on any newly opened serial port channel.


**CROSS-REFERENCE**

The system's baud rate is set with :ref:`baud`.

--------------


..  _bclear:

BCLEAR
======

+----------+-------------------------------------------------------------------+
| Syntax   |  BCLEAR                                                           |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools, TinyToolkit, BTool                                   |
+----------+-------------------------------------------------------------------+

Each console channel has what is known as an input queue, a small area
of memory where keypresses are stored before they are read by INPUT,
INKEY$ etc. The command BCLEAR clears the buffer of the current input
queue so that any keypresses which have not yet been processed are not
seen by the program. This is useful to prevent overrun on keys.


**Examples**

(1) Type this line as a direct command into the interpreter, press
<ENTER> and then type some keys. REPeat a: REMark

Now press break and all of those keypresses which you performed after
entering the line will be shown. Replace REMark by BCLEAR and try the
same.

Normally it is okay for all keypresses to be stored in a buffer - if a
program cannot cope with the typist's speed, no keypresses will be lost.
But sometimes this feature may not be welcome.

(2) Even on very good keyboards the phenomenon of key-bounce appears,
where the user has pressed a key once but the program thinks that the
same key has been pressed a few times. This generally happens with poor
quality keyboards or if the user is not used to either the keyboard or
program speed.

This is a queue clearing version of the GETCHAR% function shown at CUR.
Dangerous inputs should always clear the keyboard queue, for example
where the program is asking the question: "Do you really want to format
that disk (y/n) ?"

::

    100 DEFine FuNction GETCHAR% (channel,timeout)
    110  LOCal char$,dummy
    120  dummy=PEND(#channel): BCLEAR
    130  CUR #channel,1
    140  char$=INKEY$(#channel,timeout)
    150  CUR #channel,0
    160  RETurn CODE(char$)
    170 END DEFine GETCHAR%


**CROSS-REFERENCE**

The current keyboard queue can be selected by a dummy
:ref:`inkey-dlr` or :ref:`pend`.

--------------


..  _beep:

BEEP
====

+----------+-----------------------------------------------------------------------------+
| Syntax   || BEEP length, pitch [,pitch\_2, grd\_x, grd\_y [,wrap [,fuzz [,rndom ]]]] or|
|          || BEEP                                                                       |
+----------+-----------------------------------------------------------------------------+
| Location || QL ROM                                                                     |
+----------+-----------------------------------------------------------------------------+

This command allows you to access the QL's rather poor sound generation
chip. It can be extremely difficult to use this command, and a lot of
trial and error will generally be needed before you can find anything
similar to the sound you are after.

BEEP without any parameters will turn off the sound altogether. You must
also be aware of the fact that as soon as a BEEP command is encountered,
the QL will cancel the current sound and emit the new one (whether or
not the earlier sound had finished).

Each of the various parameters have different ranges and different
effects on the sound produced:

-  length This specifies the duration of the sound in 72 microsecond
   units (there are one million microseconds in a second). A length of
   zero means emit the sound until another BEEP command is encountered.
   The range is 0...32767 (a value of 32767 lasts for approximately 2.36
   seconds).

-  pitch This affects the tone of the sound produced. The allowable
   range is 0...255. A pitch of 0 is the highest which can be produced,
   ranging to 255 which is the deepest tone. The purity of the sound
   will be affected if any other parameters are specified.

-  pitch\_2 This represents a second pitch level, which will have no
   effect if the tone is the same (or higher) than pitch. If however,
   the value of this parameter is higher (the tone is lower) than that
   of pitch, this specifies a range between which the sound can 'bounce'
   by use of the next two parameters, creating a sequence of notes (the
   length of the sequence will depend on the length parameter).

-  grd\_x Assuming that the BEEP command is now being used to produce a
   sequence of notes, this parameter specifies the time interval (in 72
   microsecond units) of each note in the sequence. The permitted range
   is again 0...32767. Larger time intervals make each note in the
   sequence more distinct (low values tend to produce just buzzing).

-  grd\_y This parameter specifies the step between each note in the
   sequence. This must be in the range 0...15. However, this may make
   more sense if the correct range was said to be -7..8.

   A value of zero produces no step - you are returned to a single note
   again.

   A value between 1 and 7 means that each note will be that many
   pitches below the last one (unless that would bring the pitch below
   pitch\_2).

   A value of 8 makes the BEEP command fit as many notes into the
   sequence (in the range) as possible.

   Values of 9 to 15 (or -7 to -1) mean that each note will be that many
   pitches above the last one (these correspond to the values 7 to 1
   respectively), unless this would bring the pitch above pitch. When
   the top or bottom of the range pitch to pitch\_2 is reached, the step
   direction is reversed to cause the sound to 'bounce'.

-  wrap If this parameter is specified, the range of notes between the
   two pitch parameters will be repeated the specified number of times
   before the step direction is altered. The range for this parameter is
   0..15.

   The last note in the range will not be sounded, but will appear as
   the first note in the opposite direction.

-  fuzzThis affects the purity of each note, by blurring its sound. The
   effective range is 8...15, with a value of 15 producing an awful
   buzz.

-  rndomThis parameter allows you to specify a certain amount of
   'randomness' which is to be added to each note.

   The effective range is once again 8...15, with the given value being
   used to alter from how far away from the original sequence the QL can
   pick a note. The higher the value, the more random notes appear in
   the sequence.


**Examples**

BEEP 0,20,40,10070,2

will keep sounding every other note between 20 and 40 moving down and
then up the scale.

BEEP 0,20,30,10070,2,1

will sound the notes in the following sequence 20, 22, 24, 26, 28, 20,
22, 24, 26, 28, 30, 28, 26, 24, 22, 30, 28, 26,....


**NOTE 1**

On all ROMs if you set a very high pitch value, the QL finds it very
difficult to read the keyboard. BEEP 0,0 and BEEP 0,1 will make typing
rather difficult.


**NOTE 2**

Unless used on a THOR XVI, BEEP does not enter the QL into supervisor
mode and therefore if BASIC is trying to use BEEP whilst a task is
loaded or unloaded, then the system is likely to crash!


**NOTE 3**

BEEP does not do anything on ST/QLs or the Amiga-QDOS Emulator (pre
v3.23).


**NOTE 4**

The pitch of the sound is actually shifted on QLs by different values of
length, fuzz and rndom. The length of the sound is also somewhat
dependent on the pitch! Both of these problems are however fixed by the
replacement co-processor Hermes.


**CROSS-REFERENCE**

:ref:`beeping` allows you to check if a sound is
currently being emitted.

:ref:`pause` allows you to specify a time interval
during which the computer will wait (allowing you to play much longer
notes).

--------------


..  _beeping:

BEEPING
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  BEEPING                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This is a simple function which returns either 1 (true) if any sound
output from BEEP is still running or 0 (false) if not.


**Example**

BEEPING is rather useless in a formulation like: IF BEEPING THEN BEEP

because this is less efficient than BEEP on its own which has the same
effect. However, where you want to ensure that your program generates
the chosen sound, because of the QL's multi-tasking abilities, it may be
useful to use this function in case another program is executing a BEEP
command when you want to - you could then either wait or simply override
that sound by using BEEP followed by your own sound generating BEEP
command. For example:

::

    10 REPeat check_beep: IF NOT BEEPING THEN EXIT check_beep
    20 BEEP 100,20


**NOTE**

This function did not work correctly on Minerva before v1.98.


**CROSS-REFERENCE**

:ref:`beep` activates the speaker.

--------------


..  _bell:

BELL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  BELL                                                             |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, QSound                                                    |
+----------+-------------------------------------------------------------------+

This command produces the sound of a ringing phone.


**CROSS-REFERENCE**

:ref:`snd-ext`, :ref:`shoot`,
:ref:`explode`.

--------------


..  _beule-ext:

Beule\_EXT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  Beule\_EXT                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command is used to update all of the keywords which are added by
the Beuletools Toolkit. The new keywords were automatically added when
the Toolkit was loaded but keywords can be overwritten by other
Toolkits, renamed or ZAPped.

Beule\_EXT undoes these changes and restores the default status.


**WARNING**

Do not load the Beuletools toolkit into anything other than resident
procedure memory (ie. do not have any Jobs running other than Job 0 when
the toolkit is loaded). This may crash the system.


**CROSS-REFERENCE**

:ref:`tk2-ext` and
:ref:`tiny-ext` do the same for Toolkit II and
TinyToolkit keywords.

See also :ref:`atari-ext`.

--------------


..  _bgcolour-ql:

BGCOLOUR\_QL
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BGCOLOUR\_QL [#ch,] colour                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

It is possible under the latest version of SMSQ/E to set a 'wallpaper' -
this is an image which covers the whole of the available screen (in any
resolution) and which forms a background for any programs which may be
running. Normally, this would appear as a black area of the screen.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch. BGCOLOUR\_QL
allows you to specify any standard QL colour - the parameters allowed
are the same as for the INK command (in either Standard QL Colour Mode
or COLOUR\_QL mode), which thus allows for you to specify composite
colours as well as palette mapped colours with PALETTE\_QL.


**Example**

BGCOLOUR\_QL 2,7 - sets a red and white checkerboard pattern.


**CROSS-REFERENCE**

Refer to Appendix 16 and :ref:`ink` for more details
on colours.

:ref:`bgcolour-24` is similar.

:ref:`bgimage` may be used to set a screen image
as the wallpaper.

--------------


..  _bgcolour-24:

BGCOLOUR\_24
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BGCOLOUR\_24 [#ch,] colour                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

This is similar to BGCOLOUR\_QL in that it allows you to set a wallpaper
to cover the whole of the available screen (in any resolution).

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

BGCOLOUR\_24 allows you to specify any 24 Bit Colour - the parameters
allowed are the same as for the INK command (in COLOUR\_24 mode), which
thus allows for you to specify composite colours.


**Example**

BGCOLOUR\_24 $920000,$ff0092,3 -sets a checkerboard pattern of Dark Red
and Shocking Pink.


**CROSS-REFERENCE**

Refer to Appendix 16 and :ref:`ink` for more details
on colours.

:ref:`bgcolour-ql` gives more detail.

:ref:`bgimage` may be used to set a screen image
as the wallpaper.

--------------


..  _bget:

BGET
====

+----------+----------------------------------------------------------------------------+
| Syntax   || BGET [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or|
|          || BGET [#ch,] [item                                                         |
+----------+----------------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                                      |
+----------+----------------------------------------------------------------------------+

This command is very similar to GET, although this only fetches one byte
at a time (in the range 0..255) from the given channel (default #3).

Each item to be fetched must therefore be either an integer or a
floating point variable, for example: BGET #3\\100,byte1%,keying

If the channel specified is not a file, then the command will wait for a
key to be pressed for each item, and then set the value of each item to
the character code of the key pressed.

As with GET, the items will be fetched from the current (or specified)
file position, which is taken to be an absolute distance from the start
of the file. If no item is specified, then the first variant can be used
to set the current file position. position will be updated (unless it is
an expression!) with the current file position at the end of the
command.


**Examples**

BGET #3\\100 Set file pointer on #3 to position 100.

BGET a% Read the byte at the current file pointer in channel #3.


**NOTE 1**

Current versions of the Turbo and Supercharge compilers are not able to
compile programs which use BGET.


**NOTE 2**

Characters which are read from a channel using BGET are affected by TRA.


**SMS NOTE**

BGET will accept a parameter which is a sub-string of a string array to
read in several bytes at once. For example:

DIM a$(10):a$=FILL$(' ',10):BGET #3,a$(4 to 7)

This will read 4 bytes from channel #3 into the middle of a$.

Please note that a$ cannot be an empty string if this is to work since
the sub-string would not be valid!!


**CROSS-REFERENCE**

See :ref:`bput`, :ref:`put`,
:ref:`get`. :ref:`fpos` allows you
to find out the current file position.
:ref:`truncate` allows you to truncate a file to
the current file position. :ref:`peek` fetches one
byte from memory.

:ref:`open-dir` contains an example of the use
of :ref:`bget`.

--------------


..  _bgimage:

BGIMAGE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  BGIMAGE [#ch,] filename                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

This command allows you to load a screen image as a wallpaper to cover
the whole of the available screen (in any resolution).

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

The file will need to be a screen snapshot - the Photon JPEG viewer can
be used to convert JPEG files to screen snapshots.


**Example**

BGIMAGE win1\_wallpapers\_cats - load a wallpaper.


**NOTE**

The command expects the screen to have been saved in the current
resolution and colour depth, therefore any attempt to load a screen
image in a different resolution or colour depth to the one in existence
when the screen was saved will result in a corrupt image.


**CROSS-REFERENCE**

:ref:`sbytes` gives details on how to store a
screen on disk.

In many ways, this command is similar to
:ref:`loadpic`, except that it caters for
non-standard QL resolutions and colour depths.

:ref:`bgcolour-ql` and
:ref:`bgcolour-24` can be used to set a
single colour wallpaper.

--------------


..  _bicop:

BICOP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BICOP                                                            |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

This procedure will send a screen dump to the port ser1hr - it is aimed
at Epson compatible dot-matrix printers and uses grey scales to
represent the different colours. It is up to you to set the BAUD rate.


**NOTE**

It will only work on a standard 512x256 screen stored at $20000.


**CROSS-REFERENCE**

:ref:`sdump` is more flexible.

See also :ref:`hco` and :ref:`fco`.

--------------


..  _bin:

BIN
===

+----------+-------------------------------------------------------------------+
| Syntax   || BIN (binary$)  or                                                |
|          || BIN (binary) where binary=0..111111                              |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function returns the decimal value of a binary number (given as a
string). For small numbers, a floating point number can be used but will
cause problems if this is not a valid binary number.


**Examples**

(1) PRINT BIN ( '1001' )

will print the value 9

(2) As it stands, the function BIN cannot handle binary dots

(eg. 1001.101=9.625), therefore a BASIC function to provide this
facility is:

::

    100 DEFine FuNction BINN(a$)
    110   LOCal i,dot,dota,value_a,loop
    120   IF a$='' THEN RETurn 0
    130   FOR i=1 TO LEN(a$): IF a$(i) INSTR '10.'=0: REPORT -17: STOP
    140   dot='.' INSTR a$: IF dot=0 THEN RETurn BIN(a$)
    150   value_a=0:dota=0
    160   IF dot>1 THEN value_a=value_a+BIN(a$(1 TO dot-1))
    170   IF '.' INSTR a$(dot+1 TO ): REPORT -17: STOP
    180   REPeat loop
    190     IF dot>=LEN(a$):EXIT loop
    200     a$=a$(dot+1 TO )
    210     dot='1' INSTR a$: IF NOT dot THEN EXIT loop
    220     value_a=value_a+1/(2^(dot+dota)):dota=dota+dot
    230   END REPeat loop
    240   RETurn value_a
    250 END DEFine BINN


**NOTE**

Any digit other than 0 or 1 will produce odd results.


**CROSS-REFERENCE**

:ref:`bin-dlr` works the other way around, converting
decimal numbers into their binary equivalent. See
:ref:`hex` and :ref:`hex-dlr` for the
hexadecimal versions. :ref:`bit-pct` is also useful.

SMS users can achieve the same thing by using, for example :ref:`print`\ %1001 instead of :ref:`print`\ BIN('1001').

--------------


..  _bin-dlr:

BIN$
====

+----------+-------------------------------------------------------------------+
| Syntax   || BIN$ (decimal,digits)  or                                        |
|          || BIN$ (decimal [,digits]) (THOR only)                             |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function converts a signed integer decimal number to the equivalent
binary number (to a specified number of binary digits ranging from 1 to
32). Negative values are also handled correctly.


**Examples**

(1) BIN (BIN$ (x,4)) = x

if x is any number between 0 and 15.

(2) A short function to compare two numbers using the mathematical 'OR'
function. Do note however that the same function already exists on the
QL, and the commands

PRINT 100\|\|10 and PRINT \_or(100,10) have exactly the same effect,
although the BASIC version below does enable you to see what the
function actually does:

::

    100 DEFine FuNction _or(x,y)
    110  a$=BIN$(x,32): b$=BIN$(y,32)
    115  PRINT a$,b$
    120  c$=FILL$('0',32)
    130  FOR i=1 TO 32
    140    IF a$(i)=1 OR b$(i)=1: c$(i)=1
    150  END FOR i
    155  PRINT c$
    160  RETurn BIN(c$)
    170 END DEFine _or


**THOR XVI NOTE**

The THOR XVI version of BIN$ will accept a value of zero for digits {or
even the command in the form BIN$(decimal)}. In both of these cases the
result is returned in the least number of Binary digits necessary to
store the number, for example: PRINT BIN$(10)gives the result 1010.


**THOR XVI WARNING**

A second parameter of zero may crash some versions of this command other
than on v6.41 of the THOR XVI.


**CROSS-REFERENCE**

See :ref:`bin` and :ref:`hex`,
:ref:`hex-dlr`. Also refer to
:ref:`bit-pct`.

--------------


..  _binom:

BINOM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BINOM (n,k)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function BINOM returns the value of the binomial coefficient which
is defined as the following (where n >= k):

n \* (n - 1) \* (n - 2) \* ... \* (n - k + 1) ) / ( 1 \* 2 \* ... \* k )
or, FACT(n) / ( FACT(k) \* FACT(n-k) )

The binomial coefficient gives the kth coefficient of the variables in
an expanded binomial series, this is called the binomial theorem:

(a+b)^n = BINOM(n,0) \* a^n + BINOM(n,1) \* a^(n-1) \* b + BINOM(n,2) \*
a^(n-2) \* b^2 + ... + BINOM(n,n-1) \* a \* b^(n-1) + BINOM(n,n) \* b^n

The binomial coefficient can also be used to calculate combinations and
probabilities. As the example shows, it is important to know the
mathematical theory behind this function to make full use of it.


**Example**

The following program calculates 2\ :sup:`n`:

::

    100 n=10: s=0
    110 FOR k=0 TO n: s=s+BINOM(n,k)
    120 PRINT s,2^n

It can be optimised by exploiting the fact that:

BINOM (n,k) = BINOM (n,n-k) which saves half of the loops:

::

    100 n=10
    110 IF NOT n MOD 2 THEN s=BINOM(n,n DIV 2): ELSE s=0
    120 FOR k=0 TO n DIV 2 - NOT n MOD 2
    130   s=s+2*BINOM(n,k)
    140 END FOR k
    150 PRINT s,2^n


**CROSS-REFERENCE**

:ref:`fact`\ .

--------------


..  _bit-pct:

BIT%
====

+----------+-----------------------------------------------------+
| Syntax   | BIT% (number%,bitnr) with bitnr=0..15               |
+----------+-----------------------------------------------------+
| Location | BIT                                                 | 
+----------+-----------------------------------------------------+

All numbers are internally stored as a series of values, each of which
can either be 1 or 0 (or, if you prefer, true or false). This is known
as the binary system. The set of digits which make up a binary number
are known as a stream of bits.

The function BIT% returns the status of a specified bit of an integer
number%, a value of either 0 or 1. Bit 0 means the rightmost bit,
whereas bit 15 would be the leftmost.

**Example 1**

Here is a function which converts a number to the binary
system. It allows a greater range than BIN$ and needs just one
parameter. The first version needs the REV$ and LOG2 extensions, the
second does not.

Version 1:

::

    100 DEFine FuNction BIT$ (x%)
    110  LOCal b$,i: b$=""
    120  FOR i=0 TO LOG2(ABS(x%)):b$=b$ & BIT%(x%,i)
    130  RETurn REV$(b$)
    140 END DEFine BIT$

Version 2:

::

    100 DEFine FuNction BIT$ (x%)
    110  LOCal b$,i: b$=""
    120  FOR i=0 TO LN(ABS(x%))/LN(2): b$=BIT%(x%,i) & b$
    130  RETurn b$
    140 END DEFine BIT$

**Example 2**

The following logical function returns 1 (true) if the given parameter
was an upper case character, or 0 (false) if it was lower case. This
function will work with all international character sets supported on
the original QL.

::

    100 DEFine FuNction UPPER% (c$)
    110  RETurn NOT BIT%(CODE(c$),5) ^^ BIT%(CODE(c$),7)
    120 END DEFine UPPER%

In any given character, bit 5 indicates the case and bit 7 the character
set.


**CROSS-REFERENCE**

:ref:`bin-dlr` also converts a decimal number to a
binary and :ref:`bin` back again.
:ref:`upper-dlr` returns a string in upper characters.

The length of a number x in binary form is :ref:`int`\ (LOG2 (ABS
(x))+1) .

--------------


..  _bld:

BLD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  BLD                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on double
strike ('bold') on an EPSON compatible printer:

PRINT BLD is the same as PRINT CHR$(27)&"G"


**Example**

LPRINT "I " & BLD&"hate"&NRM & " these functions."


**CROSS-REFERENCE**

:ref:`norm`, :ref:`el`,
:ref:`dbl`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`, :ref:`esc`,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _block:

BLOCK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BLOCK [#channel,] width, height, x, y, colour                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command draws a block of size width x height at position x,y of the
given colour in the specified window (default #1). Both the position and
the block size are given in absolute pixel co-ordinates, with the
maximum ranges specified by the physical size of the window.

This means that for example, in a window which is defined as
448x200a32x16, the maximum block which can be drawn is a block of size
448 x 200 in position (0,0). You can also use OVER to produce other
effects with BLOCK.

As with other graphics commands, the colour can be made up of up to
three parameters, giving the background, contrast and stipple pattern
(composite colours).


**Example**

A program printing out the set of numbers 1 to 100 and then quickly
recolouring the two halves of the window:

::

    100 WINDOW 300,60,102,56
    110 PAPER 0: CLS
    120 FOR i=1 TO 100: PRINT !i!
    130 OVER -1
    140 BLOCK 150,60,0,0,7
    150 BLOCK 150,60,150,0,2
    160 OVER 0


**NOTE 1**

Some ROMs (not SMS) will allow you to specify blocks which lie partly
outside of a window without reporting the error 'Out of Range'. However,
this can also crash some ROMs!


**NOTE 2**

Odd values for width and x are always rounded down to an even number
(eg. 23 pixels wide becomes 22 pixels). This is to ensure compatibility
between MODE 4 and MODE 8. The only problem is that you cannot specify a
block one pixel wide, or even have a gap of one pixel between two
blocks.


**NOTE 3**

Unless you have a Minerva ROM or SMS, you cannot draw a block 512 pixels
wide - you need to use two adjacent blocks instead!


**NOTE 4**

BLOCK provides an extremely quick way of drawing horizontal or vertical
lines on screen.


**MINERVA NOTE**

Early versions of Minerva (pre v1.83) contained code to ensure that the
given block would appear wholly within the specified window. However,
later versions had to be altered to ensure compatibility with certain
programs. These later versions allow width, height, x and y to be within
the range -32768...32767 - only that part of the block (if any) which
appears in the given window will be drawn!

For example:

BLOCK 200,10,-20,255,7 has the same effect as:

BLOCK 180,1,0,255,7


**CROSS-REFERENCE**

:ref:`ink` contains information concerning composite
colours.

--------------


..  _blook:

BLOOK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BLOOK (tofind$, adr1 TO adr2)                                    |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

See SEARCH but note the different syntax. The string being looked for by
BLOOK is not case-sensitive.

--------------


..  _bls:

BLS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  BLS time%                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SERMouse                                                         |
+----------+-------------------------------------------------------------------+

This command sets up a job which will blank the screen after a certain
amount of time if a key is not pressed or the mouse not moved. The delay
depends on the value of time% (1-20 = seconds), (21-59 = minutes).

To turn off this function, use time%=0.

Pressing a key or moving the mouse will reactivate the screen.


**CROSS-REFERENCE**

See :ref:`a-blank`.

--------------


..  _bmove:

BMOVE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BMOVE adr1a, adr1b, adr2                                         |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

BMOVE is a procedure which copies the whole of the memory stored between
the two addresses adr1a and adr1b to the new address pointed to by adr2,
so the number of bytes moved is adr1b-adr1a.


**Example**

Dump some memory to screen (note that this only works with the screen at
131072 and at 512 x 256 resolution):

::

    100 FOR a = 0 TO 10240 STEP 128
    110   BMOVE a, a+HEX("8000") TO HEX("20000")
    120 END FOR a


**WARNING**

Always ensure that there is sufficient available free memory at adr2 to
hold the data from adr1a to adr1b, otherwise your machine is most likely
to crash.


**CROSS-REFERENCE**

It is a good idea to check with :ref:`ver-dlr` if
Minerva is present and use its extremely fast MM.MOVE machine code trap
via :ref:`call` as an alternative to
:ref:`bmove`; this is demonstrated by the example at
:ref:`ldraw`.

:ref:`copy-b`,
:ref:`ttpokem`,
:ref:`copy-w` and
:ref:`copy-l` also allow you to move memory.

--------------


..  _border:

BORDER
======

+----------+------------------------------------------------------------------+
| Syntax   || BORDER [#channel,] size [,colour] or                            |
|          || BORDER [#channel] Location: QL ROM                              |
+----------+------------------------------------------------------------------+
| Location || QL ROM                                                          |
+----------+------------------------------------------------------------------+

This command allows you to add a coloured border around the inside of
the edge of the specified window (default #1). If the second syntax is
used, this will turn off the border on the specified window - this is
the same as:

BORDER [#channel,] 0

If a border is present around the window, the physical size of the
window is altered, so that PRINT and LINE commands (for instance) will
not overwrite the border. Please note however, that the window is reset
to its original size prior to a BORDER command and therefore two
successive border commands only have the same effect as the second
BORDER command on its own.

If the specified size is too large to fit in the given window, the error
'Out of Range' will be reported.

As with other graphics commands, colour can actually be up to three
parameters forming a composite colour.

For example: BORDER #2,2,4

has the same effect as BORDER #2,2,4,4,3

or even BORDER #2,2,4,4

If no value is given for colour a transparent border will be added to
the given window. This means that a border will be created, but anything
which already appears in that border will not be affected.

Once the border has been re-drawn the cursor is automatically placed at
the top left hand position (0,0) just inside the border.


**Examples**

To produce a screen with a title, allowing you to scroll

text and do all sorts on the screen without affecting the title:

::

    100 MODE 4
    110 WINDOW 448,200,32,16
    120 PAPER 0: BORDER 0 : CLS
    130 AT 0,30: PRINT "THE TITLE PAGE"
    140 BORDER 9
    150 PAPER 2:CLS

To produce a 'take-off' effect:

::

    100 MODE 8
    110 WINDOW 448,200,32,16
    120 FOR i=1 TO 99
    130   BORDER i,2
    140 END FOR i


**NOTE 1**

If a border appears in a window, there is always a width of at least two
pixels down the sides to ensure that the border will appear in MODE 8.
Take the width value and if it is odd, add one for the width down the
sides of the window.


**NOTE 2**

The second syntax will not work on Minerva (pre v1.79) and the THOR XVI
- you will need to specify a width of zero instead.


**CROSS-REFERENCE**

:ref:`ink` describes composite colours.

Also see :ref:`window`.

--------------


..  _bpeek-pct:

BPEEK%
======

See :ref:`bpeek-l` below.


..  _bpeek-w-pct:

BPEEK\_W%
=========

See :ref:`bpeek-l` below.


..  _bpeek-l:

BPEEK\_L
========

+----------+---------------------------------------+
| Syntax   || BPEEK% (offset)    and               |
|          || BPEEK\_W% (offset) and               |
|          || BPEEK\_L (offset)                    |
+----------+---------------------------------------+
| Location || BPEEKS, BPOKE (DIY Toolkit - Vol B)  |
+----------+---------------------------------------+

These three functions are exactly the same as BASIC\_B, BASIC\_W and
BASIC\_W, and suffer with the same problem that they always access the
SuperBASIC variables of Job 0 (SuperBASIC) and cannot therefore be used
on a Multiple BASIC interpreter.


**CROSS-REFERENCE**

See :ref:`basic-w` and
:ref:`basic`.

:ref:`bpoke` and related commands allow you to alter
the values of the SuperBASIC variables.


..  _bpoke:

BPOKE
=====

See :ref:`bpoke-l` below.


..  _bpoke-w:

BPOKE\_W
========

See :ref:`bpoke-l` below.


..  _bpoke-l:

BPOKE\_L
========

+----------+---------------------------------+
| Syntax   || BPOKE offset, value   and      |
|          || BPOKE\_W offset, value         |
|          || BPOKE\_L offset, value         |
+----------+---------------------------------+
| Location || BPOKE (DIY Toolkit - Vol B)    |
+----------+---------------------------------+

These three commands allow you to alter the value of SuperBASIC
variables in much the same was as the extended POKE commands do on
Minerva and SMS.

BPOKE\_W and BPOKE\_L were added in v0.7 of the toolkit.

They unfortunately always access the SuperBASIC variables of Job 0
(SuperBASIC) and cannot therefore be used on a Multiple BASIC
interpreter.


**CROSS-REFERENCE**

See :ref:`poke`.

:ref:`bpeek-pct` and related commands allow you to
read the values of the SuperBASIC variables.

--------------


..  _bput:

BPUT
====

+----------+----------------------------------------------------------------------------+
| Syntax   || BPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or|
|          || BPUT [#ch,] [item                                                         |
+----------+----------------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                                      |
+----------+----------------------------------------------------------------------------+

This command is the complement to BGET, in that it places the byte value
for each item into the specified channel (default #3) at the current
file position (or the specified position if the first variant is used).

If the value of item is outside the range 0...255, an overflow error
will result, whereas if item is not an integer or floating point number,
then an error in expression will result. On the other hand, if a
non-integer floating point is given as an item, then the value will be
rounded to the nearest integer and this placed into the given channel.

Provided that the second variant of this command is used, the specified
channel need not be open to a file, in which case each item is taken as
being a character, for example: BPUT #2,72,101,108,108,111

will print the word Hello in channel #2. This can of course be used to
send control codes to a printer much more easily than the PRINT command.

For example:

BPUT #3,27,70

is a lot easier to understand than:

PRINT #3,CHR$(27)&'F'

to switch off emphasised mode.

As with BGET, if no item is specified, then the first variant can be
used to set the current file position. position will also be updated at
the end of the command to contain the current file pointer.


**Example**

BPUT #ch,4.5,'100',52,a+1

places the values 5,100,52 and (a+1) at the current file position.


**NOTE**

The codes sent by BPUT are affected by any translate that is active (see
TRA).


**SMS NOTE**

BPUT will now accept string parameters to allow you to pass several
bytes at a time, for example: a$='Hello':BPUT #3,a$

is equivalent to: BPUT #2,72,101,108,108,111


**CROSS-REFERENCE**

See :ref:`fgetb`, :ref:`bput`,
:ref:`put`, :ref:`get`,
:ref:`lput`, :ref:`uput` and
:ref:`wput`.

:ref:`fpos` allows you to find the current file
position.

:ref:`truncate` allows you to truncate a file to
the current file position.

:ref:`peek` fetches one byte from memory.

:ref:`uput` allows you to send bytes without them
being translated.


--------------



..  _break-on:

BREAK\_ON
=========

See :ref:`break-off` below.



..  _break-off:

BREAK\_OFF
==========

+----------+---------------+
| Syntax   || BREAK\_ON    |
|          || BREAK\_OFF   |
+----------+---------------+
| Location || TinyToolkit  |
+----------+---------------+

The command BREAK\_OFF de-activates the functioning of both
<CTRL><SPACE> (the Break Key) and <CTRL><F5> (the Pause Screen key)
during the running of interpreted SuperBASIC programs so that they
cannot be stopped by the user unless they stop either due to an error or
a STOP command.

The command BREAK\_ON reactivates both keys.

The function BREAK returns the current status:

IF BREAK=1 means the Break Key is active, while

IF BREAK=0 means that it is inactive.


**NOTE 1**

BREAK\_OFF may not work on Minerva ROMs unless you have v1.10 or later
of the Toolkit, which uses the new Minerva System Xtensions to overcome
any problem.


**NOTE 2**

BREAK\_OFF does not currently work with SMS.


**CROSS-REFERENCE**

:ref:`stop` terminates interpreted programs even if
the Break Key is disabled. Do not confuse with the command
:ref:`break`.

--------------


..  _break:

BREAK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BREAK switch                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The command BREAK takes the parameter of either ON (=1) or OFF (=0) and
enables or disables the ability to stop a program with the Break key
<CTRL><SPACE> (and <ESC> on Minerva) accordingly.


**Example**

::

    100 WINDOW 136,100,100,40: INK 7
    110 BORDER 1,4,3: PAPER 3,0: CLS
    120 SCALE 100,-50,-50: POINT 0,0
    130 fast=ASK( "Fast (y/n)" ): CLS
    140 BREAK fast
    150 FOR n=0 TO 4000
    160   IF BREAK% THEN AT 0,0: PRINT n
    170   x=RND(-50 TO 50): y=RND(-50 TO 50)
    180   z=SIN(PI*SQRT(x*x+y*y)/10)+1
    190   IF z > 2*RND THEN POINT x,y
    200 END FOR n
    210 BREAK ON


**NOTE 1**

After the Break key has been disabled and re-enabled, if you try to
Break from the interpreter's command window #0 it might be disturbed.
Instead of printing 'not complete' (error -1) in #0 when <CTRL><SPACE>
is pressed, that message may appear in #2 and Break will work only once,
the interpreter will not accept any further Breaks... A single <ENTER>
after you initially press the Break key cures this.


**NOTE 2**

This command does not work under SMS.


**CROSS-REFERENCE**

See also :ref:`break-pct`,
:ref:`freeze` and
:ref:`freeze-pct`.

Do not confuse BTool's command :ref:`break` with
TinyToolkit's function :ref:`break` (although you
can use both in the same program!)

--------------


..  _break-pct:

BREAK%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  BREAK%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function BREAK% returns the current state as to whether the Break
key is enabled, either ON or OFF.


**CROSS-REFERENCE**

See :ref:`break`!!

--------------


..  _btool-ext:

BTool\_EXT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  BTool\_EXT                                                       |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command is similar to TK2\_EXT and TINY\_EXT, in that it installs
BTool so that keyword definitions with the same name as those provided
in other Toolkits are overwritten with the Btool definition.


**WARNING**

BTool\_EXT will hang SuperBASIC if the BTool Toolkit has been loaded
into the common heap - this is most likely to happen on later versions
of Toolkit II where LRESPR uses the common heap if jobs are running. Try
LINKUP instead.

See also :ref:`kill` which removes all current jobs.

--------------


..  _btool-rmv:

BTool\_RMV
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  BTool\_RMV                                                       |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

All keywords implemented by BTool (except BTool\_EXT) are removed from
the SuperBASIC name list. The Toolkit itself remains in memory and can
be re-activated with BTool\_EXT.

--------------


..  _btrap:

BTRAP
=====

+----------+-----------------------------------------------------+
| Syntax   | BTRAP #ch,key [,d1 [,d2 [,d3 [,a1 [,a2 ]]]]]        |
+----------+-----------------------------------------------------+
| Location | TRAPS (DIY Toolkit Vol T)                           | 
+----------+-----------------------------------------------------+

This command is identical to QTRAP, except that the address parameters
(a1 and a2) are taken to be relative to A6, therefore allowing you to
access system calls which need to access the SuperBASIC variables, so
that you can for example save and load arrays direct!!


**WARNING**

Several TRAP #3 calls can crash the computer - make certain that you
know what you are doing!


**CROSS-REFERENCE**

See :ref:`io-trap`,
:ref:`mtrap` and :ref:`qtrap`.

Any return parameters can be read with
:ref:`datareg` and
:ref:`addreg`.

:ref:`cls`, :ref:`pan` and
:ref:`scroll` can also be used to call TRAP #3.

Refer to the QDOS/SMS Reference Manual (Section 15) for details of the
various system TRAP #3 calls.

Also refer to the DIY Toolkit documentation for this command.

--------------


..  _button-pct:

BUTTON%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  BUTTON% (flag)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

This function can be used to find out if any mouse buttons have been
pressed and if so which ones. Unfortunately, you cannot use this to find
out if a button has been pressed twice quickly in succession (known as
double-clicking).

The value of flag is used to tell the function which buttons you wish to
interrogate:

-  0 - Has any key been pressed ? If so, the value returned will be 0
   plus the following numbers if the relevant key(s) has been pressed:

   -  +1 - Button One Pressed
   -  +2 - Button Two Pressed
   -  +4 - Button Three Pressed

-  1 - Has Button One been pressed (this is the left hand mouse button)?
   If so 1 is returned, otherwise 0.
-  2 - Has Button Two been pressed (this is the right hand mouse
   button)? If so, 1 is returned, otherwise 0.
-  3 - Has Button Three been pressed (this is the middle mouse button)?
   If so, 1 is returned, otherwise 0.


**Example**

A routine to wait for the user to press the right and left mouse button
at the same time:

::

    100 DEFine PROCedure WAIT_MOUSE
    110 REPeat mloop
    120   IF BUTTON%(0)=1+2:RETurn
    130 END REPeat mloop
    140 END DEFine

    
**CROSS-REFERENCE**

:ref:`x-ptr-pct`, :ref:`y-ptr-pct`
and :ref:`ptr-fn-pct` can also be used to
interrogate the mouse.

--------------


..  _bver-dlr:

BVER$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BVER$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the version number of the Beule Toolkit. This may
be useful if a program makes use of commands or functions which were not
supported by older versions.

-------


..  _bytes-free:

BYTES\_FREE
===========

+----------+-------------------------------------------------------------------+
| Syntax   | memory = BYTES\FREE                                               |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This simple function  returns the amount of memory known by the system to be free.  The answer is returned in bytes, see also :ref:`kbytes-free`.  For the technically  minded, the free memory is  considered  to be that  between the addresses held in the system variables SV\_FREE and SV\_BASIC.

**EXAMPLE**

::

    ...
    2500 freeMemory = BYTES_FREE
    2510 IF freeMemory < 32 * 1024 THEN
    2520    REMark Do something here if not enough memory left...
    2530 END IF
    ...


**CROSS-REFERENCE**

:ref:`kbytes-free`.


