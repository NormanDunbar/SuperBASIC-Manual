..  _put-string:

PUT\_STRING
===========

+----------+-------------------------------------------------------------------+
| Syntax   | PUT\_STRING #channel, string                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The string  parameter is sent to the appropriate channel as a two byte word giving the length of the data then the characters of the data. If you send a string of zero length, LET A$ = "" for example, then only two bytes will be written to the file.  See :ref:`poke-string` for a description of what will happen if you supply a number or a numeric variable as the second parameter. As with all QL strings, the maximum length of a string is 32kbytes.

**EXAMPLE**

::

    PUT_STRING #3, "This is a string of data"


**CROSS-REFERENCE**

:ref:`put-byte`, :ref:`put-float`, :ref:`put-long`, :ref:`put-word`.


-------



