..  _spjob:

SPJOB
=====

+----------+-------------------------------------------------------------------------------+
| Syntax   | SPJOB jobname,priority  (Toolkit II, TinyToolkit pre v1.10 and THOR only)  or |
|          |                                                                               |
|          | SPJOB jobnr,tag,priority (Toolkit II and THOR only)  or                       |
|          |                                                                               |
|          | SPJOB jobID,priority  or                                                      |
|          |                                                                               |
|          | SPJOB jobnr,priority(TinyToolkit pre v1.10)                                   |
+----------+-------------------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI, TinyToolkit (pre v1.10), BTool                          |
+----------+-------------------------------------------------------------------------------+

The specified job (described by either its jobname, its job number and
tag, or its job identification number) is set to the given priority
(which should be in the range 0 to 127 to maintain compatibility with
Minerva). A priority of zero will ensure that the job waits until it is
given a higher priority by another job.

**NOTE 1**

It is possible that only the second syntax works. Get an update!

**NOTE 2**

Before v1.10 of TinyToolkit, this toolkit included the same command but
with an incompatible syntax - this version has been renamed SP\_JOB.

**MINERVA NOTES**

Although on other ROMs, a priority higher than 127 can be assigned to a
job, on Minerva, the permitted priority range is actually -128...127 (if
a priority is stated to be higher than 127, you must subtract the
difference between this number and 256 from 0 to get the negative
priority).

The idea behind these negative priorities is that they are
for 'background tasks' which will only run when no tasks with a positive
priority are running. However, the effect is slightly more complex
because these negative priorities are split into eight levels, each of
which can have jobs running with priorities equivalent to -1 to -15. A
job in one level will not run whilst a job in a higher level is running,
however within each level each job will get a different amount of
processor time depending on their priorities {a job with a lower
priority (eg. -15) will get more processing time than a job with a
higher priority (eg. -1)}.

+-------+----------------+---------------+
| Level | Priority Range | Overall Value |
+=======+================+===============+
| 0     | -1 ... -15     | -1 ... -15    |
+-------+----------------+---------------+
| 1     | -1 ... -15     | -16 ... -31   |
+-------+----------------+---------------+
| 2     | -1 ... -15     | -32 ... -47   |
+-------+----------------+---------------+
| 3     | -1 ... -15     | -48 ... -63   |
+-------+----------------+---------------+
| 4     | -1 ... -15     | -64 ... -79   |
+-------+----------------+---------------+
| 5     | -1 ... -15     | -80 ... -95   |
+-------+----------------+---------------+
| 6     | -1 ... -15     | -96 ... -111  |
+-------+----------------+---------------+
| 7     | -1 ... -15     | -112 ... -127 |
+-------+----------------+---------------+

**WARNING**

The supplied parameters are not checked to see what you are trying to
do, which means that you can use this command to set the priority of
SuperBASIC to zero, preventing further command entry.

**CROSS-REFERENCE**

:ref:`sjob` suspends a job,
:ref:`rel-job` releases it.
:ref:`rjob` and :ref:`kjob` remove
a specific job, :ref:`kill` and
:ref:`kjobs` remove all jobs except the main
SuperBASIC interpreter. See also :ref:`sp-job`,
:ref:`prio`,
:ref:`prioritise`.

