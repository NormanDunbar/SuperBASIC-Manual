..  _char-use:

CHAR\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHAR\_USE [#ch,] font1,font2                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command allows you to attach substitute fonts in QDOS format to the
specified window channel (default #1).

CHAR\_USE will attach the two fonts at addresses font1 and font2 to the
window in place of the current system fonts.

When a character is printed, if it cannot be found at either font1 or
font2, then the first character of the second font will be used.

To return to the current system fonts on the specified window, use
font1=0 or font2=0 as appropriate.

If you use the value of -1 as one of the parameters, then that font
attached to the specified channel will not be altered by this command.

**Example**

CHAR\_USE #3,font\_address,0

resets the first font in #3 to the font stored at font\_address in
memory.

**NOTE**

This command will have no effect on a window OPENed over the Network.

**CROSS-REFERENCE**

Please refer to the Fonts Appendix concerning QL fonts.

:ref:`char-inc` allows you to alter the spacing
between characters.

:ref:`char-def` allows you to alter the default
system fonts.

:ref:`s-font` performs the same function as
:ref:`char-use`.

--------------


