..  _nrm:

NRM
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NRM                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes to switch back to the normal
font (Pica) on an EPSON compatible printer::

    PRINT NRM

is the same as::

    PRINT CHR$(27)&"P".

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`,\ :ref:`dbl`,\ :ref:`enl`,\ :ref:`pro`,\ :ref:`si`,\ :ref:`unl`,\ :ref:`alt`,\ ESC,\ :ref:`ff`,\ :ref:`lmar`,\ :ref:`rmar`,\ :ref:`pagdis`,
:ref:`paglen`. :ref:`uput`
allows you to send untranslated bytes to the printer.
