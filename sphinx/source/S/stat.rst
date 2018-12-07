..  _stat:

STAT
====

+----------+------------------------------------------------------------------+
| Syntax   | STAT [#channel,] [device] or                                     |
|          |                                                                  |
|          | STAT \\file [,device]                                            |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This command prints the name of a medium inserted into the given device
and the available sectors to the given channel
(default #1), or file. The device must be a directory device, such as
FLP1\_ (but not PAR or CON). If no device is stated, then the default
data device is used.

**Examples**

::

    STAT STAT ram1_
    STAT n2_win1_
    STAT #3,flp2_
    STAT #0 STAT \mdv2_
    STAT _dat
    STAT \ram5_TMP,mdv1_

**CROSS-REFERENCE**

:ref:`dlist` shows the default devices,
:ref:`datad-dlr` holds the default data device. Change
default devices with :ref:`data-use`,
:ref:`prog-use` and
:ref:`spl-use`. :ref:`dir` and
:ref:`wstat` provide other information about
directory devices.

