..  _bat-use:

BAT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  BAT\_USE batch$                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command is used to specify a command string containing SuperBASIC
keywords which will be typed into the command line (#0) when the command
BAT is issued. The string may be up to 128 characters long. You may add
CHR$(10) to the end of the string in order to emulate an <ENTER>
keypress (as in the example below).


**Example**

BAT\_USE "PAPER 3: INK 7: PAPER#2,3: PAPER#2,3: INK#2,7: WMON 4: BORDER
1,0: BORDER#2,0" & CHR$(10)

The command BAT will now reset the standard start-up windows.


**CROSS-REFERENCE**

:ref:`bat` executes the batch string set with
:ref:`bat-use`.

See
:ref:`force-type`,\ :ref:`stamp`
and :ref:`type-in` also.

:ref:`do` allows batch files of any size to be
executed.

--------------


