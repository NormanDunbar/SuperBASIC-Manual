..  _mrun:

MRUN
====

+----------+------------------------------------------------------------------+
| Syntax   | MRUN device\_filename  or                                        |
|          |                                                                  |
|          | MRUN [device\_]filename (Toolkit II)                             |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command is similar to MERGE except that once the two programs have
been merged, if MRUN was issued as a direct command, then the merged
program is RUN from line 1. However, if MRUN was used from within the
program, the statement following the MRUN statement is executed, thus
making this command the same as MERGE when used within a program.

**CROSS-REFERENCE**

See :ref:`merge`!

