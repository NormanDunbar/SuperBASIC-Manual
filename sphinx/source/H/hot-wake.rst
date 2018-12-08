..  _hot-wake:

HOT\_WAKE
=========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_WAKE (key$,Jobname$ [;cmd$] [,Jobname$])  or                |
|          |                                                                  |
|          | HOT\_WAKE (key$,Jobname$ [;cmd$] !Wakename$)                     |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

Many programs which have been written to use the Pointer Environment
will recognise what is known as a WAKE event - this defines something
that the program should do once control is returned to the program, for
example, updating its tables.

Whereas PICKing a job merely brings it to
the top of the pile ready for use, when you WAKE a job, not only is it
brought to the top of the pile, but also a WAKE event is executed (if
supported). You should therefore WAKE any program which provides
information on the current state of the computer or SuperBasic program
for example.

The function HOT\_WAKE allows you to set up a hotkey which
will Wake the specified Jobname$ if a copy of the program is already
being executed. However, if there is not already a copy of the specified
Job being executed, the hotkey will then look for an Executable Thing
with the same name as Jobname$
(which should therefore be specified in full), which, if found, will be
executed by the hotkey, creating a new copy of the program.

As with the
other hotkey commands, a command string can be passed to the program
when it is executed (this will be ignored if the program is merely
woken).

As with HOT\_CHP1, HOT\_RES1 and HOT\_LOAD1, you can specify a
Wakename$ which allows you to use the Hotkey to access two jobs, if at
least the first Job (or Executable thing) exists then the Hotkey will do
one of two things:

- If there is a current job called Wakename$, then this will be woken; otherwise;
- The first Job (or Executable Thing) will be Woken if it exists (or otherwise will be started up).

HOT\_WAKE is ideally suited for programs where you would not want more than one copy
to be executed at any one time (eg. a calendar program).

**Example**

Some users prefer to be able to have a choice between either Waking an
existing copy of a program (or executing the first copy) and loading
another copy of the program at a later stage. This can be achieved, for
example, with::

    ERT HOT_RES ('Q',flp1_QUILL,'QUILL')
    ERT HOT_WAKE ('q','QUILL')

**NOTE**

Versions of the Hotkey System prior v2.21 do not allow you to pass a
command string. You also need v2.24+ to pass a job name.

**CROSS-REFERENCE**

:ref:`hot-pick` allows you to define a hotkey to
PICK an existing Job.

