..  _hex-dlr:

HEX$
====

+----------+------------------------------------------------------------------+
| Syntax   | HEX$ (decimal,nibbles)  or                                       |
|          |                                                                  |
|          | HEX$ (decimal [,nibbles]) (THOR only)                            |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This function converts a signed integer decimal number to the
equivalent hexadecimal number to a specified number of nibbles (ranging
from 1 to 32 - there are 4 nibbles in one digit). If nibbles is not
divisible by four, it is rounded up to the next multiple of four.
Negative values are also handled correctly provided that nibbles is set
to 32. The range of decimal is -2^31<decimal<2^31

**Examples**

::

    HEX (HEX$ (x,4))

Will = x if x is any number between 0 and 15.

::

    PRINT HEX$ (300,10)

will return the value 12C.

::

    PRINT HEX$ (300,8)

will return the value 2C.

**THOR XVI NOTE**

The THOR XVI version of this command will accept a value of zero for
nibbles {or even the command in the form HEX$(decimal)}. In both of
these cases the result is returned in the least number of Hexadecimal
digits necessary to store the number, for example::

    PRINT HEX$(32)

gives the result 20.

**THOR XVI WARNING**

A second parameter of zero may crash some versions of this command
except on v6.41 of the THOR XVI.

**CROSS-REFERENCE**

See :ref:`hex` and :ref:`bin`,
:ref:`bin-dlr`.

--------------


