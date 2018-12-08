..  _lpoll:

LPOLL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LPOLL [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command lists all polling interrupts and their link pointers to
the given channel (default #1). While this text was being written, LPOLL
produced the following list::

    List of polled tasks:
    Link Pointer   Routine
    1.   $0002B5D8 $000C1434
    2.   $0002B8B8 $0009E0C2
    3.   $0002CAAA $000BD056
    4.   $0002B840 $0009E988

To understand these numbers, a deep knowledge of
assembly language and the operating system is necessary. Generally, each
interrupt is a kind of background job which does not appear in the job
list. For further information, refer to system documentation.

**CROSS-REFERENCE**

:ref:`lschd` and :ref:`lint2`
list other internal routines which are running in the interrupts.
:ref:`jobs` lists all jobs.

