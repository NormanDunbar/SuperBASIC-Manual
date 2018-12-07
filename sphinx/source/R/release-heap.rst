..  _release-heap:

RELEASE\_HEAP
=============

+----------+-------------------------------------------------------------------+
| Syntax   | RELEASE\_HEAP address                                             |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The address given is assumed to be the address of a chunk of common heap as allocated earlier in the program by :ref:`reserve-heap`. In order to avoid crashing the QL when an invalid address is given, RELEASE\_HEAP checks first that there is a flag at address-4 and if so, clears the flag and returns the memory back to the  system.  If the flag is not there, or if the area has already been released, then a bad parameter error will occur.

It is more efficient to RELEASE\_HEAP in the opposite order to that in which it was reserved and will help to avoid heap fragmentation.


**CROSS-REFERENCE**

See :ref:`reserve-heap`\ , below, for an example of use.


