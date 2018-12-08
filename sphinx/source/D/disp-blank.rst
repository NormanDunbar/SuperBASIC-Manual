..  _disp-blank:

DISP\_BLANK
===========

+----------+--------------------------------------------+
| Syntax   | DISP\_BLANK [xblank][,yblank]              |
+----------+--------------------------------------------+
| Location | QVME (Level E-19 Drivers onwards),         |
|          | SMSQ/E for Atari ST & TT (QVME cards only) |
+----------+--------------------------------------------+

The Atari range of computers can be attached to a wide range of
monitors, some of which are able to display higher resolutions than
others. A 17" multi-sync monitor, for example, can display resolutions
of up to 1024x1024 (depending on make).

The QVME card is unable to
detect the various parameters related to monitors and therefore allows
you to set your own parameters either from SuperBASIC or by configuring
SMSQ/E.

This command is used for setting the margins between the
currently displayed QL screen and the edges of the monitor. This
difference is known as the overscan (pixels available on the monitor
which are currently unused). xblank sets the number of horizontal pixels
x2 from the edge of the monitor to the left hand side of the QL screen.

The standard value for a 512x256 screen is 128 pixels (a standard QL
monitor linked to an Atari can display a screen 640x480) (640-512)/2=64
pixels from the left hand side of the monitor.

If xblank is omitted or 0, then the original value is left unaltered.

Yblank sets the number of lines x 0.5 from the top of the monitor to the top edge of the QL
screen. The standard value is 56, which gives a top margin of
(480-256)/2=112 pixels from the top of the screen. If yblank is omitted
or 0, then the original value is left unaltered.


**NOTE 1**

If you use DISP\_SIZE to alter the size of the displayed QL screen, it
will automatically adjust the parameters for the overscan.


**NOTE 2**

If the y parameter is used to alter the number of blank lines, this will
override any setting of the line scan rate with DISP\_RATE.


**CROSS-REFERENCE**

:ref:`disp-size` allows you to pass these
parameters at the same time as amending the size of the displayed QL
screen. :ref:`disp-rate` sets the frame and
line scan rates for the display - if this command is used to adjust the
line scan rate, this will alter the totoal number of lines.

Both SMSQ/E
and QVME include programs to allow you to try out the various settings
for the various DISP\_... commands.

