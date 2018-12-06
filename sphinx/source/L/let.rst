..  _let:

LET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  [LET] variable=expression                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The command LET has only been implemented to make SuperBASIC more
compatible with other versions of BASIC. It assigns a specific value to
the specified variable, which can be of any type. The command may
actually be omitted altogether. Normally any mistake in this command
results in an 'Error in Expression' report.

**Examples**

::

    LET x=100+10\*20

Assigns the value 300 to the variable x.

::

    x=100+10\*20

Is exactly the same as above.

::

    LET a$='Hello '&x

This places the string 'Hello 300' into the variable a$. The value of x is converted into a
string and then appended.

::

    LET position(100)=10

This assigns the value 10 to the 101st element of the array position (see DIM).

**NOTE 1**

On the AH ROM, you need to be careful of what is being assigned to a
numerical variable: LET X="." did not produce an error on this ROM.
Compare this with LET X='0.12' which in fact assigns the value 0.12 to
the variable x due to coercion.

**NOTE 2**

It may be useful to explain the error codes which may be reported when
trying to assign a value to a variable. Under SMS the improved
interpreter will report more meaningful errors if you try to use this
command incorrectly and therefore it is these errors which are
highlighted.

Assignment can only be to a variable or array element
    This is reported if you try to assign a value to a Procedure or Function
    name, eg: PRINT = 100

    On other versions this causes an ...

Error in Expression
    When assigning values to arrays there are four possible error reports:

Only arrays or strings may be indexed
    This will be reported if you try to assign a value to an undimensioned
    array, for example if you used the line: position (100)=10
    without having used the line: DIM position (200)
    beforehand. On other implementations, this causes the error ...

**Bad Name**

Cannot assign to sub-array
    We have not been able to find a situation when this error occurs.

Unacceptable array index list
    This is reported normally if you try to use too many indices to
    reference an existing array, for example: DIM x(100) : PRINT x(10,10)

    On other implementations this causes an

**Out of Range**

Array index out of range
    This is reported if you try to use an index which is greater than that
    used when the array was dimensioned, for example: DIM x(100) :
    x(101)=100

    On other implementations this also causes an

**Out of Range**

**WARNING**

On SMS, you can easily crash SBASIC by missing out an index on an
assignment to a DIMensioned array, for example::

    DIM x(100) x (10, ) = 100

Will report Not Complete::

    x(10, , ) = 100

Will crash SBASIC.

On Minerva (and possibly other ROM versions) both of these merely report
'Error In Expression'.

**CROSS-REFERENCE**

:ref:`read` and :ref:`input` also
allow you to assign a value to a variable.

