..  _inkey-dlr:

INKEY$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  INKEY$ ( [#chan,][timeout] )                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function fetches a single character from the specified channel
(default #0). If a timeout is specified, INKEY$ will wait for timeout
frames (there are 50 frames per second in the UK, 60 frames per second
in most other countries). If a character is read, the function will
return straight away, otherwise, it will wait for the specified number
of frames and then return. Timeout can be in the range -32768..32767. If
a negative timeout is specified, INKEY$ will wait forever until a
character is read from the specified channel. The default of timeout is
0 which means return immediately. A timeout is therefore not really
necessary if INKEY$ is being used to access a channel opened to a file,
as the data will either be there or not! If #chan is not an input
channel (eg. scr\_), error -15 (bad parameter) will be reported.

**NOTE 1**

Using timeouts allows programs to run at the same speed on all QL
compatibles.

**NOTE 2**

It may be useful to clear the input buffer before trying to read a
character from the keyboard (this prevents overrun on keys) - you can do
this by using something along the lines of::

    100 dummy=KEYROW(0)
    110 key$=INKEY$(-1)

**CROSS-REFERENCE**

:ref:`inkey-dlr` is channel based, which means that it
can be used safely in multi-tasking programs.
:ref:`keyrow` will read the keyboard even though
the current Job is not the one executing the
:ref:`keyrow` command (although see the options
available with :ref:`exep`).
:ref:`input` allows you to read a string of
characters in one go. :ref:`pause` halts program
execution temporarily.

