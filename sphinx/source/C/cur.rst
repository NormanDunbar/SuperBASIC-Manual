..  _cur:

CUR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CUR [#channel,] boolean                                          |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Every Window channel has a cursor which flashes when it is switched on
and appears solid when it is inactive.

The command CUR with boolean=1 activates the cursor of a window, and it
is de-activated with boolean=0. The default channel is #1.

**Example**

Multitasking programs should use INKEY$ to read keystrokes from the
keyboard if no other job is to be similarly affected by the keys
pressed. KEYROW could be used, but this does not care which
job/channel/window was active when a key was pressed (this could be used
to give a background job a command without leaving the current job).

The following function imitates the getchar() function of the C
language, and is used for non-interactive keyboard input. Arcade games
should not engage the cursor!

::

    100 DEFine FuNction GETCHAR% (channel,timeout)
    110  LOCal char$
    120  CUR#channel,1
    130  char$=INKEY$(#channel,timeout)
    140  CUR#channel,0
    150  RETurn CODE(char$)
    160 END DEFine GETCHAR%

**NOTE**

Although the cursor was activated, it will not flash until the channel
is made into the current keyboard input queue (ie. when it can use PEND,
EOF, INKEY$). This may therefore mean that the keys <CTRL><C> will need
to be pressed to make this program the active (current) task.

Non-console windows (scr\_) cannot be used for input operations (ie.
INPUT and INKEY$ cannot be used), nevertheless, the cursor may still be
enabled.

INPUT will activate and de-activate the cursor itself.

**CROSS-REFERENCE**

See :ref:`force-type` concerning current input
queue activation, :ref:`inkey-dlr`,
:ref:`input` and :ref:`keyrow`
for general information.

:ref:`cursen` and
:ref:`curdis` are both combined by the
:ref:`cur` command.
:ref:`cursor-pct`.

--------------


