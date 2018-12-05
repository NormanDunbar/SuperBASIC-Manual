..  _reserve:

RESERVE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESERVE (bytes, JobID)                                           |
+----------+-------------------------------------------------------------------+
| Location |  Timing Toolkit (DIY Toolkit Vol H)                               |
+----------+-------------------------------------------------------------------+

This function grabs an area of memory in the Common Heap similar to
ALCHP. However, the area is not released after a new SuperBASIC program
is loaded. Standard error returns are returned as values by the function
and the program can therefore include error trapping. -3 (Out of Memory)
or -2 (Invalid Job ID) are the most common errors. You can also specify
a task which will own the memory, and that memory will be removed when
that task is removed. This task will normally be 0 (SuperBASIC) or -1
(the current job).

**CROSS-REFERENCE**

See :ref:`discard` and
:ref:`linkup`. Also see
:ref:`alchp`, :ref:`respr` and
:ref:`grab`.

--------------



