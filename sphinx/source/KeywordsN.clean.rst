
==========
Keywords N
==========

TODO
====

- Various references to ESC and QRD are broken, as these keywords do not exist.



..  _ndim:

NDIM
====

+----------+-------------------------------------------------------------------+
| Syntax   |  NDIM (array)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

Identical to NDIM%.

--------------


..  _ndim-pct:

NDIM%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  NDIM% (array)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  NDIM                                                             |
+----------+-------------------------------------------------------------------+

This function returns the number of dimensions of a given array. DIMmed
variables of any type (floating point, integer and string) are legal
parameters.

**Example**

::

    DIM test% (10,50,2) 
    PRINT NDIM% (test%)
    
gives the answer 3.

**NOTE**

String arrays often have one more dimension than the number of elements
which they can hold. This extra dimension sets the maximum length of
each element, for example:: 

    DIM name$(100,20) 

sets aside space in the array name$ for 100 strings, each of which can be a maximum of 20
characters long::

    PRINT NDIM%(name$) returns 2.

**CROSS-REFERENCE**

:ref:`dimn` finds the defined size of each dimension
and can be used to replace :ref:`ndim-pct`.
:ref:`dim` declares an array.
:ref:`ndim` is exactly the same as
:ref:`ndim-pct`.

--------------


..  _net:

NET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NET x%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command sets the computer's station number for use in a network to
x%. A station can have any integer number in the range 1..128 (although
see Note below). Each station in the network should have a different
station number to avoid confusion. When the computer is first switched
on (or reset), it is given the station number 1.

**Example**

::

    NET 12

sets the station number to 12.

**NOTE**

Many implementations allow a station number in the range 1..127 (SMS
allows 1..255), although there is still a maximum of 64 computers which
can be linked into the network at any one time using standard QLs.

Auroras allow more to be linked together.

**CROSS-REFERENCE**

Please see the Appendix concerning Networks. See also
:ref:`snet` and :ref:`mnet`.

--------------


..  _netbeep:

NETBEEP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETBEEP delay, pulses                                            |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command allows you to send signals through the QL's network ports
- if you plug a pair of earphones into the network port (instead of a
Network lead), you will be able to hear the sound generated - this can
even work alongside the QL's BEEP command to provide the QL with
rudimentary polyphonic sound. In fact, some of the Spectrum emulators
for the QL use this feature to provide the QL with Spectrum-like sound.

The first parameter tells the command the length of the delay between
pulses sent to the Network port - the higher the delay, the lower will
be the pitch. 

The second parameter tells the command the number of
pulses to send to the port - each pulse will send an electrical signal
through the network port (equivalent to turning a switch on and then
back off). 

You can also use this command (in conjunction with NETPOLL on
other computers in the Network to test the speed settings for Flexynet)
- simply send a series of bytes over the Flexynet (using NETBEEP) and
check that they have been received correctly at the other end by using
NETPOLL. If the bytes are incorrect, you may need to increase the delay.

**NOTE**

The units used by both parameters are quite arbitrary and therefore some
experimentation may be required.

**CROSS-REFERENCE**

Refer to the Appendix on Networks to find out more about Flexynet. See
:ref:`netpoll` which allows you to read signals
sent through the network ports. :ref:`netrate`
allows you to alter the speed of the Flexynet and
:ref:`netread` /
:ref:`netsend` can be used to read and send
multiple bytes.

--------------


..  _netpoll:

NETPOLL
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETPOLL address, bytes                                           |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command allows you to sample electrical signals sent over the QL's
Network, which can be used to decode any digital data stream, such as
information sent by cassettes tapes (this method has been used by some
Spectrum emulators for the QL to allow you to load Spectrum games direct
from tape). 

You need to pass two parameters - the address of a place in
memory where the data which is read is to be stored, followed by the
number of bytes which can be stored at the address. 

For each byte to be
stored at the specified address, NETPOLL
'listens' to the QL's Network ports and whenever an electrical pulse is
received by the port (for example as sent by NETBEEP), then NETPOLL
counts the length of this pulse and sets the data byte to the relevant
value, moving onto the next available byte (or returning to BASIC if it
has reached the end of the storage area). 

