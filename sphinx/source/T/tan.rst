..  _tan:

TAN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TAN (angle) angle <> (2n+1) \* PI/2 (n=0,1,2,...)                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function calculates the tangent of an angle given in radians. The
solution of TAN(PI/2) is not actually defined because the definition of
TAN is TAN(x)=SIN(x)/COS(x) and COS(PI/2)=0. In practice, most ROM
implementations will return a value of about 1E10 instead of an error
because they calculate COS(PI/2)<>0. Due to the periodic nature of this
function function, values for angle should really be in the range -PI/2
< angle < PI/2.

**Example**

::

    100 WINDOW 448,200,32,16: PAPER 3: CLS
    110 SCALE 8,-.2,-.2: INK 7
    120 INPUT "Angle (0..90):"!angle
    130 INPUT "Speed (..11 m/s):"!speed
    140 angle=RAD(angle): c1=TAN(angle)
    150 c2=9.81 / 2 / speed^2 / COS(angle)^2
    160 :
    170 FOR x=0 TO c1/c2 STEP c1/c2/20
    180   y=c1 * x - c2 * x^2
    190   FILL 1: CIRCLE x,y,.2: FILL 0
    200 END FOR x

**NOTE 1**

TAN(PI)==0 on all implementations - this should be zero. Only SMS
currently corrects this.

**NOTE 2**

On Minerva v1.96+ large values of angle return 0. On other ROMs it
produces an overflow error.

**CROSS-REFERENCE**

:ref:`sin`, :ref:`cos`,
:ref:`cot`, :ref:`asin`,
:ref:`acos`, :ref:`atan` and
:ref:`acot` are other common trigonometrical
functions. :ref:`rad` converts degrees into radians,
:ref:`deg` vice-versa. Please also refer to the
Mathematics section of the Appendix.

--------------


