..  _a5-expansion--boards:

A5 Expansion Boards
===================

In this section, we give a brief description of the more common
expansion boards which are available for the standard QL which go
further than merely increasing the memory of the machine or adding the
ability to read disk drives (or hard disks), normally improving the
speed of the machine and providing additional toolkit facilities.

A5.1 GOLD CARD
--------------

This expansion card, unlike other memory and disk expansion cards for
the Sinclair QL provides a massive increase of memory (a total of 1920K)
for the QL as well as increasing the speed of the QL by about 4 times.

Gold Card also provides Level-2 device drivers as standard and allows
the QL to access up to three Double Density (DD), High Density (HD) or
Extra-High Density (ED) disk drives. Toolkit II and a battery backed
clock is also in-built.

The main problem which may be encountered by users and software authors
alike, is that it copies the QL's ROM into RAM, which means that like
the emulators, any programs which try to write to addresses in the range
0..65535 are likely to crash the computer.

It should also be noted that some combinations of Gold Cards and QLs
allow POKE 114796,0 to force the Gold Card to run at 24MHz (it normally
runs at 16MHz compared to the QL's 12MHz). The circumstances where this
works are undefined at the moment, but see below. Some users have
however reported problems with some software running at this speed, and
in particular the network and microdrives are unuseable. The Gold Card
can be returned to normal with POKE 114796,255.

The so-called Gold Card Go-Faster POKE works on a certain series of Gold
Cards, in connection with random effects only. We highly dis-recommend
the use of this POKE, it may overheat the processor and damage your Gold
Card. Please, forget about it.

Gold Cards will support the SMSQ/E operating system if you wish to use
this. A Gold Card is the minimum expansion board required to run an
AURORA.

A5.2 SUPER GOLD CARD
--------------------

This board provides the same facilities as the Gold Card plus much more.
It is much faster, being approximately 3 times quicker than a Gold Card.
It uses a 68020 chip and provides 3986K of memory.

It suffers from the same problem as the Gold Card in that it copies the
operating system into RAM.

This card also allows you to set a flag (using AUTO\_TK2F1, AUTO\_TK2F2
and AUTO\_DIS) to say whether the QL should automatically start up in
either Monitor or TV mode and with or without Toolkit II present.

Other additions include an in-built parallel port and the ability to use
four disk drives. There is also a cache on- board the processor which
can make programs run much quicker (although you may need to use
CACHE\_OFF to disable this to make some programs work).

You can also automatically disable or enable the second screen (see
SCR2DIS) which is provided by Minerva and also used by some software -
this can therefore cause problems with some programs, especially games.

Again, this card can be used to with SMSQ/E and AURORA.

A5.3 AURORA
-----------

AURORA allows the QL to display much higher resolutions on Monitors (up
to 1024x768 pixels) and also speeds up the operation of the QL. It is no
longer available as new, but may be obtained second hand. Aurora is a
replacement for the QL motherboard, and needs a Gold Card or Super Gold
Card to work, together with various chips from the original QL board
(including an operating system).

You would normally use this board to build a replacement QL in a PC
tower case (although it is just about possible to use the original QL
case). You will also need some floppy disk drives (the microdrives are
not supported), a Qplane (to let you plug the various boards together),
a keyboard interface, an SVGA or QL monitor and cables. The BraQuet from
Q Branch and the MPlane from TF Services are also recommended to ease
the assembly of the system (the latter is a substitute for Qplane).

If you intend using Minerva with AURORA, you will need at least v1.86.
It is also recommended that you use AURORA with a Super Gold Card as the
standard Gold Card limits what you can do with the enhanced graphics
capabilities.

Although any QL operating system can be used with AURORA, you will need
SMSQ/E to make use of the higher graphics resolutions.

Several programs have difficulty working under Aurora and SMSQ/E v2.75+
(these later versions allow the use of the higher resolution screens).
The reason for this is that even if SMSQ/E is configured to start in
512x256 resolution mode, Aurora uses a fixed screen width of 256 bytes
(instead of the normal 128 bytes in this mode) and therefore has to also
move the screen from the normal base address.

To try and overcome this problem, Aurora copies anything written to the
old screen address (131072) across to the top left hand corner of the
new screen. However, this is not a two-way process and therefore if
Aurora's screen is altered (for example by BASIC PRINT commands), this
alteration will not appear on the picture stored at the old screen
address, making a mockery of hand-written machine code pan / scroll
routines for example.

Luckily, anyone using Aurora will have access to a second operating
system which can be used to run the programs successfully. After all, it
is this second operating system which is used to load in SMSQ/E!!

A5.4 Q40
--------

Q40 is a replacement motherboard for the QL. It is supplied with 16Mb
RAM (although it will support up to 32Mb) and an I/O card. You will need
to add a tower case, a keyboard, floppy and hard disk drives, a standard
PC monitor and mouse. The Q40 even has the ability to drive stero sound,
using an in-built digital to analogue converter which can be used with
either speakers or headphones. All drivers and equipment to connect
these items to the motherboard are built in.

The Q40 is a full-blown 68040 processor at 40Mhz with a maths
co-processor. This makes it an extremely quick version of the QL. It is
hoped that later versions with a 68060 processor will be available in
due course.

You can use either Linux, SMSQ/E or Classic QDOS (developed from the
Amiga QDOS Emulator) as the main operating system with the board. These
will all make the most of the Motorola processor, making the Q40 a good
competitor to a standard PC. There is also the added benefit that with
Linux working on the machine, the Q40 has the ability to access the
internet.

Although Q40 supports the original QL screen (at base 131072), it also
allows the QL to display much higher resolutions on Monitors (up to
1024x768 pixels).

Further, there is the added bonus that with SMSQ/E, the Q40 now supports
enhanced colour modes, including a 256 colour mode and a 24 bit full
colour mode, which can vary fom program to program. Background
wallpapers can also be loaded, meaning that this is a very flexible QL
successor indeed.

The Q40 is available from QBranch.

A5.5 HERMES / SuperHERMES
-------------------------

Hermes is a replacement board for one of the QL's microchips (the 8049),
which is also used on the AURORA replacement mother board - Hermes is
available from TF Services. Hermes provides the QL with much more
reliable serial port communications, improved sound and keyboard.

Hermes fixes some of the problems inherent in the original QL, including
supporting independent input BAUD rates for each serial port (not
necessarily the same as the output BAUD rates), together with full
support for input BAUD rates of 19200. Problems with the QL's BEEP
command are also fixed, meaning the pitch of the sound does not affect
its duration.

SuperHERMES is an improved version which also adds an additional high
speed serial port (up to 57600 bps), three low speed serial ports (30
bps to 1200 bps) which can be used for a serial mouse or a graphics
tablet. This also includes a keyboard interface (to allow you to use a
full size serial IBM AT keyboard), a capslock/scrollock LED connector
and 1.5K of RAM which can store data whilst the QL is switched off.
Unfortunately at present, without a special public domain program
written specifically for use with SMSQ/E, you cannot use a keyboard
linked to SuperHERMES to reset the computer (for example with the
soft-reset provided with Minerva or SMSQ/E).

If you want to use independent BAUD rates, you will need SMSQ/E or
Minerva as well as Hermes/SuperHERMES.

A5.6 QuBIDE
-----------

QuBIDE is a board which provides the QL with access to modern PC Hard
Disks and is no longer available new. If you intend using this board,
you will need expanded memory (expansion cards can be plugged into the
QuBIDE interface).

Early versions of QuBIDE will work with most IDE standard Hard Disks and
contain WIN\_DRIVE, WIN\_USE and MAKE\_DIR commands similar to those
listed in the manual. However, the MAKE\_DIR command will not work if
any files already exist which would be inside the sub-directory (unlike
the standard implementation of this command).

There is also a v2.xx ROM available for QuBIDE, which allows access to a
wider range of Hard Disks (ATAPI/IDE standard). You can also specify
that MAKE\_DIR will work as per the standard implementation. A trashcan
facility is also added, where deleted files are simply moved to the
'trashcan' and have to be specifically removed at a later date (similar
to the Recycle Bin on Windows 95).

Unfortunately, problems have been reported with the Trashcan facility
which makes it unreliable.



