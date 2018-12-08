..  _rad:

RAD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RAD (angle)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function is used to convert an angle in degrees into an angle in
radians (which is the system used by QDOS to represent angles in
commands such as SIN, COS, TAN, etc.). Although this will work for any
value of angle, due to the very nature of angles, angle should be in the
range 0..360, which will return a value in the range 0..2Pi.

**Example**

A small program to draw a circle split into 30 degree segments::

    100 MODE 4:WINDOW 448,200,32,16:SCALE 100,0,0
    110 STRIP 2:INK 7
    120 x1=75:y1=50:x2=x1:y2=y1+25
    130 CIRCLE x1,y1,25
    140 FOR x=0 TO 360/30-1
    150   x2=x1+SIN(RAD(30)*x)*25:y2=y1+COS(RAD(30)*x)*25
    160   LINE x1,y1 TO x2,y2
    170 END FOR x

**CROSS-REFERENCE**

See :ref:`deg`, :ref:`sin`,
:ref:`cos`. Also please refer to the Mathematics
section of the Appendix.

