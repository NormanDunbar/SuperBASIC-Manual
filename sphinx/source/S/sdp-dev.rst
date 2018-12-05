..  _sdp-dev:

SDP\_DEV
========

+----------+-------------------------------------------------------------------+
| Syntax   |  SDP\_DEV device                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card, Trump Card, SDUMP\_REXT, ST/QL                        |
+----------+-------------------------------------------------------------------+

The command SDP\_DEV allows you to dictate where output from the SDUMP
device should be sent. Initially, all output is sent to ser, however you
may wish to alter this. Under SMS, you will need to LRESPR SDUMP\_REXT
provided on the distribution disk.

**Example**

SDP\_DEV n1\_flp1\_Dump  will cause all future output from the SDUMP device to be sent to a file
flp1\_Dump on the machine with NetID=1 in the Network.

**CROSS-REFERENCE**

:ref:`sdump` allows you to send output to the
specified device from SuperBASIC.

--------------


