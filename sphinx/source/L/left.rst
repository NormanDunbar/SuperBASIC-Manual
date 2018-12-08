..  _left:

LEFT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LEFT [ #channel ]                                                |
+----------+-------------------------------------------------------------------+
| Location |  QSOUND                                                           |
+----------+-------------------------------------------------------------------+

This command will move the text cursor left one column in the specified
channel (default #1). If there is a pending newline on the specified
channel (for example after a PRINT
command) this will be cleared, making it as if the last PRINT
(or INPUT) statement ended with a comma - for example::

    100 PRINT 'Hello World'
    110 PRINT 'THIS LINE IS PRINTED AFTER A PENDING NEWLINE'
    120 LEFT
    130 PRINT 'THIS OVERWRITES PART OF THE LAST TEXT'

'Out of Range' will be reported if you try to move the cursor left past
column zero.

**CROSS-REFERENCE**

:ref:`at` allows you to position the text cursor.
:ref:`print`, :ref:`to`,
:ref:`input` and :ref:`cursor`
also affect the text cursor.

