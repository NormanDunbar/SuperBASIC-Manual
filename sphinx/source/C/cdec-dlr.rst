..  _cdec-dlr:

CDEC$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CDEC$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The function CDEC$ allows you to convert a given value into a string in
a specified format. This function will always take the integer part of
the given value (which must be in the range -2^31...2^31, and will be
rounded to the nearest integer if it is a floating point) and then
assumes that the last ndp digits are to the right of the decimal point.

If there are enough characters to the left of the decimal point, a comma
(',') will be placed between each set of three characters. The length is
the length of the string which is to be returned, which must always be
greater than or equal to the length of the value plus each comma and the
decimal point. If length is not large enough, then the string returned
will be full of asterisks ('\*').

This function is particularly useful for formatting columns of figures,
especially in view of the fact that it sidesteps the QL's habit of
converting large numbers to exponential form. The commas ensure that it
is ideal for use in formatting output of currencies.

**Examples**

PRINT CDEC$(123,4,0)

will print ' 123'

PRINT CDEC$(123,4,1)

will print '12.3'

PRINT CDEC$(1234567,9,2)

will print '12,345.67'

**CROSS-REFERENCE**

:ref:`print-using` is a general means of
formatting output.

:ref:`idec-dlr` and :ref:`fdec-dlr`
are complementary functions.

--------------


