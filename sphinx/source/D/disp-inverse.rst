..  _disp-inverse:

DISP\_INVERSE
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_INVERSE status                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Atari ST & TT                                         |
+----------+-------------------------------------------------------------------+

The Atari range of computers support a high resolution (640x400)
monochrome display mode which can be supported under SMSQ/E and SMS2. If
SMSQ/E or SMS2 is running on an Atari ST connected to a monochrome
monitor (or running on an Atari TT conected to such a monitor, without
QVME), then it will automatically start up by loading the monochrome
display driver (if available) and set the QL into the monochrome 640x400
display mode. The QL screen can then appear either as white ink on a
black background or black ink on a white background. DISP\_INVERSE
allows you to invert the QL display, with status=0
giving the default white on black and status=1 the black on white
display.


**NOTE**

This command is not available on SMS2.


**CROSS-REFERENCE**

:ref:`disp-type` allows you to find out if the
monochrome display driver is running.
:ref:`inverse` allows you to print in inverse
colours.

--------------


