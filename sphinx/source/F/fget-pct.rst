..  _fget-pct:

FGET%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGET% [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads two bytes from #channel (default #1) and makes an
integer value from them, so these bytes should be in the internal format
of an integer to make FGET% useful.

An integer is stored in two bytes as Integer = Byte1\*256+ byte2

**CROSS-REFERENCE**

See :ref:`get` and :ref:`mki-dlr`.
:ref:`cvi-pct` converts a string containing the internal
format of an integer to an integer number. See also
:ref:`fput-pct`

