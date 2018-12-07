..  _pick-pct:

PICK%
=====

+----------+------------------------------------------------------------------+
| Syntax   | PICK% [(JobID] or                                                |
|          |                                                                  |
|          | PICK% (JobID, action)                                            |
+----------+------------------------------------------------------------------+
| Location | PEX                                                              |
+----------+------------------------------------------------------------------+

This function can be used to perform various acts.

The first syntax is
the more common and will bring the specified Job (by reference to its
QDOS Job id or its Job Number as specified by JOBS) to the top of the
pile under the Pointer Environment, making all of its windows appear on
screen as if it had been Picked from the Qpac 2 file menu.

If JobID is
-1 or omitted, then the Job which contains this command, ie the current job,
is brought to the top of the pile. This variant is therefore similar to TOP\_WINDOW.

If JobID is -2, then the next Job in the Job Table (see NXJOB) is
brought to the top of the pile - this is therefore similar to pressing
<CTRL><C>.

The second variant is more complex and depends upon the
values of JobID and action.

#. If JobID refers to an existing Job and action is -4, then the screen is frozen - this is equivalent to pressing <CTRL><F5>.

#. If JobID equals -3 and action is an existing QDOS channel number (see CHANNELS) or SuperBASIC channel number then that particular channel is unfrozen, allowing input from / output to that channel provided that the Job which owns that channel is at the top of the pile or can use background screen access under PEX.

#. If JobID equals -4 and action is an existing QDOS channel number (see CHANNELS) or SuperBASIC channel number then that particular channel is frozen again and any attempt by a program to access that channel will (unless that program is not buried) cause that program to halt temporarily.

The  values returned by PICK% are normally zero if the function is
successful. Otherwise errors are returned as follows:

- -1 : Job is In Use (although we are not certain when this will be reported).
- -2 : Job does not exist.
- -6 : Specified QDOS channel number does not exist.

**CROSS-REFERENCE**

:ref:`ojob` and :ref:`nxjob`
allow you to find out details about a specified Job.
:ref:`peon` allows background screen access.

