..  _ajob:

AJOB
====

+----------+------------------------------------------------------------------+
| Syntax   | AJOB jobname,priority or                                         |
|          |                                                                  |
|          | AJOB jobnr,tag,priority or                                       |
|          |                                                                  |
|          | AJOB job\_id,priority                                            |
+----------+------------------------------------------------------------------+
| Location | Toolkit II                                                       |
+----------+------------------------------------------------------------------+

This command forces the specified job (described by either its jobname,
its job number and tag, or its job identification number) to be
re-started at the given priority (which should be in the range 0...127
to maintain Minerva compatability - see SPJOB).

This will only work if the current priority of the given job is set to
zero, in any other case, a 'Not Complete' (-1) error will be reported.

**NOTE**

It is possible that on early versions of Toolkit II, only the second
syntax works.

**CROSS-REFERENCE**

:ref:`sjob` suspends a job.

:ref:`rel-job` releases a job.

:ref:`spjob` sets the priority of a job without
restarting it.

--------------


