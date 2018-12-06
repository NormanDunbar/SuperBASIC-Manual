..  _dim:

DIM
===

+----------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | DIM array (index1 :sup:`\*`\ [index\ :sup:`i`]\ :sup:`\*` ) :sup:`\*`\ [,array\ :sup:`j` (index :sup:`\*`\ [index\ :sup:`j`]\ :sup:`\*` )]\ :sup:`\*` |
+----------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
| Location |QL ROM                                                                                                                                                 |
+----------+-------------------------------------------------------------------------------------------------------------------------------------------------------+

The command DIM allows you to set up one or more SuperBASIC arrays
which may be of string, integer or floating point type. Each index must
be an integer in the range 0...32767.

Numeric Arrays
~~~~~~~~~~~~~~

Each index defines the maximum number of elements (less one) in any one
direction, which provides the following examples::

    DIM a(10)

sets up a floating-point array a containing 11 elements, a(0) to a(10);

::

    DIM z%(10,10)

sets up a two dimensional integer array z% containing 121 elements,
z%(0,0) to z%(10,10) Each element can hold a different number which can
later be accessed by specific reference to each index. When the array is
set up, each element is set to zero.

String Arrays
~~~~~~~~~~~~~

String arrays are peculiar and have various differences to both
un-dimensioned strings and number arrays.

In a string array, the final
index contains the maximum length of a string, rounded up to the next
even number (an attempt to assign a longer string to one of the array
elements will result in a truncated string). For example::

    DIM a$(10)

sets up a one-dimensional string array a$ with a maximum of 10
characters. This is similar to a$=FILL$(" ",10), except that a$ now has
a maximum length;

::

    DIM z$(10,9)

sets up a two-dimensional string array, which can hold 11 strings
(z$(0) to z$(10)), each up to 9 characters long.

When a string array is
set up with DIM, each entry is set to a nul string (""). The zero'th
element of each string array contains the actual length of that string,
for example::

    DIM a$(10,10): a$(1)='Hello': PRINT a$(1,0)

will return the value 5, as will PRINT LEN(a$(1)).

If a$ is
undimensioned and a$='Hello World', PRINT a$(0) does not generally work
and will result in an 'Out of Range' error, except under SMS v2.60+ and
Minerva where PRINT a$(0) is the same as PRINT LEN(a$).

Sub-Sets of Arrays
~~~~~~~~~~~~~~~~~~

Sub-sets of arrays can also be accessed, for example::

    PRINT z$(0 TO 2)

will print the first three strings stored in the array z$.

Omitting Indices
~~~~~~~~~~~~~~~~

This can be one of the most difficult parts of SuperBasic from the point
of view of making programs compatible on all implementations of
SuperBASIC and also making programs work the same under the interpreter
and when compiled.

The ST/QL Emulators (with E-Init v1.27 or later)
follow the same rules as SMS. If an index is omitted, SuperBASIC inserts
a default index of::

    0 TO DIMN (array,index_no)

For example, if array is a two-dimensional array, array(1) is the same
as using the form array (1,0 TO DIMN(array,2)). Unfortunately, string
arrays are slightly different when using the last index.

If the last
index is omitted, this defaults to an index of::

    1 TO LEN(array$(x))

