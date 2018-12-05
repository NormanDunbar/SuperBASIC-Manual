..  _turbo-objfil:

TURBO\_objfil
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_objfil filename$                                          |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This directive
expects you to specify a string which will form the filename of the
compiled program produced by TURBO. The full filename (including device)
should be specified in quote marks. As with other compiler directives,
this value can be changed by configuring the parser\_task program or by
entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_objfil "ram1_CT_exe"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

--------------


