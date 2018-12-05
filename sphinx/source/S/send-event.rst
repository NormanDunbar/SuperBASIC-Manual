..  _send-event:

SEND\_EVENT
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  SEND\_EVENT {jobname$ \| jobID \| jobnr,tag }, event             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.71+                                                    |
+----------+-------------------------------------------------------------------+

With v1.51 of the Window Manager (and v2.71 of SMSQ/E), the possibility
of Job Events was introduced. This is basically a simple way of making
one program wait until it receives notification from another Job that up
to eight different events has occurred.

The events are undefined and
simply represented by the eight numbers : 1, 2, 4, 8, 16, 32, 64, 128.
This command allows you to tell a specified job that those events have
occurred - several events may be notified by adding together the various
values of event. The job to be notified can be represented by either
its:

#. Jobname (eg. 'SBASIC')
#. Job ID number (returned by OJOB for example).
#. Job number and Job Tag (returned by JOBS).

**Example**

::

    SEND_EVENT OJOB(1), 2+8

Notifies the current job's owner that events 2 and 8 have occured.

**CROSS-REFERENCE**

A job can test to see if an event has occured with
:ref:`wait-event`.

--------------


