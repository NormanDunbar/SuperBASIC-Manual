..  _jobid:

JOBID
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  JOBID [({nr, tag} | <name>)]                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns the 32-bit job id of the job with the given details as a
decimal value. The optional parameters may be either a job number and job tag
(as displayed by the JOBS command), or the job name. If no parameters are
supplied, the Job ID number of the current job is returned.

**Examples**

::

    result = JOBID            :REMark Returns the job ID of the current job
    result = JOBID(job_name$) :REMark Returns the job ID of the job specified in job_name$
    result = JOBID$(nr, tag)  :REMark Returns the job ID of the job specified by nr and tag


**CROSS-REFERENCE**

See :ref:`jobs`, :ref:`job-dlr`.

