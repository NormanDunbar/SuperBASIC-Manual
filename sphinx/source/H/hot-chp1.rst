..  _hot-chp1:

HOT\_CHP1
=========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_CHP1 (key$,filename [;cmd$] [,Jobname$] [,options] )  or    |
|          |                                                                  |
|          | HOT\_CHP1 (key$,filename [;cmd$] !Wakename$ [,options] )         |
+----------+------------------------------------------------------------------+
| Location |  HOTKEY II                                                       |
+----------+------------------------------------------------------------------+

The first variant of this function is very similar to HOT\_CHP except
that it will only start up a new copy of the program when the specified
hotkey is pressed if there is not already a copy of the program being
executed. If a copy of the program is already being executed, then the
hotkey will merely move that copy of the program to the top of the pile
so that you can access it (it will PICK the program and execute a WAKE
event, if supported by the program - a Wake event is normally used by a
program to force it to update its tables etc).

The second variant of this command was introduced in v2.24 of the Hotkey System II and allows you
to specify a name of a job (Wakename$) which is to be woken up if there
is already one copy of the original program running in memory.
Unfortunately this variant acts differently from the first in one main
way:

- If the original program is already running, and Wakename$ points
  to another program which is not yet running, a second copy of the
  original program will be started up.

**Example**

The following line will allow you to set up the <ALT><R> key to do one
of two things:

- If a job called QR-Config is running already, this will be Woken; otherwise;
- A copy of a program called flp1\_Route\_Obj will be started up (even if one is already running).

::

    ERT HOT_CHP1 ('R','flp1_Route_obj';'flp1_\' ! 'QR-Config')

**NOTE 1**

On early versions of the Hotkey System II, HOT\_CHP1 did not create an
Executable Thing.

**NOTE 2**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**CROSS-REFERENCE**

See :ref:`hot-chp`.
:ref:`hot-pick` allows you to set up hotkeys to
PICK a program, and :ref:`hot-wake` allows you
to set up hotkeys to WAKE a program.
:ref:`hot-thing` allows you to call an
Executable Thing.

