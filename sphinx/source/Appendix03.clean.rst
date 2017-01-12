..  _a3-emulators:

A3 Emulators
============

A3.1 Introduction
-----------------

Not only are there replacement operating systems for the QL (namely QDOS
and Minerva), as well as replacement computers (AURORA, Q40 and THOR {no
longer available}), but there have been several emulators produced which
allow programs written for the QL to run on various other computers.

When Emulators access the hard disk on the host computer, you do not
have to worry about the fact that the hard disk is not in QDOS format -
the Emulators cope with this in one of two ways:

- The hard disk has to be partitioned, and one (or more) partitions are
  set aside for the QL files (FORMAT will only affect the specified
  partitions), or

- The Emulator creates a large single file on the hard- disk (for
  example called QXL.WIN) which is equal in size to the size specified
  with the FORMAT command and then QL files are stored within this huge
  file. The host computer will only see the one QXL.WIN file. This
  method is used by QXL and QPC.

It doesn't really matter which of these methods is used, as both protect
the PC files from being over-written by QL files.

Currently, there are emulators available for the following computers
(see the relevant section of this Appendix):

-  Apple Macintosh (Power PCs and 68000 Macs)
-  PCs(any with a spare ISA slot, otherwise 486 and Pentiums only)
-  ATARI(All models except the Falcon)
-  Any computer with an UNIX operating system

The main problem with using emulators is that some emulators (QLAY and
Q-Emulator) require a copy of the QL operating system. You can use a
copy of Minerva with these emulators (obtainable from TF Services -
specify that you need it on disk for use with an emulator) or a copy of
the original QDOS ROM. Apart from North America, the copyright on the
original QDOS ROM is vested in Amstrad plc. who have stated that it can
be supplied with emulators so long as their copyright notice appears and
also an acknowledgement is included in the manual. In North America, the
copyright is not owned by Amstrad plc. QLAY (at least) includes a copy
of the JS QDOS ROM, otherwise, can make your own copy of the QL's
operating system (from a standard QL) by using the command:

::

    SBYTES flp1\_OSROM,0,49152

Note that you cannot do this with a Gold Card or Super Gold Card plugged
in as these alter the operating system.

A3.2 Apple Macintosh
--------------------

A3.2.1 Q-Emulator
^^^^^^^^^^^^^^^^^

A commercial software emulator available from Daniele Terdina which
comes in two versions (v3.0 - for 68000 Macs and v2.1 - for Power PCs).
A version which runs on IBM compatible PC's is also available.

Minimum requirements are MacOS v7.0, 4Mb of memory, a colour monitor, a
1.44Mb floppy drive and a copy of the QL's operating system.

The speed of the Emulator is really dependent upon the machine on which
it is used - the Power PC version is said to nearly equal the speed of a
QXL when used on a MacIntosh with a 100 Mhz RISC chip.

Unfortunately, SMSQ/E will not currently work with the Emulator.

You may also want to obtain a copy of Toolkit II on disk to use on the
Emulator.

This emulator provides you with a QL with up to 4Mb of memory, which can
multitask alongside MAC programs. However there is currently no support
for Level-2 Device Drivers, Network ports or the FLASH / TRA commands.
You can read and write to QL floppy disks (DD and HD) and also use the
Mac's own hard-disk as a QL hard-disk. Minerva's dual screen mode is
also supported, but at present only the standard 512x256 pixel
resolution display can be used.

The Emulator has an in-built static and dynamic RAM disk and allows you
to use the MAC's serial ports (all standard QL BAUD rates are supported,
although it is recommended that you use hardware handshaking).

Some difficulties exist due to the different MAC keyboard - for example
an OPTION button is used instead of <ALT> and most MAC's will not
recognise more than two keys pressed down at a time.

A3.3 IBM Compatible PCs
-----------------------

A3.3.1 QPC and QPC2
^^^^^^^^^^^^^^^^^^^

Commercial software emulators available from Q Branch and Jochen Merz
Software.

