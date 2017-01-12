..  _a12-device--drivers:

A12 Device Drivers
==================

A12.1 Devices in General
------------------------

This chapter informs you about the usage of the various devices
available on the QL and its compatibles. The QL's operating system QDOS
is what is known as device independent meaning that a program can be
written to use any device without having to actually know its details
(an exception to this rule is in the use of standard pipes). Programs
should be written so that (at least) all of these devices can be
accessed by the user as required.

Device Drivers are programs which usually create a connection between
hardware devices and software, in that they install a QDOS device to
interface from software to the hardware. For example a printer is
obviously hardware but you do not have to POKE around in memory to get
something printed, you can simply open a SER or PAR channel, dump your
text to that channel and voila it appears on the paper. All
communication with drivers must go through channels, whose name is very
well chosen: they take data from the program and transport it to the
device driver.

-  The program opens channel and writes or reads data to/from that
   channel...
   
-  The channel forwards the data (also instructions) to the device
   drivers...

-  The driver is a kind of translator which understands the language of
   the hardware...

-  A hardware interface translates computer codes into electrical
   signals...
   
-  The hardware performs physical actions, eg. printing or reading from
   a floppy disk.

But devices can be used for all kind of connections, there are even
general devices for communication between jobs (PIPE and HISTORY) and
devices which interface in a special way to other devices (DEV and PTH).
So the last two steps in the above figure are not obligatory, they can
be different, ie. non-hardware.

Devices fall into two categories, directory devices (such as FLP) and
non-directory devices. The latter may also be further sub-divided into
window devices (devices which access the screen, such as scr) and other
devices. All devices (other than window devices) accept the WIDTH
command.

::

                 all devices
                   /      \
                  /        \
    directory devices    non-directory devices
                             /           \
                            /             \
                  window devices       other devices

Further, if Toolkit II is present, or you are using a THOR XVI, certain
commands will support default devices and also sub-directories on
Level-2 directory devices.

Remember that device names can be in either upper or lower case, or even
mixed case, that does not matter at all. Device independent programs
should be fully configurable with regard to device names (eg. printer)
and offer up to 42 characters for each device name. However, the
...\_USE style commands and the DEV device help to overcome problems in
this respect.

A12.2 Directory Device Drivers
------------------------------

Data in the form of files can be stored on various different directory
device drivers, some of which allow data to be stored when the computer
is switched off (such as Microdrives and disks) and others which lose
their contents when the QL is reset or switched off (such as ramdisks).

Such media must be FORMATted prior to use in order to prepare them for
use by the computer.

In order to speed up reading of these devices, unused parts of the
computer's memory are set aside to act as slave blocks which store
copies of as much of the contents of the device as possible. Then, when
that same information is requested again, the computer need only check
that the data held in the slave blocks is the same as on the device, and
will then access the data from the slave blocks. This can however slow
down the initial access times (see DEL\_DEFB).

Each device contains a main directory which is made up of a copy of the
64-byte file header for each file which is (or has been) stored on the
device. This main directory is then examined by commands such as DIR to
produce a list of the files contained on that device. The file headers
contain a host of different information about each file, including the
name of the file, its type and the length of the file (see FGETH$).

When a file is accessed, various details (such as date-stamping creation
and update dates) are updated.

The way in which information is stored on a directory device really
depends upon the Level of device driver installed (see Sections A12.6 -
A12.8 below).

Details of the types of Directory Devices follow:

Microdrive (MDV)
^^^^^^^^^^^^^^^^


+----------+-------------------------------------------------------+
| Syntax   | MDVn\_file (QL ROM) or [MDVn\_]file (Toolkit II only) |
+----------+-------------------------------------------------------+
| Location | QL ROM, THOR XVI                                      |
+----------+-------------------------------------------------------+

This is the only standard directory device driver.

Microdrive cartridges are a continuous loop of video tape which store
data in packets of 512 bytes (known as sectors). There is a theoretical
maximum of 255 sectors on a Microdrive cartridge, although in practice
the formatted number of sectors tends to be around 210 to 220.

The tape has to be searched serially in order to find the desired
information which causes delay as the whole tape may have to be wound
through in order to find the information. This is where slave blocks
save a lot of time.

The standard QL supports two Microdrives (the slots to the right of the
keyboard) into which Microdrive cartridges can be inserted on which the
data is to be stored. However, up to a maximum of eight Microdrive ports
can actually be recognised, if additional Microdrives are added by means
of the Microdrive expansion port which is situated in the right hand
side of the QL by the reset button.

The THOR XVI, and QL emulators do not possess any Microdrives, although
the THOR does still recognise the device name, as it was originally
envisaged that a separate Microdrive might be made to link up with the
THOR in order to retain compatibility. The QL emulators will simply not
find any Microdrive device like MDV1\_, error -7 is produced. SMSQ/E
also does not recognise the Microdrives.

Unfortunately, unless you have Toolkit II or Minerva, Microdrive files
are not date-stamped with the creation and update dates.

Unless you have Toolkit II, the first syntax of this driver must be
used, which specifies the number of the Microdrive port to access (n),
which must be in the range 1...8, followed by the name of the file or
device to access (file). If neither or these are specified, you are
likely to receive the error 'Not Found' (-7), although whether or not
the file has to be specified depends upon the command being executed.

If however, Toolkit II is present, the default devices are supported.

**Examples**

::

    LOAD mdv1_boot

::
    
    DIR mdv2_

Microdrives will allow you to create a file with a null name, which will
not be revealed on a directory listing, but which will operate in much
the same way as any other file. For example, the following two lines are
both acceptable::

    SAVE mdv1_Myprog_bas
    SAVE mdv1_

Note that Microdrives do not possess Level-2 drivers and sub-directories
are therefore not supported. For example creating a directory with::

    MAKE_DIR mdv1_test_

will produce error -15 and leave the file test on mdv1\_.


Floppy Disk (FLP)
^^^^^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | FLPn\_file or [FLPn\_]file (Toolkit II only)          |
+----------+-------------------------------------------------------+
| Location | Disk expansion boards, THOR XVI, QL Emulators         |
+----------+-------------------------------------------------------+


This driver is for what are commonly known as floppy disks. These come
in various sizes, ranging from 3" to 8", although the QL standard is now
3.5" double sided disks with either double (720k) or extra density (3.2
MB).

The amount of space on a disk depends on the number of tracks on the
disk, the number of sides which can be used and the disk density.
However, all of the drivers meet with a standard Sinclair format,
ensuring compatibility between different manufacturers.

The drivers allow the same syntax as the MDV driver, although most disk
expansion boards will support the second variant, as Toolkit II (or at
least part of it) has become standard on disk interfaces.

**Examples**

::

    MERGE flp1_Simple_bas

::
    
    DATA_USE flp1_Quill

Some boards (such as the Gold Card, QXL, Atari Emulators and SMSQ/E)
support Level-2 commands and therefore sub-directories. Other expansion
boards can be fitted with these new drivers by updating a ROM chip.
Level-2 drivers store the directory details in a separate file for
simplicity. Unfortunately, the main directory is stored in a file with a
null name which will automatically overwrite any earlier file with a
null name. To see the main directory file, use::

    COPY flp1_ TO scr

Sub-directories are stored in files with the name of the sub-directory.
Such files have a file type of 255 and cannot be deleted or renamed
until all of the files contained within that sub-directory have been
removed.

Level-1 drivers supported files with null names in the same way as
Microdrives (see above). On some old drivers FLP may be replaced by FDK.

RAMdisk (RAM)
^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | RAMn\_file or [RAMn\_]file (Toolkit II only)          |
+----------+-------------------------------------------------------+
| Location | QJump RAMPRT, Expansion Boards, THOR XVI, ST/QL       |
|          | Emulators, SMSQ/E, QXL, QPC, Amiga QDOS Emulator      |
+----------+-------------------------------------------------------+

This driver is used to set up areas of memory which can be used in much
the same way as a floppy disk. Anything stored in a RAMdisk is lost when
the QL is reset or switched off.

