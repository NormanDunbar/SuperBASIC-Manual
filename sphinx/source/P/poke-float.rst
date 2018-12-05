..  _poke-float:

POKE\_FLOAT
===========

+----------+-------------------------------------------------------------------+
| Syntax   | POKE\_FLOAT address, value                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure will poke the 6 bytes that the QL uses to represent a floating point variable into memory at the given address. The address can be odd or even as the procedure can cope either way.


**EXAMPLE**

::

    1000 Address = RESERVE_HEAP(6)
    1010 IF Address < 0 THEN
    1020    PRINT "ERROR " & Address & " Allocating heap space."
    1030    STOP
    1040 END IF
    1050 POKE_FLOAT Address, 666.616

**CROSS-REFERENCE**

:ref:`poke-string`, :ref:`peek-string`, :ref:`peek-float`.


-------



