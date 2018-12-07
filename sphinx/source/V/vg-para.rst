..  _vg-para:

VG\_PARA
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_PARA col, xsize, ysize, angle, qlibm, italic, bold           |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

The use of the command VG\_PARA is easier than the large parameter list
may suggest. VG\_PARA specifies how text should look when printed with
VG\_PRINT. The colour col does not allow strips and textures, col may
only range from 0 to 7, other values are modulated appropriately. xsize
and ysize determine the size of the font (not in pixels!), they can be
freely chosen from any non-negative values, but sizes smaller than three
are usually not readable.

Angle is the angle (0..359º) by which the text
should be rotated. This is different from italics because the angle
parameter rotates the text around the origin point of the text whilst
italics slopes each character. The effect of italics is not linear,
values between -10 and 10 give all kinds of slope; negative italics
slope to the left and positive to the right.

The effect of bold on the
other hand is easily described: bold refers to the thickness of the
characters' lines which are bold+1 pixels.

Qlibm is a switch: any
non-negative value will make VG\_PRINT
try to find the character which matches best to the one given in the
text to be printed; this works for IBM fonts only, see VG\_PRINT for
further explanation of this point. The default setting is VG\_PARA
7,8,8,0,0,0,0 ie. white colour, 8x8 size, no italics, bold, rotation or
conversion.

**Examples**

Both examples assume a BGI font loaded to font number 0 and the default
VG\_WIND settings (VG\_WIND 0,511,0,255). The screen should be emptied
with::

    WIPE

or::

    WINDOW 512,256,0,0: CLS

::

    100 FOR size=1 TO 25
    110   bold = (size=25)
    120   VG_PARA 5.5*size/25,size,size,0,0,-3,bold
    130   VG_PRINT 70-2*size,150-size,0,"Sinclair QL"
    140 END FOR size

::

    100 FOR angle=0 TO 3000 STEP 12
    110   xsize=4*SIN(RAD(angle))+8
    120   VG_PARA 7,xsize,10,angle,0,0,0
    130   VG_PRINT 200,120,0,"Yippie"
    140   VG_PARA RND(0 TO 2),xsize,10,angle,0,0,0
    150   VG_PRINT 200,120,0,"Yippie"
    160 END FOR angle

**WARNING**

A negative bold parameter will cause VG\_PRINT to fall into an infinite
loop. This hangs the job which called VG\_PRINT
indefinitely.

**NOTE**

Negative sizes lead to strange output but do no harm. BGI fonts come in
different sizes so that the size settings of VG\_PARA do not necessarily
reflect the actual size that text will be; check with VG\_HOCH for every
font.

**CROSS-REFERENCE**

:ref:`vg-hoch` is a function which returns the
text sizes.

