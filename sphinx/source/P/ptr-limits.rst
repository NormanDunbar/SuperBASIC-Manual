..  _ptr-limits:

PTR\_LIMITS
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_LIMITS minx, miny, maxx, maxy                               |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS (v3.20+)         |
+----------+-------------------------------------------------------------------+

This command is used to set the limits of the screen over which the
mouse pointer can be moved using the mouse. The command expects four
parameters, the minimum x and y co-ordinates and the maximum x and y
co-ordinates. For a standard QL, you would normally set these values
with::

    PTR_LIMITS 0,0,511,255

However, on larger resolution displays, larger limits will be needed.

On the DIY Toolkit variant, the first two limits are ignored (they are
always taken to be zero). The maximum co-ordinates should be in pixel
sizes and can be any positive number up to 32767.

On Amiga QDOS,
negative numbers can be used, but to retain compatibility, the first two
parameters should be zero.

Having set these parameters, once the mouse
pointer has reached this position on screen then what happens depends on
whether the wrap-around display mode has been enabled with PTR\_KEY 0,1
or PTR\_KEY 1,1 (or not). If it has been disabled, then the mouse
pointer will move no further. If it has been enabled, then the mouse
pointer will appear at the other extreme limit.

**CROSS-REFERENCE**

:ref:`ptr-pos` can be used to dictate where the
mouse pointer should appear on screen. This command only calls
:ref:`ptr-max` on the DIY implementation.
