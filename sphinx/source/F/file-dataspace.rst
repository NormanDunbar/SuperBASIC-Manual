..  _file-dataspace:

FILE\_DATASPACE
===============

+----------+------------------------------------------------------------------+
| Syntax   | ds = FILE\_DATASPACE(#channel)  or                               |
|          |                                                                  |
|          | ds = FILE\_DATASPACE('filename')                                 |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function returns the current dataspace requirements for the file opened as #channel or for the file which has the name given, in quotes, as filename.  If the file is an EXEC'able file (See :ref:`file-type`) then the value returned will be the amount of dataspace that that program requires to run, if the file is not an EXEC'able file, the result is undefined, meaningless and probably zero.  If the result is negative, there has been an error and the QDOS error code has been returned.

**EXAMPLE**

::

    1000 ds = FILE_DATASPACE('flp1_WinBack_exe')
    1010 IF ds <= 0 THEN
    1020    PRINT "WinBack_exe doesn't appear to exist on flp1_, or is not executable."
    1030 ELSE
    1040    PRINT "WinBack_exe's dataspace is set to " & ds & " bytes."
    1050 END IF


**CROSS-REFERENCE**

:ref:`file-backup`, :ref:`file-length`, :ref:`file-type`, :ref:`file-update`.

