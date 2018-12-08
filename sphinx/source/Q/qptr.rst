..  _qptr:

QPTR
====

+----------+-------------------------------------------------------------------+
| Syntax   | PE_Found = QPTR(#channel)                                         |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns 1 if the Pointer Environment is loaded or 0 if not. The channel must be a SCR\_ or CON\_ channel, if not, the result will be 0. If a silly value is given then a QDOS error code will be returned instead.


**EXAMPLE**

::

    PRINT QPTR(#0)

will print 1 of the PE is loaded or zero otherwise.


