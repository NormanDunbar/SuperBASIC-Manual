..  _qub-drive:

QUB\_DRIVE
==========

+----------+------------------------------------------------------------------+
| Syntax   | QUB\_DRIVE drive, card, file                                     |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                   |
+----------+------------------------------------------------------------------+

This command mounts a the first partition of a file formated like a Qubide drive. The file is specified by the card it is on and the filename

**Example**

::
   
   QUB 1,1,"ql_bdi0.bin"

**Note 1**

Do not attempt to make two QUB drives point to the same partition!

**Note 2**

By default the QUB driver may not be loaded in SMSQ/E

**CROSS-REFERENCE**

:ref:`qub-drive-dlr` returns the parameters already associated with a
QUB drive.

