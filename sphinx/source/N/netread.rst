..  _netread:

NETREAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NETREAD address, bytes                                           |
+----------+-------------------------------------------------------------------+
| Location |  FLEXYNET (DIY Toolkit - Vol Y)                                   |
+----------+-------------------------------------------------------------------+

This command will attempt to read the specified number of bytes over
the Network port using the Flexynet driver and store any bytes it
receives at the area in memory starting with the specified address. This
area of memory should therefore really be set aside with ALCHP or RESPR
before use (unless you know that the area of memory can be altered (such
as the screen memory - see SCREEN).

**NOTE 1**

This command should only be used in conjunction with NETSEND. Do not
attempt to use any other network drivers whilst one machine has used
this command.

**NOTE 2**

This command must be used before the NETSEND command is issued, if it is
to catch the data sent by the transmitting machine.

**CROSS-REFERENCE**

See :ref:`netrate` which allows you to set the
speed of the receiving machine to match the speed of the sending
machine. Also see :ref:`netsend`.
