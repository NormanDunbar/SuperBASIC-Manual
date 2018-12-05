..  _where-fonts:

WHERE\_FONTS
============

+----------+-------------------------------------------------------------------+
| Syntax   | address = WHERE\_FONTS(#channel, 1\_or\_2)                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns a value that corresponds to the address of the fonts in use on the specified channel. The second parameter must be 1 for the first font address or 2 for the second, there are two fonts used on each channel. If the result is negative then it will be a normal QDOS error code. The channel must be a CON\_ or a SCR\_ channel to avoid errors.

**EXAMPLE**

The following example will report on the two fonts used in any given channel, and will display the character set defined in that font::

    4480 DEFine PROCedure REPORT_ON_FONTS (channel)
    4485   LOCal address, lowest, number, b
    4490   REMark show details of channel's fonts
    4495   CLS
    4500   FOR a = 1,2
    4505     address = WHERE_FONTS(#channel, a)
    4510     lowest = PEEK(address)
    4515     number = PEEK(address + 1)
    4520     PRINT '#'; channel; ' font '; a; ' at address '; address
    4525     PRINT 'Lowest character code = '; lowest
    4530     PRINT 'Number of characters  = '; number + 1
    4535     REMark print all but default characters
    4540     PRINT : REMark blank line
    4545     FOR b = lowest + 1 TO lowest + number :PRINT CHR$(b);
    4550     PRINT \\\ : REMark 2 blank lines
    4555   END FOR a
    4560 END DEFine REPORT_ON_FONTS

--------------


