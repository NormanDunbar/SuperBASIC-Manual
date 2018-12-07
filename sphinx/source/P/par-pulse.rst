..  _par-pulse:

PAR\_PULSE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_PULSE x                                                     |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for the Atari                                      |
+----------+-------------------------------------------------------------------+

Some accelerator boards enhance the speed of the Atari ST and TT
computers so much that the parallel printer port may be affected. This
can be fixed by using PAR\_PULSE to increase the rate of the strobe
pulse. This problem tends to be required if you have a printer which has
heavy drive requirements (notably a CANON) or if you use a long printer
cable.

**Example**

::

    PAR_PULSE 80

**NOTE**

On SMSQ/E running on non-Atari's, this command has no effect.

