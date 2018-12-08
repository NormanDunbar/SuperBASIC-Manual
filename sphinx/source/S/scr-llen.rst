..  _scr-llen:

SCR\_LLEN
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SCR\_LLEN [(#ch)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v2.25+), SMSQ/E                                     |
+----------+-------------------------------------------------------------------+

This function returns the number of bytes required to hold one line of
pixels on the current screen resolution attached to the specified
channel (default #0). On a standard QL 512x256 resolution, this is
normally 128 bytes but can alter on other resolutions.

**NOTE**

As with SCR\_BASE, if the specified channel is not open then Invalid
Channel ID will be reported. However, if no channel is specified and #0
is not open, then a special window will be opened for #0 on screen,
which may destroy what is already on screen.

**WARNING**

You should never assume that the number of bytes required to store a
line is the number of pixels DIV 4 - always use this function instead.

**CROSS-REFERENCE**

:ref:`scrinc` is similar. See also
:ref:`scr-xlim`,
:ref:`scr-ylim` and
:ref:`scr-base`. On QL ROMs after JM, you can
also use :ref:`print` :ref:`chan-b-pct`\ (#1,104).

