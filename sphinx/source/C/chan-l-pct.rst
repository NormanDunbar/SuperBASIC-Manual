..  _chan-l-pct:

CHAN\_L%
========

+----------+------------------------------------------------------------------+
| Syntax   | CHAN\_B% (#ch, offset) and                                       |
|          |                                                                  |
|          | CHAN\_W% (#ch, offset) and                                       |
|          |                                                                  |
|          | CHAN\_L                                                          |
+----------+------------------------------------------------------------------+
| Location | CHANS (DIY Toolkit - Vol C)                                      |
+----------+------------------------------------------------------------------+

These three functions can be used to look at values within the channel
definition block relating to the specified channel (#ch). You will need
a good book on the QL's operating system to understand the various
offsets, such as the QDOS/SMS Reference Manual (See section 18.7 to
18.9.3 in that book).

They allow you to read single bytes, words and longwords from the
channel definition block (what is required depends upon the offset).

Extra offsets (negative numbers) are added by the Pointer Environment
which can also be looked at by using these functions.

**Examples**

Instead of using SCR\_BASE, you can use:

PRINT CHAN\_L (#1,50)

to find the base address of the screen.

::

    100 PRINT 'Window #1's size is';
    110 PRINT CHAN_W% (#1,28);'x'; CHAN_W% (#1,30);'a'; CHAN_W% (#1,24);'x'; CHAN_W% (#1,26)

**CROSS-REFERENCE**

:ref:`chbase` can be used to find out similar
information.

--------------


