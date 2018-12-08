..  _his-size:

HIS\_SIZE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_SIZE #channel, lines                                        |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

A history which has been already been installed with HIS\_SET has its
size specified and is activated (or de-activated) with HIS\_SIZE. The
different usages of the command are distinguished by the lines
parameter.

- Positive numbers for lines will activate a history for the
  given channel and tell it to store the next lines number of lines which
  are terminated by pressing <ENTER>. If a history had already been
  installed, then all stored lines are lost.

- Negative numbers will have exactly the same effect except that if a history was already active, the
  absolute value of the given lines number is added to the memory capacity
  of the existing history. Existing stored lines are retained in memory.

- Zero simply turns off a history and clears the tables which hold the entered lines.

History can store a maximum of 32767 lines which should
be more than sufficient. Memory is allocated dynamically, in four
kilobytes chunks, so there is a small danger of heap fragmentation.

**CROSS-REFERENCE**

See :ref:`his-set`.

