..  _clock:

CLOCK
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLOCK [#channel] [,format$]                                      |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The command CLOCK creates a multitasking digital clock job named Clock.
If no channel parameter is stated, CLOCK will open its own window
(con\_60x20a448x206), which is intended for F1-monitor mode (see WMON),
otherwise the given channel will be used.

Format$ is optional and is used to define how the clock will appear on
screen. It can contain any text you desire (except for the characters %
or $), but there are certain special characters (see below) which allow
you to alter the way in which the clock is presented; so CLOCK "TEA AT
4" might remind you when tea time is, but will have no effect on the
display of the clock.

The format is defined by using certain set series of strings. The
following special characters will affect the way in which the clock is
displayed (the default format string is "$d %d $m %h:%m:%s" which is
ideal) :

-  %d Day of month - 2 digits
-  $d Day of week - 3 characters
-  %h Hour (24h) - 2 digits
-  $m Month - 3 characters
-  %m Minute - 2 digits
-  %s Seconds - 2 digits
-  %y Year - 2 digits (last two digits)
-  %c Century - 2 digits (see note 4 below)

A newline can be inserted by either padding out the string with spaces
or by adding CHR$(10) inside the string.

**Example**

CLOCK #2,'Date: %d $m %y' & chr$(10) & 'Time: $d %h:%m'

**NOTE 1**

There is no difference between upper case and lower case letters, so %d
has the same effect as %D. However, do watch the difference between $m
and %m!

**NOTE 2**

Any attempt to open a clock in channel #0 will be ignored and the
default window opened.

**NOTE 3**

Unfortunately for Pointer Environment users, there is no way of
'unlocking' the clock so that it can operate alongside other Jobs. On
the THOR XVI this is alleviated by ensuring that the Job is always owned
by Job 0.

**NOTE 4**

v2.25+ of Toolkit II introduced a further special character for use in
the format string. This is %c, which returns the first two digits of the
year, for example %c%y will print the current year as four digits.

**NOTE 5**

On v6.41 of the THOR XVI, if CLOCK has to open its own window, this
window is in fact owned by SuperBASIC rather than the CLOCK task. This
means that if CLOCK is removed other than by using NO\_CLOCK, (eg. with
RJOB) the channel can be left open.

**CROSS-REFERENCE**

Use :ref:`sdate` or :ref:`adate`
to set the system date and time.

:ref:`date-dlr` and :ref:`date`
return the current time.

:ref:`no-clock` removes the
:ref:`clock` on the THOR.

