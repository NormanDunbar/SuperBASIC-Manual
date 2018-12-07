..  _point:

POINT
=====

+----------+----------------------------------------------------------------------+
| Syntax   |  POINT [#ch,] x,y :sup:`\*`\ [;x\ :sup:`i`\ ,y\ :sup:`i`]\ :sup:`\*` |
+----------+----------------------------------------------------------------------+
| Location |  QL ROM, GPOINT                                                      |
+----------+----------------------------------------------------------------------+

This command draws one or more specified points in the given window
(default #1). The co-ordinates are floating point numbers, which means
that two POINTs drawn with::

    POINT 20,20: POINT 21,20

or::

    POINT 20,20; 21,20

for example, are not normally neighbours. If a
point lies outside a window, it is simply not drawn, ie. overflow errors
do not occur. The graphics cursor is updated to the last point to be
plotted.

**Examples**

::

    POINT 50,50
    POINT 50,50; 60,60
    POINT #2,20,50
    POINT #2,20,50; 50,20; 20,20; 50,50

**NOTE**

On MGx ROMs, there is a well-known POINT bug which makes POINT draw two
points instead of one. This is fixed by some versions of Toolkit II, the
ST/QL Emulator, SMS, Gold Card, other ROMs (especially Minerva) and
small patches like GPOINT. GPOINT includes two commands: a replacement
POINT and GPOINT which is just another name for the same thing.

**CROSS-REFERENCE**

The relation between the supplied co-ordinates and their position in the
window is defined with :ref:`scale`. The colour of
the point(s) is set with :ref:`ink`. The window can be
resized with :ref:`window`.
:ref:`line` draws a line. The
:ref:`gpoint` command is fully identical to
:ref:`point` except that it fixes the MGx ROM bug.
Check the ROM version with :ref:`ver-dlr`.

