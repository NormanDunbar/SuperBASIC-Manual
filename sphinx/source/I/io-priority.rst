..  _io-priority:

IO\_PRIORITY
============

+----------+-------------------------------------------------------------------+
| Syntax   |  IO\_PRIORITY level (level=1 to 1000)                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is used to set the priority of the In / Out retry
operations. This means that it affects the amount of time that the
scheduler will spend retrying IN / OUT operations (such as INKEY$ or
PRINT). Due to the QL's multitasking abilities, it is possible that a
program can be running in the background whilst you are doing something
else. If that program is trying to access a file or the Network port for
example, then it may find that there is no information waiting to be
read at the time and the scheduler will keep trying to access the file
or Network until that information is received. By using this command to
set a higher priority, the scheduler will allocate more time to doing
this and less time to running another job. IO\_PRIORITY 1is equivalent
to the way in which the scheduler worked on the original QL ROM.

