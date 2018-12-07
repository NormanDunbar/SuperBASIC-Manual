..  _thing:

THING
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  THING (thingname$)                                               |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This function is used to check whether a Thing is present in memory
(ie. whether a given item appears on the Thing list). If the Thing is
present, then the function will return 0, otherwise it will return -7
(not found).

**Examples**

::

    PRINT THING('Button_sleep')
    PRINT THING('HOTKEY')

**NOTE**

In versions earlier than v1.02, this function may sometimes return a
value greater than zero if the Thing exists.

**CROSS-REFERENCE**

:ref:`th-ver-dlr` explains what Things are.

