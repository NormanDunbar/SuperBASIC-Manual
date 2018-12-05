..  _ser-setport:

SER\_SETPORT
============

+----------+-------------------------------------------------------------------+
| Syntax   | SER\_SETPORT port%, com$                                          |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

Sets the COM port a SER port should be connected with. The change will take effect on the next open of the specified serial port.

**Example**

::

    SER_SETPORT 4,"COM32"

Will associate SER4 with COM32.

**CROSS-REFERENCE**

See :ref:`ser-getport-dlr`.

--------------


