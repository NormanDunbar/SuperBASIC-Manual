..  _a14-coercion:

A14 Coercion
============

The QL can coerce strings to transform them into numbers.

Unfortunately, the QL uses different rules on different ROMs and even
different rules according to whether you are comparing two strings or
whether you are assigning a value.

The following results have been obtained when testing a JM ROM and
Minerva v1.93-v1.97::

    PRINT '1'='1.':    REMark returns 1
    PRINT '.'='0':     REMark returns 0
    PRINT '.0'='0':    REMark returns 1
    PRINT '1'=' 1':    REMark returns 0
    PRINT '1'='1 ':    REMark returns 0
    PRINT '.0'(1)='.': REMark returns 1

    x='1.':   REMark is equivalent to x=1
    x='.':    REMark gives 'error in expression'
    x=' 1':   REMark is equivalent to x=1
    x='.0':   REMark is equivalent to x=0
    x='1 ':   REMark is equivalent to x=1

On SMSQ/E, the same results are obtained except that::

    PRINT '1'='1.': REMark returns 0
    PRINT '.0'='0': REMark returns 0

**NOTE**

x='.' is accepted on AH ROMs - becomes x=0
