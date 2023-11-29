..  _fat-wp:

FAT\_WP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  FAT\_WP drive, protect                                           |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Q68                                                   |
+----------+-------------------------------------------------------------------+

This command allows you to mark a specified FAT drive as read only
protect=1 will write protect the hard disk. protect=0 (the default) will
remove the write protection.

**Note 1**

By default the FAT driver may not be loaded in SMSQ/E

**CROSS-REFERENCE**

:ref:`dmedium-rdonly` will tell you if a
device is read only.
