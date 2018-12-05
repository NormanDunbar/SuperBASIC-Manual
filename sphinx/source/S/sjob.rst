..  _sjob:

SJOB
====

+----------+------------------------------------------------------------------+
| Syntax   | SJOB jobnr,timeout  or                                           |
|          |                                                                  |
|          | SJOB jobname,timeout                                             |
+----------+------------------------------------------------------------------+
| Location | TinyToolkit                                                      |
+----------+------------------------------------------------------------------+

There are three ways in which a job can be made to do nothing:

#. Remove the job;
#. Set the job's priority to 0;
#. Suspend the job.

This command suspends the specified job for a specified period of time,
which can be identified either by its jobnr (see JOBS) or by -1 (meaning
the current job) or by its name (which need not be in quotes). Although
suspending a job does not alter its priority, a suspended job will have
no effect upon the speed of the QL. A positive timeout will stop the Job
for timeout/50 seconds, whereas any negative number will suspend the job
forever (ie. it can only be re-activated by an express command such as
REL\_JOB). The highest positive timeout is 32768 frames which is
approximately 9 minutes, 6 seconds.

**Example 1**

::

    SJOB "Quill", -1

will suspend Quill indefinitely.

::

    SJOB Quill,-1

is the same even if there is a variable called Quill.

::

    SJOB -1, 100

will suspend the current job for approx. 2 seconds.

::

    SJOB 10, 100

will suspend Job number 10 for approx. 2 seconds

**Example 2**

A background Job which carries out work which is not time consuming,
should not slow the whole system down, otherwise it is a complete waste
of the computer's available time. Unfortunately, a priority of 1 is too
high for a simple action such as checking the clock or updating key
macros (See ALTKEY).

SJOB is useful to slow this job down to the desired
speed. SJOB is also useful for setting PAUSEs independently of the
machine's speed. The following program demonstrates both uses of SJOB
and has to be compiled and executed as a multitasking job (ie. EXEC).

The priority of the job does not really matter, because the job only
wakes up once a minute, looks at the clock and then drops off again.

::

    100 REPeat Tower
    110   d$=DATE$: minute=d$(16 TO 17)
    120   SELect ON minute
    130     =30:BEEP 20000,0,100,1000,0
    140     =0:hour=d$(13 TO 14) MOD 12:IF hour=0:hour=12
    150         FOR h=1 to hour: BEEP 10000,h,10,100,1: SJOB Q_MYJOB,65
    160     =15:BEEP 5000,0,10,20,5000
    170   END SELect
    180   SJOB Q_MYJOB,3000
    190 END REPeat Tower

This example needs Qliberator's Q\_MYJOB function.

**NOTE**

As from v1.11, jobnr can be -1, so in the above example 2, you could use
SJOB -1,65 and SJOB -1,3000 instead of the similar commands in lines 150
and 180 respectively. Earlier versions would also not accept a variable
as the parameter for the job number.

**CROSS-REFERENCE**

:ref:`rel-job` releases a suspended job.
:ref:`jobs` lists all current jobs.
:ref:`susjob` and :ref:`ttsus`
are almost the same as :ref:`sjob`.

--------------


