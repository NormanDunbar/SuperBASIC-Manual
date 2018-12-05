..  _pi:

PI
==

+----------+-------------------------------------------------------------------+
| Syntax   |  PI                                                               |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function is a constant number which returns the value of Pi with an
error of 10^(-29). You can test the precision of PI with such a program::

    100 p = PI - 3: PRINT "PI = 3.";
    110 FOR n = 1 TO 35
    120   p = p * 10
    130   PRINT INT(p);
    140   p = p - INT(p)
    150 END FOR n
    160 PRINT

**CROSS-REFERENCE**

The trigonometrical functions (:ref:`sin`,
:ref:`tan`, :ref:`acos` etc) expect
parameters in radians, so :ref:`pi` must be used in
most cases. Another fundamental mathematical constant, e, can be
obtained with :ref:`exp`\ (1).

--------------


