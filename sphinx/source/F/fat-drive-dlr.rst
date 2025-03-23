..  _fat-drive-dlr:

FAT\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  FAT\_DRIVE$ (drive)                                              |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Q68                                                   |
+----------+-------------------------------------------------------------------+

This function returns a string containing the
card and partition for specified FAT drive.

If the specified drive has not been linked to any particular hard disk
partition, an empty string is returned.

**Example**

::

    FAT_DRIVE 1,1,2
    PRINT FAT_DRIVE$(1): REMark Will print Card: 1, Partition: 2

**Note 1**

By default the FAT driver may not be loaded in SMSQ/E

**CROSS-REFERENCE**

See :ref:`fat-drive`.

