..  _fgetf:

FGETF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETF [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function FGETF gets six bytes from a channel (default #1) in the
internal format of a floating point number.

**WARNING**

FGETF will hang SuperBASIC if the six bytes did not represent a valid
floating point, so be careful.

**CROSS-REFERENCE**

:ref:`get`, :ref:`mkf-dlr`,
:ref:`peek-f`, :ref:`fputf`.
:ref:`cvf` converts a string containing the internal
format into a floating point number.

--------------


