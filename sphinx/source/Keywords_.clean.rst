
==============
Keywords Other
==============

TODO
====

- _DEF% and _DEF$ have the same URL. Needs to be fixed.
- URLs generated replace '_' with '-', but, in the index they have no leading '-'. So cross references don't actually work in this file.


..  _-def-pct:

\_DEF%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  \_DEF% [ (#channel) ]                                            |
+----------+-------------------------------------------------------------------+
| Location |  DEFS (DIY Toolkit - Vol A)                                       |
+----------+-------------------------------------------------------------------+

This function creates a table of all of the SuperBASIC PROCedures and
FuNctions used within the program currently in memory. The table appears
in the specified CONsole channel, if any (default #2). You can use the
cursor keys to highlight the required PROCedure or FuNction name and
then press <ENTER>, in which case the function will return the line
number of the program line which contains the relevant DEFine PROCedure
or DEFine FuNction. If you press the <ESC> key an 'Incomplete' error is
caused. If no PROCedures or FuNctions are defined, then a 'Not Found'
error is reported.

**Example**

::

    ED _DEF%

**CROSS-REFERENCE**

:ref:`-def-dlr` and
:ref:`-name-dlr` are similar.
:ref:`codevec` returns the machine code base
address of a Machine Code Procedure or Funtion.

--------------


..  _-def-dlr:

\_DEF$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  \_DEF$ [ (#channel) ]                                            |
+----------+-------------------------------------------------------------------+
| Location |  DEFS (DIY Toolkit - Vol A)                                       |
+----------+-------------------------------------------------------------------+

This function is similar to \_DEF% in that it creates a table of all of
the SuperBASIC PROCedures and FuNctions used within the program
currently in memory. The table appears in the specified CONsole channel
(if any - default #2). You can use the cursor keys to highlight the
required PROCedure or FuNction name and then press <ENTER>, in which
case the function will return the selected name of the PROCedure or
FuNction. If you press the <ESC> key an 'Incomplete' error is caused. If
no PROCedures or FuNctions are defined, then a 'Not Found' error is
reported.

**CROSS-REFERENCE**

See :ref:`-def-pct`

--------------


..  _-name-dlr:

\_NAME$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  \_NAME$(offset)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  DEFS (DIY Toolkit - Vol A)                                       |
+----------+-------------------------------------------------------------------+

This function can be used to examine the SuperBASIC name list, which
contains the names of all machine code Procedures, Functions, variables,
SuperBASIC PROCedures and SuperBASIC FuNctions which are available to
SuperBASIC.

**Example**

A program to print out the full name list (this only works on Minerva
and SMSQ/E)::

    100 nlist_start=PEEK_L (\\ HEX('20')) 
    110 nlist_end=PEEK_L (\\ HEX('24')) 
    120 nlist_len=nlist_end-nlist_start 
    125 names=0 
    130 FOR i=0 TO nlist_len 
    140   x$=_NAME$(i) 
    150   names=names+1+LEN(x$) 
    155   IF names>nlist_len: EXIT i 
    160   PRINT i,x$ 
    165   PAUSE 
    170 END FOR i

**CROSS-REFERENCE**

The name list can be tidied up with :ref:`clear`.
:ref:`extras` will list all the machine code
Procedures and Functions. See also :ref:`lookup-pct`.

