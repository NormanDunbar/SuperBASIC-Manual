.. _card-dir-dlr:

CARD\_DIR$
==========

+----------+-------------------------------------------------------------------+
| Syntax   | CARD\_DIR$(card)                                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                    |
+----------+-------------------------------------------------------------------+

Returns a string containing the first 16 8.3 entries on the FAT23
partition of card 1 or 2.

Entries are separated by linefeeds (ascii 10) with "-- Empty --"
signifying an empty slot and "-Long name-" signifying a filename that
does not fit the 8.3 format.

**CROSS-REFERENCE**

:ref:`card-create`
