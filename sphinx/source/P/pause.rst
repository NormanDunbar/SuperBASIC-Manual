..  _pause:

PAUSE
=====

+----------+--------------------------------------------------------------------------------+
| Syntax   | PAUSE [timeout] or                                                             |
|          |                                                                                |
|          | PAUSE [#chan,] [timeout](Minerva v1.80+, THORv6.41, SMS, ST/QL E-init v1.27+)  |
+----------+--------------------------------------------------------------------------------+
| Location | QL ROM                                                                         |
+----------+--------------------------------------------------------------------------------+

The command PAUSE halts execution of a program temporarily for the
specified timeout number of frames (there are 50 frames per second in
the UK and Europe, 60 frames per second in the US). If no timeout or a
negative timeout is specified, the command will wait indefinitely. If a
timeout of zero is specified, no actual PAUSE will take place. Execution
will continue at the end of the timeout, or if a key is pressed. The key
is read from channel #0 and therefore the command will report the error
'channel not open' if #0 is not open.

The second variant of this command
allows you to specify a channel #chan (default #0) upon which the
command should operate, thus allowing the command to be used in programs
which do not have #0 open.

**Example**

::

    PAUSE 100

Pauses for approximately 2 seconds, unless a key is pressed in the
meantime!

**NOTE 1**

Using timeouts allows programs to run at the same speed on all QL
implementations.

**NOTE 2**

Normally, if #0 or the specified channel (in the THOR variant of this
command) is not a console window (or not open), an error will be
generated, of either 'Bad Parameter' or 'Channel not open' respectively.
However, the Minerva and SMS variants of this command do not report any
error messages and merely return straight away (although see next note).

**NOTE 3**

On Minerva (v1.90+), the second variant of this command will also work
on a screen (scr\_) channel.

**NOTE 4**

The second variant didn't really work on ST/QL Emulators until v1.30 of
E-Init).

**CROSS-REFERENCE**

:ref:`inkey-dlr` allows you to read the key which has
been pressed, as well as halting program execution.

--------------


