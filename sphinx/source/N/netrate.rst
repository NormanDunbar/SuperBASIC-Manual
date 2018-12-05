..  _netrate:

NETRATE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETRATE transmit\_delay, reception\_delay, timeout               |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command is at the heart of the Flexynet philosophy and allows you
to alter the speed of the QL's networks (as regards NETSEND and
NETREAD), so that you can match the speed of the network ports to the
various computers which are linked together over the network. This
enables different machines to talk to each other substantially more
quickly than using the Network drivers supplied with the QL or Toolkit
II.

Values are sent over the Network ports as pulses equivalent to bits,
with eight bits representing one byte (0...255) - the pulse is an
electrical signal, either 1 or 0 (on or off). The three parameters are
all in arbitrary units and if they are specified as zero, any existing
value will remain unchanged. They are used as follows:

- Transmit\_delay - this specifies the amount of time that the sending machine will alter
  the voltage for on the network to signify either a 1 or a 0 bit. This
  needs to be higher than the reception delay on the receiving machine as
  the receiving process is fundamentally slower than the transmission
  process. The higher the value, the longer the delay.

- Reception\_delay - this specifies the amount of time Flexynet will wait for changes in the
  voltage over the network ports.

  If the change occurs after Flexynet has counted up to the reception\_delay value, then a bit of 0 is assumed,
  otherwise a bit of 1. Once eight bits have been received then a byte
  made up of those eight bits is stored in memory. For example: CHR$(10)
  is represented by the bits 0 0 0 0 1 0 1 0 This can be seen by::

    PRINT BIN$ (10,8)

- Timeout - this represents a timing loop which Flexynet will wait for
  the next pulse over the net - if nothing is received in this time, then
  a 'not complete' error will be reported. This value will need to exceed
  the reception\_delay parameter by a comfortable margin. The easiest way
  to match up the required parameter values for two machines connected
  using Flexynet is to send a copy of one machine's screen to the other
  machine and compare the display. To do this, enter the command::

    NETREAD 131072,32768

  on the receiving machine, then enter the command::

    NETSEND 131072,32768

  on the sending machine.

  If the NETRATE parameters are incorrect, you
  will notice that the displays do not match - either increase the
  reception\_delay on the receiving machine or increase the
  transmit\_delay on the sending machine, making notes of the values which
  you have tried at either end.

It is difficult to give any advice on the
parameters to use as it depends on the expansion boards being used with
your particular QL, as well as the speed of the ZX-8301 chip which forms
part of the QL's motherboard. However, the author cites the following
test results:

- Standard QL to Standard QL (both with code in ROM or fast
  RAM such as CST 512K expansion board)::

    NETRATE 5,3,127

  on both machines

- Gold Card on British QL to Gold Card on Foreign QL::

    NETRATE 8,4,0

on both machines.

- Gold Card on Foreign QL to Gold Card on British QL::

    NETRATE 33,12,0

 on both machines

- Standard QL (with code in ROM or fast RAM such
  as CST 512K expansion board) to Gold Card on Foreign QL::

    NETRATE 2,2,127

  on the Standard QL::

    NETRATE 20,7,127

  on the Gold Card QL

**NOTE**

Flexynet will not work on machines which do not use a 68000 or 68008
chip (for example QXLs or Super Gold Card), unless the Cache is disabled
(see CACHE\_OFF). It also requires an expanded machine to work
properly.

**CROSS-REFERENCE**

Refer to the Networks Appendix for further details. See
:ref:`netvar-pct` which allows you to read the
various speed settings. Also see :ref:`netread`
and :ref:`netsend`

--------------


