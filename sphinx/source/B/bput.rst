..  _bput:

BPUT
====

+----------+---------------------------------------------------------------------------+
| Syntax   | BPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or|
|          |                                                                           |
|          | BPUT [#ch,] [item                                                         |
+----------+---------------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                                      |
+----------+---------------------------------------------------------------------------+

This command is the complement to BGET, in that it places the byte value
for each item into the specified channel (default #3) at the current
file position (or the specified position if the first variant is used).

If the value of item is outside the range 0...255, an overflow error
will result, whereas if item is not an integer or floating point number,
then an error in expression will result. On the other hand, if a
non-integer floating point is given as an item, then the value will be
rounded to the nearest integer and this placed into the given channel.

Provided that the second variant of this command is used, the specified
channel need not be open to a file, in which case each item is taken as
being a character, for example: BPUT #2,72,101,108,108,111

will print the word Hello in channel #2. This can of course be used to
send control codes to a printer much more easily than the PRINT command.

For example:

BPUT #3,27,70

is a lot easier to understand than:

PRINT #3,CHR$(27)&'F'

to switch off emphasised mode.

As with BGET, if no item is specified, then the first variant can be
used to set the current file position. position will also be updated at
the end of the command to contain the current file pointer.


**Example**

BPUT #ch,4.5,'100',52,a+1

places the values 5,100,52 and (a+1) at the current file position.


**NOTE**

The codes sent by BPUT are affected by any translate that is active (see
TRA).


**SMS NOTE**

BPUT will now accept string parameters to allow you to pass several
bytes at a time, for example: a$='Hello':BPUT #3,a$

is equivalent to: BPUT #2,72,101,108,108,111


**CROSS-REFERENCE**

See :ref:`fgetb`, :ref:`bput`,
:ref:`put`, :ref:`get`,
:ref:`lput`, :ref:`uput` and
:ref:`wput`.

:ref:`fpos` allows you to find the current file
position.

:ref:`truncate` allows you to truncate a file to
the current file position.

:ref:`peek` fetches one byte from memory.

:ref:`uput` allows you to send bytes without them
being translated.

