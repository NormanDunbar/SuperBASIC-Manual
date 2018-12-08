..  _hot-key:

HOT\_KEY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_KEY (key$,string$ [,string2$ [,string3$... ]])              |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is very similar to the first variant of the command
ALTKEY provided by Toolkit II, except that it operates by virtue of the
Hotkey Job, rather than a polled task, which should make the hotkey a
little more reliable than the Toolkit II version (although this does
mean than a hotkey set up under the Hotkey System II cannot be accessed
from within a program running in Supervisor mode).

As with ALTKEY, this
function creates a key macro which will be typed into the current
keyboard queue each time that you press <ALT> and the specified <key$>
at the same time. Again, if more than one string appears in the
definition, an <ENTER> (line feed) will be placed between each string.
If you want a line feed at the end of the final string, add a null (empty) string
to the definition.

**NOTE**

Although HOT\_KEY will quite happily allow you to redefine an existing
hotkey created with HOT\_CMD or HOT\_KEY, if any other command has been
used to set up the hotkey (eg. ALTKEY), error -9 (in use) will be
reported.

**CROSS-REFERENCE**

As with other Hotkey System II definitions, you will need to use
:ref:`hot-go` before you can access this hotkey.
See :ref:`altkey` for more information.

