..  _fseth-dlr:

FSETH$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FSETH$ [#ch,] header$                                            |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FSETH$ is a command which is the counterpart of FGETH$: it accepts
either a 14 or 64 bytes long string which contains a file header (or at
least the first part of that) and sends that file header to the
specified channel (default #3).

**CROSS-REFERENCE**

See :ref:`heads` and
:ref:`sethead`!

