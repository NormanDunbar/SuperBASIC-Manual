..  _pjob:

PJOB
====

+----------+------------------------------------------------------------------+
| Syntax   | PJOB (job\_ID)  or                                               |
|          |                                                                  |
|          | PJOB (jobnr,tag)  or                                             |
|          |                                                                  |
|          | PJOB (jobname)                                                   |
+----------+------------------------------------------------------------------+
| Location | Toolkit II                                                       |
+----------+------------------------------------------------------------------+

Each job has a priority - the function PJOB finds it and returns 0 if
the given job does not exist, otherwise it returns the priority of the
specified job.

You can calculate the job\_ID with the formula:

    job_id = jobnr + tag * 2\ :sup:`16`

A negative job\_ID (preferably -1) identifies the job calling PJOB. The higher the
priority, the more working time a job draws from the processor, and
therefore the faster the execution.

**Example**

The priority of the main SuperBASIC interpreter can be seen with::

    PRINT PJOB(0)

**MINERVA NOTE**

The maximum priority for a job on a standard QL is 255, however, on a
Minerva ROM, the acceptable priority range is altered to -128...127. If
PJOB returns a value over 127, then deduct the difference between this
and 256 from zero to get the priority on a Minerva machine - see SPJOB
for further details.

**CROSS-REFERENCE**

:ref:`job-dlr`, :ref:`ojob` and
:ref:`nxjob` return other information about a job.

--------------


