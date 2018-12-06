..  _ceil:

CEIL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CEIL (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function CEIL returns the closest integer to x which is greater than
or equal to x (the 'ceiling' of x). Compare INT which returns the next
integer which is less than or equal:

CEIL(12.75)=13 INT(12.75)=12 CEIL(-2.3)=-2 INT(-2.3)=-3

CEIL can handle numbers in the range -32768<x<=32768.

**Example**

A mechanic needs one and a half hours to replace the rusty exhaust of a
car. If his rate of pay is £13 per hour, he will charge
CEIL(13\*1.5)=£20 for the job (excluding parts).

**NOTE**

The simplest way to get a true INTEGER function, where x is rounded up
or down to the nearest integer is with INT(x+.5) which ensures that
INT(12.75)=13 and INT(-2.3)=-2.

**CROSS-REFERENCE**

:ref:`int`