QPC and QPC2 both need a 486 processor or better (a 486 SX- 25 minimum
is recommended, although a Pentium is better!), 4MB RAM, EGA graphics
and DOS 6.xx. Although both programs will work with Windows95, only QPC2
will work in a window under Windows95 (or Windows98 / NT). However, the
PC needs to be configured not to use any extended memory handling
devices and therefore the user will need to amend the PC's AUTOEXEC.BAT
and CONFIG.SYS files.

It allows between 1Mb and 16Mb of memory to be used by the QL operating
system and supports resolutions of at least the same standard as QXL
(v1.40 allows up to 1600x1200 and MODE 8). QPC2 will even stretch the QL
screen resolution to fit the PC screen, which can make the QL characters
appear much larger than usual.

These emulators are quick (current versions are as fast as the QXL) and
have faster disk, serial and parallel port access than the QXL. They do
however lack some of the QXL's extra hardware facilities, namely QL
compatible Network ports (although users can use SERNET to connect to
the QL).

One of the main problems is that the more memory allocated to the
Emulator, the slower its disk access - this is because of the slave
blocks used to store the contents of files so that if you load a file a
second time, it loads much more quickly (see DEL\_DEFB). As the QL uses
all unused memory as slave blocks, this can slow down initial disk
access (where the file has not been read before).

Compared with QXL, QPC and QPC2 do have their advantages also, including
the ability to access the PC's colour palette (and thereby dictate which
colours may be used in the QL modes), although this will hopefully not
come into the equation when the new colour drivers are released for
SMSQ/E. Also, both versions include commands to access the PC's CD ROM
drive, although at present only audio CDs are supported (see CD\_PLAY
and related commands).

QPC and QPC2 also allow you to have more than one QL 'hard disk' on the
same PC hard disk, by using a different filename for the QL hard disk
(other than QXL.WIN as mentioned above).

Both programs also come complete with the SERNET driver to allow you to
use the PC's serial (COM) ports as Network devices - this is however
somewhat limited as most PC's only have two such ports (and one is used
for the Mouse)! If you need more serial ports for a PC, please contact
us, as we have boards which can link up to 198 serial ports to a PC!!

The main problem with earlier versions of the emulator is with loading
screen images direct - see LBYTES.

**WARNING**

Do not allocate the whole of the PC's memory to QPC as this can cause a
disaster!!

A3.3.2 QXL II
^^^^^^^^^^^^^

This is a plug-in emulator (hardware) now available from Q Branch. QXL
II is based on a cut-down version of the 68040 chip which is extremely
quick and because it only uses the PC for access to display, keyboard
and disk drives, it can co- exist with other PC programs and its speed
is not dependent on the main processor speed of the PC.

There was an earlier, slower version of QXL sold by Miracle Systems Ltd.
which can have between 1M and 8M of memory.

The QXL boards simply plug into a standard 8 or 16 bit ISA slot on the
PC and are one of the fastest versions of the QL currently available
(including the original!!). They have 8M RAM in-built and run completely
independently from the PC, just using the PC's keyboard, display and
disk facilities. QXL even has QL compatible Network ports.

Unfortunately, there are few portable IBM compatible computers with ISA
slots and therefore if you wish to use an Emulator on a portable, you
will probably need to use one of the two software Emulators.

The main problem with the QXL is that it is fairly slow when accessing
the PC's floppy disk drives and serial / parallel ports. Also, users
have reported that the mouse response and screen re-draw are fairly
sluggish if you run the QXL in a DOS Window under Windows95. It is
therefore recommended that you only use QXL under a standard DOS window.

Although the QXL has its own QL compatible Network ports (SMSQ/E users
can also use SERNET), some QXL II boards display a few problems and you
may need to configure the QXL operating system to change the speed of
the network (some machines need it turned down to 24Mhz, others need it
turned up to 26Mhz). The Network unfortunately did not work on v2.25 of
the QXL software!!

When QXL was first released the software was still undergoing
development, and only supported a limited range of commands, lacking a
full implementation of SuperBASIC and programs compiled with either
Turbo or Supercharge would not run. The majority of programs compiled
with Qliberator also had problems. If you have one of these very early
versions, you should upgrade - the full version of SMSQ was released for
QXLs in March 1995.

