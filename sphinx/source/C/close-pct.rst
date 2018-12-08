..  _close-pct:

CLOSE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CLOSE% n                                                         |
+----------+-------------------------------------------------------------------+
| Location |  BTool, TinyToolkit                                               |
+----------+-------------------------------------------------------------------+

The command CLOSE% allows you to close a channel which is specified
using the channel number listed when you use the CHANNELS command. This
thus allows you to close channels owned by other Jobs.

**WARNING**

If you close the channel of a job, this can lock up that job. Ensure
that you know the consequences of your actions!

**CROSS-REFERENCE**

:ref:`channels`, :ref:`close`

