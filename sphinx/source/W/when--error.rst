..  _when--error:

WHEN ERRor
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  WHEN ERRor                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM), THOR XVI                                       |
+----------+-------------------------------------------------------------------+

This command marks the beginning of the SuperBASIC structure which is
used to surround lines of SuperBASIC code which should be executed
whenever an error is generated whilst error trapping is active. Error
trapping is activated as soon as the interpreter reads a line containing
WHEN ERRor. It is therefore not activated by a WHEN ERRor command being
entered into the command window (#0) - indeed this has a special purpose
(see below). The syntax of the SuperBASIC structure can take two forms:

WHEN ERROR: statement :sup:`\*`\ [:statement]\ :sup:`\*`

or

WHEN ERROR  :sup:`\*`\ [statements]\ :sup:`\*` .. END WHEN

In the normal course of progress, the WHEN ERRor block would appear at
the start of a SuperBASIC program, and error trapping would therefore be
enabled as soon as a program is RUN. Once error trapping is enabled,
whenever an error is generated, control is passed to the WHEN ERRor
clause, allowing you to specify how it the error to be dealt with.

It must however be borne in mind that whilst active, errors will trigger
the WHEN ERRor clause whether they are generated whilst the program is
being RUN or at some other stage (eg. if a direct command causes an
error). If the interpreter comes across more than one WHEN ERRor
block, then the latest one is used to trap errors.

Errors generated
within the WHEN ERRor block itself are reported as normal, although the
message 'during WHEN processing' is displayed along with the error
message. Unless you include a STOP statement in the WHEN ERRor clause,
after going through all of the lines within the clause, the program will
continue running from the statement following the one which caused the
error.

You can force this to happen with CONTINUE, whereas RETRY can be
used to re-execute the command which caused the error. Error trapping is
turned off by the command WHEN ERRor (when entered as a direct command),
and also when the NEW, CLEAR, LOAD, LRUN, MERGE, and MRUN commands are
issued.

**Example**

A program which provides a fully error trapped educational aid::

    100 WHEN ERRor
    110   STRIP#0,2
    120   IF ERR_XP
    130     PRINT#0,'Please enter a number!'\'Press a key'
    140     PAUSE:STRIP #0,0:RETRY 320
    150   END IF
    160   IF ERR_OV
    170     PRINT#0,'Divide by zero is undefined!'\'Press a key'
    180     PAUSE:STRIP #0,0:RETRY 320
    190   END IF
    200   STRIP #0,0
    210   PRINT #0,'At line: ';ERLIN:REPORT:STOP
    220 END WHEN
    225 :
    230 MODE 8
    240 WINDOW 448,200,32,16:PAPER 0:INK 6:CLS
    250 WINDOW #0,448,40,32,216:PAPER#0,0:INK#0,7:CLS#0
    260 CSIZE 2,0:AT 8,8:PRINT 'Maths Division Tutor'
    270 CSIZE 1,0
    280 REPeat loop
    290   y=RND(1 TO 10):x=RND(1 TO 10)*y
    300   IF y>x:ya=x:x=y:y=ya
    310   IF RND>.9:x=0:y=0
    320   REPeat answer
    330     AT 10,0:CLS 2:AT 11,0:CLS#0
    340     INPUT 'Enter number to divide'!(x)!'by to give'!(y)!': ';a
    350     IF x/a=y THEN EXIT answer
    360     PRINT \\'Wrong - Please try again'\'Press a key'
    370     PAUSE
    380   END REPeat answer
    390   PRINT \\'Correct - Another one...'\'Press a key'
    400   PAUSE
    410 END REPeat loop

**NOTE 1**

This SuperBASIC structure does not work very reliably on any QL versions
other than Minerva v1.77 (or later), SMS or the THOR XVI: although
Toolkit II improves the reliability, problems include crashing the
machine if an error is generated inside a function whilst error trapping
is enabled {eg. PRINT SQRT(-1)}, or if you try to carry out INKEY$ at
the end of a file. WHEN ERRor clauses will also remain in force despite
NEW, CLEAR, LRUN, LOAD, MERGE and MRUN.

**NOTE 2**

WHEN ERRor cannot trap the Break key <CTRL><SPACE> (and <ESC> on
Minerva), which will continue to stop a SuperBASIC program.

**NOTE 3**

You should not try to nest several WHEN ERRor clauses - under SMS the
error 'WHEN clauses may not be nested' is reported.

**SMS NOTE**

Even in the in-line version of WHEN ERRor it is imperative that END WHEN
is specified, otherwise the error 'Incomplete WHEN clause' will be
reported.

**CROSS-REFERENCE**

:ref:`erlin` returns the line number on which the
error occurred. :ref:`ernum` returns the error
number itself. There are several functions in the form
:ref:`err-...` which return 1 if the given error
has occurred. :ref:`break-off` allows you to
turn the Break key off. :ref:`end--when` defines
the end of the error handling block.

--------------


