..  _hot-res:

HOT\_RES
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_RES (key$,filename [;cmd$] [,JobName$] [,options] )         |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is the same as HOT\_CHP except that the program is loaded
into the resident procedure area, and cannot therefore be removed in the
future. If the resident procedure area cannot be accessed (ie. if a task
is already being executed), this function will access the common heap.

**CROSS-REFERENCE**

:ref:`hot-chp`.

