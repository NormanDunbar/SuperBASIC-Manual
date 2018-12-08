..  _qdos-dlr:

QDOS$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QDOS$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn, TinyToolkit, BTool                                           |
+----------+-------------------------------------------------------------------+

This function returns a string containing the version code of the
operating system on which SuperBASIC is running. For example ::

    PRINT QDOS$

- Version 1.03 was the first main version of QDOS (an upgrade is essential if you have an earlier version!)
- Version 1x13 is for all MGx ROMs, eg. 1G13 for the MGG.
- 1.63 was the first version of Minerva.
- 1.76 was the first version of Minerva with reliable MultiBASICs.
- 1.98 was the latest and best version of Minerva
- 2.xx SMS version.
- 3.xx is the version number of the Amiga QL Emulator.
- 4.xx is the first version of ARGOS on a THOR 1 computer. #
- 5.xx is the version of ARGOS on a THOR 20 computer.
- 6.xx is the version of ARGOS on a THOR XVI computer.
- 6.41 is the final version of the THOR ARGOS ROM.

**NOTE 1**

VER$ is normally used to identify the version of the SuperBASIC
interpreter and QDOS$ to identify the version of QDOS (the operating
system). However, as SuperBASIC is an integral part of the operating
system on most QDOS computers, there should really only be a need to use
one of these functions and not both.

**NOTE 2**

The '.' in QDOS$ is changed on MG and SMS v2.50+ (on Gold Cards and
Super Gold Cards only) to reflect the country code of the language
version currently loaded.

**CROSS-REFERENCE**

:ref:`ver-dlr` contains another code identifying the
operating system. :ref:`ver-dlr`\ (1) is identical to
:ref:`qdos-dlr` for Minerva ROMs and SMS. You should
also look at :ref:`machine` and
:ref:`processor`.
:ref:`lang-use` allows you to change the
operating system language.

