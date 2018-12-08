..  _hot-cmd:

HOT\_CMD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_CMD (key$,command$ :sup:`\*`\ [,command$]\ :sup:`\*`\ )     |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function allows you to set up a specify a key, which, when pressed
with <ALT> will call up the SuperBasic task (Job 0), Picking it to the
top of the pile, and then send each specified command to the command
console (normally #0) followed by <ENTER> at the end of each string.

**Example**

::

    ERT HOT_CMD ('d','INPUT "List Device: ";d$','DIR d$')

will set up a hotkey whereby whenever you press <ALT><d>, control will
be returned to SuperBasic and the user asked to enter a device, after
which, a directory of that device will be produced.

**NOTE**

Although HOT\_CMD will quite happily allow you to redefine an existing
hotkey created with HOT\_CMD or HOT\_KEY, if any other command has been
used to set up the hotkey, error -9 (in use) will be reported.

**CROSS-REFERENCE**

See :ref:`hot-key`.
:ref:`hot-go` is required in order to make hotkey
definitions operational. :ref:`force-type` is
very similar.

