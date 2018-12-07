..  _wdel:

WDEL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WDEL [#ch,] [wild]                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THORs                                                |
+----------+-------------------------------------------------------------------+

WDEL allows you to delete several files which match the given wildcard
at the same time. If wild contains a device name, then each file on that
device is checked to see if its name matches the wildcard, otherwise the
files on the default data directory are checked.

If any files are found
which match the wildcard, a prompt will appear in the specified window
(default #0) to the effect::

    filename..Y/N/A/Q?

You must then either press <Y> to delete the offered file, <N> to leave
that file, <A> to delete that file and all other files which match the
wildcard, or <Q> to stop WDEL. <ESC> and <CTRL><SPACE> will have the
same effect as <Q>.

**Example**

::

    WDEL win1_v1_

will delete all files in the sub-directory v1.

**NOTE 1**

The THOR variant of WDEL has amended the prompt to read: 'Yes/No/All/Quit'

**NOTE 2**

Current versions of WDEL (at least up to v2.88) do not work with the DEV
device when this is pointing to a sub-directory. Even if you can
persuade WDEL to offer you the filename for deletion, when you press <Y>
or <A>, WDEL fails to delete the file!

**NOTE 3**

If you try to use WDEL on a write protected disk, it will ask you
whether you want to delete each file in turn reporting for each filename
that the disk is write-protected, rather than stopping altogether.

**CROSS-REFERENCE**

:ref:`wcopy` provides details about wildcards.
:ref:`delete` allows you to delete single files.

