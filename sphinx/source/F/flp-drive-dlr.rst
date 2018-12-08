..  _flp-drive-dlr:

FLP\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   | drive$ = FLP\_DRIVE$(drive%)                                      |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This reads back the current connection of the floppy device.

**Example**

::

    PRINT FLP_DRIVE$(2)

will tell you the current setting for flp2\_.

