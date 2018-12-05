..  _dline:

DLINE
=====

+----------+------------------------------------------------------------------------+
| Syntax   | DLINE [#ch,] [range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*`](Not SMS) |
|          |                                                                        |
|          | DLINE [range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*`](SMS Only)       |
+----------+------------------------------------------------------------------------+
| Location | QL ROM                                                                 |
+----------+------------------------------------------------------------------------+

This command deletes a given range of lines from the current SuperBASIC
program. The range of lines is as per the LIST command. If an empty
range (for example DLINE) is specified, no action is taken. When the
lines have been deleted, except under SMS, the current listed lines are
re-shown in the given channel (default #2), although we cannot see any
reason why you would wish this to happen on another channel! On SMS this
command has no effect on the display.


**NOTE 1**

DLINE TO is expanded to DLINE 1 TO 32767.


**NOTE 2**

Only Minerva v1.96+ rejects invalid channel parameters.


**NOTE 3**

On Minerva pre v1.98, DLINE to the last line could crash the QL!


**CROSS-REFERENCE**

:ref:`edit` and :ref:`auto` allow
you to enter lines. :ref:`list` allows you to view
program lines.

--------------


