..  _set-fvers:

SET\_FVERS
==========

+----------+------------------------------------------------------------------+
| Syntax   | SET\_FVERS #channel [,version] or                                |
|          |                                                                  |
|          | SET\_FVERS \\file [,version]                                     |
+----------+------------------------------------------------------------------+
| Location | Level-2 drivers                                                  |
+----------+------------------------------------------------------------------+

The command SET\_FVERS sets the version number of a file - versions
higher than 65535 or smaller than 0 are regarded as version MOD 65536,
version=0 (or if version is omitted) means that the version number will
not be updated when the channel to that file is closed. This command
supports the current default data directory (see DATAD$).

**Example**

::

    SET_FVERS \BOOT, 13

**CROSS-REFERENCE**

:ref:`fvers`. See :ref:`fgeth-dlr`
for the structure of a file header, especially which byte is modified
when the version is changed. The version number may be updated by
:ref:`save` and :ref:`qsave` on
SMS.

