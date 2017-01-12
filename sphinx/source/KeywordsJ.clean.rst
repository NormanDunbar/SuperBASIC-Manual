==========
Keywords J
==========


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

--------------


..  _jobcbs:

JobCBS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  JobCBS ( {jobnr \| jobname} )                                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function is identical to JBASE, but the problems mentioned in the
notes above do not exist with JobCBS. Alas, it will not accept a jobnr
of -1 in current versions.

--------------


..  _jobs:

JOBS
====

+----------+-------------------------------------------------------------------+
| Syntax   || JOBS [#channel]   or                                             |
|          || JOBS \\file                                                      |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command lists all jobs currently loaded into the QL to the given
channel (default #1). Five pieces of information are given: jobnumber
(job), tag, owner, priority and jobname

JobNumber / Tag
    The jobnumber and the jobtag are internally combined to form the job-ID
    (jobnumber+tag\*2^16) in order to identify jobs.

Owner
    The Owner of a job is not necessarily the job which started it nor must
    it be connected with it. If a job is removed, all jobs owned by it will
    disappear too.

Priority
    The higher the Priority of a job, the more processor time is given to it
    and therefore the faster it runs. 

    An "s" in front of the priority means
    that the job is currently suspended, so the priority does not matter.

Jobname
    The jobname is another method of identifying the job, being the name
    given to the job when it was programmed.

**NOTE 1**

If the second syntax does not work, you should update your Toolkit
version.

**NOTE 2**

Minerva users will be dismayed to learn that current versions of this
command do not display negative priorities.

**CROSS-REFERENCE**

Commands like :ref:`rjob`,
:ref:`spjob`, :ref:`rel-job`,
:ref:`job-name`
and :ref:`sjob` change job settings;
:ref:`job-dlr`, :ref:`ojob`,
:ref:`nxjob`, :ref:`pjob` return
the same information as appears on the :ref:`jobs`
list for single jobs. :ref:`list-tasks` is
similar.

--------------


..  _job-dlr:

JOB$
====

+----------+-------------------------------------------------------------------+
| Syntax   || JOB$ (job\_ID)  or                                               |
|          || JOB$ (jobnr,tag)  or                                             |
|          || JOB$ (jobname)                                                   |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

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

--------------


..  _job-name:

JOB\_NAME
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  JOB\_NAME title$                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

Although most Jobs have a name given to them by the programmer, there
are three main exceptions to this rule: 

- Minerva MultiBASICs have a job name beginning with the two letters 'SB' followed by a number. 

- The main SuperBASIC interpreter has a job name equivalent to a null
  string ("") means that no name is shown under the JOBS command. QPAC 2
  changes this in its menus to 'SuperBASIC' to identify this Job. You will
  also notice that when you put Job 0 to sleep (using <ALT><SHIFT><F1> ),
  under SMS the Button is given the name 'System'. 

- SMS's multiple SBASIC interpreters are all given the name SBASIC and there is no way of distinguishing one copy from another. 


This command allows you to set the
name of a multiple SBASIC job under SMS to the specified title$. It has
no effect on a compiled program, or on the main Interpreter (Job 0).

**Example**

It can be necessary to include code within a program which caters for
different situations depending on whether the program is being run under
an Interpreter or has been compiled. It is not sufficient to test the
name of the job, nor the job number, as this can be different on various
setups. Luckily, both Minerva and SMS allow you to discover whether a
Job is an interpreter (other than Job 0). 

- Minerva sets bit 6 in offset HEX('16') of the Job's Header; 
- SMS places the four letters 'SBAS' at offset HEX('1E4') of the Job's header. 

The following example uses these
facts to decide what setup the program is running on::

    100 vs$=VER$:prog_name$='TESTER' 
    110 IS_COMPILED=0:pass$='' 
    120 IF vs$<>'HBA' AND vs$<>'JSL1' 
    130 IF JOB$(-1)<>'':IS_COMPILED=1 
    140 ELSE
    145   IF JOB$(-1)<>'' 
    146     TJob=JBASE(-1) 
    147     IF vs$='HBA' 
    150       JOB_NAME prog_name$ 
    160       IF PEEK$(TJob+HEX('1e4'),4)<>'SBAS': IS_COMPILED=1 
    165     ELSE 
    170       TByte=PEEK(TJob+HEX('16')) 
    180       IF NOT (TByte && 2^6): IS_COMPILED=1 
    182     END IF 
    185   END IF 
    190 END IF 
    200 IF IS_COMPILED 
    210   OPEN #1,con_448x200a32x16:PAPER 0:CLS 
    220   PRINT 'This program has been compiled' 
    230   pass$=cmd$ 
    240 ELSE 
    250   IF JOB$(-1)<>'' 
    260     OPEN #1,con_448x200a32x16 
    270   ELSE 
    280     WINDOW 448,200,32,16 
    290   END IF 
    300   PAPER 0:CLS:PRINT 'This program is running under an interpreter.' 
    310   IF JOB$(-1)='' 
    320     INPUT 'Enter Command String: ';pass$ 
    330   ELSE 
    340     pass$=cmd$ 
    345     IF pass$='':INPUT 'Enter Command String: ';pass$ 
    350   END IF 
    360 END IF 
    370 IF pass$='':pass$='UNDEFINED' 
    380 PRINT 'Command String was ';pass$ 
    390 PAUSE 
    400 IF IS_COMPILED=0:IF JOB$(-1)=prog_name$:QUIT 
    410 IF IS_COMPILED=0:IF JOB$(-1)<>'':CLOSE #1

Unfortunately, we do not know of any way of testing whether a
MultiBASIC or multiple SBASIC interpreter was started up using the EX
command or not (if not, then the CMD$ will need to be entered).

**CROSS-REFERENCE**

See :ref:`sbasic` and :ref:`mb`,
about the multiple interpreters provided by Minerva and SMS.
:ref:`jobs` and :ref:`nxjob`
contain more information on current jobs. Compilers normally include
their own methods of setting the correct job name. You may want to use
:ref:`devtype` to test if a channel is open if a
program is to run correctly under both Job 0 and a multiple SBASIC.

