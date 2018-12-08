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

