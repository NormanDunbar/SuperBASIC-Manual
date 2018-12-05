..  _btool-ext:

BTool\_EXT
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  BTool\_EXT                                                       |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command is similar to TK2\_EXT and TINY\_EXT, in that it installs
BTool so that keyword definitions with the same name as those provided
in other Toolkits are overwritten with the Btool definition.


**WARNING**

BTool\_EXT will hang SuperBASIC if the BTool Toolkit has been loaded
into the common heap - this is most likely to happen on later versions
of Toolkit II where LRESPR uses the common heap if jobs are running. Try
LINKUP instead.

See also :ref:`kill` which removes all current jobs.

--------------


