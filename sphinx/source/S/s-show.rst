..  _s-show:

S\_SHOW
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  S\_SHOW adr                                                      |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Adr must be a value returned by S\_SAVE: the command S\_SHOW
displays the screen information stored by S\_SAVE. The screen is
however retained in memory for future access.

**NOTE**

This command suffers with the same problems as S\_LOAD.

**WARNING**

A wrong address leads to serious crashes.

**CROSS-REFERENCE**

:ref:`s-save`


