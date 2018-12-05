..  _partyp:

PARTYP
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARTYP (name)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

As disclosed in the description of DEFine FuNction, a parameter is
passed to a SuperBASIC PROCedure or FuNction by reference, meaning that
the variable type listed in the definition line will actually be
overriden by the type of variable which has been passed as a parameter.

The function PARTYP returns the type of the actual parameter which has
been passed, which can be used to error trap PROCedures and FuNctions.
PARTYP expects only one parameter - the name of the parameter from the
definition line to be looked at. PARTYP will then return one of the
following values depending on the type of the actual parameter passed:

+--------+------------------------------------+
| PARTYP | Meaning                            |
+========+====================================+
| 0      | A null string has been passed.     |
+--------+------------------------------------+
| 1      | A string has been passed.          |
+--------+------------------------------------+
| 2      | A floating point has been passed.  |
+--------+------------------------------------+
| 3      | An integer has been passed.        |
+--------+------------------------------------+

**Example**

A PROCedure to swap any two variables (it can only handle simple strings
and variables, not arrays)::

    100 a=1:b%=2
    110 swap_var a,b%
    115 :
    120 DEFine PROCedure swap_var (x,y)
    130   LOCal xa,xa$,param
    140   IF PARUSE(x)=0 OR PARUSE(y)=0
    150     PRINT 'A variable is unset!':RETurn
    160   END IF
    162   IF PARNAM$(1)="" OR PARNAM$(2)=""
    164     PRINT 'Parameters are not both variables!':RETurn
    165   END IF
    170   IF PARUSE(x)=3 OR PARUSE(y)=3
    180     PRINT 'Arrays not handled':RETurn
    190   END IF
    200   param=PARTYP(x)
    210   IF PARTYP(y)=1 AND param<>1 OR param=1 AND PARTYP(y)<>1
    220     PRINT 'You cannot swap a string with a value!'
    230     RETurn
    240   END IF
    250   SELect ON param
    260     =0,1:xa$=y:y=x:x=xa$
    270     =2,3:xa=y:y=x:x=xa
    280   END SELect
    290 END DEFine

**NOTE 1**

There is a difference in the way that PARTYP will report an omitted
parameter, depending on whether you implicitly omit the parameter. Try
the following using the above example:

Implicit omission::

    swap_var a$

or even::

    swap_var a$,

PARTYP(y) returns the type of the notional parameter (here y is a floating point, so PARTYP (y) returns 2), and
PARUSE(y) also reports 2. Compare explicit omission::

    swap_var ,a$

PARTYP(x) will return 0 as will PARUSE(x) If a program is Qliberated, PARTYP will return 0 whether parameters are
implicitly or explicitly omitted.

**NOTE 2**

If you pass a null string as a parameter, eg::

    swap_var a$,''

in the above example, PARTYP will still return 1 (and not zero) as you may
think, hence the need to look at PARUSE also.

**NOTE 3**

TURBO and SuperCHARGE cannot compile programs which use PARUSE.

**CROSS-REFERENCE**

:ref:`partyp` should be used alongside
:ref:`paruse` to find out whether a parameter was
passed as a variable (ie. by reference) or as a value.
:ref:`partype` is the same.
:ref:`parnam-dlr`,
:ref:`parhash`,
:ref:`parsepa` and
:ref:`parstr-dlr` form companions to these commands.

--------------


