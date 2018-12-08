..  _resfast:

RESFAST
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESFAST (bytes)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT for QVME (v2.31+)                                    |
+----------+-------------------------------------------------------------------+

This function allows you to grab a specified number of bytes
in Atari TT FastRAM and is therefore akin to RESPR and ALCHP. However,
note that you can only use LBYTES to load data to this area or SBYTES /
SEXEC to save data if you are loading a file from or saving a file to a
RAM disk. You cannot use floppy disks or hard disks with this area of
memory.

**CROSS-REFERENCE**

See FAST_FREE and :ref:`respr`.

