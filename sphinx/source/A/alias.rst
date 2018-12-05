..  _alias:

ALIAS
=====

+----------+-----------------------------------------------------------------+
| Syntax   | ALIAS old\_keyword$ TO new\_keyword(ALIAS\_CODE) or             |
|          |                                                                 |
|          | ALIAS new\_keyword TO old\_keyword$(SAILA\_CODE)                |
+----------+-----------------------------------------------------------------+
| Location | ALIAS (DIY Toolkit - Vol A)                                     |
+----------+-----------------------------------------------------------------+

This command is similar to NEW\_NAME and REPLACE.

It allows you to assign another name to machine code Procedures and
Functions which are currently resident in memory. Both versions of the
command are the same, except that the second variant expects you to pass
the two parameters in the opposite order.

We shall deal with the first variant.

The first parameter (old\_keyword$) must appear as a string and is the
original name of the Procedure or Function which is to be renamed. The
second parameter (new\_keyword) is the new name to be used - this must
not appear as a string, but simply as the actual keyword to use.

The original definition is not lost and therefore you can still use the
original name to call the machine code procedure or function (as well as
the new name).

If old\_keyword$ does not contain the name of a machine code Procedure
or Function, then either a 'Not Found' or 'Bad Name' error will be
reported.

**Example**

Try the following short program:

::

    10 INPUT 'Enter Your Name: '; a$
    20 PRINT a$
    30 ALIAS 'INPUT' TO XINPUT
    40 XINPUT 'Enter My Name with XINPUT: '; s$
    50 INPUT 'You can still use INPUT to Enter your Name: ';t$
    60 PRINT s$ / t$

**NOTE 1**

Because the original definition is not lost, you can go on to assign
further 'aliases' to the original name, but any attempt to assign an
alias to the new name (XINPUT in the above example will give a Not Found
error).

**NOTE 2**

You should not use ALIAS from within programs compiled with TURBO and
SuperCharge.

**NOTE 3**

If a program compiled with TURBO or SuperCharge reports an error when
you try to EXECute the program, such as 'SYS\_VARS is Not Defined', you
could use ALIAS from SuperBASIC to circumvent this problem, for example
by using:

ALIAS 'SYSBASE','SYS\_VARS'

**NOTE 4**

The new alias is not converted by this command to uppercase - that is up
to you (not all keywords are in uppercase after all).

**NOTE 5**

You should not use all of the new names set with ALIAS in programs which
are to be compiled with TURBO or SuperCharge if you want to make the
most of those compilers. In particular, ALIASes of the following
keywords will cause problems:

RESPR (unless it has been redefined to work in the common heap before
you used ALIAS).

RUN, INPUT, READ, EOF, CLEAR, DIMN, STOP, NEW and various TURBO toolkit
commands.

You will also lose out on optimisations on the following:

PRINT, BLOCK, CODE, CHR$, LEN, PI, PEEK, PEEK\_W, PEEK\_L, POKE, POKE\_W
and POKE\_L.

**NOTE 6**

If you wish to use ALIAS for MODE and use Speedscreen, ensure
Speedscreen is loaded and enabled before you use ALIAS (Speedscreen
redefines MODE).

If you wish to use ALIAS for mathematical functions and use the
Lightning fast maths routines, again, ensure that Lighning maths is
loaded before you use ALIAS if you want the faster routines implemented
by Lightning.

**NOTE 7**

If you want to use this command from within a Multiple SBASIC on SMS or
a MultiBASIC on Minerva, you will need to use the variant of the command
implemented in the file SAILA\_CODE.

**CROSS-REFERENCE**

See also :ref:`replace` and
:ref:`new-name`.

:ref:`-name-dlr` allows you to look at the name
table.

--------------


