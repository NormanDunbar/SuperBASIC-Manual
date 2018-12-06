..  _a4-thor--computers:

A4 Thor Computers
=================

A4.1 Introduction
-----------------

Although we do not have direct access to a THOR XVI computer, we are
able to report on one or two comments passed onto us by users.

The THOR XVI was the last in a line of various QL compatible computers
originally produced by CST in the United Kingdom, and more latterly
produced in Denmark by Dansoft.

This computer was a very nice package, with much improved hardware and
also improvements to the operating system ARGOS. Unfortunately, not many
of these computers seem to have been produced and the constant changes
to ARGOS have made it very difficult to know where the current problems
lie. There now seems little prospect of this computer ever taking off
again, and it is highly unlikely that programs will be altered to suit
this computer.

v6.40 of the THOR ROM contained various disastrous bugs and it is
recommended that users alter their ROMs to either v6.39 or v6.41 (the
last ROM version to be produced). However, with the apparent demise of
Dansoft, you will need to try and contact other THOR members to see if
they will let you use their ROMs to re-blow your chips.

ARGOS is generally based on an MG ROM with parts of Toolkit II added on
- this helps to explain why only some of the THOR's commands support
default directories. Although some of the bugs are fixed, many are left
well alone, and (at least on some versions of ARGOS) new ones are
introduced, which can make some programs unreliable on the THOR. We have
attempted to highlight many of the known problems in the main body of
this manual, but this section contains one or two further sticking
points.

A4.2 KEYROW
-----------

The main problem with the THOR range of computers has always been their
handling of the KEYROW function, which is not supported on all of the
range. This was partially implemented on the THOR XVI to try and retain
compatibility but programs which use KEYROW cannot be guaranteed to run
on the THOR.

A4.3 MODE
---------

The THOR XVI introduced a new MODE 12 which provides the same resolution
as MODE 8 (256x256 pixels), but replaces the FLASH bit by an intensity
bit which enables the THOR XVI to display 16 colours on screen.

A4.4 The Thor Windowing System
------------------------------

There has never been a version of the Pointer Environment which will run
happily on the THOR XVI - instead Dansoft produced its own windowing
environment which moves the system variables and the start address of
the screen with all of the inherent problems faced by Minerva users.

This can however be turned off on start-up by using:

::

    CLOSE
    POKE SYS_VARS+133,-1
    OPEN #1,con_
    OPEN #2,con_
    OPEN #0,con_
    WMON 4

A4.5 BEEP
---------

Although implemented on the THOR XVI, this is unlikely to match with the
sounds produced on the QL.



