..  _cchr-dlr:

CCHR$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CCHR$ (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function CCHR$ takes a word value (max 32767) and returns two
characters represented by that word. This is therefore the same as:

X=PEEK\_W(10000)

PRINT CHR$(X DIV 256);CHR$(X MOD 256)

**CROSS-REFERENCE**


:ref:`chr-dlr` can be used to print each character separately.

