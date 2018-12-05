..  _unjob:

UNJOB
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  UNJOB drive\_filename                                            |
+----------+-------------------------------------------------------------------+
| Location |  UNJOB                                                            |
+----------+-------------------------------------------------------------------+

This command sets the file type of the given file (the full filename
must be supplied) to zero. The reason for this command is that certain
assemblers and tools set the file type to 1 (executable file) even
though the file cannot be started as a job. Since commands like EX or
EXEC check the file type to decide whether a file can be executed, they will
try to start such a file and crash the system in most cases. A simple
UNJOB prevents this in the long term.

**NOTE**

v1.00 of this command did not work on most QL ROM versions, giving a bad
parameter error.

**CROSS-REFERENCE**

Each file has a file type which can be found with the
:ref:`ftyp` and
:ref:`file-type` functions or directly by looking
at the file header (:ref:`headr`). It is also
possible to set the file type by rewriting the whole file header with
:ref:`heads`; alternatively,
:ref:`unjob` does the same.

--------------


