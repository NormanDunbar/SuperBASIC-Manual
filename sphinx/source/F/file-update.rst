..  _file-update:

FILE\_UPDATE
============

+----------+------------------------------------------------------------------+
| Syntax   | fu = FILE\_UPDATE(#channel)                                      |
|          |                                                                  |
|          | fu = FILE\_UPDATE('filename')                                    |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function  returns the date that the appropriate  file was last updated, either by printing to it, saving it or editing it using an editor etc.  This date is set in all known QLs and emulators etc.

**EXAMPLE**

::

    1000 fu = FILE_UPDATE('flp1_boot')
    1010 IF fu <> 0 THEN
    1020    PRINT "Flp1_boot was last written/saved/updated on " & DATE$(fu)
    1030 ELSE
    1040    PRINT "Cannot read lates UPDATE date from flp1_boot. Error: " & fu & "."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-dataspace`, :ref:`file-length`, :ref:`file-type`, :ref:`file-type`.

