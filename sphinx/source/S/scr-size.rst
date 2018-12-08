..  _scr-size:

SCR\_SIZE
=========

+----------+------------------------------------------------------------------+
| Syntax   | SCR\_SIZE [(#channel)] or                                        |
|          |                                                                  |
|          | SCR\_SIZE (width\_x,width\_y [[,pos\_x],pos\_y] )                |
+----------+------------------------------------------------------------------+
| Location | SuperWindow Toolkit                                              |
+----------+------------------------------------------------------------------+

This function will return the space in bytes, a window (default #1) or
rectangle on the screen, needs to be stored with SCR\_STORE. Windows are
specified just by reference to their channel number, whereas rectangles
by their width and height. Naturally, the size of any shape is
independent from its position but the co-ordinates may be also added as
parameters without invoking an error message - or influencing the result
of SCR\_SIZE.

**WARNING**

SCR\_SIZE with a channel number will not work correctly if the Window
Manager is present because of the different window definition blocks.
Use either the second syntax or on a standard QL calculate the size
yourself: size=8+width\_x\*width\_y/4

**CROSS-REFERENCE**

:ref:`scr-store` stores a part of the screen in
RAM and :ref:`scr-refresh` copies it back.
See also :ref:`wman-dlr`.
:ref:`chan-w-pct` is much more flexible.

