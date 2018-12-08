..  _dev-next:

DEV\_NEXT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_NEXT (n) n=1..8                                             |
+----------+-------------------------------------------------------------------+
| Location |  DEV device, GOLD CARD, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

The function DEV\_NEXT returns the number of the next DEVice where a
given DEV will look on next if a file was not found. If a DEV is not
defined or has the search option disabled, DEV\_NEXT returns zero (0),
otherwise an integer from 1 to 8 will be returned.


**Example**

A program which lists a search path::

    100 INPUT "Which DEV device (1..8)?"!n
    110 IF n<1 OR n>8 THEN RUN
    120 DIM checked%(8)
    130 REPeat SPate
    140   IF NOT DEV_NEXT(n) OR checked%(n): EXIT SPate
    150   PRINT DEV_USE$(n)
    160   checked%(n)=1
    170   n=DEV_NEXT(n)
    180 END REPeat SPate

If you understood this example, then you will know exactly how the DEV
device works.


**CROSS-REFERENCE**

:ref:`dev-use-dlr`,
:ref:`dev-list`,
:ref:`dev-use`

