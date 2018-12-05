..  _abs-position:

ABS\_POSITION
=============

+----------+-------------------------------------------------------------------+
| Syntax   | ABS\_POSITION #channel, position                                  |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure will set the file pointer to the position given for the file attached to the given channel number. If you attempt to set the position for a screen or some other non-directory device channel, you will get a bad parameter error, as you will if position is negative.

If the position given is 0, the file will be positioned to the start, if the position is a large  number which is greater than the current file size, the position will be set to the end of file and no error will occur.

After an ABS\_POSITION command, all file accesses will take place at the new position.

**EXAMPLE**

::

    1500 REMark Set position to very end, for appending data
    1510 ABS_POSITION #3, 6e6
    1520 ...

**CROSS-REFERENCE**

:ref:`move-position`.

-------


