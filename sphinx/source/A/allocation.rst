..  _allocation:

ALLOCATION
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  ALLOCATION (bytes [,taskno%,tasktag%])                           |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is very similar to RESERVE. It allocates an area in the
common heap which may be associated with a specified job. If taskno% and
tasktag% are not specified, then the area is linked with the current job
and removed when the current job is removed.

**CROSS-REFERENCE**

:ref:`deallocate` should be used to remove the
allocated area.

The taskno% and tasktag% can be found using
:ref:`jobs` or :ref:`list-tasks`.

--------------


.. _alpha-blend:

ALPHA_BLEND
===========

+----------+----------------------+
| Syntax   | ALPHA_BLEND opacity% |
+----------+----------------------+
| Location | SMSQ version 3.26    |
+----------+----------------------+

Alpha-blending is a method of drawing graphics whereby the resultant output is partly transparent – overlapping shapes and text created with BLOCK, LINE, CIRCLE, PRINT etc. will be see-through to a degree, set by a new command ALPHA_BLEND. This takes a value from 0 (fully transparent) to 255 (opaque), ALPHA_BLEND 128 will make all output half-transparent, for example.

In the past, we have only had the variations offered by the OVER command, now we can achieve some pretty exciting graphical effects for use in games, for example. Here’s an example which draws three overlapping circles which are half-transparent::

    1000 PAPER 0: CLS
    1010 ALPHA_BLEND 128
    1020 FILL 1: INK 2: CIRCLE 40, 50, 20
    1030 FILL 1: INK 4: CIRCLE 65, 50, 20
    1040 FILL 1: INK 1: CIRCLE 50, 75, 20
    1050 CSIZE 2,0: AT 10,4: INK 7: PRINT "Alpha blending!"
    1060 STOP

In addition to the ALPHA_BLEND command, A new trap #3 with D0=$62, d1=alpha weight 0-255, d3.w=timeout and a0=channel ID allows the alpha-blend value to be set from assembler and other languages.