There are actually two types of RAMdisks: a dynamic RAMdisk and a fixed
RAMdisk.

A fixed Ram disk is allocated a size when the FORMAT command is used,
and can contain anything between 3 sectors and the whole of free memory.
Some fixed Ram disks (most notably the Qjump ram disk which is a
standard) do not work on the Amiga- QDOS emulator - a slower public
domain Ram disk which does work is supplied with the Emulator.

By contrast, a dynamic RAMdisk does not have a fixed size and is created
when anything is written to it (do not use FORMAT) - it then expands and
contracts to fit the size of the files contained in the RAMdisk.

Dynamic RAMdisks (optionally fixed) are supplied as standard on most QL
systems. The RAMdisk drivers allow exactly the same syntax to the FLP
driver, but the Miracle drivers (eg. Gold Card and Trump Card) support
an extra syntax to format a RAMdisk to 255 sectors and copy a whole
Microdrive cartridge into them, eg. FORMAT ram1\_mdv1.

**Example**

::

    WCOPY flp1_, ram2_

Level-2 drivers commands and sub-directories are also supported for the
QJump RAMdisk driver, eg. on Gold Cards and ST/QL Emulators.

Hard Disk (WIN)
^^^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | WINn\_file or [WINn\_]file                            |
+----------+-------------------------------------------------------+
| Location | Hard disk Interfaces, THOR XVI, QL Emulators          |
+----------+-------------------------------------------------------+

This device driver allows you to access a hard disk drive (including
removeable hard disks). This operates a lot more quickly than a floppy
disk (but not as quickly as a ram disk) and can store several megabytes
of data.

Hard disks are built into nearly every system that can run a QL Emulator
and are available as add-ons for a standard QL and AURORA system.

Please refer to the original manuals because the harddisk drivers all
differ in FORMATing.

Accessing a WIN device from a program is just like accessing a FLP or
RAM device.

QL ROMDisq (ROM)
^^^^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | ROM1\_file or [ROM1\_]file (Toolkit II only)          |
+----------+-------------------------------------------------------+
| Location | QLROMDisq board                                       |
+----------+-------------------------------------------------------+

This is a board which plugs into the QL's ROM Cartridge port and
provides a fixed ram disk of either 2 or 8 Megabytes. It is similar to a
RAM disk in that it is very quick when loading files, but it has three
main differences:

-  It retains its contents after the QL is switched off.
-  You can only write data to it a limited number of times (100,000).
-  It is fairly slow when you write files to it (with SAVE, SEXEC or
   SBYTES).

Because of these limits, this device is only really intended for storing
files which will not change very often and are needed when the QL is
started up (for example a new keyboard and language driver). A boot file
stored on this device will be loaded when the QL is started up in
preference to similar files on hard disks, floppy disks and microdrive
cartridges.

The other main benefit of this device is that you can transfer whole
set-ups across to another QL (instead of using lots of floppy disks or
microdrives).

A12.3 Window Device Drivers
---------------------------

There are two types of window drivers, CON and SCR. The former (CON) is
linked with a keyboard queue and can therefore accept input, as well as
echoing any characters typed on screen. The latter (SCR) on the other
hand is for output only to the screen.

Any channels opened using these screen drivers are known as windows, and
may have a cursor attached to them. If a cursor is attached, then it
will normally appear as a red blob on screen (the size and shape of the
cursor may be redefined under Minerva v1.77+), and will flash when it is
active (ie. when it will accept input).

When you press <CTRL><C>, QDOS cycles through all of the current
cursors, allowing you to access different Jobs. If you are using Minerva
in its two screen mode, then each channel is also attached to a screen,
which means that if you open a channel on scr0, then all output to that
channel will appear on scr0 whether or not that is the currently
Displayed Screen (see MODE).

Also, when you press <CTRL><C> on Minerva, it will switch to the screen
attached to the newly activated channel (unfortunately in current
versions of Minerva, this does not quite work as expected, since if the
active cursor is on the non-Displayed Screen when you press <CTRL><C> to
move to a channel on the Displayed Screen, Minerva still switches
screens, meaning that you are still not looking at the screen with the
active cursor).

Whenever a new window is opened, it is opened with black paper and green
ink. The specified pixel parameters are also rounded up to make them
even (if necessary) to ensure that they can be correctly displayed in
any screen mode. The smallest possible window is two pixels wide and one
pixel high.

Console (CON)
^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | CON[<size>][<position>][<buffer>]                     |
+----------+-------------------------------------------------------+
| Location | QL ROM                                                |
+----------+-------------------------------------------------------+

This type of screen device is used for both output to the screen and
reading the keyboard via a queue attached to that window. Depending on
the command being executed, characters typed on the keyboard may be
echoed on screen. This type of channel must be opened if you wish to use
INPUT or INKEY$.

There are various problems with OPENing CONsole devices over the Network
(see FSERVE).

When the computer is first started, there are three CONsole channels
open, #0, #1 and #2; none of which should be CLOSEd or OPENed, this is
especially true for #0!

When opening a channel, you can specify the size and position of the
window and also the length of the type-ahead buffer attached to that
window. These can have the following values:

<size>This sets the size of the window in pixel co-ordinates. It should
be specified in the form:

[\_WIDTH][xHEIGHT]

where WIDTH can have any value in the range 0...SCR\_XLIM; and HEIGHT
can have any value in the range 0...SCR\_YLIM. The maximum values are
however also dependent on <position>.

The default value for <size> is \_448x200.

<position>This specifies the co-ordinates of the top left hand corner of
the window and is in the form:

a[X][xY]

where X and Y can both be in the same range as WIDTH and HEIGHT (used in
the <size>). However, both WIDTH+X and HEIGHT+Y must also be within the
ranges, otherwise an 'Out of Range' error will be reported.

The default <position> is a32x16.

<buffer>This part of the device name specifies the size of the input
buffer associated with the window, which is in the form \_N bytes. This
value affects how many characters can be stored in the channel's buffer
before the keyboard has to be read again (this is known as the
type-ahead buffer). Although this can have any value, a value of 128
bytes tends to be large enough for most tasks, and in fact this is the
default.

Default Device::

    CON_448x200a32x16_128

**Examples**

::

    OPEN #3,con_200:     REMark Open channel #3 as CON_200x200a32x16_128
    OPEN #3,con__10:     REMark Open channel #3 as CON_448x200a32x16_10
    OPEN #3,cona12:      REMark Open channel #3 as CON_448x200a12x16_128
    OPEN #3,conax20_50: REMark Open channel #3 as CON_448x200a32x20_50

The STE/QL emulator (QVME) and also other other hardware support much
higher resolutions than 512x256, eg. QVME can go up to 1024x1024 pixels.
However, programs should be written so that they still work with all
other resolutions. This can be achieved by reading the possible screen
size from system variables (the Pointer Environment must be used) and by
not accessing screen memory directly.

Screen (SCR)
^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | SCR[<size>][<position>]                               |
+----------+-------------------------------------------------------+
| Location | QL ROM                                                |
+----------+-------------------------------------------------------+

This is very similar to the CONsole driver, except that SCR channels are
for output to the screen only. No buffer size is required. Trying to
read input from a SCR channel will give a 'Bad Parameter' (-15) error.

Please see the CON Window Driver.

Default Device::

    SCR_448x200a32x16

A12.4 Other Device Drivers
--------------------------

In the following, LF is the line feed (or newline) character CHR$(10),
CR is the carriage return character (13, $0D) and FF is the form feed
character CHR$(12). In some applications <CTRL><Z> is used as an end of
text character, CHR$(26).

Both parallel and serial ports are means for the QL to access other
hardware in the outside world (such as printers, modems and scanners).
Serial ports are so called because data is sent serially, one byte at a
time. On the other hand, parallel ports allow several bytes to be sent
at the same time and are therefore quicker.

Many printers are set up to accept parallel input and QL users may find
that they need to purchase a serial to parallel converter (also known as
a Centronics interface) in order to use a printer.

