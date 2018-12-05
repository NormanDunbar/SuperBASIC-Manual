..  _codevec:

CODEVEC
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CODEVEC (name$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ALIAS (DIY Toolkit - Vol A)                                      |
+----------+-------------------------------------------------------------------+

This function is very similar to KEY\_ADD in that it returns the address
in memory where the machine code for a machine code Procedure or
Function is stored (useful for debugging programs with Qmon or similar
machine code monitor).

If the Machine Code Procedure or Function with the given name$ does not
exist, then a 'Not Found' error is reported.

**CROSS-REFERENCE**

See :ref:`key-add` and
:ref:`elis`.

--------------


