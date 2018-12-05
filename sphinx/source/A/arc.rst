..  _arc:

ARC
===

+----------+---------------------------------------------------------------------------------------------------------------------+
| Syntax   | ARC [#ch][,x\ :sup:`1`\ ,y\ :sup:`1`] TO x\ :sup:`2`\ ,y\ :sup:`2`\ ,angle :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] |
|          | TO x\ :sup:`j`\ ,y\ :sup:`j`\ ,angle\ :sup:`j`]\ :sup:`\*`                                                          |
+----------+---------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                              |
+----------+---------------------------------------------------------------------------------------------------------------------+

ARC causes the two points at the co-ordinates
(x\ :sup:`1`\ ,y\ :sup:`1`\ ) and (x\ :sup:`2`\ ,y\ :sup:`2`\ ) to be
connected with an arc. The arc is defined as the sector of the circle
formed by drawing two straight lines from the two given co-ordinates to
the centre of the circle, where angle is the angle (in radians) between
those two lines. Therefore, angle=0 is a straight line and angle=PI,
half a circle.

It therefore follows that the greater ABS(angle), the more pronounced is
the curve on the arc.

Multiple arcs can be draw with the same command by adding extra sets of
parameters for each additional arc. For example::

    ARC 100,10 TO 120,40,3 TO 80,70,3

will actually draw two arcs, one between the points (100,10) and
(120,40) with angle=3 and the second between the points (120,40) and
(80,70), also with angle=3.

When drawing multiple arcs, there is actually no need for the next arc
in the series to begin at the end of the previous arc, provided that a
semicolon ';' is inserted between each set of parameters. For example::

    ARC 100,10 TO 120,40,3;30,40 TO 50,60,3

Whether the arc is drawn clockwise or anti-clockwise depends upon two
factors: If y\ :sup:`1`\ >y\ :sup:`2` and angle>0, then the arc will be
drawn anti-clockwise. Swapping the two co-ordinates or making the angle
negative will force the arc to be drawn clockwise.

Co-ordinates refer to the window relative graphic co-ordinate system,
which is relative to the graphic origin. The size and position of the
arc also depend upon the SCALE of the window. If no first point is given
then the current position of the graphic cursor is used. The graphic
cursor is set to the last point of the arc on completion of the command.

**Example 1**

::

    100 WINDOW 448,200,32,16: CLS: SCALE 4,-2,-2
    110 FOR t=PI/16 TO 2*PI STEP PI/16
    120   ARC SIN(t),COS(t) TO COS(t),SIN(t),PI*SIN(t/2)
    130 END FOR t

**Example 2**

::

    100 WINDOW 448,200,32,16: CLS: SCALE 100,0,0
    110 FOR x=10 TO 90 STEP 10
    120   FOR y=10 TO 90 STEP 10
    130     ARC x,y TO y,x,PI/2
    140   END FOR y
    150 END FOR x

**Example 3**

::

    100 POINT #2,150,50
    110 FOR x=50 TO 150 STEP 20
    120   ARC #2 TO x,50,PI/2
    130 END FOR x

**NOTE 1**

On non Minerva v1.89+ ROMs, ARC does not work properly - small angles
produce rubbish, wrong co-ordinates are used and the last pixel of the
arc is not always drawn. Even SMS does not cure these problems.

**NOTE 2**

An angle of 2\*PI would form a complete circle and cannot be drawn,
therefore the maximum value for ABS(angle) is a value just less than
2\*PI.

**NOTE 3**

On some ROM versions, the command does not check that the TO separator
is present - however, SMSQ/E (at least) does and therefore some programs
may fail if used under SMSQ/E and they have used a comma instead of TO.

**WARNING**

Some QDOS implementations of this command can corrupt the hard disk
drive in some obscure circumstances. Get Minerva or SMSQ/E to be safe!!

**CROSS-REFERENCE**

:ref:`arc-r` works in exactly the same way as
:ref:`arc` but uses a relative co-ordinate system,
where the origin is the current position of the graphic cursor.

:ref:`scale` sets the graphic origin and also the
size of the window.

--------------


