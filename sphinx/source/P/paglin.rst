..  _paglin:

PAGLIN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PAGLIN (lines) lines=0..127                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to set the length of a
page (in lines) when sent to EPSON or compatible printers. This is
normally either 66 or 72 lines.

::

    PRINT PAGLIN (lines)

is the same as::

    PRINT CHR$(27) & 'C' & CHR$(lines)

**CROSS-REFERENCE**

:ref:`pagdis`, :ref:`paglen`,
:ref:`lmar`, :ref:`rmar`.

--------------


