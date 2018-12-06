..  _lmar:

LMAR
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LMAR(n) with n=0..255                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to set the left margin
to n characters on EPSON compatible printers: PRINT LMAR (10)
is the same as PRINT CHR$(27)&'l'&CHR$(10)

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`alt`,
ESC, :ref:`ff`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

