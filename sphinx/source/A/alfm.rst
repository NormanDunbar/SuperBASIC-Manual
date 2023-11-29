.. _alfm:

ALFM
====

+----------+-------------------------------------------------------------------+
| Syntax   | ALFM (bytes)                                                      |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                    |
+----------+-------------------------------------------------------------------+

This allocations a chunk of the available fast memory on a
Q68. Returns the starting address of the allocated memory on success
and an out of memory error on failure.

**Example**

::

   100 x=ALFM(1024)
   110 LBYTES win1_my_process,x
   120 CALL x

**Note 1**

Very little fast memory is available with some of it being used by
SMSQ/E. A freshly booted system should have about 10 kB.

**Note 2**

Like RESPR, allocated memory cannot be freed.

**CROSS-REFERENCE**

:ref:`respr`,
:ref:`free-fmem`
