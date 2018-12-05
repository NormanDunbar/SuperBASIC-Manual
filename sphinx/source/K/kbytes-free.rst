..  _kbytes-free:

KBYTES\_FREE
============

+----------+-------------------------------------------------------------------+
| Syntax   | memory = KBYTES\_FREE                                             |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The amount of memory considered by QDOS to be free is returned rounded down to the nearest kilo byte.  See also :ref:`bytes-free` if you need the answer in bytes.  The value in KBYTES\_FREE may not be equal to :ref:`bytes-free`\ /1024 as the value returned by KBYTES\_FREE has been rounded down.


**EXAMPLE**

::

    kb_available = KBYTES_FREE


**CROSS-REFERENCE**

:ref:`bytes-free`.


-------



