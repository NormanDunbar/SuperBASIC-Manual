..  _for:

FOR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FOR var = range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*`         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The SuperBASIC version of the classic FOR loop is *extremely* flexible.

The syntax of this SuperBASIC structure can take two forms:

    FOR var=range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*` :statement :sup:`\*`\ [:statement]\ :sup:`\*`

or :

    FOR var=range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*` :sup:`\*`\ [statements]\ :sup:`\*` [EXIT var] [NEXT var] END FOR var

Where range can be one of the following:

    start\_value TO end\_value [STEP step]

or, simply just:

    value

The first of these variants is known as an in-line FOR loop. Provided
that there is at least one statement following FOR, this line will be
repeated until the end value is reached (see below). There is no need
for a related END FOR statement and therefore the shortest in-line FOR
loop possible is::

    FOR x=1 to 100: NEXT x

If an in-line loop is terminated prematurely, for example with EXIT,
control will be passed to the statement following the corresponding END
FOR statement (if one exists), or the next program line. This allows the
following::

    FOR x=1 TO 100: IF INKEY$=' ': EXIT x: END FOR x: PRINT x

The basic function of FOR is to count a floating point variable from
a given start value to an end value by adding step to var during each
pass of the loop (step may be positive or negative depending on the
start and end values). If no step is specified, STEP 1 will be assumed.

However, if step is negative when the end value is greater than the
start value (or vice versa), then the loop will immediately exit, and
nothing contained in the loop will be processed.

A similar effect can be
achieved by using a REPeat structure::

    var=start_value
    REPeat loop
      ...
      IF var >= end_value THEN
        EXIT loop
      ELSE var = var + step
    END REPeat loop

The similarity between these two SuperBASIC loop types can be extended
to the use of EXIT and NEXT statements which can be used identically in
both structures.

EXIT terminates the loop, and the next statement which
will be processed is the first statement after the corresponding END
FOR. NEXT forces the program to make the next pass of the loop.

**PROGRAMMING NOTES**

1. When NEXT is used within a FOR..END FOR structure, if var is
   already at the end\_value, the NEXT statement will have no effect::

       100 FOR x=1 TO 9
       110 PRINT x;" ";
       120 IF x MOD 2 THEN NEXT x
       130 PRINT x^2
       140 END FOR x

   Output::

        1 2 4
        3 4 16
        5 6 36
        7 8 64
        9 81

   To prevent the odd result when x=9, line 120 would need to be altered to read::

        120 IF x MOD 2 THEN NEXT x: EXIT x

2. Except on a Minerva ROM or under SMS, the loop variable is set to
   0 before the FOR is executed, therefore the following program prints the
   square roots of the numbers 0 to 9::

       100 x=3
       110 FOR x=x TO 9
       120 PRINT x;' ';
       130 IF NOT RND(10) THEN EXIT x
       140 PRINT SQRT(x)
       150 END FOR x

   On Minerva ROMs and under SMS, this would print out all of the square
   roots of the numbers 3 to 9 (as expected).

3. A NEXT statement directly after the FOR statement could be used to omit some
   values of the loop variable::

       100 FOR x=1 TO 9
       110 IF x MOD 2 THEN NEXT x: EXIT x
       120 PRINT x; TO 4; x^2
       130 END FOR x

   However, in some cases, it may be easier and shorter to write::

       100 FOR x=2,4,6,8
       110 PRINT x; TO 4; x^2
       120 END FOR x

4. Single values and intervals can be freely mixed after the equals
   sign. The following examples are all valid expressions::

       FOR x=2,4 TO 10 STEP 2,4.5,7 TO -4 STEP -.2
       FOR x=1

5. To shorten program lines even further, the FOR loop can be used in
   a single line and the END FOR omitted (this is called an in-line FOR
   loop)::

       FOR x=2,4,6,8: PRINT x; TO 4; x^2

**Example 1**

A short routine to count the lines of a text file (using the oddities
of the NEXT command)::

    100 OPEN#3,file
    110 FOR lines=0 TO 10000
    120   IF EOF(#3) THEN PRINT lines: EXIT lines
    130   INPUT #3,line$: NEXT lines
    140   PRINT 'OOPS - program is longer than 10000 lines!!'
    150 END FOR lines
    160 CLOSE#3

**Example 2**

The next example is a routine to nest a variable number (loops) of
times which go from Value\_min to Value\_max at Value\_step::

    100 FOR loop=1 TO loops:Value(loop)=Value_min(loop)
    110 REPeat Nesting
    120 <instructions using Value(1...s) go here>
    130   FOR loop=1 TO loops
    140     IF Value(loop)=Value_max(loop) THEN
    150       IF loop=loops THEN EXIT Nesting
    160       Value(loop)=Value_min(loop)
    170       NEXT loop
    180     ELSE
    190       Value(loop)=Value(loop)+Value_step(loop)
    200       EXIT loop
    210     END IF
    220   END FOR loop
    230 END REPeat Nesting

**NOTE 1**

If you use multiple in-line FOR loops in the same program line, only
the inner loop will be executed. For example::

    FOR i=1 TO 3: FOR j=1 TO 10: PRINT i*j: END FOR j

Output::

    1, 2, 3, 4, 5, 6, 7, 8, 9, 10

This will actually work correctly under SMS.

You can get it to work on a Minerva ROM and under
SMS (but not others) if the line is amended to read::

    FOR i=1 TO 3: FOR j=1 TO 10: PRINT i*j: END FOR j: END FOR i

In fact, SMS will even allow the line to work if it simply reads::

    FOR i=1 TO 3: FOR j=1 TO 10: PRINT i*j

**NOTE 2**

Unless you have SMS or a Minerva ROM, do not use GO SUB together with an
in-line FOR loop, because this will act as an END
FOR command and will not call the desired routine::

    100 FOR i=1 TO 10: PRINT 'Junk - test';: GO SUB 200: PRINT i
    110 STOP
    200 PRINT ' Number ';
    210 RETurn

**NOTE 3**

On JS (except ST/QL) and MGx ROMs, you cannot use the first of several
PROCedure/FuNction parameters as the loop identifier::

    100 TEST 5,10
    110 FOR j=1 TO 10: PRINT 'OOPS...'
    120 FOR k=1 TO 10: PRINT 'OKAY...'
    125 :
    130 DEFine PROCedure TEST(j,k)
    140   AT j,k:PRINT 'Errors .....'
    150 END DEFine

**NOTE 4**

No error will be reported and all should work okay if NEXT
is used instead of END FOR (unless you try to use EXIT which would
try to jump to the statement after the non-existent corresponding END
FOR, and may reach the end of the program without finding the END FOR,
therefore stopping without reporting any error), but you will have seen
that NEXT is intended for another purpose.

Apart from programming
elegance, compilers may not be able to understand your meaning (they
assume that you have forgotten the END FOR) and may abort compilation or
report a warning.

**NOTE 5**

Counting downwards without a negative step has no effect at all For example::

    FOR loop=0 TO -3

Omitting the STEP parameter is the same as STEP 1.

**MINERVA NOTES**

On a Minerva machine, a FOR loop can use either a single character
string variable or an integer variable::

    FOR A$='A' TO 'Z' STEP CHR$(2):PRINT A$;' ';

This prints out::

    A C E G I K M O Q S U W Y

::

    FOR loop%=1 TO 255: ...: END FOR loop%

This is a little quicker than::

    FOR loop=1 to 255: ...: END FOR loop

These examples will not work on other ROMs, unless you have SMS, even
if they will let you type them in!

**SMS NOTES**

Like Minerva, SMS will allow you to use integer variables in FOR loops
(but not string variables). As from v2.57, the range is checked to
ensure that it is within the valid word integer range (-327678..32767)
when the FOR loop is started, otherwise it returns 'Error in
Expression'.

If you try to use a string loop variable, the error
'unacceptable loop variable' is reported. EXIT, NEXT and END FOR do not
need to contain the loop identifier, SMS will presume that when used in
a program, they refer to the loop currently being executed.

**CROSS-REFERENCE**

:ref:`repeat` ... :ref:`end--repeat` is the other loop type. See also :ref:`end--for`.

--------------


