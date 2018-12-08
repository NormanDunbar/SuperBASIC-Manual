..  _clear-hot:

CLEAR\_HOT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  CLEAR\_HOT key                                                   |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command deletes a hotkey defined with the HOT command and releases
the memory used to set up the hotkey back to QDOS' memory management.

**NOTE**

CLEAR\_HOT works okay, but in most cases the memory released by this
command is not recognised by the system as being free memory and
therefore cannot be re-used without resetting the system.

**CROSS-REFERENCE**

See :ref:`hot` on how to define a hotkey.

Use :ref:`free`,
:ref:`free-mem` to check the actual available memory.

