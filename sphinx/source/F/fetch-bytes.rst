..  _fetch-bytes:

FETCH\_BYTES
============

+----------+-------------------------------------------------------------------+
| Syntax   | a$ = FETCH\_BYTES(#channel, how\_many)                            |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function  returns the requested  number of bytes from the given channel which must have been opened for INPUT or INPUT/OUTPUT.  It will work on CON\_ channels as well, but no cursor is shown and the characters typed in are not shown on the screen.  If there is an ENTER character, or a CHR$(10), it will not signal the end of input.  The function will not return until the appropriate number of bytes have been read.

WARNING - JM and AH ROMS will cause a 'Buffer overflow' error if more than 128 bytes are fetched, this is a fault with QDOS and not with DJToolkit. See the demos file, supplied with DJToolkit, for a workaround to this problem.

**EXAMPLE**

::

    LineOfBytes$ = FETCH_BYTES(#4, 256)


-------


