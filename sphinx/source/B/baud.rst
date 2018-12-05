..  _baud:

BAUD
====

+----------+------------------------------------------------------------------+
| Syntax   | BAUD bps  or                                                     |
|          |                                                                  |
|          | BAUD [port,] bps(SMS and ST/QL only)                             |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

The serial port(s) use a certain speed to communicate with printers,
modems, other computers, interfaces etc. This speed is set with BAUD.
The only values allowed are set out below, any other value for bps will
produce an error. The unit of the parameter is bits per second.

BAUD will set the same output and input baud rate for both serial ports.

+------------+-------------+------------------+
| Bits/Sec   | Bytes/Sec   | Time/32Kb        |
+============+=============+==================+
| 75         | 9.375       | 58 min, 15 sec   |
+------------+-------------+------------------+
| 300        | 37.5        | 14 min, 34 sec   |
+------------+-------------+------------------+
| 600        | 75          | 7 min, 17 sec    |
+------------+-------------+------------------+
| 1200       | 150         | 3 min, 38 sec    |
+------------+-------------+------------------+
| 2400       | 300         | 1 min, 49 sec    |
+------------+-------------+------------------+
| 4800       | 600         | 55 sec           |
+------------+-------------+------------------+
| 9600       | 1200        | 27 sec           |
+------------+-------------+------------------+
| 19200      | 2400        | 14 sec           |
+------------+-------------+------------------+


**NOTE 1**

The effect of BAUD 19200 depends on the hardware. On standard QLs the
serial port can only send data at that baud rate and tends to be
affected by the QL's sound chip.


**NOTE 2**

On a standard QL without Minerva the actual baudrate is slightly lower
than that stated above.


**NOTE 3**

In practice, data is compressed and transmitted with transfer protocols
(to reduce transmission errors), so the above transmission times refer
to the actual speed of the hardware, not the amount of data.


**NOTE 4**

The standard QL cannot safely handle the input of data at baud rates
greater than 1200.


**NOTE 5**

A modified co-processor Hermes which replaces the 8049 chip by a 8749 is
available, which allows independent input baud rates and (if Minerva
v1.95+ is present) independent output baud rates as well as fixing all
mentioned problems for QLs and AURORA boards. The more expensive version
of Hermes (SuperHermes) also provides three additional low speed RS232
input ports (supporting 30 to 1200 bps) and a high speed RS232 two way
serial port (supporting up to 57,600 bps, which equates to 4800
characters per second).


**NOTE 6**

On a QXL board without SMS v2.57+, a BAUD command would not have
immediate effect if a serial channel was open - it waited until you
closed the channel.


**NOTE 7**

It is possible to connect a mouse to a QL through the standard serial
port. Although the mouse operates at 1200 baud, you can use the mouse
alongside a printer (or modem) either with the assistance of Hermes or
by configuring the mouse software to de-activate whilst the higher baud
rate is in use.


**THOR XVI NOTES**

The THOR XVI allows the following additional baud rates:

+------------+-------------+------------------+
| Bits/Sec   | Bytes/Sec   | Time/32Kb        |
+============+=============+==================+
| 110        | 13.75       | 39 min, 43 sec   |
+------------+-------------+------------------+
| 134.5      | 16.8125     | 32 min, 29 sec   |
+------------+-------------+------------------+
| 150        | 18.75       | 29 min, 08 sec   |
+------------+-------------+------------------+
| 1800       | 225         | 2 min, 26 sec    |
+------------+-------------+------------------+

Independent baud rates may also be used on output and input channels
when the channel is opened by using an extended device name.


**MINERVA NOTES**

Minerva v1.93+ now enables you to set different output baudrates for
ser1 and ser2 - if you want different input baudrates for the two ports,
you will need Hermes (see above). Unfortunately, this enhancement will
only work on QLs without Hermes if both ports are output only.

If you want to disable the ability to handle different output baud
rates, do so with the command: POKE !124 !49,2

In order to set the two baudrates independently, BAUD will now accept
additional values in the range -1 to -128. This is calculated by looking
at the following table, working out which features you will need and
adding the values accordingly to -128:

