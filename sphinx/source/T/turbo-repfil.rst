..  _turbo-repfil:

TURBO\_repfil
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_repfil filename$                                          |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This directive
expects you to specify a filename as a string. TURBO will use this file
to produce a report on the compilation process, which can be useful to
track down compilation errors and warnings. If no filename is specified,
then all errors and warnings are merely shown on screen. The full
filename (including device) should be specified in quote marks. As with
other compiler directives, this value can be changed by configuring the
parser\_task program or by entering a different value on the Parser's
front panel.

**Example**

::

    5 TURBO_repfil "ram2_CT_report"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


