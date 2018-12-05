..  _file-position:

FILE\_POSITION
==============

+----------+-------------------------------------------------------------------+
| Syntax   | where = FILE\_POSITION(#channel)                                  |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function will tell you exactly where you are in the file that has been opened, to a directory device, as #channel, if the result returned is negative it is a QDOS error code.  If the file has just been opened, the result will be zero, if the file is at the very end, the result will be the same as calling FILE\_LENGTH(#channel) - 1, files start at byte zero remember.

**EXAMPLE**

::

    1500 DEFine FuNction OPEN_APPEND(f$)
    1510   LOCal ch, fp
    1515   :
    1520   REMark Open a file at the end, ready for additional
    1530   REMark data to be appended.
    1540   REMark Returns the channel number. (Or error)
    1545   :
    1550   ch = DJ_OPEN(f$)
    1560   IF ch < 0 THEN
    1570      PRINT "Error: " & ch & " Opening file: " & f$
    1580      RETurn ch
    1590   END IF
    1595   :
    1600   MOVE_POSITION #ch, 6e6
    1610   fp = FILE_POSITION(#ch)
    1620   IF fp < 0 THEN
    1630      PRINT "Error: " & fp & " reading file position on: " & f$
    1640      CLOSE #ch
    1650      RETurn fp
    1660   END IF
    1665   :
    1670   PRINT "File position set to EOF at: " & fp & " on file: " &f$
    1680   RETurn ch
    1690 END DEFine

**CROSS-REFERENCE**

:ref:`abs-position`, :ref:`move-position`.


-------


