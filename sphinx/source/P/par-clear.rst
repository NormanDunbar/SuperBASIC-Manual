..  _par-clear:

PAR\_CLEAR
==========

+----------+------------------------------------------------------------------+
| Syntax   | PAR\_CLEAR  or                                                   |
|          |                                                                  |
|          | PAR\_CLEAR port\_number(SMSQ/E only)                             |
+----------+------------------------------------------------------------------+
| Location | ST/QL, SMSQ/E                                                    |
+----------+------------------------------------------------------------------+

This clears out all currently closed PAR buffers, thus preventing any
further output. Any channels which are open to the PAR port will be left
unaffected.

**NOTE**

Although the SMSQ/E implementation allows a port to be specified, there
are currently no implementations of the QL which have more than one
parallel port, therefore trying to pass a port\_number at present
results in a bad parameter error.

**CROSS-REFERENCE**

:ref:`ser-clear` and
:ref:`prt-clear` are similar.

--------------


