..  _put-word:

PUT\_WORD
=========

+----------+-------------------------------------------------------------------+
| Syntax   | PUT\_WORD #channel, word                                          |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The supplied word is written to the appropriate channel as a sequence of two bytes. If the word value supplied is bigger than 65,535 then only the lower 16 bits of the value will be used. Negative values will be returned by :ref:`get-word` as positive.

**EXAMPLE**

::

    PUT_WORD #3, 65535


**CROSS-REFERENCE**

:ref:`put-byte`, :ref:`put-float`, :ref:`put-long`, :ref:`put-string`.


-------


