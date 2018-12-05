..  _pie-ex-off:

PIE\_EX\_OFF
============

+----------+-------------------------------------------------------------------+
| Syntax   |  PIE\_EX\_OFF                                                     |
+----------+-------------------------------------------------------------------+
| Location |  PIE                                                              |
+----------+-------------------------------------------------------------------+

PIE\_ON contains details about what PIE is used for and you should
first of all refer to that.

Presuming that PIE is enabled (with
PIE\_ON), you may want to treat any programs (or toolkits) which use
SD.EXTOP machine code calls to access the screen differently.

Normally,
the Window Manager halts any program which attempts to call the SD.EXTOP
machine code routine unless that program does not have any buried
windows. However, PIE\_ON allows all buried programs to continue in the
background, storing the changes to the screen as necessary.

However,
SD.EXTOP routines may be used for various purposes including writing to
the screen directly and for this reason, if PIE is active, you may find
that a program writes to the screen using SD.EXTOP even though its
windows are buried (thus overwriting part of an existing program's
display).

PIE\_EX\_OFF prevents this effect by still halting any program
which attempts to use SD.EXTOP.

**CROSS-REFERENCE**

See :ref:`pie-on` and
:ref:`pie-ex-on`. See also
:ref:`pxoff` which is similar.

--------------


