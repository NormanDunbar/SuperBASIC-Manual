..  _replace:

REPLACE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  REPLACE oldvar, newvar                                           |
+----------+-------------------------------------------------------------------+
| Location |  REPLACE (DIY Toolkit - Vol R)                                    |
+----------+-------------------------------------------------------------------+

The REPLACE command is intended for use from the interpreter's command
line and for program development only.

The idea of REPLACE is to rename
SuperBASIC variables contained in the program which is currently loaded
into the interpreter. The first and second parameter can be any
variables, they must not be given as strings ie. inside quotes (this
leads to error -15: bad parameter).

REPLACE will replace oldvar by
newvar for the whole program (in fact for the whole interpreter).

Acceptable types of parameters are variables and also REPeat loop names
but not PROCedure or FuNction names.

You can even use this to change
unquoted device names if you wish, such as::

    LBYTES flp1_data_cde

You could use::

    REPLACE flp1_data_cde, flp2_data_cde

REPLACE is extremely fast, without any noticeable reduction in speed
for large programs due to the fact that the interpreter stores the
program lines in tokenised format, this means that a line is not stored
as text but as a set of numbers (tokens) which represent the elements of
the line. So REPLACE merely has to modify the name table and change the
name which is identified with a certain token.

**Example**

Enter the following lines::

    10 x = 1
    20 PRINT SQRT(x)

Now type::

    REPLACE x, Whatever

and then LIST or ED, the program now reads::

    10 Whatever = 1
    20 PRINT SQRT(Whatever)

and is functionally identical to the original.

**NOTE 1**

Never use REPLACE as part of a program.

**NOTE 2**

REPLACE will work on a program loaded into a MultiBASIC.

**WARNING 1**

There is one possibility that you can harm your program: if you replace
a variable by another variable which is already used in this program
then the program will usually behave very differently after the
REPLACEment.

**WARNING 2**

According to the Minerva Technical Manual REPLACE is "not particularly
safe". At least if you are using the original version as published in QL
World then you need to turn off Minerva's integer tokenisation (POKE
\\\\212,128). Later versions (v0.3+) do however cope with integer
tokenisation. Despite the warning, we have yet to find any other
problems with REPLACE.

**CROSS-REFERENCE**

:ref:`new-name` is very similar to
:ref:`replace` but the parameters are passed as
strings. This has the advantage that
:ref:`new-name` can take variable parameters,
:ref:`replace` would replace the variable for the
variable name. Compare :ref:`alias`.

