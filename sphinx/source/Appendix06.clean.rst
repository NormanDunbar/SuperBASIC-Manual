..  _a6-compatability:

A6 Compatibility
================

Most QL software is well written, and provided that you use standard
SuperBASIC commands and make no assumptions such as about addresses in
memory, or the size and location of the screen, it would appear to work
happily on all different QL and QDOS compatible set-ups. Unfortunately,
as always, there are some exceptions to this rule, and the areas which
appear in the following sections would appear to cause the greatest
problems:

A6.1 Addressing
---------------

As the QL was developed, the designers tried to leave everything
open-ended so that nothing could be taken for granted. However, towards
the end of 1984 (the first year of the QL's long history) things
appeared to have settled down with the JS ROM in the UK and USA, and MG
ROM version elsewhere. Without any later ROMs in sight, software writers
got very lazy and rather than write a few lines of machine code to check
for the address for various things (such as the start of the screen):
they assumed that it would always remain where it had been, and so
started to use absolute addressing.

Likewise, programmers assumed that the QL's operating system would
always appear in ROM and they could therefore write routines which tried
to overwrite parts of memory, regardless of whether they were pointing
to ROM or RAM - after all, it could not harm the operating system as you
cannot write to ROM, can you (!).

Another problem are programs which use RESPR to reserve memory for
themselves at a particular place - the boot programs typically include
lines such as:

::

    10 Addr=273102
    20 A=RESPR(0):A=RESPR(A-Addr)
    30 LBYTES flp1_Program_cde,Addr:CALL Addr

Unfortunately, later developments in the QL world, namely emulators and
the Gold Card (for example), have moved the QL's operating system into
RAM, meaning that it can be overwritten, thus crashing the whole
machine. Parts of memory are moved around freely, making use of the
calls incorporated into QDOS by the QL's designers and even the speed of
the QL has altered. Despite the best attempts of the manufacturers of
the Gold Card and emulators, this has resulted in one or two
incompatabilities with older software.

A6.2 Speed
----------

Both QDOS emulators and the Gold Card have greatly increased the speed
at which the QL works, making some programs unuseable. Luckily the
effects of this are limited by various commands which slow the operating
speed of emulators and the Gold Card down.

A6.3 The Operating System
-------------------------

Some software in the market was written with specific versions of the QL
ROM in mind. For example, one program which was quite a useful
SuperBASIC utility, would appear to only work on JS and MG ROMs. This
software can only become redundant as more and more users upgrade their
systems to take advantage of the latest developments in the QDOS
operating system.

A6.4 Memory
-----------

Some older software is not address independent, which means that it has
to be loaded at a specific place in memory. This can prove impossible on
machines with expanded memory, but luckily commands do exist to reduce
the memory size. We have however come across one program, which although
it is address independent, refuses to work correctly whenever the system
on which it is running has anything more than the QL's original 128K
(even if only 128K is set aside for use by the program).

A6.5 The Stack Pointer
----------------------

As any machine code programmer will be aware, the processor's address
register a7 is used by the operating system as the stack pointer. Some
software attempts to set this to an absolute address when the program
begins (even though there is no need for this). If such a program is not
executed as a task, then it is likely to fall over on Minerva and
SMSQ/E.

A6.6 Compilers
--------------

SuperBASIC compilers are an excellent means of getting the best of two
worlds: the flexibility and clarity of a SuperBASIC program, but with
the speed of machine code. Unfortunately, although the SuperBASIC
compilers have mainly kept pace with the development of QDOS, some
software originally compiled with earlier versions of compilers has not
been upgraded, meaning that it may not be compatible with the latest ROM
versions.

There are two types of SuperBASIC compiler which have been produced for
the QL, namely true compilers (Turbo and Supercharge) which produce
independent machine code, not relying in any way on SuperBASIC
structures (and the code produced is therefore much more portable
between different QDOS machines) and so-called psuedo compilers
(Qliberator) which produce machine code which still uses SuperBASIC
structures and calls.

Although the former produce much quicker code, they are not as versatile
as the latter as they expect SuperBASIC commands to be used in a certain
manner and cannot therefore recognise the enhancements introduced to
SuperBASIC commands by Minerva SMSQ/E and emulators.

There is also a problem in that programs compiled with Turbo will not
work on versions 2.25 - 2.31 of SMSQ. You will also find that some Turbo
compiled programs will not work if started from a copy of BASIC other
than Job 0 (on both SMS and Minerva) and also neither compiler can
currently compile a program which from within a multiple copy of BASIC.

Patch programs have been released which enable Turbo compiled programs
to be used on a system which has a large amount of memory (such as the
Q40). Later versions of the Turbo Toolkit (v3d27 and later) are also
required for better compatability.

However, one of the remaining problems with SMSQ/E which is displayed by
Turbo compiled programs is the failure of the in- built Integer to ASCII
conversion routine to cope with negative integers. This means that Turbo
compiled programs remain unreliable on current versions of SMSQ/E -
refer to PRINT for an example.

A6.7 High Resolution Displays
-----------------------------

More and more QL implementations are now able to use much higher screen
resolutions than the original 512x256 pixels (or 256x256 pixels in MODE
8). Unfortunately many programs were written before this facility was
available and therefore will not work correctly on higher resolution
displays. Even if they do work, the program may be confined to a small
section of the screen, normally the top left hand corner, and use fonts
which are much too small to read.

The only answer to this (unless a new version of the program is
released) is to use a lower resolution screen (see DISP\_SIZE) or to put
up with the slight inconvenience. Aurora has other problems too - see
Appendix 5.3 for more details.

You should however be aware that on some monitors, a lower resolution
screen may still not fill up the whole area shown by the monitor - this
does not cause a problem in itself and there is nothing you can do about
it - it is due to the difference in ratio between 512x256 pixel displays
and standard PC (or ATARI / MAC / UNIX ...) displays.

Appendix 16.4 is also of interest in connection with High Resolution
Displays.

A6.8 String Lengths
-------------------

The maximum length of strings varies on each QL implementation (even
though you can use DIM to dimension a string up to 32767 characters,
this does not mean that you will be able to use all of those
characters!!). SMSQ/E allows a maximum string length of 32765
characters, whilst Minerva allows a maximum string length of 32764. QDOS
ROMs allow a maximum of 32766 characters. On the other hand FILL$ is
allowed to be used to create slightly different string lengths - on
SMSQ/E this is 32764 characters, on Minerva 32767 (except on v1.98 where
a limit of 32764 characters was implemented) and on QDOS ROMs, FILL$ can
produce strings up to 32767 characters long.

The outcome of this is that the maximum length that should be used for a
string should be 32764 characters which is the limit imposed by the
Turbo compiler.

A6.9 Later Processors & Gold Cards
----------------------------------

Various QL implementations use a chip as the main processor which is not
a 68008 chip (the chip that the QL was originally designed to use).
These later chips have various facilities, such as caches which can
cause problems with some software (see CACHE\_OFF). You may also note
that some leisure software does not work on a GOLD CARD QL - this is
normally where the command SCR2DIS has been issued - some leisure
software insists that the second screen is enabled!!

A6.10 Finally
-------------

Specific points to watch out for on the different QDOS implementations
are covered in the appendices dealing with each one.

There are also various points explained in the main keywords section of
this book.




