..  _bytes-free:

BYTES\_FREE
===========

+----------+-------------------------------------------------------------------+
| Syntax   | memory = BYTES\FREE                                               |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This simple function  returns the amount of memory known by the system to be free.  The answer is returned in bytes, see also :ref:`kbytes-free`.  For the technically  minded, the free memory is  considered  to be that  between the addresses held in the system variables SV\_FREE and SV\_BASIC.

**EXAMPLE**

::

    ...
    2500 freeMemory = BYTES_FREE
    2510 IF freeMemory < 32 * 1024 THEN
    2520    REMark Do something here if not enough memory left...
    2530 END IF
    ...


**CROSS-REFERENCE**

:ref:`kbytes-free`.

