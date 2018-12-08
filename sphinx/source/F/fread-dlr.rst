..  _fread-dlr:

FREAD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FREAD$ ([#ch], length)                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The FREAD$ function is very similar to the FREAD command: A fixed
number of characters is read from a channel (default #0) and returned as
a string. FREAD$ does not stop with an error if the end of file is
reached - you have to detect this by testing if the length of the
returned string is really length.

**Example**

MYCOPY copies a file with flexible buffering up to 32k, eg. type::

    MYCOPY "mycopy_bas" TO "ram2_whatever_dat", 1000

to use a 1000 bytes buffer. The larger the buffer, the faster the
file is copied; try a one byte buffer to see the difference! Ok, here is
the listing::

    100 DEFine PROCedure MYCOPY (file1$, file2$, bufsiz%)
    110   LOCal ch1, ch2, buffer$
    120   ch1 = FOP_IN(file1$)
    130   ch2 = FOP_NEW(file2$)
    140   REPeat copying
    150     buffer$ = FREAD$(#ch1, bufsiz%)
    160     PRINT#ch2,buffer$;
    170     IF LEN(buffer$) < bufsiz% THEN EXIT copying
    180   END REPeat copying
    190   CLOSE #ch1, #ch2
    200 END DEFine MYCOPY

**CROSS-REFERENCE**

:ref:`input-dlr`,
:ref:`fwrite-dlr`, :ref:`copy`,
:ref:`get-byte-dlr`

