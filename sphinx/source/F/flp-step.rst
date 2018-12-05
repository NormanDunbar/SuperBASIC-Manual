..  _flp-step:

FLP\_STEP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_STEP [drive,] rate                                          |
+----------+-------------------------------------------------------------------+
| Location |  Disk Interfaces, Gold Cards, SMS, SMSQ/E for QPC                 |
+----------+-------------------------------------------------------------------+

The step rate enables the computer to known how quickly to step
across tracks on the disk surface. Normally, this is automatically set
to 3 milliseconds (ms) for 80 track disks and 6ms for 40 track disks,
although if the system detects repeated errors on reading the disk, it
will automatically slow the step rate.

Various old disk drives may
require a slower stepping speed (you will generally know this from the
noise the disk drive makes - it will make a repetitive knocking sound
each time that the disk is accessed). You can do this by increasing the
value specified by setting the rate using this command.

If drive is not
specified, the new step rate is taken to apply to all disk drives
connected to the system, otherwise, you can specify the number of the
drive to which the new step rate is to apply.

**Examples**

::

    FLP_STEP 12

Will produce quite a slow step rate for older drives.

::

    FLP_STEP 2,12

Will produce a step rate of 12ms for the drive in FLP2\_.

**NOTE 1**

The first, optional parameter may not be available on some interfaces.

**NOTE 2**

FLP\_STEP has no effect on the QXL, QPC or Atari implementations of SMSQ
and SMS.

**CROSS-REFERENCE**

:ref:`flp-sec` will alter the security setting
for reading and writing to a disk.
:ref:`flp-start` may also be needed on older
drives.

--------------


