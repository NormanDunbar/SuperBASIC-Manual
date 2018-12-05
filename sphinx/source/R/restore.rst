..  _restore:

RESTORE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RESTORE [line\_no]                                               |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

In any program which uses DATA statements, it is necessary to tell the
interpreter where the data begins within the program, so that it knows
where to look when it encounters a READ command. RESTORE allows you to
set the data pointer to a specific line number within a SuperBASIC
program.

If line\_no is not specified, then the data pointer is moved to
the start of a program allowing all DATA within a program to be READ.
line\_no can be either a simple reference to a line number anywhere in a
SuperBASIC program, or an expression which will be calculated by the
interpreter when it reaches the RESTORE command.

**NOTE 1**

The Turbo and Supercharge compilers cannot compile computed RESTOREs.

**NOTE 2**

The data pointer is not reset when a program is RUN and it is therefore
necessary to use an implicit RESTORE or CLEAR if you wish to read the
same set of DATA each time that a program is RUN.

**NOTE 3**

On some implementations RESTORE with an invalid parameter will do a
RESTORE 0. This is fixed on Minerva v1.96+ and SMS which report the
error.

**CROSS-REFERENCE**

See :ref:`data` and :ref:`read`.
Please also refer to :ref:`renum`.

--------------


