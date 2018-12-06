..  _fgeth-dlr:

FGETH$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETH$ [(#filechan)]                                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads the file header from an open channel
linked to a file (default #3).

Each file has a header of 64 bytes
which contains technical information about the file. FGETH$ returns a
string containing 64 characters, each of which represents one byte of
the file header. The string contains the following information:

+-----------+---------------------------------+--------------------+---------------------+
| Character | Meaning                         | Value in string    | Equivalent Function |
+===========+=================================+====================+=====================+
|  1...4    | file length                     | CVL(h$(1 TO 4))    | FLEN                |
+-----------+---------------------------------+--------------------+---------------------+
|      5    | file access key                 | CODE(h$(5))        | None                |
+-----------+---------------------------------+--------------------+---------------------+
|      6    | file type                       | CODE(h$(6))        | FTYP                |
+-----------+---------------------------------+--------------------+---------------------+
|  7..14    | type dependent info (see below) |                    | FDAT,FXTRA          |
+-----------+---------------------------------+--------------------+---------------------+
| 15..16    | filename length                 | CVI%(h$(15 TO 16)) | LEN(FNAME$)         |
+-----------+---------------------------------+--------------------+---------------------+
| 17..52    | filename bytes                  | CVS$(h$(15 TO 52)) | FNAME$              |
+-----------+---------------------------------+--------------------+---------------------+
| 53..56    | update time                     | CVL(h$(53 TO 56))  | FUPDT               |
+-----------+---------------------------------+--------------------+---------------------+
| 57..58    | version number                  | CVI%(h$(57 TO 58)) | FVERS               |
+-----------+---------------------------------+--------------------+---------------------+
| 59..60    | reserved                        | CVI%(h$(59 TO 60)) | None                |
+-----------+---------------------------------+--------------------+---------------------+
| 61..64    | backup date                     | CVL(h$(61 TO 64))  | FBKDT               |
+-----------+---------------------------------+--------------------+---------------------+

The type dependent information is different for each file type. For
type 1 (executable files) bytes 7 to 10 hold the dataspace: CVL(h$(7 TO
10)). In early documentation, bytes 57 to 60 were reserved for a
reference date which was never implemented. The last eight bytes (57 to
64) are actually not used on level-1 drivers, level-2 drivers use every
byte. There is an *unofficial* standard for the file access key, which is
generally used by Toolkits to store file attributes in the format:

+--------+-------------------------------------------------------------------------------------------------------+
| Bit No | Meaning                                                                                               |
+--------+-------------------------------------------------------------------------------------------------------+
|     7  | Set if the file is read-only.                                                                         |
+--------+-------------------------------------------------------------------------------------------------------+
|     6  | Set if the file is hidden and will not appear on a directory of the disk. Neither can it be accessed. |
+--------+-------------------------------------------------------------------------------------------------------+
| 0 - 5  | are used to contain the User Number. Basically, this file will only be                                |
|        | accessible by someone with the same user number (0-63).                                               |
|        |                                                                                                       |
|        | Files with a                                                                                          |
|        | user number of 0 will be visible and usable by any user.                                              |
|        |                                                                                                       |
|        | Files with a                                                                                          |
|        | user number of 63 are generally only available to a user in a special                                 |
|        | mode (normally this will require a password).                                                         |
+--------+-------------------------------------------------------------------------------------------------------+

You will need specialist toolkits such as Toolkit III and System, neither of which are
compatible with SMS if the File Access Key is to have any effect.

**Examples**

Nearly every part of a file header (apart from the two unused bytes)
can be read by special functions (see the list above), here are two
functions to read the rest::

    100 DEFine FuNction FACCKEY (chan)
    110   LOCal h$
    120   h$=FGETH$(#chan)
    130   RETurn CODE(h$(5))
    140 END DEFine FACCKEY
    150 :
    160 DEFine FuNction FSPEC% (chan)
    170   LOCal h$
    180   h$=FGETH$(#chan)
    190   RETurn CVI%(h$(59 TO 60))
    200 END DEFine FSPEC%


**CROSS-REFERENCE**

:ref:`fseth-dlr` is the counterpart of
:ref:`fgeth-dlr`. :ref:`headr` and
:ref:`gethead` read file headers to given memory
positions, :ref:`fseth-dlr`,
:ref:`heads` and
:ref:`sethead` set them. Functions like
:ref:`flen`, :ref:`ftyp`,
:ref:`fxtra` etc. read the file header implicitly
and return a certain piece of information from it. Use the
:ref:`cvi-pct`, :ref:`cvl` and
:ref:`cvs-dlr` functions to convert the internal
representations to actual values.

