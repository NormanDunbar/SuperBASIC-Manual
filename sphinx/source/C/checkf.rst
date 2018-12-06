..  _checkf:

CHECKF
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHECKF (float$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                      |
+----------+-------------------------------------------------------------------+

Just like CHECK%, the function CHECKF takes the specified string and
coerces it to a number. This time, however, the number returned will be
a floating point rather than an integer as returned by CHECK%.

CHECKF works just like CHECK% except that a return value of -1E600
signifies unacceptable strings.

**CROSS-REFERENCE**

:ref:`check-pct` and :ref:`ttefp`
are worth a look.

