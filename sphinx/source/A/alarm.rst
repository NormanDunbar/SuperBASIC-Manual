..  _alarm:

ALARM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ALARM hour,minutes                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command creates a Job at low priority which makes the QL sound
several beeps when the alarm time is reached and then removes itself.
Naturally, this facility only works if the system clock is correct.

The hour is based on the 24-hour clock and must therefore be specified
in the range 0...23 and the minutes in the range 0...59.

**Example**

How about a hourly alarm to remind you to switch off the cassette player
and listen to the news on the radio?

::

    100 FOR hour=8 to 18
    110   ALARM hour-1,59
    120 END FOR hour

**CROSS-REFERENCE**

Set the system clock with :ref:`sdate`, adjust it
with :ref:`adate`.

Alarm jobs can be killed by using :ref:`rjob` for
example.

