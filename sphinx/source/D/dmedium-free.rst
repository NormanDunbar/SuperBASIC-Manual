..  _dmedium-free:

DMEDIUM\_FREE
=============

+----------+------------------------------------------------------------------+
| Syntax   | DMEDIUM\_FREE [(#channel)] or                                    |
|          |                                                                  |
|          | DMEDIUM\_FREE (\\file)                                           |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns the number of free sectors available on the
medium on which the specified file or directory is located, or to which
the specified channel is open. If no parameter is specified, it looks to
channel #3 (or #1 if #3 is not open).


**CROSS-REFERENCE**

:ref:`dmedium-total` allows you to find
out the total number of sectors available on the related medium.
:ref:`dir` can also be used to obtain this
information.

