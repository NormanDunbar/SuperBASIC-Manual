..  _atn2:

ATN2
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ATN2 (x,y)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

ATN2 calculates ATAN(x/y) but expands the result from 0...PI to -PI...PI
which allows you to convert cartesian and polar co-ordinates in both
directions without loss of information.

**Example**

Run this graphics demonstration and you will understand the advantage of
ATN2 and the difference from ATAN:

::

    100 WTV 4: SCALE 4,-3,-2: INK 7
    110 PAPER 0: OVER -1: CLS
    120 radius=1.5: reso=128
    130 FOR angle0=PI/reso TO 2*PI STEP PI/reso
    140   x0=radius*COS(angle0): y0=radius*SIN(angle0)
    150   angle1 = ATAN(y0/x0)
    160   x1=radius*COS(angle1): y1=radius*SIN(angle1)
    170   angle2 = ATN2(x0,y0)
    180   x2=radius*COS(angle2): y2=radius*SIN(angle2)
    190   ARRAYS: PAUSE 2: ARRAYS
    200 END FOR angle0
    210 :
    220 DEFine PROCedure ARRAYS
    230  INK 3
    240  FILL 1: CIRCLE 1.25*x0,1.25*y0,5E-2: FILL 0
    250  IF x1==x2 AND y1==y2 THEN
    260    INK 7: LINE x1/5,y1/5 TO x1,y1: INK 5
    270    CURSOR x1,y1,0,0: PRINT "ATAN/ATN2"
    280  ELSE
    290    INK 7: LINE x1/5,y1/5 TO x1,y1: INK 5
    300    CURSOR x1,y1,0,0: PRINT "ATAN"
    310    INK 7: LINE x2/5,y2/5 TO x2,y2: INK 5
    320    CURSOR x2,y2,0,0: PRINT "ATN2"
    330  END IF
    340  angle=INT(DEG(angle0))
    350  CURSOR 0,0,-3*LEN(angle),-5: PRINT angle
    360 END DEFine ARRAYS

**CROSS-REFERENCE**

:ref:`atan` which is the same on Minerva and SMS.

