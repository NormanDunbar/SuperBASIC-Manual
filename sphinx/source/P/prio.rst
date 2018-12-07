..  _prio:

PRIO
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PRIO priority                                                    |
+----------+-------------------------------------------------------------------+
| Location |  PRIO                                                             |
+----------+-------------------------------------------------------------------+

This command sets the priority of the current job to the given
priority. Priority must range from 0 to 127.

**Example**

Multitasking jobs waiting for a keypress or anything else to be
activated slow down the whole system although they are actually doing
nothing. A job which is waiting (perhaps for a certain amount of time)
for input could set its own priority to one, and then when it is able to
continue, reset to a higher priority value.

**NOTE**

If a job has priority 0 it will not be able to run. Other tasks may
however set that job's priority (eg. with SPJOB and allow it to
continue).

**CROSS-REFERENCE**

:ref:`spjob`, :ref:`sp-job`,
and :ref:`pjob` also deal with job priorities.

::

    SPJOB -1

is exactly the same as PRIO, priority, or
:ref:`prioritise`.

