..  _win-remv:

WIN\_REMV
=========

+----------+------------------------------------------------------------------+
| Syntax   | WIN\_REMV driveno, flag (SMSQ/E & ST/QL Level C-24+)  or         |
+----------+------------------------------------------------------------------+
| Syntax   | WIN\_REMV driveno                                                |
+----------+------------------------------------------------------------------+
| Location | ST/QL (Level C-20+), SMSQ/E for Atari, QXL / QPC                 |
+----------+------------------------------------------------------------------+

The advent of changeable hard disk drives caused a lot of problems,
since it is just about feasible that you might try to remove the hard
disk unit whilst it is being accessed, which can cause serious damage to
the drive unit. Although the drives attempt to warn the computer when
they are and are not removable, it is next to impossible to ensure that
when the drive says it can be removed, it is not actually powering up or
down.

The command WIN\_REMV tells the system that the drive connected to
the specified port is a removable hard disk drive - the door on the
unit will then remain firmly locked as long as any files on the hard
disk are open.

Note that driveno must be in the range 1...8. SMSQ/E
allows the first variant - flag can be omitted which is equivalent to 1
(signifies a removable hard disk). It can also be one of the following
values:

- 0: Clear the removable flag from the drive
- V: Mark the drive as being a VORTEX drive

**Example**

::

    WIN_REMV 2

denotes win2\_ as a removable disk drive.

**NOTE**

It is essential that WIN\_REMV is used as early as possible - either
before the drive is first accessed or as the first line of your boot
program if the Emulator is being booted from the hard disk in question.

**SMSQ/E NOTE**

SMSQ/E manages to detect removable hard disks 100% on SCSI ports. It is
also normally successful in detecting removable hard disks connected to
ASCI ports unless you configure it to ignore them, therefore this
command is only really needed on ASCI drives.

**QPC NOTE**

You need v1.43+ of QPC to use removable drives.

**WARNING**

Never try to remove a hard disk (removable or otherwise!) whilst it is
running.

**CROSS-REFERENCE**

:ref:`win-stop` will park the head on the drive
prior to removal. :ref:`dmedium-remove`
can tell you if the given device is a removable hard disk.

--------------


