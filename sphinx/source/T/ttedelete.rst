..  _ttedelete:

TTEDELETE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEDELETE (file$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is a function analogous to the command DELETE - it will return the
QDOS error code. The default device is not supported, ie. the file name
must be specified absolutely.

**NOTE**

In contrast to DELETE, TTEDELETE will return the value -7 if the file
did not exist.

**CROSS-REFERENCE**

:ref:`delete` of course.

