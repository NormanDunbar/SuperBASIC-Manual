..  _job-dlr:

JOB$
====

+----------+------------------------------------------------------------------+
| Syntax   | JOB$ (job\_ID)  or                                               |
|          |                                                                  |
|          | JOB$ (jobnr,tag)  or                                             |
|          |                                                                  |
|          | JOB$ (jobname)                                                   |
+----------+------------------------------------------------------------------+
| Location | Toolkit II                                                       |
+----------+------------------------------------------------------------------+

This function returns the name of a specified job, or an empty string
if it has no name or if the parameters do not specify an existing job.
The third format is somewhat curious since you need to supply the very
thing you are asking for (ie. the jobname)! A negative job\_ID points to
the calling job.

**CROSS-REFERENCE**

See :ref:`ojob`, :ref:`pjob`,
:ref:`job-name` and
:ref:`nxjob` for more information on current jobs.
Compilers normally include their own commands to set the correct job
name.

