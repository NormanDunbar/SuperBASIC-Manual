..  _turbo-struct:

TURBO\_struct
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_struct " [ s \| f ] "                                     |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. TURBO is able to
compile a wide variety of programs. However, if the program does not
follow strict programming rules, it will take longer to compile and will
run more slowly (even if TURBO can manage to compile it).

Programs which
follow the programming rules are known as Structured. These programming
rules are set out below:

#. The main section of the program must appear at the start and not contain any PROCedure or FuNction definitions.
#. At the end of the main section appears only PROCedure and FuNction definitions without any other lines between the end of one definition and start of another except for REMarks.
#. All FOR, REPeat, IF, SELect ON, WHEN, structures are contained within each section (either the main section or a PROCedure / FuNction definition) of the program and not referenced from outside that section.

All other programs are known as Freeform.

The TURBO\_struct directive allows you to specify the
type of programming style used in the program which is to be compiled.
It accepts a single character string which should be one of the
following values:

- f: The program is Freeform.
- s: The program is Structured.

As with other compiler directives, this value can be changed by
configuring the parser\_task program or by entering a different value on
the Parser's front panel.

**Example**

::

    5 TURBO_struct "s"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


