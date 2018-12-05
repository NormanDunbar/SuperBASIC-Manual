..  _dmedium-format:

DMEDIUM\_FORMAT
===============

+----------+------------------------------------------------------------------+
| Syntax   | DMEDIUM\_FORMAT [(#channel)] or                                  |
|          |                                                                  |
|          | DMEDIUM\_FORMAT (\\file)                                         |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns a number representing the operating system under
which the medium (or hard disk partition) on which the specified file or
directory is located (or to which the specified channel is open) was
created. If no parameter is specified, it looks to channel #3 (or #1 if
#3 is not open).

The values returned currently are:

- 1 QDOS or SMSQ or SMSQ/E
- 2 DOS or TOS


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 255.


**CROSS-REFERENCE**

:ref:`dir` will provide this imformation also on
Level-3 device drivers.
:ref:`dmedium-density` allows you to
check the medium's density. There is currently no way to format a disk
in a format other than QDOS or SMSQ/E without the ATARI\_rext commands
which were available with the ST/QL emulators from Jochen Merz, or
without specialist software (some of which is public domain).

--------------


