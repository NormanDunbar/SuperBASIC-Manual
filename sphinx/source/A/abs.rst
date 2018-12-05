..  _abs:

ABS
===

+----------+------------------------------------------------------------------------+
| Syntax   | ABS (number) or                                                        |
|          |                                                                        |
|          | ABS (number1 :sup:`\*`\ [,number\ :sup:`x`]\ :sup:`\*`) (Minerva only) |
+----------+------------------------------------------------------------------------+
| Location | QL ROM                                                                 |
+----------+------------------------------------------------------------------------+

This function returns the absolute value of a number - ie. the positive
difference (or distance) between zero and the number. The absolute value
of a positive number (including zero) therefore, is the number itself -
negative numbers are converted to positive. This function will happily
handle 32-bit integer numbers (-INTMAX..INTMAX, roughly -1E9..1E9).

**Example 1**

The SIGN% function returns 1 if the supplied parameter is positive, -1
if negative, or 0 if it is zero, for example,

PRINT SIGN%(-10) will print -1 on screen.

This version rounds values which are very close to zero (use = in line
110 instead of == if you want to avoid this).

Note that line 110 is needed to avoid an error when line 120 tries to
divide by zero.

::

    100 DEFine FuNction SIGN% (number)
    110  IF number==0 THEN RETurn 0
    120  RETurn number/ABS(number)
    130 END DEFine

**Example 2**

Here is a simple implementation of the cosine function. Of course, it
cannot compete with the speed of a machine code function, but it allows
you to specify the precision of the result. You can optimise the
function by exploiting the symmetries of the cosine function.

::

    100 DEFine FuNction MYCOS (x, prec)
    110  LOCal fct, result, xpower, i, lagrange, sqrx
    120  fct = 1: result = 1
    130  xpower = 1: sqrx = x*x
    140  i = 2
    150  REPeat taylor
    160    fct = fct * (i-1) * i
    170    xpower = - xpower * sqrx
    180    result = result + xpower/fct
    190    lagrange = ABS(xpower*x / fct / (i+1))
    200    IF lagrange < prec THEN EXIT taylor
    210    i = i + 2
    220  END REPeat taylor
    230  RETurn result
    240 END DEFine MYCOS

**MINERVA NOTE**

ABS can accept more than one parameter. This version of ABS will square
each parameter, and return the square root of the total of those
squares, eg. ABS(x,y)=SQRT(x2+y2). This is therefore useful to calculate
the distance between two points (using pythagoras' method).

For example, to calculate the distance between the points on screen at
(10,20) and (100,75), simply type in: PRINT ABS(100-10,75-20)

Three parameters can be used to find the distance between two points in
three dimensional space. Any more parameters take you into the realm of
theoretical mathematics (we always thought that time was the fourth
dimension!).

For example, to calculate the length of a diagonal in a standard cube
(length of sides = 1), use: PRINT ABS(1,1,1)

**CROSS-REFERENCE**

See :ref:`sgn` and :ref:`sgn-pct` for
similar machine code versions of our example function SIGN% demonstrated above.

--------------


