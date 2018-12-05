..  _dmedium-name-dlr:

DMEDIUM\_NAME$
==============

+----------+------------------------------------------------------------------+
|Syntax    | DMEDIUM\_NAME$ [(#channel)] or                                   |
|          |                                                                  |
|          | DMEDIUM\_NAME$ (\\file)                                          |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns the name which was given to the medium on which
the specified file or directory is located (or to which the specified
channel is open), when that medium was FORMATted. If no parameter is
specified, it looks to channel #3 (or #1 if #3 is not open).


**Example**

A routine to re-format a floppy disk with the same details as previously
allocated to that disk (except for the files). The drive to format (eg.
flp1\_) can be passed with or without quotes, due to the use of line
120::

    100 DEFine PROCedure RE_FORMAT(drv)
    110   v$=VER$:IF v$<>'HBA':PRINT #0,'NOT SUPPORTED':PAUSE:RETurn
    120   drv$=PARSTR$(drv,1)
    130   CH=FOPEN(drv$)
    140   IF CH<0:PRINT #0,'File Error - cannot access drive':PAUSE:RETurn
    150   IF DMEDIUM_RDONLY(#CH)
    160     PRINT #0,'Disk Write Protected, cannot proceed':PAUSE
    170     CLOSE #CH:RETurn
    180   END IF
    190   dname$=DMEDIUM_NAME$(#CH)
    200   drv_density=DMEDIUM_DENSITY(#CH)
    210   IF DMEDIUM_FORMAT(#CH)<>1
    220     PRINT #0,'Not QDOS / SMSQE disk, cannot proceed':PAUSE
    230     CLOSE #CH:RETurn
    240   END IF
    250   IF DMEDIUM_TYPE(#CH)<>1
    260     PRINT #0,'This routine only supports floppy disks!!':PAUSE
    270     CLOSE #CH:RETurn
    280   END IF
    290   CLOSE #CH
    300   IF LEN(dname$)>10:dname$=dname$(1 TO 10)
    310   SELect ON drv_density
    320     =1:dname$=dname$&'*D'
    330     =2:dname$=dname$&'*H'
    340     =3:dname$=dname$&'*E'
    350   END SELect
    360   FORMAT drv$&dname$
    370 END DEFine

Usage::

    REMark Without quotes:
    RE_FORMAT flp1_

or::

    REMark With quotes:
    RE_FORMAT 'flp2_'


**CROSS-REFERENCE**

The name of a medium is set with :ref:`format`. You
can read it with :ref:`dir` also.

--------------


