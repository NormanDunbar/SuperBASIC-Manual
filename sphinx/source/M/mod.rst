..  _mod:

MOD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  x MOD y                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This operator returns the value of x to modulus y. This is defined as
x-(x DIV y)\*y. If x or y is not an integer value, then it is rounded to
the nearest integer (compare INT). On non-SMS implementations the answer
and both parameters must lie within the range -32768...32767. On SMS,
the answer and both parameters can lie anywhere within roughly -
2e9...2e9.

**Examples**

::

    PRINT 13 DIV 5

gives the result 3. This is because 13 DIV 5 is 2, 2 multiplied by 5 is 10, 13 minus 10 is 3.

::

    PRINT 13.4 MOD 1.5

gives the result 1 (13 MOD 2).

**NOTE 1**

MOD has problems with the value -32768: PRINT -32768 MOD -1 gives the
result -1 on most implementations. On Minerva v1.76 (or later) and SMS
v2.77+ it gives the correct result, being 0.

**NOTE 2**

If you write a program for SMSQ/E which uses values outside the range
-32768...32767, this will not work on non-SMSQ/E machines - instead of::

    PRINT x MOD y

you will need to use::

    PRINT x - (INT(x / y) * y)

**CROSS-REFERENCE**

:ref:`div` returns the integer part of
x divided by y. Also, please see the alternative version of :ref:`mod`.

--------------


MOD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  MOD (x,y)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function MOD returns the value x-(DIV(x,y)\*y), ie. the value of x
to modulus y, in a similar fashion to the ROM based operator MOD.

However, this version is not limited to a range of -32768 to 32767, but
will accept parameters in the range -INTMAX to INTMAX. Because both
versions of MOD return the integer remainder of a division, x MOD 0 or
MOD(x,0) lead to an overflow error, because division by zero is
undefined.

**NOTE 1**

Both versions of MOD can be used in the same program, although the Turbo
and Supercharge compilers will not accept this alternative form.

**NOTE 2**

If you try to use a program compiled under Turbo or Supercharge after
loading the Math Package, if the program uses the normal SuperBASIC
operator MOD or DIV, an error will be generated and the program will
refuse to work!

**CROSS-REFERENCE**

:ref:`div` :ref:`mod` (ROM version)

--------------


