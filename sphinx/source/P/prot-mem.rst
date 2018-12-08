..  _prot-mem:

PROT\_MEM
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROT\_MEM level                                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

The command PROT\_MEM can be used to set the level of memory protection
which is afforded on Atari ST and TT computers, to try and stop the user
from altering essential areas of the operating system by mistake. There
are five levels of memory protection currently available:

..  tabularcolumns::    |c|p{.8\textwidth}|

+-------+---------------------------------------------------------------------+
| Level | Protection                                                          |
+=======+=====================================================================+
| 0     | Memory access faults are not reported.                              |
+-------+---------------------------------------------------------------------+
| 1     | Write memory access faults are trapped from all jobs except from    |
|       | Job 0. Read operations from a protected area read 0.                |
+-------+---------------------------------------------------------------------+
| 2     | Read memory access faults are trapped from all jobs except Job 0.   |
|       | Any Write operations to a protected area are ignored.               |
+-------+---------------------------------------------------------------------+
| 3     | Both Read and Write memory access faults are trapped from all jobs  |
|       | except Job 0.                                                       |
+-------+---------------------------------------------------------------------+
| 7     | Both Read and Write memory access faults are trapped from all jobs. |
+-------+---------------------------------------------------------------------+

The default level is 3.

We would recommend that Level 0 is
avoided if at all possible. Memory access faults tend to occur when the
user (or a program) tries to access memory which does not exist or can
only be accessed in Supervisor Mode (the vector area, the TOS system
variables and the IO hardware). However, under SMSQ/E, if there is an
attempt to read an address which actually forms part of the legitimate
QL vector area, this will not cause a fault. If a memory access fault is
trapped, the Job which has caused the fault is paused and the program
counter is placed on the stack (all registers are preserved). An
advanced user may then use a debugger to examine the Job to find out
what has caused the fault.

**NOTE**

Unfortunately, on other implementations, this command has no effect, and
it is therefore still possible to overwrite the operating system on QL
Emulators (non-Atari based), Gold and Super Gold Cards.

**CROSS-REFERENCE**

See :ref:`pokes` and
:ref:`peeks`.
:ref:`prot-date` protects a battery backed
clock.

