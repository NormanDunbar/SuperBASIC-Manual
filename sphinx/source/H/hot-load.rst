..  _hot-load:

HOT\_LOAD
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_LOAD (key$,filename [;cmd$] [,JobName$] [,options] )        |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is similar to HOT\_CHP in the parameters which it
expects. By contrast, however, HOT\_LOAD does not store the program in
memory, but, instead, each time that the specified hotkey is pressed, it
will look for the specified filename and then load the program at that
stage (this is therefore really designed for programs which are stored
on Hard Disk, as it is improbable that you will keep the same disk in a
drive all of the time).

**NOTE 1**

The I (Impure code) option is not needed with this function.

**NOTE 2**

HOT\_LOAD does not create an Executable Thing.

**NOTE 3**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**WARNING**

Versions of the Hotkey System II, earlier than v2.15 (or Level B-08 of
the ST/QL Drivers) contained serious bugs in HOT\_LOAD which could
either remove the Hotkey Job or crash the computer.

**CROSS-REFERENCE**

See :ref:`hot-load1` and
:ref:`hot-chp`.

