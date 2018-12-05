..  _xdraw:

XDRAW
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  XDRAW x1,y1 TO x2,y2                                             |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

The command XDRAW draws lines, just like LDRAW, but it draws the lines
in white ink, using the XOR mode; so drawing the same line will remove
it again without changing the background.

**Example**

::

    100 REPeat scan 110 w% = RND(1 TO 200)
    120   FOR x% = 0 TO 511 + w%
    130   IF x% < 512 THEN
    140     XDRAW x%,0 TO x%,255
    150   END IF
    160   IF x% > w% - 1 THEN
    170     XDRAW x%-w%,0 TO x%-w%,255
    180   END IF
    190   IF KEYROW(1)&&8 THEN EXIT scan
    200   END FOR x%
    210 END REPeat scan

**CROSS-REFERENCE**

:ref:`ldraw`, :ref:`line` with
:ref:`over`.

--------------


