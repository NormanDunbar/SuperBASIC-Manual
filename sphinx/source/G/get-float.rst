..  _get-float:

GET\_FLOAT
==========

+----------+-------------------------------------------------------------------+
| Syntax   | float = GET\_FLOAT(#channel)                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Reads 6 bytes from the file and returns them as a floating point value.

BEWARE, if any errors occur, the value returned will be a negative QDOS error code. As GET\_FLOAT does return negative values, it is difficult to determine whether that returned value is an error code or not. If the returned value is -10, for example, it could actually mean End Of File, this is about the only error code that can be (relatively) safely tested for.


**EXAMPLE**

::

    fp = GET_FLOAT(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-long`, :ref:`get-string`, :ref:`get-word`.

