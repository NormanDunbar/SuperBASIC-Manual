..  _mtrap:

MTRAP
=====

+----------+------------------------------------------------------------------+
| Syntax   | MTRAP key [,d1 [,d2 [,d3 [,a0 [,a1 ]]]]] or                      |
|          |                                                                  |
|          | MTRAP key\\jobnr [,d2 [,d3 [,a0 [,a1 ]]]]]                       |
+----------+------------------------------------------------------------------+
| Location | TRAPS (DIY Toolkit Vol T)                                        |
+----------+------------------------------------------------------------------+

This command is similar to QTRAP in that it allows you to access the
machine code TRAP #1 system calls directly. Unless you are using the
second variant, you will need to pass at least one parameter, the
operation key to be carried out (this is equivalent to the value in D0
when TRAP #1 is performed). The other parameters allow you to pass the
various register values which may be required by the system calls.

The
second variant is useful for when you are using a TRAP #1 call which
requires a job ID - you can merely pass the jobnr of the required job,
obtained from the JOBS list (rather than having to set D1 to the Job
ID). For example to force remove Job 12, use the command::

    MTRAP 5\12,0,0

**WARNING**

Several TRAP #1 calls can crash the computer - make certain that you
know what you are doing!

**CROSS-REFERENCE**

See :ref:`io-trap`,
:ref:`qtrap` and :ref:`btrap`.
:ref:`remove-task` and
:ref:`rjob` are better for removing Jobs. Any return
parameters can be read with :ref:`datareg` and
:ref:`addreg`. Refer to the QDOS/SMS Reference
Manual (Section 15) for details of the various system TRAP #3 calls.

