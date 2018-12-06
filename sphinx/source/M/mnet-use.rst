..  _mnet-use:

MNET\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET\_USE id                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

Due to the fact that MIDINET Networks can be run on computers alongside
SERNET Networks and even QNET Networks, it may be necessary to alter the
identification letter used to access facilities on other computers in the
Network. The default letter id is n (as with FSERVE), but this can be
set to any other single letter by using this command. However, you
should avoid letters which already appear as the first letter in another
device driver (see DEVLIST).

**Example**

::

    MNET_USE m
    OPEN #3,m2_con_512x256a0x0

Open an input channel covering the screen on station number 2 in the
MIDINET Network.

**CROSS-REFERENCE**

See :ref:`mnet` and
:ref:`midinet`. Refer also
to\ :ref:`mnet-s-pct`.

