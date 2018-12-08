..  _wren:

WREN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WREN [#ch,] [wild1] [TO wild2]                                   |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to rename several files at the same time. It
allows wildcards on both the source and destination parameters. If the
source parameter (wild1) does not include a valid device, the default
data device will be used. However, the way in which wild2 is calculated,
is even more complex than normal:

#. If wild2 is not specified, rename each file using the default destination directory.
#. If wild2 is specified and contains a device, use that device.
#. If wild2 does not include a device, use the same device as for wild1 (ie. the device
   specified as part of wild1 or DATAD$).

Beyond this, WREN acts in a
similar way to WCOPY, listing each file that is being renamed to the
specified channel (default #0). However, instead of moving the old file,
the header is merely amended to reflect the new name.

**Examples**

::

    WREN flp1_QUILL_ TO flp1_

could be used to take all of the Quill files out of a sub-directory
into the main directory, by deleting the sub-directory prefix.

::

    DEST_USE flp1_QUILL_
    DATA_USE flp1_
    WREN

would have the opposite effect.

**NOTE**

Any attempt to rename a file across to a different device will report
the error 'Bad Name'.

**CROSS-REFERENCE**

:ref:`rename` renames one file at a time.
:ref:`wcopy` contains details of wildcards.

