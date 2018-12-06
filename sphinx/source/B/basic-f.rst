..  _basic-f:

BASIC\_F
========

+----------+------------------------------------------------------------------+
| Syntax   | BASIC\_B% (offset) and                                           |
|          |                                                                  |
|          | BASIC\_W% (offset) and                                           |
|          |                                                                  |
|          | BASIC\_F (offset)                                                |
+----------+------------------------------------------------------------------+
| Location | Turbo Toolkit, BTool, Turbo Toolkit (BASIC_L only)               |
+----------+------------------------------------------------------------------+

The functions BASIC\_B% and BASIC\_W% are similar to BASIC\_B and
BASIC\_W. BASIC\_F is a further function which can be used to return a
floating point number stored as six bytes starting at the specified
offset within the SuperBASIC system variables.


**NOTE**

A file called TurboFix\_bin can be used to allow these functions to
access Minerva MultiBASIC / SBASIC variables. Some early versions of
TurboFix\_bin have bugs in it. Beware that not all versions of this file
supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`basic-b` and
:ref:`basic-w`. :ref:`peek-f`
is similar to :ref:`basic-f`.

