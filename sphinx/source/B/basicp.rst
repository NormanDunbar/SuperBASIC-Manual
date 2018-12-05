..  _basicp:

BASICP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  BASICP (offset)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function returns an internal pointer (address) used by the
SuperBASIC interpreter. offset must be non-negative and a multiple of 2
(up to a maximum of HEX('64').

Refer to system documentation for more information.


**Example**

PRINT BASICP(16)

returns the start address of the current SuperBASIC program in memory.

PRINT BASICP(32)

returns the start address of the SuperBASIC name list.


**NOTE**

This suffers from the same problem as BASIC.


**CROSS-REFERENCE**

:ref:`basic-b`,
:ref:`basic-l`,
:ref:`basic-w`. See
:ref:`new-name` for a useful example!

:ref:`basic-pointer` is the same as this
function.

:ref:`-name-dlr` and
:ref:`basic-name-dlr` allow you to access the
SuperBASIC name list safely.

--------------


