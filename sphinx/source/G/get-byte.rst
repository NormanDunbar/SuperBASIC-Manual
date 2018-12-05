..  _get-byte:

GET\_BYTE
=========

+----------+-------------------------------------------------------------------+
| Syntax   | byte = GET\_BYTE(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Reads one character  from the file attached to the channel  number given and returns it as a value between 0 and 255.  This is equivalent to CODE(INKEY$(#channel)).

BEWARE, :ref:`put-byte` can put negative values to file, for example -1 is put as 255, GET\_BYTE will return 255 instead of -1. Any negative numbers returned are always error codes.


**EXAMPLE**

::

    c = GET_BYTE(#3)


**CROSS-REFERENCE**

:ref:`get-float`, :ref:`get-long`, :ref:`get-string`, :ref:`get-word`.


-------


