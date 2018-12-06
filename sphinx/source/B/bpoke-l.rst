..  _bpoke-l:

BPOKE\_L
========

+----------+--------------------------------+
| Syntax   | BPOKE offset, value   and      |
|          |                                |
|          | BPOKE\_W offset, value         |
|          |                                |
|          | BPOKE\_L offset, value         |
+----------+--------------------------------+
| Location | BPOKE (DIY Toolkit - Vol B)    |
+----------+--------------------------------+

These three commands allow you to alter the value of SuperBASIC
variables in much the same was as the extended POKE commands do on
Minerva and SMS.

BPOKE\_W and BPOKE\_L were added in v0.7 of the toolkit.

They unfortunately always access the SuperBASIC variables of Job 0
(SuperBASIC) and cannot therefore be used on a Multiple BASIC
interpreter.


**CROSS-REFERENCE**

See :ref:`poke`.

:ref:`bpeek-pct` and related commands allow you to
read the values of the SuperBASIC variables.

