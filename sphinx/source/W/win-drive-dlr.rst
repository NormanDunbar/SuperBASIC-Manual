..  _win-drive-dlr:

WIN\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_DRIVE$ (drive)                                              |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Atari, Q68, and QXL / QPC                             |
+----------+-------------------------------------------------------------------+

On SMSQ/E for the Atari, this function returns a string containing the
unit, disk and partition numbers addressed by the specified WIN drive.

Under SMSQ/E for the QXL and QPC (v2.89+), this function will return a
string indicating the file on the PC which is used as that hard drive.

If the specified drive has not been linked to any particular hard disk
partition, an empty string is returned.

**Atari Examples**

::

    WIN_DRIVE 2,0,1,0
    PRINT WIN_DRIVE$(2): REMark Will print 0,1,0

**Q68 Examples**

::

   WIN_DRIVE 2,1,"drive.win"
   PRINT WIN_DRITE$(2): REMark will print DRIVE.WIN,1
   
**QXL / QPC Examples**

::

    WIN_DRIVE 2,'C:\qxlback.win'
    PRINT WIN_DRIVE$(2): REMark will print C:\qxlback.win

**CROSS-REFERENCE**

See :ref:`win-drive`.

