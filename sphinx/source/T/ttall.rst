..  _ttall:

TTALL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTALL (space [,jobid] )                                          |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function is the same as ALCHP but memory allocated with TTALL
cannot be cleared with CLCHP or RECHP: TTREL must be used on the return
value of TTALL; see TTFINDM for an example.

**CROSS-REFERENCE**

:ref:`ttrel` See also
:ref:`reserve`.

