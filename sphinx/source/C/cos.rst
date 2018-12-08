..  _cos:

COS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  COS (radians)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function allows you to find the cosine of the specified angle
(given in radians).

In a right angled triangle the cosine is the ratio of the length of the
side adjoining the given angle, to the length of the hypotenuse (or the
sine of the complement of that angle). Thus, sine and cosine can
actually substitute each other:

+------------------------+----------------------+
| Mathematical formula   | In SuperBASIC        |
+========================+======================+
| cos x = sin (π/2-x)    | COS(x)=SIN(PI/2-x)   |
+------------------------+----------------------+
| sin x = cos (π/2-x)    | SIN(x)=COS(PI/2-x)   |
+------------------------+----------------------+

**Example**

An analogue clock:

::

    100 wx = 50: wy = INT(wx / 1.25): px = 50: py = 40
    110 OPEN#3,"scr_" & wx & "x" & wy & "a" & px & "x" & py
    120 PAPER#3,3: CLS#3: BORDER#3,1,0: SCALE#3,100,-45,-50
    130 INK#3,0: FILL#3,1: CIRCLE#3,0,0,40:FILL#3,0: INK#3,4
    135 Hs = PI/6
    140 FOR t = 1 TO 12
    150  LINE#3,40 * SIN(Hs * t), 40 * COS(Hs * t) TO 45 * SIN(Hs * t), 45 * COS(Hs * t)
    160 END FOR t
    170 INK #3, 7
    180 d$ = DATE$: min = d$(16 TO 17)
    190 hour = d$(13 TO 14) MOD 12 + min / 60
    200 LINE#3,0,0 TO 30 * SIN(Hs * hour), 30 * COS(Hs * hour)
    210 LINE#3,0,0 TO 40 * SIN(PI / 30 * min), 40 * COS(PI / 30 * min)
    220 PAUSE 100: CLOSE #3

**NOTE 1**

COS with very large values for the angle produces either very odd
results or an overflow error (except on Minerva v1.96+ where it returns
0). The correct range for radians is -PI...PI, because anything outside
this range is actually merely a repeat of the series. This is because an
angle of PI\*2 radians forms a complete circle, therefore an angle of
PI\*3 is actually the same as an angle of PI (ie. PI\*3-PI\*2). If you
insist on using these silly angles, try SIN (X+PI/2) instead of COS(X).

**NOTE 2**

The THOR XVI (v6.41) fixes a slight inaccuracy in this command to ensure
that COS(PI/2)=0. On other ROMs COS(PI/2)==0.

The Lightning package and SMS also fix this bug.

**CROSS-REFERENCE**

See :ref:`sin`, :ref:`acos`.

Compare :ref:`cosh`.

Please also see the Mathematics section of the Appendix.

