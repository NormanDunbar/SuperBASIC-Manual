..  _cls:

CLS
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CLS [#chan,] [cls\_type]                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is normally used to clear all or part of the specified
window (default #1) to the current paper colour for that channel (this
is not affected by OVER). CLS does not affect a border attached to a
window.

The cls\_type can be used to specify which area of the window is to be
cleared (the default is 0). This can have the following standard values,
which have different effects depending upon the current position of the
text cursor:

-  0 Clear the whole window
-  1 Clear the window above the cursor line
-  2 Clear the window below the cursor line
-  3 Clear the whole cursor line
-  4 Clear the window from the cursor position to the right-hand end of
   the cursor line

After using this command, the text cursor is placed at the top left-hand
corner of the window (if cls\_type=0) or at the current cursor position for other values.

Except under SMS and on the THOR XVI, most systems allow you to use
other values for cls\_type to access various TRAP #3 system utilities.
The way in which the appropriate value of cls\_type is calculated is by
taking the value of D0 which would be used in machine code and
subtracting 32 from this. If this gives a negative result, then add this
negative result to 128.

For example, to move the cursor back one space, in machine code you
would use the call IOW.PCOL (D0=19). 19-32=-13, therefore:

CLS #3,128-13 moves the cursor back one space in #3.

You must however be aware of using CLS 98 (IO.FLINE) on pre JS ROMs,
since this tended to leave the cursor switched on!

**NOTE 1**

On pre MG ROMs CLS is likely to fail if the window is smaller than the
cursor.

**NOTE 2**

The THOR XVI only allows cls\_type to be in the range 0..4.

Under SMS, if cls\_type is more than 4, then CLS uses cls\_type MOD 4.

**NOTE 3**

Some of the additional values of cls\_type can actually cause the
computer to crash, whilst others will merely report an error.

**CROSS-REFERENCE**

:ref:`at` and :ref:`print` position
the text cursor.

:ref:`paper` alters the current paper colour.

:ref:`scroll` and :ref:`pan` also
allow you to access various system utilities.

A much safer way to access system utilities is to use
:ref:`io-trap`, :ref:`mtrap`,
:ref:`qtrap` and :ref:`btrap`.

For details of the various TRAP #3 system utilities refer to the
QDOS/SMS Reference Manual (Section 15) or similar.

