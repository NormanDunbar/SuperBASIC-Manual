..  _tiny-ext:

TINY\_EXT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  TINY\_EXT                                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command installs/updates the extensions provided by the Tiny
Toolkit. TinyToolkit and Toolkit II have some commands in common (eg.
REPORT). If you prefer to use Toolkit II's REPORT command you will
generally need to install TK2\_EXT after TINY\_EXT (on post JM ROMs the
Toolkit which was installed second will have priority!). Prior to JS
ROMs, the first version of a command loaded as a toolkit has priority.

**NOTE**

Updating TinyToolkit is different from updating other Toolkits with
\_EXT type commands, in that TinyToolkit simply adds its commands' names
to the name list and does not check to see if they were already present.
SXTRAS and EXTRAS will list commands twice (or more) and each time that
TINY\_EXT is issued, memory will be used up (max. 1 KB). Actually, the
Toolkit is only present in one place in memory because duplicated
commands are stored at the same place in RAM. This problem can be cured
with TINY\_RMV.

**CROSS-REFERENCE**

:ref:`tk2-ext` updates Toolkit II,
:ref:`beule-ext` the Beule Toolkit.
:ref:`tiny-rmv` removes most extensions of
TinyToolkit from the name list.

--------------


