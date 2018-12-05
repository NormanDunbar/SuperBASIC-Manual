..  _mki-dlr:

MKI$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MKI$ (integer%) where integer% = -32768..32767                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function MKI$ returns a string containing the internal
representation of an integer number (which is stored as two bytes).

**Example**

::

    MKI$(11111)

Would return the string "+g", because::

    CODE("+")*256 + CODE("g")

Equals 11111.

**CROSS-REFERENCE**

:ref:`cvi-pct` is the opposite function.
:ref:`mkf-dlr`, :ref:`mkl-dlr`,
:ref:`mks-dlr`

--------------


