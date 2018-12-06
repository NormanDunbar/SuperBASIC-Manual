..  _bin-dlr:

BIN$
====

+----------+------------------------------------------------------------------+
| Syntax   | BIN$ (decimal,digits)  or                                        |
|          |                                                                  |
|          | BIN$ (decimal [,digits]) (THOR only)                             |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This function converts a signed integer decimal number to the equivalent
binary number (to a specified number of binary digits ranging from 1 to
32). Negative values are also handled correctly.


**Examples**

(1) BIN (BIN$ (x,4)) = x

if x is any number between 0 and 15.

(2) A short function to compare two numbers using the mathematical 'OR'
function. Do note however that the same function already exists on the
QL, and the commands

PRINT 100\|\|10 and PRINT \_or(100,10) have exactly the same effect,
although the BASIC version below does enable you to see what the
function actually does:

::

    100 DEFine FuNction _or(x,y)
    110  a$=BIN$(x,32): b$=BIN$(y,32)
    115  PRINT a$,b$
    120  c$=FILL$('0',32)
    130  FOR i=1 TO 32
    140    IF a$(i)=1 OR b$(i)=1: c$(i)=1
    150  END FOR i
    155  PRINT c$
    160  RETurn BIN(c$)
    170 END DEFine _or


**THOR XVI NOTE**

The THOR XVI version of BIN$ will accept a value of zero for digits {or
even the command in the form BIN$(decimal)}. In both of these cases the
result is returned in the least number of Binary digits necessary to
store the number, for example: PRINT BIN$(10)gives the result 1010.


**THOR XVI WARNING**

A second parameter of zero may crash some versions of this command other
than on v6.41 of the THOR XVI.


**CROSS-REFERENCE**

See :ref:`bin` and :ref:`hex`,
:ref:`hex-dlr`. Also refer to
:ref:`bit-pct`.

