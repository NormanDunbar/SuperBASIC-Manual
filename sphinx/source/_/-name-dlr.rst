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

