..  _par-abort:

PAR\_ABORT
==========

+----------+------------------------------------------------------------------+
| Syntax   | PAR\_ABORT or                                                    |
|          |                                                                  |
|          | PAR\_ABORT port\_number(SMSQ/E only)                             |
+----------+------------------------------------------------------------------+
| Location | ST/QL, SMSQ/E                                                    |
+----------+------------------------------------------------------------------+

This command clears out all of the closed PAR buffers and then sends an
'aborted' message, to the PAR device, thus effectively stopping the
computer from sending any information still in the buffers through the
PAR device. Any open channels connected to the port are unaffected.

**NOTE**

Although the SMSQ/E implementation allows a port to be specified, there
are currently no implementations of the QL which have more than one
parallel port, therefore trying to pass a port\_number at present
results in a bad parameter error.

**CROSS-REFERENCE**

:ref:`ser-abort` and
:ref:`prt-abort` are very similar.
:ref:`par-clear` clears out the buffers but
does not tell anyone. :ref:`prt-abt` is similar
on the Trump Card and Gold Cards.

--------------


