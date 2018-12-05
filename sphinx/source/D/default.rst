..  _default:

DEFAULT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT (expression, default\_value)                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function DEFAULT usually simply returns the result of the given
expression, unless the expression contains undefined variables or does
not produce a floating point number. In either of these latter cases
DEFAULT will return the given default\_value.


**Example**

WRITE simply PRINTs a text to a given channel. If the channel ch was not
a valid number for any reason then #1 is used::

    100 DEFine PROCedure WRITE (ch, text$)
    110 ch = DEFAULT(ch, 1)
    120 PRINT#ch,text$
    130 END DEFine WRITE

**CROSS-REFERECE**

:ref:`type`. :ref:`default-dlr`
and :ref:`default-pct` work exactly like
:ref:`default` for string and integer expressions.

--------------


