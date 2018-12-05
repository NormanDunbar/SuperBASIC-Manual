..  _stop:

STOP
====

+----------+-------------------------------------------------------------------+
| Syntax   |  STOP                                                             |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This command forces an interpreted program to be terminated at the
position where STOP appears in the listing. The program can then be
continued (provided that the message 'PROC/FN cleared' has not appeared)
by using the command CONTINUE. Compiled programs terminate and remove
themselves when STOP is encountered.

**Example**

This program will print 1 and 2 to channel #1 and stop at line 120. If
it runs under the interpreter, CONTINUE will restart at line 130 (after
STOP) and print 3 and 4. RETRY does not continue here because it tries
to re-run line 120 and stops again.

::

    100 PRINT 1
    110 PRINT 2
    120 STOP
    130 PRINT 3
    140 PRINT 4

**NOTE**

If Toolkit II is installed, STOP clears WHEN ERRor definitions.

**CROSS-REFERENCE**

:ref:`run` starts a program and :ref:`go--to` jumps to a specified line. See
:ref:`continue`, :ref:`retry`. Also see :ref:`quit`.

--------------


