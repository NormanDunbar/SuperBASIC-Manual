..  _bin:

BIN
===

+----------+------------------------------------------------------------------+
| Syntax   | BIN (binary$)  or                                                |
|          |                                                                  |
|          | BIN (binary) where binary=0..111111                              |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This function returns the decimal value of a binary number (given as a
string). For small numbers, a floating point number can be used but will
cause problems if this is not a valid binary number.


**Examples**

(1) PRINT BIN ( '1001' )

will print the value 9

(2) As it stands, the function BIN cannot handle binary dots

(eg. 1001.101=9.625), therefore a BASIC function to provide this
facility is:

::

    100 DEFine FuNction BINN(a$)
    110   LOCal i,dot,dota,value_a,loop
    120   IF a$='' THEN RETurn 0
    130   FOR i=1 TO LEN(a$): IF a$(i) INSTR '10.'=0: REPORT -17: STOP
    140   dot='.' INSTR a$: IF dot=0 THEN RETurn BIN(a$)
    150   value_a=0:dota=0
    160   IF dot>1 THEN value_a=value_a+BIN(a$(1 TO dot-1))
    170   IF '.' INSTR a$(dot+1 TO ): REPORT -17: STOP
    180   REPeat loop
    190     IF dot>=LEN(a$):EXIT loop
    200     a$=a$(dot+1 TO )
    210     dot='1' INSTR a$: IF NOT dot THEN EXIT loop
    220     value_a=value_a+1/(2^(dot+dota)):dota=dota+dot
    230   END REPeat loop
    240   RETurn value_a
    250 END DEFine BINN


**NOTE**

Any digit other than 0 or 1 will produce odd results.


**CROSS-REFERENCE**

:ref:`bin-dlr` works the other way around, converting
decimal numbers into their binary equivalent. See
:ref:`hex` and :ref:`hex-dlr` for the
hexadecimal versions. :ref:`bit-pct` is also useful.

SMS users can achieve the same thing by using, for example :ref:`print`\ %1001 instead of :ref:`print`\ BIN('1001').

