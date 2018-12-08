..  _dos-drive:

DOS\_DRIVE
==========

+----------+-------------------------------------------------------------------+
| Syntax   | DOS\_DRIVE drive%, directory$                                     |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This changes the directory the DOS device is connected to.

By default, DOS1\_ corresponds to C:\\, DOS2\_ to D:\\ and so on, but the base can be freely chosen in the configuration dialogue or even at runtime::

    DOS_DRIVE 2, "C:\WINDOWS"

will assign DOS2\_ to the windows directory on the host's C:\\ drive.

::

    PRINT DOS_DRIVE$(2)

would now return "C:\\WINDOWS".

