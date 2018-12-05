..  _inarray-pct:

INARRAY%
========

+----------+--------------------------------------------------------------------+
| Syntax   |  INARRAY% (array[ { $ \| % } ] [ ,first ] ,tofind[ { $ \| % } ] )  |
+----------+--------------------------------------------------------------------+
| Location |  INARRAY (DIY Toolkit - Vol Z)                                     |
+----------+--------------------------------------------------------------------+

This function searches a given array for a specified value. The array
can be of any type, a string (although this must only be
two-dimensional), a floating point or integer (these latter two can be
any number of dimensions, up to 15 !!). INARRAY% will then search the
specified array for the given value (tofind) which must be a string,
floating point or integer value, although it does not have to be the
same type as the array itself provided that you could assign the value
to the array, for example::

    array%(10)='2020'

and::

    PRINT INARRAY%(array%,'2020')

are okay, compare::

    array%(10)='x'

and::

    PRINT INARRAY%(array%,'x')

which both return an error.

The search is not case-sensitive and will
also equate embedded numbers so that the strings '020' and '20.00' are
seen as the same as '20'. Like the function SEARCH, the search is very
fast.

The first parameter can be specified, which allows you to tell
INARRAY% from which element onwards it should look (remember that the
first element is indexed with 0).

The value returned by INARRAY% will be
-7 if the value is not found in the specified array.

An error will be
generated if tofind could not be coerced to the same type as the array.

An error will also be generated if the array contains more than 32768
entries.

If the search is successful, INARRAY% will return one value
which represents the index of the entry. For strings and single
dimensional arrays, this is easy - if the value returned is srch, then::

    PRINT array(srch)

will show the value you searched for. However, where the array has more
dimensions, you will need a little work to find out the entry referred
to.

For example, take a three-dimensional array s%(10,20,30) - this
contains 11\*21\*31 (7161) entries, with the first entry being index 0,
this being s%(0,0,0) and the last entry being index 7160, this being
s%(10,20,30).

If INARRAY% (s%,300) returned the value 32, this would be
index number 32, equivalent to s%(0,1,1). This could be found out by
using the formula for s%, where the value returned (index) points to
s%(x,y,z), where::

    z=index MOD (31*21) MOD 31
    y=index MOD (31*21) DIV 31
    x=index DIV (31*21) MOD 31

It is important to work from right to left along the list of array
elements, alternating MOD and DIV for each entry.

**NOTE**

This function will not work in a program compiled with Turbo or
SuperCharge.

**CROSS-REFERENCE**

Use :ref:`instr` to locate a sub-string in a string.
See :ref:`search` which is similar.

--------------


