..  _netbeep:

NETBEEP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETBEEP delay, pulses                                            |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command allows you to send signals through the QL's network ports
- if you plug a pair of earphones into the network port (instead of a
Network lead), you will be able to hear the sound generated - this can
even work alongside the QL's BEEP command to provide the QL with
rudimentary polyphonic sound. In fact, some of the Spectrum emulators
for the QL use this feature to provide the QL with Spectrum-like sound.

The first parameter tells the command the length of the delay between
pulses sent to the Network port - the higher the delay, the lower will
be the pitch.

The second parameter tells the command the number of
pulses to send to the port - each pulse will send an electrical signal
through the network port (equivalent to turning a switch on and then
back off).

You can also use this command (in conjunction with NETPOLL on
other computers in the Network to test the speed settings for Flexynet)
- simply send a series of bytes over the Flexynet (using NETBEEP) and
check that they have been received correctly at the other end by using
NETPOLL. If the bytes are incorrect, you may need to increase the delay.

**NOTE**

The units used by both parameters are quite arbitrary and therefore some
experimentation may be required.

**CROSS-REFERENCE**

Refer to the Appendix on Networks to find out more about Flexynet. See
:ref:`netpoll` which allows you to read signals
sent through the network ports. :ref:`netrate`
allows you to alter the speed of the Flexynet and
:ref:`netread` /
:ref:`netsend` can be used to read and send
multiple bytes.

--------------


