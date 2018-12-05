..  _hex:

HEX
===

+----------+-------------------------------------------------------------------+
| Syntax   |  HEX (hex$)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function returns the decimal value of a hexadecimal number. The
hexadecimal system of numbering is based upon base 16, which means that
instead of each digit being in the range 0..9 (as in decimal), each
digit can actually hold the value 0..15.

Because a digit can only be one
character, a system was devised for representing the value 10..15 -
these values are represented by the letters A..F respectively. Any
digits outside the range 0..F will cause an 'error in expression'.

Hex$ can be anything in the range $80000000 (which equates to -2^31) to
$79999999 (which equates to 2^31-1).

**Examples**

::

    PRINT HEX('F')

will print the value 15.

::

    PRINT HEX('10')

will print the value 16.

**CROSS-REFERENCE**

:ref:`hex-dlr` works the other way around, converting
decimal numbers into their hexadecimal equivalent. See
:ref:`bin` and :ref:`bin-dlr` for the
binary versions. SMS users can achieve the same thing by using, for
example::

    PRINT $1AB

instead of::

    PRINT HEX ('1AB').

--------------


