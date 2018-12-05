..  _draw:

DRAW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DRAW x1,y1 TO x2,y2 ,colour                                      |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

This command draws a line in absolute co-ordinates on the screen. Any
windows and window attributes are ignored. x1 and x2 range from 0 to
511, y1 and y2 from 0 to 255. DRAW uses the screen base address defined
with SCRBASE (which enables it to draw on a screen stored in memory as
well as the currently visible screen. It is therefore compatible with QL
emulators and Minerva's dual screen mode, although it cannot support
higher resolutions). The range for the colour parameter is 0..7, other
values give odd results without being dangerous.


**Example**

Here is a procedure which draws a line given in polar co-ordinates. A
point in a polar system is specified by a radius and angle.

::

    170 DEFine PROCedure POLAR_DRAW (r1,phi1,r2,phi2,col)
    180   REMark less precise but fast version
    190   LOCal r,phi,r_old,phi_old,dr,dphi
    200   LOCal x1,x2,y1,y2,dist
    210   r_old=r1: phi_old=phi1
    220   r=r1: phi=phi1
    230   x1=1.35*r_old*SIN(phi_old+PI/2)+255
    240   y1=r_old*COS(phi_old+PI/2)+127
    250   dist=(r1+r2)/2 * (phi1+phi2)/PI
    260   IF dist==0 THEN RETurn
    270   dr=(r2-r1)/dist: dphi=(phi2-phi1)/dist
    280   REPeat Drawing
    290     IF r>=r2 AND phi>=phi2 THEN EXIT Drawing
    300     r=r_old+dr: phi=phi_old+dphi
    310     x2=1.35*r*SIN(phi+PI/2)+255
    320     y2=r*COS(phi+PI/2)+127
    330     DRAW x1,y1 TO x2,y2 ,col
    340     r_old=r: phi_old=phi
    350     x1=x2: y1=y2
    360   END REPeat Drawing
    370 END DEFine POLAR_DRAW

::

    POLAR_DRAW 0,0 TO 100,8*PI ,7

draws an archimedic spiral and these few lines create a polar pattern::

    10 SCLR 0
    20 FOR a=0 TO 50 STEP 10
    30 POLAR_DRAW a,0 TO a,2*PI ,7
    40 POLAR_DRAW 0,PI*a/25 TO 50,PI*a/25, 7
    50 END FOR a
    60 REFRESH


**NOTE**

DRAW is specific to the resolution of 512x256 pixels. It can however be
used to draw on Minerva's second screen by using the command SCRBASE
SCREEN(#3) (assuming that #3 is open on the second screen).


**CROSS-REFERENCE**

:ref:`plot` plots a pixel,
:ref:`sclr` clears the screen and
:ref:`refresh` makes the screen pointed to by
:ref:`scrbase` visible. See also
:ref:`dotlin` and the other variant of
:ref:`draw`.

--------------


DRAW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DRAW [#ch,] x2,y2                                                |
+----------+-------------------------------------------------------------------+
| Location |  DRAW (DIY Toolkit - Vol G)                                       |
+----------+-------------------------------------------------------------------+

This command draws a line in absolute co-ordinates on the screen with
reference to the specified window channel (if any - default #1). The
line is drawn from the last point plotted with the PLOT
command from the same toolkit, to the point specified by x2,y2. This is
quicker than using the SuperBASIC LINE command and unlike other similar
commands, it will support the current INK
colour and OVER mode.

<CTRL><F5> will pause the line drawing and it
will even work in MODE 4, 8 and 12 (on the THOR XVI, provided that you
have v1.6+). The main limitation on this command is that the line must
appear fully within the specified window, so x2 and y2 cannot exceed the
width or height of the specified window (in pixels) nor be less than
zero.


**NOTE**

Although DRAW will work wherever the screen base is located, it assumes
that a line of pixels takes 128 bytes - it will not therefore currently
work on higher resolutions.


**CROSS-REFERENCE**

See the other variant of\ :ref:`draw`. See also
:ref:`plot`. :ref:`line` is much
more flexible.

--------------


