..  _nxjob:

NXJOB
=====

+----------+------------------------------------------------------------------+
| Syntax   | NXJOB (job\_ID, topjob\_ID)  or                                  |
|          |                                                                  |
|          | NXJOB (jobname, topjob\_ID)  or                                  |
|          |                                                                  |
|          | NXJOB (jobnr, jobtag, topjob\_ID)                                |
+----------+------------------------------------------------------------------+
| Location | Toolkit II                                                       |
+----------+------------------------------------------------------------------+

This function will work downwards through a 'job tree' to find all of
the current jobs which are both used by the given 'top job' and those
which are used by that second set of jobs. A job tree may look something
like this:

::

              SuperBASIC
                   |
      +------------+-----------+
      |            |           |
    EDITOR      QPAC-FILES    CLOCK
                   |
          +--------+----------+
          |                   |
        QUILL              ABACUS


A job can be referred to either by its name (eg. 'Quill'), its job number
and job tag (eg. 1,2) (shown by JOBS), or its job ID (a number
calculated by job\_number+65536\*job\_tag). These are always
interchangeable, so assuming there is a job 'Test' with job number 1 and
job tag 12.

::

    PRINT NXJOB ('Test',0)
    PRINT NXJOB (1,12,0)
    PRINT NXJOB (65548,0)

are all the same.

Note that the top job ID must not be the job's name
or job number and tag. You could, for instance, use::

    PRINT NXJOB(0,0)

to find that SuperBASIC is using the Job QPAC-FILES. You must now
follow that branch to its tip by using::

    PRINT NXJOB ('QPAC-FILES',0)

to find the job ID of Quill.

::

    PRINT NXJOB('Quill',0)

will then find the job ID of Abacus. Since Abacus is at the end of a
main branch,

::

    PRINT NXJOB('Abacus',0)

will find Clock.

Should you wish to merely find out which Jobs are used
by QPAC-FILES, you can do this by altering the topjob\_ID to the job\_ID
given for QPAC-FILES - eg::

    PRINT NXJOB('QPAC-FILES',65535)

**Example**

A short program to work out the whole job tree belonging to SuperBASIC.
This is very similar to the JOBS command, but displays the information
slightly differently::

    100 MODE 4
    110 a=0: b=0
    120 REPeat loop
    130   c=NXJOB(a,b)
    140   IF c=0: PRINT\'End of Job Table': STOP
    150   a=c: IF LEN(JOB$(c))=0:PRINT'ANONYMOUS';: ELSE PRINT JOB$(c);
    160   PRINT TO 15;'Priority = ';PJOB(c);
    170   IF OJOB(c)=0: own$='SuperBASIC': ELSE own$=JOB$(OJOB(c))
    180   PRINT TO 30;'Owner = ';own$
    190 END REPeat loop

**CROSS-REFERENCE**

:ref:`pjob`, :ref:`job-dlr`, and
:ref:`ojob` also deal with the job tree. For jobs in
general, see :ref:`jobs`,
:ref:`rjob`, :ref:`spjob`,
:ref:`sjob`, :ref:`ajob`.
