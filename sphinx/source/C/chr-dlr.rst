..  _chr-dlr:

CHR$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CHR$ (code)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the character associated with the given code.

The QL ROM character set is actually only in the range 0...255, although
code can be anything in the range -32768...32767. The least significant
byte of the supplied parameter is used, ie. code && 255.

**Examples**

PRINT CHR$(100) and PRINT CHR$(1636)

both return 'd'.

A short function to convert any lower case letters in a given string to
upper case:

::

    100 DEFine FuNction UP$(a$)
    110 LOCal U$
    115 U$=a$
    117 IF a$='':RETurn ''
    120 FOR i=1 TO LEN(a$)
    130   IF CODE( a$(i) )>96:IF CODE( a$(i) )<123:U$(i)=CHR$( CODE( a$(i) )-32 )
    140 END FOR i
    150 RETurn U$
    160 END DEFine UP$

**NOTE**

The THOR XVI limits code to the range 0...255.

**CROSS-REFERENCE**

See :ref:`code` and also please refer to the
Characters section of the Appendix.

--------------


