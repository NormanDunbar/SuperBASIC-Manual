..  _defined:

DEFINED
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFINED (anything)                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

SuperBASIC is different from other BASIC dialects in that it does not
assign a default value to newly introduced but still unset variables
(except on SMS which assigns the value Zero to an unset numeric variable
and an empty string to an unset string).

This makes it possible for a
program to detect if a variable has been properly initialised - an
'error in expression' (-17) is reported if you try to carry out
operations on unset variables.

The function DEFINED takes any parameter,
no matter what type it is, provided that it is a constant or a variable.
DEFINED returns 0 if the parameter was a variable but unset and 1 for defined
variables and constant expressions.


**NOTE**

This function does not work on SMS


**CROSS-REFERENCE**

:ref:`clear` makes all variables undefined.
:ref:`print` writes asterisks if unset variables are
required to be printed. :ref:`type` returns 1, 2 or 3
for undefined variables. See also :ref:`unset`.

