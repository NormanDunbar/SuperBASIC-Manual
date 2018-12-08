..  _eps:

EPS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EPS [(x)]                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

Since the precision of the QL is limited, a number may not change if a very small
value is added. The function EPS(x)  returns the smallest value which can be added
to x so that the sum of x and EPS(x) will be different from x. This only makes
sense for floating point numbers. The default parameter is 0. EPS(x) attains its
smallest value at x=0, so EPS(0) returns the smallest absolute number which can
be handled by SuperBASIC. EPS(x) is always greater than zero and EPS(x)=EPS(-x).

**Example**

An approximation of PI/4 as proposed by Leibniz::

    100 x = 0: d = 1
    110 t0 = DATE
    120 FOR i=1 TO 1E100
    130   IF ABS(1/d) < EPS(x) THEN EXIT i
    140   x = x + 1/d
    150   d = - SGN(d) \* (ABS(d)+2)
    160 END FOR i
    170 t = DATE - t0
    180 PRINT "Iterations ="!i!" Runtime ="!t;"s"
    190 PRINT "Iterations per Second ="!i/t
    200 PRINT "PI ="!4\*x!"(";PI;")"

Unfortunately, the algorithm is not efficient enough to compete with
the QL's precision, so that about 2E9 iterations are necessary to get a
suitable result. Since this will take a while (ages!), you can reduce
precision by a factor of one million, by modifying line 130::

    130 IF ABS(1/d) < 1E6 * EPS(x) THEN EXIT i

The program will then finish after 1075 iterations with 4\*x =
3.140662, not bad compared to 3.141593 when taking the drastic reduction
of precision into account.

**NOTE**

EPS does not recognise the higher precision used by Minerva. Minerva's
higher precision may have an effect on fractals and similar esoteric
calculations.

