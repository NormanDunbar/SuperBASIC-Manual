..  _parnam-dlr:

PARNAM$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARNAM$ (number)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function can be used to find the name of an actual parameter
passed to a SuperBASIC PROCedure or FuNction. You merely need to supply
the number of the parameter in the definition line which you wish to
find. If the parameter was passed as a name (ie. by reference), then
this name will be returned by PARNAM$, however, in all other cases, a
nul string will be returned.

**Example**

A short procedure which prints the square of the parameter passed (and
if possible squares the actual parameter!)::

    1000 DEFine PROCedure Square (x)
    1010   LOCal param$,loop,key$
    1020   param$=PARNAM$(1)
    1030   IF param$<>'' THEN
    1040     PRINT #0,param$!'will be altered - is this okay?'
    1050     REPeat loop:key$=INKEY$(-1):IF key$ INSTR 'yn':EXIT loop
    1060     IF key$=='n':RETurn
    1070   END IF
    1080   x=x^2:PRINT x
    1090 END DEFine

Compare the following::

    number=2:Square number: REMark number is passed by reference
    number=2:Square (number): REMark number is passed by value

**NOTE**

TURBO and SuperCHARGE cannot compile programs which use PARNAM$.

**CROSS-REFERENCE**

:ref:`partyp`, :ref:`paruse`
and :ref:`parstr-dlr` allow you to find out other
information about parameters. See also :ref:`define--function` and :ref:`define--procedure`\ .
:ref:`parname-dlr` is exactly the same.

