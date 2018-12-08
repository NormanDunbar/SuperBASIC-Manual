..  _force-type:

FORCE\_TYPE
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  FORCE\_TYPE string$                                              |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command forces the given string to be typed into the current
keyboard queue, just as if you had typed it from the keyboard. There is
not much use for this command in connection with applications because
key macros such as ALTKEY are much easier to use. But, FORCE\_TYPE can be used
to perform an
action without anyone actually needing to press a key.

**Example**

Your telephone rings and you talk half an hour with a friend.
Meanwhile your computer crashes - God only knows why - and the BASIC
program you were writing has now disappeared along with everything else.

You could decrease this danger by writing and compiling such a program::

	100 last_stroke = DATE
	110 REPeat Sleeping
	120   IF KEYROW(1) THEN last_stroke = DATE
	130   IF DATE-last_stroke > 300 THEN
	140     FORCE_TYPE "SAVE_O FLP1_Backup_bas" & CHR$(10)
	150     REPeat Wait: IF KEYROW(1) THEN EXIT Wait
	160     last_stroke=DATE
	170   END IF
	180 END REPeat Sleeping

This example should obviously be adapted to your specific needs, applications
and tools.

**NOTE 1**

Every console channel (ie. con\_ windows) has a keyboard queue - the
channel accessed by FORCE\_TYPE must first be activated by a dummy
INKEY$, PEND etc. to that channel.

**NOTE 2**

In earlier versions of Tinytoolkit (pre v1.10), this command was called
TYPE\_IN, which could cause problems with Turbo compiled programs.

**CROSS-REFERENCE**

:ref:`stamp` does exactly the same as
:ref:`force-type`.

