..  _dotlin:

DOTLIN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DOTLIN p1, p2, p3, col, x1, y1, x2, y2                           |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

The command DOTLIN is a variant of LDRAW - it draws a dotted line in
the specified colour col from the absolute co-ordinates (x1,y1) to
(x2,y2).

The three first parameters are small non-negative integers
which specify after how many pixels the line is to be broken (they are
known as the periods).

The line is drawn by plotting the first p1
pixels, then leaving a gap of p2 pixels, plotting the next p3 pixels and
once again leaving a gap of p2 pixels before recommencing the pattern.


**Examples**

::

    DOTLIN 10,10,10,3,40,40,200,60

draws a white line from the point (40,40) to the point (200,60) but
only for periods of ten pixels.

If a pixel is represented by an asterisk, this would look like this::

    **********          ********** ...
    |-- 10 --||-- 10 --||-- 10 --| ...


DOTLIN with the periods 3, 5 and 10::

    ***     **********     ***     **********
    |3||-5-||---10---||-5-||3||-5-||---10---|

**CROSS-REFERENCE**

All the warnings relevant to SET apply.

--------------


