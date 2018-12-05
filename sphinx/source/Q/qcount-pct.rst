..  _qcount-pct:

QCOUNT%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  QCOUNT% (#pipe\_ch)                                              |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This function is designed to make the use of pipes easier. Provided
that the specified channel is linked to a pipe (normally the input end
of the pipe), this function will return the number of characters which
are waiting to be read from the pipe.

**NOTE**

The value returned will be the exact number of characters placed into
the pipe, which will therefore include the line feed characters and
other control characters. Take the example of::

    10 OPEN #3,pipe_1048
    20 PRINT #3,'HELLO'
    30 PRINT QCOUNT%(#3)

The value of 6 is returned, this is because the PRINT
statement has added a line feed to the end of the word 'HELLO', so that
this can be read by an INPUT command.

**CROSS-REFERENCE**

Refer to :ref:`qlink` and also the Device Drivers
Appendix. See also :ref:`qsize-pct` and
:ref:`qspace-pct`.

--------------


