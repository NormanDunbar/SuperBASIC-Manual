..  _turbo-model:

TURBO\_model
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_model " [ < \| > ] "                                      |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. The TURBO
compiler is able to generate code using either 16 bit addressing or 32
bit addressing. The former produces more compact and slightly faster
code than the latter, but runs into problems if the compiled version of
your program (excluding dataspace) is larger than 64K. You should
therefore experiment with this setting - if your program is too large to
be compiled with 16 bit addressing, the TURBO compiler will report an
error during the code generation stage to the effect that the program is
'too large for optimisation'. This does not overcome the problem with
running TURBO compiled programs on systems which have a lot of memory or
which do not have the system variables stored at $28000. To cover these
programs, it is necessary to run them through the TurboPatch program
supplied with later versions of the TURBO toolkit.

The TURBO\_model
directive accepts a single character string which should be one of the
following values:

- <: Generate code using 16-bit addressing (shown as <64K on screen).
- >: Generate code using 32-bit addressing.

As with other compiler directives, this value can be changed by configuring the
parser\_task program or by entering a different value on the Parser's
front panel.

**Example**

::

    5 TURBO_model "<"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-optim`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

