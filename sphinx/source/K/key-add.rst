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

    100 TK2_location=KEY_ADD("TK2_EXT")
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
    120 DEFine PROCedure WRITE_DATE
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

