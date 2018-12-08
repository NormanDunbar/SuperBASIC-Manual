..  _basic-l:

BASIC\_L
========

+----------+------------------------------------------------------------------+
| Syntax   | BASIC\_B (offset) and                                            |
|          |                                                                  |
|          | BASIC\_W (offset)                                                |
|          |                                                                  |
|          | BASIC\_L (offset)                                                |
+----------+------------------------------------------------------------------+
| Location |  TinyToolkit, BTool, Turbo Toolkit (BASIC\_L only)               |
+----------+------------------------------------------------------------------+

These three functions are modified version of PEEK which return values
at memory locations in the SuperBASIC system variables, which are used
for storage by the SuperBASIC interpreter.

BASIC\_B returns bytes, BASIC\_W words and BASIC\_L long words.


**Example**

Although additional information about internal machine structures is
necessary to make full use of these functions, some simple tasks can be
performed without this knowledge, for example:

PRINT BASIC\_W ( 1076 )

gives the first line number of a program in memory - this enables a
machine code program to check if a program is actually loaded in the
machine. The value returned by this example will always be zero from the
interpreter.

::

    100 IF NOT BASIC_W (1076) THEN
    110   PRINT "No SuperBASIC program loaded"
    120 END IF


**NOTE**

These functions generally suffer the same problem as BASIC.

A file called TurboFix\_bin can be used to allow BASIC\_L to access
Minerva MultiBASIC and SMS SBASIC variables. Some early versions of
TurboFix\_bin have bugs in it. Beware that not all versions of this file
supports SMS SBASICs.


**CROSS-REFERENCE**

:ref:`peek`, :ref:`peek-w`,
:ref:`peek-l`, :ref:`basicp`.

:ref:`basic-b-pct`, :ref:`basic-w-pct`,
:ref:`bpeek-pct`,
:ref:`bpeek-w-pct` and
:ref:`bpeek-l` are similar.

See also :ref:`basic-f` and
:ref:`peek-f`.

The SuperBASIC variables appear in the QDOS/SMS Reference Manual
(Section 18.3)

