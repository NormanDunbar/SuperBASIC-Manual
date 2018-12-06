..  _a11-mathematics:

A11 Mathematics
===============

A11.1 Degrees and Radians
-------------------------

Normally an angle is expressed in so many degrees, for example 90
degrees is a right angle, 180 degrees is a straight line and 360 degrees
is a circle. Unfortunately for those of us mortals out there, the QL
works in a system of angles known as radians whereby a full circle
measures 2\*PI radians.

The diagrams make clear why 360 degrees and its multiples (720, 1080,
...) are identified with zero degrees.

::

    degrees:  0        90            180           270        360
    radians:  0       PI/2           PI          (3*PI)/2     2*PI

              |        |                            |          |
    diagram:  |        |                            |          |
              +        +-----    -----+-----    ----+          +

A programming hint: If you are calculating angles and receive values for
them where you have no guarantee that they are properly ranged, then use
the remainder from the full circle angle instead. Since MOD finds the
remainder for integers, you have simply to add a line such as::

    degrees = degrees MOD 360

or::

    degrees = MOD(degrees,360) (Math Package MOD)

for degrees, or::

    radians = radians-2 *PI *INT(radians/2/PI)

for radians.

Note however that every function and command dealing with angles
performs the same conversion internally or implicitly.

Just to make matters more confusing an angle in radians can be a maximum
of 2\*PI (which forms a circle). Thus PI is a straight line and PI/2 is
a right angle. The relation between degrees and radians is::

    radians = PI * degrees / 180

or::

    radians = RAD(degrees)

    degrees = 180 * radians / PI

or::

    degrees = DEG(radians)

The QL does include the functions DEG and RAD which enable you to
convert radians into degrees and degrees into radians (respectively).
Unfortunately, however, all of the QL mathematical functions expect
angles to be supplied in radians and therefore you must ensure that you
are working in the correct system if you are to track down errors.

A11.2 Triangles and Trigonometrics
----------------------------------

In order to explain some of the mathematical functions, you will need to
envisage a right-angled triangle whose height is y and whose base length
is x. Assuming that x is a line from the origin, the length of the line
between the points (0,0) and (x,y) (the hypotenuse) is h. The angle
formed between this line and the base line is theta radians. The maximum
value of theta is 90 degrees (PI/2).

::

               /+ (x, y)
              / |
             /  |
            /   |
           /    |
         h/     | y
         /      |
        /       |
       / theta  |
      +---------+-----+
    (0,0)  x  (x,0)

The following rules will give you an idea of the relationship between
the various lengths and angles::

    h^2 = x^2 + y^2

or::

    h = SQRT(x*x + y*y)

or::

    h = ABS(x,y): REMark Minvera only.
    x = h * COS(theta)
    y = h * SIN(theta)
    theta = ATAN (y/x)

or::

    theta = ATAN (x,y): REMark Minerva and SMS only.
    theta = ACOT (x/y)

or::

    theta = ACOT (y,x): REMark Minerva only.
    y = x * TAN(theta)
    x = y * COT(theta)
    theta = ACOS (x/h)
    theta = ASIN (y/h)

See the explanations of the keywords for details!

A11.3 Boolean Logic
-------------------

The QL supports boolean logic which can be used in order to avoid lots
of IF..END IF and SELect ON...END SELect structures. The idea behind
boolean logic is that a statement is used to calculate an expression,
which itself contains various logic operators and conditions. Please
refer to the Operators section of this appendix for the order in which
operators are calculated.

This can for example allow the following:

::

    100 start_timer = 10: timer=start_timer: max_timer=100
    110 REPeat loop
    120   timer = timer + (timer < max_timer) - (timer + 1 - start_timer) * (timer = max_timer)
    130   PRINT timer
    140 END REPeat loop

This program provides a timing counter, which counts from 10 up to 100
by one each pass of the loop and then re-starts at 10. Without boolean
logic, this would have to be re-written:

::

    100 start_timer = 10: timer = start_timer: max_timer=100
    110 REPeat loop
    120   timer = timer + 1
    130   PRINT timer
    140   IF timer = max_timer: timer = start_timer-1
    150 END REPeat loop

This works because boolean logic works through an expression using the
order of precedence (see the section on Operators). Whenever a
comparison is found, this is evaluated to either 1 (true) or 0 (false)
and then the rest of the expression evaluated. For example, x=y=0 will
not, as some users may think, set both x and y to 0, but will set x to 1
if y=0 and x to 0 if y<>0. Therefore looking at line 120 in the first
example, the following is carried out by the interpreter:

#. **timer =**... Note that we are assigning the final result to timer.

#. ... **timer**...Stack current value of timer.

#. ... **+(timer < max\_timer)** ...Calculate whether or not timer is less than
   max\_timer. If true, add 1 to current value of timer, else add 0.

