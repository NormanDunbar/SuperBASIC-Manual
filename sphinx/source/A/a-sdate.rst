..  _a-sdate:

A\_SDATE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_SDATE year, month, day, hour, minute, second                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

The Atari ST has a built in battery-backed clock which maintains the
time whilst the machine is switched off. This time is automatically
copied across to the Emulator's own internal clock when the Atari ST is
started up. However, it can be necessary to alter the Atari's battery
backed clock.

This is achieved by using the command A\_SDATE in exactly the same way
as you would use SDATE to set the internal clock.

**NOTE 1**

Before v2.19 of Atari\_rext (and in v2.23), this command will not alter
the Emulator's internal clock until the Atari is reset.

**NOTE 2**

Before v2.29, this command did not support the TT's battery backed
clock.

**CROSS-REFERENCE**

See :ref:`sdate`.

:ref:`a-rdate` will set the internal clock to the
same date and time as the battery backed clock.

--------------


