..  _int:

INT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  INT(x)                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the closest integer which is smaller than or
equal to x. For positive parameters this means that the non-integer part
of the number is cut off, so INT(12.75)=12 and INT(5)=5. Note that for
negative numbers this is not true: INT(-12.75) = -13 because -13 <
-12.75. INT can handle any number in the range -2^31<=x<2^31, except
under SMS where it can handle much larger numbers, in the range
-2^255 <= x <= 2^2047.

**Example**

A function Rond(x,d) to round a number x to d decimal places::

    100 DEFine FuNction Rond(no,plac)
    110   LOCal temp
    120   temp=INT(no*10^(plac+1)+.5)/10^(plac+1)
    130   RETurn INT(temp*10^plac+.5)/10^plac
    140 END DEFine

::

    PRINT Rond (10.3226,2)

gives the result 10.32

**NOTE 1**

The INT function does not round to the nearest integer, use INT(x+.5)
instead.

**NOTE 2**

On non-Minerva ROMs, unless you have SMS installed, INT with x>(2^31)-2
gives an overflow error.

**CROSS-REFERENCE**

:ref:`ceil` is complementary to
:ref:`int`.

--------------


