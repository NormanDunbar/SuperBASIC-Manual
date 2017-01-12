
==========
Keywords V
==========



..  _va:

VA
==

+----------+-------------------------------------------------------------------+
| Syntax   |  VA (i,n)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function VA returns the value of (1+i)\ :sup:`-n` = 1/MT(i,n) where i
and n can be any floating point numbers (see MT for error handling).

**Example**

VA allows you to find out about base capital which will grow to a
certain higher (i>0) capital at the interest rate i
over n periods. Assume that you want to buy an expensive car for $80000
in two years and your investment returns an annual gain of 10% (not
bad), then you need to invest 80000 \* VA(1/10, 2) = 66115.7

**CROSS-REFERENCE**

You can check the result of the above example with: 66115.7 \* :ref:`mt`\ (1/10,2) = 80000.
 
See also :ref:`vfr`, :ref:`var`,
:ref:`tca`, :ref:`tnc`,
:ref:`tee`, :ref:`rae`,
:ref:`rafe`.

--------------


..  _var:

VAR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  VAR (i,n)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function VAR returns the value of: ((1+i)\ :sup:`n`-1) / (i\*
(1+i)\ :sup:`n`) where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`vfr`, :ref:`tca`,
:ref:`tnc`, :ref:`tee`,
:ref:`rae`, :ref:`rafe`

--------------


..  _ver-dlr:

VER$
====

+----------+-------------------------------------------------------------------+
| Syntax   || VER$  or                                                         |
|          || VER$ [(n)] with n=1, 0, -1, -2(Minerva and SMS only)             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function VER$, which is the same as VER$(0) returns a short
identification code for the version of the current system ROM. Here are
most of the possible values (in order of development):

**Original ROMs**

.. DO NOT add a double pipe at the start of the first line. If you do then the whole table is 
   completely useless in the rendered output. As it is, each time we build, we get a Latex error
   for the ||, but pressing ENTER seems to get past it. Plus, it builds!

.. tabularcolumns::   |p{0.05\linewidth}| p{0.9\linewidth}|
   
..  table::
    :class: longtable

    +------+--------------------------------------------------------------------------+
    | VER$ | Explanation                                                              |
    +======+==========================================================================+
    || FB  | This is the first ROM sold in April 1984, QDOS version                   |
    |      | 1.00. It comes with a 'Dongle' - a board which needed to be plugged into |
    |      | the QL's ROM port. It is very unreliable and should be replaced!!        |
    +------+--------------------------------------------------------------------------+
    || PM  | These three ROMs were developed during the following two months.         |
    || EL  | (May, June & July 1984.)                                                 |
    || TB  |                                                                          |
    +------+--------------------------------------------------------------------------+
    || AH  | Released as the "definitive" version in June 1984.                       |
    +------+--------------------------------------------------------------------------+
    || JM  | British QL, QDOS v1.03, the first version which was exported.            |
    +------+--------------------------------------------------------------------------+
    || JS  | Released in spring 1985, QDOS v1.10. Also found on early Thors and       |
    |      | patched in ST/QL and early Amiga Emulators.                              |
    +------+--------------------------------------------------------------------------+
    || JSU | American QL.                                                             |
    +------+--------------------------------------------------------------------------+
    | The following versions were only sold in their respective countries.            |
    | All are QDOS v1.03.                                                             |
    +------+--------------------------------------------------------------------------+
    || MGD || Danish                                                                  |
    || MGE || Spanish                                                                 |
    || MGF || French                                                                  |
    || MGG || German                                                                  |
    || MGI || Italian                                                                 |
    || MGN || Norwegian                                                               |
    || MGS || Swedish                                                                 |
    || MGB || Swedish                                                                 |
    || MGY || Finish                                                                  |
    || MG$ || Greek                                                                   |
    || $FP || Greek                                                                   |
    +------+--------------------------------------------------------------------------+


**Patches**

.. DO NOT add a double pipe at the start of the first line. If you do then the whole table is 
   completely useless in the rendered output. As it is, each time we build, we get a Latex error
   for the ||, but pressing ENTER seems to get past it. Plus, it builds!

