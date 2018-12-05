..  _hot-go:

HOT\_GO
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_GO                                                          |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The Hotkey System II is actually a Job (called HOTKEY) which sits in
the background of the QL looking for the user to press the previously
defined hotkeys. As many users should be aware, whenever a job is
present in the QL's memory, you cannot access the resident procedure
memory (which should be used to install SuperBasic extensions and device
drivers for example - see RESPR).

For this reason, the Hotkey System II
was designed so that the Hotkey Job would not actually be created until
such time as the user was ready - ie. when all of the hotkeys had been
defined and everything loaded into the resident procedure memory. Users
who have used Toolkit II's ALTKEY system may have noticed that although
they have defined various hotkeys (with HOT\_KEY for example), they do
not work (or as soon as the Hotkey System II has been loaded, the last
line recall does not work). This is because the Hotkey Job has to be
started. This is achieved simply by using the command::

    HOT_GO

This will start the Hotkey Job which will support all of the currently
defined hotkeys, including the Hotkey Stuffer Buffer keys (which can be
re-defined by using the program CONFIG on the file HOT\_REXT), and the
last line recall. If you want to remove the Hotkey Job at any time, you
can do so by using the command HOT\_STOP, which has the same effect as
RJOB 'Hotkey'. This will not destroy any of the Hotkey definitions and
when you enter the command HOT\_GO again, they will all be available
once again.

**CROSS-REFERENCE**

:ref:`respr` allocates areas of the resident
procedure memory.

--------------


