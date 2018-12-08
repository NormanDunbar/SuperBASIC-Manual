..  _flp-start:

FLP\_START
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FLP\_START time                                                   |
+----------+-------------------------------------------------------------------+
| Location | Gold Cards, Trump Card, THORs, ST/QL (level D.02+ drivers), SMS,  |
|          | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

The disk system always tries to read data from a disk as soon as it
can. However, when writing to a disk, it is necessary to ensure that the
disk is running at full speed before any information is sent to it.

For relatively new drives, the default waiting time of 0.5 seconds should be
enough to ensure that the disk is running at full speed.

The command FLP\_START can be used for older disks to allow a longer run-up time. You will need to specify the time in 20ms units - some older drives may
require a value of about 60.

**Example**

::

    FLP_START 13

sets the start up time to 13 \* 20ms (260ms) - this may suit the most recent 3.5" drives.

**NOTE**

FLP\_START has no effect on either the QXL or QPC implementations of
SMSQ and SMSQ/E.

**CROSS-REFERENCE**

You may also need to alter the stepping rate with
:ref:`flp-step`.

