..  _altkey:

ALTKEY
======

+----------+------------------------------------------------------------------+
| Syntax   | ALTKEY character$,string$ [,string2$ [,string2$... ]]  or        |
|          |                                                                  |
|          | ALTKEY character$  or                                            |
|          |                                                                  |
|          | ALTKEY                                                           |
+----------+------------------------------------------------------------------+
| Location |  Toolkit II                                                      |
+----------+------------------------------------------------------------------+

This command defines a key macro which will be typed into the computer
when you press the <ALT> key at the same time as the <character$> key.
If more than one string follows the definition, then an <ENTER> (line
feed) character is inserted between each string.

ALTKEY without any parameters deletes all previously defined ALTKEYs,
whereas ALTKEY character$ will just kill the specified definition
(whether there was one or not).

A line feed will not be appended to the final string unless you add a
nul string to the definition.

**Example 1**

ALTKEY " ","RUN","" types in RUN <ENTER> if <ALT><SPACE> is pressed.

ALTKEY"a","flp1\_" types in flp1\_ when <ALT><A> is pressed.

ALTKEY removes all ALTKEY definitions.

ALTKEY "a" remove definition for <ALT><A>.

ALTKEY 1,"1000" same as ALTKEY "1","1000"

**Example 2**

There are many programs which do not support the Toolkit II default
device names and sub-directories.

To avoid having to enter FLP1\_Archive\_Adresses\_ in front of every
file name, one could compile the following line, then EXECute the
resultant program (using EX or EXEC) with the priority set to 1.

::

    100 PRIO 1
    110 REPeat Always
    120   ALTKEY "p",DATAD$
    130   ALTKEY "P",PROGD$
    140 END REPeat Always

You can replace PRIO by QP QMYJOB,1 with QLiberator or PRIORITY 1 with
Turbo, or SPJOB -1,1 with Toolkit II

**NOTE 1**

If character$ is an upper case letter, then you will need to press
<ALT><SHIFT> and the <key> (or <ALT><key> in CAPSLOCK) to call the
macro.

**NOTE 2**

The combination <ALT><ENTER> is always set aside for the last line
recall (ie. when these two keys are pressed all characters typed
inbetween the last two <ENTER>s are put into the keyboard buffer again).

**NOTE 3**

The Hotkey System is usually configured to type in the Hotkey Stuffer
contents if <ALT><SPACE> is pressed.

<ALT> <SHIFT> <SPACE> gets previous Stuffers.

**WARNING**

If you have Hotkey System II loaded, then ALTKEY will not have any
effect until you use the HOT\_GO command.

**CROSS-REFERENCE**

:ref:`force-type` and
:ref:`stamp` allow programs to access the keyboard,
:ref:`key` defines macros on function keys.

--------------


