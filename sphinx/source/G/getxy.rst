..  _getxy:

GETXY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  GETXY x%, y%                                                     |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

This command draws a crosshair (with its centre at (x%,y%) which can be
moved with the cursor keys. Holding down <SHIFT> while pressing a cursor
key will speed up movement. Once the crosshair is placed in the correct
position, press <SPACE> to return to BASIC. The two parameters x% and y%
will be updated to the position of the centre of the cross.

**NOTE 1**

It is obligatory to pass integer variables to GETXY.

**NOTE 2**

GETXY returns a wrong value for y% on Minerva ROMs, so it is unusable.

**NOTE 3**

Turbo and Supercharge compilers cannot compile this command.

**WARNINGS**

See :ref:`set`\ .

**CROSS-REFERENCE**

:ref:`invxy`

