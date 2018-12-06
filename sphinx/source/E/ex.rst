..  _ex:

EX
==

+----------+-------------------------------------------------------------------------------+
| Syntax   |  EX file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*` [;cmd$] |
+----------+-------------------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                                         |
+----------+-------------------------------------------------------------------------------+

This command forces the given file (which must be an executable program) to be
executed and control is then generally returned to the calling program to enable
the new job to multitask alongside the calling program. Similar parameters as
for :ref:`ew` can be passed to the job.

Use :ref:`ew` if the program cannot multitask for some reason or if you do not want it to, for example,
because you want to see any error messages returned by the executable task. EX doesn't report them,
it cannot as the executable task may still be running when EX returns to the command prompt.

**Example 1**

::

    EX QED;"readme_txt"

The QED editor will be started from the default program device and told to
load the file readme\_txt from the editor's default device.

**Example 2**

::

    EX UC_obj,ram1_hope_lis,par

A program called UC\_obj (a program which converts text to all upper
case) will be started up to run alongside all other programs. Two n:ref:`ew`
channels ('ram1\_hope\_lis' and 'par') are opened for the task to use
for its input and output channels respectively - the task must not open
its own channels but will rely upon the user supplying them as
parameters.

The BASIC version of such a program is::

    110 REPeat loop
    120 IF EOF(#0) THEN EXIT loop
    130 INPUT #0,a$
    140 IF a$='' THEN NEXT loop
    150 FOR i=1 TO LEN(a$)
    160   IF CODE(a$(i))>96 AND CODE(a$(i))<123 THEN
    170     a$(i)=CHR$(CODE(a$(i))-32)
    180   END IF
    190 END FOR i
    200 PRINT#1,a$
    210 END REPeat loop

Turbo users will need to alter #0 and #1 to #15 and #14 respectively.

Minerva and SMS users can use this program without compiling it (see :ref:`ew`
above).

**Using EX to set up filters**

It is actually quite simple to create a multitasking environment on the
QL using the EX command to set up several programs all of which will
process a given file (or data entered into a given channel) in turn.

The
syntax for this version of the command is:

    EX jobparams\ :sup:`1`:sup:`\*`\ [TO jobparams\ :sup:`i`]\ :sup:`\*` [TO #chan\ :sup:`0`]

where jobparams represents the same parameters as are available for the
normal EX command, being:

    file :sup:`\*`\ [,{file\ :sup:`x` \|#ch\ :sup:`x`}]\ :sup:`\*` [;cmd$]

What this actually does, is to set up
a chain of jobs or channels whereby one extra channel is opened for each
job to form the output channel for the job on the left of the TO and
another channel is opened to form the input channel of the job on the
right of the TO.

Where a channel number appears at the end of the line
(after a TO), this is taken as being the final output channel and
nothing further can be done to the original input.

**Examples**

How about extending the Upper case conversion 'filter' so that a given
text file is then printed out one line at a time with each line being
printed out as normal, but then printed again, but this time backwards!

First of all, the program to do the printing::

    110 REPeat loop
    120   IF EOF(#0): EXIT loop: REMark Turbo uses #15, not #0
    130   INPUT #0,a$:PRINT#1,a$: REMark Turbo uses #14, not #1
    140   IF CMD$=='y': REMark Turbo users use OPTION_CMD$
    150   IF a$='':NEXT loop
    160   FOR lop=LEN(a$) TO 1 STEP -1
    170     PRINT#1,a$(lop);
    180   END FOR lop
    190   PRINT#1
    200   END IF
    210 END REPeat loop

Compile this program and save the compiled version as flp1\_Back\_obj.

Now to carry out the desired task::

    OPEN #3,con
    EX flp1_uc_obj,flp1_test_txt TO flp1_back_obj,#3;'y'

On Minerva v1.93+, you could use::

    OPEN #3,con
    EX pipep,flp1_test_txt;'flp1_uc_bas>' TO pipep,#3;'flp1_back_bas>y'

Or on SMS::

    OPEN #3,con
    EX flp1_uc_bas,flp1_test_txt TO flp1_back_bas,#3;'y'

How about trying this::

    OPEN #3,con
    EX flp1_uc_obj,flp1_test_txt TO flp1_back_obj;'y' TO flp1_back_obj,#3;'y'

**NOTE 1**

On pre JS ROMs, you may find that if you EX a new Job whilst there is
already one Job in progress, the ink and paper colours of the first Job
are set to zero. This is a problem unless you have a key to redraw the
screen for the first Job (or the Pointer Interface).

**NOTE 2**

The THOR XVI always ensures that cursor control is passed to the new Job
on start-up rather than returning to the calling Job.

**MINERVA NOTE**

Please refer to notes about :ref:`ew` which explain how to use this command to
control MultiBASICs.

**SMS NOTE**

Please refer to notes about :ref:`ew` and use this command to control multiple
SBASICs.

**CROSS-REFERENCE**

Use :ref:`ftyp` or
:ref:`file-type` to check if a file is
executable. :ref:`fdat` returns the dataspace of an
executable file, :ref:`fxtra` provides other
information. :ref:`et` is very similar to
:ref:`ex`.

