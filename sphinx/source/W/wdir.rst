..  _wdir:

WDIR
====

+----------+------------------------------------------------------------------+
| Syntax   | WDIR [#ch,] [wild] or                                            |
+----------+------------------------------------------------------------------+
| Syntax   | WDIR \\file [,wild] (Toolkit II only)                            |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THORs                                                |
+----------+------------------------------------------------------------------+

WDIR allows you to produce a list of all of the filenames on a given
medium which match with the specified wildcard. If wild
contains a device name, then a list of all of the files on that device
which match with the wildcard is printed out to the specified channel
(default #1). If however, a device is not specified, the default data
device is used.

The second variant is only supported by Toolkit II and
allows you to send the results to the specified file instead of sending
it to a channel. If file does not include a valid device, the default
data device is used, and if the file already exists, you will be asked
whether or not you wish to overwrite it. The file is then opened by the
WDIR command, the list of files written to it and then closed again.

**Examples**

::

    WDIR \ser1, flp1___scr

will produce a list of all of the files on flp1\_ whose names end with
\_scr.

::

    WDIR my

lists all files in the current directory which start with my.

::

    WDIR _my

lists files which start with my or contain \_my somewhere.

**CROSS-REFERENCE**

:ref:`dir` will produce a list of all of the files on
a given medium. :ref:`wcopy` contains details of how
wildcards operate.

