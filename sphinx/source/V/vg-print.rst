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