+----------------+----------------------------------------------------------------------+
| Value to Add   | Effect                                                               |
+================+======================================================================+
| 64             | Alters ser2 baudrate (ser1 is default)                               |
+----------------+----------------------------------------------------------------------+
| 16             | Prevents standard BAUD command from altering baudrate on this port   |
+----------------+----------------------------------------------------------------------+
| 7              | Selects BAUD 75 on this port                                         |
+----------------+----------------------------------------------------------------------+
| 6              | Selects BAUD 300 on this port                                        |
+----------------+----------------------------------------------------------------------+
| 5              | Selects BAUD 600 on this port                                        |
+----------------+----------------------------------------------------------------------+
| 4              | Selects BAUD 1200 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 3              | Selects BAUD 2400 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 2              | Selects BAUD 4800 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 1              | Selects BAUD 9600 on this port                                       |
+----------------+----------------------------------------------------------------------+
| 0              | Selects BAUD 19200 on this port                                      |
+----------------+----------------------------------------------------------------------+

Please only try to add one baud rate value!!


**Minerva Examples**

BAUD -128

sets the baud rate for ser1 output at 19200. ser2 is unaffected.

BAUD -47

fixes the baud rate for ser2 output at 9600. ser1 is unaffected (-47 =
-128+64+16+1).


**SMSQ AND ST/QL NOTES**

If BAUD is only followed by one parameter, then it sets the baud rates
for both SER1 and SER2 on the QL, AURORA and QXL boards. However, if
SMSQ/E is running on an ATARI computer, or the command is used on an
ST/QL Emulator then it only sets the baud rate on SER1.

You can however supply two parameters to the command to set independent
baud rates (note that on a standard QL or Aurora, Hermes is needed for
independent baud rates on each serial port). In this case, the first
parameter is the number of the serial port to be set and the second
number is the new baud rate, for example:

BAUD 1,19200

sets the baud rate on SER1 to 19200 - any other serial ports are left
unaffected. If the rate (bps) is specified as zero, this selects the
highest possible BAUD rate on that port.

Please also note that if a translate has been set up with the TRA
command, changing the BAUD rate will make that translate apply to all
channels opened to the serial ports, whether or not they are already
open. See TRA for more details.

The following additional BAUD rates are also supported on the specified
SMSQ/E version:

**GOLD CARD & SUPER GOLD CARD**


-  1275(1200 receive and 75 transmit - only works with HERMES)
-  75(75 receive and 1200 transmit - only works with HERMES)

(The standard 1200 and 75 Baud rates are not supported)

**ATARI ST and TT**

On these computers, the different serial ports support different baud
rates. An ST/STE only has one serial port (SER1), a Mega STE has three
(SER1, SER2 and SER4), and a TT has four (SER1, SER2, SER3 and SER4).

Support for SER2, SER3 and SER4 was only added to the ST/QL Emulators in
version E-37 of the Drivers. It has always existed in SMSQ/E.

SER1

-  supports all the standard baud rates from 300 to 19200, except 7200.

SER2

-  supports all the standard baud rates from 300 to 19200 (including
   7200) as well as 38,400, 76,800, 83,333 and 125,000 baud (1x and 2x
   MIDI speeds).

   -  If the rate specified is 0, the rate used is 153,600.

-  Note that 38,400 on the TT was implemented in v2.69. 38,400, 76,800,
   83,333, 125,000 and 153,600 BAUD were implemented for the STE and TT
   in v2.73.

SER3

-  supports the same rates as SER1.

-  Hardware handshaking is not available on this port.

SER4

-  supports all the standard baud rates from 300 to 38,400 plus 57,600.

-  If the rate specified is 0, the rate used is 230,000.

**QXL**

All of the standard baud rates available to the normal QL are supported
except for 75 Baud.

**QPC**

All of the same baud rates as the QXL implementation are supported plus
38,400 and 57,600 baud.


**QXL AND QPC NOTES**

If one of the PC's serial ports is already linked to a mouse (in DOS)
then the BAUD command will not affect that port.


**CROSS-REFERENCE**

The Devices Appendix supplies details about the serial device ser and
parallel device par. The ser\_... and
par\_... commands allow you to set various
other parameters for serial and parallel ports.

You can check the current baud rate setting with
:ref:`baudrate`.

--------------


