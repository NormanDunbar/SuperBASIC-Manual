..  _netpoll:

NETPOLL
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETPOLL address, bytes                                           |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command allows you to sample electrical signals sent over the QL's
Network, which can be used to decode any digital data stream, such as
information sent by cassettes tapes (this method has been used by some
Spectrum emulators for the QL to allow you to load Spectrum games direct
from tape).

You need to pass two parameters - the address of a place in
memory where the data which is read is to be stored, followed by the
number of bytes which can be stored at the address.

For each byte to be
stored at the specified address, NETPOLL
'listens' to the QL's Network ports and whenever an electrical pulse is
received by the port (for example as sent by NETBEEP), then NETPOLL
counts the length of this pulse and sets the data byte to the relevant
value, moving onto the next available byte (or returning to BASIC if it
has reached the end of the storage area).

The value of the data byte
will be between 0 and 254, with the delay being the difference between
the value and 255 (hence a value of 127 shows a delay of approximately
twice a value of 254). If a value is 255, this indicates that the timer
ran out before a pulse arrived.

**NOTE**

An odd number of bytes at the storage area will be rounded up, so that
an even number of pulses will always be read.

**CROSS-REFERENCE**

The amount of time that :ref:`netpoll` will wait
for a pulse is affected by :ref:`netrate`\ 0,0,x. See
:ref:`netbeep` which sends signal tones along the
network ports. Also see
:ref:`netrate`,\ :ref:`netread`
and\ :ref:`netsend`.

--------------


