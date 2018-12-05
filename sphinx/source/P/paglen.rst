..  _paglen:

PAGLEN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PAGLEN (inches) inches=0..22                                     |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to set the length of a
page (in inches) when sent to EPSON compatible printers. This is
normally 12". The function is equivalent to::

    CHR$(27) & 'C' & CHR$(0) & CHR$(inches)

**CROSS-REFERENCE**

:ref:`pagdis`, :ref:`paglin`,
:ref:`lmar`, :ref:`rmar`.

--------------


