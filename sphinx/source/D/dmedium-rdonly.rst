..  _dmedium-rdonly:

DMEDIUM\_RDONLY
===============

+----------+------------------------------------------------------------------+
|Syntax    | DMEDIUM\_RDONLY [(#channel)] or                                  |
|          |                                                                  |
|          | DMEDIUM\_RDONLY (\\file)                                         |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns the value 1 (true) if the the medium on which the
specified file or directory is located (or to which the specified
channel is open) is write-protected either through hardware or software
control. If no parameter is specified, it looks to channel #3 (or #1 if
#3 is not open). If the medium can be written to, the value returned is
zero.


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 1.


**CROSS-REFERENCE**

See :ref:`dmedium-name-dlr` for an example.

--------------


