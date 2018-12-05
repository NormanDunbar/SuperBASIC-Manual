..  _devtype:

DEVTYPE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVTYPE [(#channel)]                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This function returns a value to indicate the type of device the
specified channel (default #0) is connected to. At present, you should
only look at the first three bits of the return value, ie::

    x%=DEVTYPE(#channel)
    x%=x% && 3

The value returned is:

- 0 - a purely serial device
- 1 - a screen device
- 2 - a file system device (ie. it supports file positioning)

Any other values indicate that there is something wrong with the channel (if the
value is >2) otherwise, a negative value means that the channel is not open.


**NOTE**

Prior to v2.71, DEVTYPE would return 'End of File' error if the
specified channel was attached to a file and the file pointer was at the
end of the file.


**CROSS-REFERENCE**

:ref:`open`, :ref:`open-in`,
:ref:`open-new` and
:ref:`open-over` allow you to open channels.

--------------


