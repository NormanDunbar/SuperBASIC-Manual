..  _deallocate:

DEALLOCATE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEALLOCATE address                                               |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This procedure is very similar to RECHP in that it cancels a
reservation of common heap memory. However, the specified address must
be an area of memory which had previously been set aside with
ALLOCATION.


**WARNING**

Prior to v3d27 this command could crash the system if the specified
address had already been deallocated, was an odd address, or had not
been set aside with ALLOCATION.


**CROSS-REFERENCE**

See :ref:`allocation` and
:ref:`rechp`.

--------------