.. tabularcolumns::   |p{0.05\linewidth}| p{0.9\linewidth}|
   
..  table::
    :class: longtable

    +------+--------------------------------------------------------------------------+
    | VER$ | Explanation                                                              |
    +======+==========================================================================+
    | MGUK | A version of the MGx ROM produced independently for the UK market.       |
    +------+--------------------------------------------------------------------------+
    | MG   | Another patched version, mainly distributed in Germany.                  |
    +------+--------------------------------------------------------------------------+
    | MGUS | Out of the three patches, this is the only legal one and was produced    |
    |      | for the United States.                                                   |
    +------+--------------------------------------------------------------------------+

**New developments** 

.. DO NOT add a double pipe at the start of the first line. If you do then the whole table is 
   completely useless in the rendered output. As it is, each time we build, we get a Latex error
   for the ||, but pressing ENTER seems to get past it. Plus, it builds!

.. tabularcolumns::   |p{0.05\linewidth}| p{0.9\linewidth}|
   
..  table::
    :class: longtable

    +------+--------------------------------------------------------------------------+
    | VER$ | Explanation                                                              |
    +======+==========================================================================+
    | CS   |                                                                          |
    | PT   | Different ROMs used on the THOR XVI.                                     |
    | PO   |                                                                          |
    +------+--------------------------------------------------------------------------+
    | JSL1 | QL with Minerva ROM, a very much debugged and enhanced                   |
    |      | version of the JS ROM, available in all languages for all kinds of QLs.  |
    +------+--------------------------------------------------------------------------+
    | HBA  | Either the SMSQ or SMSQ/E replacement operating system for QXLs,         |
    |      | Atari ST/STE and TT series computers and the Miracle Gold Card family of |
    |      | add-on cards.                                                            |
    +------+--------------------------------------------------------------------------+

**NOTE 1**

VER$ can be used to write flexible programs which adapt themselves to
specific features of computers and ROM implementations. However, if you
intend to test VER$, for example::

    IF VER$= 'JM'
    
to retain compatibility with the different ROM versions, you must first
assign the contents of VER$ to a variable::

    100 a$=VER$ 
    110 IF a$(1 TO 2)='MG': PRINT 'MG ROM'

**NOTE 2**

The names of the original ROMs were derived from names of Clive
Sinclair's secretaries, taxi drivers he met and so on. (Just in case you
are looking for any sense behind the abbreviations.)

**MINERVA NOTES**

On Minerva, VER$ accepts a parameter: 

- VER$(0)as per above VER$.
- VER$(-2) returns the base address of the system variables (normally $28000 = 163840 on a standard QL). 
- VER$(-1)returns the current job identification number. 
- VER$(1)returns the version of QDOS (see also QDOS$).

**SMS NOTES**

VER$ has been amended to provide the same facilities as on Minerva.

**WARNING**

If you fail to assign VER$ to a variable before testing its value, then
you can crash a JS (or JSU) ROM. This will also happen on Minerva ROMs
(pre v1.77) with Minerva's extended variant VER$(n).

**CROSS-REFERENCE**

:ref:`qdos-dlr` returns the version number of QDOS in
the same way as :ref:`ver-dlr`\ (1). See also
:ref:`machine` and
:ref:`processor`.

--------------


..  _vfr:

VFR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  VFR (i,n)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function VFR returns the value of: ((1+i)\ :sup:`n`-1)/i
where i and n can be any floating point numbers (see MT for error
handling).

**CROSS-REFERENCE**

:ref:`mt`, :ref:`va`,
:ref:`var`, :ref:`tca`,
:ref:`tnc`, :ref:`tee`,
:ref:`rae`, :ref:`rafe`

--------------


..  _vg-hoch:

VG\_HOCH
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_HOCH (fontnr) fontnr=0..15                                   |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This function returns the maximum height of the specified font
(fontnr=0..15) in pixels if printed with the current size settings of
VG\_PARA.

**CROSS-REFERENCE**

:ref:`vg-para` and
:ref:`vg-load`.

--------------


..  _vg-load:

