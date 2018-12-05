..  _bit-pct:

BIT%
====

+----------+-----------------------------------------------------+
| Syntax   | BIT% (number%,bitnr) with bitnr=0..15               |
+----------+-----------------------------------------------------+
| Location | BIT                                                 |
+----------+-----------------------------------------------------+

All numbers are internally stored as a series of values, each of which
can either be 1 or 0 (or, if you prefer, true or false). This is known
as the binary system. The set of digits which make up a binary number
are known as a stream of bits.

The function BIT% returns the status of a specified bit of an integer
number%, a value of either 0 or 1. Bit 0 means the rightmost bit,
whereas bit 15 would be the leftmost.

**Example 1**

Here is a function which converts a number to the binary
system. It allows a greater range than BIN$ and needs just one
parameter. The first version needs the REV$ and LOG2 extensions, the
second does not.

Version 1:

::

    100 DEFine FuNction BIT$ (x%)
    110  LOCal b$,i: b$=""
    120  FOR i=0 TO LOG2(ABS(x%)):b$=b$ & BIT%(x%,i)
    130  RETurn REV$(b$)
    140 END DEFine BIT$

Version 2:

::

    100 DEFine FuNction BIT$ (x%)
    110  LOCal b$,i: b$=""
    120  FOR i=0 TO LN(ABS(x%))/LN(2): b$=BIT%(x%,i) & b$
    130  RETurn b$
    140 END DEFine BIT$

**Example 2**

The following logical function returns 1 (true) if the given parameter
was an upper case character, or 0 (false) if it was lower case. This
function will work with all international character sets supported on
the original QL.

::

    100 DEFine FuNction UPPER% (c$)
    110  RETurn NOT BIT%(CODE(c$),5) ^^ BIT%(CODE(c$),7)
    120 END DEFine UPPER%

In any given character, bit 5 indicates the case and bit 7 the character
set.


**CROSS-REFERENCE**

:ref:`bin-dlr` also converts a decimal number to a
binary and :ref:`bin` back again.
:ref:`upper-dlr` returns a string in upper characters.

The length of a number x in binary form is :ref:`int`\ (LOG2 (ABS
(x))+1) .

--------------


