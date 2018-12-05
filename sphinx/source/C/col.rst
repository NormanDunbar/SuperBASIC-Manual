..  _col:

COL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  COL(x, y)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

COL is a function which returns the colour of a given screen pixel
(specified in absolute co-ordinates). The colour is however not coded in
the usual way - the return value of COL is either 0, 1, 2 or 3
(representing the four true colours which can displayed in MODE 4, ie.
black, red, green and white).

**Example**

::

    100 WMON: LIST#2
    110 xmin% = 0: xmax% = 100
    120 ymin% = 0: ymax% = 100
    130 FOR x% = xmin% TO xmax%
    140   FOR y% = ymin% TO ymax%
    150     c% = 2 * COL(x%,y%) + 1
    160     BLOCK 1, 1, x%-xmin%, y%-ymin%, c%
    170   END FOR y%
    180 END FOR x%

Unless you are using Minerva or SMS, replace x% and y% by x and y.

**NOTE**

COL will return meaningless data unless the screen is located at address
131072, is in MODE 4, and uses a 512 x 256 resolution.

**CROSS-REFERENCE**

:ref:`set` draws a screen pixel.

--------------


