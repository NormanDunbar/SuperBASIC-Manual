..  _define--function:

DEFine FuNction
===============

+----------+--------------------------------------------------------------------------------+
| Syntax   | DEFine FuNction name[$ \| %] [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] |
+----------+--------------------------------------------------------------------------------+
| Location |QL ROM                                                                          |
+----------+--------------------------------------------------------------------------------+


This command marks the beginning of the SuperBASIC structure which is
used to surround lines of SuperBASIC code which forms an equivalent to a
machine code function, which can be called from within SuperBASIC and
will return a value dependent upon the code contained within the
structure. The syntax of the SuperBASIC structure can take two forms:

--------------

DEFine FuNction name[$ \| %] [(item\ :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*`\ )]: statement
:sup:`\*`\ [:statement]\ :sup:`\*`:RETurn value

or

DEFine FuNction name[$ \| %] [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] :sup:`\*`\ [LOCal var
:sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*`]\ :sup:`\*` :sup:`\*`\ [statements]\ :sup:`\*` RETurn value END DEFine [name]

--------------

When the specified function name is
called, the interpreter will search the SuperBASIC program for the
related DEFine FuNction statement.

If a related DEFine FuNction cannot be found, then the
interpreter will search for a machine code function of that name.

If the definition of name cannot be found, then the error 'Not Found' will be
reported if name was defined in the past, but the definition line has
since been deleted.

If name has never been defined in the current SuperBASIC program, then it will be treated as a normal variable and
relevant error messages reported.

Under SMS in both instances the value
0 will be returned (name is treated as an undefined variable).

The method of searching for a FuNction means that if a SuperBASIC FuNction
is defined with the same name as a machine code one, the machine code
one will no longer be available, and when the SuperBASIC FuNction is
removed (for example with NEW), that keyword will no longer have any
effect. If entered as a direct command, even the in-line structure will
not have any effect unless it is also called on the same line, as the
interpreter must jump to the relevant DEFine FuNction statement when the function is called.

If a DEFine FuNction statement
appears in a program, if the code is not called, program flow will
continue from the statement following the next END DEFine - it is
however good practice to keep all definition structures towards the end
of a program, and not to place the structure blocks in the middle of
program code, as this makes it very difficult to follow the flow of
programs.

It is also good programming practice to make FuNctions
self-contained and not to jump out of them using GO TOs or GO SUBs (they
can of course call other FuNctions and PROCedures).

To call the DEFine FuNction, you merely need to include its name in an expression. If
however any parameters are listed in the definition, you will need to
pass the same number of parameters in brackets after the name of the
FuNction, separated by any valid SuperBASIC separator {ie. comma (,),
semicolon (;), backslash (\\), exclamation mark (!) or TO }. You can
also place a hash (#) before the parameters if you so wish to indicate
that it is a channel number.

If not enough parameters are supplied, the
program will report 'Error in Expression' when the missing parameter is
used, except under SMS where the missing parameters are treated as unset
variables and will therefore have the value 0 (if a numeric variable) or
else contain an empty string (if a string variable).

If however, too
many parameters are passed, the extra parameters are ignored. Parameters
are passed by reference which means that the list of items in the DEFine
FuNction statement are deemed LOCal to that definition - this means that
any previous values of the items are stored whilst the definition block
is active. What is more, the type of each item does not actually matter
- they assume the type of the passed parameter. For example, the
following short program will work without any problems::

    10 a$=QUERY$('What is your name')
    20 DEFine FuNction QUERY$(x)
    30   INPUT (x)!b$
    40   RETurn b$
    50 END DEFine

Note though that the name of the FuNction must end with the correct
variable type, ie. $ if a string is to be returned, or % if an integer
is to be returned (although see note 7 below).

One of the results of
passing variables by reference is that if the item is altered within the
definition block, if a variable is passed as a parameter, the variable
itself will also be altered (although see note 4). This can be shown
with the following short program::

    100 x=10
    110 y=Square(x)
    120 PRINT x;'^2=';y
    130 DEFine FuNction Square(za)
    140   za=za*za
    150   RETurn za
    160 END DEFine

This can be avoided by either assigning the item to a temporary
variable and then using the temporary variable instead (see the example
below), or by passing the variable as an expression, by placing it
inside brackets; for example by replacing line 110 with the following::


    110 y=Square((x))

Having passed the necessary parameters to the Function, you can then use
each item inside the definition block as normal.


**Example**

A short program to calculate the length of the hypotenuse in a triangle,
given the length of its two other sides::

    100 MODE 4: WINDOW 448,200,32,16: SCALE 100,0,0: PAPER 0 105 CLS: INK 7
    110 AT 2,25: UNDER 1: PRINT'Pythagoras calculator': UNDER 0
    120 INPUT \\'Enter length of base of triangle:'!base
    130 INPUT \\'Enter height of triangle:'!height
    140 hypotenuse=Pythag(base,height)
    150 INK 4: LINE 50,20 TO 100,20 TO 100,70 TO 50,20
    160 INK 7: AT 16,35-LEN(base): PRINT base
    170 AT 11,46: PRINT height
    180 AT 11,31-LEN(hypotenuse): PRINT hypotenuse
    190 :
    1000 DEFine FuNction Pythag(x,y)
    1010   LOCal x1,y1
    1020   x1=x*x:y1=y*y
    1030   RETurn SQRT(x1+y1)
    1040 END DEFine

See what happens if you replace lines 1000 to 1040 with the following::

    1000 DEFine FuNction Pythag(x,y)
    1010   x=x*x:y=y*y
    1020   RETurn SQRT(x*y)
    1030 END DEFine


**NOTE 1**

A FuNction must return a value under all circumstances. If the END
DEFine is reached without a value having been returned then SuperBASIC
will report an 'error in expression' (-17), specifying the error as
having occured at the line containing the END DEFine.

Under SMS the
error 'RETurn not in PROCedure or FuNction' will be reported instead.


**NOTE 2**

On pre JS ROMs, you could not define new FuNctions with names which had
already been used in the same program.


**NOTE 3**

On pre MG ROMs, any more than nine parameters may upset the program,
corrupting it by replacing names with PRINT towards the end of a
program. This can however be circumvented by increasing the size of the
Name Table by 8 bytes for each name (plus a little more for luck), using
the line::

    CALL PEEK_W(282)+36,N


**NOTE 4**

Although a sub-set of a simple string is an expression and therefore
will not be altered within a function, a sub-set of a DIMensioned string
is not treated as an expression and will therefore be altered!!


**NOTE 5**

Recursive FuNctions (ie. FuNctions which call themselves, or call
another PROCedure or FuNction which in turn calls the original FuNction)
are allowed (up to 32767 recursions under Minerva). They do however
gobble up memory at an amazing rate and can cause problems in compiled
SuperBASIC due to the fact that they need an ever-increasing amount of
stack space. They should be avoided wherever possible because they are
also very slow.

On SMS, if you try to use recursive functions too much,
you may end up with the rather esoteric error 'program structures nested
too deeply, my brain hurts'! It is however, more likely that you will
end up with an 'Out of Error' memory and not be able to do anything else
(not even NEW).


**NOTE 6**

The LOCal statement (if used) must appear as the next statement
following DEFine FuNction, otherwise an error will be reported. Under
SMS if this is not the case, the error 'Misplaced LOCal' will be
reported.


**NOTE 7**

SMS and QLiberator do not seem to mind if you do not end the FuNction
name with a $ symbol when a string is to be returned and the FuNction
will work perfectly well in the compiled version of the program.
However, this should be avoided as the program will not work on other QL
ROMs and also cannot be compiled with TURBO. For example, take the
following program, which works under SMS or when QLiberated.

For other
ROMs and TURBO, rename the function to GETSUBDIR$::

    100 file$='n1_win2_test_bas'
    110 test$=GETSUBDIR(file$)
    295 :
    300 DEFine FuNction GETSUBDIR(s$)
    310   IF s$(LEN(s$))<>'_':s$=s$&'_'
    320   IF LEN(s$)=5:IF s$(4) INSTR '1234567890':RETurn ''
    322   REPeat t_loop
    325     root=1
    330     FOR x=1 TO LEN(s$)
    340       IF s$(x)='_'
    350       IF x=3:IF s$(2) INSTR '1234567890':root=3
    360       IF x=5:IF s$(4) INSTR '1234567890':root=5
    370       IF x>5:IF root=1:s$=PROGD$ & s$:NEXT t_loop
    380       IF x=8:IF root=3:root=8
    390       END IF
    400     NEXT x
    410       IF root=1:s$=PROGD$ & s$:NEXT t_loop
    415       as$=s$
    420       IF root=3:s$=s$(1 TO 3) & PROGD$
    425       IF root=3:IF LEN(as$)>3:s$=s$&as$(4 TO):NEXT t_loop:ELSE EXIT t_loop
    430     END FOR x
    435     EXIT t_loop
    440   END REPeat t_loop
    445   as$=s$
    460   RETurn s$(1 to root)
    470 END DEFine


**NOTE 8**

Do not try to DEFine one FuNction inside another - although this is
actually allowed under most implementations, compilers presume that an
END DEFine should be placed before the start of the next DEFine FuNction
and it makes programs very difficult to follow.

Under SMS the error
'Defines may not be within other clauses' will be reported when you try
to RUN the program.


**NOTE 9**

On Minerva pre v1.96, if you try to link in machine code procedures or
functions from inside a DEFine PROCedure or DEFine FuNction block, problems could occur after a CLEAR command.

**WARNING 1**

On most ROMs (at least on JM, MGx, AH and Minerva up to v1.97), a single
line recursive FuNction will not respond to the break key. For example::

    10 DEFine FuNction Root(a): a=2^Root(a)

The solution for all ROMs (or all those tested so far!) - insert an additional colon (:) as in::

    10 DEFine FuNction Root(a)::a=2^Root(a)

This is fixed on SMS v2.59+.

**WARNING 2**

All ROMs also suffer from this problem on multiple line recursive
FuNctions, where there is no active program line between the definition
line and the line which calls the FuNction. For example::

    10 DEFine FuNction Root(a)
    20   a = 2^Root(a)
    30 END DEFine

The solution here is to insert another active program line at line 15 -
for example::

    15 :

or::

    15 PRINT

Do however note that a REMark, DATA or LOCal line at line 15 will not
be sufficient as these are not active commands. Again, this is fixed
under SMS v2.59.


**WARNING 3**

Except under SMS, if you assign the same name to a FuNction as a resident command, not only will you no longer be able to use the
resident command, but it may crash the system!


**SMS NOTES**

In v2.59+, if you fail to create a SuperBASIC function correctly, the
error INCOMPLETE DEFine appears (for example if you omit the END
DEFine). Prior to v2.89 SMS would only allow a single line DEFine
FuNction if END DEFine appeared on the same line. However, although
v2.89 would allow a single-line DEFine FuNction without an END DEFine ,
it would report an error if the END DEFine existed!! Thankfully, v2.90+
fixes this problem, allowing both.


**CROSS-REFERENCE**

:ref:`end--define` tells the interpreter where
the end of the definition block can be found.
:ref:`return` allows you to return the result of
the Function. :ref:`define--procedure`
is very similar. :ref:`local` allows you to assign
temporary variables with the same name as variables used outside the
definition block. :ref:`paruse` and
:ref:`partyp` allow you to examine the type of the
parameters which are passed to the definition block.

--------------


