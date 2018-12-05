..  _parhash:

PARHASH
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARHASH (parameter)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

This is an addition to the normal PARUSE and PARNAM$ functions which
allows you to check whether a value passed as a parameter to a
SuperBASIC PROCedure or FuNction was preceded by a hash or not.

**Example**

The following PROCedure allows you to create a CAT command which is
similar to DIR, allowing you to use the following syntaxes::

    CAT #channel [,device]
    CAT [#channel,] [device]

to read a directory.

If device is not
specified, then a directory of the default data device is produced. If a
channel is not specified, then #1 will be used. The device can be in
quotes or not if you prefer. The following can therefore all be used::

    CAT #2
    CAT CAT flp1_
    CAT #3,'win1_'

::

    100 DEFine PROCedure CAT (ch,direct)
    110   LOCal dir_ch,sepa%,hash%
    112   hash%=PARHASH(ch): sepa%=PARSEPA(ch)
    120   IF sepa%>0
    130     file$=PARSTR$(direct,2)
    140   ELSE
    150     IF hash%
    160       file$=DATAD$
    170     ELSE
    180       file$=PARSTR$(ch,1):ch=1
    185       IF file$='': file$=DATAD$
    187     END IF
    190   END IF
    200   dir_ch=FOP\_DIR(file$)
    210   IF dir_ch<0: PRINT #0,'CANNOT ACCESS DIRECTORY ON ';file$:RETurn
    220   CLOSE #dir_ch
    230   DIR #ch,file$
    250 END DEFine

**NOTE 1**

There is a problem with this function that prevents the above example
from working under SMS - once either PARHASH or PARSEPA have been used
once on a parameter, they will not work again!!

For example, try adding
the following lines to the above and compare the results::

    116 PRINT PARHASH(ch), PARSEPA(direct), PARNAME$(2), PARTYP(ch), PARTYPE(direct)
    117 PRINT PARHASH(ch), PARSEPA(direct), PARNAME$(2), PARTYP(ch), PARTYPE(direct)
    118 STOP

**NOTE 2**

TURBO and SuperCHARGE cannot compile programs which use PARHASH.

**CROSS-REFERENCE**

:ref:`partyp`\ E, :ref:`unset`
and :ref:`parname-dlr` are also added by this
toolkit.

--------------


