..  _alt:

ALT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ALT                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch to the
alternative font (normally italics) on an EPSON compatible printer::

    PRINT #ch,ALT

is therefore equivalent to::

    PRINT #ch,CHR$(27)&"6"

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`esc`,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

