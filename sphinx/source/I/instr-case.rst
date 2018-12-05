..  _instr-case:

INSTR\_CASE
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  INSTR\_CASE flag                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.58+                                                    |
+----------+-------------------------------------------------------------------+

Normally the INSTR operator carries out a non-case sensitive search.
This command allows you to specify that the search should be case
sensitive (if flag=1) or revert to the old system (if flag=0).

**Example**

::

    INSTR_CASE 1
    PRINT 'Hello' INSTR 'HELLO'

will return 0

::

    INSTR_CASE 0
    PRINT 'Hello' INSTR 'HELLO'

will return 1

**NOTE 1**

This command does not seem to have any effect on the speed of the INSTR
operator.

**NOTE 2**

The setting of INSTR\_CASE is cleared (to non-case sensitive) following
NEW, LOAD, MERGE, LRUN, RUN, MRUN.

**CROSS-REFERENCE**

See :ref:`instr`.

--------------


