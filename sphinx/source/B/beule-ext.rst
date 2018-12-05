..  _beule-ext:

Beule\_EXT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  Beule\_EXT                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command is used to update all of the keywords which are added by
the Beuletools Toolkit. The new keywords were automatically added when
the Toolkit was loaded but keywords can be overwritten by other
Toolkits, renamed or ZAPped.

Beule\_EXT undoes these changes and restores the default status.


**WARNING**

Do not load the Beuletools toolkit into anything other than resident
procedure memory (ie. do not have any Jobs running other than Job 0 when
the toolkit is loaded). This may crash the system.


**CROSS-REFERENCE**

:ref:`tk2-ext` and
:ref:`tiny-ext` do the same for Toolkit II and
TinyToolkit keywords.

See also :ref:`atari-ext`.

--------------


