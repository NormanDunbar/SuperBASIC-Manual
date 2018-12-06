..  _file-length:

FILE\_LENGTH
============

+----------+------------------------------------------------------------------+
| Syntax   | fl = FILE\_LENGTH(#channel)                                      |
|          |                                                                  |
|          | fl = FILE\_LENGTH('filename')                                    |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

The file length is returned. The file may be open, in which case simply supply the channel number, or closed, supply the filename in quotes. If the returned value is negative, then it is a QDOS error code.

**EXAMPLE**

::

    1000 fl = FILE_LENGTH('flp1_WinBack_exe')
    1010 IF fl <= 0 THEN
    1020    PRINT "Error checking FILE_LENGTH: " & fl
    1030 ELSE
    1040    PRINT "WinBack_exe's file size is " & fl & " bytes."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-backup`, :ref:`file-dataspace`, :ref:`file-type`, :ref:`file-update`.

