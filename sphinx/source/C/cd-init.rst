..  _cd-init:

CD\_INIT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_INIT [name$]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

QPC is able to use a CD player linked to a PC in order to play Audio CDs
at present.

You first of all need to initialise the CD drive by using this command.
CD\_INIT causes QPC to seach for a CD-ROM drive and initialise the
driver.

You can either pass the name of the drive as a parameter or, if you do
not use name$, then QPC will use the PC program MSCDEX (if present) to
locate the CD-ROM Drive. MSCDEX can be loaded in the PC file
AUTOEXEC.BAT if you wish, otherwise the CD drive name must appear in the
PC file CONFIG.SYS.

**Example**

CD\_INIT 'mscd001'

**NOTE 1**

This command will only be recognised once.

**NOTE 2**

The CD player commands and functions will not work if you have not
loaded the PC's CD-ROM driver in config.sys, for example with the line:

DEVICE=C:\\CD\\CDROMDRV.SYS /D:MSCD001

**CROSS-REFERENCE**

:ref:`cd-play` allows you to play CD Audio
tracks.

:ref:`cd-eject` ejects a disk from the drive, or
allows you to insert a new disk.

