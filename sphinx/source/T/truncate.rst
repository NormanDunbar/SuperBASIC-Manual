..  _truncate:

TRUNCATE
========

+----------+------------------------------------------------------------------+
| Syntax   | TRUNCATE #channel [\\position] or                                |
|          |                                                                  |
|          | TRUNCATE                                                         |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

Every file has a certain length, measured in bytes, which can be
reduced with the command TRUNCATE. If TRUNCATE is used without the
position parameter, the end of the file will be moved to the current
file pointer position, meaning that for most purposes, the last byte of
the file is the byte which was being pointed to.

If you supply a second
parameter, then the file pointer is set to the given position before the
file is TRUNCATEd. Note that any data after the new 'end of file' will
be lost.

TRUNCATE returns error -15 (invalid parameter) if the specified
channel is not actually linked to a file. A position
greater than the actual file length, such as position>=FLEN(#channel)
has no effect. TRUNCATE without any parameters uses #3 as the default
channel and is therefore the same as::

    TRUNCATE #3

**NOTE**

The syntax TRUNCATE \\position is not valid, error -17 (error in
expression) will be reported. You have to specify a channel number if
you intend to set the file pointer before truncating the file.

**CROSS-REFERENCE**

:ref:`flen` and
:ref:`file-len` return the length of a file,
:ref:`fpos` and
:ref:`file-pos` the current file pointer
position, :ref:`file-ptra` and
:ref:`file-ptrr` move the file pointer as do
:ref:`get`, :ref:`put`,
:ref:`bget` and :ref:`bput`.

--------------


