..  _sys-base:

SYS\_BASE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SYS\_BASE                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SYSBASE, Fn                                                      |
+----------+-------------------------------------------------------------------+

The function SYS\_BASE returns the base address of the system
variables.

**Example**

::

    POKE_W SYS_BASE+140,8
    POKE_W SYS_BASE+142,3

Sets the key repeat delay.

**NOTE 1**

Users peeking and poking in the System Variables should know what they
are doing!

**NOTE 2**

Minerva and SMS offer another technique to read and alter system
variables but these are specific to Minerva and SMS whilst SYS\_BASE
works an every ROM. It is generally not advisable to access fixed
addresses in memory as virtually everything can move around.

**CROSS-REFERENCE**

:ref:`sysbase`,
:ref:`win-base`, :ref:`peek`,
:ref:`poke`, :ref:`screen`,
:ref:`sys-vars`, :ref:`ver-dlr`

