..  _fop-new:

FOP\_NEW
========

+----------+------------------------------------------------------------------+
| Syntax   | FOP\_NEW (#ch, name) or                                          |
|          |                                                                  |
|          | FOP\_NEW (name)                                                  |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This function, together with its companions FOPEN, FOP\_IN, FOP\_DIR
and FOP\_OVER, is designed to allow you to access files safely without
causing errors which force a program to stop. This function is the
complement to OPEN\_NEW and returns the same values and suffers from the
same problem as FOPEN. If the specified file already exists, you are
asked whether you want to over-write the existing file. An error (-8) is
returned if you press N, and error (-20) is returned if the disk is read
only.

**CROSS-REFERENCE**

See :ref:`fopen` and
:ref:`open-new`.

--------------


