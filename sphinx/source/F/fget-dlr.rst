..  _fget-dlr:

FGET$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGET$ [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads a string in internal format from a specified
channel (default #1) and returns the string.

A string is stored
internally as a two byte integer (see FGET%) specifying the length of
the string followed by the characters of the string itself.

**Example**

::

    100 OPEN_NEW#3,ram1_test
    110 PRINT#3,MKS$("Hello World.")
    120 FPOS_A#3,0
    130 PRINT FGET$(#3)
    140 CLOSE#3
    150 DELETE ram1_test

**CROSS-REFERENCE**

:ref:`get`, :ref:`fgetb`,
:ref:`fget-pct`, :ref:`fgetl`,
:ref:`mks-dlr`. :ref:`fput-dlr` writes
a string in internal format. :ref:`cvs-dlr` converts a
string into its internal format.

--------------


