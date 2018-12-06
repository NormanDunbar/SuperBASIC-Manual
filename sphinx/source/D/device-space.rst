..  _device-space:

DEVICE\_SPACE
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVICE\_SPACE ([#]channel)                                       |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns the number of unused bytes on the medium (disk,
hard disk or microdrive) to which the specified channel is open. The
channel must relate to an open file on a directory device (otherwise
junk figures may be returned).


**Example**

A short routine which saves an area of memory to disk, with error
checking.

::

    100 OPEN #3,'CON_448X200A32X16'
    110 CLS #3
    120 FILE$='FLP1_MEMORY_BIN'
    130 FILE_SIZE=20000: ADDR=ALCHP(FILE_SIZE)
    140 REPEAT LOOP
    150   INPUT #3,'ENTER FILENAME TO SAVE MEMORY TO : [DEFAULT=';(FILE$);']';F$
    160   IF F$='': F$=FILE$: ELSE FILE$=F$
    170   OPEN_STATE=DEVICE_STATUS(2,FILE$)
    180   IF OPEN_STATE=-20: PRINT #3,'DEVICE IS READ ONLY': NEXT LOOP
    190   IF OPEN_STATE=-11: PRINT #3,'DEVICE IS FULL': NEXT LOOP
    200   IF OPEN_STATE=-8
    210     INPUT #3,'DO YOU WANT TO DELETE EXISTING FILE ? (Y/N)';A$
    220     IF A$=='Y'
    230       CH=FOP_IN(FILE$)
    240     ELSE
    250       PRINT #3;'ENTER NEW FILENAME': PAUSE 100
    260       NEXT LOOP
    270     END IF
    275   ELSE
    277     CH=FOP_NEW(FILE$)
    280   END IF
    300   IF CH<0:REPORT #3: NEXT LOOP
    305   FREE_SPACE=DEVICE_SPACE(#CH)
    307   IF OPEN_STATE=-8: FREE_SPACE=FREE_SPACE+FLEN(#CH)
    310   IF FREE_SPACE>=FILE_SIZE: PRINT#3,'SAVING FILE': EXIT LOOP
    320   PRINT #3;'NOT ENOUGH ROOM ON DEVICE'
    330   CLOSE #CH
    335   IF OPEN_STATE<>-8: DELETE FILE$
    340 END REPEAT LOOP
    350 CLOSE #CH
    355 DELETE FILE$
    360 SBYTES FILE$,ADDR,FILE_SIZE


**NOTE**

Current versions of this fuction have difficulty returning the amount of
space on large capacity drives, such as hard disks. It assumes that a
sector contains 512 bytes and will only cope with a maximum of 65535
sectors.


**CROSS-REFERENCE**

See :ref:`fopen` and
:ref:`device-status` for more details on
accessing directory devices. :ref:`devtype`
finds out what type of device a channel is looking at.

