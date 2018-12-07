..  _win-start:

WIN\_START
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_START driveno                                               |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for Atari and QPC / QXL                            |
+----------+-------------------------------------------------------------------+

After the head on a changeable hard disk drive has been parked, it is
necessary to tell it to release its head before you can access the
drive. WIN\_START issues the command to do this. The parameter driveno
is the number of the hard disk to be told to release the head. Driveno
must be in the range 1...8.

**Example**

::

    WIN_START 1

releases the head on win1\_.

**NOTE**

Some hard disk drives will not release the head even after WIN\_START
unless the power to the drive is switched off and back on.

**CROSS-REFERENCE**

See also :ref:`win-drive` and
:ref:`win-stop`.