Each driver accepts various parameters which are used to match the
output with the type expected by the device connected to the port. The
main parameter deals with the parity of the byte to be sent. If no
parity is specified, then all eight bits of the given byte will be sent,
otherwise bit 7 of the byte will be altered according to the parity
(this is best set according to what the hardware attached to the port
requires).

You can also specify whether handshake is to be enabled, which tells the
computer whether to wait for confirmation from the external hardware
that the data has been received safely. If handshake is enabled, then if
no acknowledgement is received, or the external hardware reports an
error then the computer will try again.

Finally, you can specify whether the data is to be converted as it
passes through the port. The standard code for ending a record or a line
is CR, however, the QL is non-standard in that it uses the code LF,
which therefore may need to be converted prior to transmitting.

Also, you may wish to send the character <CTRL><Z> as the last character
in order to tell the external hardware that there is no more data.

Parallel Port (PAR)
^^^^^^^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | PAR<new\_line><trns><ff><buf>  (THOR XVI) or          |
+----------+-------------------------------------------------------+
|          | PAR<port><translate><convert><eof>                    |
|          | (SMSQ/E, ST Emulators, Super Gold Card)         or    |
+----------+-------------------------------------------------------+
|          | PAR (AMIGA QDOS)                                      |
+----------+-------------------------------------------------------+
| Location | THOR XVI, ST Emulators, SMSQ/E, Super Gold Card,      |
|          | Amiga QDOS Emulator                                   |
+----------+-------------------------------------------------------+

Various QL implementations now come equipped with a parallel device
driver for use with their parallel port. Parallel ports can be used for
transmitting data only and are therefore normally used to connect
parallel printers to the computer. Although there are various other
expansion boards which also provide the standard QL with a PAR device,
we do not currently have details of their syntax.

Note that even with SMSQ/E the PAR device does not exist on a Gold Card
- there is no parallel printer port!!

The syntax of this device is quite complex, allowing different types of
translations and buffers to be used. We shall therefore examine each
variant in turn.

THOR XVI
^^^^^^^^

The values of each part of the device name are as follows:

<new\_line>This dictates how end of line (LFs) and end of text markers
are to be treated. The following values are available:

-  n - This converts LF to CR,LF and sends <CTRL><Z> at the end of the
   file. This is the default.
-  c -This converts LF to CR and also sends <CTRL><Z> at the end of the
   file.
-  r -This sends the text as it is - no conversions are carried out.
-  z - This does not convert LF, but sends <CTRL><Z> at the end of the
   file.

The following table may be of use:

+---------+----------+------------+
| EOL     | EOF      | Use This   |
+=========+==========+============+
| CR,LF   | CTRL-Z   | n          |
+---------+----------+------------+
| CR      | CTRL-Z   | c          |
+---------+----------+------------+
| \-      | \-       | r          |
+---------+----------+------------+
| LF      | CTRL-Z   | z          |
+---------+----------+------------+

<trns> This tells the THOR XVI whether or not to use its translation
tables (set with TRA). This can have the following values:

-  t -Use the translation table. This is the default if <new\_line> is
   specified but not raw.
-  p -Do not use translation table. This is the default if <new\_line>
   is not specified or is raw.

<ff> This says whether or not to send FF at the end of the file. The
default depends on <new\_line>. By default, a FF will be sent if
<new\_line> is set to n or c and the last character is not FF. The
default can be overridden by setting <ff> to f which tells the THOR not
to send FF unless of course there is already a FF at the end of the
text!

<buf> This sets the size of the output buffer in bytes, and must be in
the form \_n, where n is the size of the buffer. If you add 'k' after
the value of n, the value of n will be multiplied by 1024, for example
\_2K sets an output buffer of 2048 bytes.

The default is \_127.

**Examples**

::

    par_90k

Conversion of LF to CR, LF; translation table used; FF sent at
end; buffer length 90 kilobytes.

::

    parrt 
    
No conversion; translation table used; no FF sent.

Note the coupling between the <New\_line> and <trns> arguments. This
means that par is equal to parnt, whereas parr is equal to parrp. The
translation table used is the one set with TRA.

Default Device::

    PARnt_128

ST Emulators, Super Gold Card AND SMSQ/E
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

These allow output through the parallel ports to be buffered
dynamically, whereby a buffer is allocated up to all of the available
free memory or (except on the Super Gold Card without SMSQ/E) can be set
to a specific amount of space (thus allowing printing to continue in the
background). Several channels may be open to one output port at any
time, in which case the data is buffered and sent through the parallel
port in the order in which the channels are opened.

Commands are implemented to allow you to set a specific output buffer or
input buffer size (PAR\_BUFF), as well as aborting output to a parallel
port (PAR\_ABORT) or clearing an output buffer (PARR\_CLEAR).

The values of each part of the device name are as follows:

<port>This is provided for future compatability. It represents the
number of the parallel port to use. It can be either 1 or 2, although
any attempt to use par2 is currently ignored and par1 used. The default
is therefore 1.

<translate>This, like the THOR XVI's <trans> parameter specifies the
type of translation to be carried out on the data. This can have the
following values:

-  d - No translation is performed.
-  t - Translate according to the translate table. This is the default.
-  <convert>This specifies how LF is to be treated. It can have the
   values:

   -  c - This converts LF to CR.
   -  r - No conversion, this is the default.
   -  a -Insert CR,LF at end of line. Insert CR,FF at end of page (added
      to ST/QL drivers in Level D-05).

-  <eof>This specifies how the end of the file is to be treated. It can
   be the default (do nothing) or have one of the following values:

   -  f - Print FF at end of file
   -  z - Print CTRL-Z at end of file

**Example**

PAR1cz is the same as the THOR's PARn

Default Device::

    PAR1tr

AMIGA-QDOS
^^^^^^^^^^

This is the simplest form of parallel device driver, in that it does not
accept any parameters (at least in v1.03 of the parallel driver). Any
characters are sent straight through the Amiga's parallel port without
being altered in any way.

Serial Ports (SER)
^^^^^^^^^^^^^^^^^^

+----------+-----------------------------------------------------------------------------+
| Syntax   | SER<prt><par><handshake><protocol>(QL only) or                              |
+----------+-----------------------------------------------------------------------------+
|          | SER<prt><par><hand><translate><convert><eof> (ST Emulators, SMSQ/E)  or     |
+----------+-----------------------------------------------------------------------------+
|          | SER<prt><par><bits><hds><bpso><bpsi><nl><trns><ff><buf> (THOR XVI only) or  |
+----------+-----------------------------------------------------------------------------+
| Location | QL ROM, ST/QL, THOR XVI                                                     |
+----------+-----------------------------------------------------------------------------+

The QL, and THOR XVI are each equipped with two serial ports, marked
SER1 and SER2 on the rear panel. Other implementations of the QL can in
fact have access to up to four serial ports (even the standard QL can
use additional serial ports built into SuperHermes for example).

If only one serial port is available (as on some STs), any attempt to
use SER2 is treated as SER1.

The Amiga-QL emulator adopts a serial driver based on the JS version of
the QL driver. It can be used to access either of the Amiga's two serial
ports. It is however, unknown if current versions of the emulator's
driver (v1.03) support CTRL Z.

Both ports on the British QL use non-standard British Telecom connectors
and are actually wired up differently to each other (although they still
use the same device driver). The other types of serial port tend to use
standard 9-pin trapezium connectors.

On the standard QL, both ports conform with the RS-232-C standard,
although the port marked SER1 is configured as a data communication
equipment (DCE) port, which is normally used to drive printers; whereas
the port marked SER2 is set up as a data terminal equipment (DTE) port,
which is more suited towards accepting input from other devices (such as
a modem). Refer to the QL User Guide manual, Concepts section, for
further details of the hardware.

The rate at which data can be passed through the ports is known as the
Baud rate which is set with the command BAUD from SuperBasic (or with a
corresponding machine code trap call). This is supposed to be the number
of bits per second, but due to the limitations of the QL's hardware, the
rate of data transfer actually falls somewhat short of these rates
(unless you have a THOR XVI, or use Minerva or SMSQ/E which has speeded
up the rate of data transfer considerably).

