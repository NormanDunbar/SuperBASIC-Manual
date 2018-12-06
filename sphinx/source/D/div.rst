..  _div:

DIV
===

+----------+-------------------------------------------------------------------+
| Syntax   |  x DIV y                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This operator returns the integer part of x divided by y.

If x or y is
not an integer, then the given value is rounded to the nearest integer
(compare INT).

On non-SMS implementations the answer and both parameters
must lie within the range -32768...32767.

On SMS, the answer and both
parameters can lie anywhere within roughly -2e9...2e9 (32-bit numbers).

The result of the operation is always rounded down to the next integer
ie. x DIV y=INT(x/y). Although this leads to some unexpected results
with negative numbers this is so that the formula: x=y\*(x DIV y)+(x MOD
y) is always true.

If you wish to use 32-bit numbers on non SMS systems,
you will need to use the formula: PRINT INT(x/y) instead of PRINT x DIV
y if either x or y is outside of the specified range.


**Examples**

::

    PRINT 13 DIV 5

gives the result 2 (13 divided by 5 is 2.6)

::

    PRINT 13.4 DIV 1.5

gives the result 6 (13 DIV 2).

::

    PRINT -13 DIV 5

gives the result -3


**NOTE**

DIV has problems with the value -32768: PRINT -32768 DIV -1
gives the result -32768 on most implementations. On Minerva v1.76 (or
later) it gives the correct result, being an overflow error (the answer
is +32768 which cannot be stored as a short integer variable). On SMS
v2.75+, it returns the value +32768 as DIV can handle the larger
numbers!!


**CROSS-REFERENCE**

:ref:`mod` returns the modulus of x divided by y. Also
please see the alternative version of :ref:`div`.

--------------


DIV
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DIV (x,y)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function returns x/y as an integer in the same way as the ROM
based DIV operator. However, this version is not limited to 16-bit
integers (-32768..32767). It will happily handle 32-bit integer numbers
(-INTMAX..INTMAX, roughly -1E9..1E9). Division by zero is not defined
and will produce an overflow message.


**Example**

::

    PRINT -40000 DIV 3

will produce an error on a standard QL ROM. Instead, you can now use::

    PRINT DIV(-40000,3)

which gives the correct result.


**NOTE 1**

Both variants of DIV can be used in the same program, although the Turbo
and Supercharge compilers will not accept this version.


**NOTE 2**

If you try to use a program compiled under Turbo or Supercharge after
loading the Math Package, if the program uses the normal SuperBASIC
operator MOD or DIV, an error will be generated and the program will
refuse to work!


**CROSS-REFERENCE**

:ref:`mod` (as an operator or a function) returns the
remainder of a division. Compare the other version of
:ref:`div`.

