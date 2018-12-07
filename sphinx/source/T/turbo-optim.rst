..  _turbo-optim:

TURBO\_optim
============

+----------+-------------------------------------------------------------------+
| Syntax   |  TURBO\_optim " [ b \| r \| f ] "                                 |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit v3.00+                                             |
+----------+-------------------------------------------------------------------+

This is a directive for the TURBO compiler and should be located at the
start of your program before any active program lines. The way in which
TURBO compiles a program can be optimised using a trade off between
speed and code size.

The TURBO\_optim directive allows you to dictate
how the compiled program is to be optimised and accepts a single
character string which should be one of the following values:

- b: Generate BRIEF code, which ensures that the program uses as little memory as possible. This generates the slowest programs.
- r: Optimise code according to REMarks in the program. Normally this will generate BRIEF code unless you include a line containing REMark + in your program which tells TURBO to switch to FAST code. The code will then be optimised for speed until a line containing REMark - is encountered.
- f: Generate FAST code, which ensures that the program runs as quickly as possible. This may however cause the program to need a lot more memory. As with other compiler directives, this value can be changed by configuring the parser\_task program or by entering a different value on the Parser's front panel.

**Example**

::

    5 TURBO_optim "b"

**CROSS-REFERENCE**

See :ref:`turbo-diags`,
:ref:`turbo-locstr`,
:ref:`turbo-model`,
:ref:`turbo-objdat`,
:ref:`turbo-objfil`,
:ref:`turbo-repfil`,
:ref:`turbo-struct`,
:ref:`turbo-taskn` and
:ref:`turbo-window` for other directives

