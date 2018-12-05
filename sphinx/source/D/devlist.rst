..  _devlist:

DEVLIST
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVLIST [#channel]                                               |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command lists all directory devices recognised by the system to
the specified channel. A directory device is one which contains files.
The default list channel is #1.


**NOTE**

If device names appear in the listing more than once, this means that
more than one device driver is loaded. This normally happens with
ramdisks ("RAM").


**CROSS-REFERENCE**

Directory devices may be renamed with :ref:`change`
(this will have a corresponding effect on
:ref:`devlist`), whilst any device can be renamed
using QRD (this will have no effect on
:ref:`devlist`). Compare
:ref:`dlist`.

--------------


