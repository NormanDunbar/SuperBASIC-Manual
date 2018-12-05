..  _return:

RETurn
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RETurn [expression]                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command has two actual uses. The main use of RETurn is to force an
early return from a PROCedure or FuNction definition block. A FuNction
must always return a value and therefore a SuperBASIC DEFine FuNction
block must always contain a RETurn
statement to return this value.

The second use of RETurn is to mark the
end of a sub-routine which has been called with GO SUB. This is
implemented in SuperBASIC to make the transition from other
implementations of BASIC easier.

**Examples**

A PROCedure to report an error more safely than REPORT::

    100 DEFine PROCedure REPORT_ERROR(errnumber)
    110 IF errnumber>=0 OR errnumber<-21
    120   PRINT #0,'No error'
    130   RETurn
    140 END IF
    150 REPORT errnumber
    160 END DEFine

A FuNction which returns 1 (true) if a given number is even::

    100 DEFine FuNction CK_EVEN (x)
    110   IF x/2=INT(x/2):RETurn 1
    120   RETurn 0
    130 END DEFine

**CROSS-REFERENCE**

See :ref:`define--procedure` and :ref:`define--function`\ . Please also refer to :ref:`go--sub`\ .

--------------


