..  _iformat:

IFORMAT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  IFORMAT device\_[name]                                           |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command formats the specified device in IBM PS/2 disk format,
giving it the specified name (if any). The only difference between this
and AFORMAT is the way in which the boot sector is created. As with
FORMAT, this will normally format a disk to the highest possible density
- however, you can force it to format a disk as single-sided by making
the last character of the filename an asterisk (\*). However, some IBM
compatible PC's are unable to read single-sided disks.

**NOTE**

Unfortunately, you cannot format 360K or 1.2M disks with this command.

**CROSS-REFERENCE**

See :ref:`format` and
:ref:`aformat`. Other commands added are
:ref:`iqconvert`,
:ref:`adelete` and
:ref:`qcopy`.

