..  _flp-drive:

FLP\_DRIVE
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FLP\_DRIVE drive%, drive$                                         |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This changes the drive/image the floppy device is connected to.

**Example**

::

    FLP_DRIVE 2,"C:\FLOPPY.IMG"

Now FLP2\_ is assigned to the floppy image FLOPPY.IMG on the host computer's C:\\ drive.

::

    FLP_DRIVE 2,"B:\"

FLP2\_ is assigned to the physical B:\\ floppy drive of the host computer.