QXL comes with its own operating system (SMSQ), but the much improved
operating system (SMSQ/E) is now also available for QXLs. SMSQ/E will be
needed if you wish to use more than the standard QL's 8 colours on the
QXL.

SMSQ as supplied with QXLs comes complete with a copy of Toolkit II (you
still need to use TK2\_EXT to install the toolkit) and Level-2 Device
Drivers. SMSQ can handle three different display resolutions in addition
to the standard QL 512x256 screen, if your PC has EGA or VGA graphics.
These are 630x350 in EGA mode, 640x480 in VGA mode and 800x600 on most
SVGA monitors. These display modes must be configured before the
emulator is used - compare SMSQ/E which allows you to change the display
at any time using the DISP\_SIZE command.

SMSQ adopted a different approach to SMSQ/E in that its main aim was to
be as compatible as possible with the original QL, whilst at the same
time being quicker than QDOS and incorporating an improved SuperBASIC
interpreter (it is very similar to SMSQ/E so far as the interpreter
goes). In fact, in the main keywords section of this book, we have
referred to SMS meaning both SMSQ and SMSQ/E.

For compatibility reasons, it is not possible for SMSQ to adopt the more
advanced drivers or an integrated Pointer Environment such as appear in
SMSQ/E. It can however work with the standard PTR\_GEN, WMAN and
HOT\_REXT files which are supplied with most Pointer Environment
software and therefore can use the Pointer Environment. In order to have
SBASIC set up as an Executable Thing, you will need to enter the command
SB\_THING on SMSQ after the HOT\_REXT file has been loaded.

SMSQ also includes facilities to access IBM compatible disks and the
hard-disk on a PC. There were however problems with earlier versions
which could not create more than one QL partition on each PC hard-disk
and limited each partition to 63 Megabytes (see FORMAT). Even in current
versions, if your PC does not support partitioning of hard-disks, you
can only have one QL 'hard-disk' on each DOS device - normally C:.

You can overcome this limitation by simply using DOS to rename the QL
'hard-disk' file (QXL.WIN) to something else and then create another
QXL.WIN file if you wish to have access to several QL 'hard-disks'. If
you do this however, you will need to use DEL\_DEFB from the QXL to
ensure that it recognises that a new QXL.WIN file is being used.

There were also problems on early versions of SMSQ in recognising when a
PC format disk had been swapped for another one and you may get the same
DIR listing for both disks. This was however fixed by using either
DEL\_DEFB or reading the directory of a QL format disk before inserting
the second PC format disk.

Lightning and Speedscreen must not be used with QXL, but the screen
driver supplied with SMSQ and SMSQ/E is nearly the same speed anyway.

QXL's incorporate an easy means of switching between the QL and the PC -
simply press <CTRL><SCROLL-LOCK> to switch out of QL mode and into DOS.
This is somewhat limited however, as the PC's display sometimes gets
distorted.

One of the problems which remains with QXL is that some users have
reported difficulties in FORMATting and writing to QL format HD disks -
the problems seem to vary from user to user, and it seems that this may
in fact be a problem related to the PC's own hardware.

A3.3.3 QLAY
^^^^^^^^^^^

This is a freeware software emulator in its very early stages of
development which works on most PCs and will run under either DOS or
Linux or even Windows95 (v0.84+). It needs a minimum of a 486 processor
running at 66Mhz with 8 Mb of memory in order to work. This is not
really a competitor to the two products listed above and may be
difficult to use if you've never seen a QL - it is however free and
available from the Web on:

http://www.inter.nl.net/hcc/A.Jaw.Venema (This link no lonegr works. NDunbar)

A copy of the JS QDOS ROM is supplied as part of this emulator.

From v0.84+, this emulator will actually allow you to use the QL inside
a window under Windows 95 (although this version will not support QL
ALTkeys) - all other PC emulators, except for Q-Emulator and QPC2,
currently insist on you using a DOS window.

At present it has a few problems in that it has poor error detection and
reporting. QLAY cannot currently work with a Mouse and early versions
only allowed the standard QL resolution display. From v0.85b (the
Windows version), various resolutions up to 1024x768 are supported, with
the window being scaled accordingly to fill the PC's screen. Early
versions (at least v0.7) did not support QL floppy disks, the PC's
serial ports or Networks - it is unknown whether these have yet been
added.

