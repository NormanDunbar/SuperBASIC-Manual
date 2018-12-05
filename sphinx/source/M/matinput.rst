..  _matinput:

MATINPUT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  MATINPUT array [{\\ \| , \| ; \| !}]                             |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATINPUT reads each element of an array in turn from #1, so
that you have to type them all in. The modifiers ';' and '!' place the
cursor behind the last entry whilst ',' moves it to the next tab
position. The default is '\\' which forces a new line between entries -
the '\\' can be omitted.

**Example**

::

    100 DIM a(1,2)
    110 MATINPUT a,

**CROSS-REFERENCE**

:ref:`matread`,
:ref:`matrnd`, :ref:`for`

--------------


