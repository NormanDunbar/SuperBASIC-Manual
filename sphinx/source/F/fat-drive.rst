..  _fat-drive:

FAT\_DRIVE
==========

+----------+------------------------------------------------------------------+
| Syntax   | FAT\_DRIVE drive, card, partition                                |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                   |
+----------+------------------------------------------------------------------+

This command mounts a the primary FAT16 partition (1-4) on an SD card
(1-2) as FAT\_drive to simplify moving software into the Q68.

**Example**

::
   
   FAT 1,1,2

**Note 1**

Do not attempt to make two FAT drives point to the same partition!

**Note 2**

The partition must be a primary partition, formatted FAT16, and no
larger than 255 MB.

**Note 3**

Normally partition 1 is formatted FAT32 to allow it to contain WIN images.

**Note 4**

By default the FAT driver may not be loaded in SMSQ/E

**CROSS-REFERENCE**

:ref:`fat-drive-dlr` returns the parameters already associated with a
FAT drive.