The value of the data byte
will be between 0 and 254, with the delay being the difference between
the value and 255 (hence a value of 127 shows a delay of approximately
twice a value of 254). If a value is 255, this indicates that the timer
ran out before a pulse arrived.

**NOTE**

An odd number of bytes at the storage area will be rounded up, so that
an even number of pulses will always be read.

**CROSS-REFERENCE**

The amount of time that :ref:`netpoll` will wait
for a pulse is affected by :ref:`netrate`\ 0,0,x. See
:ref:`netbeep` which sends signal tones along the
network ports. Also see
:ref:`netrate`,\ :ref:`netread`
and\ :ref:`netsend`.

--------------


..  _netrate:

NETRATE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETRATE transmit\_delay, reception\_delay, timeout               |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command is at the heart of the Flexynet philosophy and allows you
to alter the speed of the QL's networks (as regards NETSEND and
NETREAD), so that you can match the speed of the network ports to the
various computers which are linked together over the network. This
enables different machines to talk to each other substantially more
quickly than using the Network drivers supplied with the QL or Toolkit
II. 

Values are sent over the Network ports as pulses equivalent to bits,
with eight bits representing one byte (0...255) - the pulse is an
electrical signal, either 1 or 0 (on or off). The three parameters are
all in arbitrary units and if they are specified as zero, any existing
value will remain unchanged. They are used as follows: 

- Transmit\_delay - this specifies the amount of time that the sending machine will alter
  the voltage for on the network to signify either a 1 or a 0 bit. This
  needs to be higher than the reception delay on the receiving machine as
  the receiving process is fundamentally slower than the transmission
  process. The higher the value, the longer the delay. 
  
- Reception\_delay - this specifies the amount of time Flexynet will wait for changes in the
  voltage over the network ports. 
  
  If the change occurs after Flexynet has counted up to the reception\_delay value, then a bit of 0 is assumed,
  otherwise a bit of 1. Once eight bits have been received then a byte
  made up of those eight bits is stored in memory. For example: CHR$(10)
  is represented by the bits 0 0 0 0 1 0 1 0 This can be seen by::

    PRINT BIN$ (10,8)

- Timeout - this represents a timing loop which Flexynet will wait for
  the next pulse over the net - if nothing is received in this time, then
  a 'not complete' error will be reported. This value will need to exceed
  the reception\_delay parameter by a comfortable margin. The easiest way
  to match up the required parameter values for two machines connected
  using Flexynet is to send a copy of one machine's screen to the other
  machine and compare the display. To do this, enter the command::
  
    NETREAD 131072,32768
    
  on the receiving machine, then enter the command:: 
  
    NETSEND 131072,32768
    
  on the sending machine. 
  
  If the NETRATE parameters are incorrect, you
  will notice that the displays do not match - either increase the
  reception\_delay on the receiving machine or increase the
  transmit\_delay on the sending machine, making notes of the values which
  you have tried at either end. 
  
It is difficult to give any advice on the
parameters to use as it depends on the expansion boards being used with
your particular QL, as well as the speed of the ZX-8301 chip which forms
part of the QL's motherboard. However, the author cites the following
test results: 

- Standard QL to Standard QL (both with code in ROM or fast
  RAM such as CST 512K expansion board):: 
  
    NETRATE 5,3,127

  on both machines

- Gold Card on British QL to Gold Card on Foreign QL::

    NETRATE 8,4,0
    
on both machines.

- Gold Card on Foreign QL to Gold Card on British QL::

    NETRATE 33,12,0
 
 on both machines 

- Standard QL (with code in ROM or fast RAM such
  as CST 512K expansion board) to Gold Card on Foreign QL::
  
    NETRATE 2,2,127
  
  on the Standard QL::
  
    NETRATE 20,7,127 
    
  on the Gold Card QL

**NOTE**

Flexynet will not work on machines which do not use a 68000 or 68008
chip (for example QXLs or Super Gold Card), unless the Cache is disabled
(see CACHE\_OFF). It also requires an expanded machine to work
properly.

