..  _fgetb:

FGETB
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETB [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads a single byte (character) from a specified
channel (default #1) and returns its numeric value.

**Example**

::

    100 PRINT "Please press any key..."
    110 CLEAR: c = FGETB
    120 PRINT "You pressed '";CHR$(c);"', ";
    130 PRINT "which is code"!c!"($";HEX$(c,8);")."

**CROSS-REFERENCE**

The Toolkit II equivalent is :ref:`bget`. See also
:ref:`fputb`!

--------------