QLAY does however allow you to use Microdrives - what it actually does
is use a file on either a PC format disk or the PC's hard disk which is
identified as a QL microdrive by the extension .MDV - you create a new
'Microdrive' by copying from DOS the file EMPTYDSK.MDV onto the required
medium and give it a new name, such as QUILL.MDV. When you start up QLAY
(from DOS), you can pass it the names of the two microdrive files it is
to use as MDV1\_ and MDV2\_ and then any files which are SAVEd to MDV1\_
(or MDV2\_) will be stored as part of the DOS file. For example:

::

    QLAY -1QUILL.MDV -2DATA.MDV

will allow you to enter the command (inside QLAY) SAVE MDV2\_TEST\_bas
which will then create the QDOS file test\_bas inside the DOS file
DATA.MDV.

You can also specify whether QLAY is to use up to 8Mb of memory for the
QL (although you will need to use Minerva to cope with more than 768K)
and even whether microdrives are to be write-protected.

Unfortunately, early versions of QLAY provided no means of getting QL
files across to the PC to store in these microdrive files. There is now
a separate program (QLAYT) supplied to allow you to do this. A ramdisk
is also supplied.

A3.3.4 Q-Emulator for Windows95
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is intended to be a shareware Emulator, which again, is in its
early stages of development. It is based upon the Emulator of the same
name for the Apple MacIntosh and works only under Windows95. It requires
a 486 computer at least and supports both QDOS and Minerva (although as
with QLAY, you need to obtain a copy of the QL ROM). The Emulator
provides the user with up to 4M of memory and the current Alpha version
supports the PAR device, QDOS disks and host files.

This Emulator is currently limited to supporting the standard QL display
(512x256 pixels); and supports the PC's mouse, and QL BEEP commands
(provided that you have PC DirectX drivers). It can use any PC BAUD rate
up to 256,000 as well as those supported by the QL.

The TRA command is not supported.

A copy of this Emulator and further details can be obtained from:

http://www.geocities.com/SiliconValley/Heights/1296/winql.html (This link no lonegr works. NDunbar)

A3.4 Atari Computers
--------------------

There are several hardware based Emulators which are referred to in this
book collectively as 'ST/QL Emulator' (excluding SMS2). There is also
one software Emulator (SMSQ/E).

A3.4.1 The ST/QL Emulator
-------------------------

This in fact relates to three different QL Emulators which can be fitted
to the Atari range of computers. The type of Emulator needed depends
upon the Atari computer being used and also when the Emulator was
purchased.

All later versions of the Emulators come complete with Atari\_rext and
AtariDOS toolkits.

(a) Atari-QL Emulator
^^^^^^^^^^^^^^^^^^^^^

A commercial hardware emulator made by Futura Datasenter in Norway for
MEGA ST and 520/1040 machines - this has not been available for some
time. Some versions of the emulator supported MODE 8, some did not - it
is impossible to check if it does. This only supported the original QL
screen resolutions.

(b) Extended4-Emulator
^^^^^^^^^^^^^^^^^^^^^^

A commercial hardware emulator for all ST machines (268,520,1040 but not
STE), including STF, STFM and MEGA ST models. It will however not work
on the Falcon 030. This may still be available from Jochen Merz
Software.

Although this has its own operating system built in, you can upgrade it
to SMSQ/E if you wish.

(c) QVME
^^^^^^^^

A plug in commercial hardware emulator for Mega STEs and TTs that plugs
into the VME slot. It unfortunately will not work with the Falcon 030.
This is available from Jochen Merz Software and current versions come
complete with SMSQ/E.

This supports a wide range of screen resolutions up to 1024x780 pixels
(or theoretically, if you can obtain a monitor, 1024x1024 pixels) are
supported. You are also able to choose at runtime (unlike the
QL-emulator Extended4) the resolution in which you wish to work, using
the DISP\_SIZE command - this is only limited by the capabilities of
your monitor.

In General
^^^^^^^^^^

Both of the first two hardware emulators must be fitted inside an Atari
ST computer and needed a bit of careful soldering to make them work. The
QVME simply plugs into the Atari ST.

