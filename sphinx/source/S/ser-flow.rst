..  _ser-flow:

SER\_FLOW
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SER\_FLOW [port,] flow                                           |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

Because of the variety of equipment which can be connected to a QL
system through a serial port, the System has to support several types of
handshaking. Handshaking is basically a means of checking if the data
received through a serial port is the same as the data which has been
sent. Normally, handshaking can be specified when a port is opened (see
the Appendix concerning device drivers). However, it can also be useful
to preset the handshaking by using the command SER\_FLOW. flow can have
one of three values:

- h Enable handshaking
- i Ignore handshaking - do not bother to check data
- x XON/XOFF detection.

To enable flexibility on
machines with more than one serial port, you can also specify the number
of the serial port to be affected by this command (default SER1).

**CROSS-REFERENCE**

Please refer to the Appendix on device drivers for more information.

--------------


