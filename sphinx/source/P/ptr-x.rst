..  _ptr-x:

PTR\_X
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_X (argument, module)                                        |
+----------+-------------------------------------------------------------------+
| Location |  PTRRTP                                                           |
+----------+-------------------------------------------------------------------+

The function PTR\_X transforms a point (described in polar
co-ordinates) into the rectangular co-ordinates and returns the real
part of the latter. argument is an angle in radians, module a radius.

**Example**

A line in rectangular co-ordinates transformed to polar co-ordinates
looks like a circle when plotted on screen. However, if you were to look
at this line using polar co-ordinates, it would appear as straight line
again. Confused?

::

    100 SCALE 10,-5,-5: PAPER 0: CLS
    110 FOR a = 0 TO 2*PI STEP PI/128
    120   POINT PTR_X(a,2), PTR_Y(a,2)
    130 END FOR a

**CROSS-REFERENCE**

The other rectangular co-ordinate is found with
:ref:`ptr-y` below. Also see
:ref:`rtp-r` and :ref:`rtp-t`
