..  _datareg:

DATAREG
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DATAREG [number]number=0...3                                     |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This function returns the value of the Machine code data register
number (default 0) following the completion of a MTRAP, QTRAP or BTRAP
command.

Because the default data register number is 0: PRINT DATAREG
will be 0 if no error occured during the TRAP call or else the relevant
error code.

Number will let you read the value of the relevant data register D0, D1, D2 or D3.


**CROSS-REFERENCE**

:ref:`addreg` allows you to read machine code
address registers - see this for an example of
:ref:`datareg`. See
:ref:`mtrap`, :ref:`qtrap` and
:ref:`btrap`.