Unfortunately, the 8049 IPC which controls input from both serial ports
on the QL cannot handle different baud rates for the two ports. On the
other hand, the THOR XVI does support different baud rates, although not
via the BAUD command which sets the baud rate on both ports to the same.
Hermes is a replacement for the QL's 8049 chip and allows different
input baud rates on each of the two serial ports. Minerva allows
different output baud rates on each port.

SMSQ/E and the ST Emulators allow you to set fully independent input and
output BAUD rates on each port (although SuperHermes is still needed if
this is to work on a standard QL).

Either port may be used for input or output (subject to hardware
restrictions - see above), however, only one channel can be open to a
serial port at a time, and if a channel is already open to the given
port, the error 'In Use' will be reported.

The actual implementation of the SER device driver is dependent upon the
machine. We shall therefore deal with each machine in turn.

Standard QL
^^^^^^^^^^^

This enables you to open a channel to either of the two serial ports.
The action taken by the device driver depends both upon the ROM version
being used and whether data is being input or output.

Note that input through the serial ports tends to be unreliable with
baud rates in excess of 1200, and in any case, when receiving at 9600
baud, two stop bits must be issued by the transmitting device. Receiving
at 19200 baud is not possible.

Unfortunately, problems in the 8049 mean that incoming data can be lost
due to a delay in notification of the fact that the receive queue is
full. Also, input channels can actually suffer from 'serial overrun'
where some characters are held up in the 8049, and then released only
when a new character is read from the serial port. This can sometimes
happen with modems, making serial input unuseable.

There exists a replacement for the 8049 (called HERMES and its bigger
brother SuperHERMES) which fixes these problems, as well as allowing
separate baud rates for input and output channels, and which even
supports different input rates on SER1 and SER2. This replacement also
makes input at the higher baud rates much more reliable (including input
at 19200 baud), without needing two stop bits at any rate.

The handling of both input and output is also dependent upon the ROM
version being used:

(a) Output SERial devices
"""""""""""""""""""""""""

**Pre-JS ROMs**

If the C protocol has been chosen, then if the byte is a LF it is
converted into a CR. Bit 7 of the byte is then adjusted to suit the
parity and the byte then placed into the queue for the 8302 chip to
read, deal with the handshaking and send through the channel. When the
whole of the data has been sent, once the 8302 has emptied the queue,
CTRL-Z is sent (if required).

Unfortunately, this meant that the protocol could just about be altered
before the CTRL-Z had actually been sent, resulting in a failure by the
QL to send any CTRL-Z's. This could happen for instance, if a series of
small CTRL-Z files was sent to the serial channel and then the channel
was re-opened as SERr. Another problem with the handling of CTRL-Z's was
that the parity (if required) was not always correct on this final byte.

**JS and MG ROMs**

The serial driver followed the same pattern, except that if enabled by a
TRA command (or the appropriate machine code call) the byte was
translated according to the specified translation table after it had
been adjusted to suit the parity (if required). This meant that bytes
above CHR$(127) could not always be translated. The problems with CTRL-Z
persisted.

**Minerva ROMs**

The serial driver is much improved, in that if the protocol is C, then
LF is swapped with CR (and vice-versa). The byte is then translated
according to the translation table (if required) and only then is it
altered according to the parity setting.

The byte is then put into the queue to be sent to the 8302 and
handshaking is then dealt with, leaving the 8302 to actually output the
byte.

The problems with CTRL-Z have mainly been dealt with, although to
overcome the problem of changing protocols, a channel structure linked
to SERz or SERc cannot be discarded until all of the data in the
transmit queue has been sent (meaning that the channel structure may not
ever be discarded if handshaking forces the computer to keep trying to
send the data). The main remaining problem is that in Minerva's two
screen mode, characters may be lost on output.

(b) Input SERial devices
""""""""""""""""""""""""

**Pre-JS ROMs**

The 8302 deals with handshaking and then puts the byte which it has read
into the receive queue. The device driver then reads the byte from the
receive queue and checks the parity of the byte; reporting Xmit error if
the check fails.

If the C protocol is chosen, then any CRs are converted into LFs and the
byte returned to the user. Parity is completely ignored on CTRL-Z.

**JS and MG ROMs**

These both still suffer from CTRL-Z.

If enabled, a simple (one to one) translate is performed on the incoming
byte as soon as it is fetched from the receive queue (see TRA). The
parity is then altered as required, CRs converted into LFs (if
necessary) and the byte passed onto the user.

**Minerva ROMs**

This checks the parity on CTRL-Z if required, along with the parity on
any other data as soon as each byte is fetched from the receive queue.
The byte is then translated (if necessary) according to the simple (one
to one) translation table, CRs and LFs exchanged (unless protocol R
chosen) and the byte then passed onto the user.

