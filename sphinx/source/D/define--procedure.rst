..  _define--procedure:

DEFine PROCedure
================

+----------+-------------------------------------------------------------------------+
| Syntax   | DEFine PROCedure name [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] |
+----------+-------------------------------------------------------------------------+
| Location | QL ROM                                                                  |
+----------+-------------------------------------------------------------------------+

This command marks the beginning of the SuperBASIC structure which is
used to surround lines of SuperBASIC code which forms an equivalent to a
machine code SuperBASIC procedure, which can be called from within
SuperBASIC as a sub-routine. This forms a powerful alternative to GO SUB
and helps to make SuperBASIC programs very easy to read and de-bug.

The syntax of the SuperBASIC structure can take two forms:

--------------

DEFine PROCedure name [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )]: statement
:sup:`\*`\ [:statement]\ :sup:`\*`

or

DEFine PROCedure name [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] :sup:`\*`\ [LOCal var
:sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*` ]\ :sup:`\*` :sup:`\*`\ [statements]\ :sup:`\*` [RETurn] END DEFine [name]

--------------


When the specified procedure name is
called, the interpreter then searches the SuperBASIC program for the
related DEFine PROCedure statement.

If this cannot be found, then the
interpreter will look for a machine code procedure of that name.

If the
definition of name cannot be found, then the error 'Not Found' will be
reported if name was defined in the past, but the definition line has
since been deleted.

If name has never been defined in the current
SuperBASIC program, then the 'Bad Name' error will be reported. As with
FuNctions, the method of searching means that a machine code PROCedure
can be overwritten with a SuperBASIC definition and then later lost.
Parameters and items are treated in the same manner as with DEFine
FuNction. However, please note that calling parameters should not appear
in brackets after the name (unless you intend to pass them otherwise
than by reference!).

When called, all of the SuperBASIC code within the
definition block will be executed until either an END DEFine or RETurn
is found, in which case execution will return to the statement after the
calling statement. In contrast however, to DEFine FuNction, there is no
need for a PROCedure definition block to contain a RETurn statement.


Strictly a PROCedure cannot return a value - however due to the nature
of the parameters being passed by reference (see DEFine FuNction), this
*is* possible.


**Example**

A simple demonstration program which highlights the fact that a
PROCedure or FuNction can actually be recursive (ie. call itself), and
also highlights the effect of passing parameters by reference - keep an
eye on the values in #0::

    100 radius=50:height=125:CLS:CLS#0
    110 Rndom_circle radius,(height),100
    120 AT #0,0,0:PRINT#0,radius,height,100
    125 :
    130 DEFine PROCedure Rndom_circle(x,y,z)
    140   INK RND(7):FILL RND(1)
    150   CIRCLE RND (y),RND(z),x
    160   FILL 0
    170   AT #0,0,0:PRINT#0,x,y,z:PAUSE
    180   x=x-RND(5):y=y-1:z=z+1
    190   IF x<1:RETurn
    200   Rndom_circle (x),y,z
    210 END DEFine


**NOTE 1**

On pre JS ROMs, you could not define new PROCedures with names which had
already been used in the same program.


**NOTE 2**

On pre MG ROMs, any more than nine parameters may upset the program,
corrupting it by replacing names with PRINT towards the end of a
program. This can however be circumvented by increasing the size of the
Name Table by 8 bytes for each name (plus a little more for luck), using
the line::

    CALL PEEK_W(282)+36,N


**NOTE 3**

Recursive PROCedures (ie. PROCedures which call themselves, or call
another PROCedure or FuNction which in turn calls the original
PROCedure) are allowed (up to 32767 recursions on Minerva). They do
however gobble up memory at an amazing rate and can cause problems in
compiled SuperBASIC due to the fact that they need an ever-increasing
amount of stack space. They should be avoided wherever possible. On SMS,
if you try to use recursive functions too much, you may end up with the
error 'program structures nested too deeply, my brain hurts'! It is
however, more likely that you will end up with an 'Out of Memory' error
and not be able to do anything else (not even NEW).


**NOTE 4**

The LOCal statement (if used) must appear as the next statement
following DEFine PROCedure, otherwise an error will be reported. Under
SMS if this is not the case, the error 'Misplaced LOCal' will be
reported.


**NOTE 5**

Do not try to DEFine one PROCedure inside another - although this is
actually allowed under most implementations, compilers presume that an
END DEFine should be placed before the start of the next DEFine
PROCedure and it makes programs very difficult to follow. Under SMS the
error 'Defines may not be within other clauses' will be reported when
you try to RUN the program.

**WARNING 1**

As with DEFine FuNction problems do exist with recursive PROCedures
which prevent the Break key from working. These problems are fixed by
SMS v2.59+

**WARNING 2**

Except under SMS, if you assign the same name to a PROCedure
as a resident command, not only will you no longer be able to use the
resident command, but it may crash the system!


**SMS NOTES**

From v2.59, as with DEFine FuNction, SMS insists that all PROCedures
have an END DEFine statement, even if they are on a single line. If this
does not exist, or there is something else wrong with the syntax, then
the error 'Incomplete DEFine is reported. The same problems exist in
versions prior to v2.90 as with DEFine FuNction for in-line code.


**CROSS-REFERENCE**

Please see :ref:`define--function`! Also
see :ref:`end--define`. Look at the example
for :ref:`swap` which provides a more practical use
of recursive :ref:`procedure`\ s.

--------------


