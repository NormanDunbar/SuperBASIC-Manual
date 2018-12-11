..  _norm:

NORM
====

+----------+-------------------------------------------------------------------+
| Syntax   |  NORM                                                             |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to reset an EPSON
compatible printer::

    PRINT NORM

is the same as::

    PRINT CHR$(27)&"@"

**Example**

::

    LPRINT NORM

**CROSS-REFERENCE**

:ref:`bld`, :ref:`el`,
:ref:`dbl`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`,\ :ref:`esc`,\ :ref:`ff`,\ :ref:`lmar`,
:ref:`rmar`,\ :ref:`pagdis`,
:ref:`paglen`.
