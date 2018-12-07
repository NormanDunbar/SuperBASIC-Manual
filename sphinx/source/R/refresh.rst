..  _refresh:

REFRESH
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  REFRESH                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

This command forces the whole screen pointed to by SCRBASE to be copied
onto the visible part of memory.

**NOTE**

REFRESH assumes 512x256 pixel resolution, the screen base is always
assumed at $20000.

**CROSS-REFERENCE**

See also :ref:`scrbase`,
:ref:`sclr`, :ref:`plot` and
:ref:`draw`. See also
:ref:`w-show`.

