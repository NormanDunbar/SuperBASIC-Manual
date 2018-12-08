..  _hot-off:

HOT\_OFF
========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_OFF (key$)  or                                              |
|          |                                                                  |
|          | HOT\_OFF (Thingname$)                                            |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

The HOT\_OFF function allows you to turn off an individual hotkey by
either specifying the hotkey itself, or the name of the Thing accessed
by using the hotkey, if the second variant is used (if there are two
hotkeys which access the same Thing, the first hotkey alphabetically
will be turned off).

The second variant even allows you to pass the
string or command used by HOT\_KEY or HOT\_CMD, although this is a
somewhat dubious method of doing this!!

Even though the hotkey has been
turned off, it will still appear in the hotkey list (see HOT\_LIST),
although pressing the hotkey will have no effect.

**NOTE**

If the hotkey or Thingname cannot be found, the function will return -7.

**Example**

::

    HOT_OFF ('p')

will turn off the <ALT><p> hotkey, eg. if this is used by a program as a command.

::

    HOT_SET ('p')

will turn it back on.

**CROSS-REFERENCE**

:ref:`hot-set` will turn the hotkey back on
again. :ref:`hot-remv` will remove the hotkey
definition for good.