VG\_LOAD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_LOAD fontnr, file$ fontnr=0..15                              |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This toolkit allows the QL to use BGI vector fonts (common on the PC)
to draw on the screen. There are now numerous fonts available in this
format for the QL, being the same format as used by the PROWESS
programming system from PROGS. 

The advantage of vector fonts is that
they can be drawn on screen at any size and angle without affecting the
legibility. Each character is not made up by a bit-map (as with the
original QL fonts), but by a description of how each line is drawn to
make up a character. 

This command forces a BGI font file$ to be loaded
from a file into memory. Fontnr is the number of the font Up to 16 fonts
can be loaded at the same time; Fontnr may range from 0 to 15. The file$
can be any font in standard BGI format, for example those which are
delivered with Turbo Pascal and Turbo C by Borland. The format used on
the QL with this Toolkit is binary compatible. 

If VG\_LOAD fails to load
a file for external reasons (eg. if the file is not found), the font
which was previously attached to fontnr will have been lost.

**Example**

::

    VG_LOAD 1, "flp1_goth_chr"

**WARNING**

You have to ensure that file is actually a BGI font. Otherwise your
machine will almost surely crash.

**CROSS-REFERENCE**

See :ref:`vg-print` about displaying text using
a vector font and the other VG_XXX commands.

--------------


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

--------------


..  _vg-print:

VG\_PRINT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_PRINT x, y, fontnr, text$                                    |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

The command VG\_PRINT prints text$ at the absolute position x, y
on the screen. The font which has been applied to fontnr with VG\_LOAD
will be used; there will be no output if the font number has not been
used yet. If x and y are not inside the area defined with VG\_WIND or
the text is too high to fit, again there will be no output. VG\_PRINT
works only in high resolution mode (MODE 4).

**Example**

::

    VG_LOAD 1,flp1_goth_chr 
    VG_WIND 0,511,0,255 
    VG_PRINT 100,100,1,"Hello World"

**NOTE**

Since the BGI fonts will usually originate from another computer system
which uses a different character set, text$ and the actual output may
differ dramatically if text$ contains characters which are not
standardised in ASCII, especially national characters (umlauts, acutes).
The following program lists the complete character set of a BGI font::

    100 VG_LOAD 0,"flp1_goth_chr" 
    110 VG_WIND 0,511,0,255 
    120 WINDOW 512,256,0,0: PAPER 0: CLS 
    130 VG_PARA 7,5,5,0,0,0,0 
    140 FOR c=0 TO 255 
    150   VG_PRINT 20*(c MOD 20)+50,20*(c DIV 20),0,CHR$(c) 
    160 END FOR c

**CROSS-REFERENCE**

:ref:`vg-para` offers a switch to approximate an
identity between text$ and display as far as possible. Modify line 130 in the 
above listing so that it looks like this now::

    130 VG_PARA 7,5,5,0,1,0,0 
 
Running the program again shows you :ref:`vg-print`'s
attempts to correct the problem. See also the other
VG_XXX keywords!

--------------


..  _vg-reso:

VG\_RESO
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_RESO scradr, xres, yres                                      |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This command defines the screen base address and the screen size for
printing the BGI fonts. The default is::

    VG_RESO 131072,512,256

This will need to be changed if the screen offset is not 131072. A
fixed screen address should never be assumed. VG\_RESO can also be used
to write to the second screen on a dual screen system.

**CROSS-REFERENCE**

The settings of :ref:`vg-wind` are dependent on
:ref:`vg-reso`'s. See
:ref:`scrbase`, :ref:`peek` and
:ref:`mode`.

--------------


..  _vg-wind:

VG\_WIND
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_WIND x1, x2, y1, y2                                          |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This command defines a rectangular area of the screen. Only text
printed inside this window with VG\_PRINT (it's not a window in
SuperBASIC terms) will be visible::

      0                         511 
    0 +-------------------------+
      |                         | 
      |   x1        x2          | 
      | y1+---------+           | 
      |   |         |           | 
      |   |BGI Text |           | 
      |   |         |           | 
      | y2+---------+           | 
    55+-------------------------+ 

