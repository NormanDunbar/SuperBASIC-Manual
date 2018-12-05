..  _get-string:

GET\_STRING
===========

+----------+-------------------------------------------------------------------+
| Syntax   | a$ = GET\_STRING(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Read the next 2 bytes from the file and assuming them to be a QDOS string's length, read that many characters into a$.  The two bytes holding the string's length are NOT returned in a$, only the data bytes.

The subtle difference between this function and :ref:`fetch-bytes` is that this one finds out how many bytes to return from the channel given, :ref:`fetch-bytes` needs to be told how many to return by the  user. GET\_STRING is the same as::

    FETCH_BYTES(#channel, GET_WORD(#channel))

WARNING - JM and AH ROMS will give a 'Buffer overflow' error if the length of the returned string is more than 128 bytes. This is a fault in QDOS, not DJToolkit. The demos file, supplied with DJToolkit, has a 'fix' for this problem.


**EXAMPLE**

::

    b$ = GET_STRING(#3)


**CROSS-REFERENCE**

:ref:`get-byte`, :ref:`get-float`, :ref:`get-long`, :ref:`get-word`, :ref:`fetch-bytes`.


-------



