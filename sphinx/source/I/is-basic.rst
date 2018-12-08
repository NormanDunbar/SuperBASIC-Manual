..  _is-basic:

IS\_BASIC
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  IS\_BASIC                                                        |
+----------+-------------------------------------------------------------------+
| Location |  MULTI                                                            |
+----------+-------------------------------------------------------------------+

The function IS\_BASIC allows you to find out whether the SuperBASIC
program which executes the command is running under the interpreter or
has been compiled. This is done by returning the sum of the jobnumber
and the jobtag: the sum is 0 for the interpreter and a positive number
for a compiled job. So NOT IS\_BASIC is 1 under the interpreter and 0 in
a compiled program (or a MultiBASIC on Minerva or Multiple SBASIC under
SMS).

**Example**

If a compiler is available, programs are normally compiled for: - faster
loading - faster execution - possibly linking in Toolkits (QLiberator
only) - easier multitasking - operating system independent
code(QLiberator only) - shared code/hotkey execution (QLiberator only)
IS\_BASIC helps the programmer who uses the interpreter to develop
programs which distinguish between features which are only available in
compiled programs, for instance passing a command string::

    100 IF NOT IS_BASIC THEN
    110   CMD$="Test"
    120 ELSE
    130   INPUT CMD$
    140 END IF

**NOTE**

IS\_BASIC will fail to spot a MultiBASIC or SBASIC interpreter.

**CROSS-REFERENCE**

:ref:`prio` sets the priority of the current job.
Under SMS or Minerva, you can use
JOB_NAME$ to look at the name of the
task which would normally be SBASIC or have its first two letters as MB
respectively for a Multiple SBASIC or MultiBASIC interpreter, unless the
name of the Interpreter has been altered. Refer
to\ :ref:`job-name`.

