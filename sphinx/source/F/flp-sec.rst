..  _flp-sec:

FLP\_SEC
========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_SEC level                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, Trump Card, SMS, THORs, SMSQ/E for QPC               |
+----------+-------------------------------------------------------------------+

The Gold Card, Trump Card and Thor range of computers, together with
SMS provide a high standard of disk security, meaning that they are
unlikely to fail to notice when a disk has been swapped over, and
thereby try to write a file across two disks!

However, this level of
security does affect the speed of disk access, as the system must check
to see if the disk has been altered each time that it is written to.

The command FLP\_SEC allows you to choose between three levels of security,
the lowest of which (level 0) is still at least as secure as many other
disk operating systems (such as MSDOS). The lower the level of security,
the quicker disk access will be. The levels of security are as follows:-

Security Level 0
    The disk system will only check to see if the disk has changed if a file
    is opened and the disk has stopped (ie. the disk light will have gone
    out) since the last time it was checked. The disk map is only updated
    when a file is closed (or flushed) and no other disk access has happened
    within half a second. Confusion can be expected on both read and write
    operations whenever a disk is changed whilst the disk light is still on
    or there are files open to the disk.

Security Level 1
    The disk is checked each time that a file is opened, data is written to
    the disk, or the disk map is to be written; provided that the disk has
    stopped since the last time it was checked. The disk map is only updated
    when a file is closed (or flushed) and no other disk access has happened
    within half a second. The disk is not checked when anything is read from
    the disk, which can lead to confusion if a disk is changed whilst there
    are files still open.

Security Level 2
    The disk is checked whenever a file is opened, data is written to or
    read from the disk, or the map is to be read or written to; provided
    that the disk has stopped since the last time that it was checked. The
    disk map and directory are updated and the slave buffers flushed every
    time that a file is closed (or flushed).

**SMS NOTE**

FLP\_SEC has no effect - the security level is fixed at 2, the most
secure.

**SMSQ/E for QPC NOTE**

FLP\_SEC has no effect - the security level is fixed at 2, the most
secure.

