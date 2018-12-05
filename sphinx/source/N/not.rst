..  _not:

NOT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NOT x                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

NOT is an operator which does not combine two operands (unlike +, DIV
or \|\| for example) but only operates on one. In fact, it can be
regarded as a function which returns a value depending on the operand,
except that brackets are not needed around the operand.

NOT is a logical
operator and returns either 1 if the operand is zero or 0 in any other
case. The following function would work the same way::

    100 DEFine FuNction NOT1 (x)
    110   IF x=0 THEN RETurn 1: ELSE RETurn 0
    120 END DEFine NOT1

or even shorter::

    100 DEFine FuNction NOT2 (x)
    110   RETurn x=0
    120 END DEFine NOT2

**Example**

The above replacements of NOT demonstrate that it is not necessary at
all to use NOT. But in context, NOT can clarify an expression and make
program listings more readable. If is\_lamp is a logical variable used
to say whether something is a lamp (is\_lamp=1) or not (is\_lamp=0),
there are (at least) two variants to write the status of is\_lamp to the
screen. Which is easier to read?

::

    PRINT "This is ";: IF is_lamp=0 THEN PRINT "not ";PRINT "a lamp."

or::

    PRINT "This is ";: IF NOT is_lamp THEN PRINT "not ";PRINT "a lamp."

Let's assume lamps is a variable counting lamps and you want to write
out a message if there are no lamps left::

    IF lamps=0 THEN PRINT "Sorry, we are out of lamps."

or::

    IF NOT lamps THEN PRINT "Sorry, we are out of lamps."


Here, the first formulation, which does not use NOT is clearer.

Until now, the examples have shown that NOT can be used to improve the style
of a program, but there are also ways to put NOT to practical use,
especially if a logical variable is to be set depending on another
logical variable.

For instance, this procedure will accept such a value
as a parameter and convert it to its logical counterpart for its own
use::

    100 DEFine PROCedure MY_CIRCLE (x,y,r, filled)
    110   IF filled THEN FILL 1
    120   CIRCLE x,y,r
    130   IF filled THEN FILL 0
    140 END DEFine MY_CIRCLE

As IFs are relatively slow and FILL takes a logical parameter, the
following variant is faster::

    100 DEFine PROCedure MY_CIRCLE (x,y,r, filled)
    110   FILL filled
    120   CIRCLE x,y,r
    130   FILL 0
    140 END DEFine MY_CIRCLE

As FILL cannot handle parameters other than 0 and 1, if filled
could have any value at all (not just 0 or 1), it would be necessary to
change filled so that it was either 0 or 1, by an additional line::

    105 IF filled THEN filled=1

NOT is ideal (although here a bit complex!) to avoid the IF
and calculate filled directly::

    110 FILL NOT(NOT filled)

**NOTE**

When dealing with logical variables, the use of NOT to toggle the value,
for example::

    filled = NOT filled

is invariably quicker than the use of an IF statement::

    IF filled THEN filled = 0: ELSE filled = 1

**CROSS-REFERENCE**

Comparisons between any two values (or even two variables) is regarded
as a numeric expression by SuperBASIC. :ref:`if`
handles actual numeric values.

--------------


