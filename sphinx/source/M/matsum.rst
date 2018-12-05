..  _matsum:

MATSUM
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATSUM (array[%])                                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function calculates the sum of all of the elements of the supplied
array. array can be any floating point or integer array, but not a
string array. The latter leads to error -15 (bad parameter). Array can
be any number of dimensions, although the following example uses just
one dimension for demonstration reasons.

**Example**

If you stored a lot of values, eg. temperatures, in an array and want to
find the average temperature, you have to divide the sum of the
temperatures by the number of values. Obviously the operation of adding
temperatures can take quite some time for a large data base, so this is
a point where MATSUM helps::

    100 values% = 200: DIM temp%(values%)
    110 :
    120 PRINT#0,"random initialisation..."
    130 MATRND temp%,-20,30
    140 PRINT#0,"equalising";
    150 FOR equalize = 1 TO 10
    160   FOR i = 0 TO values%-1
    170     temp%(i) = ( temp%(i) + temp%(i+1) ) / 2
    180   END FOR i
    190   PRINT#0,".";
    200 END FOR equalize
    210 :
    220 PRINT#0\\"drawing..."
    230 WINDOW 448,200,32,16: SCALE 100,0,0
    240 PAPER 3: CLS: INK 7: OVER 0
    250 dist = 160 / values%: yoff = 50
    260 FOR i = 0 TO values%-1
    270   x1 = i*dist: x2 = x1+dist
    280   y1 = temp%(i) + yoff: y2 = temp%(i+1) + yoff
    290   LINE x1,y1 TO x2,y2
    300 END FOR i
    310 :
    320 PRINT#0,"find medium..."
    330 tmed = MATSUM(temp%) / values%
    340 INK 3: OVER -1
    350 LINE 0,tmed+yoff TO x2,tmed+yoff

The important line is 330 where MATSUM is used. Lines 150 to 200
transform the random values to more realistic temperatures: you won't
find any country where outside temperature jumps from -20 to +30 degrees
Celsius in one day! The number of equalize loops can be freely chosen.

This is also true for values%, the figure adapts itself to the number of
values (see dist in line 250).

**NOTE**

A program using MATSUM cannot be compiled with Turbo or Super-charge.

**CROSS-REFERENCE**

:ref:`matrnd` initialises an array with random
values. :ref:`matprod` is very similar to
:ref:`matsum` except that it finds the product of
an array's elements. :ref:`matmean` finds the mean
value of a matrix's values directly, so line 330 could be replaced with::

    330 tmed = MATMEAN(temp%)

--------------


