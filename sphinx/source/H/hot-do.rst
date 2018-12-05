..  _hot-do:

HOT\_DO
=======

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_DO key$  or                                                 |
|          |                                                                  |
|          | HOT\_DO Thingname$                                               |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

Once a hotkey is operational (see HOT\_GO), you can call up the program
or action set up on that hotkey by using the command HOT\_DO, which
enables a program to emulate the user pressing <ALT><key>.

The first variant expects you to supply the key which would normally be used
together with <ALT> to call up the facility. You can however, also use
the second variant to supply the name of an Executable Thing to be
called up.

**Example**

Take the following hotkey::

    100 ERT HOT_WAKE ('f',Files)
    110 HOT_GO

The following would all have the same effect:

- Pressing <ALT><f>
- HOT\_DO 'f'
- HOT\_DO Files

**CROSS-REFERENCE**

See the other :ref:`hot`... commands about setting
up hotkeys.

--------------


