..  _snet-use:

SNET\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SNET\_USE id                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

Due to the fact that SERNET Networks can be run on computers alongside MIDINET
Networks and even QNET
Networks, it may be necessary to alter the identification letter used to
access facilties on other computers in the Network. The default letter
id is s, but this can be set to any other single letter by using this
command. However, you should avoid letters which already appear as the
first letter in another device driver (see DEVLIST).

**Example**

::

    SNET_USE c
    DEV_USE 3,c2_win1_

Redefine DEV3\_ so that it refers to win1\_ on station number 2 in the
SERNET Network. This can be useful to allow some programs to access data
over the Network. However note the file protection implemented in SERNET
and MIDINET.

**NOTE**

Before v2.28 of Toolkit II, the various wildcard commands did not accept
any single letter other than n as representing a Network.

**CROSS-REFERENCE**

See :ref:`snet` and
:ref:`sernet`. Refer also to
:ref:`snet-s-pct`.
:ref:`mnet-use` is similar. See also
:ref:`nfs-use`.

