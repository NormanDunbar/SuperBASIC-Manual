..  _fat-use:

FAT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   | FAT\_USE [device]                                                 |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                    |
+----------+-------------------------------------------------------------------+


As with FLP\_USE this allows you to assign another three letter
description to the FAT device driver, so that it can be accessed by
programs which do not allow you to alter their devices. If no device is
specified, then the device name is returned to the default fat.

**Example**

::

    FAT_USE mdv

will ensure that any further attempt to access mdv1\_ will actually
access fat1\_. If you later use the command::

    FAT_USE

or::

    FAT_USE fat

then you will once again be able to use the microdrives as well as
fat1\_.

**Note 1**

The QL's operating system tests for directory device drivers in a fixed
order: DEV, FLP, RAM, WIN and MDV. This means that if you rename a
driver to three letters which refer to a device driver earlier in the
list, that original device driver will be used in preference. For
example::

    FAT_USE flp

will not work (attempts to read a file from flp1\_ will still try to
read floppy disk drive number one) - you will need to also rename the
floppy disk driver::

    FLP_USE flp

**Note 2**

By default the FAT driver may not be loaded in SMSQ/E

**CROSS-REFERENCE**

:ref:`flp-use`,
:ref:`ram-use`,
:ref:`dev-use`,
:ref:`win-use` are similar.
:ref:`dmedium-type` can be used to find out
the type of device which a name actually refers to.
:ref:`dmedium-name-dlr` will return the default
name of a device.

