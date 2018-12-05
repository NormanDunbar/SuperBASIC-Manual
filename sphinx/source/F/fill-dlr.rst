..  _fill-dlr:

FILL$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FILL$ (short$,length)                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function will generate a string of the given length and return
it. The new string will consist of a repeated series of short$ which may
be one or two characters long. The length (as with any string) ranges
from 0 to 32767.

**Examples**

::

    FILL$("W-",7)

returns "W-W-W-W".

::

    FILL$("+",10)

returns "++++++++++".

::

    FILL$("Jo",0)

returns "" (the empty string).

::

    FILL$("Test",6)

returns "TeTeTe".

**NOTE 1**

A bug in the THOR XVI (v6.40) meant that the return stack could be
destroyed when appending the result to an even length string.

**NOTE 2**

A program will run more quickly (although it is more difficult to type
in) if you declare the string explicitly rather than using FILL$.

**NOTE 3**

The maximum length of string that can be produced with FILL$
depends on the ROM version - see the Compatibility Appendix.

**CROSS-REFERENCE**

Refer to :ref:`dim` about strings in general.

--------------


