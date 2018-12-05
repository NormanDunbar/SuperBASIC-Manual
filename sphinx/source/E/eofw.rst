..  _eofw:

EOFW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  EOFW (#ch)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This function is very similar to EOF in that it returns the value 0 if there is
data waiting to be read from the specified channel, otherwise it returns 1. The
difference is that this version of the function will however wait until data is
received or the end of file code is received, which is especially useful on pipes
which may not always work with EOF which returns 1 if the channel does not contain
any data to be read.

**CROSS-REFERENCE**

See :ref:`eof`. :ref:`pend` and
:ref:`io-pend-pct` are very similar.

--------------


