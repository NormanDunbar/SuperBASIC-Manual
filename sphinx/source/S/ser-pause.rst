..  _ser-pause:

SER\_PAUSE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  SER\_PAUSE [port,] time                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Gold Card                                             |
+----------+-------------------------------------------------------------------+

On standard QL serial ports, you may find that some characters which
are sent by the QL through the serial ports get lost or the device to
which they are sent (for example a printer) prints undefined characters.

This problem may be caused by the fact that the stop bit which is sent
by the QL serial ports may be too short for the device at the other end.

The SER\_PAUSE command allows you to set the length of the stop bit in
microseconds - it effectively causes a short pause between each
character sent through the serial ports. If port
is not specified, this command will affect both serial ports, otherwise
it will only affect the specified serial port. The higher the value of
time, the longer the stop bit will be and hence the slower the serial
transfer rate.

**CROSS-REFERENCE**

If you are using serial ports to receive data, you may need to set
:ref:`ser-room`. :ref:`baud`
also affects the serial transfer rate. Please also refer to the Appendix
on device drivers for more information.

--------------


