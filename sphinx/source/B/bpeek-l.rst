..  _bpeek-l:

BPEEK\_L
========

+----------+--------------------------------------+
| Syntax   | BPEEK% (offset)    and               |
|          |                                      |
|          | BPEEK\_W% (offset) and               |
|          |                                      |
|          | BPEEK\_L (offset)                    |
+----------+--------------------------------------+
| Location | BPEEKS, BPOKE (DIY Toolkit - Vol B)  |
+----------+--------------------------------------+

These three functions are exactly the same as BASIC\_B, BASIC\_W and
BASIC\_W, and suffer with the same problem that they always access the
SuperBASIC variables of Job 0 (SuperBASIC) and cannot therefore be used
on a Multiple BASIC interpreter.


**CROSS-REFERENCE**

See :ref:`basic-w` and
:ref:`basic`.

:ref:`bpoke` and related commands allow you to alter
the values of the SuperBASIC variables.

