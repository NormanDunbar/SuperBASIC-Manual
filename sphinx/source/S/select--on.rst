..  _select--on:

SELect ON
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SELect ON var                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command is used to mark the start of a SuperBASIC structure which
is an extremely quick means of testing for various values of a variable
and taking a different course of action in a program according to those
values. Unfortunately, the standard form of this command only allows you
to test for different values of a numeric variable (eg. SELect ON a$ is
not allowed).

There are actually two forms of the SuperBASIC structure:

SELect ON var=range: statement :sup:`\*`\ [:statement]\ :sup:`\*\*`\ [:=range:statement
:sup:`\*`\ [:statement]\ :sup:`\*`]\ :sup:`\*`

or

SELect ON var :sup:`\*`\ [[ON var] = range:statement :sup:`\*`\ [:statement]\ :sup:`\*` ]\ :sup:`\*` .. END SELect

Range can be any one, or mixtures of, the following:

- Expression
- Expression TO Expression
- REMAINDER

The first of these two SELect variants (in this and all SuperBASIC structures) is
known as an in-line structure, as the entire structure appears on the
same program line. This does not need END SELect to mark the end of the
structure.

After the main SELect ON var statement, the interpreter looks
for a list of possible values, and then if the value of the given
variable falls within the range of possible values, the program takes
action according to the statements which follow that value in the list.

The interpreter will use the first range of values into which it can fit
the variable and once found, all statements up until (but excluding) the
next range in the list will be treated as applying to that range
(whether they appear on the same line or not). Once all of the
statements applying to that range have been executed, control passes to
the statement following the END SELect
statement (or if the in-line form of the structure is used, and END
SELect does not appear on that line, then control passes to the next
line).

The way in which matches are made when checking whether a value
falls within a range depends on whether range is a single number eg::

    ON var = 100

or various values eg::

    ON var = 90 TO 100

If the former, the
value need only be approximately equal to range (ie. to within 1 part in
10\ :sup:`7`, for instance: 100.0000045==100!). However, if the latter
format is used, a match will only be found
if the given value is within the absolute range (eg. in the above
example, 100.0000045 would not be matched!).

If the long form of the
structure is used, and ON var is used within the body of the structure,
this must be the same variable as that used in the initial SELect ON
statement.

**Example 1**

::

    10 SELect ON x=1,10 TO 100,500:PRINT 'x'

**Example 2**

::

    100 SELect ON test
    110   = 0,2,4,6,8,10: PRINT 'Even Number'
    120   = REMAINDER: PRINT 'Odd Number'
    130 END SELect

**Example 3**

A re-write of the example given for ON...GO SUB::

    100 no_of_locations=3
    110 start=0
    120 PRINT_LOC 2
    125 :
    130 DEFine PROCedure PRINT_LOC(xa)
    135   xa=xa+start
    140   SELect ON xa
    150     = 1: PRINT 'This is location 1'
    160     =2
    165       PRINT 'This is location 2'
    170     =3: PRINT 'This is location 3'
    180     = REMAINDER: PRINT 'Undefined Location'
    185       RETurn
    190   END SELect
    200   PRINT 'What now?:RETurn
    210 END DEFine

**NOTE 1**

Pre JS ROMs and SMS allow you to enter string and integer variables into
the SELect statement, but they will not work unless you used a
SuperBASIC compiler. Later ROMs, report a 'bad line' error unless you
have Minerva.

**NOTE 2**

On JS ROMs, you cannot use a parameter passed to a PROCedure or FuNction
as the variable in a SELect ON statement unless it appears as the last
parameter in the list in the definition line. If you do try to break
this rule, you will end up with a 'bad name' error. The answer is to
copy the parameter to a temporary variable.

**NOTE 3**

As you may have noticed, unlike other SuperBASIC structures which will
expand a command typed into the full structure name if you type just the
capital letters (eg. DEFPROC becomes DEFine PROCedure), SELON will not
be expanded to SELect ON. You will need to type SEL ON instead.

**NOTE 4**

To maximise the speed of the SELect ON command, ensure that the most
common matches appear at the start of the definition block.

**NOTE 5**

Except under SMS, SELect ON can only cope with simple variables, for
example::

    SELect ON a

is acceptable. Compare::

    SELect ON a(2)
    SELect ON s*10
    SELect ON CODE(a$)

All of these are acceptable on SMS but cannot currently be compiled.

Although lines such as::

    SELect ON CODE

and::

    SELect ON INKEY$

might be accepted by the interpreter, the lines contained within the
block will be ignored (other than =REMAINDER matches). On SMS both of
these give an 'error in expression' when RUN.

**MINERVA NOTES**

Minerva supports string and variables in SELect ON statements. The check
for characters is normally case independent. For example::

    SELect ON a$: ='hello'

will find both a$='HeLLo' and a$='hello'. If however, you want the
match to be exact (case dependent), then something along the lines of::

    SELect ON a$: ='hello' TO 'hello'

must be used. Unfortunately, you still cannot SELect ON machine code
functions (for example, INKEY$), which will have no effect, or slice the
string, which will cause a 'bad line' error. A short example of the
additional flexibility is a check for a response to a simple question
{eg. Overwrite (y/n)?}::

    100 REPeat loop
    110   A$=INKEY$(-1)
    120   SELect ON A$
    130     ='yn'&chr$(27):EXIT loop
    140   END SELect
    150 END REPeat loop

is the same as::

    100 REPeat loop
    110   A=CODE(INKEY$(-1))
    120   SELect ON A:
    130     =89,121,78,110,27:EXIT loop
    140   END SELect
    150 END REPeat loop

Minerva also supports integer variables, such as::

    SELect ON a%

This is an extremely fast means of testing a condition. However, due to the
nature of integers, tests will only match the integer part of range.

**SMS NOTE**

This has greatly extended the flexibility of SELect ON - see in
particular Note 5 above. It will also allow integer variables as the
SELect, but unfortunately not string SELect variables at present. If you
try to do so, the error 'Incorrectly structured SELect clause' will be
reported. It will however, even support things like::

    SELect ON CODE(INKEY$(#1))

Unfortunately, SMS pre v2.90 had problems in dealing with in-line
SELect ON statements. Prior to v2.89 an error would be generated if an
END SELect statement did not appear in an in-line definition, and v2.89
reported an error if END SELect did appear!!

**CROSS-REFERENCE**

A slower means of testing for values is the structure :ref:`if` ... :ref:`end--if`\ . :ref:`end--select` ends a :ref:`select--on` structure.

--------------


