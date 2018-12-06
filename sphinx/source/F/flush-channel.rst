..  _flush-channel:

FLUSH\_CHANNEL
==============

+----------+-------------------------------------------------------------------+
| Syntax   | FLUSH\_CHANNEL #channel                                           |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure  makes sure that all data written to the given channel number has been 'flushed' out to the appropriate device. This means that if a power cut occurs, then no data will be lost.

**EXAMPLE**

::

    1000 DEFine PROCedure SaveSettings
    1010   OPEN_OVER #3, "flp1_settings.cfg"
    1020   FOR x = 1 to 100
    1030     PRINT #3, Setting$(x), Value$(x)
    1040   END FOR x
    1050   FLUSH_CHANNEL #3
    1060   CLOSE #3
    1070 END DEFine