**CROSS-REFERENCE**

Refer to the Networks Appendix for further details. See
:ref:`netvar-pct` which allows you to read the
various speed settings. Also see :ref:`netread`
and :ref:`netsend`

--------------


..  _netread:

NETREAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETREAD address, bytes                                           |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command will attempt to read the specified number of bytes over
the Network port using the Flexynet driver and store any bytes it
receives at the area in memory starting with the specified address. This
area of memory should therefore really be set aside with ALCHP or RESPR
before use (unless you know that the area of memory can be altered (such
as the screen memory - see SCREEN).

**NOTE 1**

This command should only be used in conjunction with NETSEND. Do not
attempt to use any other network drivers whilst one machine has used
this command.

**NOTE 2**

This command must be used before the NETSEND command is issued, if it is
to catch the data sent by the transmitting machine.

**CROSS-REFERENCE**

See :ref:`netrate` which allows you to set the
speed of the receiving machine to match the speed of the sending
machine. Also see :ref:`netsend`.

--------------


..  _netsend:

NETSEND
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETSEND address, bytes                                           |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command will attempt to send the specified number of bytes over
the Network port using the Flexynet driver, reading the bytes to be sent
from the area in memory starting with the specified address.

**NOTE**

Please refer to the notes given for NETREAD.

**CROSS-REFERENCE**

See :ref:`netrate` which allows you to set the
speed of the transmitting machine to match the speed of the receiving
machine. Also see :ref:`netread`.

--------------


..  _netvar-pct:

NETVAR%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETVAR% (parameter)                                              |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This function returns the various values set with the NETRATE command.
The possible values of parameter are:

+-----------+-------------------------------+
| Parameter | Meaning                       |
+===========+===============================+
| 1         | Return the Transmission Delay | 
+-----------+-------------------------------+
| 2         | Return the Reception Delay    |
+-----------+-------------------------------+
| 3         | Return the Timeout            | 
+-----------+-------------------------------+

**CROSS-REFERENCE**

See :ref:`netrate`.

--------------


..  _net-id:

NET\_ID
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NET\_ID                                                          |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI                                                         |
+----------+-------------------------------------------------------------------+

This function returns the computer's station number set with NET. Other
ROMs can also find out their station number by using::

    PRINT PEEK (SYS_VARS+55)

or::

    PRINT PEEK (!!55)

(the latter syntax being accepted by Minerva and SMS).

**CROSS-REFERENCE**

See :ref:`net` which sets the station number. Also see
:ref:`mnet-pct` and :ref:`snet-pct`

--------------


..  _new:

NEW
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NEW                                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

If the command NEW is issued under the interpreter, the current
SuperBASIC program is removed from memory, the values of all variables
are forgotten, all channels owned by the interpreter (job 0) which have
a number equal to or higher than #3 are closed and the windows #0, #1,
#2 are cleared (in this order). 

The Minerva, THOR XVI and Toolkit II
versions of NEW also disable WHEN ERRor clauses. A bug in JS and MGx
ROMs meant that these clauses could not be disabled once activated. 

From within a compiled program, NEW removes the job from which it was issued
(ie. the current job).

**WARNING**

All data stored in variables is lost.

**CROSS-REFERENCE**

:ref:`clear`, :ref:`kill-a`.
Inside compiled programs, :ref:`new` and
:ref:`stop` are effectively the same.
:ref:`reset` clears the whole system by restarting
it.

--------------


..  _newchan-pct:

NEWCHAN%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  NEWCHAN%                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Function (DIY Toolkit - Vol R)                                   |
+----------+-------------------------------------------------------------------+

When writing / designing SuperBASIC programs, it is essential that you
try to keep the channel numbers as small as possible for two reasons -
compilers only allow a fixed number of channels to be OPENed by a
program (normally 16) and if you OPEN #100,scr (for example), space has
to be created by SuperBASIC in the channel table for channels #1 to #99,
thus wasting a lot of memory if those channels are not used. 

This
function can therefore be quite useful - it looks at the channel table
and returns the number of the next available channel number which can be
OPENed.

**Example**

After::

    NEW
    PRINT NEWCHAN% 
    
will always return 3, as the only channels OPEN will be #0, #1 and #2.

**CROSS-REFERENCE**

:ref:`open` allows you to open a channel.
:ref:`fopen` and similar functions will
automatically open the next available channel number.

--------------


..  _new-name:

NEW\_NAME
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  NEW\_NAME old\_name$, new\_name$                                 |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command allows all keywords, variables, procedures, functions and
device names to be renamed, whether they are in RAM or ROM (except
device names, which must be RAM based), BASIC or machine code
implementations. If a program is loaded when the command is issued, then
all references in that program to the given name will also altered.

**Examples**

- FORMAT can destroy a lot of data. To avoid a catastrophe when an
  alien, unknown BASIC program formats your hard disk for example, you
  could rename FORMAT::

    NEW_NAME "FORMAT" TO "FORMAT_MEDIUM"

  Note that you would need to issue this command before loading the
  program! 
  
- Creating algorithms is very easy and fast in SuperBASIC,
  especially if short variable names like i ,n, q1 are used. But even the
  author him/herself may have difficulty in understanding source code full
  of such meaningless names. The obvious solution: Rename them! - for
  example::

    NEW_NAME "d","dog"

  BASIC programs loaded in memory are amended completely and permanently - at once. 
  
- If you prefer to see all names in capital letters, run this short program:: 

    100 adr=BASICP(32) 
    110 REPeat all_names 
    120   length=PEEK(adr) 
    130   IF NOT length THEN EXIT all_names 
    140   name$=PEEK$(adr+1,length) 
    150   NEW_NAME name$,UPPER$(name$) 
    160   adr=adr+length+1 
    170 END REPeat all_names

**NOTE**

A name may be up to 255 characters long, and because it is only stored
once (in the name table) and represented in a tokenised program by
symbols pointing to the name table, the actual speed of operation will
not be slowed down by using longer names.

**WARNING**

It is possible to rename FORMAT to FORMAT! (for example) but FORMAT! is
an illegal name, can no longer be called from BASIC and may crash some
advanced implementations of SuperBASIC.

**CROSS-REFERENCE**

:ref:`zap` and :ref:`key-rmv`
remove a resident keyword. See :ref:`replace` and
:ref:`alias` as well.

--------------


..  _next:

NEXT
====

+----------+-------------------------------------------------------------------+
| Syntax   || NEXT loop\_variable (inside FOR loops) or                        |
|          || NEXT loop\_name (inside REPeat loops) or                         |
|          || NEXT(SMS only)                                                   |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command forces the program to make the next pass in a loop
structure - the next command to be processed is the first after the
relevant FOR or REPeat instruction. NEXT can be used in both loop
structures, FOR and REPeat.

**NOTE**

If a FOR loop has already reached its last value, NEXT will have no
effect.

**SMS NOTE**

The loop\_name / loop\_variable do not need to be specified, in which
case NEXT merely makes the program make the next pass of the latest
defined FOR or REPeat loop. If NEXT does not appear within a loop
structure, the error 'unable to find an open loop' will be reported. If
however, NEXT is followed by a loop\_name or loop\_variable and that
does not correspond to a currently open loop, the error 'undefined loop
control variable' will be reported.

**CROSS-REFERENCE**

You must study :ref:`for` or
:ref:`repeat` before using
:ref:`next`. :ref:`exit` leaves a
loop.

--------------


..  _nfs-use:

NFS\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   || NFS\_USE newdrive, drive1 [,drive2 [..., drive8]] or             |
|          || NFS\_USE [newdrive]                                              |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

Two QLs, both fitted with Toolkit II on EPROM (or SMS) and connected
via a network cable, can use Toolkit II's file server which is activated
by the FSERVE command. All of the devices on the other QL (provided the
Server job is running on that QL) can then be accessed as if they were a
normal device on the QL wishing to use the facilities. This is achieved
by prefixing the device name by: n<netnr>\_, eg:: 

    DIR n2_flp1_

will show the directory of flp1\_ on station number 2. 

:ref:`net` sets this
station number. 

Two problems do however arise from using this technique:
Firstly, it is a bit annoying to have to type n2\_flp1\_. Secondly, a
lot of programs check the validity of a device by checking if the length
is five characters, the first three characters of which must be letters,
and the fourth character of which must be a digit from 1 to 8 with an
underscore at the end. These programs therefore only allow device names
such as ram6\_, mdv1\_, etc. To fool these programs (and also to shorten
names):: 

    NFS_USE

can be used to create a new device which has a shorter name. The first
parameter is the name of the new drive which can be any description up
to four characters long (there is no need to include a number or
underscore). After this up to eight parameters (each of which can be up
to a maximum of 15 characters) can follow which specify the drive which
should be accessed as (for example): flop1\_, ... flop8\_. It is neither
possible to rename a local drive with::

    NFS_USE test,ram1_
 
(error -12), nor indirectly with NET1::

    NFS_USE test,n1_ram1_

The second example can be entered but any attempted access to test1\_
will lead to a Network aborted message after half a minute of complete
silence. 

The second syntax is used to remove a specified set of
definitions (or, if no parameter is supplied, then all definitions will
be removed) which have been created with NFS\_USE.

**Examples**

::

    NFS_USE flop,n2_flp1_,n3_flp1_
    
creates a device name flop where flop1\_ refers to flp1\_ on QL2 and
flop2\_ to flp1\_ on QL3. NFS\_USE flop clears the above definition.

NFS\_USE without any parameters clears all such definitions.

**NOTE**

Devices can be shared by several remote QLs. Although a file can be read
by several jobs (or QLs) at the same time, QDOS will ensure that a file
cannot be opened by one job (or QL) for writing to whilst another is
trying to read from it (or vice versa). If this occurs, then an error -9
(IN USE) will be reported.

**CROSS-REFERENCE**

:ref:`qrd` renames any local device. See also
:ref:`flp-use`,
:ref:`ram-use` and
:ref:`dev-use`.
:ref:`midinet` and
:ref:`sernet` set up similar fileservers to
:ref:`fserve` -
:ref:`nfs-use` can be used with these fileservers
also, provided that you use :ref:`snet-use` n or :ref:`mnet-use` n to ensure that they are identified by the letter n.

--------------


..  _nix:

NIX
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NIX                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

Nix is a word from colloquial German and means nothing, which is nearly
what this command does. The command is intended to help multitask Qmon,
a monitor program published by Qjump. When the command is issued, a
dummy job named Qmons Nix-Job is created. If the monitor is started to
examine this job, for example by entering::

    QMON con_,4 

(assuming that the dummy job has the job number 4), Qmon can easily be switched on and
off.

--------------


..  _no-clock:

NO\_CLOCK
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  NO\_CLOCK                                                        |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI                                                         |
+----------+-------------------------------------------------------------------+

The command NO\_CLOCK removes the THOR's clock task which is invoked
with CLOCK. This is a much cleaner method of removing the CLOCK job and
can avoid some problems (see the note on CLOCK).

**CROSS-REFERENCE**

:ref:`clock` starts up the clock job on the THOR's
screen.

--------------


..  _nocaps:

NOCAPS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  NOCAPS                                                           |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools                                                       |
+----------+-------------------------------------------------------------------+

If capslock was on, this command forces it to be switched off.

**CROSS-REFERENCE**

See :ref:`caps` for an example.

--------------


..  _nokey:

NOKEY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  NOKEY                                                            |
+----------+-------------------------------------------------------------------+
| Location |  KEYMAN                                                           |
+----------+-------------------------------------------------------------------+

This command temporarily disables all definitions of KEY. Pressing the
key combination <CTRL><CAPS> toggles between enabled and disabled state,
so this is partially equivalent to NOKEY.

**CROSS-REFERENCE**

See :ref:`key` for details.

--------------


..  _norm:

NORM
====

+----------+-------------------------------------------------------------------+
| Syntax   |  NORM                                                             |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to reset an EPSON
compatible printer:: 

    PRINT NORM 
    
is the same as::

    PRINT CHR$(27)&"@"

**Example**

::

    LPRINT NORM

**CROSS-REFERENCE**

:ref:`bld`, :ref:`el`,
:ref:`dbl`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`,\ :ref:`esc`,\ :ref:`ff`,\ :ref:`lmar`,
:ref:`rmar`,\ :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _nor-msg:

NOR\_MSG
========

+----------+-------------------------------------------------------------------+
| Syntax   |  NOR\_MSG                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

The file NOR\_TRA\_rext is supplied with the ST/QL Emulator which
contains translation tables to allow the Emulator to use Norwegian. Once
this file has been LRESPR'd, this function can be used to find the start
of the message translation table to be used with the TRA command. You
can use: TRA NOR\_TRA,NOR\_MSG
to set up the printer and message translation tables for Norway.

**CROSS-REFERENCE**

See :ref:`ger-msg` and
:ref:`nor-tra`. Also see
:ref:`tra`.

--------------


..  _nor-tra:

NOR\_TRA
========

+----------+-------------------------------------------------------------------+
| Syntax   |  NOR\_TRA                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL                                                            |
+----------+-------------------------------------------------------------------+

This is the complementary function to NOR\_MSG and points to the
printer translation table for Norway contained in the file
NOR\_TRA\_rext.

**CROSS-REFERENCE**

See :ref:`nor-msg`.

--------------


..  _not:

NOT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NOT x                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

NOT is an operator which does not combine two operands (unlike +, DIV
or \|\| for example) but only operates on one. In fact, it can be
regarded as a function which returns a value depending on the operand,
except that brackets are not needed around the operand. 

NOT is a logical
operator and returns either 1 if the operand is zero or 0 in any other
case. The following function would work the same way:: 

    100 DEFine FuNction NOT1 (x) 
    110   IF x=0 THEN RETurn 1: ELSE RETurn 0 
    120 END DEFine NOT1

or even shorter:: 

    100 DEFine FuNction NOT2 (x) 
    110   RETurn x=0 
    120 END DEFine NOT2

**Example**

The above replacements of NOT demonstrate that it is not necessary at
all to use NOT. But in context, NOT can clarify an expression and make
program listings more readable. If is\_lamp is a logical variable used
to say whether something is a lamp (is\_lamp=1) or not (is\_lamp=0),
there are (at least) two variants to write the status of is\_lamp to the
screen. Which is easier to read? 

::

    PRINT "This is ";: IF is_lamp=0 THEN PRINT "not ";PRINT "a lamp."
    
or::

    PRINT "This is ";: IF NOT is_lamp THEN PRINT "not ";PRINT "a lamp."

Let's assume lamps is a variable counting lamps and you want to write
out a message if there are no lamps left:: 

    IF lamps=0 THEN PRINT "Sorry, we are out of lamps."
    
or::

    IF NOT lamps THEN PRINT "Sorry, we are out of lamps."
    

Here, the first formulation, which does not use NOT is clearer. 

Until now, the examples have shown that NOT can be used to improve the style
of a program, but there are also ways to put NOT to practical use,
especially if a logical variable is to be set depending on another
logical variable. 

For instance, this procedure will accept such a value
as a parameter and convert it to its logical counterpart for its own
use::

    100 DEFine PROCedure MY_CIRCLE (x,y,r, filled) 
    110   IF filled THEN FILL 1 
    120   CIRCLE x,y,r 
    130   IF filled THEN FILL 0 
    140 END DEFine MY_CIRCLE

As IFs are relatively slow and FILL takes a logical parameter, the
following variant is faster:: 

    100 DEFine PROCedure MY_CIRCLE (x,y,r, filled) 
    110   FILL filled 
    120   CIRCLE x,y,r 
    130   FILL 0 
    140 END DEFine MY_CIRCLE

As FILL cannot handle parameters other than 0 and 1, if filled
could have any value at all (not just 0 or 1), it would be necessary to
change filled so that it was either 0 or 1, by an additional line:: 

    105 IF filled THEN filled=1

NOT is ideal (although here a bit complex!) to avoid the IF
and calculate filled directly::

    110 FILL NOT(NOT filled)

**NOTE**

When dealing with logical variables, the use of NOT to toggle the value,
for example:: 

    filled = NOT filled
    
is invariably quicker than the use of an IF statement:: 

    IF filled THEN filled = 0: ELSE filled = 1

**CROSS-REFERENCE**

Comparisons between any two values (or even two variables) is regarded
as a numeric expression by SuperBASIC. :ref:`if`
handles actual numeric values.

--------------


..  _nrm:

NRM
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NRM                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes to switch back to the normal
font (Pica) on an EPSON compatible printer::

    PRINT NRM
    
is the same as::

    PRINT CHR$(27)&"P".

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`,\ :ref:`dbl`,\ :ref:`enl`,\ :ref:`pro`,\ :ref:`si`,\ :ref:`unl`,\ :ref:`alt`,\ :ref:`esc`,\ :ref:`ff`,\ :ref:`lmar`,\ :ref:`rmar`,\ :ref:`pagdis`,
:ref:`paglen`. :ref:`uput`
allows you to send untranslated bytes to the printer.

--------------


..  _nxjob:

NXJOB
=====

+----------+-------------------------------------------------------------------+
| Syntax   || NXJOB (job\_ID, topjob\_ID)  or                                  |
|          || NXJOB (jobname, topjob\_ID)  or                                  |
|          || NXJOB (jobnr, jobtag, topjob\_ID)                                |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function will work downwards through a 'job tree' to find all of
the current jobs which are both used by the given 'top job' and those
which are used by that second set of jobs. A job tree may look something
like this: 

::

              SuperBASIC
                   |
      +------------+-----------+           
      |            |           |          
    EDITOR      QPAC-FILES    CLOCK
                   |
          +--------+----------+
          |                   |
        QUILL              ABACUS    
        
        
A job can be referred to either by its name (eg. Quill), its job number
and job tag (eg. 1,2) (shown by JOBS), or its job ID (a number
calculated by job\_number+65536\*job\_tag). These are always
interchangeable, so assuming there is a job Test with job number 1 and
job tag 12. 

::

    PRINT NXJOB ('Test',0) 
    PRINT NXJOB (1,12,0) 
    PRINT NXJOB (65548,0)
    
are all the same. 

Note that the top job ID must not be the job's name
or job number and tag. You could, for instance, use::

    PRINT NXJOB(0,0)

to find that SuperBASIC is using the Job QPAC-FILES. You must now
follow that branch to its tip by using::

    PRINT NXJOB ('QPAC-FILES',0)

to find the job ID of Quill. 

::

    PRINT NXJOB('Quill',0)

will then find the job ID of Abacus. Since Abacus is at the end of a
main branch, 

::

    PRINT NXJOB('Abacus',0)

will find Clock. 

Should you wish to merely find out which Jobs are used
by QPAC-FILES, you can do this by altering the topjob\_ID to the job\_ID
given for QPAC-FILES - eg::

    PRINT NXJOB('QPAC-FILES',65535)

**Example**

A short program to work out the whole job tree belonging to SuperBASIC.
This is very similar to the JOBS command, but displays the information
slightly differently:: 

    100 MODE 4 
    110 a=0: b=0 
    120 REPeat loop 
    130   c=NXJOB(a,b) 
    140   IF c=0: PRINT\'End of Job Table': STOP 
    150   a=c: IF LEN(JOB$(c))=0:PRINT'ANONYMOUS';: ELSE PRINT JOB$(c); 
    160   PRINT TO 15;'Priority = ';PJOB(c); 
    170   IF OJOB(c)=0: own$='SuperBASIC': ELSE own$=JOB$(OJOB(c)) 
    180   PRINT TO 30;'Owner = ';own$ 
    190 END REPeat loop

**CROSS-REFERENCE**

:ref:`pjob`, :ref:`job-dlr`, and
:ref:`ojob` also deal with the job tree. For jobs in
general, see :ref:`jobs`,
:ref:`rjob`, :ref:`spjob`,
:ref:`sjob`, :ref:`ajob`.

