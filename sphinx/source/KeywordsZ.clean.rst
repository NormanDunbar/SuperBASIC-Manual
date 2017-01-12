
==========
Keywords Z
==========


..  _zap:

ZAP
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ZAP keyword$                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command removes a given keyword from the name table so that
SuperBASIC is no longer aware of its existence. The code remains in
memory so no memory is freed. A ZAPped keyword cannot be recovered
without re-loading the code or resetting the system.

**Example**

You try to run a SuperBASIC program but it stops at the following line::

    1120 er=2: es=.9: ET=1.4: eu=0

with error -17. The author used et as a variable because the ET command
was not present when (s)he wrote that program. The more resident
keywords that are present, the more it is likely that such collisions
may occur. ZAP "ET" and re-loading the program will cure the problem.

**NOTE**

It is okay to ZAP incompatible and bug-ridden keywords, but removing
essential keywords like ED, EDIT, AUTO, LIST to stop the user from
editing a program will decrease the QL's multitasking abilities. Yes,
multitasking depends on this general rule: the more a program influences
the whole system and may affect other programs, the less the computer
can multitask.

**CROSS-REFERENCE**

Keywords can be renamed with :ref:`new-name`.
:ref:`key-rmv` works in the same way as
:ref:`zap`. See also
:ref:`tiny-rmv`.

