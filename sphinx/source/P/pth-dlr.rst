..  _pth-dlr:

PTH$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH$ (n)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

The function PTH$ returns the nth directory in the search list of the
path device.

**Examples**

The procedure PTH\_INFO prints all of the current settings concerning
the the pth device to #1.

The function PTH\_ENTRIES% returns the number of directories in the path list.

::

    100 DEFine PROCedure PTH_INFO
    110   LOCal n: n=0
    120   PRINT "Path device:"!PTH_USE$
    130   PRINT\"Search paths";
    140   REPeat list_them
    150     IF PTH$(n)="" THEN EXIT list_them
    160     IF NOT n THEN PRINT
    170     PRINT FILL$(" ",3-LEN(n));n;TO 5,PTH$(n)
    180     n=n+1
    190   END REPeat list_them
    200   IF NOT n THEN PRINT " no entries"
    210 END DEFine PTH_INFO
    220 :
    240 DEFine FuNction PTH_ENTRIES%
    250   LOCal n
    260   FOR n=0 TO 32767: IF PTH$(n)="" THEN EXIT n
    270   RETurn n
    280 END DEFine PTH_ENTRIES%

**CROSS-REFERENCE**

:ref:`pth-add`,
:ref:`pth-list`
