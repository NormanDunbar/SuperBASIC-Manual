..  _qspace-pct:

QSPACE%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QSPACE% (#pipe\_ch)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This function returns the amount of empty space in a pipe connected to
the specified channel.

::

    PRINT QSPACE(#3)

is therefore the same as::

    PRINT QSIZE%(#3) - QCOUNT%(#3)

**CROSS-REFERENCE**

Refer to :ref:`qcount-pct` and
:ref:`qsize-pct`.

