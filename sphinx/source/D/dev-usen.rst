..  _dev-usen:

DEV\_USEN
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_USEN [drivetype]                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command is provided on SMSQ/E to allow you to alter the three
letter reference used to access the DEV devices. If no parameter is
specified, then the name reverts to DEV.


**Example**

::

    DEV_USE 2,'win1_progs_'
    DEV_USEN 'flp' DIR flp2_

This will provide a directory of win1\_progs\_ - this can be reset
with::

    DEV_USEN
    DIR dev2_

**CROSS-REFERENCE**

:ref:`dev-use` allows you to do the same thing.
:ref:`flp-use` allows you to alter the three
letter description for floppy disks.

