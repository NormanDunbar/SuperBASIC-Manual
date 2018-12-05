..  _prog-use:

PROG\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROG\_USE default\_device                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The command PROG\_USE and dependent commands behave in the same way as
DATA\_USE with a few differences.

The program device set with PROG\_USE
is used by the EX (EXEC), EW (EXEC\_W) and (exceptionally SEXEC)
commands as the default device. Whereas some commands which use the data
device (eg. MERGE, LOAD) check the program device if they do not find a
given file on the data device, the above commands which use the program
device will not look at the data device should they fail on the program
device.

**NOTE**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to assign a longer string will result in the
error 'Bad Parameter' (error -15).

**CROSS-REFERENCE**

:ref:`progd-dlr` returns the program device setting.
See :ref:`data-use` for more information.

--------------


