..  _ssave:

SSAVE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  SSAVE (scrno, xpos, ypos, xsiz, ysiz)                            |
+----------+-------------------------------------------------------------------+
| Location |  Ecran Manager                                                    |
+----------+-------------------------------------------------------------------+

The function SSAVE reserves memory and saves a part of the screen to
it, the saved block's left upper corner is the point (xpos,ypos) in
absolute co-ordinates, the width is xsiz and the height ysiz. xpos may
range from 0 to 511 and ypos from 0 to 255, so SSAVE
is not suitable for resolutions other than 512x256 pixels. The reserved
memory can only be released with SLOAD. The first parameter scrno can be
either 0 or 1 - it is used under dual screen mode to select the first or
second screen, scrno=1 is only available under dual screen mode, on
other machines SSAVE will break with the 'not found' (-7) error. The
value returned represents the address where the screen is stored in
memory.

**NOTE**

If you wish to link the Ecran Manager Toolkit to a QLiberated program,
you must not use the ECMAN but the ECMANcp version.

**CROSS-REFERENCE**

Saved pictures can be reloaded with :ref:`sshow`.

--------------


