..  _dos-drive-dlr:

DOS\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   | directory$ = DOS\_DRIVE$(drive%)                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This reads back the currently connected directory of the DOS device.

**Example**

If we continue from the example above for :ref:`dos-drive`\ , then::

    PRINT DOS_DRIVE$(2)

Will print "C:\\WINDOWS".


--------------



