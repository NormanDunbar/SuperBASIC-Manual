.. |copyright| unicode:: U+00A9



Introduction
============

The Sinclair QL was officially released during 1984, and since that
date, has gone through several changes to both the hardware and the
operating system. Unfortunately, when the rights to the QL were sold to
Amstrad it looked as if the end of the QL was near in view of the fact
that Alan Sugar, Managing Director of Amstrad decided that the QL should
be withdrawn from the market.

Since that fateful day, several types of QL replacement have emerged,
including new Hardware platforms such as the THOR range of computers,
the AURORA replacement motherboard, the ST/QL hardware emulators
(including QVME and the Mode 4 Emulator), the Q40 and the QXL, a
hardware emulator that can be plugged into a PC. Several software
emulators have also been developed, allowing QL software to run on PCs,
Amigas, Apple MacIntosh and Unix based computers.

Some of these emulators are much faster than the original QL computer,
which itself can be speeded up by the use of new operating systems
(SMSQ/E and Minerva) and new, faster expansion boards (Gold Card and
Super Gold Card).

The QL has also been further expanded by the ability of the emulators
and the new AURORA and Q40 motherboards to handle much higher
resolutions (and more colours in the case of AURORA and Q40).

The QL is different from several other more popular computers in that it
has a built-in programming language (SuperBASIC) which has survived
(mainly unchanged) since the QL was first released. Various assertions
were made concerning the abilities of SuperBASIC when the QL was first
launched many of which did not exist at the time. Most of those promises
have now been fulfilled by third party toolkits. There are now even two
multitasking versions of SuperBASIC, called MultiBASIC which is built
into Minerva and SBASIC which forms part of the SMSQ/E operating system.

We, the authors of this book, think that SuperBASIC is a superb
programming language for several reasons:

-  SuperBASIC is part of the QL, whose multitasking operating system
   QDOS (and now also SMSQ/E) is extremely powerful even when compared
   with more popular (and expensive) ones.
-  SuperBASIC was originally implemented as an interpreter. This makes
   program development very fast. Several compilers are available which
   allow you to produce programs which can run easily and quickly on all
   versions the QL.
-  The version of SuperBASIC provided with the SMSQ/E operating system
   is extremely quick; in many cases, faster than when compiled with
   Qliberator.
-  SuperBASIC is designed to be extendable from SuperBASIC itself
   through user-defined PROCedures and FuNctions as well as from machine
   code via resident toolkits.

The latter point was indeed the motivation to write this book. There are
a lot of really useful toolkits available in the public domain which can
be used by a programmer in his or her programs and freely distributed as
part of it.

Not only is there a vast range of toolkits available to the SuperBASIC
programmer, but the QL's Operating System has also undergone various
changes, and with new QL compatible computers and emulators being
released, as well as the Minerva replacement ROM and SMSQ/E replacement
operating system, it is important that any programmer should know where
problems may occur in the use of each SuperBASIC command.

We have therefore attempted to cover each command in sufficient detail,
with useful examples, and a commentary on bugs and incompatibilities. No
doubt as each new implementation of SuperBASIC comes to light, so will
further problems and we will try to keep abreast of these. We would
refer you in general to the Appendix on compatibility, which contains
various guidelines for ensuring that programs should remain compatible
with future operating systems. More specific detail is contained in the
description for each command where problems are known to exist.

We have covered the commands contained in the following sources:

