..  _kbd-use:

KBD\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  KBD\_USE [ser\_port]                                             |
+----------+-------------------------------------------------------------------+
| Location |  XKBD                                                             |
+----------+-------------------------------------------------------------------+

This command ensures that any incoming data from the specified serial
port (1 for ser1, 2 for ser2) is transformed into keystrokes. Thus other
computers or 8 bit keyboards can be used as an additional external
keyboard. Using the command without a parameter, or zero (eg. KBD\_USE
0) closes the ser channel and stops this operation.

**NOTE**

This task is carried out in the background of any other programs, but
does not actually create a job.

--------------


