..  _dmedium-remove:

DMEDIUM\_REMOVE
===============

+----------+------------------------------------------------------------------+
| Syntax   | DMEDIUM\_REMOVE [(#channel)] or                                  |
|          |                                                                  |
|          | DMEDIUM\_REMOVE (\\file)                                         |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns the value 1 (true) if the medium on which the
specified file or directory is located (or to which the specified
channel is open) is a removable hard disk. Otherwise it returns 0
(false). If no parameter is specified, it looks to channel #3 (or #1 if
#3 is not open).


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 1.


**CROSS-REFERENCE**

:ref:`dmedium-rdonly` allows you to check
if a disk is write- protected. There do not appear to be any ways in
which you can check if any channels are currently open to the medium
(ie. whether it is safe to remove the disk), except for listing all
currently open channels, see :ref:`channels`.

