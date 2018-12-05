..  _csize:

CSIZE
=====

+----------+-------------------------------------------------------------------+
| Syntax   | CSIZE [#channel,] width, height                                   |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+

This command sets the size and spacing of characters in the given
channel (default #1).

Width ranges from 0 to 3 and there are two possible heights, 0 and 1.
Each width and height corresponds to a certain pixel size:

+-------+---------+------+--------+---------+------+
| Width | Spacing | Size | Height | Spacing | Size |
+=======+=========+======+========+=========+======+
|   0   |    6    |   5  |   0    |   10    |   9  |
+-------+---------+------+--------+---------+------+
|   1   |    8    |   5  |   1    |   20    |  18  |
+-------+---------+------+--------+---------+------+
|   2   |   12    |  10  |                         |
+-------+---------+------+                         |
|   3   |   16    |  10  |                         |
+-------+---------+------+--------+---------+------+

In low resolution mode width 0 and 1 have no effect: in that mode, the
smallest character size allowable is 12 pixels wide; CSIZE 2,0.

**NOTE 1**

On pre-JS ROMs, characters which use all eight pixels available for the
definition of characters will not be printed correctly on screen. Even
on JS and MG ROMs, problems exist in some character sizes. Minerva, SMS
and the ST/QL drivers (Level E-23 onwards) prevent any such problems.

**NOTE 2**

The THOR XVI allows you to use any value for the vertical size - odd
values give double height characters and even values give normal height.

**CROSS-REFERENCE**

:ref:`char-inc` allows you to change spacing
independently of character size.

:ref:`mode` will reset the character size to the
default (ie. 2,0 in :ref:`mode` 8 and 0,0 in
:ref:`mode` 4).

The command :ref:`at` is also affected by the current
character spacing.

--------------


