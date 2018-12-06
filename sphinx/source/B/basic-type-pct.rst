..  _basic-type-pct:

BASIC\_TYPE%
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_TYPE% (offset)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function looks at the entry in the SuperBASIC name table for Job 0
at the specified offset and returns its type in accordance with the
following values:

-  0 .... no type
-  1 .... string
-  2 .... floating point
-  4 .... integer

If the specified offset is greater than the maximum name table entry, a
bad parameter error is returned. If it is smaller than 0, an error may
be generated, or junk may be returned.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_TYPE% to access
the Minerva MultiBASIC and SMS SBASIC name tables. Some early versions
of TurboFix\_bin have bugs in it. Beware that not all versions of this
file supports SMS SBASICs.


**CROSS-REFERENCE**

:ref:`type` is similar.

See also :ref:`basic-name-dlr`.

