..  _file-open:

FILE\_OPEN
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_OPEN ([#ch,] device [,{mode% \| ChID}])                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FILE\_OPEN is a function which will open any device (default data
directory supported for files) for all kinds of tasks. If a channel
number #ch is not supplied, FILE\_OPEN will choose the channel number on
its own by searching for the next free channel number and returning it.

FILE\_OPEN returns the channel number if it was not specified or
otherwise zero. In case of failure it will return a (negative) error
code. If error -4 ('out of range') is returned when a channel number has
not been supplied, this indicates that the channel table of a compiled
job is full.

The third parameter can be either the open mode or the
channel ID of an un-named pipe.

The open mode (default 0) is:

- 0 (old exclusive) - open an existing file to read and write.
- 1 (old shared) - open an existing file to read only.
- 2 (new exclusive) - create a new file if it does not exist.
- 3 (new overwrite) - create a new file, whether or not it exists.
- 4 (dir open) - open a directory to read only.

If the third parameter is the channel ID of an open input pipe, then FILE\_OPEN will
create an output pipe linked to that channel.

**Example**

Count additional keywords::

    100 ch1=FILE_OPEN(pipe_10000)
    110 ch2=FILE_OPEN(pipe_,CHANID(#ch1))
    120 EXTRAS#ch1
    130 FOR count=1 TO 1E6
    140   IF IO_PEND%(#ch2) THEN EXIT
    150   INPUT#ch2,keyword$
    160   AT 0,0: PRINT count
    170 END FOR count
    180 CLOSE#ch1,#ch2

**CROSS-REFERENCE**

:ref:`file-open` combines
:ref:`open`, :ref:`open-in`,
:ref:`open-new`,
:ref:`open-over`,
:ref:`open-dir`,
:ref:`fopen`, :ref:`fop-in`,
:ref:`fop-over`,
:ref:`fop-new`,
:ref:`fop-dir`,
:ref:`tteopen` and
:ref:`tconnect`. See also
:ref:`chanid` and :ref:`ernum`.

