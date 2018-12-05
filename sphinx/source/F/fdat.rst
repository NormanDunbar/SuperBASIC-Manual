..  _fdat:

FDAT
====

+----------+------------------------------------------------------------------+
| Syntax   | FDAT [(#channel)] or                                             |
|          |                                                                  |
|          | FDAT (\\filename) (Toolkit II and THOR)                          |
+----------+------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, BTool                                     |
+----------+------------------------------------------------------------------+

This function returns the value of four bytes (at offset 6 to 9) in a
file header. This value represents the dataspace of executable files
(file type 1). There is no convention for any other file types. The
default data device and sub-directories are supported, the default
channel is #3.

**CROSS-REFERENCE**

:ref:`fxtra` returns the other four bytes of the
type dependent information contained in the file header.
:ref:`file-dat` is very similar to
:ref:`fdat`. See also :ref:`ftyp`.

--------------


