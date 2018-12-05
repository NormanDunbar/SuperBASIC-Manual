..  _set-fupdt:

SET\_FUPDT
==========

+----------+------------------------------------------------------------------+
| Syntax   | SET\_FUPDT #channel [,time] or                                   |
|          |                                                                  |
|          | SET\_FUPDT \\file [,time]                                        |
+----------+------------------------------------------------------------------+
| Location | Level-2 drivers                                                  |
+----------+------------------------------------------------------------------+

The command SET\_FUPDT sets the date on which a file was last altered.
This is always set to the current system DATE when a file is SAVEd, or
CLOSEd after having been written to. If time is not specified (or is 0),
then the current DATE is used. If time
is set to 1, then this command will have no effect on the file. COPY
sets the update time on the file being created to the current DATE. For
a SuperBASIC 'backup' function which gives the newly created file the
same update time as the original and alters the backup time, see FBKDT.
This command supports the current default data directory (see DATAD$).

**NOTE**

If you use SET\_FUPDT to alter the update time of a file OPENed to the
specified channel, closing that channel later in the program will not
affect the update time.

**CROSS-REFERENCE**

:ref:`fupdt`. See :ref:`fgeth-dlr`
for the structure of a file header, especially which byte is modified
when the update time is set.

--------------


