..  _expand:

EXPAND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  EXPAND file$                                                     |
+----------+-------------------------------------------------------------------+
| Location |  COMPICT                                                          |
+----------+-------------------------------------------------------------------+

This command takes a screen file (which must have been created with COMPRESS),
and re-expands it on the visible screen.

**NOTE 1**

EXPAND needs a working space of 32K. A memory overflow error will be
reported if there is not enough memory available.

**NOTE 2**

EXPAND assumes that the screen starts at $20000 and will therefore not
work on Minerva's second screen or extended resolutions.

**NOTE 3**

EXPAND will not work on QLs with resolutions above 512x256

**WARNING**

If the file was not saved by COMPRESS, it is most likely that the system
will crash. This is certain if the file is longer than 32K.

**CROSS-REFERENCE**

:ref:`compress`,
:ref:`fastexpand`.

--------------


