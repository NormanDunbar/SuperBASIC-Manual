..  _rtp-r:

RTP\_R
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RTP\_R (imag, real)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PTRRTP                                                           |
+----------+-------------------------------------------------------------------+

The function RTP\_R takes a given rectangular co-ordinate and returns
the so-called module (ie. the radius in polar co-ordinates). The result
of RTP\_R is always strictly positive and is not affected by the sign of
the imag and real parameters, because of the symmetries of a circle.

**Example 1**

Draw a rectangular pattern in green and the corresponding polar pattern
again displayed as rectangular co-ordinates in white::

    100 SCALE 10,-5,-5: PAPER 0: CLS
    110 FOR x = -3 TO 3 STEP .4
    120   FOR y = -3 TO 3 STEP 5E-2
    130     INK 4: POINT x, y
    140     INK 7: POINT RTP_R(x,y), RTP_T(x,y)
    150   END FOR y
    160 END FOR x

**Example 2**

The same as the above example but the polar co-ordinates are treated
even more unusually. If you correct the program and exchange a and b in
line 140 then the two patterns will match exactly - this reveals what
the RTP\_... functions are actually doing::

    100 SCALE 10,-5,-5: PAPER 0: CLS
    110   FOR x = -3 TO 3 STEP .4
    120   FOR y = -3 TO 3 STEP 2E-2
    130     INK 4: POINT x, y
    140     a = RTP_R(x,y): b = RTP_T(x,y)
    145     INK 7: POINT b * COS(a), b * SIN(a)
    150   END FOR y
    160 END FOR x

**CROSS-REFERENCE**

Polar co-ordinates also need an angle, this is calculated with :ref:`rtp-t`.
The :ref:`ptr-x` and :ref:`ptr-y` pair of functions are complementary to
:ref:`rtp-r` and :ref:`rtp-t`\ .

