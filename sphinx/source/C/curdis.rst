..  _curdis:

CURDIS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CURDIS [#ch]                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, QSOUND                                     |
+----------+-------------------------------------------------------------------+

This command disables the cursor in the given channel. See CURSEN!

The default window for this command is #1.

If a cursor is disabled in a given window (or does not exist), task
switching with <CTRL><C> to the job which owns that window will not work
unless the Pointer Environment is present.

**WARNING**

Do not use CURDIS #0 as this may prevent further input.

**CROSS-REFERENCE**

See :ref:`cursen` for more details.

:ref:`cursor-off` is similar.

--------------


