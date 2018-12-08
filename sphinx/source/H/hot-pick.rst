..  _hot-pick:

HOT\_PICK
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_PICK (key$, JobName$)                                       |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The function HOT\_PICK is used to specify a hotkey to Pick a job of a
specified name whenever that key is pressed together with <ALT>. In
effect, whenever the hotkey is pressed, the specified program will be
brought to the top of the pile, allowing you to continue work on it. The
Job Name given need only be the first word contained in the name shown
when you use the JOBS command, therefore meaning that Job names can be
as descriptive as you like! If the specified Job is not present in
memory when you press the hotkey, a warning beep will be sounded.

**Example**

::

    ERT HOT_PICK('p','Perfection')

will set up a hotkey which will allow you to jump straight into
Perfection from any other program (provided that Perfection is in
memory), just by pressing <ALT><p>.

**NOTE**

HOT\_PICK up to v1.22 gave problems on the ST Emulators.

**CROSS-REFERENCE**

:ref:`exep`, :ref:`hot-load`,
:ref:`hot-chp` and
:ref:`hot-res` all allow you to alter the Job
Name of a program as it is loaded. Compare
:ref:`hot-wake`.

