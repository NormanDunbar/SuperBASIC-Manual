..  _dev-use-dlr:

DEV\_USE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_USE$ (n) where n=1..8                                       |
+----------+-------------------------------------------------------------------+
| Location |  DEV device, GOLD CARD, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

The DEV\_USE$ function returns the actual drive and directory for the
number of a DEV device. If a device was not defined, DEV\_USE$ will
return an empty string "", LEN(DEV\_USE$(n))=0.


**Example**

A listing of all DEV definitions::

    100 UNDER 1: PRINT "DEV";: UNDER 0
    110 PRINT " ";: UNDER 1: PRINT "definition": UNDER 0
    120 found=0
    130 FOR n=1 TO 8
    140 IF LEN(DEV_USE$(n)) THEN
    150   PRINT n TO 5;DEV_USE$(n)
    160   found=1
    170 END IF
    180 END FOR n
    190 IF NOT found: PRINT "no DEVs defined"


**CROSS-REFERENCE**

:ref:`dev-next`,
:ref:`dev-list`,\ :ref:`dev-use`.

--------------


