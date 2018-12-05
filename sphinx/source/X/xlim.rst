..  _xlim:

XLIM
====

+----------+------------------------------------------------------------------+
| Syntax   | XLIM  or                                                         |
|          |                                                                  |
|          | XLIM #ch (v2.08+)                                                |
+----------+------------------------------------------------------------------+
| Location | ATARI\_REXT (v1.29+)                                             |
+----------+------------------------------------------------------------------+

This function returns the horizontal size of the screen in pixels. It
can therefore be used to ascertain if the Extended Mode-4 is present,
and if so, the size of the screen available to the program (ie. 512x256,
768x280 or larger!). The second variant makes this function the same as
SCR\_XLIM.

**Example**

A program may wish to use the whole of the screen for its output,
adapting itself accordingly::

    100 MAX_WIDTH=XLIM
    110 MAX_HEIGHT=YLIM
    120 OPEN #1,'CON_' & MAX_WIDTH & 'x' & MAX_HEIGHT & 'a0x0'

**NOTE**

The Pointer Interface must be present in order for XLIM to work.

**CROSS-REFERENCE**

:ref:`ylim` returns the maximum screen height.
:ref:`qflim` and
:ref:`scr-xlim` are very similar. Use
:ref:`qram-dlr` or :ref:`wman-dlr` to
see if the Pointer Environment is available.

--------------


