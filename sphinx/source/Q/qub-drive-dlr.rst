..  _qub-drive-dlr:

QUB\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  QUB\_DRIVE$ (drive)                                              |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Q68                                                   |
+----------+-------------------------------------------------------------------+

This function returns a string containing the card and filename for
specified QUB drive.

If the specified drive has not been linked to any particular file
partition, an empty string is returned.

**Example**

::

    QUB_DRIVE 1,1,"ql_bdi0.bin"
    PRINT QUB_DRIVE$(1): REMark Will print QL_BDI0.BIN,1

**Note 1**

By default the QUB driver may not be loaded in SMSQ/E

**CROSS-REFERENCE**

See :ref:`qub-drive`.

