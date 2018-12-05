..  _put-long:

PUT\_LONG
=========

+----------+-------------------------------------------------------------------+
| Syntax   | PUT\_LONG #channel, byte                                          |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The long value given is sent as a sequence of four bytes to the channel. Negative values can be put and these will be returned correctly by :ref:`get-long` unless any errors occur.

**EXAMPLE**

::

    PUT_LONG #3, 1234567890

**CROSS-REFERENCE**

:ref:`put-byte`, :ref:`put-float`, :ref:`put-string`, :ref:`put-word`.


-------



