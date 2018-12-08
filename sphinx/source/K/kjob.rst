..  _kjob:

KJOB
====

+----------+------------------------------------------------------------------+
| Syntax   | KJOB jobname (TinyToolkit only)  or                              |
|          |                                                                  |
|          | KJOB jobnr  or                                                   |
|          |                                                                  |
|          | KJOB jobnr,tag (BTool only)                                      |
+----------+------------------------------------------------------------------+
| Location | TinyToolkit, BTool                                               |
+----------+------------------------------------------------------------------+

This command kills the given job (causing it, together with all of its
owned jobs, channels and memory to be removed or freed). Jobname in the
first variant can be passed as a string or as just the name of the Job
without quotes (so long as that name is not defined as a variable or
SuperBASIC PROCedure or FuNction). jobnr is the Job number as listed by
the JOBS command. If this is -1, this will kill the current Job.

The last variant is surplus at present - it was intended that it would pass
the second parameter back to the owner of the job, but due to an error
in the code, this second parameter is seen as the job tag.

**Examples**

::

    KJOB 'Perfection v2.04'
    KJOB 1

**NOTE**

Before v1.11 of TinyToolkit, you could not pass jobnr as -1 nor could
you use a variable to pass the jobnr (see JBASE).

**CROSS-REFERENCE**

:ref:`rjob` has a slightly different syntax.
:ref:`kill` and :ref:`kjobs`
remove all jobs. :ref:`spjob`,
:ref:`sjob`, :ref:`rel-job`,
:ref:`ajob` are other commands which handle jobs. The
function :ref:`job-dlr` will return the name of the
given job.

