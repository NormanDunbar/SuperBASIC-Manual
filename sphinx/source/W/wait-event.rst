..  _wait-event:

WAIT\_EVENT
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  WAIT\_EVENT (event [,timeout] )                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.71+                                                    |
+----------+-------------------------------------------------------------------+

This function access the Event Accumulator for the current job and
checks whether the specified event (or events) have occurred. If you want
to check for the occurrence of several events, you merely need to add
together the numbers of the events. If any one of the specified events
has already occurred then the function will return the total value of the
specified events which have occurred. If none of the specified events
have occurred, then this function will suspend the current program until
one of those events has occurred or the specified timeout (if any) has
elapsed. If timeout is not specified then the function will wait
forever. If the reason for the function returning was that the timeout
has elapsed (and none of the specified events have occurred) then the
returned value will be 0.

**Example**

::

    PRINT WAIT_EVENT(12)

This wait for event numbers 4 and 8 (4+8=12). If event 8 was notified
as having occurred, then the value 8 would be shown on screen.

**CROSS-REFERENCE**

:ref:`send-event` notifies a Job's Event
Accumulator that one or more events have occurred.

