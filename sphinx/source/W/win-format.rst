..  _win-format:

WIN\_FORMAT
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_FORMAT drive [,protect]                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E (v2.73+) for Atari, Q68, and QXL / QPC                    |
+----------+-------------------------------------------------------------------+


In order to prevent you from accidentally formatting your hard disk (or
a partition of your hard disk) and overwriting important information,
SMSQ/E has implemented a form of protection. Before formatting a QDOS
partition, you will first of all need to create that partition using
either the Atari's or the PC's operating system (see the SMSQ/E
documentation for details). You must then use the WIN\_DRIVE command,
followed by WIN\_FORMAT to allow the FORMAT command to work on the hard disk.

Protect is a flag - if it is omitted, this removes the protection from the partition
pointed to by the specified WIN drive. protect=1 sets the protection
again after FORMATting.

**Example**

To format a QDOS partition called PROGS, pointed to by WIN2 on unit 1,
partition 1::

    WIN_DRIVE 2,1,1
    WIN_FORMAT 2
    FORMAT win2_PROGS
    WIN_FORMAT 2,1

**NOTE**

Earlier versions of SMSQ/E did not include this command and the FORMAT
command would work once WIN\_DRIVE had been used to set up the WIN drive
name.

**CROSS-REFERENCE**

See :ref:`format` and
:ref:`win-drive`.

