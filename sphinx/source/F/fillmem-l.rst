..  _fillmem-l:

FILLMEM\_L
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FILLMEM\_L start\_address, how\_many, value                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Fill memory with a long (32 bit) value.


**EXAMPLE**

The screen memory is 32 kilobytes long. To fill it all black, try this::

    1000 FILLMEM_B SCREEN_BASE(#0), 32 * 1024, 0

or this::

    1010 FILLMEM_W SCREEN_BASE(#0), 16 * 1024, 0

or this::

    1020 FILLMEM_L SCREEN_BASE(#0), 8 * 1024, 0

and the screen will change to all black. Note how the second parameter is halved each time? This is because there are half as many words as bytes and half as many longs as words.

The fastest is FILLMEM\_L and the slowest is :ref:`fillmem-b`. When you use :ref:`fillmem-w` or FILLMEM\_L you must make sure that the start\_address is even or you will get a bad parameter error. :ref:`fillmem-b` does not care about its start_address being even or not.

:ref:`fillmem-b` truncates the value to the lowest 8 bits, :ref:`fillmem-w` to the lowest 16 bits and FILLMEM\_L uses the lowest 32 bits of the value. Note that some values may be treated as negatives when :ref:`peek`\ 'd back from memory. This is due to the QL treating words and long words as signed numbers.

**CROSS-REFERENCE**

:ref:`fillmem-b`, :ref:`fillmem-w`.


-------



