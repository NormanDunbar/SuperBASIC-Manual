..  _turbo-locstr:

TURBO\_locstr
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_locstr " [ i \| r \| c ] "                                |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. All strings used
within a compiled program should be dimensioned so that the compiler
knows the maximum amount of memory which needs to be set aside to store
a string. Any attempt to assign a longer value to the string than that
set with a DIM or LOCal command will be cut to the appropriate length.

If TURBO has to automatically DIMension a string, it assumes a length of
100 characters (unless configured otherwise).

The TURBO\_locstr
directive relates to the way in which TURBO should deal with LOCal
strings or string parameters. It accepts a single character string which
should be one of the following values:

- i: Ignore any strings which are used in the program but not dimensioned. TURBO assumes that you know what you are doing with them.
- r: Report any undimensioned strings - do nothing with them.
- c: Create a DIM statement for any undimensioned strings, making them global sizes for the whole program.

As with other compiler directives, this value can be changed by configuring the
parser\_task program or by entering a different value on the Parser's
front panel.

**Example**

::

    5 TURBO_locstr "c"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,\ :ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

