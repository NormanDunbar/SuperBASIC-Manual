..  _system-variables:

SYSTEM\_VARIABLES
=================

+----------+-------------------------------------------------------------------+
| Syntax   | sys_vars = SYSTEM\_VARIABLES                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns the current address of the QL's system variables.  For most purposes, this will be hex 28000, decimal 163840, but Minerva users will probably get a different value due to the double screen.  *Do not* assume that all QLs, current or future, will have their system variables at a fixed point in memory, this need not be the case.


**EXAMPLE**

::

    PRINT SYSTEM_VARIABLES

