..  _jbase:

JBASE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  JBASE ( {jobnr \| jobname} )                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Each running job has a job header where information such as the job's
priority is stored. Usually, the SuperBASIC programmer should read these
settings by using JOBS, PJOB, OJOB etc, and change them with SPJOB, AJOB etc.

However, for some purposes
it might be interesting to access a job header directly - hence this
function.

The function JBASE takes either a job number or job name and
returns the start address of where its job header is stored. JBASE
breaks with error -2 (unknown job) if the parameter does not point to a
job. The jobname need not appear in quotes (unless it is also the name
of a SuperBASIC variable, procedure or function).

As from v1.11, the
jobnr can be -1 which will return the base address of the current job.

The following parts of the job header are interesting from the
SuperBASIC aspect, but please see system documentation for more details:

+--------+--------+-------------------------------------------------------------------------------+
| Offset | Length | Meaning                                                                       |
+========+========+===============================================================================+
| 0..3   | 4      | Total length of job area                                                      |
+--------+--------+-------------------------------------------------------------------------------+
| 4..7   | 4      | Job start address                                                             |
+--------+--------+-------------------------------------------------------------------------------+
| 8..11  | 4      | Job ID of parent job (0 if none)                                              |
+--------+--------+-------------------------------------------------------------------------------+
| 12..15 | 4      | Address of job Released Flag (0 if Job released)                              |
+--------+--------+-------------------------------------------------------------------------------+
| 16..17 | 2      | Job tag                                                                       |
+--------+--------+-------------------------------------------------------------------------------+
| 19     | 1      | Priority (Only on original QL ROMs and Minerva and Thor XVI)                  |
+--------+--------+-------------------------------------------------------------------------------+
| 20..21 | 2      | Job status (0 active, >0 timeout, -1 suspended, -2 waiting)                   |
+--------+--------+-------------------------------------------------------------------------------+
| 23     | 1      | Wait flag (bit 7 set if another job is waiting for this job) (not under SMS2) |
+--------+--------+-------------------------------------------------------------------------------+
| 24..27 | 4      | Job ID of that waiting job                                                    |
+--------+--------+-------------------------------------------------------------------------------+

**Example**

This program lists all running jobs by name, occupied memory and status::


    100 CLEAR: CLS: id=0: UNDER 1
    110 PRINT "Job";TO 20;"Size";TO 25;"Status"
    120 UNDER 0
    130 REPeat job_list
    140   id = NXJOB(id,0)
    150   IF NOT id THEN EXIT job_list
    160   name$=JOB$(id)
    170   IF name$="" THEN name$="<anonymous>"
    180   nr=id-65536*INT(id/65536)
    190   base=JBASE(nr*(nr=nr))
    200   length=1+INT(CVL(PEEK$(base,4))/1024)
    210   status=CVI%(PEEK$(base+20,2))
    220   SELect ON status
    230     =0 TO 32767: timeout=INT(20*status)
    240        status$="inactive for "&timeout&" ms"
    250     =-1: status$="suspended"
    260     =-2: status$="waiting"
    270     =REMAINDER : status$="undefined"
    280   END SELect
    290   PRINT name$;TO 20;length;"k";TO 25;status$
    300 END REPeat job_list

**NOTE 1**

JBASE returns an undefined value if the parameter used to be a job
number but that job has already been removed. For example, create a job
with CLOCK #1 and look up its number with JOBS:
::

    Job Tag Owner Priority
    0   0   0     32
    4   8   0     s1 Clock

Enter the command::

    PRINT JBASE(4)

or::

    PRINT JBASE('clock')

and see the result.

Now kill the job with KJOB 4 and check with JOBS if it has really gone::

    Job Tag Owner Priority
    0   0   0     32

The job is dead but PRINT JBASE(4) still returns something - usually that
number will be negative.

**NOTE 2**

JBASE sometimes behaves oddly due to rounding errors. Before v1.11,
JBASE would report an 'invalid job' error if you used a variable to
supply the job number (even if that variable pointed to an existing
job). The example above shows how the problem can be easily
circumvented: use JBASE (nr\*(nr=nr)) instead of JBASE (nr) -
this converts the variable into an expression.

**CROSS-REFERENCE**

:ref:`jobs`, :ref:`sjob`,
:ref:`ajob`, :ref:`nxjob`. See
:ref:`jobcbs` which corrects all of the problems
associated with :ref:`jbase`. Details of Job Headers
can be found in the QDOS/SMS Reference Manual Section 18 p8.

