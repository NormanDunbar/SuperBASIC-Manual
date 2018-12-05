..  _cmd-dlr:

CMD$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CMD$                                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Minerva                                                     |
+----------+-------------------------------------------------------------------+

This function can be used from within SMS SBASICs, Minerva MultiBASICs
and compiled programs (not SuperBASIC Job 0) to read a string passed to
the program when it was initiated, with the command EX (or similar).

The string appears after the EX command, preceded with a semicolon.

**Example**

Create a program to load in Xchange and set its default drives and
memory, something akin to:

::

    10 xch_data$=DATAD$:xch$=PROGD$
    20 data_space=300
    30 x$=CMD$
    40 IF x$<>''
    45   datpos='\' INSTR x$
    50   IF datpos:data_space=x$(datpos+1 TO)
    55   IF datpos>5:x$=x$(1 TO datpos-1)
    74   dr1=',' INSTR x$
    75   IF dr1<6
    80     IF dr1=0:PROG_USE x$(1 TO):ELSE IF dr1<LEN(x$-4):DATA_USE x$(dr1+1 TO)
    90   ELSE
    100     PROG_USE x$(1 TO dr1-1)
    110     IF dr1<LEN(x$)-4:DATA_USE x$(dr1+1 TO)
    120   END IF
    140 END IF
    150 EX xchange;data_space
    160 DATA_USE xch_data$
    170 PROG_USE xch$

Save this as FLP1\_XCHANGE\_BAS (or similar).

Now, to pass the relevant parameters all you need do under SMS is enter
the line:

EXEC flp1\_XCHANGE\_BAS;'win1\_XCHANGE\_,flp2\_\\200'

Minerva treats the string slightly differently - see EX for an
explanation of the following command which achieves the same:

EXEC pipep;'flp1\_XCHANGE\_BAS>win1\_XCHANGE,flp2\_\\200'

This will execute win1\_XCHANGE\_xchange with the help file to be loaded
from win1\_XCHANGE\_ , the data files being loaded from flp2\_ and a
dataspace of 200K.

**NOTE 1**

In SMS pre v2.60, you could not directly slice CMD$ - copy it to another
string variable first, as in the example.

**NOTE 2**

You cannot use this command in TURBO compiled jobs - use OPTION\_CMD$
instead.

**CROSS-REFERENCE**

See :ref:`exec` and
:ref:`exec-w`.

--------------


