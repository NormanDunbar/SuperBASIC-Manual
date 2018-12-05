..  _discard:

DISCARD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DISCARD [adr]                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Memory Toolkit (DIY Toolkit Vol H)                               |
+----------+-------------------------------------------------------------------+

This command removes memory which has been allocated with RESERVE
fairly safely, ensuring that the memory had been allocated with RESERVE
and has not already been DISCARDed. If the adr does not point to memory
set aside with RESERVE the error 'not found' is returned.


**CROSS-REFERENCE**

See :ref:`reserve` and
:ref:`linkup`. Also see
:ref:`clchp`, :ref:`rechp` and
:ref:`despr`.

--------------


