..  _set-header:

SET\_HEADER
===========

+----------+-------------------------------------------------------------------+
| Syntax   | error = SET\_HEADER(#channel, buffer)                             |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function  returns the error code that occurred when trying to set the header of the file on the given  channel, to the contents of the 64 byte buffer stored at the given address.  If the result is zero then you can assume that it worked ok, otherwise the result will be a negative QDOS error code.  On normal QLs, the three dates at the end of a file header cannot be set.

**EXAMPLE**

See the example for :ref:`read-header`.

**CROSS-REFERENCE**

:ref:`read-header`.


