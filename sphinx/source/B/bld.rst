..  _bld:

BLD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  BLD                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on double
strike ('bold') on an EPSON compatible printer:

PRINT BLD is the same as PRINT CHR$(27)&"G"


**Example**

LPRINT "I " & BLD&"hate"&NRM & " these functions."


**CROSS-REFERENCE**

:ref:`norm`, :ref:`el`,
:ref:`dbl`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`, ESC,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


