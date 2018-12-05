..  _data:

DATA
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DATA expression :sup:`\*`\ [,expression]\ :sup:`\*`              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The QL allows a SuperBASIC program to store a set of data in the
program itself, which can then be assigned to a given variable by the
READ command. The DATA statement marks these areas for use by READ. The
information which can be stored at a DATA statement is basically
anything which can be stored in a variable, including strings,
variables, constants and expressions.

Expressions will be calculated at
the time that the item in question is READ. Whilst a program is running,
unless a READ command is found, DATA statements are ignored.


**Example**

::

    1000 DATA "QL User",100,x*1000+10


**NOTE 1**

On Pre MG ROMs, if any values in a DATA statement start with a bracket,
then the other items on the line may be ignored. If you must specify
items starting with brackets, use for example: DATA 0+(...
This is fixed by MG ROMs, Minerva and SMS.


**NOTE 2**

Unless you have a Minerva ROM (v1.77 or later) or SMS, when you enter
the DATA statement, you will always need to type a space after the word
DATA as the parser will not automatically insert one. On later
implementations a space is automatically inserted where the first DATA
expression is a string, eg. DATA'Hello'.


**NOTE 3**

Entering a DATA statement as a direct command from #0 has no effect.
Under SMS an error is reported 'DATA in command line has no meaning'.


**NOTE 4**

Due to the way in which the interpreter works, it is always more
efficient to place DATA statements at the start of a program (the search
function always starts at the first line of the program).


**NOTE 5**

Various SuperBASIC compilers (such as Turbo) do not support expressions
in DATA statements.


**NOTE 6**

There appears to be no real check on the parameters given for DATA, so
the following line can be entered, but will in fact cause an error when
you try to READ it::

    10 DATA 1000,PRINT,10

SMS's improved interpreter does do more checks than earlier
implementations and will prevent you from entering the line::

    10 DATA 1,1,2a,3

which other implementations allow (but give an error when they try to
READ the line).


**NOTE 7**

SMS may complain if you create numerous DATA statements inside a DEFine
PROCedure or DEFine FuNction struture.


**CROSS-REFERENCE**

:ref:`restore` allows you to set the current
:ref:`data` pointer. :ref:`read`
will assign the value at the current :ref:`data`
pointer to the given variable. :ref:`eof` will return
the value one if there are no more :ref:`data`
statements in the current program.

--------------


