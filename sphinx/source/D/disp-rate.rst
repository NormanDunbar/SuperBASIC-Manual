..  _disp-rate:

DISP\_RATE
==========

+----------+--------------------------------------------+
| Syntax   | DISP\_RATE [frame\_scan][,line\_scan]      |
+----------+--------------------------------------------+
| Location | QVME (Level E-19 Drivers onwards),         |
|          | SMSQ/E for Atari ST & TT (QVME cards only) |
+----------+--------------------------------------------+

Due to the multitude of monitors which are available for the Atari ST
range, it is necessary to be able to alter the horizontal and vertical
scan rates (default = 50Hz, the setting on standard QL monitors).

The
first parameter specifies the frame rate (the horizontal scan rate), a
setting of 70 (or more) will reduce flicker on most Atari monitors. If
omitted or 0, the original value is unchanged.

The second parameter
specifies the line rate (the vertical scan rate), although this is
normally not required as it is equal to the frame rate multiplied by the
total number of lines. If this parameter is omitted or zero, the
original is recalculated by reference to the number of lines and the
frame rate.

The total number of lines and line rate can be calculated by
reference to the following program::

    100 INPUT #0,'Enter y size of QL screen (DISP_SIZE) ';QLy
    110 INPUT #0,'Enter horizontal frame rate (DISP_RATE) ';Frate
    120 INPUT #0,'Enter vertical blank pixels setting (DISP_BLANK) ';Blanky
    130 Total_y=QLy+Blanky
    140 total_lines=Total_y*(Qly/QLy)
    150 PRINT 'The total number of displayed lines will be ';total_lines
    160 PRINT 'Line scan rate will be ';total_lines*Frate

If you use DISP\_RATE to set the line scan rate, then using the total
number of lines (and hence the blank lines) are recalculated, using the
following routine::

    100 INPUT #0,'Enter y size of QL screen (DISP_SIZE) ';QLy
    110 INPUT #0,'Enter horizontal frame rate (DISP_RATE) ';Frate
    120 INPUT #0,'Enter vertical line scan rate (DISP_RATE) ';Lrate
    130 Total_y=INT(Lrate/Frate)
    140 PRINT 'Blank Lines for DISP_BLANK will be ';Total_y-QLy


**CROSS-REFERENCE**

:ref:`disp-size` allows you to pass these
parameters at the same time as amending the size of the displayed QL
screen. :ref:`disp-blank` sets the number of
horizontal and vertical blank pixels on the edge of the display.

Both
SMSQ/E and QVME include programs to allow you to try out the various
settings for the DISP\_... commands.

