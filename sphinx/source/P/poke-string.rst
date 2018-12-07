..  _poke-string:

POKE\_STRING
============

+----------+-------------------------------------------------------------------+
| Syntax   | POKE\_STRING address, string                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure simply stores the strings contents at the given address. Only the contents of the string are stored, the 2 bytes defining the length are not stored. The address may be odd or even.

If the second parameter given is a numeric one or simply a number, beware, QDOS will convert it to the format that would be seen if the number was :ref:`print`\ ed before storing it at the address.  For example, 1 million would be '1E6' which is arithmetically the same, but characterwise, very different.


**EXAMPLE**

::

    1000 Address = RESERVE_HEAP(60)
    1010 IF Address < 0 THEN
    1020    PRINT "ERROR " & Address & " Allocating heap space."
    1030    STOP
    1040 END IF
    1050 POKE_STRING Address, "DJToolkit " & DJTK_VERS$


**CROSS-REFERENCE**

:ref:`peek-string`, :ref:`peek-float`, :ref:`poke-float`.

