..  _fname-dlr:

FNAME$
======

+----------+------------------------------------------------------------------+
| Syntax   | FNAME$ [(#channel)] or                                           |
|                                                                             |
|          | FNAME$ (\\file)(Toolkit II only)                                 |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, BTool                                                |
+----------+------------------------------------------------------------------+

This function returns the filename of a file attached to the
specified channel (default #3), including the sub-directory prefix but
without the pure device name (eg. RAM1\_).

The second syntax enables you
to find out the full filename of the specified file.

It is hard to
understand why one should need to find out about the name of an opened
file - the second syntax is even more absurd.

One possible usage is to
convert a Toolkit II filename, which need not include the current
sub-directory, to a full file name. However, the functions DATAD$,
PROGD$ together with some string operations are much faster and more
elegant because they skip the need to access the file header.

**CROSS-REFERENCE**

:ref:`flen`, :ref:`ftyp`,
:ref:`fdat`, :ref:`fxtra`,
:ref:`fupdt`,
:ref:`file-len` and
:ref:`file-type` return other information about a
file.

--------------


