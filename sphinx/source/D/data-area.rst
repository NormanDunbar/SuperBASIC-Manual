..  _data-area:

DATA\_AREA
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DATA\_AREA size size=0...850                                     |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is only used by the Turbo compiler and should be located
at the start of your program before any active program lines.

The
command specifies how much dataspace (size kilobytes) should be
specified for the compiled program.

This dataspace is used by a task for
stack space and a temporary store whilst it is running.


**Example**

::

    10 DATA_AREA 32


**NOTE**

This setting will override a previous TURBO\_objdat directive in the
same program. It will also be overridden by a later TURBO\_objdat
directive in the same program.


**CROSS-REFERENCE**

:ref:`dataspace` allows you to find out how much
dataspace has been set aside for a program. See
:ref:`compiled` and
:ref:`turbo-objfil` for other compiler
directives. :ref:`turbo-objdat` is exactly
the same.

