..  _flen:

FLEN
====

+----------+------------------------------------------------------------------+
| Syntax   | FLEN [(#channel)] or                                             |
|          |                                                                  |
|          | FLEN (\\file)(Toolkit II and THOR only)                          |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI, BTool                                      |
+----------+------------------------------------------------------------------+

This function returns the length of a file in bytes. If the second
version is used, then Toolkit II's default data device and
sub-directories will be supported, meaning that the command will consult
the default data directory if necessary (see DATAD$).

If you use the
first version however, you will first of all need to open a channel. If
you do not supply a channel number, then the default used by the
function is #3.

**NOTE 1**

The space on disks, cartridges, ramdisks and all other media where files
can be stored is divided up into sectors, which are normally 512 bytes
long. A file does not occupy the number of bytes returned by FLEN but a
certain number of sectors for the contents of the file itself, a few
bytes for the file header and the directory entries (sector map, etc).
The total number of sectors which are occupied by the file data are::

    sectors = 2 + CEIL(FLEN(\file)/512)


**NOTE 2**

If the second syntax does not work, update your Toolkit.

**CROSS-REFERENCE**

:ref:`file-len` has a slightly different syntax.
:ref:`file-type`,
:ref:`file-dat`,
:ref:`file-pos`,
:ref:`fname-dlr`, :ref:`fpos`,
:ref:`ftyp`, :ref:`fupdt` and
:ref:`fxtra` hold other information about a file.
:ref:`headr` and :ref:`heads`
allow you to directly access a file header.

--------------


