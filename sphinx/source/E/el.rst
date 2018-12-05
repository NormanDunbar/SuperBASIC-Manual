..  _el:

EL
==

+----------+-------------------------------------------------------------------+
| Syntax   |  EL                                                               |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on the NLQ ( near letter
quality) font on an EPSON compatible printer::

    PRINT EL

is the same as::

    PRINT CHR$(27)&"x"&CHR$(1).

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`dbl`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`, ESC,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


