..  _break-off:

BREAK\_OFF
==========

+----------+--------------+
| Syntax   | BREAK\_ON    |
|          |              |
|          | BREAK\_OFF   |
+----------+--------------+
| Location | TinyToolkit  |
+----------+--------------+

The command BREAK\_OFF de-activates the functioning of both
<CTRL><SPACE> (the Break Key) and <CTRL><F5> (the Pause Screen key)
during the running of interpreted SuperBASIC programs so that they
cannot be stopped by the user unless they stop either due to an error or
a STOP command.

The command BREAK\_ON reactivates both keys.

The function BREAK returns the current status:

IF BREAK=1 means the Break Key is active, while

IF BREAK=0 means that it is inactive.


**NOTE 1**

BREAK\_OFF may not work on Minerva ROMs unless you have v1.10 or later
of the Toolkit, which uses the new Minerva System Xtensions to overcome
any problem.


**NOTE 2**

BREAK\_OFF does not currently work with SMS.


**CROSS-REFERENCE**

:ref:`stop` terminates interpreted programs even if
the Break Key is disabled. Do not confuse with the command
:ref:`break`.

