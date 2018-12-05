..  _get-long:

GET\_LONG
=========

+----------+-------------------------------------------------------------------+
| Syntax   | long = GET\_LONG(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Read the next 4 bytes  from the file and return  them as a number  between 0 and 2^32 -1 (4,294,967,295 or HEX FFFFFFFF unsigned).

BEWARE, the same problem with negatives & error codes applies here as well as :ref:`get-float`.

**EXAMPLE**

::

    lv = GET_LONG(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-float`, :ref:`get-string`, :ref:`get-word`.


-------



