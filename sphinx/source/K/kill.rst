..  _kill:

KILL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  KILL                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools, KILL                                                 |
+----------+-------------------------------------------------------------------+

This command will cause all current jobs, except the main SuperBASIC
interpreter (Job 0), to be stopped and removed from memory.

**Example**

The presence of jobs prevents the commands RESPR / LRESPR from grabbing
memory in the Resident Procedure Area (although some implementations
overcome this restriction, they do so by by allocating space in the
Common Heap) and because some machine code programs cannot or should not
be loaded into the common heap, the command KILL can be of assistance.

**WARNING**

Be sure that no important data gets lost!

**CROSS-REFERENCE**

:ref:`rjob` removes single jobs,
:ref:`kjobs` works in the same way as
:ref:`kill`.

--------------


