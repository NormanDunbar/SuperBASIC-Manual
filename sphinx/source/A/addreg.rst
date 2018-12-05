..  _addreg:

ADDREG
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ADDREG                                                           |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This function returns the value of the following Machine code address
register following the completion of a MTRAP, QTRAP or BTRAP command.

+-----------+------------------------------------------------+
| Command   | Machine Code Register Value Returned.          |
+===========+================================================+
| MTRAP     | A0                                             |
+-----------+------------------------------------------------+
| QTRAP     | A1                                             |
+-----------+------------------------------------------------+
| BTRAP     | A1 (relative to A6) - can be used by BPEEK%.   |
+-----------+------------------------------------------------+

**Example**

You could replace the ALCHP function with:

::

    100 bytes=100 : REMark Number of bytes required
    110 MTRAP 24,bytes,-1
    120 IF DATAREG < 0 : REPORT DATAREG : REMark an error has occurred
    130 IF DATAREG (1) < bytes : PRINT 'Requested area not allocated':STOP
    140 base=ADDREG

**CROSS-REFERENCE**

:ref:`datareg` allows you to read machine code
data registers.

See :ref:`mtrap`, :ref:`qtrap`
and :ref:`btrap`.

--------------


