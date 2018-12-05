..  _turbo-window:

TURBO\_window
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_window number                                             |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. This tells the
TURBO parser to copy across number windows from the existing channel
structure into the compiled program. If number=1 only window #1 will
appear in the compiled program. Any greater value for number will copy
window #0 also. It is usually better to ensure that your compiled
program opens all of its own windows, using commands such as::

    100 OPEN #1,'con_448x200a32x16'

This reduces the amount of memory used up by each channel and also
ensures that your program only opens the windows which it actually needs
to work. As with other compiler directives, this value can be changed by
configuring the parser\_task program or by entering a different value on
the Parser's front panel.

**Example**

::

    5 TURBO_window 0

**NOTE**

Only the active area of a window is copied across to the compiled
program, so if a BORDER has been specified, this will not appear in the
compiled program (only the area inside the border will be copied
across). If your compiled program then defines its own BORDER on that
window, the size of the window will be further reduced.

**CROSS-REFERENCE**

See
:ref:`turbo-diags`,\ :ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,\ :ref:`turbo-repfil`,
:ref:`turbo-struct`, and
:ref:`turbo-taskn` for other directives

--------------


