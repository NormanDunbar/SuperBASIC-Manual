..  _prt-use-dlr:

PRT\_USE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_USE$                                                        |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

This function returns a string representing the current port emulated
by the PRT device, thus allowing you to check whether or not you need to
alter the device set with PRT\_USE.

**Example**

::

    PRT_USE ser1etf
    PRINT PRT_USE$

will return 'ser1etf'.

**CROSS-REFERENCE**

See :ref:`prt-use`.

