..  _disp-size:

DISP\_SIZE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_SIZE                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QVME (Level E-19 Drivers onwards), SMSQ/E                        |
+----------+-------------------------------------------------------------------+

This command lets you alter the size of the QL screen being displayed.

The first two parameters allow you to specify the display width in
pixels and the height in lines (the normal QL display is DISP\_SIZE
512,256). The remaining four parameters are those which can be set using
the DISP\_RATE and DISP\_BLANK commands respectively. The effect of the
first two parameters depends upon the system it is being used on:

**Extended Mode4 Emulator**

Any width up to 512 will select the standard QL resolution. Any width
over 512 will select the extended resolution (768x280).

**QVME, QXL and QPC**

The width and height of the display can only be altered in increments of
32 pixels and 8 lines respectively. If width is not a multiple of 32 or
height is not a multiple of 8, they are made into the nearest feasible
size. The minimum size is 512x256 pixels.

**Q68**

Not implemented

**NOTE 1**

If you try to use DISP\_SIZE to specify both the line rate and the
number of blank lines, the line rate is ignored and calculated according
to the internal formula (see DISP\_RATE).


**NOTE 2**

DISP\_SIZE will not work if you have already used the A\_OLDSCR
command.


**NOTE 3**

Some combinations of Super Gold Card and AURORA may cause the internal
QL clock to run too quickly unless you follow DISP\_SIZE by PROT\_DATE 0.


**NOTE 4**

This command has no effect if your implementation of the QL does not
support higher resolution displays.


**NOTE 5**

Using higher resolution displays will affect the location of the start
of the screen (see SCR\_BASE) - using DISP\_SIZE 512,256 to set the
display size back to the normal QL resolution will not set the base of
the screen back to 131072 (the normal screen base on a standard QL). See
A\_OLDSCR.


**NOTE 6**

Be careful when reducing screen resolution size - windows are not
resized and therefore you may not be able to see all of a program's
windows, or the SuperBASIC cursor!!


**CROSS-REFERENCE**

All of these parameters can be configured in SMSQ/E so that they are
available immediately on start-up. See
:ref:`disp-rate` and
:ref:`disp-blank`.

