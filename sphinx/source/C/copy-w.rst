..  _copy-w:

COPY\_W
=======

+----------+------------------------------------------------------------------+
| Syntax   | COPY\_W adr1, adr2, n         or                                 |
|          |                                                                  |
|          | COPY\_W adr1, n TO adr2                                          |
+----------+------------------------------------------------------------------+
| Location | BTool                                                            |
+----------+------------------------------------------------------------------+

The command COPY\_W copies n words (two bytes each) from address adr1 to
adr2.

**NOTE**

Both addresses must be even.

**CROSS-REFERENCE**

:ref:`copy-w` is always faster than
:ref:`copy-b`, but
:ref:`copy-l` is even faster than
:ref:`copy-w`.

See also :ref:`xchange`.

Minerva has its own fast copy routines (see
:ref:`call`).

--------------


