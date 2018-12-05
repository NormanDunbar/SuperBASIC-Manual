..  _free:

FREE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FREE                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns the largest block of the available free memory.
This can be less than the actual free memory if the heap has become
fragmented (see DEL\_DEFB).

**CROSS-REFERENCE**

See also :ref:`free-mem` and :ref:`tpfree`.

::

    x=ALCHP(FREE)

reserves the largest piece of memory available.

--------------

