..  _hot-list:

HOT\_LIST
=========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_LIST [#ch] or                                               |
|          |                                                                  |
|          | HOT\_LIST \\filename                                             |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

This command will produce a list in the given channel (default #1) of
all of the currently set hotkeys recognised by the Hotkey System II. If
the second variant of the command is used, this will create a file with
the specified filename (default data device supported), offering the
option to overwrite any existing file, and list the hotkeys in that
file. Each hotkey will be listed in tabulated form, with the key (which
has to be pressed together with <ALT>) followed by the operation or
definition string. If you need to press <SHIFT> along with the key, the
key will be pre-fixed with 's'.

**CROSS-REFERENCE**

:ref:`hot-name-dlr` returns the description or
name for the hotkey. :ref:`hot-type` returns the
type of hotkey operation.

