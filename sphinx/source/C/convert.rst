..  _convert:

CONVERT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CONVERT src\_file,dst\_file,original$,replacement$               |
+----------+-------------------------------------------------------------------+
| Location |  CONVERT                                                          |
+----------+-------------------------------------------------------------------+

This command is used to copy src\_file to dest\_file and replace all
occurrences of original$ by replacement$.

Both strings must have the same length.

The search is case-independent.

No default devices are supported.

**Example 1**

Take a QUILL-document and export it using the 'Print to file' option
without a printer driver in the main drive.

Next VIEW it or look at it with an editor or by: COPY flp1\_example\_lis
TO scr.

You will see the character CHR$(13) (the carriage return <CR> character)
at the end of each line. This is not needed by QDOS to perform a
carriage return on screen. Remove these excess characters with: CONVERT
flp1\_example\_lis, flp1\_example\_txt, CHR$(13), " ".

<CR> at the end of lines may also appear when downloading messages from
a bulletin board or converting MS/DOS text files to QDOS.

**Example 2**

Badly written or simple programs generally lack the feature to change
device names for file operations. Using commands like FLP\_USE may have
a negative effect on any jobs which are running simultaneously, so it is
better to make the program use flp1\_ instead of mdv2\_.

This can be achieved quite simply with the command: CONVERT prog1\_exe,
prog2\_exe, "mdv2\_", "flp1\_".

**NOTE**

The character CHR$(0) cannot be replaced.

**CROSS-REFERENCE**

:ref:`exchg` is similar to
:ref:`convert`.