-  The standard QL ROM |copyright| Sinclair Research Limited / Amstrad plc.
-  The THOR ARGOS Operating System |copyright| CST and DANSOFT
-  The Minerva ROM |copyright| Minerva and TF Services
-  Super Gold Card, Gold Card, QXL and Trump Card |copyright| Miracle Systems Ltd.
-  SMSQ/E, SMSQ Operating Systems |copyright| Tony Tebby
-  Toolkit II and Hotkey System II |copyright| Tony Tebby
-  SERMouse |copyright| Albin Hessler Software
-  DIY Toolkit (sold as Cardware) |copyright| Simon Goodwin
-  AtariDOS and ATARI\_REXT |copyright| Jochen Merz Software
-  Turbo Toolkit (freeware) |copyright| The Turbo Team, David Gilham & Mark Knight
-  DJToolkit 1.16 (freeware) |copyright| Norman Dunbar & Dilwyn Jones
-  QPC version 4.04 specific commands |copyright| Marcel Kilgus.
-  As many Public Domain Toolkits as we can find and understand.

We have covered the Toolkit II and Hotkey System II because it is a
standard addition to a QL operating system and included on several
add-on expansion boards.

As you look at the range of toolkits already available, you will notice
that several commands appear in more than one toolkit. Unfortunately, a
command with the same name in two toolkits, may in fact have a different
syntax or even a different function! It is therefore our hope that with
the aid of this book, any future toolkits will remain compatible with
earlier ones, and existing toolkits will be amended to resolve these
incompatibilities.

If you do come across further incompatibilities, operating system
commands or public domain toolkits which are not noted in the manual,
then please do contact us as soon as possible so that we may investigate
the situation and incorporate them in the book. We may even find ways of
correcting the errors!

In the meantime enjoy SuperBASIC !

Contributing Authors
--------------------

- Franz Herrmann 
- Peter Jager 
- Rich Mellor
- Norman Dunbar - DJToolkit 1.16 additions.
- Norman Dunbar - QPC 4.04 additions.
- (Norman Dunbar - HTML conversion, tidyup etc.)

Installing Toolkits
-------------------

Most toolkits can be loaded and linked into the QL's operating system as
an addition to the existing SuperBASIC (or SBASIC) keywords simply by
using a command similar to one of the following three examples::

    LRESPR flp1_Toolkit_bin
    
::
    
    A=RESPR(x): LBYTES flp1_Toolkit_bin, A: CALL A

::
    
    B=ALCHP(x): LBYTES flp1_Toolkit_bin, B: CALL B

(where x is the length of the toolkit code).

Some toolkits include additional device drivers and must be loaded into
the resident procedure area of memory and therefore the third example
above must not be used, and the toolkit must be linked in before any
jobs are EXECuted (or else the toolkit can crash your system). We have
tried to include a reference in this book where this is the case.

The normal sequence of events for loading toolkits and other extensions
to the operating system is set out below:

#. Link in any speed enhancements (such as Lightning or Speedscreen)
   <--- not needed on SMSQ/E
#. Load any additional device drivers (such as Mem or History) <---
   check which ones are already included in SMSQ/E
#. Link in all required toolkits (those which contain device drivers
   should be linked in first).
#. Load the Pointer Environment (if required) <--- not needed on SMSQ/E
#. Load a secondary program to carry on setting up the system - this is
   because on pre-JS ROMs, any keywords added by toolkits are not
   available for use in the same program which linked them in.
#. Start up any required Jobs (such as ALTKEY, FSERVE or the Buttons
   provided by the Pointer Environment).
#. Use HOT\_GO if you use the Hotkey System II.

However, some toolkits insist that you enter a command before you can
actually use any of the other keywords provided by that toolkit. The
following toolkits need this:

- Toolkit II- You will need to enter the command TK2\_EXT, unless Toolkit
  II is built into your operating system (such as SMSQ/E) or you have used
  the commands AUTO\_TK2F1 or AUTO\_TK2F2

- BeuleTools- You need to enter the command Beule\_EXT

- BTools- You need to enter the command BTOOL\_EXT

- Tiny Toolkit- You need to enter the command TINY\_EXT

- ATARI\_REXT- You need to enter the command ATARI\_EXT

- Hotkey System- You need to enter the command HOT\_GO for any of the
  ALTKEY (or other HOT\_xxx) keywords to work.

(See the individual commands listed above for further details).



