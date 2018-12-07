..  _w-show:

W\_SHOW
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_SHOW #channel, address                                        |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This command takes an image stored at the specified address
using either the W\_CRUNCH or W\_STORE functions and then copies it
across to the specified window channel.

**NOTE 1**

This command will only work on screen resolutions of 512x256 pixels.

**NOTE 2**

The memory used by W\_CRUNCH or W\_STORE is not released, so that you
can re-display the screen again in the future.

**NOTE 3**

An out of range error will be reported if the stored image will not fit
within the specified window.

**CROSS-REFERENCE**

See :ref:`scr-refresh` and
:ref:`scr-store`. See also
:ref:`w-store`,
:ref:`w-crunch`.
:ref:`w-swop`,
:ref:`set-red` and
:ref:`set-green` allow you to recolour windows.

