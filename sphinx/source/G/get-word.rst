..  _get-word:

GET\_WORD
=========

+----------+-------------------------------------------------------------------+
| Syntax   | word = GET\_WORD(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The next two bytes are read from the appropriate file and returned as an integer value.  This is equivalent to CODE(INKEY$(#channel)) \* 256 + CODE(INKEY$(#channel)). See the caution above for :ref:`get-byte` as it applies here as well. Any negative numbers returned will always be an error code.

**EXAMPLE**

::

    w = GET_WORD(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-float`, :ref:`get-long`, :ref:`get-string`.


-------



