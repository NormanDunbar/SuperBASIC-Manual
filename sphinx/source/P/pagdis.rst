..  _pagdis:

PAGDIS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PAGDIS (lines) lines=0..127                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the printer control codes needed to set the
length of the page header when sent to EPSON compatible printers.

::

    PRINT PAGDIS (lines)

is equivalent to::

    PRINT CHR$(27) & CHR$(78) & CHR$(lines)

**Example**

To set the header to three lines::

    OPEN #3,ser1:PRINT #3,PAGDIS(3):CLOSE#3

**CROSS-REFERENCE**

:ref:`paglin`, :ref:`paglen`,
:ref:`lmar`, :ref:`rmar`.

--------------


