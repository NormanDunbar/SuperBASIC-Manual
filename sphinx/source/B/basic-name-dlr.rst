..  _basic-name-dlr:

BASIC\_NAME$
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BASIC\_NAME$ (index)                                             |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is exactly the same as \_NAME$.

If the specified index is greater than the maximum name table entry, a
bad parameter error is returned. If it is smaller than 0, an error may
be generated, or junk may be returned.


**NOTE**

A file called TurboFix\_bin can be used to allow BASIC\_NAME$ to access
the Minerva MultiBASIC and SMS SBASIC name tables. Some early versions
of TurboFix\_bin have bugs in it. Beware that not all versions of this
file supports SMS SBASICs.


**CROSS-REFERENCE**

Refer to :ref:`-name-dlr` and
:ref:`basic-index-pct`.

--------------


