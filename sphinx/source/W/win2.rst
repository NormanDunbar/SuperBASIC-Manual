..  _win2:

WIN2
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN2 directory                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card, THOR XVI and ST/QL (Level C-19+)                      |
+----------+-------------------------------------------------------------------+

This command simulates the drive win2\_ if only one hard disk (win1\_)
is present. All access to win2\_ will be redirected to directory.

**Example**

    WIN2 system: DIR win2_

will produce a listing of the files held in the sub-directory
win1\_system. This is equivalent to::

    DIR win1_system


**NOTE**

Do not specify the device as part of directory.

**CROSS-REFERENCE**

:ref:`dev-use` is much more flexible.

--------------


