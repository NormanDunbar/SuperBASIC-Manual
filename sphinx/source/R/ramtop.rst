..  _ramtop:

RAMTOP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RAMTOP                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

The function returns the active memory in KBytes, whether this is free
memory or not. On the original QL without any expansion this function
will return 128, whereas on a QL expanded to 640K, 640 is returned.

**CROSS-REFERENCE**

The value of :ref:`ramtop` can be lowered with
:ref:`reset` to emulate a machine which has less
available memory.

:ref:`print`\ (PHYSTOP/1024)-128
gives the value of the additional memory.

:ref:`free-mem` and :ref:`free` return the actually available
memory.

--------------


