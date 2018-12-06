..  _file-backup:

FILE\_BACKUP
============

+----------+------------------------------------------------------------------+
| Syntax   | bk = FILE\_BACKUP(#channel)                                      |
+----------+------------------------------------------------------------------+
| Syntax   | bk = FILE\_BACKUP('filename')                                    |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function reads the backup date from the file header and returns it into the variable bk.  The parameter can either be a channel number for an open channel, or it can be the filename (in quotes) of a closed file.  If the returned value is negative, it is a normal QDOS error code.  If the value returned is positive, it can be  converted to a string be calling DATE$(bk). In normal use, a files backup date is never set by QDOS, however, users who have WinBack or a similar backup utility program will see proper backup dates if the file has been backed up.

**EXAMPLE**

::

    1000 bk = FILE_BACKUP('flp1_boot')
    1010 IF bk <> 0 THEN
    1020    PRINT "Flp1_boot was last backed up on " & DATE$(bk)
    1030 ELSE
    1040    PRINT "Flp1_boot doesn't appear to have been backed up yet."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-dataspace`, :ref:`file-length`, :ref:`file-type`, :ref:`file-update`.

