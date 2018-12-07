..  _scrinc:

SCRINC
======

+----------+-------------------------------------------------------------------+
| Syntax   |  SCRINC [(#ch)]                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

The screen width is not fixed on QDOS computers, QL Emulators and
future hardware expansions (graphic cards) offer different screen modes
with different resolutions. The function SCRINC returns the screen width
relating to the screen upon which the given channel (default #0) is
located. The width is returned as the number of bytes needed to store a
line of pixels.

The standard QL mode 4 and mode 8 always return 128 = 512/4.

However, it is not *always* true that the number of
bytes required to store a line of pixels is equal to the number of
pixels DIV 4 and you should therefore use this function or similar.

**Example**

See the second listing at the second example for SCRBASE.

**CROSS-REFERENCE**

:ref:`screen` returns the start address of the
screen. See also :ref:`scr-llen`

