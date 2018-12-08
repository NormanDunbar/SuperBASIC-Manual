..  _prioritise:

PRIORITISE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRIORITISE [jobnr, jobtag,] priority                             |
+----------+-------------------------------------------------------------------+
| Location |  TASKCMDS (DIY Toolkit Vol J)                                     |
+----------+-------------------------------------------------------------------+

PRIORITISE is a command which takes either one or three parameters and
sets the priority of the current job (if only one parameter is used) or
the job specified by jobnr and jobtag to priority.

**Example**

::

    PRIORITISE 127

gives the current job the maximum amount of processor time available when multitasking.

**CROSS-REFERENCE**

A one parameter variant of :ref:`prioritise` is
:ref:`prio`. Refer to
:ref:`spjob` and connected keywords for more
information on jobs and priorities. :ref:`jobs` will
give details of job numbers and job tags.

