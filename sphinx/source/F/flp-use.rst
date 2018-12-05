..  _flp-use:

FLP\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_USE [device]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, Trump Card, THORs, ST/QL, SMS, SMSQ/E for QPC        |
+----------+-------------------------------------------------------------------+

Software which was written in the early days of the QL tended to
assume that it would always be run from microdrive, and therefore
included no facilities to alter the default devices used by the
software.

You may even find some software was written on a non-standard
disk system and assumed that disks would be accessed via FDK rather than
the normal FLP.

The FLP\_USE command allows you to use such software by
making the FLP device emulate any other device. You merely need to
supply a three letter parameter representing the name of the device
which is to be emulated. Once you do this, the FLP device will no longer
be recognised. If the device is not specified, then the system reverts
to using FLP to access the disk drives.

**Example**

::

    FLP_USE 'mdv'

will allow you to use software which would normally run from microdrive (unless it is copy protected!).

**CROSS-REFERENCE**

:ref:`ram-use`,
:ref:`dev-use` and
:ref:`win-use` are very similar.
:ref:`dmedium-type` can be used to find out
the type of device which a name actually refers to.
:ref:`dmedium-name-dlr` will return the default
name of a device.

--------------


