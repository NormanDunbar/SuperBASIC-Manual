..  _sys-vars:

SYS\_VARS
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SYS\_VARS                                                        |
+----------+-------------------------------------------------------------------+
| Location |  THOR (all models)                                                |
+----------+-------------------------------------------------------------------+

The function SYS\_VARS returns the base address of the system
variables, which can move around on the THOR range of computers, in much
the same way as they can move on other implementations - it is therefore
imperative that any program which uses the system variables works
relative to the address returned by this function.

**Example**

::

    POKE SYS_VARS+133,-1

switches off the THOR XVI's windowing facilities for windows opened
after this command.

**CROSS-REFERENCE**

:ref:`ver-dlr`\ (-2) on Minerva ROMs and on SMS
returns the base address of the system variables, as do
:ref:`sys-base` and
:ref:`sysbase`.

--------------


