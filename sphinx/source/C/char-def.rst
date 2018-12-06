..  _char-def:

CHAR\_DEF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHAR\_DEF font1,font2                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.57+                                                    |
+----------+-------------------------------------------------------------------+

This command is very similar to the CHAR\_USE command, except that
instead of altering the fonts attached to a specified window, it sets
the default fonts which are used for every new window channel that is
opened after this command (unless they in turn define their own fonts).

The two parameters should point to an address in memory where a font in
the QL font format is stored. If either parameter is 0, then that fount
is reset to the standard system fount. If either parameter is -1, then
CHAR\_DEF will not affect that font.

Minerva users can achieve the same effect with the following:

::

    110 Font0=PEEK_L (!124 !40)
    120 Font1=PEEK_L (!124 !44)
    130 POKE_L !124 !40, NewFont0, NewFont1

Note that you will need to store the addresses of the original QL ROM
fonts (as in lines 110 and 120).

**NOTE 1**

The screen windows which are already open will not be affected.

**NOTE 2**

This command cannot affect a screen window which has been OPENed over
the Network, unless issued on the Slave computer (on whose screen the
window appears), before the window was OPENed over the Network.

**CROSS-REFERENCE**

:ref:`char-use`,
:ref:`char-inc`.

Please also refer to the Fonts Appendix.