Once fitted, all of these hardware emulators are based on a JS ROM
(unless you have installed SMSQ/E on the QVME emulator); indeed a
slightly patched copy of a JS ROM is loaded as the basis for the
emulator's operating system; these patches are not documented. The
operating system may be loaded from either disk, harddisk or EPROM.

Once loaded, you are presented with the normal QL start-up screen,
although later versions of the emulator allow you to start-up by
pressing the following:

-  F1... MODE 4 + Monitor
-  F2... MODE 4 + TV
-  F3... Extended MODE 4 + Monitor
-  F4... Extended MODE 4 + TV

(On the QVME, only the first two options are displayed).

Together with the image of a JS ROM, the emulator loads in its own set
of drivers - please see the section on Drivers. In the latest versions
of the emulator software (E-level), the window drivers are almost as
fast as with Lightning.

Unfortunately, in the Extended MODE4, the parameters of CON and SCR
devices are not recognised by early versions of Qpac2, which will
display them merely as SCR\_ or CON\_.

Also present as standard on Level-E drivers (and later) of the Emulators
is the Pointer Environment, Toolkit II, the OUTLN command, a RAM disk
driver and the Hotkey System II.

Microdrives
^^^^^^^^^^^

The emulator cannot support microdrives and if you try to access the
microdrive, error -7 (not found) will be reported. If a program has been
written for microdrives, either use

::

    EXCHG flp1_file,'mdv','flp'

or

::

    FLP_USE 'mdv'.

BEEP
^^^^

The emulator cannot support QL sound and therefore this command usually
has no effect.

MODE 8
^^^^^^

This is not supported (except on some versions of the original
QL-Emulator). Any attempt to access MODE 8 will have no effect, and
displays in MODE 8 have the same effect as trying to load a MODE 8
screen in MODE 4.

All software will however run happily on the emulator (although see
below if you are trying to use the Extended resolutions), although it
will look a little odd.

MODE 4
^^^^^^

Current versions of the emulator support a much enhanced screen
resolution. This is known as Extended Resolution and on the Extended
Mode 4 Emulator is chosen from the start-up screen (see above). On QVME,
you can configure the size of the screen resolution or even alter it
whilst the Emulator is being used.

This extended resolution mode has the same four colours as normal MODE
4, except that instead of displaying 512x256 pixels, the resolution of
the screen is 768x280 pixels on the QL-Emulator EXTENDED4 and anything
between 512x256 pixels and 1024x1024 pixels on the QVME (this can be any
value in the range in steps of 8 or 16 pixels, provided that you have a
powerful enough monitor).

Well written software must therefore not assume the resolution of the
screen, and if writers wish to access these higher resolutions, the
functions QFLIM, XLIM and YLIM have to be used. The logical consequence
is that higher resolutions can only be supported with the help of the
Pointer Environment, thus underlining that this extension is absolutely
obligatory.

Unfortunately some software writes directly to the screen and assumes
that the screen will be 512x256 pixels and start at address $20000. This
will cause untold havoc in Extended MODE 4, although such software will
run happily in normal MODE 4 on the emulator. Interestingly, this odd
kind of software runs happily on QVME, because this has its own screen
memory on-board and leaves the 32k RAM from $20000 upwards untouched; so
it does no harm if software writes directly into memory... you will
simply not see the effect of this.

ROM Memory
^^^^^^^^^^

The QL ROM on the emulator is actually stored in RAM, which means that
if software tries to write to addresses in the range 0...65535, the
Emulator is likely to crash. On a standard QL, writing to ROM has no
effect. This should be avoided in all cases!

You can plug QL-ROM cartridges into the Atari ST with the help of
special hardware.

Network
^^^^^^^

The Emulator cannot access the QL Network which was always very
particular to Sinclair. This is really a pity. There does however now
exist a means of communicating via the MIDI port to other STs (the
MIDINET driver) and even the serial ports (the SERNET driver). See the
separate Appendix concerning Networking.

Devices
^^^^^^^

