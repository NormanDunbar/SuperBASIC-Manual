..  _clrmdv:

CLRMDV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CLRMDV n                                                         |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, Btool                                               |
+----------+-------------------------------------------------------------------+

This command forces the QL to forget that it had already read a
cartridge in the given microdrive mdvn\_. This could be necessary if
cartridges are exchanged between QLs, otherwise one of the QLs may not
find a file written by another QL on a cartridge. Such problems do not
exist with floppies or any other media.

**Example**

CLRMDV 2

**CROSS-REFERENCE**

For :ref:`rand`, :ref:`clrmdv`
is very useful.

See also :ref:`del-defb` which performs a
similar task.