It is strongly
recommended that you specify a window inside the physical screen, so: 0
<= x1 < x2 <= 511 and 0 <= y1 < y2 <= 255  (assuming a standard 512x256 
pixel screen - replace the upper bounds if you have a better graphics 
card, eg. QVME). Note that VG\_WIND does not
check the parameters (this is impossible without the Window Manager).

Default settings are x1=0, x2=511, y1=0, y2=255.

**Example**

::

    VG_WIND 0,511,0,255 
    
restores these defaults.

**CROSS-REFERENCE**

See also the other VG_XXX keywords. :ref:`qflim` can
be used to find out about about the size of the screen if the Window
Manager is loaded.

--------------


..  _view:

VIEW
====

+----------+-------------------------------------------------------------------+
| Syntax   || VIEW [#channel,] text\_file  or                                  |
|          || VIEW \\channel, text\_file                                       |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command reads the contents of the given text\_file line by line
and prints it to the given channel (default #1). If a line is longer
than the window, it is not split and continued in the next line (as
PRINT would do) but truncated. The second syntax allows you to open a
temporary channel to which the output will be sent, for example you
could use::

    VIEW \con,text_file

or::

    VIEW \ram1_test,flp1_text_file
    
Note that the latter is the same as::

    COPY flp1_text_file TO ram1_test
    
Lines in a text file are separated by line feed characters <LF>, ie.
CHR$(10). If output is sent to a window, then when a window page is
full, VIEW generates a <CTRL><F5>, and waits for a keypress to continue
VIEWing. Sub-directories and default directories are supported by this
command, which will look on the default data directory for the given
file if necessary (see DATAD$).

**NOTE**

If the final line in the file being VIEWed does not contain a line feed,
it will not appear on screen.

**WARNING**

There is a possibility that if a file is longer than 32767 characters
and does not include a newline character, the system may crash!

**CROSS-REFERENCE**

:ref:`spl` file TO #1 copies all
kinds of files to a window, for example without truncating lines.

Compare :ref:`copy` and
:ref:`more`.

--------------


..  _vocab:

VOCAB
=====

+----------+-------------------------------------------------------------------+
| Syntax   || VOCAB [ #channel, ] type  or                                     |
|          || VOCAB [ #channel ] [,type]                                       |
+----------+-------------------------------------------------------------------+
| Location || VOCAB (DIY Toolkit, Vol X)                                       |
+----------+-------------------------------------------------------------------+

This command lists all of the names which fall into a given category
and are recognised by the SuperBASIC interpreter in the given channel
(default #1). If type is not specified, then it is assumed to be type=8.

The names are listed in columns, calculated by reference to the width of
the specified channel (set by WIDTH for non-window devices). Once all of
the names of the given type have been listed, a line feed is printed to
end the list. The values for type are:

+------+--------------------------+
| Type | Category of names listed |
+======+==========================+
| 0    | Unset Names              |
+------+--------------------------+
| 2    | Simple Variables         |
+------+--------------------------+
| 3    | Dimensioned Variables    |
+------+--------------------------+
| 4    | SuperBASIC PROCedures    |
+------+--------------------------+
| 5    | SuperBASIC FuNctions     |
+------+--------------------------+
| 6    | Used REPeat loops        |
+------+--------------------------+
| 7    | Used FOR loops           |
+------+--------------------------+
| 8    | Machine code Procedures  |
+------+--------------------------+
| 9    | Machine code Functions   |
+------+--------------------------+

Other values or type=1 will report an error or may cause junk to appear on screen.

**NOTE 1**

For some reason, under SMS, VOCAB 2 will report rubbish on screen unless
a program has been RUN already and even then, the last entry may not be
an actual variable. No such problems seem to occur on Minerva or other
ROMs.

**NOTE 2**

VOCAB 6 and VOCAB 7 only list those REPeat and FOR loop names which have
actually been used in the program when it has been RUN.

**CROSS-REFERENCE**

Use :ref:`sxtras` if you have a lot of extensions
in memory and you are looking for a specific one. 

See also
:ref:`txtras`, :ref:`extras`
and :ref:`type`.

