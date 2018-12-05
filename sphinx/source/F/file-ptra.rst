..  _file-ptra:

FILE\_PTRA
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_PTRA #channel, position                                    |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command forces the file pointer to be set to the given position.
Positions greater than the actual file length or smaller than zero will
set the pointer to the end or start of the file respectively.

**CROSS-REFERENCE**

:ref:`file-ptrr`,
:ref:`file-pos`, :ref:`fpos`,
:ref:`flen`, :ref:`file-len`,
:ref:`get`.

--------------


