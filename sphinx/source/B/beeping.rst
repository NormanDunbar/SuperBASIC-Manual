..  _beeping:

BEEPING
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  BEEPING                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This is a simple function which returns either 1 (true) if any sound
output from BEEP is still running or 0 (false) if not.


**Example**

BEEPING is rather useless in a formulation like: IF BEEPING THEN BEEP

because this is less efficient than BEEP on its own which has the same
effect. However, where you want to ensure that your program generates
the chosen sound, because of the QL's multi-tasking abilities, it may be
useful to use this function in case another program is executing a BEEP
command when you want to - you could then either wait or simply override
that sound by using BEEP followed by your own sound generating BEEP
command. For example:

::

    10 REPeat check_beep: IF NOT BEEPING THEN EXIT check_beep
    20 BEEP 100,20


**NOTE**

This function did not work correctly on Minerva before v1.98.


**CROSS-REFERENCE**

:ref:`beep` activates the speaker.

--------------


