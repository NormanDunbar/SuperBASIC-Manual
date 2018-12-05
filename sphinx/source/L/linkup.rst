..  _linkup:

LINKUP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  LINKUP file$                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Memory Toolkit (DIY Toolkit Vol H)                               |
+----------+-------------------------------------------------------------------+

This command is similar to LRESPR except that it will work even if jobs
are running in the system. Although it loads the specified file into the
common heap, it marks the area of memory as permanent and therefore this
memory will not be removed by CLCHP or NEW. This therefore provides a
safe means of linking in new toolkits and device drivers permanently
even when Jobs are have already been EXECuted. Unlike LRESPR the default
data device is not supported and the filename must be supplied in full
as a string.

**CROSS-REFERENCE**

See :ref:`reserve` and
:ref:`discard`. Also see
:ref:`lrespr` and :ref:`alchp`.

--------------


