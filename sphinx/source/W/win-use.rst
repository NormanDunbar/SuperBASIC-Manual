..  _win-use:

WIN\_USE
========

+----------+--------------------------------------------------------------------+
| Syntax   |  WIN\_USE [device]                                                 |
+----------+--------------------------------------------------------------------+
| Location |  THOR XVI, ST/QL, Hard disk driver, SMSQ/E for Atari and QXL / QPC |
+----------+--------------------------------------------------------------------+


As with FLP\_USE this allows you to assign another three letter
description to the WIN device driver, so that it can be accessed by
programs which do not allow you to alter their devices. If no device is
specified, then the device name is returned to the default win.

**Example**

::

    WIN_USE mdv

will ensure that any further attempt to access mdv1\_ will actually
access win1\_. If you later use the command::

    WIN_USE

or::

    WIN_USE win

then you will once again be able to use the microdrives as well as
win1\_.

**NOTE**

The QL's operating system tests for directory device drivers in a fixed
order: DEV, FLP, RAM, WIN and MDV. This means that if you rename a
driver to three letters which refer to a device driver earlier in the
list, that original device driver will be used in preference. For
example::

    WIN_USE flp

will not work (attempts to read a file from flp1\_ will still try to
read floppy disk drive number one) - you will need to also rename the
floppy disk driver::

    FLP_USE flp

**CROSS-REFERENCE**

:ref:`flp-use`,
:ref:`ram-use`,
:ref:`dev-use` are similar.
:ref:`dmedium-type` can be used to find out
the type of device which a name actually refers to.
:ref:`dmedium-name-dlr` will return the default
name of a device.

