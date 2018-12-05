..  _get-byte-dlr:

GET\_BYTE$
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  GET\_BYTE$ (#channel,bytes)                                      |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function will read a specific number of bytes from the given
channel and return the result as a string. If GET\_BYTE$
cannot get the specified number of bytes from that channel, it will
wait until there are enough bytes present in the channel or until it
detects an End Of File character. GET\_BYTE$ does not care which
characters are read, so <LF> = CHR$(10) will not cause any problems
unlike INPUT.

**Example**

A program to compare the contents of two files, both of which are the
same length. The greater the buffer size (maximum 32767 bytes), the
faster will be the execution, but then again the greater the work space
which will be needed (maximum 64K). This is an example of the
fundamental link between available memory and operation speed::

    100 File1$="ram1_a"
    110 File2$="ram1_b"
    120 Buffer=10000
    130 :
    140 Pieces=FILE_LEN(File1$) DIV Buffer
    150 Rest=FILE_LEN(File1$) MOD Buffer
    160 OPEN#3,File1$: OPEN#4,File2$
    170 FOR Blk=0 TO Pieces+1
    180   IF Blk>Pieces THEN Buffer=Rest
    190   One$=GET_BYTE$(#3,Buffer)
    200   Two$=GET_BYTE$(#4,Buffer)
    210   PRINT "Block"!Blk TO 12;
    220   IF One$<>Two$ THEN
    230     PRINT "Difference between"!Buffer*Blk!"and"! Buffer*(Blk+1)
    240   ELSE
    250     PRINT "OK"
    260   END IF
    270 END FOR Blk
    280 CLOSE#3: CLOSE#4

**NOTE**

Earlier TinyToolkit versions (pre v1.10) called this function GET$,
which unfortunately caused problems with a similar function in the Turbo
Toolkit and EASYPTR.

**CROSS-REFERENCE**

:ref:`inkey-dlr` reads just one byte from the given
channel, which is therefore much slower than
:ref:`get-byte-dlr` if blocks of bytes are to be
read. On the other hand, :ref:`inkey-dlr` allows you
to specify a timeout.

The :ref:`input` command
combines input/output and reads blocks, but a block must end with <LF>.

The usage of the different keywords depends mainly on the structure of
the incoming data. User input and lines in an ASCII file normally
terminate with Enter <LF>, while internal data such as disk directory
entries are stored as blocks with a fixed length (see
:ref:`fop-dir`). Have a look at
:ref:`get`, :ref:`put`,
:ref:`bget` and :ref:`bput`, too.
:ref:`file-ptrr`,
:ref:`file-pos`, :ref:`fpos`
can be used for movement.

--------------


