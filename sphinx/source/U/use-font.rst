..  _use-font:

USE\_FONT
=========

+----------+-------------------------------------------------------------------+
| Syntax   | USE_FONT #channel, font1\_address, font2\_address                 |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This is a procedure that will allow your programs to use a character set that is different from the standard QL fonts. The following example will suffice as a full description.

**EXAMPLE**

::

    1000 REMark Change the character set for channel #1
    1010 :
    1020 REMark Reserve space for the font file
    1030 size = FILE_LENGTH('flp1_font_file')
    1040 IF size < 0
    1050    PRINT 'Font file error ' & size
    1060    STOP
    1070 END IF
    1080 :
    1090 REMark Reserve space to load font into
    1200 font_address = RESERVE_HEAP(size)
    1210 IF font_address < 0
    1220    PRINT 'Heap error ' & font_address
    1230    STOP
    1240 END IF
    1250 :
    1260 REMark Load the font
    1270 LBYTES flp1_font_file, font_address
    1280 :
    1290 REMark Now use the new font
    1300 USE_FONT #1, font_address, 0

    .......Rest of program

    9000 REMark Reset channel #1 fonts
    9010 USE_FONT #1, 0, 0
    9020 :
    9030 REMark Release the storage space
    9040 RELEASE_HEAP font_address

