..  _et:

ET
==

+----------+-------------------------------------------------------------------+
| Syntax   |  ET file :sup:`\*`\ [,{filex \| #chx}]\ :sup:`\*` [;cmd$]         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

The syntax for ET is the same as for the Toolkit II variant of EX and it also
operates in a similar manner. However, ET is intended for low level debugging,
ie. to trace execution of the machine code commands step by step.

A monitor program such as Qmon is necessary.

The command ET loads the executable program, installs the job and immediately
suspends the job by setting its priority to zero. Control is then returned to
SuperBASIC to allow you to use a monitor program.

**CROSS-REFERENCE**

:ref:`ex`

