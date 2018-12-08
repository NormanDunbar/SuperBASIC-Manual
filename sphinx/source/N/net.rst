..  _net:

NET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NET x%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command sets the computer's station number for use in a network to
x%. A station can have any integer number in the range 1..128 (although
see Note below). Each station in the network should have a different
station number to avoid confusion. When the computer is first switched
on (or reset), it is given the station number 1.

**Example**

::

    NET 12

sets the station number to 12.

**NOTE**

Many implementations allow a station number in the range 1..127 (SMS
allows 1..255), although there is still a maximum of 64 computers which
can be linked into the network at any one time using standard QLs.

Auroras allow more to be linked together.

**CROSS-REFERENCE**

Please see the Appendix concerning Networks. See also
:ref:`snet` and :ref:`mnet`.
