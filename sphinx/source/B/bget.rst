..  _bget:

BGET
====

+----------+---------------------------------------------------------------------------+
| Syntax   | BGET [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or|
|          |                                                                           |
|          | BGET [#ch,] [item                                                         |
+----------+---------------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                                      |
+----------+---------------------------------------------------------------------------+

This command is very similar to GET, although this only fetches one byte
at a time (in the range 0..255) from the given channel (default #3).

Each item to be fetched must therefore be either an integer or a
floating point variable, for example: BGET #3\\100,byte1%,keying

If the channel specified is not a file, then the command will wait for a
key to be pressed for each item, and then set the value of each item to
the character code of the key pressed.

As with GET, the items will be fetched from the current (or specified)
file position, which is taken to be an absolute distance from the start
of the file. If no item is specified, then the first variant can be used
to set the current file position. position will be updated (unless it is
an expression!) with the current file position at the end of the
command.


**Examples**

BGET #3\\100 Set file pointer on #3 to position 100.

BGET a% Read the byte at the current file pointer in channel #3.


**NOTE 1**

Current versions of the Turbo and Supercharge compilers are not able to
compile programs which use BGET.


**NOTE 2**

Characters which are read from a channel using BGET are affected by TRA.


**SMS NOTE**

BGET will accept a parameter which is a sub-string of a string array to
read in several bytes at once. For example:

DIM a$(10):a$=FILL$(' ',10):BGET #3,a$(4 to 7)

This will read 4 bytes from channel #3 into the middle of a$.

Please note that a$ cannot be an empty string if this is to work since
the sub-string would not be valid!!


**CROSS-REFERENCE**

See :ref:`bput`, :ref:`put`,
:ref:`get`. :ref:`fpos` allows you
to find out the current file position.
:ref:`truncate` allows you to truncate a file to
the current file position. :ref:`peek` fetches one
byte from memory.

:ref:`open-dir` contains an example of the use
of :ref:`bget`.

--------------