The following devices are supported on the ST/QL emulators: flp, win,
ram, dev, ser, par, prt, nulf, nulz, null, nulp, pipe\_<length> pipe,
pipe\_name/pipe\_name\_<length>, sdump; where flp, win and ram are at
'Level-2'.

Lightning/Speedscreen
^^^^^^^^^^^^^^^^^^^^^

Neither Lightning nor Speedscreen can be used with current versions of
the Emulator. Lightning could be used with drivers before Level-E, but
you needed a special Atari version.

Qliberator
^^^^^^^^^^

You will need to use v3.22a of the Runtimes at least on these Emulators.

A3.4.2 SMSQ/E
-------------

This is a commercial software emulator which can run on all ST models
(but not the Falcon). It is fast and very flexible - in fact it is the
operating system now sold with QVME, Extended4, and QPC emulators. This
is available from Q-Branch, or from Jochen Merz Software. Note that
there are several ST versions, call the supplier before ordering.

SMSQ/E is to be the new standard operating system for future QL
developments and is also available for QXL II, AURORA, Q40 and QLs with
either a Gold Card or Super Gold Card attached.

Lightning/Speedscreen
^^^^^^^^^^^^^^^^^^^^^

Neither Lightning nor Speedscreen can be used with SMSQ/E.

Qliberator
^^^^^^^^^^

You will need to use v3.22a of the Runtimes at least on SMSQ/E.

Please refer to the SMSQ/E Appendix for more details.

**NOTE:**

The emulator is RAM based and you can therefore expect some problems
with software which tries to write to the original QL ROM (in the range
0...65535).

A3.4.3 SMS2
-----------

This is a board which plugs into the side of the Atari ST computers,
which was marketed by Furst Ltd. It is no longer available. SMS2 was not
marketed as being an emulator for the QL, but as an add-on enhancement
for the Atari's native operating system.

It includes a version of the Pointer Environment including QPac 2, and
can run a fair amount of QL software. The main problem with SMS2 is that
it does not provide a version of SuperBASIC, although it is possible to
create programs under SMS2 using the in-built version of the QD editor
(© Jochen Merz Software) and the in-built Qliberator compiler (©
Liberation Software).

Unfortunately, the use of this board is restricted, since it only worked
on Atari ST computers. It would also work on Atari STE computers
however, provided that the QVME board was plugged in also!

The way in which SMS2 loads programs is very different to other
implementations of SuperBASIC due to the lack of an interpreter. We feel
that this is beyond the scope of this book.

SMS2 provides the following facilities as well as being able to run
various QL software:

-  Access to Atari serial and parallel ports (details of ports unknown)
-  Access to Atari floppy disks and SCSI hard drives (presumably it can
   handle QL disks)
-  Network facilities are available for SMS2 via the MIDINET extension
   (now provided with SMSQ/E).
-  Built in ram disks
-  Supports Atari mouse and Atari monochrome display (640x400 pixels)

A3.5 Commodore Amigas
---------------------

A3.5.1 Amiga QDOS
^^^^^^^^^^^^^^^^^

This is a public domain software emulator available for Amiga computers.
It was distributed together with a load of public domain QL software on
a CD cover disk on the Amiga Format magazine (published by Future
Publishing of Bath) in September 1996. It is also available from
Qubbesoft P/D.

Details about the emulator are on the Web at:

http://www.emulnews.com/aer/articles/af (This link no lonegr works. NDunbar)

The program loads the operating system from disk and basically simulates
a JS ROM QL with a few additions in later versions. Although a public
domain toolkit is included with the package that contains many of the
commands added by Toolkit II, you really could do with a copy of Toolkit
II on disk to load into the Emulator (with LBYTES
flp1\_Toolkit2\_cde,49152).

There is no need for the EPROM\_LOAD command on this Emulator since,
once any toolkits have been loaded into the Amiga's memory (as with
Toolkit II above), you can do a warm reset of the system by pressing
<CTRL><SHIFT><ALT><TAB> which will not wipe out any code previously
loaded into the QL's EPROM area.

The emulator has been (and is still being) improved independently by
several people; making it impossible to be certain of which versions
have which bugs in them.

It is recommended that you get at least v3.23 which had the following
enhancements over earlier versions:

