..  _dmedium-total:

DMEDIUM\_TOTAL
==============

+----------+------------------------------------------------------------------+
| Syntax   | DMEDIUM\_TOTAL [(#channel)] or                                   |
|          |                                                                  |
|          | DMEDIUM\_TOTAL (\\file)                                          |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns the number of total sectors available on the
medium on which the specified file or directory is located, or to which
the specified channel is open. If no parameter is specified, it looks to
channel #3 (or #1 if #3 is not open).


**CROSS-REFERENCE**

:ref:`dmedium-free` allows you to find out
the number of sectors which currently do not contain any data on the
related medium. :ref:`dir` can also be used to obtain
this information. :ref:`format` releases all
sectors on a disk, marking any which may be corrupt as unavailable.

