..  _fwrite:

FWRITE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FWRITE #ch,address,bytes                                         |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

The command FWRITE reads a given number of bytes (bytes) from memory
(starting at address) and writes them to the given channel, which should
point to a file.

**Example**

A procedure which adds a file to another already existing file -
CONCAT cannot do so. This is a rather primitive version which grabs as
much memory as necessary and uses only TinyToolkit extensions. The
program is very primitive (not in its use of these extensions), but
because the memory management of the routine is simple (but fast) and as
FILE\_LEN does not support default devices and sub-directories, full
filenames have to be passed.

See :ref:`fread` for an enhanced version!

::

    100 DEFine PROCedure APPEND (file1$,file2$)
    110   length=FILE_LEN(file1$)
    120   buffer=GRAB(length)
    130   LBYTES file1$,buffer
    140   ch=FOPEN(file1$): FILE_PTRA#3,1E9
    150   FWRITE #ch,buffer,length
    160   CLOSE#ch: RELEASE buffer
    170 END DEFine APPEND

The procedure is called by APPEND file1$ TO file2$, which will add
the first file to the second file. First, a buffer of the size of the
first file is reserved in RAM, then, this file is read into the buffer.
Now the second file is opened, the file pointer moved to the end of it
and the whole buffer is then appended to the end of the file. Finally,
the channel is closed and the buffer RELEASEd.

**NOTE**

If the channel number does not refer to a file or even if the channel
has not yet been opened, FWRITE will report error -15 (bad parameter)
after it has completed its work. This behaviour is pretty strange.

**CROSS-REFERENCE**

:ref:`fread`, :ref:`lbytes`,
:ref:`sbytes`, :ref:`get`,
:ref:`put`. If you intend to use
:ref:`append`, please see
:ref:`fread` for a better version.

--------------


