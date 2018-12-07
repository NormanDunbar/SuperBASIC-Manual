..  _queue-pct:

QUEUE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QUEUE% (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  QBASE (DIY Toolkit Vol Q)                                        |
+----------+-------------------------------------------------------------------+

QUEUE% is a function but does exactly the same as FORCE\_TYPE and
TYPE\_IN.

The return value is zero if all bytes have been successfully
typed in, negative if the keyboard queue is full and positive if another
problem occurred.

The absolute value of the return always indicates how
many characters QUEUE% failed to send.

