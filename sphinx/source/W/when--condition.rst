..  _when--condition:

WHEN condition
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  WHEN condition                                                   |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM), THOR XVI, Not SMSQ/E                           |
+----------+-------------------------------------------------------------------+

WHEN is used to identify the start of a SuperBASIC structure which is
used to surround lines of SuperBASIC code which should be executed
whenever the given condition is met. The condition is not checked when a
variable is READ, or INPUT.

The syntax of the SuperBASIC structure can
take two forms:

WHEN condition:statement:sup:`\*`\ [:statement]\ :sup:`\*`

or

WHEN condition  :sup:`\*`\ [statements]\ :sup:`\*` .. END WHEN

The condition can be anything which is accepted by the IF
command, provided that it begins with the name of a variable (for
example, WHEN a-10=b is acceptable, but WHEN 10-a=b is not). The
variable cannot be an array.

When a program is run, the interpreter will
make a note of the variable being tested and then jump to the statement
following the END WHEN statement (unless the in-line format is used when
control jumps to the next line if END WHEN does not appear on that
line). Great care must however, be taken where the condition refers to
more than one variable, as an 'error in expression' will be reported if
a variable is not defined when the condition is tested, for example, the
following stops with 'error in expression' at line 4::

    4 WHEN x>1 AND y>1
    5   x=x+1:PRINT 'hello'
    6 END WHEN
    7 PRINT 'Start'
    8 :
    100 FOR x=1 TO 2
    110   FOR y=1 TO 2
    120     PRINT x,y;' ';
    130   END FOR y
    140 END FOR x

This is because when line 100 is processed, the interpreter jumps to
the WHEN clause. At this stage, y is undefined, hence the error. The
program will work if you add the line::

    1 y=0

Although blocks can be specified which check for various conditions of
the same variable, if the conditions overlap, there is no guarantee as
to which WHEN statement will be executed first. Blocks cannot be mixed
together. In the following example, although if a$='me' the messages
'hello' and 'who' will be printed, and if a=2 the only message which
will be printed is 'A is 2' - when the program is RUN, the first END
WHEN command is matched with line 1, thus the message 'who' is also
printed when the program is run (it is extremely bad programming
practice in any event to mix program structures of this sort).

::

    1 WHEN a$='me'
    2   PRINT 'hello'
    3   WHEN a=2
    4     PRINT 'A is 2'
    5   END WHEN
    6   PRINT 'Who'
    7 END WHEN

WHEN processing is turned off by the command WHEN anything, and also
when the NEW, CLEAR, LOAD, LRUN, MERGE, and MRUN commands are issued.
You can also switch off WHEN processing on a given variable (eg. b) by
the command WHEN b (in the following example).

**Example**

::

    110 WHEN a>100 AND a<1000: PRINT 'A is now in the range 100-1000': a=a+100
    120 WHEN b=a
    130   PRINT 'B is now the same as A ': PRINT B,A: A=A+50
    140 END WHEN
    150 WHEN b MOD 100=0: b=b+200
    155 :
    160 LET a=100: b=a
    170 a=10
    180 REPeat Loop
    190   a=a+1: b=b-1
    200   AT 0,0: PRINT 'A='!a\\'B='!b
    210 END REPeat Loop

**NOTE 1**

This command does not work reliably on any QL versions other than
Minerva v1.77 or later: although Toolkit II improves the reliability,
problems include calling the block more than once, and reporting 'bad
name' when the block is called. WHEN clauses will also remain in force
despite NEW, CLEAR, LRUN, LOAD, MERGE and MRUN, unless Toolkit II is
present.

**NOTE 2**

A WHEN clause will not be called if it is already active, even though
the program may have jumped out of the actual WHEN
clause. For example::

    100 WHEN a=100: PRINT 'A=100': GOTO 400
    115 :
    110 a=10
    120 REPeat loop
    130   a=a+10: PRINT a
    140 END REPeat loop
    150 STOP
    160 :
    400 FOR a=10 TO 200 STEP 30
    410   PRINT a
    420 END FOR a

**NOTE 3**

On JS MG and THOR XVI ROMs, a maximum of 20 WHEN clauses can be active
at any time.

**CROSS-REFERENCE**

Other SuperBASIC structures are :ref:`when--error`,
:ref:`select--on` and
:ref:`if`..\ :ref:`end--if`.

:ref:`end--when` defines the end of a WHEN XXX structure.

--------------


