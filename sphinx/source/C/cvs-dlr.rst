..  _cvs-dlr:

CVS$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CVS$ (mks\_$)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function takes the internal representation of a string and returns
the string concerned.

A string is represented internally as a word containing the length of
the string followed by the string itself.

**Example**

CVS$( CHR$(0) & CHR$(2) & "Test" ) = "Test"(1 TO 2) = "Te"

**CROSS-REFERENCE**

:ref:`mks-dlr`, :ref:`cvi-pct`,
:ref:`cvl`, :ref:`cvf`.
:ref:`fput-dlr` and :ref:`fget-dlr`
enable you to write strings to and read strings from files in their
internal formats.

