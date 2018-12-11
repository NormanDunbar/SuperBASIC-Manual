..  _win-drive:

WIN\_DRIVE
==========

+----------+------------------------------------------------------------------+
| Syntax   | WIN\_DRIVE driveno [, unit, disk] or                             |
|          |                                                                  |
|          | WIN\_DRIVE driveno, unit [,disk] [,partition ](SMSQ/E only)  or  |
|          |                                                                  |
|          | WIN\_DRIVE driveno, path$(QPC & QXL SMSQ/E only)                 |
+----------+------------------------------------------------------------------+
| Location | ST/QL, SMSQ/E for Atari and QXL / QPC                            |
+----------+------------------------------------------------------------------+

It is possible not only to have several hard disk units attached to the
Atari ST, but each hard disk unit can also have more than one drive in
it (for example, you might own a hard disk unit which has both a
standard hard disk and a changeable hard disk inside).

The normal chain
of events is that each WIN drive would attach itself to the equivalent
hard disk unit, for example, WIN1\_ would be connected to hard disk unit
0, WIN2\_ to hard disk unit 1 and so on. However, so that you may link
the WIN drives to specific disks within each unit, the WIN\_DRIVE
command exists.

WIN\_DRIVE takes the WIN drive number supplied by
driveno and will attach this to the specified disk which is housed in
the specified unit.

Driveno must be in the range 1...8 - this
corresponds to the number which will be attached to WIN to refer to the
relevant drive (eg. WIN4\_). If a unit and disk are not specified, this
command will remove the definition attached to the specified driveno.

Unit should be in the range 0...7 and represents the number of the disk
drive controller. An internal disk drive controller is normally unit 0,
but external controller unit numbers will depend upon the setting of the
switches on the back of the box.

If you are running SMSQ/E on the TT and
wish to access a SCSI disk controller, then you will need to add 8 to
the value of unit.

Disk can be in the range 0...7 and represents the
number of the disk drive actually addressed by the given controller. It
is however rare in the Atari world to have more than one disk drive per
controller and so this value is normally either 0 or 1. The default is
0.

Finally, each disk can be partitioned, so that an area of each disk
is set aside for specific uses (eg. for QDOS or for GEM). You therefore
need to specify the number of the partition. Default is 0. Although you
can configure SMSQ/E to start from a specific drive and partition, it
normally looks for a BOOT file in any partition on unit 0 (on the TT it
will look at SCSI unit 0 and then ASCI unit 0). If found, WIN1\_ will be
set to this partition.

In current versions of SMSQ/E WIN2\_ will not be
linked to anything until you use the WIN\_DRIVE command.

**Example**

Assume that you have two hard disk units plugged into the Atari ST,
the first one of which (unit 0) contains a normal hard disk unit (disk
0) and a changeable hard disk unit (disk 1).

On starting the Emulator,
WIN1\_ would refer to the normal hard disk in unit 0 and WIN2\_ would be
undefined. You could not therefore access the changeable hard disk from
the Emulator. To avoid this, use the commands::

    WIN_DRIVE 2,0,1,0
    WIN_DRIVE 3,1,0,2

This will link WIN2\_ to the changeable hard disk (this is disk number
1 in unit 0, partition 0) and WIN3\_ would then point to the hard disk
in the second unit (disk 0 in unit 1, partition 2).

**NOTE**

Disk must be specified unless it is 0. - this means that if three
parameters are specified, the third parameter is taken to be the
partition number.

**QPC / QXL NOTE**

From v2.89 of SMSQ/E, WIN\_DRIVE is implemented slightly differently on
these emulators. For each driveno, you can specify a PC related path for
the hard disk (the hard disk under QPC and QXL is implemented as a
single file stored on the PC's hard disks). For example, use::

    WIN_DRIVE 2,'D:\qxl.win'

to make win2\_ on the QL emulator look use the file qxl.win on the PC's
D: drive. In this way, CD-ROMs and DVD-RAMs can be used on the PC as a
hard drive for the QL emulator. Although QPC allows you to have several
QL hard disk files on each PC device, QXL only allows one qxl.win file
per PC device!!

**WARNING 1**

You must not make the QDOS WIN drive point to another physical drive if
that WIN device has been accessed already. For example, if you wanted to
follow the above example, but had just loaded a program from WIN2\_ you
*must not* use::

    WIN_DRIVE 2,0,1.

**WARNING 2**

Do not attempt to make two WIN drives point to the same physical drive!

**CROSS-REFERENCE**

:ref:`win-drive-dlr` returns the parameters
already associated with a WIN drive.
:ref:`win-format` allows you to format a hard
disk.