#. ... **-(timer - start\_timer)** ...Stack the minus sign and then calculate
   the difference between the current value of timer and start\_timer
   (this is the amount which will need to be deducted from timer to make
   it equal to start\_timer).
   
#. ... **\*(timer=max\_timer)** Calculate whether or not timer is equal to
   max\_timer. If true, multiply the difference (from step 4) by 1,
   otherwise multiply it by 0.
   
#. Retrieve minus sign from stack and deduct value calculated in step 5
   from the current value of timer. Assign current value to actual
   variable timer.

A11.4 Operators
---------------

Operators provide the QL (and any other computer) with a means of
calculating an expression. An expression is always in the form:

term :sup:`\*`\ [operator term]\ :sup:`\*`

A list of available operators is set out below in order of precedence,
that is to say that when the interpreter comes to calculate the value of
an expression, which parts of the expression get calculated first. The
order of precedence may be over-ridden by using parenthesis (brackets) -
anything within a set of parenthesis gets calculated first, this is
known as a sub-expression. For example, take the following expression:

x\*y+(120-100-(50-20))

The interpreter will first of all calculate the value 50-20 which gives
30. Next, the interpreter needs to calculate 120-100-(30). As each
operator is the same, this is carried out in an order from left to
right, giving the value 20-30, in other words, -10.

This then leaves the interpreter with the expression x\*y+(-10) to
calculate. The multiplication operator takes precedence here, so the
interpreter calculates the value x\*y and then adds -10 to the result.
This means for example, that if x is 20 and y is 5, this expression will
return the value 90.

A term may be one of the following types:

-  variable
-  array element
-  FuNctions
-  strings
-  values
-  sub-expressions

A term may also be preceded by a Monadic Operator, which can be one of
the following:-

-  \+ this is a positive floating point. This can be omitted.

-  \- negate this floating point. eg. -x will if x=10 force this term to
   be equal to -10. However, if x=-10, this will force this term to be
   equal to 10.

-  NOT perform logical NOT on this floating point - eg. NOT xwill, if
   x=0 force this term to be equal to 1. If however, x<>0, this term
   will be equal to 0.

-  ~~ perform binary not on this integer - eg. ~~BIN('1001') will force
   this term to be equal to BIN('0110').

**NOTE 1**

On non-Minerva ROMs, monadic operators may only occur singly, which
prevented expressions such as x=- NOT x. Minerva now allows this, for
example, x%=-~~x% is the same as x%=x%+1 (this does not work with
floating point numbers as ~~ can only work on integer values).

**NOTE 2**

On non-Minerva ROMs, negative values (eg. x=-1) are stored as a monadic
positive operator, followed by a monadic negative operator. This no
longer works on Minerva which stores negative numbers as merely a
monadic negative operator.

Order of precedence of commands:

-  \+ monadic operator - positive number eg: ++100 is the same as +100

-  \- monadic operator - negative number eg: +-100 is the same as -100

-  & concatenates two strings together eg: 'Hello'&'World' => 'Hello
   World' (see Appendix 6.8)
   
-  INSTR returns position of one string inside another (this is normally
   case independent, but see INSTR\_CASE). Eg: 'world' INSTR 'Hello
   World' = 7
   
-  ^ raise a floating point to the power of another floating point eg:
   2^3=8
   
-  \* multiply a floating point by another floating point eg: 2\*3=6

-  / divide one floating point by another eg:10/5=2

-  MOD return one integer modulus another integer, eg: 11 MOD 5=1

-  DIV return the integer part of one integer divided by another eg:11
   DIV 5=2
   
-  \+ add two floating point numbers eg: 2+3=5

-  \- deduct a floating point from another eg: 2-5=-3

-  > compare two values - is the first greater than the second? eg:x>2
   for all values of x greater than 2
   
-  >= compare two values - is the first greater than or equal to the
   second? eg:x>=2 for all values of x which are not less than 2
   
-  = compare two values - is the first equal to the second?
   eg:'Hello'='HeLLo' is false
   
