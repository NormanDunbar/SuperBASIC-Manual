..  _win-stop:

WIN\_STOP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_STOP driveno                                                |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for Atari and QPC / QXL                            |
+----------+-------------------------------------------------------------------+

If you are going to move a computer around, or swap over a changeable
hard disk drive, it is *essential* that you make sure that the head on the
hard disk drive is parked. This basically means that the drive locks the
head away and ensures that it cannot be banged onto the surface of the
hard disk drive.

Some hard disk interfaces (such as the Miracle Hard
Disk system for the QL) automatically park the head if the drive has not
been accessed for a while. However, on other systems, it is necessary to
do this explicitly. WIN\_STOP tells the hard disk in the specified drive
to park its head. driveno must be in the range 1...8.

**Example**

::

    WIN_STOP 2

will park the head in win2\_.

**WARNING 1**

Never move a hard disk about unless its head is parked as this can cause
permanent damage to the drive.

**WARNING 2**

Some hard disk drives require that you park the head before
disconnecting the power to the drive. Refer to the instructions for the
hard disk which you are using.

**WARNING 3**

You may find that some drives will refuse to respond to access calls if
stopped accidentally, or when using this command. If WIN\_START does not
revive them, then unfortunately the only thing to do is to reset the
system (switching the power back and back on).

**CROSS-REFERENCE**

:ref:`win-start` releases the head so that the
drive can be used again.

