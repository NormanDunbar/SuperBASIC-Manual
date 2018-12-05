..  _file-type:

FILE\_TYPE
==========

+----------+------------------------------------------------------------------+
| Syntax   | ft = FILE\_TYPE(#channel)                                        |
|          |                                                                  |
|          | ft = FILE\_TYPE('filename')                                      |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function returns the files type byte. The various types currently known to me are :

- 0 = BASIC, CALL'able machine code, an extensions file or a DATA file.
- 1 = EXEC'able file.
- 2 = SROFF file used by linkers etc, a C68 Library file etc.
- 3 = THOR hard disc directory file. (I think!)
- 4 = A font file in The Painter
- 5 = A pattern file in The Painter
- 6 = A compressed MODE 4 screen in The Painter
- 11 = A compressed MODE 8 screen in The Painter
- 255 = Level 2 driver directory or sub-directory file, Miracle hard disc directory file.

There *may* be others.

**EXAMPLE**

::

    1000 ft = FILE_TYPE('flp1_boot')
    1010 IF ft <= 0 THEN
    1020    PRINT "Error checking FILE_TYPE: " & ft
    1030 ELSE
    1040    PRINT "Flp1_boot's file type is " & ft & "."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-backup`, :ref:`file-dataspace`, :ref:`file-length`, :ref:`file-update`.


-------



