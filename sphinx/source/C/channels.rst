..  _channels:

CHANNELS
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CHANNELS [#ch]                                                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool, Qsound, TinyToolkit                                       |
+----------+-------------------------------------------------------------------+

The command CHANNELS list all channels which are currently open
(including channels from any other job) to the given channel (default
#1).

Each channel is listed with a channel number which can be used with
CLOSE% and provides details of its size and position. Unfortunately, the
name of the Job which owns the channel is not listed.

**NOTE**

The Tiny Toolkit and Qsound version of this command do not currently
work with the Pointer Environment. The BTool version works to some
extent.

**CROSS-REFERENCE**

:ref:`close-pct`, :ref:`jobs` and
:ref:`chanid`

