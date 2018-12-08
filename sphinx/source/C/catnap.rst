..  _catnap:

CATNAP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CATNAP                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

The Turbo compiler allows PROCedure and FuNction definitions within a
compiled program to be defined as GLOBAL and then called by other tasks.
This is similar to making a modular machine code program which is then
linked together when the assembly language modules are assembled. Under
Turbo, the various program modules can be compiled separately, but then
loaded together with LINK\_LOAD\_A and similar commands.

The CATNAP command will force a compiled program to wait at this
statement indefinitely. The compiled program is only allowed to carry on
execution from the next statement if another module calls one of the
GLOBAL definitions contained in the current program and the GLOBAL
PROCedure or FuNction has completed.

If CATNAP is used within a SuperBASIC program, then the program is
simply suspended until the Break key is pressed.

**CROSS-REFERENCE**

SNOOZE is similar. See also
GLOBAL,
EXTERNAL and
LINK_LOAD_A.