(c) The Standard QL Device Driver
"""""""""""""""""""""""""""""""""

The parts of the device driver are made up of the following:

<prt> This specifies which serial port is to be used, and can be 1 or any
higher number.

The default is ser1.

<par> This sets the type of parity to be used. The default is none, which
allows all 8 bits of the characters to be sent. <par> may however be
specified for one of the following values:

-  e - Even
-  o - Odd
-  m - Mark
-  s - Space

If a parity setting is used, then only seven bits of each code sent to
the serial port are used, the last eighth bit is used to specify the
parity.

If the parity is wrong when data is received through a port then the
error 'Xmit Error' is reported.

<handshake>This specifies whether handshaking should be used. It may
have the values:

-  i - Ignore Handshaking
-  h - Handshaking on. This is the default.

Handshaking is used to ensure that data is only sent through the serial
port when the machine connected to the other end of the lead has sent a
signal to say that it is ready to receive data.

<protocol>This specifies the type of conversion to be used. It may have
one of the following values:

-  r - No conversion carried out. This is the default.
-  z - Use CTRL-Z for end of file flag.
-  c - Convert LF to CR (or vice versa on input) and use CTRL-Z as end
   of file flag. Note: on Minerva, swap LF with CR on both input and
   output.

Default Device::

    SER1hr

ST Emulators and SMSQ/E
^^^^^^^^^^^^^^^^^^^^^^^

These support a slightly enhanced variant of the device found in JS and
MG ROM QLs (but with different bugs). Output through the serial ports
can be buffered dynamically, whereby a buffer is allocated up to all of
the available free memory or can be set to specific amount of space
(thus allowing printing to continue in the background). Several channels
may be open to one output port at any time, in which case the data is
buffered and sent through the serial port in the order in which the
channels are opened.

Commands are implemented to allow you to set a specific output buffer or
input buffer size (SER\_BUFF and SER\_ROOM), as well as aborting output
to a serial port (SER\_ABORT) or clearing an output buffer (SER\_CLEAR).
Even the default handshaking can be set with SER\_FLOW.

Serial ports may even be joined together to form a Network (SERNET).

When using SMSQ/E on standard QL serial ports hardware, there are
several ways to improve the reliability:

-  Use STX instead of SER to open output only ports.

-  Use the command SER\_PAUSE to alter the length of the stop bits on
   the serial ports.
   
-  Fit Hermes (or SuperHERMES) - this is especially important for using
   higher BAUD rates and can improve the XON / XOFF protocol which can
   normally fail when trying to read data on the QL at over 2400 BAUD or
   trying to send data at over 4800 BAUD. Hermes is also needed to
   receive data at a different BAUD rate on each port and also at a
   different rate to the transmission rate.
   
-  Change your serial to parallel converter - SMSQ/E is now so fast on
   the QL that some older converters no longer work correctly.

The SER device supports the various settings detailed on the following
page. The default is ser1htr

<prt> This is the same as on the QL.

<par> This is also the same as on the QL.

<hand> This specifies whether or not to use handshaking, and if so which
type is to be used. It can take the following values:

-  h - Hardware Handshaking on - the default.
-  i - Ignore handshaking
-  x - XON/XOFF; no handshaking (see SER\_ROOM).

Hardware Handshaking can only be used with a five-wire serial connector,
as it uses one of the lines as a signal line to signify when the machine
is ready to receive data.

XON/XOFF was added to ST/QL Emulators in Level D-00 drivers and also
exists in SMSQ/E - it is software based handshaking and can be used with
three-wire serial connectors. An XOFF character is sent to the other
machine when there are only 32 characters left in the receive buffer (or
other figure set with SER\_ROOM), telling that other machine to stop
sending data. Once there is room in the receive buffer for twice this
number of characters an XON character is sent to the other machine which
tells that machine to re- start data transmission.

SER\_FLOW also affects this parameter.

<translate> This specifies the type of translation to be carried out on
the data. This can have the following values:

-  d - No translation is performed.
-  t - Translate according to the translation table. This is the
   default.

The TRA command sets up translation tables.

<convert> This specifies how LF is to be treated. It can have the values:

-  c - This converts LF to CR.
-  r - No conversion, this is the default.
-  a -Automatic insertion of CR,LF at end of line and CR,FF at end of
   page. This was added to ST/QL Drivers in Level D-05.

<eof> This specifies how the end of the file is to be treated. It can be
the default (do nothing) or have one of the following values:

-  f - Print FF at end of file
-  z - Print CTRL-Z at end of file

THOR XVI
^^^^^^^^

The serial ports provided on the THOR XVI use a much enhanced variant of
the original JS device driver. The new serial device syntax is upwardly
compatible with the original, ie. the old syntax described above is
still accepted but additional parameters are allowed. The THOR also
supports an enhanced translate table (see TRA).

The following parameters are now accepted by the device driver:

<prt> This is the same as on the standard QL driver.

<par> Again, as per the standard QL.

<bits> This digit sets the number of bits per byte to be sent. It can be
5, 6, 7 or 8. The default is 7 if parity is set, otherwise 8 for no
parity.

<hds> This letter sets handshaking:

-  h - on (default).
-  i - ignore.
-  x - XON/XOFF with handshaking.
-  y - XON/XOFF without handshaking.

<bpso> This sets the current output baud rate and is specified as the
number is preceded by a B. Valid parameters are: B75, B110, B134.5,
B150, B300, B600, B1200, B1800, B2400, B4800, B9600, B19200.

The system BAUD setting is the default. See BAUD.

<bpsi> This sets the input baud rate as above. A THOR XVI can send and
receive data at different speeds. The default input baud rate is the
current output baud rate.

<nl> This letter specifies how the end of line (EOL) and end of file
(EOF) codes should be converted. This is the same as <new\_line> in the
THOR's PAR driver, except that the default here is r (raw).

<trns> This tells the THOR XVI whether or not to use its translation
tables (set with TRA). This can have the following values:

-  t - Use the translation table. This is the default if <nl> is not
   specified.
-  p - Do not use translation table. This is the default if <nl> is
   specified.

<ff> This says whether or not to send FF at the end of the file. The
default depends on <nl>. By default, a FF will be sent if <nl> is set to
n or c and the last character is not FF. The default can be overridden
by setting <ff> to f which tells the THOR not to send FF unless of
course there is already a FF at the end of the text!

<buf> This sets the size of the output buffer in bytes, and must be in
the form \_n, where n is the size of the buffer. If you add 'k' after
the value of n, the value of n will be multiplied by 1024, for example
\_2K sets an output buffer of 2048 bytes.

The default is \_127.

**Example 1**

::

    ser2exb75b1200cf

ser2 with even parity, send 7 bits per byte, XON/XOFF with handshake on,
set output baud rate at 75 bps and input baud rate at 1200 bps, newline
conversion to CR and use translate table, no form feed at end of file,
use an output buffer of 127 bytes.

**Example 2**

::

    ser7b1200

ser1 with no parity, send 7 bits per byte, normal handshake, both output
and input baud rate set at 1200, no newline conversion (raw data) but
use translate table, send form feed at end of file, use output buffer of
127 bytes.

Default Device::

    ser18hrt_127

Note the coupling between the <nl> and <trns> arguments. This means that
'ser1' is equal to 'ser1rt', whereas 'ser1r' is equal to 'ser1rp'. The
translation table used is the one set with TRA.

Serial Ports (SRX)
^^^^^^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | SRX<prt><par><hand><translate><convert><eof>          |
+----------+-------------------------------------------------------+
| Location | ST Emulators, SMSQ/E                                  |
+----------+-------------------------------------------------------+

This is a dedicated input only serial device, which has the same syntax
as the ST Emulator's SER device.

Default Device::

    SRX1htr

Serial Ports (STX)
^^^^^^^^^^^^^^^^^^

+----------+-------------------------------------------------------+
| Syntax   | STX<prt><par><hand><translate><convert><eof>          |
+----------+-------------------------------------------------------+
| Location | ST Emulators, SMSQ/E                                  |
+----------+-------------------------------------------------------+

This is a dedicated output only serial device, which has the same syntax
as the ST Emulator's SER device.

It is recommended that if your program only needs to be able to send
data out of the serial ports, this device is used, as this will enable
other programs to open input devices (SRX) to the same serial port.

**NOTE**

On a standard QL, the same hardware is used for both serial ports, and
therefore if you are using one port for input and one for output you
should use the STX device on the output only port (instead of SER). If
you use SER to open both ports then the speed of the input port will be
unduly affected even though the other port is being used for output
only. STX gets around this problem.

Default Device::

    STX1htr

Printer Ports (PRT)
^^^^^^^^^^^^^^^^^^^

+----------+----------------------------------------------------------------+
| Syntax   | PRT                                                            |
+----------+----------------------------------------------------------------+
| Location | Qjump RAMPRT, ST Emulators, SMSQ/E, QXL, Gold Card, Trump Card |
+----------+----------------------------------------------------------------+

This is an unusual device driver which comes in two forms. However, in
both forms, the idea is that a user will set up this device to point to
the port which connects to his printer, so that a program merely needs
to OPEN prt. In practice however, it is more advisable to allow the user
to configure the program with the details of the port to be used for
printing.

Qjump RAMPRT, Trump Card, QXL and Gold Cards
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

These allow the PRT device to be used to add buffers to serial and
parallel ports (see PRT\_USE).

ST Emulators and SMSQ/E
"""""""""""""""""""""""

On these implementations, the PRT device can be used to emulate either
SER or PAR, but does not necessarily have a buffer attached. See
PRT\_USE.

Memory Driver (MEM)
"""""""""""""""""""

+----------+-------------------------------------------------------+
| Syntax   | MEM\_[adr1[\_adr2]] (IODev) or                        |
+----------+-------------------------------------------------------+
|          | MEM[bufnr][\_buflen{p\|t}] (DIY Toolkit)              |
+----------+-------------------------------------------------------+
| Location | MEM device (DIY Toolkit Vol N), IODev (System)        |
+----------+-------------------------------------------------------+

The memory device allows you to access RAM memory directly via a device.
This is functionally the same as PEEKing the values with any of PEEK's
available variants (PEEK$, PEEK\_F etc), but the latter only allows you
to access the memory of the local machine.

The MEM device on the other hand can be installed on a different machine
connected via the Toolkit II fileserver, which allows you to use any
device driver on a host machine through the n<nr>\_ fileserver interface
(see below).

Data can be read and written through a MEM device to memory with all
commands and functions that work on files as well, so that memory
becomes a file.

The DIY MEM device supports up to eight buffers of buflen bytes in size
for data transfer between program and memory. A buffer is specified by
bufnr, each buffer can be either temporary (t suffix to buffer length)
or permanent (p). The file pointer needs to be explicitly set to the
address location which you want to read from or write to.

IODev's MEM device has a much different syntax. The two modifiers adr1
and adr2 are numbers which indicate the start address (offset zero):
1024\*adr1+adr2.

adr1 and adr2 are assumed zero if omitted.

**Example**

The classical demonstration for the MEM device is copying

the screen from one machine to another:

(1) IODev Variant

This can be easily done with::

    SBYTES n2_mem_128,131072,32768

provided that the screen address is located at 131072 (128 \* 1024 =
131072) on both machines and that both screens are 32k long. The above
command copies the screen of the current machine to Network station
number 2 (which must be running FSERVE).

