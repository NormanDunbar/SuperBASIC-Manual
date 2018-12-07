..  _odd:

ODD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ODD (number)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This function checks if the integer part of number can be divided by
two without remainder, ie. whether it is an odd number or not. If the
number is odd, the function will return 1, otherwise it will return 0.
The ODD function could easily be duplicated in BASIC by the following
function::

    10 DEFine FuNction ODD (number%)
    20   RETurn number% MOD 2
    30 END DEFine ODD
