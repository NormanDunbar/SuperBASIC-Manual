..  _read:

READ
====

+----------+-------------------------------------------------------------------+
| Syntax   |  READ var\ :sup:`1` :sup:`\*`\ [var\ :sup:`i`]\ :sup:`\*`         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command forces the interpreter to look at the current data
pointer, that is to say the next program line which begins with the
marker DATA.

When a program is *first* RUN, the data pointer is set to the
start of the program, and hence READ will attempt to assign the first
value following the first occurrence of DATA to the specified variable.
Having assigned this value, the data pointer is updated to the next
value in the same DATA statement, or the next program line if there are
no more values following the DATA statement.

If no more DATA is
contained within the program and you try to READ a value, the error 'End
of File' is reported. SMS's improved interpreter reports 'End of DATA'.

**Example**

A simple program to convert the three letter code returned by DAY$ into
the full name of the day::

    100 DATA 'Monday','Tuesday','Wednesday','Thursday'
    110 DATA 'Friday','Saturday','Sunday'
    120 RESTORE
    130 dday$=DAY$
    135 day=(dday$ INSTR ' MonTueWedThuFriSatSun')/3
    140 FOR find_day=1 TO day
    150   IF EOF:EXIT find_day
    160   READ dday$
    170 END FOR find_day
    180 PRINT dday$

**NOTE 1**

The data pointer is not reset to the start of the program following
every RUN. You need a RESTORE command to do this - try running the above
program without line 120.

**NOTE 2**

If you try to READ a value into a slice of an undimensioned string, the
value will not be stored and SuperBASIC may stop without a message, eg::

    100 DATA 'Bess '
    110 a$='Hello World'
    120 READ a$(7 TO)
    130 PRINT a$

Try by way of comparison, adding the line::

    10 DIM a$(12)

Both of these work under SMS.

**NOTE 3**

The interpreter does not really check the parameters listed after READ,
and unacceptable parameters, for example::

    READ 1

won't report an error and the program continues as if it had read a
variable. SMS's improved Interpreter reports 'Unacceptable Parameters
for READ' when the program is RUN.

**MINERVA NOTE**

As from v1.96, READ has been improved so that it will accept an array
parameter and then read a value for each element of the array in turn,
without having to put READ into a loop.

**Example**

::

    100 DIM x(5)
    110 READ x
    120 :
    1000 DATA 1,2,3,4,5,6


This will read x(0), x(1), x(2), x(3), x(4) and x(5)

All other implementations insist upon you using something akin to::

    100 DIM x(5)
    110 FOR i=0 TO 5:READ x(i)
    120 :
    1000 DATA 1,2,3,4,5,6

**CROSS-REFERENCE**

:ref:`restore` allows you to alter the program
line pointed at by the data pointer. :ref:`data` sets
out lines to be :ref:`read`.
:ref:`eof` allows you to test for the end of all
program data.

--------------



