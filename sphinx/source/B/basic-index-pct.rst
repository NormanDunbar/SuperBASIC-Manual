..  _basic-index-pct:

BASIC\_INDEX%
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_INDEX% (name$)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is similar to LOOKUP%, except it does not suffer with any
problems under SMS.

If the specified name$ does not exist, -12 is returned. -7 is returned
if there is some mismatch between table entries.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_INDEX% to access
the Minerva MultiBASIC and SMS SBASIC name tables. Some early versions
of TurboFix\_bin have bugs in it. Beware that not all versions of this
file supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`lookup-pct` and
:ref:`basic-name-dlr`.

--------------