However, except on SMS, if a start descriptor is specified, but not an
end one, the last index defaults once again to: start\_descriptor TO
DIMN(array$,index\_no). On SMS this defaults to start\_descriptor TO LEN(array$(x).

Even more oddly, except on SMS and Minerva, if a start descriptor is
omitted, but an end descriptor specified, the index defaults to: 0 TO
end\_descriptor normally resulting in an error. (On SMS and Minerva this defaults to 1
TO end\_descriptor).

However, except on SMS and Minerva, if neither a
start nor end descriptor are specified, but the TO itself is specified,
this defaults to 0 TO DIMN (array$,index\_no), again normally causing an
error.

On SMS this defaults to 1 TO LEN (Array$ (x)

On Minerva this defaults to 1 TO DIMN (array$,index\_no)

This creates the following result::

    DIM a$(10):a$='Hello' INK 7:PAPER 0
    STRIP 2

::

    PRINT a$

Prints 'Hello' => a$ (1 TO LEN(a$) (On all implementations)

::

    PRINT a$(1 TO)

Prints 'Hello ' => a$(1 TO DIMN(a$,1)) (except on SMS, where it prints
'Hello', unless the program is compiled with Qliberator in which case
the original system is adopted).

::

    PRINT a$(TO)

Results in 'Out of Range' => a$(0 TO DIMN(a$,1)) (except on SMS, where
it prints 'Hello', and on Minerva where it prints 'Hello ' In both
cases, if the program is compiled with Qliberator it still reports an
error).

::

    PRINT a$( TO 5)

Results in 'Out of Range' => a$(0 TO 5) (again on SMS and Minerva it
still prints 'Hello', unless the program is compiled with Qliberator,
which reports an error).

Un-Dimensioned Strings
~~~~~~~~~~~~~~~~~~~~~~

You can use sub-sets of un-dimensioned strings, for example::

    a$='Hello World':PRINT a$(1 TO 5)

However, such subsets are always treated as expressions, which means
that if such a subset was passed as a parameter to a FuNction or
PROCedure (see DEFine FuNction), it cannot be passed by reference and
the string will remain unaltered by the FuNction/PROCedure.

Compare this
with a sub-set of a string array, which will be altered (this sub-set
exists as a sub-array). Please see Example 3 below.

The handling of
descriptors is also different with un-dimensioned strings. If neither a
start nor an end descriptor are specified, this, like string arrays,
defaults to::

    1 TO LEN(string$)

However, if the start descriptor is specified, but not the end
descriptor, this defaults to::

    start_descriptor TO LEN(string$)

However, if the start descriptor is omitted (whether the end descriptor
is specified or just TO is used), unless you have Minerva or SMS, this
defaults to::

    0 TO end_descriptor

and::

    0 TO LEN(string$)

respectively, both of which cause an 'out of range' error.

On Minerva
and SMS however, this defaults to::

    1 TO end_descriptor

and::

    1 TO LEN(string$)

respectively, thus avoiding this error.

This leads to the following result::

    CLEAR
    x$='Hello'
    INK 7: PAPER 0: STRIP 2

::

    PRINT x$

This Prints 'Hello'.

::

    PRINT x$(1 TO)

This prints 'Hello'

::

    PRINT x$(TO)

This results in 'Out of Range' or 'Hello' on Minerva and SMS.

::

    PRINT x$( TO 10)

This results in 'Out of Range' or 'Hello' on Minerva and SMS.


ERRORS
~~~~~~

Due to the complexity of DIM, we felt that it would be useful to explain
some of the various errors which may be reported. SMS has an improved
Interpreter which reports more intelligible error codes, therefore those
have been used:

**Only arrays may be dimensioned**

This occurs when you try to DIM the name of a procedure or function. It
also occurs if you try to use DIM on one of the parameters of a
procedure or function and that parameter is not itself a dimensioned
variable::

    100 DIM x(10)
    110 c=1:test x,1
    130 DEFine PROCedure test (a,b)
    140   DIM b(10)
    150 END DEFine

 On other implementations, 'Bad Name' is reported in both instances.

**Procedure and function parameters may not be dimensioned**

This only happens as in the example above where you try to DIMension a
variable which is in fact one of the parameters from the DEFine
PROCedure or DEFine FuNction line (eg. line 140). Here, if you pass a
dimensioned variable, eg: TEST 1,x, you get this error under SMS. Also
see note 7. On other implementations no error is reported and the
problems listed in Note 7 occur.

**SBASIC cannot put up with negative dimensions**

This occurs if you try to use a negative index, for example: DIM x(-10)
On other implementations 'Out of Range' is reported.

**Dimensional overflow - you cannot be serious!**

Too many indices have been specified in the DIM statement - refer to
Appendix 8.

**Error in Expression**

SMS has either been unable to make any sense of the index, or else it
exceeds 32767. On other ROMs you will get the error 'Overflow' if index
exceeds 32767.

**Unknown function or array**

This is generally reported of you try to use a Procedure name as the
index. Other implementations report 'Error in Expression'

EXAMPLES
~~~~~~~~

**Example 1**

A program which acts as a simple quiz program, but shows off some of the
best features of using arrays - it is simplicity itself to add new
questions and answers to this quiz (just amend quest and target and add
the new questions and answers as DATA at the end of the program)::

    100 MODE 8:WINDOW 512,256,0,0:PAPER 0:CLS
    110 WINDOW 448,200,32,16
    120 quest=5:target=5
    130 DIM question$(quest,50),option$(quest,3,25),answer(quest)
    140 RESTORE
    150 FOR i=0 TO quest-1
    160   READ question$(i)
    170   FOR j=1 TO 3:READ option$(i,j)
    180   READ answer(i)
    190 END FOR i
    200 REPeat main_loop
    210   score=0
    220   FOR i=1 TO 7,1:BORDER 10,i:PAUSE 2
    230   PAPER 6:CLS:INK 2:AT 3,10:UNDER 1:CSIZE 2,1
    240   PRINT 'QUIZ EXAMPLE':CSIZE 2,0:UNDER 0
    250   INK 0:AT 0,20:PRINT 'SCORE = ';score
    260   DIM asked(quest)
    270   REPeat loop
    280     opt=RND(1 TO quest)
    290     IF asked(opt)=1 THEN
    300       FOR j=1 TO quest
    310         IF asked(j)=0:opt=j:EXIT j
    320         NEXT j
    330         DIM asked(quest):NEXT loop
    340       END FOR j
    350     END IF
    360     asked(opt)=1
    370     AT 4,0:CLS 2
    380     ask_question(opt)
    390     reply=get_answer
    400     AT 16,0:PAPER 2:INK 7
    410     IF reply=answer(opt-1)
    420       PRINT 'Correct':score=score+1
    430     ELSE
    440       PRINT 'Wrong!':score=score-1
    450     END IF
    460     PAPER 6:INK 0
    470     AT 0,20:PRINT 'SCORE = ';score
    480     PAUSE
    490     IF score=target OR score<0:EXIT loop
    500   END REPeat loop
    510   PAPER 0:CLS
    520   INK 2+2*(score=target):CSIZE 3,1
    530   IF score=target
    540     PRINT 'Congratulations'
    550   ELSE
    560     PRINT 'Oh Dear'
    570   END IF
    580   CSIZE 2,0:INK 7
    590   PRINT \\'Try again?? -----> y/n'
    600   REPeat keys
    610     key$=INKEY$(-1):IF key$ INSTR 'yn':EXIT keys
    620   END REPeat keys
    630   IF key$=='n':STOP
    640 END REPeat main_loop
    645 :
    650 DEFine PROCedure ask_question(no)
    660   LOCal i
    670   AT 6,0:start_word=1:end_word=1
    680   no=no-1
    690   REPeat quest_loop
    700     FOR char=start_word TO question$(no,0)
    710       IF question$(no,char)=' ':EXIT char
    720     END FOR char
    730     end_word=char
    740     PRINT !question$(no,start_word TO end_word)!
    750     IF end_word=question$(no,0):EXIT quest_loop
    760     start_word=end_word+1
    770   END REPeat quest_loop
    780   REPeat opt_loop
    790     PRINT \
    800     FOR i=1 TO 3
    810       PRINT TO 5;i;' = ';option$(no,i)
    820     END FOR i
    830 END DEFine
    835 :
    840 DEFine FuNction get_answer
    850   REPeat keys
    860     key$=INKEY$(-1)
    870     IF key$ INSTR '123':RETurn key$
    880   END REPeat keys
    890 END DEFine
    895 :
    900 DATA 'The standard Sinclair QL has how much memory?'
    910 DATA '16K','128K','640K',2
    920 DATA "What was the name of Sinclair's first computer?"
    930 DATA 'Z80','ZX81','ZX80',3
    940 DATA 'Who is the main person responsible for QDOS?'
    950 DATA 'T.Tebby','J.Jones','C.Sinclair',1
    960 DATA "Which company created the QL's Gold Card?"
    970 DATA 'Miracle Ltd.','Digital Precision Ltd.','Mercury',1
    980 DATA 'Who is the main person responsible for SuperBASIC?'
    990 DATA 'T.Tebby','J.Jones','C.Sinclair',2

Some of you may have noticed that we have used DIM option$(quest,3,25)
when we could have used DIM option$(quest,2,25). The reason for this is
to make it easier to check the text - try PRINT option$ and you will see
that each set of three options is separated by a blank string.


**Example 2**

Take the two arrays set up with::

    DIM x(2,3,4),x$(2,4,6).

The following
sub-arrays produce the following equivalents::

    x(TO, TO 2, 1 TO) => x(0TO 2,0 TO 2,1 TO 4)
    x$(1 TO 2, TO 2) => x$(1 TO 2,0 TO 2,1 TO LEN(x$(..)))
    x$(TO 2, TO,1 TO) => x$(0 TO 2,0 TO 4,1 TO 6)


**Example 3**

A short example of the use of sub-arrays and subsets of undimensioned
strings::

    100 DIM a$(11)
    110 a$='Hello World'
    120 b$='Great World'
    130 swap_array a$(1 TO 5),b$(1 TO 5)
    140 PRINT a$,b$
    150 :
    1000 DEFine PROCedure swap_array (a,b)
    1010   c$=b: b=a: a=c$
    1020 END DEFine


**NOTE 1**

The Turbo compiler alters DIM in compiled programs to enable you to
re-dimension arrays without losing their original contents. You may
therefore need to physically set the contents of arrays to zero (or nul
strings) to ensure that a program works properly when compiled.


**NOTE 2**

On AH ROMs, a floating point array is limited to 384K size.


**NOTE 3**

A variable cannot be used as both a simple variable and an array
variable. It is set to an array variable as soon as the line containing
the relevant DIM statement is parsed. This means that if a line
containing DIM var has been entered, the array var cannot be used until
such time as the program has RUN this line, and in any case, an attempt to use var without array
descriptors (eg. var=1) is likely to fail, either resulting in a 'Bad
Name' error or 'Error in Expression'.


**NOTE 4**

You cannot assign one array to another. For example::

    DIM a$ (3,10) , z$(3,10) :z$=a$

will report a 'Not Implemented' error.

Compare::

    z$ ( 1, 1 TO 10 )=a$ (1, 1 TO 10 ).


**NOTE 5**

The Turbo and Supercharge compilers insist that strings are all
dimensioned as string arrays. They do however also alter the way in
which string arrays work so that they operate more like un-dimensioned
strings. Un-dimensioned strings may also upset Qliberated tasks!


**NOTE 6**

On pre JS ROMs you cannot use one array as the array sub-script of
another in the DIM statement (other than as the first sub-script), for
example::

    DIM a(10):a(3)=10
    DIM a$(10,a(3))

If you try this, you will find that previous array sub-scripts are set
to the value 0, ie. using the above example, a$(0) would be acceptable,
whereas a$(2) would cause an error. This will work okay provided that
the array is used as the first sub-script, otherwise use a temporary
variable. For example::

    subs=a(3): DIM a$(10,subs)
    DIM a$(a(3),10)

would both work okay on all ROM versions.


**NOTE 7**

There is a bug in SMS (at least up to v2.88) if you try to DIMension a
variable which has been used as a parameter for a PROCedure or FuNction
call.

Take the example given above to demonstrate the error 'procedure
and function parameters may not be dimensioned'. Now use::

    CLEAR : TEST a,b

no error is reported (although line 140 has no effect).

::

    PRINT a,b

is equivalent to PRINT a; and any attempt to use b (eg. x=b) reports
error in expression, even after CLEAR.

On other ROMs no error is
reported. However, the variable passed as a parameter is not
re-dimensioned, but some of its elements will no longer be the original
value, but very small numbers and any attempt to assign another value to
those elements which have been changed may in fact fail!!


**NOTE 8**

Current versions of Qliberator treat all strings in the same way as on
the original QL, therefore although a program may RUN fine under the SMS
or Minerva intepreter, it may cause problems when compiled. The TURBO
and SuperCHARGE compilers treat strings the same as SMS, except see Note
1 and Note 5.


**MINERVA NOTE**

Minerva alters the way in which both dimensioned and undimensioned
strings are handled so that::

    PRINT a$( TO 10)

is now acceptable! See above.

Minerva also allows you to slice expressions and numbers. Lines
such as::

    PRINT 'abcd' (2 TO 3)

and::

    a$=101010 (3)

will now work. Minerva v1.96+ allows multiple index lists (see SMS Notes).


**SMS NOTES**

SMS alters the way in which both undimensioned and dimensioned strings
are handled to make them more sensible (see above). We now await a
compiler which handles strings in the same way! SMS says that it no
longer handles multiple index lists on assignments (which apparently
were allowed on earlier ROM versions - did anyone ever use these?). An
example is the line::

    100 DIM a$(3,4,5)
    110 a$(3,4)='Hello'
    120 a$(3,4)(2 TO 5)='ELLO'

SMS will not let you type in line 120 reporting invalid syntax. To
overcome this you have to replace the line with::

    120 a$(3,4,2 TO 5)='ELLO'

In common with Minerva, SMS will now also allow you to slice
expressions and numbers. There is a bug in current versions of SMS (at
least up to v2.90) when passing string array sub-sets by reference, for
example the following program::

    5 DIM x$(11)
    10 x$='Hello World'
    15 PRINT x$
    20 change x$(1 TO 11)
    30 PRINT x$
    40 :
    1000 DEFine PROCedure change (a$)
    1010   a$(1 TO 3)='EXT'
    1020 END DEFine

At line 30, x$ is shown to be 'HeEXT World'?? It should be 'EXTlo
World'. Try making line 20 read::

    20 change x$

Although v2.90 fixes this problem, if you pass a sub-set of an
undimensioned string, a worse problem is created. Try deleting line 5
and adding line::

    1015 PRINT a$: PAUSE

before RUNning the program (you may need to use CLEAR beforehand).


**WARNING**

DIM and dimensioned variables can crash the system in certain instances
- refer to A8.4 for details of the possible problems and more error
messages which can be generated.


**CROSS-REFERENCE**

:ref:`dimn` allows you to find out the maximum sizes
of an array. Please see the Appendix on Compatability concerning String
Lengths. :ref:`len` allows you to find the length of a
string.

