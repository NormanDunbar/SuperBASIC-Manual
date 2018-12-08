..  _set-fbkdt:

SET\_FBKDT
==========

+----------+------------------------------------------------------------------+
| Syntax   | SET\_FBKDT #channel [,time] or                                   |
|          |                                                                  |
|          | SET\_FBKDT \\file [,time]                                        |
+----------+------------------------------------------------------------------+
| Location | Level-2 drivers                                                  |
+----------+------------------------------------------------------------------+

The command SET\_FBKDT sets the date when a file was last backed-up.
The time specified, must be in the number of seconds since 1st January
1961, ie. the number returned by DATE. If time is not specified or is 0,
then the current DATE setting is used. If time=1 this has no effect on
the file. Normally the backup date is not set unless you do so using
SET\_FBKDT. This command supports the data default directory (set with
DATA\_USE).

**Example**

::

    SET_FBKDT \BOOT, DATE

sets the backup date on the file BOOT in the current data default
directory to the current time and date.

**CROSS-REFERENCE**

:ref:`fbkdt`. See :ref:`fgeth-dlr`
for the structure of a file header, especially which byte is modified
when the backup date is changed.

