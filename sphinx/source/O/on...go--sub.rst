..  _on...go--sub:

ON...GO SUB
===========

+----------+------------------------------------------------------------------------------+
| Syntax   | ON condition GO TO line\ :sup:`1` :sup:`\*`\ [,line\ :sup:`i`]\ :sup:`\*` or |
|          |                                                                              |
|          | ON condition GO SUB line\ :sup:`1` :sup:`\*`\ [,line\ :sup:`i`]\ :sup:`\*`   |
+----------+------------------------------------------------------------------------------+
| Location | QL ROM                                                                       |
+----------+------------------------------------------------------------------------------+

The QL supports a structure which enables the program to jump to
specific lines depending upon the value of a variable. condition must be
an integer expression which returns a value of one or more. After the
command GO TO or GO SUB must appear a list of line numbers to jump to
depending on the value of the condition. The value returned is then used
to determine which of these line numbers will be jumped to, by counting
the different options. If the result of the condition is zero, or more
than the number of options, then the error 'Out of Range' will be
returned. If ON...GO SUB is used, then when a RETurn is executed from
within the sub-routine, the program will continue from the statement
following ON..GO SUB.

**Example**

A procedure to print out the locations in an adventure might look like
this::

    100 no_of_locations=3
    110 start=0
    120 PRINT_LOC 2
    130 DEFine PROCedure PRINT_LOC (xa)
    140   IF xa=0 OR xa>no_of_locations THEN PRINT 'Undefined Location':RETurn
    150   ON xa+start GO SUB 170,180,190
    160   PRINT 'What now?':RETurn
    170   PRINT 'This is location 1':RETurn
    180   PRINT 'This is location 2':RETurn
    190   PRINT 'This is location 3':RETurn
    200 END DEFine

For a simpler (and clearer) way of writing this PROCedure, please refer
to the example given for SELect ON.

**NOTE**

ON can also be used with the SELect ON structure - please refer to
:ref:`select--on` for further details.

**CROSS-REFERENCE**

These two commands can generally be replaced either by a calculated
:ref:`go--sub` or :ref:`go--to`
statement, or the :ref:`select--on` structure.

--------------


