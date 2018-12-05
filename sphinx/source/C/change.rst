..  _change:

CHANGE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHANGE old\_drv1$ TO new\_drv2$                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command allows you to rename directory devices. All directory
device names are in the form xxxn\_, where xxx identifies the drive type
(eg. FLP) and n the drive number (1..8).

The most common drive types are:

-  RAM - temporary internal ramdisk
-  FLP - floppy disk drive (sometimes called FDK)
-  MDV - microdrive
-  MOS - permanent external ramdisk
-  WIN - hard disk drive (sometimes HDK)
-  NUL - null device, a dummy device
-  DEV - universal devices (also PTH)

(Please see the Devices Appendix.)

CHANGE replaces the xxx part of a device name by a user defined name.
This new name can already exist but both parameters must consist of
three letters; the use of characters other than letters is possible but
not recommended, eg:

CHANGE "flp" TO "<\*>".

**Example**

CHANGE "ram" TO "mdv" makes the system believe that a ramdisk is a
microdrive.

DIR mdv1\_ will provide a directory of ramdisk 1, but the device ram1\_
(or ram2\_, etc.) is no longer recognised. The microdrives themselves
cannot be accessed any more until you use: CHANGE "mdv" TO "ram" to
restore the normal condition.

**NOTE**

If a device name is in ROM (eg. possibly mdv on QLs without floppy disk
drives), the error -20 (read only) will be reported.

**CROSS-REFERENCE**

:ref:`flp-use` and
:ref:`ram-use` work similarly.

--------------


