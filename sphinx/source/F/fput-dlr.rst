..  _fput-dlr:

FPUT$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPUT$ [#ch,] string :sup:`\*`\ [,string\ :sup:`i`]\ :sup:`\*`    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command writes the given string(s) in internal format to #ch,
default is #1. The internal format of a string is a word (two bytes)
giving the length of the string followed by the contents of the string
itself.

**Example**

::

    FPUT$ 'Hello'

will produce the equivalent of PRINT CHR$(0)&CHR$(5)&'Hello'.

**CROSS-REFERENCE**

:ref:`fget-dlr`, :ref:`put`.

--------------


