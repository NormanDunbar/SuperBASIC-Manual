..  _turbo-diags:

TURBO\_diags
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_diags " [ d \| i \| o ] "                                 |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. A program can be
compiled with line numbers included, which increases the amount of
memory and dataspace required by a program, but does mean that if an
error occurs, the line number will be displayed. If you do not include
line numbers, any errors will report 'at line 0' and ERLIN% will return
0. This directive accepts a single character string which should be one
of the following values:

- d: Display line numbers during compilation process but do not include them in final code.
- i: Include line numbers in final code.
- o: Omit line numbers all together.

As with other compiler
directives, this value can be changed by configuring the parser\_task
program or by entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_diags "i"

**CROSS-REFERENCE**

See
:ref:`turbo-f`,\ :ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objdat`,\ :ref:`turbo-objfil`,
:ref:`turbo-optim`,\ :ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