-  == compare two values - is the first approximately equal to the
   second? (numeric values are approximately equal if they are equal to
   one part in 1E-7, whereas string variables are approximately equal if
   all of the characters are the same {ignoring case}). However, do note
   that nothing can ever be ==0, ie. x==0 will never be true (unless x
   is exactly equal to zero (ie. x=0). Instead, try x+1==1. Examples:
   'Hello'=='HeLLo' is true '1.000000032'==1 is true
   
-  <> compare two values - is the first value different from the second?
   eg:'Hello'<>'HeLLo' is true
   
-  <= compare two values - is the first less than or equal to the
   second? eg:x<=2 for all values of x which are not greater than 2
   
-  < compare two values - is the first less than the second? eg: x<2 for
   all values of x which are less than 2
   
-  NOT monadic operator - logical not (see above) 

-  ~~ monadic operator - bitwise not (see above)
   
-  AND logical and - are two floating point expressions true? eg:x=1 AND
   y=1 is true if both x and y are 1.
   
-  && bitwise and - alter an integer value dependent upon a comparison
   bit by bit with the second integer value. eg:BIN('10001')&&BIN('111')
   returns BIN('00001')
   
-  OR logical or - are either one or the other of two floating point
   expressions true? eg: x=1 OR y=1 is true if either x or y are 1.
   
-  \|\| bitwise or - alter an integer value dependent upon a comparison
   bit by bit with the second integer value. eg:
   BIN('10001')\|\|BIN('111') returns BIN('10111')
   
-  XOR logical exclusive or - are either one or the other of two
   floating point expressions true (but not both)? eg: x=1 XOR y=1 is
   true if either x or y are 1, but false if both are 1 or some other
   value.
   
-  ^^ bitwise exclusive or - alter an integer value dependent upon a
   comparison bit by bit with the second integer value.
   eg:BIN('10001')^^BIN('111') returns BIN('10110')

A11.5 Hexadecimal and Binary Numbers
------------------------------------

The original QL ROM could only work with decimal numbers which could
cause some confusion when trying to work with machine code or using the
bitwise operators to compare two values.

Toolkit II alleviated this somewhat with the introduction of the HEX,
HEX$, BIN and BIN$ functions.

SMS and ST/QL Emulators (v1.27 of E-Init) have taken this one step
further, by allowing hexadecimal and binary numbers to appear directly
in SuperBASIC programs.

Hexadecimal numbers should be prefixed by the $ symbol, for example:

x=$4AFB is the same as x=19195

Binary numbers should be prefixed by the % symbol, for example:

x=%1010 is the same as x=10

**NOTE**

You need to process QREF\_BIN to work with these new number types.

MasterBasic v1.46+ and Turbo v4.3+ can also cope with them.

A11.6 Integers
--------------

QLs have always been able to understand and use integer arithmetic,
sometimes to speed up programs.

Minerva and SMS have extended the usefulness of the FOR and REPeat loops
to allow them to use integer loop identifiers, which can be much quicker
than using floating point identifiers (especially where the identifier
is used to address an array).

Minerva has also introduced Integer Tokenisation which (when enabled)
affects the way in which numbers are stored internally. This can both
reduce memory requirements (and the size of a compiled program under
Qliberator) as well as speed up programs. This can however cause
problems - see QLOAD and POKE.

**NOTE**

Prior to v2.66 of SMS a=b%\*c% would produce an overflow error where the
result exceeded 32768.

Problems also existed where a=i%+j% and a<0 prior to v2.74.

There were also some other problems with integer arithmetic in versions
prior to v2.31.

A11.7 Faster Mathematics
------------------------

There are several ways of speeding up the QL's mathematics routines,
such as using a faster processor (including some emulators and the THOR
21 Computer), SMSQ/E, Minerva or Lightning (a program by Digital
Precision). You can even mix these together to get more improvement.

However, you can also use any maths co-processor which may be attached
to your computer (see PROCESSOR) to speed up the routines substantially.

In order to do this, you will need to obtain the FPSAVE public domain
toolkit together with an appropriate FPSP file (and also have a maths
co-processor present - this is in-built on full 68040 and 68060 chips).
You cannot use a maths co- processor with the original QL or with a Gold
Card. If you have a QXL you will need to upgrade the 68040 chip to the
full-blown model. However, the Atari TT and Falcon machines, the THOR 21
and 32 bit Amiga machines have either built in maths co-processors or
sockets to take them.

The FPSAVE toolkit includes a set of functions which will replace the
QL's native maths routines by faster ones which use the co-processor as
well as another file containing the same functions prefixed with the
letter F so that you can use both if you so wish. Unfortunately there
are currently problems with using this toolkit on the Atari computers
and you should use a copy of FPSAVE v1.17 at least to ensure that no
other problems are encountered.

The functions which are speeded up by FPSAVE are:

ACOS, ACOT, ASIN, ATAN, COS, COT, EXP, LOG10, LN, SIN, SQRT, TAN

A11.8 Precision
---------------

The main problem with the QL's mathematics routines is the limited
precision which is used by the native mathematics routines. Although the
internal routines use a precision of at least 9 decimal places to
calculate results, the Basic interpreter and PRINT commands will only
accept figures six digits long for integers and seven digits long for
floating point numbers. Any greater numbers are converted by PRINT and
the interpreter to exponential notation, which means that the whole
number is not stored.

To overcome this problem, you can either use Turbo or Supercharge to
compile the program (these allow up to nine digits) or, if the number is
to be stored within a BASIC program, place it in quote marks (as with
the first example for the SCALE command).
