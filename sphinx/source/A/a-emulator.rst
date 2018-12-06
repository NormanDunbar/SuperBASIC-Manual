..  _a-emulator:

A\_EMULATOR
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_EMULATOR                                                      |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT v2.22+                                               |
+----------+-------------------------------------------------------------------+

This function returns a number to signify the type of ST/QL EMulator
which is being used with the Atari computer. The value returned may be
one of the following:

-  0 - QL Emulator (the original QL Emulator)
-  1 - Extended-Mode4 Emulator
-  2 - QVME Emulator

**NOTE 1**

This will only work with Level E-20 of the Drivers or later.

**NOTE 2**

It is impossible to tell whether the original QL Emulator supports MODE
8 or not.

**NOTE 3**

You can also use DISP\_TYPE to find out the Emulator type.

**CROSS-REFERENCE**

See also :ref:`processor` and
:ref:`machine`.

