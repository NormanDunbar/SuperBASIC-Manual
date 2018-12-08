..  _dmedium-type:

DMEDIUM\_TYPE
=============

+----------+------------------------------------------------------------------+
|          |                                                                  |
| Syntax   | DMEDIUM\_TYPE [(#channel)] or                                    |
|          | DMEDIUM\_TYPE (\\file)                                           |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns a number representing the type of drive on which
the specified file or directory is located (or to which the specified
channel is open). If no parameter is specified, it looks to channel #3
(or #1 if #3 is not open).

The values currently returned are:

- 0 RAM disk
- 1 Floppy disk drive
- 2 Hard disk drive
- 3 CD-ROM drive


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 255.


**CROSS-REFERENCE**

See :ref:`dmedium-name-dlr` for an example.

