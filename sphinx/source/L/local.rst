..  _local:

LOCal
=====

+----------+----------------------------------------------------------------------------------------------------------------------------+
| Syntax   |  LOCal var\ :sup:`1` :sup:`\*`\ [, var\ :sup:`x` [(index\ :sup:`1` :sup:`\*`\ [index\ :sup:`i`]\ :sup:`\*` )] ]\ :sup:`\*` |
+----------+----------------------------------------------------------------------------------------------------------------------------+
| Location |  QL ROM                                                                                                                    |
+----------+----------------------------------------------------------------------------------------------------------------------------+

This command must only be used as the first executable line within
either a PROCedure or FuNction definition block (ie. it can only be
preceded by REMark lines) - if it is used elsewhere, it will cause a
'bad line' error when the program is RUN. Under SMS's improved
interpreter the error 'Misplaced LOCal' will be reported.

LOCal must be
followed by a list of variables which are said to be 'local' to that
definition block. This means that although a variable may already have
been used within the main body of the program, if it is local to that
definition block, on entry its value is stored and it is then made
'unset' (without value), and can then be used for any means within that
definition block (or within any sub-procedure or sub-function called by
that definition block).

When the definition block is left (with END
DEFine or RETurn), the variable is restored to its original value.

Arrays can also be made LOCal by placing an index after their name,
which is used to specify their size (as with DIM). Indeed this is the
only way in which a simple variable can also be used as an array. In any
event, the parameters contained in the definition line are local to that
definition block and can also be safely used in the main program - these
are in fact swapped with the actual parameters passed for the duration
of the definition block (see DEFine PROCedure).

**Example**

This program shows the status of three variables at various stages -
note how x can be used as an array in the main program and a simple
variable within the PROCedure definition block::

    100 DIM x(10)
    110 test$='Wait'
    120 moder=4:x(1)=10
    130 PRINT moder,test$,x(1)
    140 Change_vars
    150 PRINT moder,test$,x(1)
    155 :
    160 DEFine PROCedure Change_vars
    170   LOCal moder(2,10),x,test$
    180   PRINT moder(1,5),test$,x
    190   test$='Changed':moder(1,5)=10
    200   x=5
    210   PRINT moder(1,5),test$,x
    220 END DEFine

This produces the following output::

    4 Wait 10 line 130
    0 * * line 180, local variables
    10 Changed 5 line 210, local variables
    4 Wait 10 line 150

**NOTE 1**

On pre MG ROMs, any more than nine parameters may corrupt the program,
by replacing names with PRINT towards the end of a program. This can
however be circumvented by increasing the size of the Name Table by 8
bytes for each name (plus a little more for luck), by using the line::

    CALL PEEK_W(282)+36,N

This bug is fixed on the ST/QL Emulator (with E-Init software v1.27+),
Minerva and SMS.

**NOTE 2**

On most ROMs, you cannot LOCal the names of the parameters passed to the
PROCedure or FuNction. ROMs which can cope with this will simply set the
passed value to undefined. Type in the following small procedure test::

    100 DEFine PROCedure test(a,b)
    110   LOCal a
    120   PRINT a,b
    130 END DEFine

If your interpreter behaves correctly then::

    test 3,2

will write::

    * 2

SMS will print::

    0 2

Any reference to a in the procedure, eg. a=a+1, will
break with an error in expression (-17) because the LOCal declaration of
a undefined the passed parameter. You would need to expressly assign a value to a
within the PROCedure for this to work. This works correctly on Minerva
ROMs (ie. a is unset by the LOCal command).

**CROSS-REFERENCE**

:ref:`dim` sets up arrays normally. :ref:`define--procedure`,
:ref:`define--function` and :ref:`end--define` are used to identify definition
blocks.

--------------