-  Supports the full range of Motorola processors (68000, 68010, 68020,
   68030, 68040 and 68060).

-  MODE 8 support (excluding FLASH)

-  Authentic BEEP sounds which are the same as on the original QL.

-  QL compatible disk handling, including the ability to use QL HD disks
   and sub-directories.

-  The system variable SYS\_PTYP (at offset $A1) is supported, allowing
   you to test the type of processor on which Amiga QDOS is running.

-  Support for dual screen display MODE.

This emulator is also available in the form of QDOS Classic, which has
been released for use on the Q40.

**NOTES:**

Memory The emulator is RAM based and you can therefore expect some
problems with software which tries to write to the original QL ROM (in
the range 0...65535).

ROM Cartridges
^^^^^^^^^^^^^^

These cannot be connected to the Amiga.

Network & Microdrives
^^^^^^^^^^^^^^^^^^^^^

As with the ST/QL Emulator, none of these are supported.

MODE 8
^^^^^^

Before v3.23 this was not supported and any attempt to use this will
result in MODE 4.

BEEP
^^^^

Before v3.23 this was not supported.

MODE 4
^^^^^^

Because of the way in which the Amiga's display works, some displays can
cause flickering of the screen, or even a scrolling screen. This has to
be controlled by altering the speed at which the Amiga's Blitter chip
updates the screen (on early versions of the emulator, this was achieved
by using POKE 164082,x). In v3.20+ SCR\_PRIORITY was added to perform
this task.

You can actually alter the four colours available in MODE 4 if you wish,
by POKEing the hardware. To do this, you will need to POKE\_W a new word
value (up to 4095) into one of the following addresses, each one
representing one of the QL's standard 4 colours (note the need for quote
marks around the address due to the limitations of QL maths):

::

    POKE_W '14676352', black
    POKE_W '14676354', red
    POKE_W '14676356', green
    POKE_W '14676358', white

Beware that you should not try to read the values at these addresses
(for example with PEEK\_W) as this is likely to alter the contents!

DEVICES
^^^^^^^

The standard QL devices (except MDV) are all supported without any
alterations. However, the Qjump static RAM disk supplied as RAMPRT does
not work. Unfortunately, disk access is somewhat slower than on the QL
in all current versions of the emulator.

In v3.10 the serial port could successfully receive data from the QL at
up to 9600 BAUD. v3.20 managed to send data to the QL at up to 1200 BAUD
and to the Apple Macintosh at up to 19200 BAUD. We do not know at
present whether later versions have improved these figures.

Disk formatting was also exceptionally slow prior to v3.23 and before
v3.10, if Amiga-QDOS wrote to a disk, it could not be read on a standard
QL.

TAS INSTRUCTIONS
^^^^^^^^^^^^^^^^

The main area of incompatibility with the Amiga QL Emulator is the fact
that the machine code TAS instruction, which is used to test and set a
byte in one command, does not work properly on the Amiga. However, there
is a small program supplied with the emulator which patches these
instructions in any given program. All programs compiled with Turbo and
SuperCHARGE need to be altered in this way. If a program has been
compiled with Qliberator, you will need to patch the runtimes in this
way.

Note that this incompatibility has been completely cured on certain
versions.

A3.6 Unix Systems
-----------------

A3.6.1 UQLX
^^^^^^^^^^^

This is a shareware software emulator by Richard Zidlicky, still in an
early development stage.

In order to work it requires Unix or a Unix-like operating system plus
both gcc and Xwindows. It will however work on at least 5 types of
processor: HP-PA, INTEL (486 or better), MIPS, PPC and SPARC. If you use
Linux on the Q40, this emulator can be used as another method to allow
the Q40 to boot up as either a Linux machine or a QL!!

Current versions support JS ROMs (or Minerva), Toolkit II and MODE 4
displays. You can access the floppy disks and up to 4MB of RAM. You can
also create and access UNIX directories using Level-2 Device Drivers.

If you use Minerva, you can use higher resolution display modes (up to
8192x4096 pixels) and access 16MB of RAM.

The main incompatibility problem with this emulator is due to the case
sensitive names used by Unix (ie. filenames).



