..  _xchange:

XCHANGE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  XCHANGE (a1 TO a2, c1 TO c2)                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function XCHANGE replaces all occurrences of byte c1 by c2
from memory locations a1 to a2 inclusive. The function counts the
exchanged bytes and returns the sum.

**Example**

Provided that you have enough free memory, this small program replaces
line-feed characters CHR$(10) by carriage returns CHR$(13) in
ram1\_test\_txt as quickly as possible::

    100 ch=FILE_OPEN("ram1_test_txt",0)
    110 IF ch<0 THEN REPORT ch: STOP
    120 length=FLEN(#3)
    130 memory=ALCHP(length)
    140 IF NOT memory THEN REPORT -3: STOP
    150 x=LOAD_FILE(#ch,memory,length)
    160 IF XCHANGE(memory,memory+length-1,13,10) THEN
    170   GET#ch\0
    180   SAVE_FILE#ch,memory,x
    190   TRUNCATE#ch
    200 END IF
    210 CLOSE#ch: RECHP memory

**CROSS-REFERENCE**

:ref:`search`, :ref:`copy-b`,
:ref:`copy-w`, :ref:`copy-l`

