..  _peek-string:

PEEK\_STRING
============

+----------+-------------------------------------------------------------------+
| Syntax   | a$ = PEEK\_STRING(address, length)                                |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The characters in memory at the given address are returned to a$.  The address may be odd or even as no word for the length is used, the length of the returned string is given by the length parameter.

**EXAMPLE**
The following set of functions return the Toolkit 2 default devices::

    1000 DEFine FuNction TK2_DATA$
    1010   RETurn TK2_DEFAULT$(176)
    1020 END DEFine TK2_DATA$
    1030 :
    1040 DEFine FuNction TK2_PROG$
    1050   RETurn TK2_DEFAULT$(172)
    1060 END DEFine TK2_PROG$
    1070 :
    1080 DEFine FuNction TK2_DEST$
    1090   RETurn TK2_DEFAULT$(180)
    1100 END DEFine TK2_DEST$
    1110 :
    1120 :
    1200 DEFine FuNction TK2_DEFAULT$(offset)
    1210   LOCal address
    1220   IF offset <> 172 AND offset <> 176 AND offset <> 180 THEN
    1230      PRINT "TK2_DEAFULT$: Invalid Offset: " & offset
    1240      RETurn ''
    1250   END IF
    1260   address = PEEK_L (SYSTEM_VARIABLES + offset)
    1270   IF address = 0 THEN
    1280     RETurn ''
    1290   ELSE
    1300     REMark this is a pointer to the appropriate TK2 default
    1310     RETurn PEEK_STRING(address+2, PEEK_W(address))
    1320   END IF
    1330 END DEFine TK2_DEFAULT$


**CROSS-REFERENCE**

:ref:`poke-string`, :ref:`peek-float`, :ref:`poke-float`.

