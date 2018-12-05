..  _arc-r:

ARC\_R
======

+----------+------------------------------------------------------------------------------------------------------------------------+
| Syntax   | ARC\_R [#ch][,x\ :sup:`1`\ ,y\ :sup:`1`] TO x\ :sup:`2`\ ,y\ :sup:`2`\ ,angle :sup:`\*`\ [[;x\ :sup:`i`\ ,y\ :sup:`i`] |
|          | TO x\ :sup:`j`\ ,y\ :sup:`j`\ ,angle\ :sup:`j`]\ :sup:`\*`                                                             |
+----------+------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                 |
+----------+------------------------------------------------------------------------------------------------------------------------+

This command draws an arc relative to the current graphic cursor. This
means that rather than the co-ordinates (x,y) being relative to the
graphic origin, they are relative to the current graphic cursor. Arcs
are however still affected by the current SCALE.

Each set of co-ordinates used in the ARC\_R command moves the graphic
cursor, which means for example that (x\ :sup:`1`\ ,y\ :sup:`1`\ ) is
relative to the graphic cursor when ARC\_R is first called, whereas
(x\ :sup:`2`\ ,y\ :sup:`2`\ ) is relative to
(x\ :sup:`1`\ ,y\ :sup:`1`\ ).

**Example 1**

A short program to draw several equi-distant arcs using ARC\_R:

::

    100 WINDOW 448,200,32,16:SCALE 100,0,0
    110 PAPER 0:INK 4:CLS
    120 ARC 20,20 TO 90,20,PI/4
    130 FOR i=1 TO 4
    140   ARC_R 0,10 TO -70,0,-PI/4
    150   ARC_R 0,10 TO 70,0,PI/4
    160 END FOR i

**Example 2**

The same routine, but altered to use ARC:

::

    100 WINDOW 448,200,32,16:SCALE 100,0,0
    110 PAPER 0:INK 4:CLS
    120 ARC 20,20 TO 90,20,PI/4
    130 FOR i=30 TO 100 STEP 10
    140   ARC 20,i TO 90,i,PI/4
    150 END FOR i

**CROSS-REFERENCE**

The graphic cursor is moved with commands such as
:ref:`point`, :ref:`arc`,
:ref:`circle` and :ref:`line`.

Please also see :ref:`arc`.

--------------


