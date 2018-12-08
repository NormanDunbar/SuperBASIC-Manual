..  _scr-base:

SCR\_BASE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SCR\_BASE [(#ch)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v2.25+), SMSQ/E                                     |
+----------+-------------------------------------------------------------------+

This function returns the base address of the screen linked to the
specified channel (default #0), this is normally 131072 on standard QLs
but can alter on other resolutions or if dual screen mode is supported.
On machines which support higher resolutions, the screen base will only
be at the standard address of 131072 if you configure the machine to
start up in 512x256 and even here there is no guarantee - see the
documentation for the particular QL resolution you are using.

**NOTE**

If the specified channel is not open then Invalid Channel ID will be
reported. However, if no channel is specified and #0 is not open, then a
special window will be opened for #0 on screen, which may destroy what
is already on screen.

**CROSS-REFERENCE**

:ref:`screen` is similar. See also
:ref:`scr-xlim`,
:ref:`scr-ylim` and
:ref:`scr-llen`.
:ref:`a-oldscr` can help some older software to
work. You can also use :ref:`print` :ref:`chan-l-pct`\ (#1,50) instead of
:ref:`scr-base`.

