..  _peek-float:

PEEK\_FLOAT
===========

+----------+-------------------------------------------------------------------+
| Syntax   | value = PEEK\_FLOAT(address)                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns the floating point value represented by the 6 bytes stored at the given address. BEWARE, although this function cannot detect any errors, if the 6 bytes stored at 'address' are not a proper floating point value, the QL can crash. The crash is caused by QDOS and not by PEEK\_FLOAT. This function should be used to retrieve values put there by :ref:`poke-float` mentioned above.

**EXAMPLE**

::

    1000 addr = RESERVE_HEAP(6)
    1010 IF addr < 0 THEN
    1020    PRINT "OUT OF MEMORY"
    1030    STOP
    1040 END IF
    1050 POKE_FLOAT addr, PI
    1060 myPI = PEEK_FLOAT(addr)
    1070 IF myPI <> PI THEN
    1080    PRINT "Something went horribly wrong!"
    1090    PRINT "PI = " & PI & ", myPI = " & myPI
    1100 END IF


**CROSS-REFERENCE**

:ref:`poke-string`, :ref:`peek-string`, :ref:`poke-float`.


-------



