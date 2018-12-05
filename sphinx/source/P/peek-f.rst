..  _peek-f:

PEEK\_F
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PEEK\_F (address)                                                |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

PEEK\_F is a function which reads six bytes from any position in
memory, which it assumes is the internal representation of a SuperBASIC
floating point number, and returns its value.

**WARNING**

PEEK\_F will lead to a crash if the six bytes at address did not
represent a valid floating point, compare this with CVF.

**CROSS-REFERENCE**

:ref:`poke-f`, :ref:`cvf`,
:ref:`mkf-dlr` See also :ref:`peek-dlr`

--------------


