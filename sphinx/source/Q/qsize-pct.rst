..  _qsize-pct:

QSIZE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  QSIZE% (#pipe\_ch)                                               |
+----------+-------------------------------------------------------------------+
| Location |  PIPES (DIY Toolkit - Vol P)                                      |
+----------+-------------------------------------------------------------------+

This function is designed to read the amount of characters which a pipe
linked to the specified channel can hold at any one time.

**Example**

::

    10 OPEN #4,pipe_200
    20 QLINK #4 TO #3
    25 PRINT #4,'QL DATA'
    30 PRINT QSIZE% (#3), QCOUNT%(#3)
    40 CLOSE #3: CLOSE #4

This short program will print 203 and 8 on screen.

This will also work with named pipes on SMS::

    10 OPEN_NEW #4,pipe_test_200
    20 OPEN_IN #3,pipe_test
    25 PRINT #4,'QL DATA'
    30 PRINT QSIZE% (#3), QCOUNT%(#3)
    40 CLOSE #3:CLOSE #4

Note however, that if you re-run the program the figure returned by
QCOUNT% continues increasing - this is because a named pipe does not
disappear just because both ends of the pipe have been closed. You would
need to add the line::

    50 DELETE pipe_test

to overcome this. Alternatively, try::

    DIR pipe: WDEL pipe

**NOTE**

A pipe can normally hold a few extra characters that the size originally
given to the pipe (in the example 203 is returned on most
implementations rather than 200 as might be expected). This does not
cause a problem.

**CROSS-REFERENCE**

Refer to :ref:`qlink` and also the Device Drivers
Appendix. See also :ref:`qcount-pct` and
:ref:`qspace-pct`.

--------------


