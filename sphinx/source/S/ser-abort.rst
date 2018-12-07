..  _ser-abort:

SER\_ABORT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  SER\_ABORT [port]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

This command is similar to PAR\_ABORT except that it clears out all of
the closed SER buffers and then sends an 'aborted' message, to the SER
device. If port is specified, on machines which support more than one
serial port, this allows you to specify the port number to be affected
(default SER1).

**CROSS-REFERENCE**

See :ref:`par-abort`.

