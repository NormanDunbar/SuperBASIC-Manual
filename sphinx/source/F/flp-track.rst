..  _flp-track:

FLP\_TRACK
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_TRACK tracks                                                |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, Trump Card, THOR, ST/QL, SMS                         |
+----------+-------------------------------------------------------------------+

When a disk is formatted, the operating system will check to see if
there are more than 55 tracks on the disk, and if so, will presume that
it should be formatted to 80 tracks (otherwise it will presume the disk
is to be formatted to 40 tracks).

The command FLP\_TRACK allows you to
override this setting, so that you can format a disk to, say, 75 tracks.
FLP\_TRACK 40 should be used as standard when a 40 track disk drive is
attached to the system as this will prevent the system from trying to
read track 55 (which does not exist!!), thus saving wear on the drive.

**Example**

::

    FLP_TRACK 40

can be used on a standard DSDD 80 track disk to format it into a form
readable on a 40 track drive.

**CROSS-REFERENCE**

:ref:`flp-density` also affects how a disk is
:ref:`format`\ ted.

--------------


