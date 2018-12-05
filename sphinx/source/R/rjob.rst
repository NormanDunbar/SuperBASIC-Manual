..  _rjob:

RJOB
====

+----------+------------------------------------------------------------------+
| Syntax   | RJOB jobname [,error] or                                         |
|          |                                                                  |
|          | RJOB jobnr,tag,error  or                                         |
|          |                                                                  |
|          | RJOB job\_id,error  or                                           |
|          |                                                                  |
|          | RJOB [job\_id,error] (BTool only)                                |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI, BTool                                      |
+----------+------------------------------------------------------------------+

This command removes a job from memory - all of its channels are
automatically closed and any memory used by the job is freed. The error
code is returned to the owner job of the removed job. The BTool variant
of RJOB allows you to enter the command without any parameters which
will kill every job except SuperBASIC (Job 0), see KJOBS and KILL.

**NOTE**

If the first syntax does not work, you are using an old Toolkit version.

**CROSS-REFERENCE**

:ref:`kjob` works similarly to
:ref:`rjob`. :ref:`kill`,
:ref:`remove` and :ref:`kjobs`
remove all jobs. Have a look at :ref:`jobs`,
:ref:`spjob`, :ref:`ajob`,
:ref:`sjob` etc.

--------------


