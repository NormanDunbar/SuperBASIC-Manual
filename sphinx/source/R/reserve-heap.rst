..  _reserve-heap:

RESERVE\_HEAP
=============

+----------+-------------------------------------------------------------------+
| Syntax   | buffer = RESERVE\_HEAP(length)                                    |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function obtains a chunk of memory for your program to use, the starting address is returned as the result of the call.  Note that the function will ask for 4 bytes more than you require, these are used to store a flag so that calls to :ref:`read-header` do not crash the system by attempting to deallocate invalid areas of memory. If you call this function, the returned address is the first byte that your program can use.

**EXAMPLE**

The following example shows how this function can be used to reserve a buffer for :ref:`read-header`, described elsewhere.

::

    1000 buffer = RESERVE_HEAP(64)
    1010 IF buffer < 0
    1020    PRINT 'ERROR allocating buffer, ' & buffer
    1030    STOP
    1040 END IF
    1050 error = READ_HEADER(#3, buffer)

    .....do something with buffer contents here

    2040 REMark Finished with buffer
    2050 RELEASE_HEAP buffer


**CROSS-REFERENCE**

:ref:`release-heap`, :ref:`alchp`,
:ref:`rechp`, :ref:`allocation`.


-------



