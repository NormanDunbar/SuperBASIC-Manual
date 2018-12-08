..  _cot:

COT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  COT (angle)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the cotangent of a given angle (specified in
radians).

In a right angled triangle the cotangent of an angle is defined as the
ratio of the side adjoining the given angle to the side opposite to the
given angle (forming a right angle with the other line). Due to the
periodic nature of the function, it is best to work with angle in the
range: 0 < angle < PI.

COT(angle) can also be calculated as COS(angle)/SIN(angle).

**Example**

A program to create a graph showing the range of the function COT:

::

    100 MODE 4: OPEN#1,con_448x200a32x16
    110 SCALE 100,-75,-50
    120 INK 4: LINE -75,0 TO 125,0: LINE 0,-50 TO 0,50
    130 CURSOR 0,0,0,0: PRINT '0'
    140 CURSOR 0,0,-100,0: PRINT '-ã'
    150 CURSOR 0,0,100,0: PRINT 'ã'
    160 CURSOR 0,0,-200,0: PRINT '-ã * 2'
    170 CURSOR 0,0,200,0: PRINT '2ã'
    180 CURSOR 0,0,0,-100: PRINT '1'
    190 CURSOR 0,0,0,90: PRINT '-1'
    200 INK 7
    210 FOR ang=-(PI*2)+1E-2 TO PI*2 STEP 1E-2
    220   POINT ang*75/(PI*2),50*COT(ang)
    230 END FOR ang

**NOTE 1**

Although COT(PI) and COT(PI\*x) should be undefined (values of angle
very close to PI tend to infinity), on most QDOS implementations, it
gives a very large positive or negative number.

Currently, only the Lightning maths package and SMS produce an overflow
error (the correct result).

**NOTE 2**

On Minerva v1.96+ very large values of angle will return the value 0. On
other implementations produce an overflow error.

**NOTE 3**

COT(0) on most ROMs gives 1 - this is fixed on Minerva, SMS, Lightning,
QXL, and ST/QL which give an overflow error.

**NOTE 4**

COT(PI/2) should equal zero - on all implementations of this command,
this returns a number near to zero (except under SMS).

**CROSS-REFERENCE**

Please refer to\ :ref:`acot`,
:ref:`atan`, :ref:`tan`.

Compare :ref:`coth`.

Also refer to the Mathematics section of the Appendix.

