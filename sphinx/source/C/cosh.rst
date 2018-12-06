..  _cosh:

COSH
====

+----------+-------------------------------------------------------------------+
| Syntax   |  COSH (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Hyper, Hyperbola                                                 |
+----------+-------------------------------------------------------------------+

This function is defined very similarly to SINH. It can be expressed as:

( EXP(x) + EXP(-x) ) / 2

**Example**

The COSH function can be used to describe a rope, chain or similar
object which has two ends tied at the same height to a ceiling (for
instance). Line 110 draws the ceiling, lines 120 to 160 the chain.

::

    100 a = .8: SCALE 10, -5, 0: CLS
    110 LINE -2,CHAIN(-2) TO 2,CHAIN(2)
    120 FOR x = -2 TO 2 STEP .1
    130   y = CHAIN(x)
    140   IF x > -2 THEN LINE _x, _y TO x, y
    150   _x = x: _y = y
    160 END FOR x
    170 :
    180 DEFine FuNction CHAIN(x)
    190  RETurn a * COSH(x/a)
    200 END DEFine CHAIN

**CROSS-REFERENCE**

See :ref:`sinh` for an example.

:ref:`arcosh` is the inverse function of
:ref:`cosh`.

