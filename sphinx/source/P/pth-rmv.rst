..  _pth-rmv:

PTH\_RMV
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_RMV n                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

This command removes a search path from the search list and all
directories below the removed entry are moved up in the list by one
position to fill the gap. The number n corresponds to the number in the
list produced by PTH\_LIST.

**Example**

Assume the following search list::

    0 flp1_
    1 flp1_basic_
    2 flp2_
    3 ram1_

::

    PTH_RMV 2

will remove entry 2 (flp2\_), entry 3 will become entry 2 so that the
new list will be::

    0 flp1_
    1 flp1_basic_
    2 ram1_


The search list can be totally cleaned up with the following little
procedure PTH\_CLEAR::

    10 DEFine PROCedure PTH_CLEAR
    20   REPeat clean_up
    30     IF PTH$(0)="" THEN EXIT clean_up
    40     PTH_RMV 0
    50   END REPeat clean_up
    60 END DEFine PTH_CLEAR

**CROSS-REFERENCE**

Other 'PTH_XXX' keywords starting at :ref:`pth-add`!
