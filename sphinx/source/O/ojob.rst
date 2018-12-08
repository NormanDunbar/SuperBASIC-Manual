..  _ojob:

OJOB
====

+----------+------------------------------------------------------------------+
| Syntax   | OJOB (job\_ID)  or                                               |
|          |                                                                  |
|          | OJOB (jobnr, tag)  or                                            |
|          |                                                                  |
|          | OJOB (jobname)                                                   |
+----------+------------------------------------------------------------------+
| Location | Toolkit II                                                       |
+----------+------------------------------------------------------------------+

This function will return the job\_id of the 'owner' of the given job.
Normally the owner of a job is the job which initiated it. So, if job 1
creates job 2 then job 1 is the owner of job 2. However, because jobs
can execute other jobs without becoming their owner, generally the owner
of a job is the job that will kill that job when it itself is removed. A
negative job\_ID points to the job which calls OJOB.

**CROSS-REFERENCE**

:ref:`job-dlr`, :ref:`nxjob` and
:ref:`pjob` return other information about a job.
:ref:`jobs` lists all jobs.
