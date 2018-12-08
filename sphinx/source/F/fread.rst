..  _fread:

FREAD
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FREAD (#ch,address,bytes)                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

The function FREAD reads a number of bytes (bytes) from a given
channel into memory, starting at address. The number returned by FREAD
gives the number of bytes it actually read.

**Example**

A BASIC Procedure APPEND which adds a file (file1$) to the end of a
target file (file2$). If the target file does not exist, it will be
created.

The first file will be erased (remove line 220 if you do not
want this). The third parameter allows you to determine the working
space of the procedure; the larger this space, the quicker the
execution::

    100 DEFine PROCedure APPEND (file1$,file2$,bufsize)
    110   LOCal length,buffer,file1,file2,part
    120   file1=FOP_IN(file1$): length=FLEN(#file1)
    130   buffer=ALCHP(length)
    140   file2=FOPEN(file2$)
    150   IF file2=-7 THEN file2=FOP_NEW(file2$)
    160   GET #file2 \1E9
    170   FOR part=0 TO INT(length/bufsize)
    180     bufsize=FREAD(#file1,buffer,bufsize)
    190     FWRITE #file2,buffer,bufsize
    200   END FOR part
    210   CLOSE #file1, #file2: RECHP buffer
    220   DELETE file1$
    230 END DEFine APPEND

It can be called as follows::

    APPEND "ram1_tumb_tmp" TO "flp2_tump_dat",20480

**NOTE**

If the channel number supplied to FREAD does not refer to a file, then
the error -15 (bad parameter) will be reported after it has done its
work. This behaviour is pretty strange.

**CROSS-REFERENCE**

:ref:`fread-dlr`, :ref:`fwrite`,
:ref:`lbytes`, :ref:`sbytes`,
:ref:`get`, :ref:`put`.

