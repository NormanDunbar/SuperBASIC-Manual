..  _wset-def:

WSET\_DEF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WSET\_DEF x0,y0,a0,b0, x1,y1,a1,b1, x2,y2,a2,b2                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

The command WSET\_DEF allows you to set up a user-defined size and
position for each of the three default windows, #0, #1 and #2. Each set
of four parameters is used to specify the size x,y
and position (a,b) of each window.

**Example**

::

    WSET_DEF 448,40,32,216, 448,200,32,16, 448,200,32,16
    WSET -1,8

is the same as WTV 8

**CROSS-REFERENCE**

See :ref:`wset`.

--------------


