..  _ser-room:

SER\_ROOM
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SER\_ROOM [port,] bytes                                          |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

Although handshaking should ensure that serial input is safe,
unfortunately some devices carry on sending data even though they have
been told to stop. This may be caused by a buffer attached between the
sending and receiving equipment, for example. This is known as 'serial
overrun' and can have unfortunate consequences, as the receiving
equipment may not have room to store the additional information.

Where the system is acting as the receiver, you can use the command SER\_ROOM
to specify a minimum amount of memory which must be left in the input
buffer when the System uses handshaking to check on the validity of the
data received. SER\_ROOM sets aside bytes in the input buffer which can
be used to store information received after the System has told the
sending equipment to stop.

If you still find that some data is lost due
to serial overrun, try increasing the amount of space. For machines with
more than one serial port, you can specify the number of the serial port
to be affected by this command (default SER1).

**NOTE**

The default room is 32 bytes.

**CROSS-REFERENCE**

:ref:`ser-buff` allows you to alter the size of
the input buffer and affects the value set by this command. You should
also look at :ref:`ser-pause`.

