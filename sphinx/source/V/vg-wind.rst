..  _vg-wind:

VG\_WIND
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_WIND x1, x2, y1, y2                                          |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This command defines a rectangular area of the screen. Only text
printed inside this window with VG\_PRINT (it's not a window in
SuperBASIC terms) will be visible::

      0                         511
    0 +-------------------------+
      |                         |
      |   x1        x2          |
      | y1+---------+           |
      |   |         |           |
      |   |BGI Text |           |
      |   |         |           |
      | y2+---------+           |
    55+-------------------------+

It is strongly
recommended that you specify a window inside the physical screen, so: 0
<= x1 < x2 <= 511 and 0 <= y1 < y2 <= 255  (assuming a standard 512x256
pixel screen - replace the upper bounds if you have a better graphics
card, eg. QVME). Note that VG\_WIND does not
check the parameters (this is impossible without the Window Manager).

Default settings are x1=0, x2=511, y1=0, y2=255.

**Example**

::

    VG_WIND 0,511,0,255

restores these defaults.

**CROSS-REFERENCE**

See also the other VG_XXX keywords. :ref:`qflim` can
be used to find out about about the size of the screen if the Window
Manager is loaded.

--------------


