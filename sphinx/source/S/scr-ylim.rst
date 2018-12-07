..  _scr-ylim:

SCR\_YLIM
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SCR\_YLIM [(#ch)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function is the same as QFLIM(#ch,1) except that the channel
parameter is optional (it defaults to #0).

**NOTE**

As with SCR\_BASE, if the specified channel is not open then Invalid
Channel ID will be reported. However, if no channel is specified and #0
is not open, then a special window will be opened for #0 on screen,
which may destroy what is already on screen.

**CROSS-REFERENCE**

:ref:`qflim` and :ref:`ylim` are
similar. See also :ref:`scr-xlim`,
:ref:`scr-base` and
:ref:`scr-llen`.

