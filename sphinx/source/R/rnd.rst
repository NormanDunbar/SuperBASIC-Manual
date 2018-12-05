..  _rnd:

RND
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RND [([min TO] max)]                                             |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function produces a (pseudo) random number. When used without
parameters it returns a floating point number between 0 and 1, otherwise
an integer number lying between the two parameters (including the
parameters) will be returned.

+-------------------+------------------------------+
| Expression        | Results                      |
+===================+==============================+
| x=RND             | 0 < x < 1                    |
+-------------------+------------------------------+
| x=RND(max)        | 0, 1, 2, 3, ..., max         |
| where max >= 0    |                              |
+-------------------+------------------------------+
| x=RND(min TO max) | min, min+1, ..., max-1, max  |
| where max >= min  |                              |
+-------------------+------------------------------+

**Example**

::

    100 CLS: PRINT "RND Statistics"
    110 n = 1000: m = 10: DIM h%(m)
    120 FOR i=1 TO n
    130   k = RND(1 TO m)
    140   h%(k) = h%(k )+ 1
    150   AT 2,5: PRINT i
    160 END FOR i
    170 PRINT: avdiff = 0
    180 FOR k = 1 TO m
    190   diff = n / m - h%(k)
    200   PRINT k; TO 6; h%(k); TO 12; INT(diff)
    210   avdiff = avdiff + ABS(diff / n * m)
    220 END FOR k
    230 PRINT\"average difference:" ! INT(100 * avdiff / m);"%"

**NOTE**

If a range is specified {eg. RND(x TO y)} the second number must not be
less than the first (ie. y>=x). If only one parameter is specified, this
is taken to be the top of the range, with the bottom of the range being
0. Therefore, if only one parameter is specified, this must not be
negative.

**CROSS-REFERENCE**

The results of :ref:`rnd` can be influenced with
:ref:`randomise`. See also
:ref:`matrnd`.

--------------


