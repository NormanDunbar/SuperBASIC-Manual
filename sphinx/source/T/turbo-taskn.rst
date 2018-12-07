..  _turbo-taskn:

TURBO\_taskn
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_taskn name$                                               |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This directive
allows you to specify the name for the compiled program which will
appear in its header and appear when JOBS is used for example. The full
name should be specified in quote marks.

As with other compiler
directives, this value can be changed by configuring the parser\_task
program or by entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_taskn "Main v1.2"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct` and
:ref:`turbo-window` for other directives