(2) DIY Toolkit variant

This is defined differently and needs you to set the file pointer
accordingly:

::

    100 SBYTES_O ram1_q,131072,32768
    110 OPEN#3,n2_mem_
    120 GET#3\131072
    130 SPL ram1_q TO #3

You will have noticed that both variants of MEM have an incompatible
syntax. Fortunately however, it is still possible to write portable
programs for both devices. Just use the most basic syntax; both MEMs
will then behave identically and start at the absolute address zero.

This means that the above DIY Toolkit example will also work on the
IODev variant (however ensure that the final underscore appears in line
110 to maintain DIY Toolkit compatability.

This example can be much improved by avoiding the need for a temporary
file and extra code to check if SPL has finished (ignored here) by using
FWRITE.

**NOTE**

MEM could have problems on Minerva pre v1.78.

**WARNING**

The use of the MEM device is not recommended because it uses absolute
addresses on another machine. QDOS tends to move around all kinds of
area of memory, so that even very sophisticated communication between
the network partners cannot provide enough safety to avoid crashes.

Imagine the following (horror) scenario: Machine 1 tells machine 2 where
its screen memory is located. Machine 2 starts to send its own screen to
machine 1 but during the upload QDOS moves the screen on machine 1 to
another location... BANG! The use of MEM must be declared as dirty or at
least most dangerous. There are always alternatives which avoid MEM.

Network Drivers (NET)
^^^^^^^^^^^^^^^^^^^^^

+----------+---------------------------------------------------------+
| Syntax   | NET<direction><station>(QL ROM) or                      |
+----------+---------------------------------------------------------+
|          | NET<direction><station>\_<buffer>(Toolkit II, THOR XVI) |
+----------+---------------------------------------------------------+
| Location | QL ROM, Toolkit II, THOR XVI                            |
+----------+---------------------------------------------------------+

These device drivers are explained separately in the Networks appendix.

Communication Drivers (PIPE)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+----------+----------------------------------------------------------------+
| Syntax   | PIPE\_length(standard drivers) or                              |
+----------+----------------------------------------------------------------+
|          | PIPE[IDin]{X \| P \| T}IDout[\_[length]][K](Minerva v1.97+) or |
+----------+----------------------------------------------------------------+
|          | PIPE\_name[\_length] (named drivers, SMS)                      |
+----------+----------------------------------------------------------------+
| Location | QL ROM, named pipe drivers, SMS                                |
+----------+----------------------------------------------------------------+

These are basically areas of memory which are set aside to act as
communication queues. In theory, output data can be placed into the
queue by a Job through one channel and the data can then be read by
another Job (or the same Job) through another channel. The Job which is
outputting data will be told when the pipe is full and will have to wait
for something else to read some of the data before any more can be
placed into the pipe.

Data is read out of a pipe in the order in which it is placed into it.
This is known as First In First Out (FIFO).

Pipes can only be one way (either output or input). Any attempt to send
data through an input pipe (or to read data from an output pipe) will
cause a 'Bad Parameter' error. For compatability reasons, you should
open output pipes with OPEN\_NEW and open input pipes with OPEN\_IN.

A channel which is open to an input pipe cannot detect the end of data
held within the pipe with the EOF command (unless the output channel has
been closed) - instead, you will need to use the PEND or EOFW command to
check if there is any more data waiting in the pipe. If you do not do
this, then commands accessing the input pipe will merely wait around
until they timeout (or wait indefinitely if the timeout is negative!).

More recently, the concept of Named Pipes has been introduced to QDOS
which make the handling of pipes much easier, as you only need supply
the name of the pipe to the input channel.

Again, we need to look at the various implementations of pipes:

Standard QL ROM
"""""""""""""""

**(1) Output Pipes**

It is easy to open an output pipe, with the syntax::

    PIPE_length

where:

length Defines the length of the pipe, this is the number of bytes which
can be stored in the queue at any one time. This cannot be extended at a
later date (at least not very easily without losing all of the data).

length must be in the range 2...32767.

There is no default.

**(2) Input Pipes**

The problem comes when you try to link an input channel to this pipe. To
do this, you need to open a channel to PIPE\_0 with the channel ID of
the first pipe in the machine code register D3.

Unfortunately there is no easy way of doing this in SuperBASIC, unless
you have Minerva v1.82+ (see OPEN) or use a toolkit command such as
QLINK which connects an existing channel to the given pipe.

**WARNING**

More than one input pipe may be connected to the same output pipe
inadvertently, and you could even connect one input pipe to another.
Both of these will eventually crash the system.

Minerva ROM
"""""""""""

This allows pipes to be created which are the same as on the standard QL
ROM, except that length can have the letter K appended to multiply it by
1024. However, it is easier to link up input pipes to existing output
pipes by using the extended OPEN commands implemented on Minerva v1.82+.

**Example**

Open a pipe between two programs, with a buffer of 10K

::

    100 PCHAN=3
    110 OPEN_NEW #PCHAN,pipe_10K
    120 pipeID=PEEK_W(\48\PCHAN*40+2)

then in another program, having transferred the pipeID from the above
program (by example using a temporary file)::

    130 OPEN_IN #5,pipe_,pipeID

However, a more flexible type of pipe has been implemented in Minerva
v1.93+, with the syntax:

PIPE[IDin]{X \| P \| T}IDout[\_[length]][K]

Pipes are identified by ID numbers (IDin) and (IDout), both of which can
be any integer number in the range -32768 to 32767. The effect of
omitting either ID numbers depends on the circumstances (see below).

In keeping with the other pipe drivers, length can be any integer
between 0 ans 32767, appended by K if you want to multiply it by 1024.
If omitted, it defaults to 0.

This sets up a system of pipes which are very similar to named pipes and
channels can actually be opened to pipes which can both read from and
output data to that pipe. The first channel to open a pipe to a
particular IDin or IDout will need to specify the buffer length - any
future channel which tries to specify a buffer length for the same pipe
IDin or IDout will have no effect on the buffer.

The effect of the pipe depends on the values of IDin, IDout and whether
the X, P or T parameter is specified.

-  If IDin is omitted then the channel opened to the pipe will be
   write-only. IDin defaults to zero.
   
-  If IDout is omitted or a negative number, and IDin is specified
   together with the X, P or T parameter then it will default to the
   same as IDin. - see (3) below. However, If IDout is omitted and the
   above paragraph does not apply, IDout is taken to be zero (or if
   IDout is specified to be zero) then the channel opened to the pipe
   will be read-only (you will need to specify X, P or T parameter if
   Minerva is to recognise IDout whether it is there or not).
   
-  If both IDin and IDout are non-zero (or IDout was made to be the same
   as IDin under (2) above), then the channel opened to the pipe will
   read data from IDin and send data to IDout. If IDin and IDout are the
   same then this will form a circular queue.
   
-  If both IDin and IDout are omitted and the X, P or T parameter is not
   specified, then you have created a standard QL pipe! If you specify
   the P or T parameter in this instance, see note 1 and note 2 below.
   PIPEX has no meaning!
   
-  If a P parameter is specified, then this pipe will be marked as
   permanent and will retain its data even if no channels are open to
   it.
   
-  A T parameter marks a pipe as temporary and can be used to remove a
   permanent pipe, eg: OPEN #3,'pipe1p2'Open a permanent input pipe
   (ID=1) and a permanent output pipe (ID=2). OPEN #3,'pipet2':CLOSE
   #3Remove the pipe (ID=2) once all information has been read from it.
   
-  An X parameter is used to merely separate IDin and IDout - this will
   create a temporary pipe which will mark the end of the data 'End of
   File' when the last channel which can output data to the specified
   pipe ID has been closed. When there are no channels at all left open
   to that pipe ID then any data in that pipe is lost and the memory
   released.

**Examples**

::

    OPEN #3,pipe3x_100: REMark Open a read only pipe with a 100 byte buffer.
    OPEN #3,pipex3_100: REMark Open the write only end of the above pipe.

Any easy way to transfer data between two programs:

From SuperBASIC enter the program:

::

    100 OPEN #3,pipe1t3_300
    110 REPeat wait_loop
    120   INPUT #3,info$
    130   IF info$='PROG 2 IS READY - SEND'
    140     INPUT #3,datan,dummy$
    150     EXIT wait_loop
    160   END IF
    170 END REPeat wait_loop
    180 FOR i=1 TO datan
    190   INPUT 'Enter Data Entry ';(i);': ';a$
    200   PRINT #3,a$
    210 END FOR i
    220 REPeat end_WAIT
    230   INPUT #3,a$
    240   IF a$='THANKYOU':PRINT 'DATA SENT SUCCESSFULLY':EXIT end_WAIT
    250 END REPeat end_WAIT
    260 CLOSE #3

Use EX pipep to start a MultiBASIC and enter the program:

::

    100 OPEN #3,pipe3t1_300
    110 space=10
    120 DIM rd$(space,100)
    130 PRINT #3,'PROG 2 IS READY - SEND'
    140 PRINT #3,space
    150 PRINT #3,'DATA'
    160 FOR i=1 TO space
    170   INPUT #3,rd$(i)
    180 END FOR i
    190 PRINT #3,'THANKYOU'
    200 CLOSE #3

Now RUN the program in the MultiBASIC, <CTRL><C> to SuperBASIC and enter
RUN. Any data you enter into the SuperBASIC program will then be sent to
the MultiBASIC program. Both programs can be RUN in either order!!

**NOTE 1**

PIPEP without any other parameters was implemented to automatically
start up a MultiBasic, by using for example: EX pipep

see EW for details.

**NOTE 2**

PIPET opens a pipe similar to a NUL device - any attempt to read data
from it will always report 'End of File', whereas any data sent to it
will be thrown away.

**NOTE 3**

In v1.97 PIPEP and PIPET were the wrong way around when opened as an
input pipe. You will therefore need to use a line such as::

    IF VER$(1)='1.97': OPEN_IN #3, PIPEP2: ELSE: OPEN_IN #3, PIPET2

**NOTE 4**

It is recommended that in order to overcome problems with multitasking
jobs trying to access the same pipe IDs inadvertantly, a Job should use
its own Job number\*100 plus the pipe ID number. This can be calculated
with::

    jobID = VER$(-1): JobNr = JobID - INT(JobID/65536)*65536
    JobID = (PEEK_L(!!100) - PEEK_L(!!104)) DIV 4

Named Pipe Drivers, SMS
^^^^^^^^^^^^^^^^^^^^^^^

SMS, the ST/QL Emulators (Level D-00 onwards) and various other
utilities implement named pipe drivers.

Named pipes solve many of the problems associated with QDOS's native
pipes, in that there is no need to know the channel ID of the output
pipe in order to open the input pipe.

Most versions will also allow you to open the input side before opening
the output side, but oddly enough some non- standard versions will lose
any data stored in a pipe if there is neither an output nor an input
channel associated with it.

Input and output pipes can be closed in any order - information
contained in them will not be lost, so you can close both the input and
output pipes, but if there is still information contained in the pipe,
you can then open a new input pipe to read this remaining data.

SMS v2.79 has further extended the concept of named pipes, allowing you
to DELETE and DIR pipes.

::

    DIR pipe

will list all named pipes which exist

::

    DELETE pipe_name

will delete the specified pipe.

You can also::

    VIEW pipe_name

In current drivers, a maximum of 15 or 16 named pipes can be open at any
one time. The syntax of this driver is::

    PIPE_name_length

for an output pipe, or::

    PIPE_name 
    
for an input pipe.

where:

name The name of the pipe (up to 32766 characters long), which must be in
the standard name format (ie. the first character must be a letter or
'\_' symbol, with any other characters following).

There is no default.

length The length of the queue associated with the pipe (ie. how many
characters can be stored in the pipe at a time). This must be in the
range 2...32767. If a length of zero is given, this is taken to be an
input pipe.

Default is 0.

**NOTE 1**

As there is no guarantee when you open an input channel to a pipe that
it is empty (or contains only the information which you expect - for
example another copy of your program may already be in use!!), it is
normal for the first information to be sent by a program through a pipe
to be some identification information (see the Minerva examples).

**Examples**

::

    OPEN_NEW #3,PIPE_100

Open a standard output pipe which can hold up to 100 characters at a
time.

::

    OPEN_NEW #4,PIPE_xover_50

Open an output pipe named xover which can hold up to 50 characters at a
time.

::

    OPEN_IN #5,PIPE_xover

Open an input channel to the pipe xover.

::

    OPEN_NEW #2,PIPE_quill_exp_100

Open an output pipe named quill\_exp with a buffer for 100 characters.

::

    PIPE_0

Open a general input channel to a pipe - see standard QL version above!

**NOTE 2**

Before Level D-06 of the ST/QL Drivers, PIPE\_ or PIPE\_0 could cause
problems with TURBO compiled programs.

**WARNING**

When using SMSQ/E's named pipes, if you try to DELETE a pipe but a
channel is OPEN to that pipe, then the error 'in use' is reported.
However, when all channels to that pipe are CLOSEd, the pipe will
immediately be DELETEd.

Communication Drivers (HISTORY)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+----------+----------------------------------------------------------------+
| Syntax   | HISTORY\_name[\_length] or                                     |
+----------+----------------------------------------------------------------+
|          | HISTORY[\_length]                                              |
+----------+----------------------------------------------------------------+
| Location | SMSQ/E                                                         |
+----------+----------------------------------------------------------------+

The first syntax to this device creates a Public History Device - this
is similar to the named pipes driver on the SMSQ/E except that it works
as a Last In First Out (LIFO) device, so that information read from a
HISTORY appears in the opposite order to which it was placed in the
HISTORY and can be read from any program. Also if a HISTORY device
becomes full, the oldest message is thrown away. Messages are separated
by NewLine characters.

Note that the name should not be a single character to allow for future
improvements to this device.

The second syntax creates a Private History Device, which still stores
messages so that they are fetched out of the History in the reverse
order to how they were stored. However, no other program will be able to
open a channel to this History and therefore it can only be read by the
program which has opened it.

In both versions, if length is not specified, then it is presumed to be
1024 bytes.

As with Named Pipes, as from v2.79 of SMSQ/E, you can use DIR, VIEW and
DELETE to get a directory of Public Histories, look at one of them and
Delete them.

**Example**

Grab the name of the last file on a disk:

::

    OPEN_NEW #4,HISTORY_FILE_10000
    DIR #4,flp1_

    VIEW HISTORY_file: REMark Just a quick look at the contents - it does  not  alter  the  contents  of  the HISTORY

    INPUT #4,name$
    CLOSE #4
    DIR HISTORY
    DELETE HISTORY_file

Nul Driver (NUL)
^^^^^^^^^^^^^^^^

+----------+----------------------------------------------------------------+
| Syntax   | NUL or NULZ or NULF or NULL or NULP                            |
+----------+----------------------------------------------------------------+
| Location | ST/QL Emulators and SMS                                        |
+----------+----------------------------------------------------------------+

A nul device is generally just an empty input only device that can
consume anything put into it at great speed. It enables you to write
software which can easily turn off its normal output by merely
re-opening its output channel to a nul device should the user choose to
do so.

All nul drivers are added by additional hardware and software. The
standard device name is NUL, but there are also NULZ, NULF, NULL and
NULP.

Input
"""""

The only real difference is if you try to read one of the nul drivers.

-  NUL - This is an output only device, and returns bad parameter if you
   try to read information from it. Any attempt to read window
   information will return a zero parameter. Any attempt to read pointer
   information will return an invalid parameter.

-  NULF - This emulates a null file - the EOF function will always be
   true on this channel. If you read the file header (with HGET for
   example) then a 14 byte header full of zeros is returned. Any attempt
   to read window information or pointer information has the same result
   as on NUL.

-  NULL - This emulates a file filled with Line Feed characters
   CHR$(10). The file position can be set anywhere and the file header
   is 14 zero bytes. Any attempt to read window information or pointer
   information has the same result as on NUL.

-  NULZ - This emulates a file full of zeros. You can set the file
   position to any value, but reading the header or data from the file
   will always return zeros. Any attempt to read window information or
   pointer information has the same result as on NUL.

-  NULP - This will force the program to wait forever (or until any
   specified timeout has elapsed).

Output
""""""

There is no difference when writing - all of the drivers just forget any
data sent to them (eating it up at very high speeds).

A12.5 DIRECT SECTOR ACCESS
--------------------------

All standard directory device drivers (WIN, FLP, MDV and RAM) support
direct sector access. This allow you to access the contents of a
directory device without having to rely on the directory itself - it can
therefore be used to rescue corrupt disks and even change the formatting
of a disk (for example one utility uses this feature to squeeze extra
room onto a normal Double Density floppy disk).

To use direct sector access, it is necessary to OPEN a channel to a
special filename, in the form::

    DRIVEn_*Dsd

Where:

DRIVEn\_ This should be the name of the device followed by the drive
number, for example FLP1\_

\*D This is the direct access identifier and must remain the same.

s This is a number which represents the length of a sector. s should be
one of the following numbers:

-  0 = 128 bytes
-  1 = 256 bytes
-  2 = 512 bytes (DD and HD disks)
-  3 = 1024 bytes
-  4 = 2048 bytes (ED disks)

The value of 4 is only supported on Super Gold Cards. Values other than
2 are only supported on SMSQ/E and ST/QL Drivers from Level D-05
onwards.

d This is a letter in lower case which represents the density of the
device, and should be:

-  d - Double Density
-  h - High Density
-  e - Extra High Density

Once this file is OPENed, the file pointer is positioned at the start of
the first sector of side 0 track 0 on the disk. Except on the ST/QL
Drivers (pre D-04), no other file can be OPEN on the disk if this access
is to work. For further details on how data is stored on a directory
device, please refer to the documentation of the device driver.

**Example**

Read the name of a HD disk inserted in flp1\_

::

    100 OPEN_IN #3,'flp1_*D2h'
    110 GET #3\1+ 0*256 + 0*2^16,sector$
    120 CLOSE #3
    130 PRINT 'The First Sector of the disk is;'sector$
    140 PRINT 'The name of the disk appears in this sector - it is ';sector$(5 to 14)

**NOTE 1**

Some older floppy disk interfaces do not support this.

**NOTE 2**

MIDINET and SERNET include code to stop you using this facility over the
Network to access protected files.

A12.6 Level-1 Device Drivers
----------------------------

These were the first Directory Device Drivers provided with the QL (and
early QL floppy / hard disk controllers) and allowed the QL to access
files on microdrives, ram disk, floppy disk and hard disk relatively
easily. Hard disks introduced their own system of storing a directory of
the files (and also some introduced their own non-standard sub-directory
filing system).

DIR would produce a list of all files present on the device (normally)
in the order in which they were created. You could even have files with
no names (for example flp1\_ ).

The main problem with these drives was when you had a hard disk (or even
a floppy disk) containing hundreds of files, it could be very difficult
to find the required file.

The drivers could also not read files which had been placed in
sub-directories on disks created by Level-2 Device Drivers.

A12.7 Level-2 Device Drivers
----------------------------

Level-2 device drivers were first introduced for the ST/QL emulator but
are now available on several emulators and QL expansion boards. These
allow the user to define sub-directories of sets of files on certain
directory devices.

Sub-directories are identified by grouping together all files which have
the same prefix. The main directory will only recognise the name of the
sub-directory and you will then need to look at the sub-directory to
obtain details of that set of files. For example, DIR flp1\_ may produce
the following output:-

::

    Example1
    870/1440 sectors
    boot
    PSION->

This would show that the disk in flp1\_ had the medium name 'Example1'
(see FORMAT), had a maximum of 1440 sectors (720K) of which 870 remain
unused, a boot file and a sub-directory called 'PSION' (see MAKE\_DIR).
You could then use::

    DIR flp1_PSION

to produce the following:

::

    Example1
    870/1440 sectors
    PSION_boot
    PSION_Quill

This still provides the same information about the disk, but goes on to
show that the sub-directory 'PSION' contains the files 'PSION\_boot' and
'PSION\_Quill'.

The use of sub-directories help to make the finding of files much more
easy, especially on devices like hard disk drives where there could be
several thousand file names to sort through.

A12.8 Level-3 Device Drivers
----------------------------

These device drivers provide all of the facilities of earlier device
drivers (allowing you to create sub-directories on Hard Disks, RAM Disks
and Floppy Disks), plus giving you the ability to read from and write to
PC and Atari TOS disks.

The DIR command prints the type of the disk in the specified device.

Unfortunately, there are limited means of formatting PC and ATARI disks
under the QL operating system and you have to use one of the various
public domain utility programs to do so (or use the commands AFORMAT and
IFORMAT if available).

If you try to write to an ATARI or PC format disk, then the filing
system will look at the file name which you are using and if it is an
invalid ATARI / PC filename (namely eight characters followed by a dot
and a three letter extension) then a Not Found error may be reported.
You are allowed to create sub-directories (up to four letters long) on
an ATARI or PC disk with MAKE\_DIR and also save filenames without an
extension (up to a maximum of 8 characters still).

Oddly, however, if you try to precede the three letter filename
extension by an underscore (as would normally be the case on the QL),
this is not translated to a dot, instead, this underscore is counted as
one of the 8 characters in the filename.

A slight inconsistency (possibly in the way in which PCs handle
sub-directories) is that if you make a sub-directory with the command::

    MAKE_DIR flp1_TEST
    SAVE flp1_TEST.BAS

will not actually place this file in the sub-directory - compare SAVE
flp1\_TEST\_TEST.BAS. You must also be aware that in keeping with PCs,
you must create a sub-directory on DOS or TOS disks before you try to
store a file in that sub-directory.

Until v2.52 of SMSQ/E, the filename needed to be in quote marks if it
was to include a dot.

There is also a problem in that if you read some information from a DOS
or TOS disk (for example with LOAD) and then remove that disk from the
drive and alter it on another computer, replacing the disk in the
original computer's disk drive (not having used another disk in the mean
time), it is impossible to tell that the disk has been modified, so any
further attempt to access that disk may render it unuseable. If you must
insist on doing this, use DEL\_DEFB before trying to access the disk a
second time.

One more difficulty that has been rectified from version 2.87 of SMSQ/E,
is that on earlier versions you could not use EXEC or EXEC\_W (or
similar command) to execute a file from a DOS or TOS disk - this is
because the file type will not be 1. You needed to copy the file from
the DOS or TOS disk to RAM disk and then use commands such as:

::

    OPEN #3,ram1_File_exe
    HGET #3,length
    HPUT #3,length,0,1,exdat
    CLOSE #3

exdat will depend upon the file itself (it is the extra information
which can be stored in a QDOS file header) - you will need to read this
from the original QDOS version of the file when it was created.

You will also find that some programs will not be able to use PC
formatted disks - for example the Psion programs (such as Quill and
QL-Xchange) which will both add a three letter extension preceded by an
underscore if one does not exist (such as \_doc).

A12.9 Using Alien Format Disks
------------------------------

QL Emulators which run on non-QL based hardware normally have a means of
creating a section of the hard-disk connected to a computer which can be
used for storage of QL files.

QPC also includes commands to allow you to access CD-ROM drives (see
CD\_PLAY).

However, the problem comes when you need to try and read data from (or
save data to) a floppy disk which is not in standard QDOS format.

There are several Public Domain and Commercial utilities which allow you
to convert files from or to IBM or Atari Format disks into a QDOS
format. Included amongst these utilities is the toolkit ATARIDOS (see
IQCONVERT for example). Other good examples are the public domain
IBMDISK program, the commercial program XOVER (by Digital Precision) and
the shareware program MultiDISCOVER (by Dave Walker).

However, if you want really flexible access to such disks, then you will
need an operating system which includes Level-3 Device Drivers (see
above).


