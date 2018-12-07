..  _put-byte:

PUT\_BYTE
=========

+----------+-------------------------------------------------------------------+
| Syntax   | PUT\_BYTE #channel, byte                                          |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The given byte is sent to the  channel. If a byte value larger than 255 is given, only the lowest 8 bits of the value are sent. The byte value written to the channel will always be between 0 and 255 even if a negative value is supplied. :ref:`get-byte` returns all values as positive.

**EXAMPLE**

::

    PUT_BYTE #3, 10


**CROSS-REFERENCE**

:ref:`put-float`, :ref:`put-long`, :ref:`put-string`, :ref:`put-word`.
