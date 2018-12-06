..  _hot-set:

HOT\_SET
========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_SET (key$)  or                                              |
|          |                                                                  |
|          | HOT\_SET (Thingname$)  or                                        |
|          |                                                                  |
|          | HOT\_SET (newkey$,oldkey$)  or                                   |
|          |                                                                  |
|          | HOT\_SET (newkey$,oldThingname$)                                 |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

The first two variants of this function are the opposite to HOT\_OFF in
that they re-activate the specified hotkey. If the specified hotkey does
not exist, the value -7 will be returned. By contrast, the second two
variants allow you to re-define a hotkey by assigning a new key which is
to replace the old key press. If the specified new hotkey already
exists, -9 will be returned, and if the old hotkey cannot be found, the
value -7 will be returned.

**Example**

::

    10 ERT HOT_CHP ('p','flp1_Perfection')
    20 HOT_GO
    30 ERT HOT_SET ('L','p')
    40 ERT HOT_WAKE ('p','Pick')

**CROSS-REFERENCE**

See :ref:`hot-off` and
:ref:`hot-key`.

