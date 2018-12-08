..  _rename:

RENAME
======

+----------+-------------------------------------------------------------------+
| Syntax   |  RENAME [device\_]oldname TO [device\_]newname                    |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI, Toolkit II                                             |
+----------+-------------------------------------------------------------------+

This command allows you to alter the name of a file which has already been created
on the given device.

You must first of all specify the name
of the file to be renamed (if no device is specified, the default data
directory will be used). You will then need to specify the new name for
that file (again, if no device is specified, the default data device
will be used). Assuming that both filenames are valid, an attempt will
be made to alter the filename as requested. If however newname
already exists an error will be generated.

**Example**

::

    RENAME flp1_boot TO flp1_oldboot

**NOTE 1**

If you try to RENAME a file across to another drive, (eg::

    RENAME flp1_boot, flp2_oldboot

the error 'bad name' will be reported.

**NOTE 2**

Although you can RENAME each file within a sub-directory so that they no
longer appear in that sub-directory, any attempt to RENAME the
sub-directory itself (even if there are no files in it) will cause the
error 'Read Only'.

For example, assuming that a directory of disk flp1\_
returns the following::

    boot QUILL->

You could for example, use::

    RENAME flp1_QUILL_boot TO flp1_ARCHIVE_boot

if you wished, but any attempt to use::

    RENAME flp1_QUILL TO flp1_ARCHIVE

will cause an error except on SMSQ/E (although an error is still
generated on RAM disks).

**NOTE 3**

Unless you have Minerva v1.77 (or later) fitted, RENAME will alter the
date of a microdrive file when used to rename a file on microdrive.

**NOTE 4**

In versions of Toolkit II before v2.10, RENAME could leave the file open
(and therefore inaccessible) if only one name was provided.

**NOTE 5**

If you try to use RENAME to change a filename to upper case (or
lower case) the error 'Already Exists' will be reported.

**CROSS-REFERENCE**

See also :ref:`wren` which allows you to rename
several files at once. :ref:`ttrename` is
similar.

